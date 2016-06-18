#include <gtkmm.h>
#include <experimental/optional>
#include <iostream>

#include "get_DPI_scale.hpp"

std::experimental::optional<float> g_DPI_scale;

int main(int argc, char* argv[])
{
  g_DPI_scale.emplace(get_DPI_scale());

  std::cerr << "DPI scale: " << *g_DPI_scale << "\n";

  auto app = Gtk::Application::create(argc, argv, "veltas.distrotycoon");

  Gtk::Window window;
  window.set_default_size(200, 200);

  return app->run(window);
}
