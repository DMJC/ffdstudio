#ifndef EFFECT
#define EFFECT
#include <string>
using namespace std;

class FFDEffect {
private:
string effect_name;
unsigned int type;
unsigned int effect_type;
unsigned short int condition_type;
short unsigned int length;
short unsigned int delay;
short unsigned int button;
short unsigned int interval;
short unsigned int right_sat_0;
short unsigned int right_sat_1;
short unsigned int right_sat_2;
short unsigned int left_sat_0;
short unsigned int left_sat_1;
short unsigned int left_sat_2;
short signed int right_coeff_0;
short signed int right_coeff_1;
short signed int right_coeff_2;
short signed int left_coeff_0;
short signed int left_coeff_1;
short signed int left_coeff_2;
short unsigned int deadband_0;
short unsigned int deadband_1;
short unsigned int deadband_2;
short signed int center_0;
short signed int center_1;
short signed int center_2;
short unsigned int direction_0;
short unsigned int direction_1;
short unsigned int direction_type;
short unsigned int period;
short unsigned int samples;
short signed int magnitude;
short signed int large_magnitude;
short signed int small_magnitude;
short signed int offset;
short unsigned int phase;
short unsigned int attack_length;
short unsigned int attack_level;
short unsigned int fade_length;
short unsigned int fade_level;
//short unsigned int* data should contain channels*
//short unsigned int8 channels

public:
	void set_effect_name(string effect_name){this->effect_name = effect_name;}
	void set_type(unsigned int type){this->type = type;}
	void set_effect_type(unsigned int effect_type){this->effect_type = effect_type;}
	void set_condition_type(unsigned short int condition_type){this->condition_type = condition_type;}
	void set_length(short unsigned int length){this->length = length;}
	void set_delay(short unsigned int delay){this->delay= delay;}
	void set_button(short unsigned int button){this->button = button;}
	void set_interval(short unsigned int interval){this->interval = interval;}
	void set_right_sat_0(short unsigned int right_sat_0){this->right_sat_0 = right_sat_0;}
	void set_right_sat_1(short unsigned int right_sat_1){this->right_sat_1 = right_sat_1;}
	void set_right_sat_2(short unsigned int right_sat_2){this->right_sat_2 = right_sat_2;}
	void set_left_sat_0(short unsigned int left_sat_0){this->left_sat_0 = left_sat_0;}
	void set_left_sat_1(short unsigned int left_sat_1){this->left_sat_1 = left_sat_1;}
	void set_left_sat_2(short unsigned int left_sat_2){this->left_sat_2 = left_sat_2;}
	void set_right_coeff_0(short signed int right_coeff_0){this->right_coeff_0 = right_coeff_0;}
	void set_right_coeff_1(short signed int right_coeff_1){this->right_coeff_1 = right_coeff_1;}
	void set_right_coeff_2(short signed int right_coeff_2){this->right_coeff_2 = right_coeff_2;}
	void set_left_coeff_0(short signed int left_coeff_0){this->left_coeff_0 = left_coeff_0;}
	void set_left_coeff_1(short signed int left_coeff_1){this->left_coeff_1 = left_coeff_1;}
	void set_left_coeff_2(short signed int left_coeff_2){this->left_coeff_2 = left_coeff_2;}
	void set_deadband_0(short unsigned int deadband_0){this->deadband_0 = deadband_0;}
	void set_deadband_1(short unsigned int deadband_1){this->deadband_1 = deadband_1;}
	void set_deadband_2(short unsigned int deadband_2){this->deadband_2 = deadband_1;}
	void set_center_0(short signed int center_0){this->center_0 = center_0;}
	void set_center_1(short signed int center_1){this->center_1 = center_1;}
	void set_center_2(short signed int center_2){this->center_2 = center_2;}
	void set_direction_0(short unsigned int direction_0){this->direction_0 = direction_0;}
	void set_direction_1(short unsigned int direction_1){this->direction_1 = direction_1;}
	void set_direction_type(short unsigned int direction_type){this->direction_type = direction_type;}
	void set_period(short unsigned int period){this->period = period;}
	void set_samples(short unsigned int samples){this->samples = samples;}
	void set_magnitude(short signed int magnitude){this->magnitude = magnitude;}
	void set_large_magnitude(short signed int large_magnitude){this->large_magnitude = large_magnitude;}
	void set_small_magnitude(short signed int small_magnitude){this->small_magnitude = small_magnitude;}
	void set_offset(short signed int offset){this->offset = offset;}
	void set_phase(short unsigned int phase){this->phase = phase;}
	void set_attack_length(short unsigned int attack_length){this->attack_length = attack_length;}
	void set_attack_level(short unsigned int attack_level){this->attack_level = attack_level;}
	void set_fade_length(short unsigned int fade_length){this->fade_length = fade_length;}
	void set_fade_level(short unsigned int fade_level){this->fade_level = fade_level;}

	string get_effect_name(void){ return effect_name; }
	unsigned int get_type(void){ return type;}
	unsigned int get_effect_type(void){ return effect_type;}
	unsigned short int get_condition_type(void){ return condition_type;}
	short unsigned int get_length(void){ return length;}
	short unsigned int get_delay(void){return delay;}
	short unsigned int get_button(void){return button;}
	short unsigned int get_interval(void){return interval;}
	short unsigned int get_right_sat_0(void){return right_sat_0;}
	short unsigned int get_right_sat_1(void){return right_sat_1;}
	short unsigned int get_right_sat_2(void){return right_sat_2;}
	short unsigned int get_left_sat_0(void){return left_sat_0;}
	short unsigned int get_left_sat_1(void){return left_sat_1;}
	short unsigned int get_left_sat_2(void){return left_sat_2;}
	short signed int get_right_coeff_0(void){return right_coeff_0;}
	short signed int get_right_coeff_1(void){return right_coeff_1;}
	short signed int get_right_coeff_2(void){return right_coeff_2;}
	short signed int get_left_coeff_0(void){return left_coeff_0;}
	short signed int get_left_coeff_1(void){return left_coeff_1;}
	short signed int get_left_coeff_2(void){return left_coeff_2;}
	short unsigned int get_deadband_0(void){return deadband_0;}
	short unsigned int get_deadband_1(void){return deadband_1;}
	short unsigned int get_deadband_2(void){return deadband_2;}
	short signed int get_center_0(void){return center_0;}
	short signed int get_center_1(void){return center_1;}
	short signed int get_center_2(void){return center_2;}
	short unsigned int get_direction_type(void){ return direction_type;}
	short unsigned int get_direction_0(void){return direction_0;}
	short unsigned int get_direction_1(void){return direction_1;}
	short unsigned int get_period(void){return period;}
	short unsigned int get_samples(void){return samples;}
	short signed int get_magnitude(void){return magnitude;}
	short signed int get_large_magnitude(void){return large_magnitude;}
	short signed int get_small_magnitude(void){return small_magnitude;}
	short signed int get_offset(void){return offset;}
	short unsigned int get_phase(void){return phase;}
	short unsigned int get_attack_length(void){return attack_length;}
	short unsigned int get_attack_level(void){return attack_level;}
	short unsigned int get_fade_length(void){return fade_length;}
	short unsigned int get_fade_level(void){return fade_level;}
};
#endif //EFFECT
