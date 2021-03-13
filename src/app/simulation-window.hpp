/**
 * simulation-window.hpp
 *
 * Author: Viktor Fukala
 * Created on 2020/12/25
 */
#ifndef SIMULATION_WINDOW_HPP
#define SIMULATION_WINDOW_HPP

#include <functional>

#include <gtkmm/button.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/entry.h>
#include <gtkmm/frame.h>
#include <gtkmm/grid.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/scale.h>
#include <gtkmm/switch.h>

#include "glob.hpp"

#include "brandy-window.hpp"
#include "display-area.hpp"
#include "sim-frame.hpp"
#include "simulation-state-abstr.hpp"
#include "simulation-params.hpp"

namespace brandy0
{

class SimulationWindow : public BrandyWindow
{
private:
	SimulationStateAbstr *parent;

	DisplayArea dArea;
	Gtk::Grid mainGrid;

	Gtk::Grid panelGrid;
	
	Gtk::Button toConfigButton;

	Gtk::Frame computingFrame;
	Gtk::Grid computingGrid;
	Gtk::Switch computingSwitch;
	Gtk::Label frameBufferLabel;
	Gtk::Label curIterLabel;
	Gtk::Label computingStatusLabel;

	Gtk::Frame playbackFrame;
	Gtk::Grid playbackGrid;
	Gtk::ComboBoxText playbackModeSelector;
	Gtk::Button playPauseButton;
	Gtk::Label timeLabel, playbackSpeedLabel;
	bool timeScaleAutoSet;
	Gtk::Scale timeScale, playbackSpeedScale;

	Gtk::Frame viewFrame;
	Gtk::Grid viewGrid;
	Gtk::Label backDisplayLabel, frontDisplayLabel;
	Gtk::ComboBoxText backDisplaySelector, frontDisplaySelector;

	Gtk::Button videoExportButton;

	void updateStats();
	void updatePlaybackModeSelector();
	void disableWhenExport();
	void enableWhenNotExport();
	void update();

public:
	SimulationWindow(SimulationStateAbstr *const parent);

	~SimulationWindow();
};

}

#endif // SIMULATION_WINDOW_HPP
