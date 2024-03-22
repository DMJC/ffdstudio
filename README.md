# Force Feedback Design Studio
A tool for creating/editing Force Feedback Effects written in C++/GTKMM-4.0

## Major Milestone Reached - Loading/Saving Works.
Can be used to create/load test and share Force Feedback Effects with other users!

### Notes:
- Compatible with Wayland
- Currently Periodic effects work the best, smaller values are more effective. The default when creating a periodic effect works.
- Able to load and save files with .ffb extension. 

### Testing:
- Tested on Micosoft Sidewinder Force Feedback 2.
- Will soon be tested on Micosoft Sidewinder Force Feedback Pro.
- Should work on any Joystick or Wheel device as long as libSDL2 supports it.

### Dependencies:
- Ensure you have libSDL2 installed along with gtkmm-4.0

### Compiling:
- Run Make

## Roadmap
- Implement some decent effects/sane values for each effect type.
- Start Packaging for Distros
  
