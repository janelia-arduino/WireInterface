// ----------------------------------------------------------------------------
// I2CInterface.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../I2CInterface.h"


using namespace i2c_interface;

I2CInterface::I2CInterface()
{
}

void I2CInterface::setup()
{
  // Parent Setup
  ModularDeviceBase::setup();

  // Reset Watchdog
  resetWatchdog();

  // Event Controller Setup
  event_controller_.setup();

  // Variable Setup

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware
  modular_server_.addHardware(constants::hardware_info,
    pins_);

  // Pins

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
    properties_,
    parameters_,
    functions_,
    callbacks_);

  // Properties
  modular_server::Property & polling_enabled_property = modular_server_.createProperty(constants::polling_enabled_property_name,constants::polling_enabled_default);
  polling_enabled_property.setArrayLengthRange(constants::WIRE_COUNT,constants::WIRE_COUNT);
  polling_enabled_property.attachPostSetElementValueFunctor(makeFunctor((Functor1<size_t> *)0,*this,&I2CInterface::setPollingEnabledHandler));

  modular_server::Property & polling_period_property = modular_server_.createProperty(constants::polling_period_property_name,constants::polling_period_default);
  polling_period_property.setArrayLengthRange(constants::WIRE_COUNT,constants::WIRE_COUNT);
  polling_period_property.attachPostSetElementValueFunctor(makeFunctor((Functor1<size_t> *)0,*this,&I2CInterface::setPollingPeriodHandler));

  // Parameters

  // Functions

  // Callbacks
}

void I2CInterface::pollingHandler(int index)
{
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray *
// ArduinoJson::JsonObject *
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void I2CInterface::setPollingEnabledHandler(size_t wire_index)
{
}

void I2CInterface::setPollingPeriodHandler(size_t wire_index)
{
}
