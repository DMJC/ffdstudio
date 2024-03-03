#ifndef FFD
#define FFD
#include <gtkmm.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include <string>
#include "ffb.h"
#include "effect.h"
using namespace std;

class FFDWindow : public Gtk::Window {
public:
    FFDWindow();
    thread sdlThread;
    future<int> sdl_started;
    void align_all();
    void joinThread();
    void start_sdl();
    void on_file_save_response(int response_id, Gtk::FileChooserDialog* dialog);
    void on_file_open_response(int response_id, Gtk::FileChooserDialog* dialog);
    void update_variables();
    void on_create_button_clicked();
    void on_open_profile_button_clicked();
    void on_quit_button_clicked();
    void on_save_profile_button_clicked();
    void clean_effect_grid ();
    void on_periodic_button_clicked();
    void on_ramp_button_clicked();
    void on_leftright_button_clicked();
    void on_condition_button_clicked();
    void on_constant_button_clicked();
    void on_custom_button_clicked();
    void on_test_effect_button_clicked();
private:
    Gtk::Grid launch_grid, effect_select_grid, effect_create_grid; // Define your grids
    Gtk::Button create_new_button, open_profile_button, quit_button;
    Gtk::Button save_profile_button, condition_button, custom_button, periodic_button, ramp_button, leftright_button, direction_button, constant_button;
    Gtk::Label set_effect_label, effect_header_label, condition_type_label, name_label, effect_type_label;
    Gtk::Label dir_type_label, dir_label, delay_label, period_label, phase_label, offset_label, magnitude_label, large_magnitude_label, small_magnitude_label;
    Gtk::Label length_label, attack_label, fade_label, attack_lvl_label, fade_lvl_label, level_label, left_sat_label, right_sat_label, right_coeff_label;
    Gtk::Label left_coeff_label, deadband_label, center_label, start_strength_label, end_strength_label;
    Gtk::Paned pane;
    Gtk::Button test_effect_button;
    Gtk::Scale direction_0, direction_1, direction_2, delay, period, phase, offset, magnitude, large_magnitude, small_magnitude, length, fade, fade_lvl, fade_length, attack, attack_lvl;
    Gtk::Scale level, left_sat_0, right_sat_0, right_coeff_0, left_coeff_0, deadband_0, center_0, left_sat_1, right_sat_1, right_coeff_1, left_coeff_1, deadband_1, center_1,left_sat_2, right_sat_2, right_coeff_2, left_coeff_2, deadband_2, center_2, start_strength, end_strength;
    Gtk::Entry name_entry;
    Gtk::ComboBoxText effect_type, direction_type, condition_type;
    FFDEffect effect;
    int chosen = 0;
    int has_sdl_started = 0;
};

#endif //FFD
