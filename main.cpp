#include "ffd.h"

FFDWindow::FFDWindow() 
{
	name_label.set_label("Profile Name: ");
	effect_type_label.set_label("Effect Type: ");
	dir_type_label.set_label("Direction Type: ");
	dir_label.set_label("Direction (Degrees): ");
	delay_label.set_label("Delay before start (in ms): ");
	period_label.set_label("Period (in ms): ");
	phase_label.set_label("Phase (100ths of Degrees): ");
	offset_label.set_label("Offset (size of wave): ");
	magnitude_label.set_label("Magnitude: ");
	large_magnitude_label.set_label("Large Magnitude: ");
	small_magnitude_label.set_label("Small Magnitude: ");
	level_label.set_label("Strength of effect: ");
	start_strength_label.set_label("Strength at start of effect: ");
	end_strength_label.set_label("Strength at end of effect: ");
	length_label.set_label("Length Time (Seconds): ");
	attack_label.set_label("Attack Length (seconds to max strength): ");
	attack_lvl_label.set_label("Attack Level (at start of Attack): ");
	fade_label.set_label("Fade Length (seconds to fade off): ");
	fade_lvl_label.set_label("Fade Level (level at end of fade): ");
	left_sat_label.set_label("Left Level: ");
	left_coeff_label.set_label("Left Coefficient: ");
	right_sat_label.set_label("Right Level: ");
	right_coeff_label.set_label("Right Coefficient: ");
	deadband_label.set_label("Deadzone Size: ");
	center_label.set_label("Center of Deadzone: ");
	effect_header_label.set_margin_top(8);
	effect_header_label.set_margin_bottom(8);

	//Create a Dropdown combo
	effect_type.append("Left/Right");
	effect_type.append("Sawtooth Up");
	effect_type.append("Sawtooth Down");
	effect_type.append("Sine");
	effect_type.append("Triangle");
	effect_type.set_active(0);

	direction_type.append("Polar");
	direction_type.append("Cartesian");
	direction_type.append("Spherical");
	direction_type.set_active(0);

	condition_type.append("Spring");
	condition_type.append("Damper");
	condition_type.append("Inertia");
	condition_type.append("Friction");
	condition_type.set_active(0);

	// Create a scale widget
	direction_0.set_range(0, 27000);
	direction_0.set_digits(0); // Set number of digits after the decimal point
	direction_0.set_draw_value(FALSE); // Display the value on the scale
	// Add marks to the scale
	direction_0.add_mark(0, Gtk::PositionType::TOP, "0");
	direction_0.add_mark(9000, Gtk::PositionType::TOP, "90");
	direction_0.add_mark(18000, Gtk::PositionType::TOP, "180");
	direction_0.add_mark(27000, Gtk::PositionType::TOP, "270");
	direction_0.set_value(18000);
	direction_0.set_hexpand();
	direction_0.set_vexpand();

	// Create a scale widget
	direction_1.set_range(0, 27000);
	direction_1.set_digits(0); // Set number of digits after the decimal point
	direction_1.set_draw_value(FALSE); // Display the value on the scale
	// Add marks to the scale
	direction_1.add_mark(0, Gtk::PositionType::TOP, "0");
	direction_1.add_mark(9000, Gtk::PositionType::TOP, "90");
	direction_1.add_mark(18000, Gtk::PositionType::TOP, "180");
	direction_1.add_mark(27000, Gtk::PositionType::TOP, "270");
	direction_1.set_value(9000);
	direction_1.set_hexpand();
	direction_1.set_vexpand();

	left_coeff_0.set_range(-32767, 32767);
	left_coeff_0.set_digits(0); // Set number of digits after the decimal point
	left_coeff_0.set_draw_value(TRUE); // Display the value on the scale
	left_coeff_0.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	left_coeff_0.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	left_coeff_0.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	left_coeff_0.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	left_coeff_0.add_mark(0, Gtk::PositionType::TOP, "0%");
	left_coeff_0.add_mark(9000, Gtk::PositionType::TOP, "25%");
	left_coeff_0.add_mark(18000, Gtk::PositionType::TOP, "50%");
	left_coeff_0.add_mark(27000, Gtk::PositionType::TOP, "75%");
	left_coeff_0.add_mark(32767, Gtk::PositionType::TOP, "100%");
	left_coeff_0.set_hexpand();
	left_coeff_0.set_vexpand();

	left_coeff_1.set_range(-32767, 32767);
	left_coeff_1.set_digits(0); // Set number of digits after the decimal point
	left_coeff_1.set_draw_value(TRUE); // Display the value on the scale
	left_coeff_1.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	left_coeff_1.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	left_coeff_1.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	left_coeff_1.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	left_coeff_1.add_mark(0, Gtk::PositionType::TOP, "0%");
	left_coeff_1.add_mark(9000, Gtk::PositionType::TOP, "25%");
	left_coeff_1.add_mark(18000, Gtk::PositionType::TOP, "50%");
	left_coeff_1.add_mark(27000, Gtk::PositionType::TOP, "75%");
	left_coeff_1.add_mark(32767, Gtk::PositionType::TOP, "100%");
	left_coeff_1.set_hexpand();
	left_coeff_1.set_vexpand();

	left_coeff_2.set_range(-32767, 32767);
	left_coeff_2.set_digits(0); // Set number of digits after the decimal point
	left_coeff_2.set_draw_value(TRUE); // Display the value on the scale
	left_coeff_2.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	left_coeff_2.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	left_coeff_2.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	left_coeff_2.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	left_coeff_2.add_mark(0, Gtk::PositionType::TOP, "0%");
	left_coeff_2.add_mark(9000, Gtk::PositionType::TOP, "25%");
	left_coeff_2.add_mark(18000, Gtk::PositionType::TOP, "50%");
	left_coeff_2.add_mark(27000, Gtk::PositionType::TOP, "75%");
	left_coeff_2.add_mark(32767, Gtk::PositionType::TOP, "100%");
	left_coeff_2.set_hexpand();
	left_coeff_2.set_vexpand();

	right_coeff_0.set_range(-32767, 32767);
	right_coeff_0.set_digits(0); // Set number of digits after the decimal point
	right_coeff_0.set_draw_value(TRUE); // Display the value on the scale
	right_coeff_0.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	right_coeff_0.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	right_coeff_0.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	right_coeff_0.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	right_coeff_0.add_mark(0, Gtk::PositionType::TOP, "0%");
	right_coeff_0.add_mark(9000, Gtk::PositionType::TOP, "25%");
	right_coeff_0.add_mark(18000, Gtk::PositionType::TOP, "50%");
   	right_coeff_0.add_mark(27000, Gtk::PositionType::TOP, "75%");
   	right_coeff_0.add_mark(32767, Gtk::PositionType::TOP, "100%");
	right_coeff_0.set_hexpand();
	right_coeff_0.set_vexpand();

	right_coeff_1.set_range(-32767, 32767);
	right_coeff_1.set_digits(0); // Set number of digits after the decimal point
	right_coeff_1.set_draw_value(TRUE); // Display the value on the scale
	right_coeff_1.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	right_coeff_1.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	right_coeff_1.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	right_coeff_1.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	right_coeff_1.add_mark(0, Gtk::PositionType::TOP, "0%");
	right_coeff_1.add_mark(9000, Gtk::PositionType::TOP, "25%");
	right_coeff_1.add_mark(18000, Gtk::PositionType::TOP, "50%");
   	right_coeff_1.add_mark(27000, Gtk::PositionType::TOP, "75%");
   	right_coeff_1.add_mark(32767, Gtk::PositionType::TOP, "100%");
	right_coeff_1.set_hexpand();
	right_coeff_1.set_vexpand();

	right_coeff_2.set_range(-32767, 32767);
	right_coeff_2.set_digits(0); // Set number of digits after the decimal point
	right_coeff_2.set_draw_value(TRUE); // Display the value on the scale
	right_coeff_2.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	right_coeff_2.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	right_coeff_2.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	right_coeff_2.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	right_coeff_2.add_mark(0, Gtk::PositionType::TOP, "0%");
	right_coeff_2.add_mark(9000, Gtk::PositionType::TOP, "25%");
	right_coeff_2.add_mark(18000, Gtk::PositionType::TOP, "50%");
   	right_coeff_2.add_mark(27000, Gtk::PositionType::TOP, "75%");
   	right_coeff_2.add_mark(32767, Gtk::PositionType::TOP, "100%");
	right_coeff_2.set_hexpand();
	right_coeff_2.set_vexpand();

	left_sat_0.set_range(0, 65535);
	left_sat_0.set_digits(0); // Set number of digits after the decimal point
	left_sat_0.set_draw_value(TRUE); // Display the value on the scale
	left_sat_0.add_mark(0, Gtk::PositionType::TOP, "0%");
	left_sat_0.add_mark(16384, Gtk::PositionType::TOP, "25%");
	left_sat_0.add_mark(32768, Gtk::PositionType::TOP, "50%");
	left_sat_0.add_mark(49172, Gtk::PositionType::TOP, "75%");
	left_sat_0.add_mark(65535, Gtk::PositionType::TOP, "100%");
	left_sat_0.set_value(32768);
	left_sat_0.set_hexpand();
	left_sat_0.set_vexpand();

	left_sat_1.set_range(0, 65535);
	left_sat_1.set_digits(0); // Set number of digits after the decimal point
	left_sat_1.set_draw_value(TRUE); // Display the value on the scale
	left_sat_1.add_mark(0, Gtk::PositionType::TOP, "0%");
	left_sat_1.add_mark(16384, Gtk::PositionType::TOP, "25%");
	left_sat_1.add_mark(32768, Gtk::PositionType::TOP, "50%");
	left_sat_1.add_mark(49172, Gtk::PositionType::TOP, "75%");
	left_sat_1.add_mark(65535, Gtk::PositionType::TOP, "100%");
	left_sat_1.set_value(32768);
	left_sat_1.set_hexpand();
	left_sat_1.set_vexpand();

	left_sat_2.set_range(0, 65535);
	left_sat_2.set_digits(0); // Set number of digits after the decimal point
	left_sat_2.set_draw_value(TRUE); // Display the value on the scale
	left_sat_2.add_mark(0, Gtk::PositionType::TOP, "0%");
	left_sat_2.add_mark(16384, Gtk::PositionType::TOP, "25%");
	left_sat_2.add_mark(32768, Gtk::PositionType::TOP, "50%");
	left_sat_2.add_mark(49172, Gtk::PositionType::TOP, "75%");
	left_sat_2.add_mark(65535, Gtk::PositionType::TOP, "100%");
	left_sat_2.set_value(32768);
	left_sat_2.set_hexpand();
	left_sat_2.set_vexpand();

	right_sat_0.set_range(0, 65535);
	right_sat_0.set_digits(0); // Set number of digits after the decimal point
	right_sat_0.set_draw_value(TRUE); // Display the value on the scale
	right_sat_0.add_mark(0, Gtk::PositionType::TOP, "0%");
	right_sat_0.add_mark(16384, Gtk::PositionType::TOP, "25%");
	right_sat_0.add_mark(32768, Gtk::PositionType::TOP, "50%");
	right_sat_0.add_mark(49172, Gtk::PositionType::TOP, "75%");
	right_sat_0.add_mark(65535, Gtk::PositionType::TOP, "100%");
	right_sat_0.set_value(32768);
	right_sat_0.set_hexpand();
	right_sat_0.set_vexpand();

	right_sat_1.set_range(0, 65535);
	right_sat_1.set_digits(0); // Set number of digits after the decimal point
	right_sat_1.set_draw_value(TRUE); // Display the value on the scale
	right_sat_1.add_mark(0, Gtk::PositionType::TOP, "0%");
	right_sat_1.add_mark(16384, Gtk::PositionType::TOP, "25%");
	right_sat_1.add_mark(32768, Gtk::PositionType::TOP, "50%");
	right_sat_1.add_mark(49172, Gtk::PositionType::TOP, "75%");
	right_sat_1.add_mark(65535, Gtk::PositionType::TOP, "100%");
	right_sat_1.set_value(32768);
	right_sat_1.set_hexpand();
	right_sat_1.set_vexpand();

	right_sat_2.set_range(0, 65535);
	right_sat_2.set_digits(0); // Set number of digits after the decimal point
	right_sat_2.set_draw_value(TRUE); // Display the value on the scale
	right_sat_2.add_mark(0, Gtk::PositionType::TOP, "0%");
	right_sat_2.add_mark(16384, Gtk::PositionType::TOP, "25%");
	right_sat_2.add_mark(32768, Gtk::PositionType::TOP, "50%");
	right_sat_2.add_mark(49172, Gtk::PositionType::TOP, "75%");
	right_sat_2.add_mark(65535, Gtk::PositionType::TOP, "100%");
	right_sat_2.set_value(32768);
	right_sat_2.set_hexpand();
	right_sat_2.set_vexpand();

	center_0.set_range(-32767, 32767);
	center_0.set_digits(0); // Set number of digits after the decimal point
	center_0.set_draw_value(TRUE); // Display the value on the scale
	center_0.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	center_0.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	center_0.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	center_0.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	center_0.add_mark(0, Gtk::PositionType::TOP, "0%");
	center_0.add_mark(9000, Gtk::PositionType::TOP, "25%");
	center_0.add_mark(18000, Gtk::PositionType::TOP, "50%");
	center_0.add_mark(27000, Gtk::PositionType::TOP, "75%");
	center_0.add_mark(32767, Gtk::PositionType::TOP, "100%");
	center_0.set_hexpand();
	center_0.set_vexpand();

	center_1.set_range(-32767, 32767);
	center_1.set_digits(0); // Set number of digits after the decimal point
	center_1.set_draw_value(TRUE); // Display the value on the scale
	center_1.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	center_1.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	center_1.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	center_1.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	center_1.add_mark(0, Gtk::PositionType::TOP, "0%");
	center_1.add_mark(9000, Gtk::PositionType::TOP, "25%");
	center_1.add_mark(18000, Gtk::PositionType::TOP, "50%");
	center_1.add_mark(27000, Gtk::PositionType::TOP, "75%");
	center_1.add_mark(32767, Gtk::PositionType::TOP, "100%");
	center_1.set_hexpand();
	center_1.set_vexpand();

	center_2.set_range(-32767, 32767);
	center_2.set_digits(0); // Set number of digits after the decimal point
	center_2.set_draw_value(TRUE); // Display the value on the scale
	center_2.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	center_2.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	center_2.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	center_2.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	center_2.add_mark(0, Gtk::PositionType::TOP, "0%");
	center_2.add_mark(9000, Gtk::PositionType::TOP, "25%");
	center_2.add_mark(18000, Gtk::PositionType::TOP, "50%");
	center_2.add_mark(27000, Gtk::PositionType::TOP, "75%");
	center_2.add_mark(32767, Gtk::PositionType::TOP, "100%");
	center_2.set_hexpand();
	center_2.set_vexpand();

	deadband_0.set_range(0, 65535);
	deadband_0.add_mark(0, Gtk::PositionType::TOP, "0");
	deadband_0.add_mark(1000, Gtk::PositionType::TOP, "1");
	deadband_0.add_mark(5000, Gtk::PositionType::TOP, "5");
	deadband_0.add_mark(10000, Gtk::PositionType::TOP, "10");
	deadband_0.add_mark(20000, Gtk::PositionType::TOP, "20");
	deadband_0.add_mark(30000, Gtk::PositionType::TOP, "30");
	deadband_0.add_mark(40000, Gtk::PositionType::TOP, "40");
	deadband_0.add_mark(50000, Gtk::PositionType::TOP, "50");
	deadband_0.add_mark(60000, Gtk::PositionType::TOP, "60");
	deadband_0.add_mark(65535, Gtk::PositionType::TOP, "Max");
	deadband_0.set_hexpand();
	deadband_0.set_vexpand();

	deadband_1.set_range(0, 65535);
	deadband_1.add_mark(0, Gtk::PositionType::TOP, "0");
	deadband_1.add_mark(1000, Gtk::PositionType::TOP, "1");
	deadband_1.add_mark(5000, Gtk::PositionType::TOP, "5");
	deadband_1.add_mark(10000, Gtk::PositionType::TOP, "10");
	deadband_1.add_mark(20000, Gtk::PositionType::TOP, "20");
	deadband_1.add_mark(30000, Gtk::PositionType::TOP, "30");
	deadband_1.add_mark(40000, Gtk::PositionType::TOP, "40");
	deadband_1.add_mark(50000, Gtk::PositionType::TOP, "50");
	deadband_1.add_mark(60000, Gtk::PositionType::TOP, "60");
	deadband_1.add_mark(65535, Gtk::PositionType::TOP, "Max");
	deadband_1.set_hexpand();
	deadband_1.set_vexpand();

	deadband_2.set_range(0, 65535);
	deadband_2.add_mark(0, Gtk::PositionType::TOP, "0");
	deadband_2.add_mark(1000, Gtk::PositionType::TOP, "1");
	deadband_2.add_mark(5000, Gtk::PositionType::TOP, "5");
	deadband_2.add_mark(10000, Gtk::PositionType::TOP, "10");
	deadband_2.add_mark(20000, Gtk::PositionType::TOP, "20");
	deadband_2.add_mark(30000, Gtk::PositionType::TOP, "30");
	deadband_2.add_mark(40000, Gtk::PositionType::TOP, "40");
	deadband_2.add_mark(50000, Gtk::PositionType::TOP, "50");
	deadband_2.add_mark(60000, Gtk::PositionType::TOP, "60");
	deadband_2.add_mark(65535, Gtk::PositionType::TOP, "Max");
	deadband_2.set_hexpand();
	deadband_2.set_vexpand();

	delay.set_range(0, 65535);
	delay.set_digits(0); // Set number of digits after the decimal point
	delay.set_draw_value(TRUE); // Display the value on the scale
	delay.add_mark(0, Gtk::PositionType::TOP, "0");
	delay.add_mark(1000, Gtk::PositionType::TOP, "1");
	delay.add_mark(2000, Gtk::PositionType::TOP, "2");
	delay.add_mark(3000, Gtk::PositionType::TOP, "3");
	delay.add_mark(4000, Gtk::PositionType::TOP, "4");
	delay.add_mark(5000, Gtk::PositionType::TOP, "5s");
	delay.add_mark(10000, Gtk::PositionType::TOP, "10s");
	delay.add_mark(20000, Gtk::PositionType::TOP, "20s");
	delay.add_mark(30000, Gtk::PositionType::TOP, "30s");
	delay.add_mark(40000, Gtk::PositionType::TOP, "40s");
	delay.add_mark(65535, Gtk::PositionType::TOP, "Maximum");
	delay.set_hexpand();
	delay.set_vexpand();

	period.set_range(0, 65535);
	period.set_digits(0); // Set number of digits after the decimal point
	period.set_draw_value(TRUE); // Display the value on the scale
	period.add_mark(0, Gtk::PositionType::TOP, "0");
	period.add_mark(10000, Gtk::PositionType::TOP, "10");
	period.add_mark(20000, Gtk::PositionType::TOP, "20");
	period.add_mark(30000, Gtk::PositionType::TOP, "30");
	period.add_mark(40000, Gtk::PositionType::TOP, "40");
	period.add_mark(50000, Gtk::PositionType::TOP, "50");
	period.add_mark(60000, Gtk::PositionType::TOP, "60");
	period.add_mark(65535, Gtk::PositionType::TOP, "Maximum");
	period.set_value(1500);
	period.set_hexpand();
	period.set_vexpand();

	phase.set_range(0, 63000);
	phase.set_digits(0); // Set number of digits after the decimal point
	phase.set_draw_value(TRUE); // Display the value on the scale
	phase.add_mark(0, Gtk::PositionType::TOP, "0%");
	phase.add_mark(9000, Gtk::PositionType::TOP, "25%");
	phase.add_mark(18000, Gtk::PositionType::TOP, "50%");
	phase.add_mark(27000, Gtk::PositionType::TOP, "75%");
	phase.add_mark(36000, Gtk::PositionType::TOP, "100%");
	phase.add_mark(45000, Gtk::PositionType::TOP, "125%");
	phase.add_mark(54000, Gtk::PositionType::TOP, "150%");
	phase.add_mark(63000, Gtk::PositionType::TOP, "175%");
	phase.set_value(18000);
	phase.set_hexpand();
	phase.set_vexpand();

	offset.set_range(-32767, 32767);
	offset.set_digits(0); // Set number of digits after the decimal point
	offset.set_draw_value(TRUE); // Display the value on the scale
	offset.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	offset.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	offset.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	offset.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	offset.add_mark(0, Gtk::PositionType::TOP, "0%");
	offset.add_mark(9000, Gtk::PositionType::TOP, "25%");
	offset.add_mark(18000, Gtk::PositionType::TOP, "50%");
	offset.add_mark(27000, Gtk::PositionType::TOP, "75%");
	offset.add_mark(32767, Gtk::PositionType::TOP, "100%");
	offset.set_hexpand();
	offset.set_vexpand();

	magnitude.set_range(-32767, 32767);
	magnitude.set_digits(0); // Set number of digits after the decimal point
	magnitude.set_draw_value(TRUE); // Display the value on the scale
	magnitude.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	magnitude.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	magnitude.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	magnitude.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	magnitude.add_mark(0, Gtk::PositionType::TOP, "0%");
	magnitude.add_mark(9000, Gtk::PositionType::TOP, "25%");
	magnitude.add_mark(18000, Gtk::PositionType::TOP, "50%");
	magnitude.add_mark(27000, Gtk::PositionType::TOP, "75%");
	magnitude.add_mark(32767, Gtk::PositionType::TOP, "100%");
	magnitude.set_value(32767);
	magnitude.set_hexpand();
	magnitude.set_vexpand();

	large_magnitude.set_range(-32767, 32767);
	large_magnitude.set_digits(0); // Set number of digits after the decimal point
	large_magnitude.set_draw_value(TRUE); // Display the value on the scale
	large_magnitude.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	large_magnitude.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	large_magnitude.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	large_magnitude.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	large_magnitude.add_mark(0, Gtk::PositionType::TOP, "0%");
	large_magnitude.add_mark(9000, Gtk::PositionType::TOP, "25%");
	large_magnitude.add_mark(18000, Gtk::PositionType::TOP, "50%");
	large_magnitude.add_mark(27000, Gtk::PositionType::TOP, "75%");
	large_magnitude.add_mark(32767, Gtk::PositionType::TOP, "100%");
	large_magnitude.set_hexpand();
	large_magnitude.set_vexpand();

	small_magnitude.set_range(-32767, 32767);
	small_magnitude.set_digits(0); // Set number of digits after the decimal point
	small_magnitude.set_draw_value(TRUE); // Display the value on the scale
	small_magnitude.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	small_magnitude.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	small_magnitude.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	small_magnitude.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	small_magnitude.add_mark(0, Gtk::PositionType::TOP, "0%");
	small_magnitude.add_mark(9000, Gtk::PositionType::TOP, "25%");
	small_magnitude.add_mark(18000, Gtk::PositionType::TOP, "50%");
	small_magnitude.add_mark(27000, Gtk::PositionType::TOP, "75%");
	small_magnitude.add_mark(32767, Gtk::PositionType::TOP, "100%");
	small_magnitude.set_hexpand();
	small_magnitude.set_vexpand();

	level.set_range(-32767, 32767);
	level.set_digits(0); // Set number of digits after the decimal point
	level.set_draw_value(TRUE); // Display the value on the scale
	level.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	level.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	level.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	level.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	level.add_mark(0, Gtk::PositionType::TOP, "0%");
	level.add_mark(9000, Gtk::PositionType::TOP, "25%");
	level.add_mark(18000, Gtk::PositionType::TOP, "50%");
	level.add_mark(27000, Gtk::PositionType::TOP, "75%");
	level.add_mark(32767, Gtk::PositionType::TOP, "100%");
	level.set_hexpand();
	level.set_vexpand();

	start_strength.set_range(-32767, 32767);
	start_strength.set_digits(0); // Set number of digits after the decimal point
	start_strength.set_draw_value(TRUE); // Display the value on the scale
	start_strength.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	start_strength.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	start_strength.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	start_strength.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	start_strength.add_mark(0, Gtk::PositionType::TOP, "0%");
	start_strength.add_mark(9000, Gtk::PositionType::TOP, "25%");
	start_strength.add_mark(18000, Gtk::PositionType::TOP, "50%");
	start_strength.add_mark(27000, Gtk::PositionType::TOP, "75%");
	start_strength.add_mark(32767, Gtk::PositionType::TOP, "100%");
	start_strength.set_hexpand();
	start_strength.set_vexpand();

	end_strength.set_range(-32767, 32767);
	end_strength.set_digits(0); // Set number of digits after the decimal point
	end_strength.set_draw_value(TRUE); // Display the value on the scale
	end_strength.add_mark(-32768, Gtk::PositionType::TOP, "-100%");
	end_strength.add_mark(-27000, Gtk::PositionType::TOP, "-75%");
	end_strength.add_mark(-18000, Gtk::PositionType::TOP, "-50%");
	end_strength.add_mark(-9000, Gtk::PositionType::TOP, "-25%");
	end_strength.add_mark(0, Gtk::PositionType::TOP, "0%");
	end_strength.add_mark(9000, Gtk::PositionType::TOP, "25%");
	end_strength.add_mark(18000, Gtk::PositionType::TOP, "50%");
	end_strength.add_mark(27000, Gtk::PositionType::TOP, "75%");
	end_strength.add_mark(32767, Gtk::PositionType::TOP, "100%");
	end_strength.set_hexpand();
	end_strength.set_vexpand();

	length.set_range(0, 120000);
	length.add_mark(0, Gtk::PositionType::TOP, "0");
	length.add_mark(1000, Gtk::PositionType::TOP, "1");
	length.add_mark(5000, Gtk::PositionType::TOP, "5");
	length.add_mark(10000, Gtk::PositionType::TOP, "10");
	length.add_mark(20000, Gtk::PositionType::TOP, "20");
	length.add_mark(30000, Gtk::PositionType::TOP, "30");
	length.add_mark(60000, Gtk::PositionType::TOP, "60");
	length.add_mark(120000, Gtk::PositionType::TOP, "2 Mins");
	length.set_value(3000);
	length.set_hexpand();
	length.set_vexpand();

	attack.set_range(0, 65535);
	attack.add_mark(0, Gtk::PositionType::TOP, "0");
	attack.add_mark(1000, Gtk::PositionType::TOP, "1");
	attack.add_mark(5000, Gtk::PositionType::TOP, "5");
	attack.add_mark(10000, Gtk::PositionType::TOP, "10");
	attack.add_mark(20000, Gtk::PositionType::TOP, "20");
	attack.add_mark(30000, Gtk::PositionType::TOP, "30");
	attack.add_mark(40000, Gtk::PositionType::TOP, "40");
	attack.add_mark(50000, Gtk::PositionType::TOP, "50");
	attack.add_mark(60000, Gtk::PositionType::TOP, "60");
	attack.add_mark(65535, Gtk::PositionType::TOP, "Max");
	attack.set_value(125);
	attack.set_hexpand();
	attack.set_vexpand();

	attack_lvl.set_range(0, 65535);
	attack_lvl.add_mark(0, Gtk::PositionType::TOP, "0%");
	attack_lvl.add_mark(16384, Gtk::PositionType::TOP, "25%");
	attack_lvl.add_mark(32768, Gtk::PositionType::TOP, "50%");
	attack_lvl.add_mark(49152, Gtk::PositionType::TOP, "75%");
	attack_lvl.add_mark(65535, Gtk::PositionType::TOP, "100%");
	attack_lvl.set_hexpand();
	attack_lvl.set_vexpand();

	fade.set_range(0, 65535);
	fade.add_mark(0, Gtk::PositionType::TOP, "0");
	fade.add_mark(1000, Gtk::PositionType::TOP, "1");
	fade.add_mark(5000, Gtk::PositionType::TOP, "5");
	fade.add_mark(10000, Gtk::PositionType::TOP, "10");
	fade.add_mark(20000, Gtk::PositionType::TOP, "20");
	fade.add_mark(30000, Gtk::PositionType::TOP, "30");
	fade.add_mark(40000, Gtk::PositionType::TOP, "40");
	fade.add_mark(50000, Gtk::PositionType::TOP, "50");
	fade.add_mark(60000, Gtk::PositionType::TOP, "60");
	fade.add_mark(65535, Gtk::PositionType::TOP, "MAX");
	fade.set_value(250);
	fade.set_hexpand();
	fade.set_vexpand();

	fade_lvl.set_range(0, 65535);
	fade_lvl.add_mark(0, Gtk::PositionType::TOP, "0%");
	fade_lvl.add_mark(16384, Gtk::PositionType::TOP, "25%");
	fade_lvl.add_mark(32768, Gtk::PositionType::TOP, "50%");
	fade_lvl.add_mark(49152, Gtk::PositionType::TOP, "75%");
	fade_lvl.add_mark(65535, Gtk::PositionType::TOP, "100%");
	fade_lvl.set_hexpand();
	fade_lvl.set_vexpand();

	save_profile_button.set_label("Save Profile");
	set_effect_label.set_label("Pick an effect to Create:");
	periodic_button.set_label("Periodic");
	ramp_button.set_label("Ramp");
	leftright_button.set_label("Left-Right");
	constant_button.set_label("Constant");
	condition_button.set_label("Condition");
	custom_button.set_label("Custom");
	ramp_button.set_label("Ramp");
	test_effect_button.set_label("Test Effect");
	create_new_button.set_label("Create New Profile");
	open_profile_button.set_label("Open Profile");
	quit_button.set_label("Quit");
	set_title("Force Feedback Designer");

	//set widget layout properties
	create_new_button.set_hexpand();
	create_new_button.set_vexpand();
	open_profile_button.set_hexpand();
	open_profile_button.set_vexpand();
	quit_button.set_hexpand();
	quit_button.set_vexpand();
	pane.set_hexpand();
	pane.set_vexpand();
	launch_grid.set_hexpand();
	launch_grid.set_vexpand();
	effect_select_grid.set_hexpand();
	effect_select_grid.set_vexpand();
	effect_create_grid.set_hexpand();
	effect_create_grid.set_vexpand();
	launch_grid.set_orientation(Gtk::Orientation::VERTICAL);
	//disable save button at launch
	save_profile_button.set_sensitive(false);
	// Add button click event handlers
	open_profile_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_open_profile_button_clicked));
	quit_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_quit_button_clicked));
	save_profile_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_save_profile_button_clicked));
	periodic_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_periodic_button_clicked));
	ramp_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_ramp_button_clicked));
	leftright_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_leftright_button_clicked));
	condition_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_condition_button_clicked));
	constant_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_constant_button_clicked));
	custom_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_custom_button_clicked));
	test_effect_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_test_effect_button_clicked));
	// Create Add widgets to the window
	set_child(pane);
	open_profile_button.set_vexpand(FALSE);
	quit_button.set_vexpand(FALSE);
	// Add widgets to the second grid
	effect_select_grid.attach(open_profile_button,0,0,1,1);
	effect_select_grid.attach(save_profile_button,0,1,1,1);
	effect_select_grid.attach(set_effect_label,0,2,1,1);
	effect_select_grid.attach(periodic_button,0,3,1,1);
	effect_select_grid.attach(ramp_button,0,4,1,1);
	effect_select_grid.attach(leftright_button,0,5,1,1);
	effect_select_grid.attach(condition_button,0,6,1,1);
	effect_select_grid.attach(custom_button,0,7,1,1);
	effect_select_grid.attach(constant_button,0,8,1,1);
	effect_select_grid.attach(quit_button,0,9,1,1);
	pane.set_start_child(effect_select_grid);
	pane.set_end_child(effect_create_grid);
}

void FFDWindow::start_sdl()
{
	init_sdl();
}

void FFDWindow::update_settings()
{
	this->name_entry.set_text(this->effect.get_effect_name());
	this->length.set_value(this->effect.get_length());
	this->delay.set_value(this->effect.get_delay());
	//this->effect.set_button();
	//this->effect.set_interval();
	this->right_sat_0.set_value(this->effect.get_right_sat_0());
	this->right_sat_1.set_value(this->effect.get_right_sat_1());
	this->right_sat_2.set_value(this->effect.get_right_sat_2());
	this->left_sat_0.set_value(this->effect.get_left_sat_0());
	this->left_sat_1.set_value(this->effect.get_left_sat_1());
	this->left_sat_2.set_value(this->effect.get_left_sat_2());
	this->right_coeff_0.set_value(this->effect.get_right_coeff_0());
	this->right_coeff_1.set_value(this->effect.get_right_coeff_1());
	this->right_coeff_2.set_value(this->effect.get_right_coeff_2());
	this->left_coeff_0.set_value(this->effect.get_left_coeff_0());
	this->left_coeff_1.set_value(this->effect.get_left_coeff_1());
	this->left_coeff_2.set_value(this->effect.get_left_coeff_2());
	this->deadband_0.set_value(this->effect.get_deadband_0());
	this->deadband_1.set_value(this->effect.get_deadband_1());
	this->deadband_2.set_value(this->effect.get_deadband_2());
	this->center_0.set_value(this->effect.get_center_0());
	this->center_1.set_value(this->effect.get_center_1());
	this->center_2.set_value(this->effect.get_center_2());
	this->direction_type.set_active(this->effect.get_direction_type());
	this->direction_0.set_value(this->effect.get_direction_0());
	this->direction_1.set_value(this->effect.get_direction_1());
	this->period.set_value(this->effect.get_period());
	//this->effect.get_samples();
	this->magnitude.set_value(this->effect.get_magnitude());
	this->large_magnitude.set_value(this->effect.get_large_magnitude());
	this->small_magnitude.set_value(this->effect.get_small_magnitude());
	this->offset.set_value(this->effect.get_offset());
	this->phase.set_value(this->effect.get_phase());
	this->attack.set_value(this->effect.get_attack_length());
	this->attack_lvl.set_value(this->effect.get_attack_level());
	this->fade.set_value(this->effect.get_fade_length());
	this->fade_lvl.set_value(this->effect.get_fade_level());
	int type_set = 0;
	type_set = this->effect.get_type();
	switch (type_set)
	{
		case 0:
		{
		on_condition_button_clicked();
		break;
		}
		case 1:
		{
		on_constant_button_clicked();
		break;
		}
		case 2:
		{
		on_leftright_button_clicked();
		break;
		}
		case 3:
		{
		on_periodic_button_clicked();
		break;
		}
		case 4:
		{
		on_ramp_button_clicked();
		break;
		}
		case 5:
		{
		on_custom_button_clicked();
		break;
		}
	}
}

void FFDWindow::update_variables()
{
	this->effect.set_effect_name(string(name_entry.get_text()));
	this->effect.set_length(int(length.get_value()));
	this->effect.set_delay(int(delay.get_value()));
	//this->effect.set_button();
	//this->effect.set_interval();
	this->effect.set_right_sat_0(int(right_sat_0.get_value()));
	this->effect.set_right_sat_1(int(right_sat_1.get_value()));
	this->effect.set_right_sat_2(int(right_sat_2.get_value()));
	this->effect.set_left_sat_0(int(left_sat_0.get_value()));
	this->effect.set_left_sat_1(int(left_sat_1.get_value()));
	this->effect.set_left_sat_2(int(left_sat_2.get_value()));
	this->effect.set_right_coeff_0(int(right_coeff_0.get_value()));
	this->effect.set_right_coeff_1(int(right_coeff_1.get_value()));
	this->effect.set_right_coeff_2(int(right_coeff_2.get_value()));
	this->effect.set_left_coeff_0(int(left_coeff_0.get_value()));
	this->effect.set_left_coeff_1(int(left_coeff_1.get_value()));
	this->effect.set_left_coeff_2(int(left_coeff_2.get_value()));
	this->effect.set_deadband_0(int(deadband_0.get_value()));
	this->effect.set_deadband_1(int(deadband_1.get_value()));
	this->effect.set_deadband_2(int(deadband_2.get_value()));
	this->effect.set_center_0(int(center_0.get_value()));
	this->effect.set_center_1(int(center_1.get_value()));
	this->effect.set_center_2(int(center_2.get_value()));
	this->effect.set_direction_type(int(direction_type.get_active_row_number()));
	this->effect.set_direction_0(int(direction_0.get_value()));
	this->effect.set_direction_1(int(direction_1.get_value()));
	this->effect.set_period(int(period.get_value()));
	//this->effect.set_samples();
	this->effect.set_magnitude(int(magnitude.get_value()));
	this->effect.set_large_magnitude(int(large_magnitude.get_value()));
	this->effect.set_small_magnitude(int(small_magnitude.get_value()));
	this->effect.set_offset(int(offset.get_value()));
	this->effect.set_phase(int(phase.get_value()));
	this->effect.set_attack_length(int(attack.get_value()));
	this->effect.set_attack_level(int(attack_lvl.get_value()));
	this->effect.set_fade_length(int(fade.get_value()));
	this->effect.set_fade_level(int(fade_lvl.get_value()));
}

void FFDWindow::on_file_open_response(int response_id, Gtk::FileChooserDialog* dialog) 
{
     //Handle the response:
  switch (response_id)
  {
    case Gtk::ResponseType::OK:
    {
	cout << "Open clicked." << endl;
        auto filename = dialog->get_file()->get_path();
	cout << "Opening for reading: " << filename << endl;
	ifstream infile(filename);
                if (!infile.is_open()) {
                std::cerr << "Error opening file for reading!" << std::endl;
        }
	string ffb_effect_name;
	int ffb_type = 0;
	int ffb_length = 0;
	int ffb_delay = 0;
	int ffb_right_sat_0 = 0;
	int ffb_right_sat_1 = 0;
	int ffb_right_sat_2 = 0;
	int ffb_left_sat_0 = 0;
	int ffb_left_sat_1 = 0;
	int ffb_left_sat_2 = 0;
	int ffb_right_coeff_0 = 0;
	int ffb_right_coeff_1 = 0;
	int ffb_right_coeff_2 = 0;
	int ffb_left_coeff_0 = 0;
	int ffb_left_coeff_1 = 0;
	int ffb_left_coeff_2 = 0;
	int ffb_deadband_0 = 0;
	int ffb_deadband_1 = 0;
	int ffb_deadband_2 = 0;
	int ffb_center_0 = 0;
	int ffb_center_1 = 0;
	int ffb_center_2 = 0;
	int ffb_direction_type = 0;
	int ffb_direction_0 = 0;
	int ffb_direction_1 = 0;
	int ffb_period = 0;
        int ffb_samples = 0;
	int ffb_magnitude = 0;
	int ffb_large_magnitude = 0;
	int ffb_small_magnitude = 0;
	int ffb_offset = 0;
	int ffb_phase = 0;
	int ffb_attack_length = 0;
	int ffb_attack_level = 0;
	int ffb_fade_length = 0;
	int ffb_fade_level = 0;
        getline(infile, ffb_effect_name);
        infile >> ffb_type;
        infile >> ffb_length;
        infile >> ffb_delay;
        infile >> ffb_right_sat_0;
        infile >> ffb_right_sat_1;
        //infile >> ffb_button(;
	//infile >> this->effect.set_button(ffb_button);
        //int ffb_button = 0;
	//int ffb_interval = 0;
	//infile >>ffb_interval;
        //getline(infile, this->effect.set_interval(ffb_interval);
        infile >> ffb_right_sat_2;
        infile >> ffb_left_sat_0;
        infile >> ffb_left_sat_1;
        infile >> ffb_left_sat_2;
        infile >> ffb_right_coeff_0;
        infile >> ffb_right_coeff_1;
        infile >> ffb_right_coeff_2;
        infile >> ffb_large_magnitude;
        infile >> ffb_left_coeff_0;
        infile >> ffb_left_coeff_1;
        infile >> ffb_left_coeff_2;
        infile >> ffb_deadband_0;
        infile >> ffb_deadband_1;
        infile >> ffb_deadband_2;
        infile >> ffb_center_0;
        infile >> ffb_center_1;
        infile >> ffb_center_2;
        infile >> ffb_direction_type;
        infile >> ffb_direction_0;
        infile >> ffb_direction_1;
        infile >> ffb_period;
        infile >> ffb_magnitude;
        infile >> ffb_small_magnitude;
        infile >> ffb_offset;
        infile >> ffb_phase;
        infile >> ffb_attack_length;
        infile >> ffb_attack_level;
        infile >> ffb_fade_length;
        infile >> ffb_fade_level;
        this->effect.set_effect_name(ffb_effect_name);
        this->effect.set_type(ffb_type);
        this->effect.set_length(ffb_length);
        this->effect.set_delay(ffb_delay);
        this->effect.set_right_sat_0(ffb_right_sat_0);
        this->effect.set_right_sat_1(ffb_right_sat_1);
        this->effect.set_right_sat_2(ffb_right_sat_2);
        this->effect.set_left_sat_0(ffb_left_sat_0);
        this->effect.set_left_sat_1(ffb_left_sat_1);
        this->effect.set_left_sat_2(ffb_left_sat_2);
        this->effect.set_right_coeff_0(ffb_right_coeff_0);
        this->effect.set_right_coeff_1(ffb_right_coeff_1);
        this->effect.set_right_coeff_2(ffb_right_coeff_2);
        this->effect.set_left_coeff_0(ffb_left_coeff_0);
        this->effect.set_left_coeff_1(ffb_left_coeff_1);
	this->effect.set_left_coeff_2(ffb_left_coeff_2);
        this->effect.set_deadband_0(ffb_deadband_0);
        this->effect.set_deadband_1(ffb_deadband_1);
        this->effect.set_deadband_2(ffb_deadband_2);
        this->effect.set_center_0(ffb_center_0);
        this->effect.set_center_1(ffb_center_1);
        this->effect.set_center_2(ffb_center_2);
        this->effect.set_direction_type(ffb_direction_type);
        this->effect.set_direction_0(ffb_direction_0);
        this->effect.set_direction_1(ffb_direction_1);
        this->effect.set_period(ffb_period);
        //getline(infile,ffb_samples;
        //getline(infile, this->effect.set_samples(ffb_samples;
        this->effect.set_magnitude(ffb_magnitude);
        this->effect.set_large_magnitude(ffb_large_magnitude);
        this->effect.set_small_magnitude(ffb_small_magnitude);
        this->effect.set_offset(ffb_offset);
        this->effect.set_phase(ffb_phase);
        this->effect.set_attack_length(ffb_attack_length);
        this->effect.set_attack_level(ffb_attack_level);
        this->effect.set_fade_length(ffb_fade_length);
        this->effect.set_fade_level(ffb_fade_level);
	infile.close();
	update_settings();
        break;
    }
    case Gtk::ResponseType::CANCEL:
    {
      cout << "Cancel clicked." << endl;
      break;
    }
    default:
    {
      cout << "Unexpected button clicked." << endl;
      break;
    }
  }
  delete dialog;
}

void FFDWindow::on_open_profile_button_clicked() 
{
	auto open_dialog = new Gtk::FileChooserDialog("Please choose a file", Gtk::FileChooser::Action::OPEN);
	open_dialog->set_transient_for(*this);
	open_dialog->set_select_multiple(false);
	open_dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	open_dialog->add_button("_Open", Gtk::ResponseType::OK);
	auto filter_ffp = Gtk::FileFilter::create();
	filter_ffp->set_name("FFP Files");
	filter_ffp->add_pattern("*.ffp");
	open_dialog->add_filter(filter_ffp);
    	open_dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &FFDWindow::on_file_open_response), open_dialog));
	open_dialog->show();

/*		int result = open_dialog.run();
		if (result == Gtk::ResponseType::OK) 
{
				string filename = open_dialog.get_file();
				open_from_file(filename);
		}*/
}

void FFDWindow::on_quit_button_clicked() 
{
	this->close();
}

void FFDWindow::on_file_save_response(int response_id, Gtk::FileChooserDialog* dialog)
{
     //Handle the response:
  switch (response_id)
  {
    case Gtk::ResponseType::OK:
    {
      cout << "Save clicked." << endl;
      //Notice that this is a string, not a Glib::ustring.
      auto filename = dialog->get_file()->get_path();
      cout << "File selected: " <<  filename << endl;
		ofstream outfile(filename);
		if (!outfile.is_open()) {
        	std::cerr << "Error opening file for writing!" << std::endl;
    	}
	update_variables();
	outfile << this->effect.get_effect_name() << endl;
	cout << "Effect Type: " << this->effect.get_type() << endl;
	outfile << this->effect.get_type() << endl;
	outfile << this->effect.get_length() << endl;
	outfile << this->effect.get_delay() << endl;
	//outfile << this->effect.get_button();
	//outfile << this->effect.get_interval();
	outfile << this->effect.get_right_sat_0() << endl;
	outfile << this->effect.get_right_sat_1() << endl;
	outfile << this->effect.get_right_sat_2() << endl;
	outfile << this->effect.get_left_sat_0() << endl;
	outfile << this->effect.get_left_sat_1() << endl;
	outfile << this->effect.get_left_sat_2() << endl;
	outfile << this->effect.get_right_coeff_0() << endl;
	outfile << this->effect.get_right_coeff_1() << endl;
	outfile << this->effect.get_right_coeff_2() << endl;
	outfile << this->effect.get_left_coeff_0() << endl;
	outfile << this->effect.get_left_coeff_1() << endl;
	outfile << this->effect.get_left_coeff_2() << endl;
	outfile << this->effect.get_deadband_0() << endl;
	outfile << this->effect.get_deadband_1() << endl;
	outfile << this->effect.get_deadband_2() << endl;
	outfile << this->effect.get_center_0() << endl;
	outfile << this->effect.get_center_1() << endl;
	outfile << this->effect.get_center_2() << endl;
	outfile << this->effect.get_direction_type() << endl;
	outfile << this->effect.get_direction_0() << endl;
	outfile << this->effect.get_direction_1() << endl;
	outfile << this->effect.get_period() << endl;
	//outfile << this->effect.get_samples();
	outfile << this->effect.get_magnitude() << endl;
	outfile << this->effect.get_large_magnitude() << endl;
	outfile << this->effect.get_small_magnitude() << endl;
	outfile << this->effect.get_offset() << endl;
	outfile << this->effect.get_phase() << endl;
	outfile << this->effect.get_attack_length() << endl;
	outfile << this->effect.get_attack_level() << endl;
	outfile << this->effect.get_fade_length() << endl;
	outfile << this->effect.get_fade_level() << endl;
	outfile.close();
      break;
    }
    case Gtk::ResponseType::CANCEL:
    {
      cout << "Cancel clicked." << endl;
      break;
    }
    default:
    {
      cout << "Unexpected button clicked." << endl;
      break;
    }
  }
  delete dialog;
}

void FFDWindow::on_save_profile_button_clicked() 
{
    auto save_dialog = new Gtk::FileChooserDialog("Please choose a file", Gtk::FileChooser::Action::SAVE);
    save_dialog->set_transient_for(*this);
	save_dialog->set_select_multiple(false);
	save_dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	save_dialog->add_button("Save", Gtk::ResponseType::OK);
	auto filter_ffp = Gtk::FileFilter::create();
	filter_ffp->set_name("FFP Files");
	filter_ffp->add_pattern("*.ffp");
	save_dialog->add_filter(filter_ffp);
    	save_dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &FFDWindow::on_file_save_response), save_dialog));
	save_dialog->show();
}


void FFDWindow::clean_effect_grid()
{
//	effect_create_grid.remove_column(3);
	effect_create_grid.remove_column(2);
	effect_create_grid.remove_column(1);
	effect_create_grid.remove_column(0);
	save_profile_button.set_sensitive(true);
    	set_default_size(1000, 400);
	this->chosen = 0;
}

void FFDWindow::align_all()
{
/*	for (auto& child : effect_create_grid.get_children()) 
{
		// Check if the child is a label
		if (auto label = dynamic_cast<Gtk::Label*>(&child)) 
{
			// Set horizontal alignment to start (left-justified)
			label->set_halign(Gtk::Align::END);
		}
	}*/
	effect_header_label.set_halign(Gtk::Align::CENTER);
}

void FFDWindow::on_periodic_button_clicked()
{
	clean_effect_grid();
	this->effect.set_type(3);
	effect_header_label.set_text("Periodic");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(effect_type_label,0,2,1,1);
	effect_create_grid.attach(effect_type,1,2,1,1);
	effect_create_grid.attach(dir_type_label,0,3,1,1);
	effect_create_grid.attach(direction_type,1,3,1,1);
	effect_create_grid.attach(dir_label,0,4,1,1);
	effect_create_grid.attach(direction_0,1,4,1,1);
	effect_create_grid.attach(period_label,0,5,1,1);
	effect_create_grid.attach(period,1,5,1,1);
	effect_create_grid.attach(magnitude_label,0,7,1,1);
	effect_create_grid.attach(magnitude,1,7,1,1);
	effect_create_grid.attach(phase_label,0,6,1,1);
	effect_create_grid.attach(phase,1,6,1,1);
	effect_create_grid.attach(length_label,0,8,1,1);
	effect_create_grid.attach(length,1,8,1,1);
	effect_create_grid.attach(attack_label,0,9,1,1);
	effect_create_grid.attach(attack,1,9,1,1);
	effect_create_grid.attach(fade_label,0,10,1,1);
	effect_create_grid.attach(fade,1,10,1,1);
	effect_create_grid.attach(test_effect_button,0,11,3,1);
	align_all();
	this->chosen = 1;
}

void FFDWindow::on_ramp_button_clicked() 
{
	clean_effect_grid();
	this->effect.set_type(4);
	effect_header_label.set_text("Ramp");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(dir_type_label,0,2,1,1);
	effect_create_grid.attach(direction_type,1,2,1,1);
	effect_create_grid.attach(dir_label,0,3,1,1);
	effect_create_grid.attach(direction_0,1,3,1,1);
	effect_create_grid.attach(length_label,0,4,1,1);
	effect_create_grid.attach(length,1,4,1,1);
	effect_create_grid.attach(delay_label,0,5,1,1);
	effect_create_grid.attach(delay,1,5,1,1);
	effect_create_grid.attach(start_strength_label,0,6,1,1);
	effect_create_grid.attach(start_strength,1,6,1,1);
	effect_create_grid.attach(end_strength_label,0,7,1,1);
	effect_create_grid.attach(end_strength,1,7,1,1);
	effect_create_grid.attach(attack_lvl_label,0,8,1,1);
	effect_create_grid.attach(attack_lvl,1,8,1,1);
	effect_create_grid.attach(fade_label,0,9,1,1);
	effect_create_grid.attach(fade,1,9,1,1);
	effect_create_grid.attach(fade_lvl_label,0,10,1,1);
	effect_create_grid.attach(fade_lvl,1,10,1,1);
	effect_create_grid.attach(test_effect_button,0,11,3,1);
		align_all();
	this->chosen == 1;
}

void FFDWindow::on_leftright_button_clicked()
{
	clean_effect_grid();
	this->effect.set_type(2);
	effect_header_label.set_text("Left Right");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(length_label,0,2,1,1);
	effect_create_grid.attach(length,1,2,1,1);
	effect_create_grid.attach(large_magnitude_label,0,3,1,1);
	effect_create_grid.attach(large_magnitude,1,3,1,1);
	effect_create_grid.attach(small_magnitude_label,0,4,1,1);
	effect_create_grid.attach(small_magnitude,1,4,1,1);
	effect_create_grid.attach(test_effect_button,0,5,3,1);
		align_all();
	this->chosen == 1;
}

void FFDWindow::on_condition_button_clicked()
{
	clean_effect_grid();
	this->effect.set_type(0);
	effect_header_label.set_text("Condition");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(condition_type_label,0,2,1,1);
	effect_create_grid.attach(condition_type,1,2,1,1);
	effect_create_grid.attach(length_label,0,3,1,1);
	effect_create_grid.attach(length,1,3,1,1);
	effect_create_grid.attach(delay_label,0,4,1,1);
	effect_create_grid.attach(delay,1,4,1,1);
	effect_create_grid.attach(right_sat_label,0,5,1,1);
	effect_create_grid.attach(right_sat_0,1,5,1,1);
	effect_create_grid.attach(left_sat_label,0,6,1,1);
	effect_create_grid.attach(left_sat_0,1,6,1,1);
	effect_create_grid.attach(right_coeff_label,0,7,1,1);
	effect_create_grid.attach(right_coeff_0,1,7,1,1);
	effect_create_grid.attach(left_coeff_label,0,8,1,1);
	effect_create_grid.attach(left_coeff_0,1,8,1,1);
	effect_create_grid.attach(deadband_label,0,9,1,1);
	effect_create_grid.attach(deadband_0,1,9,1,1);
	effect_create_grid.attach(center_label,0,10,1,1);
	effect_create_grid.attach(center_0,1,10,1,1);
	effect_create_grid.attach(test_effect_button,0,11,3,1);
		align_all();
	this->chosen == 1;
}

void FFDWindow::on_constant_button_clicked()
{
	clean_effect_grid();
	this->effect.set_type(1);
	effect_header_label.set_text("Constant");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(dir_label,0,2,1,1);
	effect_create_grid.attach(direction_0,1,2,1,1);
	effect_create_grid.attach(length_label,0,3,1,1);
	effect_create_grid.attach(length,1,3,1,1);
	effect_create_grid.attach(delay_label,0,4,1,1);
	effect_create_grid.attach(delay,1,4,1,1);
	effect_create_grid.attach(level_label,0,5,1,1);
	effect_create_grid.attach(level,1,5,1,1);
	effect_create_grid.attach(attack_label,0,6,1,1);
	effect_create_grid.attach(attack,1,6,1,1);
	effect_create_grid.attach(attack_lvl_label,0,7,1,1);
	effect_create_grid.attach(attack_lvl,1,7,1,1);
	effect_create_grid.attach(fade_label,0,8,1,1);
	effect_create_grid.attach(fade,1,8,1,1);
	effect_create_grid.attach(fade_lvl_label,0,9,1,1);
	effect_create_grid.attach(fade_lvl,1,9,1,1);
	effect_create_grid.attach(test_effect_button,0,10,2,1);
		align_all();
	this->chosen == 1;
}

void FFDWindow::on_custom_button_clicked() 
{
	clean_effect_grid();
	this->effect.set_type(5);
	effect_header_label.set_text("Custom");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(length_label,0,2,1,1);
	effect_create_grid.attach(length,1,2,1,1);
	effect_create_grid.attach(delay_label,0,3,1,1);
	effect_create_grid.attach(delay,1,3,1,1);
	effect_create_grid.attach(attack_label,0,4,1,1);
	effect_create_grid.attach(attack,1,4,1,1);
	effect_create_grid.attach(attack_lvl_label,0,5,1,1);
	effect_create_grid.attach(attack_lvl,1,5,1,1);
	effect_create_grid.attach(test_effect_button,0,6,2,1);
		align_all();
	this->chosen == 1;
}

void FFDWindow::joinThread() 
{
	if (sdlThread.joinable()) 
	{
		sdlThread.join();
	}
}

void FFDWindow::on_test_effect_button_clicked() 
{
	cout << "Collecting Variables" << endl;
	string name = effect_header_label.get_text();
	short unsigned int type_var = 0;
		if (name == "Condition"){ type_var = 0; }
		if (name == "Constant"){ type_var = 1; }
		if (name == "Left Right"){ type_var = 2; }
		if (name == "Periodic"){ type_var = 3; }
		if (name == "Ramp"){ type_var = 4; }
		if (name == "Custom"){ type_var = 5; }
	cout << "type_var = " << type_var << endl;
	this->effect.set_type(type_var);
        switch (direction_type.get_active_row_number())
        {
                case 0:
                        this->effect.set_direction_type(SDL_HAPTIC_POLAR);
                break;
                case 1:
                        this->effect.set_direction_type(SDL_HAPTIC_CARTESIAN);
                break;
                case 2:
                        this->effect.set_direction_type(SDL_HAPTIC_SPHERICAL);
                break;
	}
	switch (effect_type.get_active_row_number())
	{
		case 0:
			this->effect.set_effect_type(SDL_HAPTIC_LEFTRIGHT);
		break;
		case 1:
			this->effect.set_effect_type(SDL_HAPTIC_SAWTOOTHUP);
		break;
		case 2:
			this->effect.set_effect_type(SDL_HAPTIC_SAWTOOTHDOWN);
		break;
		case 3:
			this->effect.set_effect_type(SDL_HAPTIC_SINE);
		break;
		case 4:
			this->effect.set_effect_type(SDL_HAPTIC_TRIANGLE);
		break;
	}
	switch (condition_type.get_active_row_number())
	{
		case 0:
			this->effect.set_condition_type(SDL_HAPTIC_SPRING);
		break;
		case 1:
			this->effect.set_condition_type(SDL_HAPTIC_DAMPER);
		break;
		case 2:
			this->effect.set_condition_type(SDL_HAPTIC_INERTIA);
		break;
		case 3:
			this->effect.set_condition_type(SDL_HAPTIC_FRICTION);
		break;
	}
	update_variables();
	cout << "Running Effect" << endl;
	/*Execute the Force Feedback Engine!*/
	open_joys(this->effect);
}

int main(int argc, char *argv[]) 
{
	auto app = Gtk::Application::create("org.Force_Feedback_Designer");
	FFDWindow window;
	window.start_sdl();
	return app->make_window_and_run<FFDWindow>(argc, argv);
}

