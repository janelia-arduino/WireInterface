// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef WIRE_INTERFACE_CONSTANTS_H
#define WIRE_INTERFACE_CONSTANTS_H
#include <ConstantVariable.h>
#include <ModularServer.h>
#include <Wire.h>


namespace wire_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=3};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=1};
enum{CALLBACK_COUNT_MAX=1};

enum{EVENT_COUNT_MAX=8};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern ConstantString hardware_name;
extern const modular_server::HardwareInfo hardware_info;

// Pins

// Units
extern ConstantString ms_units;

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern ConstantString wire_count_property_name;
extern const long wire_count_min;
extern const long wire_count_default;

extern ConstantString polling_enabled_property_name;
extern const bool polling_enabled_element_default;

extern ConstantString polling_period_property_name;
extern const long polling_period_min;
extern const long polling_period_max;
extern const long polling_period_element_default;

// Parameters

// Functions

// Callbacks

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
