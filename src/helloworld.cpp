#include "helloworld.hpp"
#include "defs.hpp"
#include <iostream>

Hello_world::Hello_world() :
  m_button("Hello, world")
{
  set_border_width(*g_DPI_scale * 10);

  m_button.signal_clicked().connect(
    sigc::mem_fun(*this, &Hello_world::on_button_clicked)
  );

  add(m_button);
  m_button.show();
}

Hello_world::~Hello_world()
{ }

void Hello_world::on_button_clicked()
{
  std::cerr << "Hello, world!\n";
}
