#include <gtkmm/application.h>
#include <iostream>

#include "get_DPI_scale.hpp"
#include "defs.hpp"

#include "helloworld.hpp"

int main(int argc, char* argv[])
{
  g_DPI_scale.emplace(get_DPI_scale());

  std::cerr << PROGNAME ": DPI scale = " << *g_DPI_scale << "\n";

  auto app = Gtk::Application::create(argc, argv, "veltas.distrotycoon");

  Hello_world helloworld;

  return app->run(helloworld);
}
