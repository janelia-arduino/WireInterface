// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace wire_interface
{
namespace constants
{
CONSTANT_STRING(device_name,"wire_interface");

CONSTANT_STRING(firmware_name,"WireInterface");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=3,
  .version_patch=0,
};

CONSTANT_STRING(hardware_name,"wire_interface");

// Pins

// Units
CONSTANT_STRING(ms_units,"ms");

// Properties
CONSTANT_STRING(wire_count_property_name,"wireCount");
const long wire_count_min = 1;

CONSTANT_STRING(device_count_property_name,"deviceCount");
const long device_count_min = 1;
const long device_count_max = 128;
const long device_count_element_default = 1;

CONSTANT_STRING(polling_enabled_property_name,"pollingEnabled");
const bool polling_enabled_element_default = false;

CONSTANT_STRING(polling_period_property_name,"pollingPeriod");
const long polling_period_max = 3600;
const long polling_period_element_default = 100;

// Parameters

// Functions

// Callbacks

// Errors
}
}
