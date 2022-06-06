# JoyShockExtension

A [GDExtension](https://godotengine.org/article/introducing-gd-extensions) for [Godot 4.x](https://github.com/godotengine/godot), that aims to extend the functionality of game controllers in Godot by linking against [SDL2](http://libsdl.org/), using [JoyShockMapper](https://docs.godotengine.org/en/latest/community/contributing/code_style_guidelines.html) as an implementation reference.  

Currently, it does a big fat nothing.
 
The target scope is to support Accelerometer and Gyroscope Sensors. Additional features like implementation of [GamepadMotionHelpers](https://github.com/JibbSmart/GamepadMotionHelpers), will follow.  
However, this extension is by nature designed to be a temporary solution, holding the line until adding these features to Godot's core is viable. You can follow the proposal and discussion for that [here](https://github.com/godotengine/godot-proposals/issues/2829)

## Implementation
The current idea is to extend Godot's Input singleton IF: possible. ELSE: mirror it, creating a separate SensorInput singleton that gets updated by SDL, mirroring how [`joypad_windows.h`](https://github.com/godotengine/godot/blob/master/platform/windows/joypad_windows.h) probes and processes joypads.
Then to mirror how Input is processed into InputEvents which can be used by the Engine.  

I think the Viewport polls the InputEvents at the physics framerate set in the game properties, and that causes a chain reaction down through Input, to the xInput/dInput backend.
Whatever it is, the Extension needs to be linked to the Viewport class somehow.  
~~I'm not really sure if that's exactly what happens but it seems to be about right.~~  
Except, it really doesn't make sense for things to happen that way. It has to be the case that the input from the user is updated when the user gives it. Perhaps the input API puts data into the singleton on demand, and it's just that the singleton is checked at the physics framerate?  

After the inputs are in the Engine, end users need a way to access them.
Raw IMU data will be output as usable axes and Vector3, while filtered motion data will be given as Quaternion Orientation, Gravity, and Acceleration.

Then, we need to link the Singletons via Godot's internal controller count, using GUID, so that we can filter which controllers are giving us which sensor data. It's no good that you have controllers when you can only use all of them for one player. :'(

## Progress
0. ☑️ It Builds. That's something, sometimes.
1. ❎ Input is polled from SDL2 
2. ❎ Inputs are processed into Singleton
3. ❎ InputEvents are generated from Singleton
4. ❎ Viewport handles InputEvents
5. ❎ Raw IMU Data is made available to end user as Vector3 and axes.
6. ❎ Data is filtered into motion data (Quaternions, Gravity, Acceleration) for end user.
7. ❎ Multiple controllers supported.

## Contributing
I barely know what I'm doing, and I'm about as good at programming as I am at cooking ([awful](https://cdn.discordapp.com/attachments/309861882351583233/892518367704018974/unknown.png)).  

### If you're able to help out, it would be greatly appreciated.  

I have a rough idea of what's going on and where, but things are bound to be messy and shift around substantially.  
Even if you can't help directly, If you have any understanding, especially a better understanding, of how Godot's core and input backend work, please feel free to advise or review. Contact me!  

Right now everything is on Windows,
If you can work on Mac, Linux, Android, iOS, or more - there isn't anything for you to port, but there will be in future!

The "Style guide" is to [match godot](https://docs.godotengine.org/en/latest/community/contributing/code_style_guidelines.html) as closely as possible. That means trying to use clang-format. But I'm terrible at it myself.  
Try to comment any code you can - documenting what things do should be done in the code, much like how SDL has explanation paragraphs in its headers. This extension has no intention of being small or lightweight, so don't worry about that as long as what you've done can be explained.

## Building the extension
1. Clone the extension recursively from this repository
```bash
# --recursive to automatically load the submodule godot-cpp
git clone --recursive https://github.com/pie75/JoyShockExtension.git
```

2. Make sure you are in the top level of the repository
```bash
pwd
.../JoyShockExtension
```

3. Go inside the godot-cpp folder
```bash
cd godot-cpp
```

4. Compile godot-cpp and generate bindings
```bash
scons target=debug generate_bindings=yes
```

5. Go back to the top level of the directory
```bash
cd ..
```

6. Compile the extension
```bash
scons target=debug
```
