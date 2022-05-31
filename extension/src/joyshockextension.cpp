#include "joyshockextension.h"
#include "SDL.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/variant/utlity_functions.hpp>

using namespace godot;

static const char *_joy_sensors[(size_t)JoySensor::JOY_SENSOR_MAX] = {
	"accelx",
	"accely",
	"accelz",
	"gyrox",
	"gyroy",
	"gyroz",
	"magnetx",
	"magnety",
	"magnetz",
	"inclinex",
	"incliney",
	"inclinez",
};

struct ControllerDevice {
	ControllerDevice(int id) :
			_has_accel(false), _has_gyro(false), _has_magnet(false), _has_incline(false) {
		if (SDL_IsGameController(id)) {
			_sdlController = SDL_GameControllerOpen(id);

			if (_sdlController) {
				_has_gyro =
						SDL_GameControllerHasSensor(_sdlController, SDL_SENSOR_GYRO);
				_has_accel =
						SDL_GameControllerHasSensor(_sdlController, SDL_SENSOR_ACCEL);

				if (_has_gyro) {
					SDL_GameControllerSetSensorEnabled(_sdlController, SDL_SENSOR_GYRO,
							SDL_TRUE);
				}
				if (_has_accel) {
					SDL_GameControllerSetSensorEnabled(_sdlController, SDL_SENSOR_ACCEL,
							SDL_TRUE);
				}
			}
		}
	}

	virtual ~ControllerDevice() { SDL_GameControllerClose(_sdlController); }

	inline bool isValid() { return _sdlController != nullptr; }

	bool _has_accel;
	bool _has_gyro;
	bool _has_magnet;
	bool _has_incline;
	SDL_GameController *_sdlController = nullptr;
};

void JoyShockExtension::_bind_methods() {
	// Methods
	ClassDB::bind_method(D_METHOD("get_joy_sensor"),
			&JoyShockExtension::get_joy_sensor);
};

JoyShockExtension::JoyShockExtension() {
	UtilityFunctions::print("Constructor.");
};

JoyShockExtension::~JoyShockExtension() {
	UtilityFunctions::print("Destructor.");
};

class Input : public Object {
}