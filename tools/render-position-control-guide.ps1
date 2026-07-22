param(
    [string]$InputMarkdown = "docs/position-control-tuning-guide.md",
    [string]$OutputHtml = "docs/Position-Control-Tuning-Guide.html"
)

$ErrorActionPreference = 'Stop'

function Convert-InlineMarkdown {
    param([string]$Text)

    $encoded = [System.Net.WebUtility]::HtmlEncode($Text)
    $encoded = [regex]::Replace($encoded, '`([^`]+)`', '<code>$1</code>')
    $encoded = [regex]::Replace($encoded, '\*\*([^*]+)\*\*', '<strong>$1</strong>')
    return $encoded
}

function Get-Slug {
    param([string]$Text)

    $slug = $Text.ToLowerInvariant()
    $slug = [regex]::Replace($slug, '[^a-z0-9]+', '-')
    return $slug.Trim('-')
}

$sourcePath = (Resolve-Path -LiteralPath $InputMarkdown).Path
$lines = Get-Content -LiteralPath $sourcePath
$body = [System.Text.StringBuilder]::new()
$toc = [System.Collections.Generic.List[object]]::new()
$paragraph = [System.Collections.Generic.List[string]]::new()
$listType = $null
$inCode = $false
$codeLines = [System.Collections.Generic.List[string]]::new()
$headingIds = @{}

function Flush-Paragraph {
    if ($paragraph.Count -gt 0) {
        $text = ($paragraph -join ' ')
        [void]$body.AppendLine("<p>$(Convert-InlineMarkdown $text)</p>")
        $paragraph.Clear()
    }
}

function Close-List {
    if ($null -ne $listType) {
        [void]$body.AppendLine("</$listType>")
        $script:listType = $null
    }
}

function New-UniqueHeadingId {
    param([string]$Heading)

    $base = Get-Slug $Heading
    if ([string]::IsNullOrWhiteSpace($base)) {
        $base = 'section'
    }
    if (-not $headingIds.ContainsKey($base)) {
        $headingIds[$base] = 1
        return $base
    }
    $headingIds[$base]++
    return "$base-$($headingIds[$base])"
}

$index = 0
while ($index -lt $lines.Count) {
    $line = $lines[$index]

    if ($line -match '^```') {
        Flush-Paragraph
        Close-List
        if (-not $inCode) {
            $inCode = $true
            $codeLines.Clear()
        }
        else {
            $codeText = [System.Net.WebUtility]::HtmlEncode(($codeLines -join "`n"))
            [void]$body.AppendLine("<pre><code>$codeText</code></pre>")
            $inCode = $false
        }
        $index++
        continue
    }

    if ($inCode) {
        $codeLines.Add($line)
        $index++
        continue
    }

    if (($line -match '^\|') -and (($index + 1) -lt $lines.Count) -and
        ($lines[$index + 1] -match '^\|(?:\s*:?-+:?\s*\|)+\s*$')) {
        Flush-Paragraph
        Close-List

        $headerCells = $line.Trim().Trim('|').Split('|')
        $index += 2
        [void]$body.AppendLine('<div class="table-wrap"><table><thead><tr>')
        foreach ($cell in $headerCells) {
            [void]$body.AppendLine("<th>$(Convert-InlineMarkdown $cell.Trim())</th>")
        }
        [void]$body.AppendLine('</tr></thead><tbody>')

        while (($index -lt $lines.Count) -and ($lines[$index] -match '^\|')) {
            $cells = $lines[$index].Trim().Trim('|').Split('|')
            [void]$body.AppendLine('<tr>')
            foreach ($cell in $cells) {
                [void]$body.AppendLine("<td>$(Convert-InlineMarkdown $cell.Trim())</td>")
            }
            [void]$body.AppendLine('</tr>')
            $index++
        }
        [void]$body.AppendLine('</tbody></table></div>')
        continue
    }

    if ($line -match '^(#{1,6})\s+(.+)$') {
        Flush-Paragraph
        Close-List
        $level = $Matches[1].Length
        $heading = $Matches[2]
        if ($level -eq 1) {
            $index++
            continue
        }
        $id = New-UniqueHeadingId $heading
        if ($level -le 3) {
            $toc.Add([pscustomobject]@{ Level = $level; Text = $heading; Id = $id })
        }
        [void]$body.AppendLine(('<h{0} id="{1}">{2}</h{0}>' -f
            $level, $id, (Convert-InlineMarkdown $heading)))
        $index++
        continue
    }

    if ($line -match '^\d+\.\s+(.+)$') {
        Flush-Paragraph
        if ($listType -ne 'ol') {
            Close-List
            [void]$body.AppendLine('<ol>')
            $listType = 'ol'
        }
        [void]$body.AppendLine("<li>$(Convert-InlineMarkdown $Matches[1])</li>")
        $index++
        continue
    }

    if ($line -match '^-\s+(.+)$') {
        Flush-Paragraph
        if ($listType -ne 'ul') {
            Close-List
            [void]$body.AppendLine('<ul>')
            $listType = 'ul'
        }
        [void]$body.AppendLine("<li>$(Convert-InlineMarkdown $Matches[1])</li>")
        $index++
        continue
    }

    if ([string]::IsNullOrWhiteSpace($line)) {
        Flush-Paragraph
        Close-List
        $index++
        continue
    }

    $paragraph.Add($line.Trim())
    $index++
}

Flush-Paragraph
Close-List

$tocHtml = [System.Text.StringBuilder]::new()
foreach ($entry in $toc) {
    $className = if ($entry.Level -eq 3) { 'toc-sub' } else { 'toc-main' }
    [void]$tocHtml.AppendLine(('<a class="{0}" href="#{1}">{2}</a>' -f
        $className, $entry.Id, (Convert-InlineMarkdown $entry.Text)))
}

$generatedDate = Get-Date -Format 'dd MMMM yyyy'
$html = @"
<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Position-Control Tuning Guide</title>
<style>
  :root {
    --navy: #15324a;
    --blue: #1f6b91;
    --cyan: #2d9db7;
    --ink: #1f2933;
    --muted: #5c6b76;
    --line: #ccd8df;
    --pale: #eef6f8;
    --warn-bg: #fff6de;
    --warn-line: #d89b17;
    --danger: #a63232;
  }

  @page {
    size: A4;
    margin: 17mm 14mm 18mm 14mm;
  }

  * { box-sizing: border-box; }

  html { font-size: 10.2pt; }

  body {
    margin: 0;
    color: var(--ink);
    font-family: "Segoe UI", Arial, sans-serif;
    line-height: 1.46;
    background: white;
  }

  .cover {
    min-height: 250mm;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    page-break-after: always;
    color: white;
    background: linear-gradient(145deg, var(--navy) 0%, #204d6a 58%, var(--cyan) 100%);
    margin: -17mm -14mm -18mm -14mm;
    padding: 30mm 23mm 22mm 23mm;
  }

  .cover-kicker {
    text-transform: uppercase;
    letter-spacing: 0.16em;
    font-size: 10pt;
    font-weight: 700;
    opacity: 0.85;
  }

  .cover h1 {
    color: white;
    font-size: 31pt;
    line-height: 1.08;
    margin: 16mm 0 6mm 0;
    max-width: 150mm;
  }

  .cover .subtitle {
    font-size: 14pt;
    line-height: 1.45;
    max-width: 145mm;
    color: #dff5fa;
  }

  .cover-card {
    border-left: 3px solid #74d9e8;
    padding: 2mm 0 2mm 6mm;
    font-size: 10.5pt;
    line-height: 1.7;
  }

  .cover-note {
    margin-top: 10mm;
    color: #dff5fa;
    font-size: 9pt;
  }

  .toc {
    page-break-after: always;
  }

  .toc h2 {
    margin-top: 0;
    border-bottom: 3px solid var(--cyan);
    padding-bottom: 3mm;
  }

  .toc a {
    display: block;
    color: var(--ink);
    text-decoration: none;
    border-bottom: 1px dotted var(--line);
    padding: 2.1mm 0;
  }

  .toc-main { font-weight: 650; }
  .toc-sub { padding-left: 7mm !important; color: var(--muted) !important; font-size: 9.2pt; }

  h2 {
    color: var(--navy);
    font-size: 19pt;
    line-height: 1.2;
    margin: 10mm 0 4mm 0;
    padding-bottom: 2mm;
    border-bottom: 2px solid var(--cyan);
    break-after: avoid-page;
  }

  h3 {
    color: var(--blue);
    font-size: 13.5pt;
    margin: 7mm 0 2.5mm 0;
    break-after: avoid-page;
  }

  p { margin: 0 0 3.2mm 0; }

  ul, ol {
    margin: 1.5mm 0 4mm 0;
    padding-left: 7mm;
  }

  li { margin: 1.2mm 0; padding-left: 1mm; }

  code {
    font-family: Consolas, "Courier New", monospace;
    font-size: 8.7pt;
    color: #153b52;
    background: #edf3f6;
    border: 1px solid #d9e3e8;
    border-radius: 3px;
    padding: 0.2mm 0.8mm;
    overflow-wrap: anywhere;
  }

  pre {
    margin: 3mm 0 5mm 0;
    padding: 4mm;
    border-left: 3px solid var(--cyan);
    background: #f4f8fa;
    color: #18394b;
    border-radius: 0 4px 4px 0;
    white-space: pre-wrap;
    break-inside: avoid-page;
  }

  pre code {
    background: transparent;
    border: 0;
    padding: 0;
    color: inherit;
    font-size: 8.5pt;
  }

  .table-wrap {
    margin: 3mm 0 6mm 0;
  }

  table {
    width: 100%;
    border-collapse: collapse;
    table-layout: fixed;
    font-size: 7.7pt;
  }

  thead { display: table-header-group; }
  tr { break-inside: avoid-page; }

  th {
    color: white;
    background: var(--navy);
    text-align: left;
    vertical-align: top;
    padding: 2.1mm 1.7mm;
    border: 1px solid var(--navy);
  }

  td {
    vertical-align: top;
    padding: 1.8mm 1.7mm;
    border: 1px solid var(--line);
    overflow-wrap: anywhere;
  }

  tbody tr:nth-child(even) { background: var(--pale); }
  td code { font-size: 7.2pt; }

  #safety-rules + p,
  #safety-rules + p + ol {
    border-left: 3px solid var(--warn-line);
    background: var(--warn-bg);
    padding-left: 4mm;
    padding-right: 3mm;
  }

  #final-recommended-starting-value-card + pre {
    border: 2px solid var(--cyan);
    border-left-width: 5px;
    background: #edf9fb;
    font-size: 9pt;
  }

  .footer {
    position: fixed;
    bottom: -13mm;
    left: 0;
    right: 0;
    color: #71808a;
    font-size: 7.5pt;
    border-top: 1px solid var(--line);
    padding-top: 2mm;
    display: flex;
    justify-content: space-between;
  }

  .cover .footer { display: none; }

  @media print {
    a { color: inherit; }
    h2 { break-after: avoid; }
    .toc { break-after: page; }
  }
</style>
</head>
<body>
  <section class="cover">
    <div>
      <div class="cover-kicker">S32M276 PMSM FOC Firmware</div>
      <h1>Position-Control Tuning Guide</h1>
      <div class="subtitle">FreeMASTER Variable Watch commissioning procedure for relative multi-turn mechanical position control.</div>
    </div>
    <div>
      <div class="cover-card">
        <strong>Motor:</strong> Faulhaber 3216 W 012 BXT H<br>
        <strong>Encoder:</strong> IEF3-4096L-128, 512 quadrature counts/revolution<br>
        <strong>Initial condition:</strong> Mechanically unloaded<br>
        <strong>Requested later ceiling:</strong> 2000 RPM<br>
        <strong>Document date:</strong> $generatedDate
      </div>
      <div class="cover-note">Bench commissioning guide. Calculated starting values are not a claim of hardware validation.</div>
    </div>
  </section>

  <section class="toc">
    <h2>Contents</h2>
    $($tocHtml.ToString())
  </section>

  <div class="footer"><span>Position-Control Tuning Guide</span><span>S32M276 / Faulhaber 3216</span></div>
  <main>
    $($body.ToString())
  </main>
</body>
</html>
"@

$outputDirectory = Split-Path -Parent $OutputHtml
if (-not (Test-Path -LiteralPath $outputDirectory)) {
    New-Item -ItemType Directory -Path $outputDirectory | Out-Null
}
[System.IO.File]::WriteAllText((Join-Path (Get-Location) $OutputHtml), $html,
    [System.Text.UTF8Encoding]::new($false))

Write-Output "Generated $OutputHtml"
