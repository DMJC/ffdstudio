#include "ffb.h"
#include "effect.h"

using namespace std;


int test_haptic( SDL_Joystick * joystick, FFDEffect effect_data) {
 SDL_Haptic *haptic;
 SDL_HapticEffect effect;
 int effect_id;

 // Open the device
 haptic = SDL_HapticOpenFromJoystick( joystick );

 if (haptic == NULL) {
  cout << "Joystick isn't haptic" << endl;
  return -1;
 } // Most likely joystick isn't haptic
// cout << "Joystick can do force feedback!" << endl;

 // See if it can do sine waves
 if ((SDL_HapticQuery(haptic) & SDL_HAPTIC_SINE)==0) {
  cout << "joystick can't do sine waves" << endl;
  SDL_HapticClose(haptic); // No sine effect
  return -1;
 }

 // See if it can do gain adjustment
 if ((SDL_HapticQuery(haptic) & SDL_HAPTIC_GAIN)==0) {
  cout << "joystick can't adjust gain" << endl;
  SDL_HapticClose(haptic); // No sine effect
  return -1;
 }

 //set joystick to full strength if it supports it
 SDL_HapticSetGain( haptic, 100);

 // Create the effect
 SDL_memset( &effect, 0, sizeof(SDL_HapticEffect) ); // 0 is safe default

//enum hap { leftright, sawtoothup, sawtoothdown, sine, triangle };

 enum hap_type { condition, constant, leftright, periodic, ramp, custom};
 hap_type haptic_effect = static_cast<hap_type>(effect_data.get_type());
 cout << "\nHaptic Effect: " << haptic_effect << endl;
 cout << "data length: " <<  effect_data.get_length() << endl;
 int effect_length = 1000;
 cout << "Trying Effects" << endl;


Uint32 sdlValue = static_cast<Uint32>(effect_data.get_type());
cout << "Converted value: " << sdlValue << endl;
 switch (haptic_effect)
 {
 	case periodic:
	 	effect_length = effect_data.get_length(); // 3 seconds long
		effect.periodic.type = effect_data.get_effect_type();
 		effect.periodic.direction.type = effect_data.get_direction_type(); // Polar coordinates
		switch (effect_data.get_direction_type()){
			case 1:
				cout << "call 1: " << effect_data.get_direction_1() << endl;
 				effect.periodic.direction.dir[1] = effect_data.get_direction_1(); // Force comes from north at 180 degrees
			default:
				cout << "call 2: " << effect_data.get_direction_0() << endl;
		 		effect.periodic.direction.dir[0] = effect_data.get_direction_0(); // Force comes from north at 180 degrees
			break;
		}
	 	effect.periodic.length = effect_data.get_length(); // 3 seconds long
	 	effect.periodic.delay = effect_data.get_delay(); // 3 seconds long
 		effect.periodic.period = effect_data.get_period(); // 1500 ms
 		effect.periodic.phase = effect_data.get_phase(); // 18000 ms
	 	effect.periodic.magnitude = effect_data.get_magnitude(); // 32767 strength
 		effect.periodic.attack_length = effect_data.get_attack_length(); // 1000 = Takes 1 second to get max strength
 		effect.periodic.attack_level = effect_data.get_attack_level(); // 1000 = Takes 1 second to get max strength
		effect.periodic.fade_length = effect_data.get_fade_length(); // 1000 = Takes 1 second to fade away
		effect.periodic.fade_level = effect_data.get_fade_level(); // 1000 = Takes 1 second to fade away
	 break;
 	case ramp: cout << "Type: Ramp" << endl;
	 	effect_length = effect_data.get_length(); // 3 seconds long
		effect.ramp.type = SDL_HAPTIC_RAMP;
		effect.ramp.direction.type = effect_data.get_direction_type(); // Polar coordinates
		switch (effect_data.get_direction_type()){
			case 1:
				cout << "call 1: " << effect_data.get_direction_1() << endl;
 				effect.ramp.direction.dir[1] = effect_data.get_direction_1(); // Force comes from north at 180 degrees
			default:
				cout << "call 2: " << effect_data.get_direction_0() << endl;
		 		effect.ramp.direction.dir[0] = effect_data.get_direction_0(); // Force comes from north at 180 degrees
			break;
		}
	 	effect.ramp.length = effect_data.get_length(); // 3 seconds long
 		effect.ramp.attack_length = effect_data.get_attack_length(); // 1000 = Takes 1 second to get max strength
		effect.ramp.fade_length = effect_data.get_fade_length(); // 1000 = Takes 1 second to fade away
	 break;
 	case leftright:
		cout << "Left/Right" << endl;
	 	effect_length = effect_data.get_length(); // 3 seconds long
		effect.leftright.type = SDL_HAPTIC_LEFTRIGHT;
	 	effect.leftright.length = effect_data.get_length(); // 3 seconds long
	 	effect.leftright.large_magnitude = effect_data.get_large_magnitude(); // 3 seconds long
	 	effect.leftright.small_magnitude = effect_data.get_small_magnitude(); // 3 seconds long
	 break;
 	case condition:
		 cout << "Condition" << endl;
	 	effect_length = effect_data.get_length(); // 3 seconds long
 		effect.condition.type = effect_data.get_condition_type(); // Polar coordinates
		effect.condition.direction.type = effect_data.get_direction_type(); // Polar coordinates
		switch (effect_data.get_direction_type()){
			case 1:
				cout << "call 1: " << effect_data.get_direction_1() << endl;
 				effect.condition.direction.dir[1] = effect_data.get_direction_1(); // Force comes from north at 180 degrees
			default:
				cout << "call 2: " << effect_data.get_direction_0() << endl;
		 		effect.condition.direction.dir[0] = effect_data.get_direction_0(); // Force comes from north at 180 degrees
			break;
		}
	 	effect.condition.length = effect_data.get_length(); // 3 seconds long
		effect.condition.delay = effect_data.get_delay();
/*		switch(axes_enabled){
			case 2:
				effect.condition.right_sat[2] = effect_data.get_right_sat_2();
				effect.condition.left_sat[2] = effect_data.get_left_sat_2();
				effect.condition.right_coeff[2] = effect_data.get_right_coeff_2();
				effect.condition.left_coeff[2] = effect_data.get_left_coeff_2();
				effect.condition.deadband[2] = effect_data.get_deadband_2();
				effect.condition.center[2] = effect_data.get_center_2();
			case 1:
				effect.condition.right_sat[1] = effect_data.get_right_sat_1();
				effect.condition.left_sat[1] = effect_data.get_left_sat_1();
				effect.condition.right_coeff[1] = effect_data.get_right_coeff_1();
				effect.condition.left_coeff[1] = effect_data.get_left_coeff_1();
				effect.condition.deadband[1] = effect_data.get_deadband_1();
				effect.condition.center[1] = effect_data.get_center_1();
			default:
				effect.condition.right_sat[0] = effect_data.get_right_sat_0();
				effect.condition.left_sat[0] = effect_data.get_left_sat_0();
				effect.condition.right_coeff[0] = effect_data.get_right_coeff_0();
				effect.condition.left_coeff[0] = effect_data.get_left_coeff_0();
				effect.condition.deadband[0] = effect_data.get_deadband_0();
				effect.condition.center[0] = effect_data.get_center_0();
		}*/
	 break;
 	case custom:
		 cout << "Custom" << endl;
	 	effect_length = effect_data.get_length(); // 3 seconds long
 		effect.custom.type = SDL_HAPTIC_CUSTOM;
		effect.custom.direction.type = effect_data.get_direction_type(); // Polar coordinates
		switch (effect_data.get_direction_type()){
			case 1:
				cout << "call 1: " << effect_data.get_direction_1() << endl;
 				effect.custom.direction.dir[1] = effect_data.get_direction_1(); // Force comes from north at 180 degrees
			default:
				cout << "call 2: " << effect_data.get_direction_0() << endl;
		 		effect.custom.direction.dir[0] = effect_data.get_direction_0(); // Force comes from north at 180 degrees
			break;
		}
 		effect.custom.period = effect_data.get_period(); // 1500 ms
	 	effect.custom.length = effect_data.get_length(); // 3 seconds long
 		effect.custom.attack_length = effect_data.get_attack_length(); // 1000 = Takes 1 second to get max strength
		effect.custom.fade_length = effect_data.get_fade_length(); // 1000 = Takes 1 second to fade away
	 break;
 	case constant: cout << "Constant" << endl; 
	 	effect_length = effect_data.get_length(); // 3 seconds long
		effect.constant.type = SDL_HAPTIC_CONSTANT;
		effect.constant.direction.type = effect_data.get_direction_type(); // Polar coordinates
		switch (effect_data.get_direction_type()){
			case 1:
				cout << "call 1: " << effect_data.get_direction_1() << endl;
 				effect.constant.direction.dir[1] = effect_data.get_direction_1(); // Force comes from north at 180 degrees
			default:
				cout << "call 2: " << effect_data.get_direction_0() << endl;
		 		effect.constant.direction.dir[0] = effect_data.get_direction_0(); // Force comes from north at 180 degrees
			break;
		}
	 	effect.constant.length = effect_data.get_length(); // 3 seconds long
	 	effect.constant.delay = effect_data.get_delay(); // delay before starting 1 second
 		effect.constant.attack_length = effect_data.get_attack_length(); // 1000 = Takes 1 second to get max strength
 		effect.constant.attack_level = effect_data.get_attack_level(); // 1000 = Takes 1 second to get max strength
		effect.constant.fade_length = effect_data.get_fade_length(); // 1000 = Takes 1 second to fade away
		effect.constant.fade_level = effect_data.get_fade_level(); // 1000 = Takes 1 second to fade away
	 break;
 }


 // Upload the effect
 effect_id = SDL_HapticNewEffect( haptic, &effect );

 // Test the effect
 SDL_HapticRunEffect( haptic, effect_id, 1 );
 cout << "How Long: " << effect_length << endl;
 SDL_Delay(effect_length); // Wait for the effect to finish

 // We destroy the effect, although closing the device also does this
 SDL_HapticDestroyEffect( haptic, effect_id );

 // Close the device
 SDL_HapticClose(haptic);
 return 0; // Success
}

void open_joysticks(FFDEffect effect_data){
	SDL_Joystick *joy;

	// Initialize the joystick subsystem
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	// Check for joystick
	if (SDL_NumJoysticks() > 0) {
	    // Open joystick
	    joy = SDL_JoystickOpen(0);

	    if (joy) {
	        cout << "\nOpened Joystick 0" << endl;
	        cout << "Name: " << SDL_JoystickNameForIndex(0) << endl;
	        cout << "Number of Axes: " << SDL_JoystickNumAxes(joy) << endl;
	        cout << "Number of Buttons: " <<  SDL_JoystickNumButtons(joy) << endl;
	        cout << "Number of Balls: " <<  SDL_JoystickNumBalls(joy) << endl;
		int result = test_haptic(joy, effect_data);
		if (result == -1){
			cout << "error, not a Force Feedback Device" << endl;
		}
	    	} else {
	        cout << "Couldn't open Joystick 0" << endl;
	    }

	    // Close if opened
	    if (SDL_JoystickGetAttached(joy)) {	
	        SDL_JoystickClose(joy);
	    }
	}
}

void open_joys(FFDEffect effect_data){
	open_joysticks(effect_data);
}

void init_sdl(void){
        	cout << "Starting SDL\n this will take a while" << SDL_GetError( ) << endl;
	if (SDL_Init( SDL_INIT_HAPTIC ) < 0 )
	{
        	cout << " error starting SDL " <<SDL_GetError( ) << endl;
	} else {
		cout << "SDL Started!" << endl;
	}
}
