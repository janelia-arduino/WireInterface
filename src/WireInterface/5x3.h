// ----------------------------------------------------------------------------
// 5x3.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef WIRE_INTERFACE_5X3_CONSTANTS_H
#define WIRE_INTERFACE_5X3_CONSTANTS_H
#include "Constants.h"


#if defined(__MK64FX512__)

namespace wire_interface
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PIN_COUNT_MAX=1};

enum{WIRE_COUNT_MAX=2};

extern TwoWire * wire_ptrs[WIRE_COUNT_MAX];

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const bool polling_enabled_default[WIRE_COUNT_MAX];

extern const long polling_period_default[WIRE_COUNT_MAX];

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
#endif
