#ifndef HELLOWORLD_HPP_INCLUDED
#define HELLOWORLD_HPP_INCLUDED

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Hello_world: public Gtk::Window
{
public:
  Hello_world();
  virtual ~Hello_world();
protected:
  void on_button_clicked();

  Gtk::Button m_button{"_Hello", true};
};

#endif // HELLOWORLD_HPP_INCLUDED
