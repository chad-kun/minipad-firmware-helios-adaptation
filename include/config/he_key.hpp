#pragma once

#include <stdint.h>

// Configuration for the hall effect keys of the keypad, containing the actuation points, calibration, sensitivities etc. of the key.
struct HEKey
{
    // Version of the configuration, used to check whether the struct layout in the EEPROM is up-to-date.
    int64_t version = HEKey::getVersion();

    // The index of the key. This is hardcoded in the default config and is not changed.
    // It does not serve a config purpose but is instead for accessing the index from the HEKey object.
    uint8_t index;

    // Bool whether rapid trigger is enabled or not.
    bool rapidTrigger;

    // Bool whether continuous rapid trigger is enabled or not.
    bool continuousRapidTrigger;

    // The sensitivity of the rapid trigger algorithm when pressing up.
    uint16_t rapidTriggerUpSensitivity;

    // The sensitivity of the rapid trigger algorithm when pressing down.
    uint16_t rapidTriggerDownSensitivity;

    // The value below which the key is pressed and rapid trigger is active in rapid trigger mode.
    uint16_t lowerHysteresis;

    // The value below which the key is no longer pressed and rapid trigger is no longer active in rapid trigger mode.
    uint16_t upperHysteresis;

    // The corresponding key sent via HID interface.
    char keyChar;

    // Bools whether HID commands are sent on the key.
    bool hidEnabled;

    // The value read when the keys are in rest position/all the way down.
    uint16_t restPosition;
    uint16_t downPosition;

    // Returns the version constant of the latest configuration layout.
    static uint32_t getVersion()
    {
        // Version of the configuration in the format YYMMDDhhmm (e.g. 2301030040 for 12:44am on the 3rd january 2023)
        return 2303171833;
    }
};
