/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2019  Theo Arends

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
// This const will be added by docker script at the end of this file
//#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4619                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Wifi ----------------------------------------
#undef WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS        "0.0.0.0"         // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
#undef STA_SSID1
#undef STA_PASS1
#undef STA_SSID2
#undef STA_PASS2
// Credentials will be added by docker script from env variables
// Reset the 2nd AP because we don't use it
#define STA_SSID2              ""      // [Ssid2] Optional alternate AP Wifi SSID
#define STA_PASS2              ""  // [Password2] Optional alternate AP Wifi password

#undef WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL       WIFI_RETRY

#undef PROJECT
#define PROJECT                "h801_bedroom"
#undef MODULE
#define MODULE                 H801

// -- Syslog --------------------------------------
#undef SERIAL_LOG_LEVEL
#define SERIAL_LOG_LEVEL       LOG_LEVEL_NONE   // [SerialLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef WEB_LOG_LEVEL
#define WEB_LOG_LEVEL          LOG_LEVEL_INFO    // [WebLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef MQTT_LOG_LEVEL
#define MQTT_LOG_LEVEL         LOG_LEVEL_ERROR    // [MqttLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)

// -- Setup your own MQTT settings  ---------------
#undef MQTT_HOST
#define MQTT_HOST            "192.168.1.2" // [MqttHost]
#undef MQTT_PORT
#define MQTT_PORT            1883          // [MqttPort] MQTT port (10123 on CloudMQTT)
#undef MQTT_USER
#define MQTT_USER            ""       // [MqttUser] Optional user
#undef MQTT_PASS
#define MQTT_PASS            ""       // [MqttPassword] Optional password

// -- MQTT - Telemetry ----------------------------
#undef TELE_PERIOD
#define TELE_PERIOD          120               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)

// -- HTTP ----------------------------------------
#ifdef FRIENDLY_NAME
  #undef FRIENDLY_NAME
  #define FRIENDLY_NAME        "smart-home-us - " PROJECT // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
#endif

// -- Time - Up to three NTP servers in your region
#undef NTP_SERVER1
#undef NTP_SERVER2
#undef NTP_SERVER3
#define NTP_SERVER1            "pool.ntp.org"       // [NtpServer1] Select first NTP server by name or IP address
#define NTP_SERVER2            "time.nist.gov"    // [NtpServer2] Select second NTP server by name or IP address
#define NTP_SERVER3            "time-a.nist.gov"  // [NtpServer3] Select third NTP server by name or IP address

// -- Time - Start Daylight Saving Time and timezone offset from UTC in minutes
#undef TIME_DST
#undef TIME_STD
#define TIME_DST               Second, Sun, Mar, 2, +120  // Last sunday in march at 02:00 +120 minutes
// second Sunday in March and ends on the first Sunday in November, with the time changes taking place at 2:00 a.m. local time
#define TIME_STD               First, Sun, Nov, 2, +60   // Last sunday in october 02:00 +60 minutes

// -- Location ------------------------------------
#undef LATITUDE
#undef LONGITUDE
#define LATITUDE               40.835808         // [Latitude] Your location to be used with sunrise and sunset
#define LONGITUDE              -73.972971        // [Longitude] Your location to be used with sunrise and sunset

// -- Application ---------------------------------
#undef APP_TIMEZONE
#undef APP_LEDSTATE
#define APP_TIMEZONE           -5                 // [Timezone] +1 hour (Amsterdam) (-12 .. 12 = hours from UTC, 99 = use TIME_DST/TIME_STD)
#define APP_LEDSTATE           LED_POWER_MQTT    // [LedState] Function of led
                                                 //   (LED_OFF, LED_POWER, LED_MQTTSUB, LED_POWER_MQTTSUB, LED_MQTTPUB, LED_POWER_MQTTPUB, LED_MQTT, LED_POWER_MQTT)

/*********************************************************************************************\
 * END OF SECTION 1
 *
 * SECTION 2
 * - Enable a feature by removing both // in front of it
 * - Disable a feature by preceding it with //
\*********************************************************************************************/

// -- MQTT - Domoticz -----------------------------
#ifdef USE_DOMOTICZ
  #undef USE_DOMOTICZ
#endif

// -- MQTT - Home Assistant Discovery -------------
#ifdef USE_HOME_ASSISTANT
  #undef USE_HOME_ASSISTANT
#endif

// -- HTTP ----------------------------------------
  #undef USE_EMULATION_HUE                      // Enable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
  #undef USE_EMULATION_WEMO                     // Enable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

// -- mDNS ----------------------------------------
  #undef MQTT_HOST_DISCOVERY                    // Find MQTT host server (overrides MQTT_HOST if found)

// -- Time ----------------------------------------
#ifdef USE_TIMERS                               // Add support for up to 16 timers (+2k2 code)
  #undef USE_TIMERS
#endif

// -- Rules or Script  ----------------------------
#ifdef USE_RULES                               // Add support for rules (+4k4 code)
  #undef USE_RULES
#endif

// -- Optional modules ----------------------------
#undef USE_SONOFF_RF                            // Add support for Sonoff Rf Bridge (+3k2 code)
#undef USE_SONOFF_SC                            // Add support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                             // Add support for Tuya Serial MCU
#undef USE_ARMTRONIX_DIMMERS                    // Add support for Armtronix Dimmers (+1k4 code)
#undef USE_PS_16_DZ                             // Add support for PS-16-DZ Dimmer (+2k code)
#undef USE_SONOFF_IFAN                          // Add support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                               // Add support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                            // Add support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef USE_DEEPSLEEP                            // Add support for deepsleep (+1k code)

// -- Optional light modules ----------------------
#undef USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
#undef USE_MY92X1                               // Add support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
#undef USE_SM16716                              // Add support for SM16716 RGB LED controller (+0k7 code)
#undef USE_SM2135                               // Add support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef USE_SONOFF_L1                            // Add support for Sonoff L1 led control

// -- One wire sensors ----------------------------
#ifdef USE_DS18x20
  #undef USE_DS18x20
#endif

// -- I2C sensors ---------------------------------
#ifdef USE_I2C
  #undef USE_I2C
#endif

// -- Serial sensors ------------------------------
#undef USE_MHZ19                                // Add support for MH-Z19 CO2 sensor (+2k code)
#undef USE_SENSEAIR                             // Add support for SenseAir K30, K70 and S8 CO2 sensor (+2k3 code)
#undef USE_PMS5003                              // Add support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
#undef USE_NOVA_SDS                             // Add support for SDS011 and SDS021 particle concentration sensor (+1k5 code)
#undef USE_SERIAL_BRIDGE

// -- Power monitoring sensors --------------------
#undef USE_ENERGY_MARGIN_DETECTION              // Add support for Energy Margin detection (+1k6 code)
#undef USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef USE_PZEM_AC                              // Add support for PZEM014,016 Energy monitor (+1k1 code)
#undef USE_PZEM_DC                              // Add support for PZEM003,017 Energy monitor (+1k1 code)
#undef USE_MCP39F501                            // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)

// -- Low level interface devices -----------------
#undef USE_DHT                                  // Add support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor (1k6 code)

// -- IR Remote features - subset of IR protocols --------------------------
#undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 and ArduinoJson (+4k3 code, 0k3 mem, 48 iram)

// -- Other sensors/drivers -----------------------

#undef USE_SR04                                 // Add support for HC-SR04 ultrasonic devices (+1k code)

#undef USE_HX711                                // Add support for HX711 load cell (+1k5 code)

#endif  // _USER_CONFIG_OVERRIDE_H_
