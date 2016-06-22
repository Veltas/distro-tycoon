#include <gtkmm/application.h>
#include <gtkmm/messagedialog.h>
#include <iostream>
#include <iterator>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <cassert>

#include <exception>
#include <stdexcept>

#include "get_DPI_scale.hpp"
#include "defs.hpp"

#include "Program_mode.hpp"
#include "Start_menu_window.hpp"

namespace {
  void init_names()
  {
    using Input_it = std::istream_iterator<std::string>;
    {
      std::ifstream input_stream(FIRSTNAMES);
      g_firstnames.emplace(Input_it{input_stream}, Input_it{});
    }
    {
      std::ifstream input_stream(LASTNAMES);
      g_lastnames.emplace(Input_it{input_stream}, Input_it{});
    }
  }

  void init_globals()
  {
    g_DPI_scale.emplace(get_DPI_scale());

    std::cerr << PROGNAME ": DPI scale = " << *g_DPI_scale << "\n";

    using namespace std::chrono;
    g_RNE.emplace(steady_clock::now().time_since_epoch().count());

    init_names();
  }
}

int main(int argc, char* argv[])
{
  init_globals();

  Program_mode program_mode = Program_mode::start_menu;
  bool running = true;
  while (running) {
    try {
      auto app = Gtk::Application::create("veltas.distrotycoon");
      switch (program_mode) {
        case Program_mode::start_menu: {
          Start_menu_window start_menu_window;
          app->run(start_menu_window);
          assert(app > 0);
          program_mode = start_menu_window.get_next_mode();
        } break;
        case Program_mode::load_game: {
          /*
          Load_game_window load_game_window;
          app->run(load_game_window);
          program_mode = load_game_window.get_next_mode();
          // */
          throw std::runtime_error("Not implemented");
        } break;
        case Program_mode::playing: {
          /*
          Playing_window playing;
          app->run(playing);
          program_mode = playing.get_next_mode();
          // */
          throw std::runtime_error("Not implemented");
        } break;
        case Program_mode::end: {
          running = false;
        } break;
      }
    } catch (std::exception& e) {
      Gtk::MessageDialog message_dialog{
        "Uncaught exception error",
        false,
        Gtk::MESSAGE_ERROR
      };
      message_dialog.set_secondary_text(std::string{"Error: "} + e.what());
      message_dialog.run();
      return EXIT_FAILURE;
    }
  }
}
