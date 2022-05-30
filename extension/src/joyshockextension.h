// joyshockextension.h
#pragma once
#ifndef JOYSHOCKEXTENSION_CLASS_H
#define JOYSHOCKEXTENSION_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/input.hpp>

#include <godot_cpp/core/defs.hpp>

#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

typedef struct IMU_STATE
{
	Vector3 accel;
	Vector3 gyro;
	Vector3 magnet;
} IMU_STATE;

typedef struct MOTION_STATE
{
	Quaternion quat;
	Vector3 accel;
	Vector3 grav;
} MOTION_STATE;

class JoyShockExtension : public Input
{
    GDCLASS(JoyShockExtension, Input);

protected:
    static void _bind_methods();

public:
	// Constants

    JoyShockExtension();
    ~JoyShockExtension();

	// Functions
/*	
    virtual int32_t ConnectDevices() = 0;
	virtual int32_t GetConnectedDeviceHandles(int32_t* deviceHandleArray, int32_t size) = 0;
	virtual void DisconnectAndDisposeAll() = 0;
	virtual IMU_STATE GetIMUState(int32_t deviceId) = 0;
	virtual MOTION_STATE GetMotionState(int32_t deviceId) = 0;
	virtual real_t GetLeftTrigger(int32_t deviceId) = 0;
	virtual real_t GetRightTrigger(int32_t deviceId) = 0;
	virtual real_t GetGyroX(int32_t deviceId) = 0;
	virtual real_t GetGyroY(int32_t deviceId) = 0;
	virtual real_t GetGyroZ(int32_t deviceId) = 0;
	virtual real_t GetAccelX(int32_t deviceId) = 0;
	virtual real_t GetAccelY(int32_t deviceId) = 0;
	virtual real_t GetAccelZ(int32_t deviceId) = 0;
	virtual real_t GetPollRate(int32_t deviceId) = 0;
	virtual void ResetContinuousCalibration(int32_t deviceId) = 0;
	virtual void StartContinuousCalibration(int32_t deviceId) = 0;
	virtual void PauseContinuousCalibration(int32_t deviceId) = 0;
	virtual void GetCalibrationOffset(int32_t deviceId, real_t& xOffset, real_t& yOffset, real_t& zOffset) = 0;
	virtual void SetCalibrationOffset(int32_t deviceId, real_t xOffset, real_t yOffset, real_t zOffset) = 0;
	virtual void SetCallback(void (*callback)(int32_t, IMU_STATE, IMU_STATE, real_t)) = 0;
	virtual int32_t GetControllerType(int32_t deviceId) = 0;
	virtual int32_t GetControllerColour(int32_t deviceId) = 0;
*/
};

#endif // JOYSHOCKEXTENSION_CLASS_H