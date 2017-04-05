/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdbool.h>

#if FLASH_SIZE <= 128
#define MAX_PROFILE_COUNT 2
#else
#define MAX_PROFILE_COUNT 3
#endif
#define MAX_RATEPROFILES 3
#define MAX_NAME_LENGTH 16

typedef enum {
    FEATURE_RX_PPM = 1 << 0,
    FEATURE_VBAT = 1 << 1,
    FEATURE_INFLIGHT_ACC_CAL = 1 << 2,
    FEATURE_RX_SERIAL = 1 << 3,
    FEATURE_MOTOR_STOP = 1 << 4,
    FEATURE_SERVO_TILT = 1 << 5,
    FEATURE_SOFTSERIAL = 1 << 6,
    FEATURE_GPS = 1 << 7,
    FEATURE_FAILSAFE = 1 << 8,
    FEATURE_SONAR = 1 << 9,
    FEATURE_TELEMETRY = 1 << 10,
    FEATURE_CURRENT_METER = 1 << 11,
    FEATURE_3D = 1 << 12,
    FEATURE_RX_PARALLEL_PWM = 1 << 13,
    FEATURE_RX_MSP = 1 << 14,
    FEATURE_RSSI_ADC = 1 << 15,
    FEATURE_LED_STRIP = 1 << 16,
    FEATURE_DASHBOARD = 1 << 17,
    FEATURE_OSD = 1 << 18,
    FEATURE_BLACKBOX = 1 << 19,
    FEATURE_CHANNEL_FORWARDING = 1 << 20,
    FEATURE_TRANSPONDER = 1 << 21,
    FEATURE_AIRMODE = 1 << 22,
    FEATURE_SDCARD = 1 << 23,
    FEATURE_VTX = 1 << 24,
    FEATURE_RX_SPI = 1 << 25,
    FEATURE_SOFTSPI = 1 << 26,
    FEATURE_ESC_SENSOR = 1 << 27,
    FEATURE_ANTI_GRAVITY = 1 << 28,
    FEATURE_PWM_DIMMER = 1 << 29,
} features_e;

void beeperOffSet(uint32_t mask);
void beeperOffSetAll(uint8_t beeperCount);
void beeperOffClear(uint32_t mask);
void beeperOffClearAll(void);
uint32_t getBeeperOffMask(void);
void setBeeperOffMask(uint32_t mask);
uint32_t getPreferredBeeperOffMask(void);
void setPreferredBeeperOffMask(uint32_t mask);

void copyCurrentProfileToProfileSlot(uint8_t profileSlotIndex);

void resetEEPROM(void);
void ensureEEPROMContainsValidData(void);

void saveConfigAndNotify(void);
void validateAndFixConfig(void);
void validateAndFixGyroConfig(void);
void activateConfig(void);

uint8_t getCurrentProfile(void);
void changeProfile(uint8_t profileIndex);
void setProfile(uint8_t profileIndex);

uint8_t getCurrentControlRateProfile(void);
void changeControlRateProfile(uint8_t profileIndex);
bool canSoftwareSerialBeUsed(void);

uint16_t getCurrentMinthrottle(void);
struct master_s;

void targetConfiguration(struct master_s *config);
void targetValidateConfiguration(struct master_s *config);
