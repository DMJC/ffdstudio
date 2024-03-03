#ifndef FFB
#define FFB
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_haptic.h>
#include <iostream>
#include <string>
#include "ffd.h"
#include "effect.h"

int run_force_feedback( SDL_Joystick * joystick, int effect_opt, FFDEffect effect_data );
void open_joysticks(FFDEffect effect_data);
//void run_ffb(Gtk::Window& window);
//int init_ffb(FFDEffect effect_data);
void open_joys(FFDEffect effect_data);
void init_sdl(void);
#endif //FFB
