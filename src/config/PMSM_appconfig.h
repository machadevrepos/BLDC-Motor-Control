/**********************************************************************/
// File Name: {FM_project_loc}/PMSM_appconfig.h 
//
// Date:  17. July, 2026
//
// Automatically generated file by MCAT
// - static configuration of the PMSM FOC application
/**********************************************************************/

#ifndef __PMSM_APPCONFIG_H
#define __PMSM_APPCONFIG_H


//Motor Parameters                      
//----------------------------------------------------------------------
//Pole-pair number                      = 7 [-]
//Stator resistance                     = 0.44 [Ohms]
//Direct axis inductance                = 165.5e-6 [H]
//Quadrature axis inductance            = 165.5e-6 [H]
//Back-EMF constant                     = 0.01804 [V.sec/rad]
//Drive inertia                         = 1.83e-6 [kg.m2]
//Nominal current                       = 2.18 [A]
//Nominal speed                         = 3860 [rpm]

#define MOTOR_PP                        (7.0F)
#define MOTOR_PP_GAIN                   FRAC32(0.875)
#define MOTOR_PP_SHIFT                  (3)

//Application scales                    
//----------------------------------------------------------------------
#define I_MAX                           (15.625F)
#define U_DCB_MAX                       (22.1F)
#define N_MAX                           (5300.0F)
#define WEL_MAX                         (3885.1F)
#define E_MAX                           (6.765F)

//Application Fault Triggers            
//----------------------------------------------------------------------
#define U_DCB_TRIP                      (14.5F)
#define U_DCB_UNDER                     (9.0F)
#define U_DCB_OVER                      (14.0F)
#define I_PH_OVER                       (5.0F)
#define TEMP_OVER                       (110.0F)

//DC Bus voltage IIR1 filter constants  
//----------------------------------------------------------------------
//Cut-off frequency                     = 100 [Hz]
//Sample time                           = 0.0001 [sec]
//----------------------------------------------------------------------
#define UDCB_IIR_B0                     (0.030459027951421222F)
#define UDCB_IIR_B1                     (0.030459027951421222F)
#define UDCB_IIR_A1                     (-0.9390819440971575F)
//Mechanical Alignment                  
#define ALIGN_VOLTAGE                   (0.2F)
#define ALIGN_DURATION                  (10000)

//Current Loop Control                  
//----------------------------------------------------------------------
//Loop Bandwidth                        = 250 [Hz]
//Loop Attenuation                      = 1 [-]
//Loop sample time                      = 0.0001 [sec]
//----------------------------------------------------------------------
//Current Controller Output Limit       
#define CLOOP_LIMIT                     (0.95F)
//D-axis Controller - Recurrent type    
#define D_CC1SC                         (0.10035132827386434F)
#define D_CC2SC                         (-0.05951584006435712F)
//Q-axis Controller - Recurrent type    
#define Q_CC1SC                         (0.10035132827386434F)
#define Q_CC2SC                         (-0.05951584006435712F)

//Speed Loop Control                    
//----------------------------------------------------------------------
//Loop Bandwidth                        = 1 [Hz]
//Loop Attenuation                      = 1 [-]
//Loop sample time                      = 0.001 [sec]
//----------------------------------------------------------------------
//Speed Controller - Parallel type      
#define SPEED_PI_PROP_GAIN              (0.0012747482385963018F)
#define SPEED_PI_INTEG_GAIN             (0.0000020023698507753356F)
#define SPEED_LOOP_HIGH_LIMIT           (2.18F)
#define SPEED_LOOP_LOW_LIMIT            (-2.18F)

#define SPEED_RAMP_UP                   (7.33038F)
#define SPEED_RAMP_DOWN                 (7.33038F)

#define SPEED_LOOP_CNTR                 (10)

#define POSPE_SPEED_FILTER_MA_LAMBDA    (0.8F)

//Position & Speed Sensors Module       
//Loop sample time                      = 0.0001 [sec]
//----------------------------------------------------------------------
//Encoder Loop Bandwidth                = 150 [Hz]
//Encoder Loop Attenuation              = 1 [-]
#define POSPE_ENC_TO_CC1                (1907.1622020563268F)
#define POSPE_ENC_TO_CC2                (-1862.7489822514248F)
#define POSPE_ENC_TO_INTEG_GAIN         (0.000025F)
#define ENC_PULSES                      (128)

//Sensorless DQ BEMF Observer and Tracking Observer
//----------------------------------------------------------------------
//Loop Bandwidth                        = 150 [Hz]
//Loop Attenuation                      = 0.707 [-]
//Loop sample time                      = 0.0001 [sec]
//----------------------------------------------------------------------
//DQ Bemf - plant coefficients          
#define I_Gain                          (0.7653333333333334F)
#define U_Gain                          (0.26666666666666666F)
#define E_Gain                          (0.26666666666666666F)
#define WI_Gain                         (0.00004413333333333334F)

//DQ Bemf - PI controller parameters    
#define BEMF_DQ_CC1_GAIN                (-0.2120937857177519F)
#define BEMF_DQ_CC2_GAIN                (0.2267945614731745F)

//Tracking Observer - PI controller parameters
#define TO_CC1SC                        (89.04163233154114F)
#define TO_CC2SC                        (-88.64684815549756F)
//Tracking Observer - Integrator        
#define TO_THETA_GAIN                   (0.00005F)

//Observer speed output filter          

//Open loop start-up                    
#define OL_START_RAMP_INC               (0.73304F)
#define OL_START_I                      (0.8F)
#define MERG_SPEED_1_TRH                (300.0F)
#define MERG_SPEED_2_TRH                (6000.0F)

//Control Structure Module - Scalar Control
//----------------------------------------------------------------------
#define SCALAR_VHZ_FACTOR_GAIN          (0.0050043686029191065F)
#define SCALAR_INTEG_GAIN               FRAC32(0.061833333333)
#define SCALAR_INTEG_SHIFT              (0)
#define SCALAR_RAMP_UP                  (0.73304F)
#define SCALAR_RAMP_DOWN                (0.73304F)

//FreeMASTER Scale Variables            
//----------------------------------------------------------------------
//Note: Scaled at input = 1000          
//----------------------------------------------------------------------
#define FM_SPEED_RAD_MEC_SCALE          (1000)
#define FM_SPEED_RPM_EL_SCALE           (9549)
#define FM_SPEED_RPM_MEC_SCALE          (1364)
#define FM_POSITION_DEG_SCALE           (57296)

#endif

//End of generated file                 
/**********************************************************************/
