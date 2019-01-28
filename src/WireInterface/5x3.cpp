// ----------------------------------------------------------------------------
// 5x3.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "5x3.h"


#if defined(__MK64FX512__)

namespace wire_interface
{
namespace constants
{
const modular_server::HardwareInfo hardware_info =
{
  .name_ptr=&hardware_name,
  .part_number=1260,
  .version_major=1,
  .version_minor=0,
};

TwoWire * wire_ptrs[WIRE_COUNT_MAX] =
{
  &Wire,
  &Wire1,
};
// Pins

// Units

// Properties
const long wire_count_default = WIRE_COUNT_MAX;

const long device_count_default[WIRE_COUNT_MAX] =
{
  device_count_element_default,
  device_count_element_default,
};

const bool polling_enabled_default[WIRE_COUNT_MAX] =
{
  polling_enabled_element_default,
  polling_enabled_element_default,
};

const long polling_period_min = WIRE_COUNT_MAX;
const long polling_period_default[WIRE_COUNT_MAX] =
{
  polling_period_element_default,
  polling_period_element_default,
};

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
