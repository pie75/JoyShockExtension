// input_event_sensor.h
// Input Event for Sensors
// The engine's abstract format for inputs.
// Things in the viewport look for these and consume them,
// then do stuff in reaction.
#ifndef INPUT_EVENT_SENSOR_H
#define INPUT_EVENT_SENSOR_H

#include "input_sensor_enums.h"

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/input_event.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/defs.hpp>

#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

class InputEventSensor : public InputEvent {
	GDCLASS(InputEventSensor, InputEvent);

protected:
	static void _bind_methods();

public:
	// Constants

	InputEventSensor();
	~InputEventSensor();

	// Functions

	// Properties
	virtual IMU_STATE get_joy_imu_state(int device) = 0;
	virtual MOTION_STATE get_joy_motion_state(int device) = 0;

	virtual void set_joy_imu_state() = 0;
	virtual void set_joy_motion_state() = 0;

	virtual Vector3 get_joy_accelerometer(int device) = 0;
	virtual Vector3 get_joy_gyroscope(int device) = 0;
	virtual Vector3 get_joy_magnetometer(int device) = 0;
	virtual Vector3 get_joy_inclinometer(int device) = 0;
	virtual float get_joy_sensor(int device, JoySensor sensor) = 0;

	virtual float get_joy_pollrate(int device) = 0;

	virtual void set_callback(void (*callback)(int, IMU_STATE, IMU_STATE,
			float)) = 0;

private:
	// Properties
	float joy_pollrate = 0;
};

#endif // INPUT_EVENT_SENSOR_H