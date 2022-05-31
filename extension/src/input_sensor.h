// input_sensor.h
// Input Singleton for Sensors
// Needed since we can't(?) modify the engine's Singleton at runtime.
#ifndef INPUT_SENSOR_H
#define INPUT_SENSOR_H

#include "input_sensor_enums.h"

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/input.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/defs.hpp>

#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

class InputSensor : public Input {
	GDNATIVE_CLASS(InputSensor, Input)

public:
	float get_joy_sensor(int p_device, JoySensor p_sensor) const;
	void set_joy_sensor(int p_device, JoySensor p_sensor, float p_value);
};

#endif // INPUT_SENSOR_H