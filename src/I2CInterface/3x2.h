// ----------------------------------------------------------------------------
// 3x2.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef I2C_INTERFACE_3X2_CONSTANTS_H
#define I2C_INTERFACE_3X2_CONSTANTS_H
#include "Constants.h"


#if defined(__MK20DX256__)

namespace i2c_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PIN_COUNT_MAX=1};

enum{WIRE_COUNT=1};

extern TwoWire * wire_ptrs[WIRE_COUNT];

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const bool polling_enabled_default[WIRE_COUNT];

extern const long polling_period_default[WIRE_COUNT];

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
#endif
