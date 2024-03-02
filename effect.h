#ifndef EFFECT
#define EFFECT
class FFDEffect {
private:
short unsigned int effect_type;
short unsigned int type;
short unsigned int length;
short unsigned int delay;
short unsigned int button;
short unsigned int interval;
short unsigned int right_sat;
short unsigned int left_sat;
short signed int right_coeff;
short signed int left_coeff;
short unsigned int deadband;
short signed int center;
short unsigned int direction;
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
	void set_effect_type(short unsigned int effect_type){this->effect_type = effect_type;}
	void set_type(short unsigned int type){this->type = type;}
	void set_length(short unsigned int length){this->length = length;}
	void set_delay(short unsigned int delay){this->delay= delay;}
	void set_button(short unsigned int button){this->button = button;}
	void set_interval(short unsigned int interval){this->interval = interval;}
	void set_right_sat(short unsigned int right_sat){this->right_sat = right_sat;}
	void set_left_sat(short unsigned int left_sat){this->left_sat = left_sat;}
	void set_right_coeff(short signed int right_coeff){this->right_coeff = right_coeff;}
	void set_left_coeff(short signed int left_coeff){this->left_coeff = left_coeff;}
	void set_deadband(short unsigned int deadband){this->deadband = deadband;}
	void set_center(short signed int center){this->center = center;}
	void set_direction(short unsigned int direction){this->direction = direction;}
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

	short unsigned int get_effect_type(void){ return effect_type;}
	short unsigned int get_type(void){ return type;}
	short unsigned int get_length(void){ return length;}
	short unsigned int get_delay(void){return delay;}
	short unsigned int get_button(void){return button;}
	short unsigned int get_interval(void){return interval;}
	short unsigned int get_right_sat(void){return right_sat;}
	short unsigned int get_left_sat(void){return left_sat;}
	short signed int get_right_coeff(void){return right_coeff;}
	short signed int get_left_coeff(void){return left_coeff;}
	short unsigned int get_deadband(void){return deadband;}
	short signed int get_center(void){return center;}
	short unsigned int get_direction_type(void){ return direction_type;}
	short unsigned int get_direction(void){return direction;}
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
