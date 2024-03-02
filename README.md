# Force Feedback Design Studio
A tool for creating/editing Force Feedback Effects.

Notes:
- Compatible with Wayland
- Currently Periodic effects work the best, smaller values are more effective. The default when creating a periodic effect works.
- Startup is a little slow due to SDL loading.

Testing:
- Tested on Micosoft Sidewinder Force Feedback 2.
- Will soon be tested on Micosoft Sidewinder Force Feedback Pro.
- Should work on any Joystick or Wheel device as long as libSDL2 supports it.

Dependencies:
Ensure you have libSDL2 installed along with gtkmm-3.0

Compiling:
Run Make
