#include "Start_menu_window.hpp"

#include <gtkmm/aboutdialog.h>
#include <cstddef>
#include "defs.hpp"
#include <stdexcept>

Start_menu_window::Start_menu_window()
{
  m_buttons.emplace_back("New game");
  m_buttons.emplace_back("Load game");
  m_buttons.emplace_back("About");
  m_buttons.emplace_back("Quit");

  m_banner.set_markup("<tt><span variant=\"smallcaps\" size=\"x-large\">Distro Tycoon</span></tt>");

  set_title("Distro Tycoon");
  set_border_width(*g_DPI_scale * 20);

  add(m_top_box);
  m_top_box.set_homogeneous(false);

  m_top_box.pack_start(m_banner, Gtk::PACK_EXPAND_PADDING, *g_DPI_scale * 2);

  for (std::size_t i = 0; i < m_buttons.size(); ++i) {
    m_buttons[i].signal_clicked().connect([&, i]{ on_button_clicked(static_cast<Button_enum>(i)); });
    m_top_box.pack_start(m_buttons[i], Gtk::PACK_EXPAND_PADDING, *g_DPI_scale * 2);
    m_buttons[i].show();
  }

  m_top_box.show();

  show_all_children();
}

void Start_menu_window::on_button_clicked(Button_enum button_enum)
{
  switch (button_enum) {
    case Button_enum::new_game: {
      m_next_mode = Program_mode::playing;
      hide();
    } break;
    case Button_enum::load_game: {
      m_next_mode = Program_mode::load_game;
      hide();
    } break;
    case Button_enum::about: {
      Gtk::AboutDialog dialog;
      dialog.set_transient_for(*this);
      dialog.set_version("in dev");
      dialog.set_copyright("Christopher Leonard");
      dialog.set_comments("Distro management game.");
      dialog.set_license("GPL v3");
      dialog.set_website("http://www.github.com/Veltas/distro-tycoon");
      dialog.set_website_label("GitHub page");
      std::vector<Glib::ustring> list_authors;
      list_authors.emplace_back("Christopher Leonard");
      dialog.set_authors(list_authors);
      dialog.run();
    } break;
    case Button_enum::quit: {
      hide();
    } break;
  }
}

Start_menu_window::~Start_menu_window() { }
