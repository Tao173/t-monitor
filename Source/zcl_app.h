#ifndef ZCL_APP_H
#define ZCL_APP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * INCLUDES
 */
#include "version.h"
#include "zcl.h"


/*********************************************************************
 * CONSTANTS
 */

// Application Events
#define APP_REPORT_EVT                  0x0001
#define APP_READ_SENSORS_EVT            0x0002
#define APP_REPORT_CLOCK_EVT            0x0004
#define APP_MOTION_ON_EVT               0x0008
#define APP_REQ_BIND_EVT                0x0010 
#define APP_MOTION_OFF_EVT              0x0020
#define APP_MOTION_DELAY_EVT            0x0040
#define APP_SAVE_ATTRS_EVT              0x0080
#if defined(EPD3IN7)
#define APP_EPD_DELAY_EVT               0x0100
#endif //EPD3IN7
#if defined(TFT3IN5)
//#define APP_TFT_DELAY_EVT               0x0100   
//#define APP_TFT_TP_EVT                  0x0100
//#define APP_REPORT_CONFIG_DISPLAY_EVT   0x0100
#ifdef HAL_LCD_PWM_PORT1   
#define APP_TFT_LED_PWM_EVT             0x8000
#endif //HAL_LCD_PWM_PORT1   
#endif //TFT3IN5
#define APP_BH1750_DELAY_EVT            0x0200
#define APP_REPORT_TEMPERATURE_EVT      0x0400
#define APP_REPORT_PRESSURE_EVT         0x0800
#define APP_REPORT_HUMIDITY_EVT         0x1000
#define APP_REPORT_ILLUMINANCE_EVT      0x2000
#define APP_REPORT_BATTERY_EVT          0x4000

/*********************************************************************
 * MACROS
 */
#define NW_APP_CONFIG 0x0401

#define R           ACCESS_CONTROL_READ
#define RR          (R | ACCESS_REPORTABLE)
#define RW          (ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE | ACCESS_CONTROL_AUTH_WRITE)
#define RRW          (ACCESS_CONTROL_READ| ACCESS_REPORTABLE | ACCESS_CONTROL_WRITE | ACCESS_CONTROL_AUTH_WRITE)

#define BASIC              ZCL_CLUSTER_ID_GEN_BASIC
#define ONOFF              ZCL_CLUSTER_ID_GEN_ON_OFF
#define POWER_CFG          ZCL_CLUSTER_ID_GEN_POWER_CFG
#define TEMP               ZCL_CLUSTER_ID_MS_TEMPERATURE_MEASUREMENT
#define HUMIDITY           ZCL_CLUSTER_ID_MS_RELATIVE_HUMIDITY
//#define SOIL_HUMIDITY      0x0408
#define PRESSURE           ZCL_CLUSTER_ID_MS_PRESSURE_MEASUREMENT
#define ILLUMINANCE        ZCL_CLUSTER_ID_MS_ILLUMINANCE_MEASUREMENT
//#define ILLUMINANCE_CONFIG ZCL_CLUSTER_ID_MS_ILLUMINANCE_LEVEL_SENSING_CONFIG
#define OCCUPANCY          ZCL_CLUSTER_ID_MS_OCCUPANCY_SENSING
#define GEN_TIME           ZCL_CLUSTER_ID_GEN_TIME
#define HVAC_UI_CONFIG     ZCL_CLUSTER_ID_HVAC_USER_INTERFACE_CONFIG
#define BINARY_INPUT       ZCL_CLUSTER_ID_GEN_BINARY_INPUT_BASIC

#define ZCL_BOOLEAN   ZCL_DATATYPE_BOOLEAN
#define ZCL_UINT8     ZCL_DATATYPE_UINT8
#define ZCL_UINT16    ZCL_DATATYPE_UINT16
#define ZCL_UINT32    ZCL_DATATYPE_UINT32
#define ZCL_INT16     ZCL_DATATYPE_INT16
#define ZCL_INT8      ZCL_DATATYPE_INT8
#define ZCL_BITMAP8   ZCL_DATATYPE_BITMAP8
#define ZCL_ENUM8     ZCL_DATATYPE_ENUM8
#define ZCL_UNKNOWN   ZCL_DATATYPE_UNKNOWN
#define ZCL_CHARSTR   ZCL_DATATYPE_CHAR_STR
#define ZCL_UTC       ZCL_DATATYPE_UTC

#define ATTRID_TEMPERATURE_MIN_ABSOLUTE_CHANGE 0xF001
#define ATTRID_TEMPERATURE_PERIOD 0xF002
#define ATTRID_PRESSURE_MIN_ABSOLUTE_CHANGE 0xF001
#define ATTRID_PRESSURE_PERIOD 0xF002
#define ATTRID_HUMIDITY_MIN_ABSOLUTE_CHANGE 0xF001
#define ATTRID_HUMIDITY_PERIOD 0xF002
#define ATTRID_ILLUMINANCE_LEVEL_SENSING_SENSITIVITY 0xF000
#define ATTRID_ILLUMINANCE_MIN_ABSOLUTE_CHANGE 0xF001
#define ATTRID_ILLUMINANCE_PERIOD 0xF002
#define ATTRID_POWER_CFG_BATTERY_PERIOD 0xF003
#define ATTRID_HVAC_THERMOSTAT_UI_CONFIG_DISPLAY_MODE 0xF004
  
#define ATTRID_GEN_BINARY_INPUT_PRESENTVALUE 0x55
  
// enable/disable display of values
// bit 0 - 0x0001 POWER_CFG, 1 - 0x0400 ILLUMINANCE, 2 - 0x0402 TEMP,         3 - 0x0403 PRESSURE, 
//     4 - 0x0405 HUMIDITY,  5 - 0x0406 OCCUPANCY,   6 - 0x000F BINARY_INPUT, 7 - table received
#define CB_LQI          0x0000
#define CB_POWER_CFG    0x0001 //0 bit
#define CB_ILLUMINANCE  0x0002
#define CB_TEMP         0x0004
#define CB_PRESSURE     0x0008
#define CB_HUMIDITY     0x0010  
#define CB_OCCUPANCY    0x0020 
#define CB_BINARY_INPUT 0x0040
#define CB_7            0x0080
#define CB_8            0x0100
#define CB_9            0x0200  
#define CB_10           0x0400
#define CB_11           0x0800
#define CB_12           0x1000
#define CB_13           0x2000
#define CB_14           0x4000
#define CB_TABLE        0x8000
   
//mask zclApp_Config.HvacUiDisplayMode
// 0 - invert, 1 - rotate, 2 - backlight, 3 - none
// 4,5 - color schtme, 
#define DM_INVERT_NOT          0x01
#define DM_ROTATE              0x02
#define DM_BACKLIGHT           0x04
#define DM_3                   0x08
#define DM_BLUE                0x10
#define DM_RED                 0x20
#define DM_GREEN               0x40
#define DM_7                   0x80
      
#define MAX_LEVEL_PWM          220 // min 254, max 0

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * VARIABLES
 */

extern SimpleDescriptionFormat_t zclApp_FirstEP;
extern SimpleDescriptionFormat_t zclApp_SecondEP;
extern SimpleDescriptionFormat_t zclApp_ThirdEP;
extern SimpleDescriptionFormat_t zclApp_FourthEP;

extern uint8 zclApp_BatteryVoltage;
extern uint8 zclApp_BatteryPercentageRemainig;
//extern uint16 zclApp_BatteryVoltageRawAdc;
extern int16 zclApp_Temperature_Sensor_MeasuredValue;
extern int16 zclApp_PressureSensor_MeasuredValue;
extern int16 zclApp_PressureSensor_ScaledValue;
extern int8 zclApp_PressureSensor_Scale;
extern uint16 zclApp_HumiditySensor_MeasuredValue;
//extern int16 zclApp_DS18B20_MeasuredValue;
//extern uint16 zclApp_SoilHumiditySensor_MeasuredValue;
//extern uint16 zclApp_SoilHumiditySensor_MeasuredValueRawAdc;
//extern uint16 zclApp_IlluminanceSensor_MeasuredValue;
//extern uint16 zclApp_IlluminanceSensor_MeasuredValueRawAdc;
extern uint16 zclApp_bh1750IlluminanceSensor_MeasuredValue;
extern uint32 zclApp_GenTime_TimeUTC;

//extern uint8 zclApp_Magnet_OnOff;
extern uint8 zclApp_Magnet;
extern uint8 zclApp_Occupied_OnOff;
// Occupancy Cluster 
extern uint8 zclApp_Occupied; 
extern uint8 zclApp_Bind_OnOff;
//extern uint8 zclApp_OccType;

//extern unsigned long time_now_s;

typedef struct
{
    uint16 PirOccupiedToUnoccupiedDelay;
    uint16 PirUnoccupiedToOccupiedDelay;
    uint16 MsIlluminanceLevelSensingSensitivity;
    uint16 MsTemperatureMinAbsoluteChange;
    uint16 MsPressureMinAbsoluteChange;
    uint16 MsHumidityMinAbsoluteChange;
    uint16 MsIlluminanceMinAbsoluteChange;
    uint16 MsTemperaturePeriod;
    uint16 MsPressurePeriod;
    uint16 MsHumidityPeriod;
    uint16 MsIlluminancePeriod;
    uint16 CfgBatteryPeriod;
    uint8 HvacUiDisplayMode;
}  application_config_t;

extern application_config_t zclApp_Config;

// attribute list
extern CONST zclAttrRec_t zclApp_AttrsFirstEP[];
extern CONST zclAttrRec_t zclApp_AttrsSecondEP[];
extern CONST zclAttrRec_t zclApp_AttrsThirdEP[];
extern CONST zclAttrRec_t zclApp_AttrsFourthEP[];

extern CONST uint8 zclApp_AttrsFirstEPCount;
extern CONST uint8 zclApp_AttrsSecondEPCount;
extern CONST uint8 zclApp_AttrsThirdEPCount;
extern CONST uint8 zclApp_AttrsFourthEPCount;

extern const uint8 zclApp_ManufacturerName[];
extern const uint8 zclApp_ModelId[];
extern const uint8 zclApp_PowerSource;

extern bool zcl_game;
extern bool butt_quit;

extern void zclApp_keyprocessing(void);
extern void TftUpdateRefresh(void);

//extern uint8 zclApp_BatteryManu[];

// APP_TODO: Declare application specific attributes here

/*********************************************************************
 * FUNCTIONS
 */

/*
 * Initialization for the task
 */
extern void zclApp_Init(byte task_id);

/*
 *  Event Process for the task
 */
extern UINT16 zclApp_event_loop(byte task_id, UINT16 events);

//void user_delay_ms(uint32_t period);

extern void zclApp_ResetAttributesToDefaultValues(void);

static void zclApp_OnOffCB(uint8);

extern void zclApp_TPkeyprocessing(void);

#ifdef __cplusplus
}
#endif

#endif /* ZCL_APP_H */
