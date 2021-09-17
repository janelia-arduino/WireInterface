// ----------------------------------------------------------------------------
// WireInterface.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "../WireInterface.h"


using namespace wire_interface;

WireInterface::WireInterface()
{
}

void WireInterface::setup()
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
  modular_server::Property & wire_count_property = modular_server_.createProperty(constants::wire_count_property_name,constants::wire_count_default);
  wire_count_property.setRange(constants::wire_count_min,constants::WIRE_COUNT_MAX);
  wire_count_property.attachPostSetValueFunctor(makeFunctor((Functor0 *)0,*this,&WireInterface::setWireCountHandler));

  modular_server::Property & device_count_property = modular_server_.createProperty(constants::device_count_property_name,constants::device_count_default);
  device_count_property.setRange(constants::device_count_min,constants::device_count_max);
  device_count_property.setArrayLengthRange(constants::WIRE_COUNT_MAX,constants::WIRE_COUNT_MAX);
  device_count_property.attachPostSetElementValueFunctor(makeFunctor((Functor1<size_t> *)0,*this,&WireInterface::setDeviceCountHandler));

  modular_server::Property & polling_enabled_property = modular_server_.createProperty(constants::polling_enabled_property_name,constants::polling_enabled_default);
  polling_enabled_property.setArrayLengthRange(constants::WIRE_COUNT_MAX,constants::WIRE_COUNT_MAX);
  polling_enabled_property.attachPostSetElementValueFunctor(makeFunctor((Functor1<size_t> *)0,*this,&WireInterface::updatePollingHandler));

  modular_server::Property & polling_period_property = modular_server_.createProperty(constants::polling_period_property_name,constants::polling_period_default);
  polling_period_property.setArrayLengthRange(constants::WIRE_COUNT_MAX,constants::WIRE_COUNT_MAX);
  polling_period_property.attachPostSetElementValueFunctor(makeFunctor((Functor1<size_t> *)0,*this,&WireInterface::updatePollingHandler));

  // Parameters

  // Functions

  // Callbacks
}

size_t WireInterface::getWireCount()
{
  long wire_count;
  modular_server_.property(constants::wire_count_property_name).getValue(wire_count);

  return wire_count;
}

size_t WireInterface::getDeviceCount(size_t wire_index)
{
  if (wire_index >= constants::WIRE_COUNT_MAX)
  {
    return 0;
  }
  long device_count;
  modular_server_.property(constants::device_count_property_name).getElementValue(wire_index,
    device_count);

  return device_count;
}

void WireInterface::setupPolling()
{
  for (size_t wire_index=0; wire_index<getWireCount(); ++wire_index)
  {
    updatePollingHandler(wire_index);
  }
}

void WireInterface::setWireCountHandler()
{
  size_t wire_count = getWireCount();

  modular_server::Property & device_count_property = modular_server_.property(constants::device_count_property_name);
  device_count_property.setArrayLengthRange(wire_count,wire_count);

  modular_server::Property & polling_enabled_property = modular_server_.property(constants::polling_enabled_property_name);
  polling_enabled_property.setArrayLengthRange(wire_count,wire_count);

  modular_server::Property & polling_period_property = modular_server_.property(constants::polling_period_property_name);
  polling_period_property.setArrayLengthRange(wire_count,wire_count);

}

void WireInterface::setDeviceCountHandler(size_t wire_index)
{
}

void WireInterface::pollingHandler(int wire_index)
{
}

void WireInterface::updatePollingHandler(size_t wire_index)
{
  bool polling_enabled;
  modular_server::Property & polling_enabled_property = modular_server_.property(constants::polling_enabled_property_name);
  polling_enabled_property.getElementValue(wire_index,polling_enabled);

  EventId & polling_event = polling_events_[wire_index];
  event_controller_.remove(polling_event);

  if (polling_enabled)
  {
    long polling_period;
    modular_server::Property & polling_period_property = modular_server_.property(constants::polling_period_property_name);
    polling_period_property.getElementValue(wire_index,polling_period);

    polling_event = event_controller_.addInfiniteRecurringEventUsingDelay(makeFunctor((Functor1<int> *)0,*this,&WireInterface::pollingHandler),
      polling_period,
      polling_period,
      wire_index);
    event_controller_.enable(polling_event);
  }
}
