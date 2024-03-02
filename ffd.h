#ifndef FFD
#define FFD
#include <gtkmm.h>
#include <iostream>
#include <fstream>
#include "ffb.h"
#include "effect.h"
using namespace std;

class FFDWindow : public Gtk::Window {
public:
    FFDWindow();
    FFDWindow(const std::string& title, Gtk::FileChooserAction action);
    void save_to_file(const std::string& filename, const std::string& content);
    void open_from_file(const std::string& filename);
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
    Gtk::Scale direction, delay, period, phase, offset, magnitude, large_magnitude, small_magnitude, length, fade, fade_lvl, fade_length, attack, attack_lvl;
    Gtk::Scale level, left_sat, right_sat, right_coeff, left_coeff, deadband, center, start_strength, end_strength;
    Gtk::Entry name_entry;
    Gtk::ComboBoxText effect_type, direction_type, condition_type;
    FFDEffect effect;
    int chosen = 0;
};

#endif //FFD
