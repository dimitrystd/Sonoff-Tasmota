/*
  user_config_override.h - user configuration overrides user_config.h for Sonoff-Tasmota

  Copyright (C) 2017  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * ATTENTION: - Changes to most PARAMETER defines will only override flash settings if you change
 *              define CFG_HOLDER.
 *            - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *            - You still need to update user_config.h for major defines MODULE and USE_MQTT_TLS.
 *            - Changing MODULE defines are not being tested for validity as they are in user_config.h.
 *            - Most parameters can be changed online using commands via MQTT, WebConsole or serial.
 *            - So I see no use in this but anyway, your on your own.
\*****************************************************************************************************/

// Examples
//#ifdef CFG_HOLDER
//#undef CFG_HOLDER
//#endif
//#define CFG_HOLDER             0x20161210

#undef STA_SSID1
#undef STA_PASS1
#undef STA_SSID2
#undef STA_PASS2
// Define actual password in credentials.h
#include "credentials.h"
// Reset the 2nd AP because we don't use it
#define STA_SSID2              ""      // [Ssid2] Optional alternate AP Wifi SSID
#define STA_PASS2              ""  // [Password2] Optional alternate AP Wifi password

#ifdef WIFI_CONFIG_TOOL
    #undef WIFI_CONFIG_TOOL
#endif
#define WIFI_CONFIG_TOOL       WIFI_RETRY

#undef PROJECT
#define PROJECT                "h801_bedroom"
#undef MODULE
#define MODULE                 H801

#ifdef SERIAL_LOG_LEVEL
    #undef SERIAL_LOG_LEVEL
#endif
#define SERIAL_LOG_LEVEL       LOG_LEVEL_NONE

#ifdef OTA_URL
    #undef OTA_URL
#endif
#define OTA_URL                "http://dms-ota-firmware.s3.amazonaws.com/sonoff-tasmota/" PROJECT ".ino.bin"  // [OtaUrl]

#ifdef MQTT_USE
    #undef MQTT_HOST
    #undef MQTT_PORT
    #undef MQTT_USER
    #undef MQTT_PASS
    #undef MQTT_CLIENT_ID

    #define MQTT_HOST            "192.168.1.2" // [MqttHost]
    #define MQTT_PORT            1883          // [MqttPort] MQTT port (10123 on CloudMQTT)
    #define MQTT_USER            ""       // [MqttUser] Optional user
    #define MQTT_PASS            ""       // [MqttPassword] Optional password
    #define MQTT_CLIENT_ID       PROJECT "_%06X"       // [MqttClient] Also fall back topic using Chip Id = last 6 characters of MAC address
#endif

#ifdef USE_DOMOTICZ
    #undef USE_DOMOTICZ
#endif

#ifdef FRIENDLY_NAME
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME        "smart-home-us - " PROJECT // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
#endif

#ifdef USE_DISCOVERY
    #undef USE_DISCOVERY
#endif

#undef NTP_SERVER1
#undef NTP_SERVER2
#undef NTP_SERVER3
#define NTP_SERVER1            "pool.ntp.org"       // [NtpServer1] Select first NTP server by name or IP address
#define NTP_SERVER2            "time.nist.gov"    // [NtpServer2] Select second NTP server by name or IP address
#define NTP_SERVER3            "time-a.nist.gov"  // [NtpServer3] Select third NTP server by name or IP address

#undef TIME_DST
#undef TIME_STD
#undef APP_TIMEZONE
#undef APP_LEDSTATE
// second Sunday in March and ends on the first Sunday in November, with the time changes taking place at 2:00 a.m. local time
#define TIME_DST               Second, Sun, Mar, 2, +120  // Last sunday in march at 02:00 +120 minutes
#define TIME_STD               First, Sun, Nov, 2, +60   // Last sunday in october 02:00 +60 minutes
#define APP_TIMEZONE           -5                 // [Timezone] +1 hour (Amsterdam) (-12 .. 12 = hours from UTC, 99 = use TIME_DST/TIME_STD)
#define APP_LEDSTATE           LED_POWER_MQTT

#ifdef WS2812_LEDS
    #undef WS2812_LEDS
#endif

#ifdef USE_DS18x20
    #undef USE_DS18x20
#endif

#ifdef USE_I2C
    #undef USE_I2C
#endif

#ifdef USE_IR_REMOTE
    #undef USE_IR_REMOTE
#endif

#ifdef USE_WS2812
    #undef USE_WS2812
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
