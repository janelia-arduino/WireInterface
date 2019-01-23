// ----------------------------------------------------------------------------
// 3x2.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "3x2.h"


#if defined(__MK20DX256__)

namespace i2c_interface
{
namespace constants
{
const modular_server::HardwareInfo hardware_info =
{
  .name_ptr=&hardware_name,
  .part_number=1261,
  .version_major=1,
  .version_minor=0,
};

TwoWire * wire_ptrs[WIRE_COUNT] =
{
  &Wire,
};
// Pins

// Units

// Properties
const bool polling_enabled_default[WIRE_COUNT] =
{
  polling_enabled_element_default,
};

const long polling_period_default[WIRE_COUNT] =
{
  polling_period_element_default,
};

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
