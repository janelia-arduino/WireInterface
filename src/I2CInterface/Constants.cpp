// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace i2c_interface
{
namespace constants
{
CONSTANT_STRING(device_name,"i2c_interface");

CONSTANT_STRING(firmware_name,"I2CInterface");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=1,
  .version_patch=0,
};

CONSTANT_STRING(hardware_name,"i2c_interface");

// Pins

// Units
CONSTANT_STRING(ms_units,"ms");

// Properties
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
