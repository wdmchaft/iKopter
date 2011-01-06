// ///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2010-2011, Frank Blumenberg
//
// See License.txt for complete licensing and attribution information.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ///////////////////////////////////////////////////////////////////////////////

typedef enum {
  MKAddressAll   =0,
  MKAddressFC    =1,
  MKAddressNC    =2,
  MKAddressMK3MAg=3,
  MKAddressMKGPS =0XFE
} MKAddress;

static const int kMaxDebugData = 32;

typedef enum {
  MKCommandDebugValueRequest='d',
  MKCommandDebugValueResponse='D',
  MKCommandDebugLabelRequest='a',
  MKCommandDebugLabelResponse='A',
  MKCommandVersionRequest='v',
  MKCommandVersionResponse='V',
  MKCommandLcdMenuRequest='l',
  MKCommandLcdMenuResponse='L',
  MKCommandLcdRequest='h',
  MKCommandLcdResponse='H',
  MKCommandReadSettingsRequest='q',
  MKCommandReadSettingsResponse='Q',
  MKCommandWriteSettingsRequest='s',
  MKCommandWriteSettingsResponse='S',
  MKCommandChangeSettingsRequest='f',
  MKCommandChangeSettingsResponse='F',
  MKCommandChannelsValueRequest='p',
  MKCommandChannelsValueResponse='P',
  MKCommandMixerReadRequest='n',
  MKCommandMixerReadResponse='N',
  MKCommandMixerWriteRequest='m',
  MKCommandMixerWriteResponse='M',
  MKCommandRedirectRequest='u',
  MKCommandEngineTestRequest='t',
  MKCommandOsdRequest='o',
  MKCommandOsdResponse='O',
} MKCommandId;


typedef struct
{
  uint8_t SWMajor;
  uint8_t SWMinor;
  uint8_t ProtoMajor;
  uint8_t ProtoMinor;
  uint8_t SWPatch;
  uint8_t Reserved[5];
} VersionInfo;

typedef struct
{
  uint8_t Digital[2];
  uint16_t Analog[32];    // Debugvalues
} DebugOut;

typedef struct
{
  char Revision;
  char Name[12];
  signed char Motor[16][4];
} Mixer;

typedef struct
{
  unsigned char Kanalbelegung[12];       // GAS[0], GIER[1],NICK[2], ROLL[3], POTI1, POTI2, POTI3
  unsigned char GlobalConfig;           // 0x01=H?henregler aktiv,0x02=Kompass aktiv, 0x04=GPS aktiv, 0x08=Heading Hold aktiv
  unsigned char Hoehe_MinGas;           // Wert : 0-100
  unsigned char Luftdruck_D;            // Wert : 0-250
  unsigned char MaxHoehe;               // Wert : 0-32
  unsigned char Hoehe_P;                // Wert : 0-32
  unsigned char Hoehe_Verstaerkung;     // Wert : 0-50
  unsigned char Hoehe_ACC_Wirkung;      // Wert : 0-250
  unsigned char Hoehe_HoverBand;        // Wert : 0-250
  unsigned char Hoehe_GPS_Z;            // Wert : 0-250
  unsigned char Hoehe_StickNeutralPoint;// Wert : 0-250
  unsigned char Stick_P;                // Wert : 1-6
  unsigned char Stick_D;                // Wert : 0-64
  unsigned char Gier_P;                 // Wert : 1-20
  unsigned char Gas_Min;                // Wert : 0-32
  unsigned char Gas_Max;                // Wert : 33-250
  unsigned char GyroAccFaktor;          // Wert : 1-64
  unsigned char KompassWirkung;         // Wert : 0-32
  unsigned char Gyro_P;                 // Wert : 10-250
  unsigned char Gyro_I;                 // Wert : 0-250
  unsigned char Gyro_D;                 // Wert : 0-250
  unsigned char Gyro_Gier_P;                 // Wert : 10-250
  unsigned char Gyro_Gier_I;                 // Wert : 0-250
  unsigned char UnterspannungsWarnung;  // Wert : 0-250
  unsigned char NotGas;                 // Wert : 0-250     //Gaswert bei Emp?ngsverlust
  unsigned char NotGasZeit;             // Wert : 0-250     // Zeitbis auf NotGas geschaltet wird, wg. Rx-Problemen
  unsigned char Receiver;         		 // 0= Summensignal, 1= Spektrum, 2 =Jeti, 3=ACT DSL, 4=ACT S3D
  unsigned char I_Faktor;               // Wert : 0-250
  unsigned char UserParam1;             // Wert : 0-250
  unsigned char UserParam2;             // Wert : 0-250
  unsigned char UserParam3;             // Wert : 0-250
  unsigned char UserParam4;             // Wert : 0-250
  unsigned char ServoNickControl;       // Wert : 0-250     // Stellung des Servos
  unsigned char ServoNickComp;          // Wert : 0-250     // Einfluss Gyro/Servo
  unsigned char ServoNickMin;           // Wert : 0-250     // Anschlag
  unsigned char ServoNickMax;           // Wert : 0-250     // Anschlag
  unsigned char ServoRollControl;       // Wert : 0-250     // Stellung des Servos
  unsigned char ServoRollComp;          // Wert : 0-250
  unsigned char ServoRollMin;           // Wert : 0-250
  unsigned char ServoRollMax;           // Wert : 0-250
  unsigned char ServoNickRefresh;       // Speed of the Servo
  unsigned char Servo3;        		 // Value or mapping of the Servo Output
  unsigned char Servo4;       			 // Value or mapping of the Servo Output
  unsigned char Servo5;       			 // Value or mapping of the Servo Output
  unsigned char LoopGasLimit;           // Wert: 0-250  max. Gas w?hrend Looping
  unsigned char LoopThreshold;          // Wert: 0-250  Schwelle f?r Stickausschlag
  unsigned char LoopHysterese;          // Wert: 0-250  Hysterese f?r Stickausschlag
  unsigned char AchsKopplung1;          // Wert: 0-250  Faktor, mit dem Gier die Achsen Roll und Nick koppelt (NickRollMitkopplung)
  unsigned char AchsKopplung2;          // Wert: 0-250  Faktor, mit dem Nick und Roll verkoppelt werden
  unsigned char CouplingYawCorrection;  // Wert: 0-250  Faktor, mit dem Nick und Roll verkoppelt werden
  unsigned char WinkelUmschlagNick;     // Wert: 0-250  180?-Punkt
  unsigned char WinkelUmschlagRoll;     // Wert: 0-250  180?-Punkt
  unsigned char GyroAccAbgleich;        // 1/k  (Koppel_ACC_Wirkung)
  unsigned char Driftkomp;
  unsigned char DynamicStability;
  unsigned char UserParam5;             // Wert : 0-250
  unsigned char UserParam6;             // Wert : 0-250
  unsigned char UserParam7;             // Wert : 0-250
  unsigned char UserParam8;             // Wert : 0-250
  unsigned char J16Bitmask;             // for the J16 Output
  unsigned char J16Timing;              // for the J16 Output
  unsigned char J17Bitmask;             // for the J17 Output
  unsigned char J17Timing;              // for the J17 Output
  unsigned char WARN_J16_Bitmask;       // for the J16 Output
  unsigned char WARN_J17_Bitmask;       // for the J17 Output
  unsigned char NaviGpsModeControl;     // Parameters for the Naviboard
  unsigned char NaviGpsGain;
  unsigned char NaviGpsP;
  unsigned char NaviGpsI;
  unsigned char NaviGpsD;
  unsigned char NaviGpsPLimit;
  unsigned char NaviGpsILimit;
  unsigned char NaviGpsDLimit;
  unsigned char NaviGpsACC;
  unsigned char NaviGpsMinSat;
  unsigned char NaviStickThreshold;
  unsigned char NaviWindCorrection;
  unsigned char NaviSpeedCompensation;
  unsigned char NaviOperatingRadius;
  unsigned char NaviAngleLimitation;
  unsigned char NaviPH_LoginTime;
  unsigned char ExternalControl;        // for serial Control
  unsigned char BitConfig;          // (war Loop-Cfg) Bitcodiert: 0x01=oben, 0x02=unten, 0x04=links, 0x08=rechts / wird getrennt behandelt
  unsigned char ServoCompInvert;    // //  0x01 = Nick, 0x02 = Roll   0 oder 1  // WICHTIG!!! am Ende lassen
  unsigned char ExtraConfig;        // bitcodiert
  char Name[12];
} MKSetting;

#define CFG_HOEHENREGELUNG       0x01
#define CFG_HOEHEN_SCHALTER      0x02
#define CFG_HEADING_HOLD         0x04
#define CFG_KOMPASS_AKTIV        0x08
#define CFG_KOMPASS_FIX          0x10
#define CFG_GPS_AKTIV            0x20
#define CFG_ACHSENKOPPLUNG_AKTIV 0x40
#define CFG_DREHRATEN_BEGRENZER  0x80

#define CFG_LOOP_OBEN            0x01
#define CFG_LOOP_UNTEN           0x02
#define CFG_LOOP_LINKS           0x04
#define CFG_LOOP_RECHTS          0x08
#define CFG_MOTOR_BLINK	         0x10
#define CFG_MOTOR_OFF_LED1       0x20
#define CFG_MOTOR_OFF_LED2       0x40
#define CFG_RES4                 0x80

#define CFG2_HEIGHT_LIMIT        0x01
#define CFG2_VARIO_BEEP          0x02
#define CFG_SENSITIVE_RC         0x04

#define CFG2_INVERT_NICK         0x01
#define CFG2_INVERT_ROLL         0x02

//////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
  int16_t AngleNick;  // in 0.1 deg
  int16_t AngleRoll;   // in 0.1 deg
  int16_t Heading;    // in 0.1 deg
  uint8_t reserve[8];
} Data3D_t;



typedef struct
{
  int32_t Longitude;      // in 1E-7 deg
  int32_t Latitude;       // in 1E-7 deg
  int32_t Altitude;       // in mm
  uint8_t Status;         // validity of data
} __attribute__((packed)) GPS_Pos_t;

typedef struct
{
  uint16_t Distance;      // distance to target in dm
  int16_t Bearing;        // course to target in deg
}  __attribute__((packed)) GPS_PosDev_t;

typedef struct
{
  uint8_t      Version;		// version of the data structure
  GPS_Pos_t    CurrentPosition;		// see ubx.h for details
  GPS_Pos_t    TargetPosition;
  GPS_PosDev_t TargetPositionDeviation;
  GPS_Pos_t    HomePosition;
  GPS_PosDev_t HomePositionDeviation;
  uint8_t      WaypointIndex;		// index of current waypoints running from 0 to WaypointNumber-1
  uint8_t      WaypointNumber;		// number of stored waypoints
  uint8_t      SatsInUse;		// number of satellites used for position solution
  int16_t      Altimeter; 		// hight according to air pressure
  int16_t      Variometer;		// climb(+) and sink(-) rate
  uint16_t     FlyingTime;		// in seconds
  uint8_t      UBat;			// Battery Voltage in 0.1 Volts
  uint16_t     GroundSpeed;		// speed over ground in cm/s (2D)
  int16_t      Heading;		// current flight direction in ° as angle to north
  int16_t      CompassHeading;		// current compass value in °
  int8_t       AngleNick;		// current Nick angle in 1°
  int8_t       AngleRoll;		// current Rick angle in 1°
  uint8_t      RC_Quality;		// RC_Quality
  uint8_t      FCFlags;		// Flags from FC
  uint8_t      NCFlags;		// Flags from NC
  uint8_t      Errorcode;		// 0 --> okay
  uint8_t      OperatingRadius;               // current operation radius around the Home Position in m
  int16_t      TopSpeed;		// velocity in vertical direction in cm/s
  uint8_t      TargetHoldTime;		// time in s to stay at the given target, counts down to 0 if target has been reached
  uint8_t      RC_RSSI;		// Receiver signal strength (since version 2 added)
  int16_t      SetpointAltitude;			// setpoint for altitude
  uint8_t      Gas;						// for future use
  uint16_t     Current;					// actual current in 0.1A steps
  uint16_t     UsedCapacity;				// used capacity in mAh
  
} __attribute__((packed)) NaviData_t;

typedef struct
{
  GPS_Pos_t Position;          // the gps position of the waypoint, see ubx.h for details
  int16_t   Heading;           // orientation, future implementation
  uint8_t   ToleranceRadius;   // in meters, if the MK is within that range around the target, then the next target is triggered
  uint8_t   HoldTime;          // in seconds, if the was once in the tolerance area around a WP, this time defies the delay before the next WP is triggered
  uint8_t   Event_Flag;        // future emplementation
  uint8_t   reserve[12];       // reserve
} __attribute__((packed)) WayPoint_t;


#define NAVIDATA_VERSION 3

#define NC_FLAG_FREE            0x01
#define NC_FLAG_PH              0x02
#define NC_FLAG_CH              0x04
#define NC_FLAG_RANGE_LIMIT     0x08
#define NC_FLAG_NOSERIALLINK    0x10
#define NC_FLAG_TARGET_REACHED  0x20
#define NC_FLAG_MANUAL_CONTROL  0x40
#define NC_FLAG_8               0x80

#define FCFLAG_MOTOR_RUN        0x01
#define FCFLAG_FLY              0x02
#define FCFLAG_CALIBRATE        0x04
#define FCFLAG_START            0x08
#define FCFLAG_NOTLANDUNG       0x10
#define FCFLAG_LOWBAT           0x20
#define FCFLAG_SPI_RX_ERR       0x40
#define FCFLAG_I2CERR           0x80
