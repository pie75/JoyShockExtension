// joyshockextension.h
#pragma once
#ifndef JOYSHOCKEXTENSION_CLASS_H
#define JOYSHOCKEXTENSION_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include "input_sensor_enums.h"

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/defs.hpp>

#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

// Main loop process ?
// Should this also serve as the SDL Wrapper? It will for now, I suppose.
// Since we're initialising SDL when the plugin is loaded,
// this should poll the SDL devices and update our Input singleton.
// ...I think
// Try to mirror JOYPAD_WINDOWS.h here maybe?
class JoyShockExtension : public{
protected:
	JoyShockExtension() {}

public:
	struct IMU_STATE {
		Vector3 accelerometer;
		Vector3 gyroscope;
	} IMU_STATE;

	struct MOTION_STATE {
		Quaternion quat;
		Vector3 accel;
		Vector3 grav;
	} MOTION_STATE;

	virtual ~JoyShockExtension() {}
	static JoyShockExtension *get_new();

	virtual int connect_devices() = 0;
	void probe_joypads();
	void process_joypads();

	virtual Vector3 get_accelerometer(int device) = 0;
	virtual Vector3 get_gyroscope(int device) = 0;

	virtual int get_connected_device_handles(int *device_handle_array,
			int size) = 0;
	virtual void disconnect_all() = 0;

private:
	enum {
		JOYPADS_MAX = 16,
		JOY_SENSOR_COUNT = 2,
		JOY_SENSOR_AXIS_COUNT = 6
	}
};

#endif // JOYSHOCKEXTENSION_CLASS_H