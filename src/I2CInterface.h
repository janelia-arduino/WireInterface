// ----------------------------------------------------------------------------
// I2CInterface.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <EventController.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>

#include "I2CInterface/Constants.h"


class I2CInterface : public ModularDeviceBase
{
public:
  I2CInterface();
  virtual void setup();

protected:
  EventController<i2c_interface::constants::EVENT_COUNT_MAX> event_controller_;

  // Handlers
  virtual void pollingHandler(int index);

private:
  modular_server::Pin pins_[i2c_interface::constants::PIN_COUNT_MAX];

  modular_server::Property properties_[i2c_interface::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[i2c_interface::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[i2c_interface::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[i2c_interface::constants::CALLBACK_COUNT_MAX];

  // Handlers
  void setPollingEnabledHandler(size_t wire_index);
  void setPollingPeriodHandler(size_t wire_index);

};

#endif
