#include "ffd.h"
FFDWindow::FFDWindow() {
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
	right_sat_label.set_label("Right Level: ");
	right_coeff_label.set_label("Right Coefficient: ");
	left_coeff_label.set_label("Left Coefficient: ");
	deadband_label.set_label("Deadzone Size: ");
	center_label.set_label("Center of Deadzone: ");

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
	direction.set_range(0, 27000);
    	direction.set_digits(0); // Set number of digits after the decimal point
    	direction.set_draw_value(FALSE); // Display the value on the scale
    	// Add marks to the scale
    	direction.add_mark(0, Gtk::POS_TOP, "0");
    	direction.add_mark(9000, Gtk::POS_TOP, "90");
    	direction.add_mark(18000, Gtk::POS_TOP, "180");
    	direction.add_mark(27000, Gtk::POS_TOP, "270");
	direction.set_value(18000);
	direction.set_hexpand();

	left_coeff.set_range(-32767, 32767);
    	left_coeff.set_digits(0); // Set number of digits after the decimal point
    	left_coeff.set_draw_value(TRUE); // Display the value on the scale
    	left_coeff.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	left_coeff.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	left_coeff.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	left_coeff.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	left_coeff.add_mark(0, Gtk::POS_TOP, "0%");
    	left_coeff.add_mark(9000, Gtk::POS_TOP, "25%");
    	left_coeff.add_mark(18000, Gtk::POS_TOP, "50%");
    	left_coeff.add_mark(27000, Gtk::POS_TOP, "75%");
    	left_coeff.add_mark(32767, Gtk::POS_TOP, "100%");
	left_coeff.set_hexpand();

	right_coeff.set_range(-32767, 32767);
    	right_coeff.set_digits(0); // Set number of digits after the decimal point
    	right_coeff.set_draw_value(TRUE); // Display the value on the scale
    	right_coeff.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	right_coeff.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	right_coeff.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	right_coeff.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	right_coeff.add_mark(0, Gtk::POS_TOP, "0%");
    	right_coeff.add_mark(9000, Gtk::POS_TOP, "25%");
    	right_coeff.add_mark(18000, Gtk::POS_TOP, "50%");
    	right_coeff.add_mark(27000, Gtk::POS_TOP, "75%");
    	right_coeff.add_mark(32767, Gtk::POS_TOP, "100%");
	right_coeff.set_hexpand();

	left_sat.set_range(0, 65535);
    	left_sat.set_digits(0); // Set number of digits after the decimal point
    	left_sat.set_draw_value(TRUE); // Display the value on the scale
    	left_sat.add_mark(0, Gtk::POS_TOP, "0%");
    	left_sat.add_mark(16384, Gtk::POS_TOP, "25%");
    	left_sat.add_mark(32768, Gtk::POS_TOP, "50%");
    	left_sat.add_mark(49172, Gtk::POS_TOP, "75%");
    	left_sat.add_mark(65535, Gtk::POS_TOP, "100%");
	left_sat.set_value(32768);
	left_sat.set_hexpand();

	right_sat.set_range(0, 65535);
    	right_sat.set_digits(0); // Set number of digits after the decimal point
    	right_sat.set_draw_value(TRUE); // Display the value on the scale
    	right_sat.add_mark(0, Gtk::POS_TOP, "0%");
    	right_sat.add_mark(16384, Gtk::POS_TOP, "25%");
    	right_sat.add_mark(32768, Gtk::POS_TOP, "50%");
    	right_sat.add_mark(49172, Gtk::POS_TOP, "75%");
    	right_sat.add_mark(65535, Gtk::POS_TOP, "100%");
	right_sat.set_value(32768);
	right_sat.set_hexpand();

	center.set_range(-32767, 32767);
    	center.set_digits(0); // Set number of digits after the decimal point
    	center.set_draw_value(TRUE); // Display the value on the scale
    	center.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	center.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	center.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	center.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	center.add_mark(0, Gtk::POS_TOP, "0%");
    	center.add_mark(9000, Gtk::POS_TOP, "25%");
    	center.add_mark(18000, Gtk::POS_TOP, "50%");
    	center.add_mark(27000, Gtk::POS_TOP, "75%");
    	center.add_mark(32767, Gtk::POS_TOP, "100%");
	center.set_hexpand();

	delay.set_range(0, 65535);
    	delay.set_digits(0); // Set number of digits after the decimal point
    	delay.set_draw_value(TRUE); // Display the value on the scale
    	delay.add_mark(0, Gtk::POS_TOP, "0");
    	delay.add_mark(1000, Gtk::POS_TOP, "1");
    	delay.add_mark(2000, Gtk::POS_TOP, "2");
    	delay.add_mark(3000, Gtk::POS_TOP, "3");
    	delay.add_mark(4000, Gtk::POS_TOP, "4");
    	delay.add_mark(5000, Gtk::POS_TOP, "5s");
    	delay.add_mark(10000, Gtk::POS_TOP, "10s");
    	delay.add_mark(20000, Gtk::POS_TOP, "20s");
    	delay.add_mark(30000, Gtk::POS_TOP, "30s");
    	delay.add_mark(40000, Gtk::POS_TOP, "40s");
    	delay.add_mark(65535, Gtk::POS_TOP, "Maximum");
	delay.set_hexpand();

	period.set_range(0, 65535);
    	period.set_digits(0); // Set number of digits after the decimal point
    	period.set_draw_value(TRUE); // Display the value on the scale
    	period.add_mark(0, Gtk::POS_TOP, "0");
    	period.add_mark(10000, Gtk::POS_TOP, "10");
    	period.add_mark(20000, Gtk::POS_TOP, "20");
    	period.add_mark(30000, Gtk::POS_TOP, "30");
    	period.add_mark(40000, Gtk::POS_TOP, "40");
    	period.add_mark(50000, Gtk::POS_TOP, "50");
    	period.add_mark(60000, Gtk::POS_TOP, "60");
    	period.add_mark(65535, Gtk::POS_TOP, "Maximum");
	period.set_value(1500);
	period.set_hexpand();

	phase.set_range(0, 63000);
    	phase.set_digits(0); // Set number of digits after the decimal point
    	phase.set_draw_value(TRUE); // Display the value on the scale
    	phase.add_mark(0, Gtk::POS_TOP, "0%");
    	phase.add_mark(9000, Gtk::POS_TOP, "25%");
    	phase.add_mark(18000, Gtk::POS_TOP, "50%");
    	phase.add_mark(27000, Gtk::POS_TOP, "75%");
    	phase.add_mark(36000, Gtk::POS_TOP, "100%");
    	phase.add_mark(45000, Gtk::POS_TOP, "125%");
    	phase.add_mark(54000, Gtk::POS_TOP, "150%");
    	phase.add_mark(63000, Gtk::POS_TOP, "175%");
	phase.set_value(18000);
	phase.set_hexpand();

	offset.set_range(-32767, 32767);
    	offset.set_digits(0); // Set number of digits after the decimal point
    	offset.set_draw_value(TRUE); // Display the value on the scale
    	offset.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	offset.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	offset.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	offset.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	offset.add_mark(0, Gtk::POS_TOP, "0%");
    	offset.add_mark(9000, Gtk::POS_TOP, "25%");
    	offset.add_mark(18000, Gtk::POS_TOP, "50%");
    	offset.add_mark(27000, Gtk::POS_TOP, "75%");
    	offset.add_mark(32767, Gtk::POS_TOP, "100%");
	offset.set_hexpand();

	magnitude.set_range(-32767, 32767);
    	magnitude.set_digits(0); // Set number of digits after the decimal point
    	magnitude.set_draw_value(TRUE); // Display the value on the scale
    	magnitude.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	magnitude.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	magnitude.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	magnitude.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	magnitude.add_mark(0, Gtk::POS_TOP, "0%");
    	magnitude.add_mark(9000, Gtk::POS_TOP, "25%");
    	magnitude.add_mark(18000, Gtk::POS_TOP, "50%");
    	magnitude.add_mark(27000, Gtk::POS_TOP, "75%");
    	magnitude.add_mark(32767, Gtk::POS_TOP, "100%");
	magnitude.set_value(32767);
	magnitude.set_hexpand();

	large_magnitude.set_range(-32767, 32767);
    	large_magnitude.set_digits(0); // Set number of digits after the decimal point
    	large_magnitude.set_draw_value(TRUE); // Display the value on the scale
    	large_magnitude.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	large_magnitude.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	large_magnitude.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	large_magnitude.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	large_magnitude.add_mark(0, Gtk::POS_TOP, "0%");
    	large_magnitude.add_mark(9000, Gtk::POS_TOP, "25%");
    	large_magnitude.add_mark(18000, Gtk::POS_TOP, "50%");
    	large_magnitude.add_mark(27000, Gtk::POS_TOP, "75%");
    	large_magnitude.add_mark(32767, Gtk::POS_TOP, "100%");
	large_magnitude.set_hexpand();

	small_magnitude.set_range(-32767, 32767);
    	small_magnitude.set_digits(0); // Set number of digits after the decimal point
    	small_magnitude.set_draw_value(TRUE); // Display the value on the scale
    	small_magnitude.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	small_magnitude.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	small_magnitude.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	small_magnitude.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	small_magnitude.add_mark(0, Gtk::POS_TOP, "0%");
    	small_magnitude.add_mark(9000, Gtk::POS_TOP, "25%");
    	small_magnitude.add_mark(18000, Gtk::POS_TOP, "50%");
    	small_magnitude.add_mark(27000, Gtk::POS_TOP, "75%");
    	small_magnitude.add_mark(32767, Gtk::POS_TOP, "100%");
	small_magnitude.set_hexpand();

	level.set_range(-32767, 32767);
    	level.set_digits(0); // Set number of digits after the decimal point
    	level.set_draw_value(TRUE); // Display the value on the scale
    	level.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	level.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	level.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	level.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	level.add_mark(0, Gtk::POS_TOP, "0%");
    	level.add_mark(9000, Gtk::POS_TOP, "25%");
    	level.add_mark(18000, Gtk::POS_TOP, "50%");
    	level.add_mark(27000, Gtk::POS_TOP, "75%");
    	level.add_mark(32767, Gtk::POS_TOP, "100%");
	level.set_hexpand();

	start_strength.set_range(-32767, 32767);
    	start_strength.set_digits(0); // Set number of digits after the decimal point
    	start_strength.set_draw_value(TRUE); // Display the value on the scale
    	start_strength.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	start_strength.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	start_strength.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	start_strength.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	start_strength.add_mark(0, Gtk::POS_TOP, "0%");
    	start_strength.add_mark(9000, Gtk::POS_TOP, "25%");
    	start_strength.add_mark(18000, Gtk::POS_TOP, "50%");
    	start_strength.add_mark(27000, Gtk::POS_TOP, "75%");
    	start_strength.add_mark(32767, Gtk::POS_TOP, "100%");
	start_strength.set_hexpand();

	end_strength.set_range(-32767, 32767);
    	end_strength.set_digits(0); // Set number of digits after the decimal point
    	end_strength.set_draw_value(TRUE); // Display the value on the scale
    	end_strength.add_mark(-32768, Gtk::POS_TOP, "-100%");
    	end_strength.add_mark(-27000, Gtk::POS_TOP, "-75%");
    	end_strength.add_mark(-18000, Gtk::POS_TOP, "-50%");
    	end_strength.add_mark(-9000, Gtk::POS_TOP, "-25%");
    	end_strength.add_mark(0, Gtk::POS_TOP, "0%");
    	end_strength.add_mark(9000, Gtk::POS_TOP, "25%");
    	end_strength.add_mark(18000, Gtk::POS_TOP, "50%");
    	end_strength.add_mark(27000, Gtk::POS_TOP, "75%");
    	end_strength.add_mark(32767, Gtk::POS_TOP, "100%");
	end_strength.set_hexpand();

	length.set_range(0, 120000);
    	length.add_mark(0, Gtk::POS_TOP, "0");
    	length.add_mark(1000, Gtk::POS_TOP, "1");
    	length.add_mark(5000, Gtk::POS_TOP, "5");
    	length.add_mark(10000, Gtk::POS_TOP, "10");
    	length.add_mark(20000, Gtk::POS_TOP, "20");
    	length.add_mark(30000, Gtk::POS_TOP, "30");
    	length.add_mark(60000, Gtk::POS_TOP, "60");
    	length.add_mark(120000, Gtk::POS_TOP, "2 Mins");
	length.set_value(3000);
	length.set_hexpand();

	attack.set_range(0, 65535);
    	attack.add_mark(0, Gtk::POS_TOP, "0");
    	attack.add_mark(1000, Gtk::POS_TOP, "1");
    	attack.add_mark(5000, Gtk::POS_TOP, "5");
    	attack.add_mark(10000, Gtk::POS_TOP, "10");
    	attack.add_mark(20000, Gtk::POS_TOP, "20");
    	attack.add_mark(30000, Gtk::POS_TOP, "30");
    	attack.add_mark(40000, Gtk::POS_TOP, "40");
    	attack.add_mark(50000, Gtk::POS_TOP, "50");
    	attack.add_mark(60000, Gtk::POS_TOP, "60");
    	attack.add_mark(65535, Gtk::POS_TOP, "Max");
	attack.set_value(125);
	attack.set_hexpand();

	attack_lvl.set_range(0, 65535);
    	attack_lvl.add_mark(0, Gtk::POS_TOP, "0%");
    	attack_lvl.add_mark(16384, Gtk::POS_TOP, "25%");
    	attack_lvl.add_mark(32768, Gtk::POS_TOP, "50%");
    	attack_lvl.add_mark(49152, Gtk::POS_TOP, "75%");
    	attack_lvl.add_mark(65535, Gtk::POS_TOP, "100%");
	attack_lvl.set_hexpand();

	fade.set_range(0, 65535);
    	fade.add_mark(0, Gtk::POS_TOP, "0");
    	fade.add_mark(1000, Gtk::POS_TOP, "1");
    	fade.add_mark(5000, Gtk::POS_TOP, "5");
    	fade.add_mark(10000, Gtk::POS_TOP, "10");
    	fade.add_mark(20000, Gtk::POS_TOP, "20");
    	fade.add_mark(30000, Gtk::POS_TOP, "30");
    	fade.add_mark(40000, Gtk::POS_TOP, "40");
    	fade.add_mark(50000, Gtk::POS_TOP, "50");
    	fade.add_mark(60000, Gtk::POS_TOP, "60");
    	fade.add_mark(65535, Gtk::POS_TOP, "MAX");
	fade.set_value(125);
	fade.set_hexpand();

	fade_lvl.set_range(0, 65535);
    	fade_lvl.add_mark(0, Gtk::POS_TOP, "0%");
    	fade_lvl.add_mark(16384, Gtk::POS_TOP, "25%");
    	fade_lvl.add_mark(32768, Gtk::POS_TOP, "50%");
    	fade_lvl.add_mark(49152, Gtk::POS_TOP, "75%");
    	fade_lvl.add_mark(65535, Gtk::POS_TOP, "100%");
	fade_lvl.set_hexpand();

	deadband.set_range(0, 65535);
    	deadband.add_mark(0, Gtk::POS_TOP, "0");
    	deadband.add_mark(1000, Gtk::POS_TOP, "1");
    	deadband.add_mark(5000, Gtk::POS_TOP, "5");
    	deadband.add_mark(10000, Gtk::POS_TOP, "10");
    	deadband.add_mark(20000, Gtk::POS_TOP, "20");
    	deadband.add_mark(30000, Gtk::POS_TOP, "30");
    	deadband.add_mark(40000, Gtk::POS_TOP, "40");
    	deadband.add_mark(50000, Gtk::POS_TOP, "50");
    	deadband.add_mark(60000, Gtk::POS_TOP, "60");
    	deadband.add_mark(65535, Gtk::POS_TOP, "Max");
	deadband.set_hexpand();

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
	launch_grid.set_hexpand();
	launch_grid.set_vexpand();
	effect_select_grid.set_hexpand();
	effect_select_grid.set_vexpand();
	effect_create_grid.set_hexpand();
	effect_create_grid.set_vexpand();
	launch_grid.set_orientation(Gtk::ORIENTATION_VERTICAL);

	// Add widgets to the first grid
	launch_grid.add(create_new_button);
	launch_grid.add(open_profile_button);
	launch_grid.add(quit_button);
	// Add button click event handlers
	create_new_button.signal_clicked().connect(sigc::mem_fun(*this, &FFDWindow::on_create_button_clicked));
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

	// Add widgets to the window
	add(launch_grid);
        show_all_children();
}

void FFDWindow::on_create_button_clicked() {
        // Remove the first grid
		remove();
		launch_grid.remove(open_profile_button);
		launch_grid.remove(quit_button);
		add(pane);
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
		pane.pack1(effect_select_grid,true,false);
		pane.pack2(effect_create_grid,true,false);
        show_all_children();
}
void FFDWindow::on_open_profile_button_clicked() {
		cout << "open profile" << endl;
}

void FFDWindow::on_quit_button_clicked() {
		this->close();
}

void FFDWindow::on_save_profile_button_clicked() {
	cout << "Save Profile" << endl;
}

void FFDWindow::clean_effect_grid (){
	if (this->chosen == 1){
        	auto children = effect_create_grid.get_children();
        	for(auto& child : children) {
        	    effect_create_grid.remove(*child);
        	}
	}
	this->chosen = 0;
}

void FFDWindow::on_periodic_button_clicked() {
	clean_effect_grid();
	effect_header_label.set_text("Periodic");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(effect_type_label,0,2,1,1);
	effect_create_grid.attach(effect_type,1,2,1,1);
	effect_create_grid.attach(dir_type_label,0,3,1,1);
	effect_create_grid.attach(direction_type,1,3,1,1);
	effect_create_grid.attach(dir_label,0,4,1,1);
	effect_create_grid.attach(direction,1,4,4,1);
	effect_create_grid.attach(period_label,0,5,1,1);
	effect_create_grid.attach(period,1,5,4,1);
	effect_create_grid.attach(magnitude_label,0,7,1,1);
	effect_create_grid.attach(magnitude,1,7,1,1);
	effect_create_grid.attach(phase_label,0,6,1,1);
	effect_create_grid.attach(phase,1,6,4,1);
	effect_create_grid.attach(length_label,0,8,1,1);
	effect_create_grid.attach(length,1,8,1,1);
	effect_create_grid.attach(attack_label,0,9,1,1);
	effect_create_grid.attach(attack,1,9,1,1);
	effect_create_grid.attach(fade_label,0,10,1,1);
	effect_create_grid.attach(fade,1,10,1,1);
	effect_create_grid.attach(test_effect_button,0,11,3,1);
        this->show_all();
	this->chosen = 1;
}

void FFDWindow::on_ramp_button_clicked() {
	clean_effect_grid();
	effect_header_label.set_text("Ramp");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(effect_type_label,0,2,1,1);
	effect_create_grid.attach(effect_type,1,2,1,1);
	effect_create_grid.attach(dir_type_label,0,3,1,1);
	effect_create_grid.attach(direction_type,1,3,1,1);
	effect_create_grid.attach(dir_label,0,4,1,1);
	effect_create_grid.attach(direction,1,4,4,1);
	effect_create_grid.attach(length_label,0,5,1,1);
	effect_create_grid.attach(length,1,5,1,1);
	effect_create_grid.attach(delay_label,0,6,1,1);
	effect_create_grid.attach(delay,1,6,1,1);
	effect_create_grid.attach(start_strength_label,0,7,1,1);
	effect_create_grid.attach(start_strength,1,7,1,1);
	effect_create_grid.attach(end_strength_label,0,8,1,1);
	effect_create_grid.attach(end_strength,1,8,1,1);
	effect_create_grid.attach(attack_lvl_label,0,9,1,1);
	effect_create_grid.attach(attack_lvl,1,9,1,1);
	effect_create_grid.attach(fade_label,0,10,1,1);
	effect_create_grid.attach(fade,1,10,1,1);
	effect_create_grid.attach(fade_lvl_label,0,11,1,1);
	effect_create_grid.attach(fade_lvl,1,11,1,1);
	effect_create_grid.attach(test_effect_button,0,12,3,1);
        this->show_all();
	this->chosen == 1;
}

void FFDWindow::on_leftright_button_clicked() {
	clean_effect_grid();
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
        this->show_all();
	this->chosen == 1;
}

void FFDWindow::on_condition_button_clicked() {
	clean_effect_grid();
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
	effect_create_grid.attach(right_sat,1,5,1,1);
	effect_create_grid.attach(left_sat_label,0,6,1,1);
	effect_create_grid.attach(left_sat,1,6,1,1);
	effect_create_grid.attach(right_coeff_label,0,7,1,1);
	effect_create_grid.attach(right_coeff,1,7,1,1);
	effect_create_grid.attach(left_coeff_label,0,8,1,1);
	effect_create_grid.attach(left_coeff,1,8,1,1);
	effect_create_grid.attach(deadband_label,0,9,1,1);
	effect_create_grid.attach(deadband,1,9,1,1);
	effect_create_grid.attach(center_label,0,10,1,1);
	effect_create_grid.attach(center,1,10,1,1);
	effect_create_grid.attach(test_effect_button,0,11,3,1);
        this->show_all();
	this->chosen == 1;
}

void FFDWindow::on_constant_button_clicked() {
	clean_effect_grid();
	effect_header_label.set_text("Constant");
	effect_create_grid.attach(name_label,0,0,1,1);
	effect_create_grid.attach(name_entry,1,0,1,1);
	effect_create_grid.attach(effect_header_label,0,1,2,1);
	effect_create_grid.attach(condition_type_label,0,2,1,1);
	effect_create_grid.attach(condition_type,1,2,1,1);
	effect_create_grid.attach(dir_label,0,3,1,1);
	effect_create_grid.attach(direction,1,3,4,1);
	effect_create_grid.attach(length_label,0,4,1,1);
	effect_create_grid.attach(length,1,4,1,1);
	effect_create_grid.attach(delay_label,0,5,1,1);
	effect_create_grid.attach(delay,1,5,1,1);
	effect_create_grid.attach(level_label,0,6,1,1);
	effect_create_grid.attach(level,1,6,1,1);
	effect_create_grid.attach(attack_label,0,7,1,1);
	effect_create_grid.attach(attack,1,7,1,1);
	effect_create_grid.attach(attack_lvl_label,0,8,1,1);
	effect_create_grid.attach(attack_lvl,1,8,1,1);
	effect_create_grid.attach(fade_label,0,9,1,1);
	effect_create_grid.attach(fade,1,9,1,1);
	effect_create_grid.attach(fade_lvl_label,0,10,1,1);
	effect_create_grid.attach(fade_lvl,1,10,1,1);
	effect_create_grid.attach(test_effect_button,0,11,3,1);
        this->show_all();
	this->chosen == 1;
}

void FFDWindow::on_custom_button_clicked() {
	clean_effect_grid();
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
	effect_create_grid.attach(test_effect_button,0,6,3,1);
        this->show_all();
	this->chosen == 1;
}

void FFDWindow::on_test_effect_button_clicked() {
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
        	this->effect.set_effect_type(type_var);
		switch (effect_type.get_active_row_number()){
			case 0:
		                this->effect.set_type(SDL_HAPTIC_LEFTRIGHT);
			break;
			case 1:
				this->effect.set_type(SDL_HAPTIC_SAWTOOTHUP);
			break;
			case 2:
	        	        this->effect.set_type(SDL_HAPTIC_SAWTOOTHDOWN);
			break;
			case 3:
		                this->effect.set_type(SDL_HAPTIC_SINE);
			break;
			case 4:
		                this->effect.set_type(SDL_HAPTIC_TRIANGLE);
			break;
		}
		switch (condition_type.get_active_row_number()){
                       case 0:
                                this->effect.set_type(SDL_HAPTIC_SPRING);
                        break;
                        case 1:
                                this->effect.set_type(SDL_HAPTIC_DAMPER);
                        break;
                        case 2:
                                this->effect.set_type(SDL_HAPTIC_INERTIA);
                        break;
                        case 3:
                                this->effect.set_type(SDL_HAPTIC_FRICTION);
                        break;
		}
	        this->effect.set_length(int(length.get_value()));
	        this->effect.set_delay(int(delay.get_value()));
        	//this->effect.set_button();
        	//this->effect.set_interval();
       		this->effect.set_right_sat(int(right_sat.get_value()));
       		this->effect.set_left_sat(int(left_sat.get_value()));
       		this->effect.set_right_coeff(int(right_coeff.get_value()));
        	this->effect.set_left_coeff(int(left_coeff.get_value()));
        	this->effect.set_deadband(int(deadband.get_value()));
	        this->effect.set_center(int(center.get_value()));
	        this->effect.set_direction_type(int(direction_type.get_active_row_number()));
	        this->effect.set_direction(int(direction.get_value()));
	        this->effect.set_period(int(period.get_value()));
	        //this->effect.set_samples();
	        this->effect.set_magnitude(int(magnitude.get_value()));
	        this->effect.set_large_magnitude(int(large_magnitude.get_value()));
	        this->effect.set_small_magnitude(int(small_magnitude.get_value()));
	        this->effect.set_offset(int(offset.get_value()));
	        this->effect.set_phase(int(phase.get_value()));
	        this->effect.set_attack_length(int(attack.get_value()));
	        this->effect.set_attack_level(int(attack_lvl.get_value()));
	        this->effect.set_fade_length(int(fade_length.get_value()));
	        this->effect.set_fade_level(int(fade_lvl.get_value()));
		cout << "Running Effect" << endl;
		/*Execute the Force Feedback Engine!*/
//		init_ffb(this->effect);
		open_joys(this->effect);
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.Force_Feedback_Designer");
    FFDWindow window;
    init_sdl();
    return app->run(window);
}

