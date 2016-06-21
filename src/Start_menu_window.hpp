#ifndef START_MENU_WINDOW_HPP_INCLUDED
#define START_MENU_WINDOW_HPP_INCLUDED

#include <deque>

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include "defs.hpp"
#include "Program_mode.hpp"

class Start_menu_window: public Gtk::Window {
  Program_mode m_next_mode = Program_mode::end;

  enum class Button_enum: int {
    new_game = 0,
    load_game,
    about,
    quit
  };

public:
  Start_menu_window();

  virtual ~Start_menu_window() override;

  Program_mode get_next_mode() const { return m_next_mode; }

protected:

  void on_button_clicked(Button_enum button_enum);

  Gtk::Box m_box{Gtk::ORIENTATION_VERTICAL, static_cast<int>(*g_DPI_scale * 5)};

  Gtk::Label m_banner{"<span varient='smallcaps' size='x-large'>Distro Tycoon</span>"};

  std::deque<Gtk::Button> m_buttons;
};

#endif // START_MENU_WINDOW_HPP_INCLUDED
