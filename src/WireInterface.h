// ----------------------------------------------------------------------------
// WireInterface.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef WIRE_INTERFACE_H
#define WIRE_INTERFACE_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <EventController.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>

#include "WireInterface/Constants.h"


class WireInterface : public ModularDeviceBase
{
public:
  WireInterface();
  virtual void setup();

  virtual size_t getWireCount();

  void setupPolling();

protected:
  EventController<wire_interface::constants::EVENT_COUNT_MAX> event_controller_;

  // Handlers
  void setWireCountHandler();
  virtual void pollingHandler(int wire_index);

private:
  modular_server::Pin pins_[wire_interface::constants::PIN_COUNT_MAX];

  modular_server::Property properties_[wire_interface::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[wire_interface::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[wire_interface::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[wire_interface::constants::CALLBACK_COUNT_MAX];

  EventId polling_events_[wire_interface::constants::WIRE_COUNT_MAX];

  // Handlers
  void updatePollingHandler(size_t wire_index);

};

#endif
