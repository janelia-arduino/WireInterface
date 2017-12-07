// ----------------------------------------------------------------------------
// I2CInterface.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H
#include <Flash.h>
#include <EEPROM.h>
#include <Streaming.h>
#include <ArduinoJson.h>
#include <JsonSanitizer.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <MemoryFree.h>
#include <ConstantVariable.h>
#include <SavedVariable.h>
#include <Functor.h>
#include <IndexedContainer.h>
#include <FunctorCallbacks.h>
#include <Watchdog.h>

#include <ModularClient.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>

#include "I2CInterface/Constants.h"


class I2CInterface : public Parent
{
public:
  I2CInterface();
  virtual void setup();

private:
  modular_server::Property properties_[i2c_interface::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[i2c_interface::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[i2c_interface::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[i2c_interface::constants::CALLBACK_COUNT_MAX];

  // Handlers

};

#endif
