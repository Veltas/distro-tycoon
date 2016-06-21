#ifndef DEV_MODEL_HPP_INCLUDED
#define DEV_MODEL_HPP_INCLUDED

#include "Package_type.hpp"

#include <string>

class Dev_model {
  Package_type m_affinity;
  int m_age;
  int m_exp;
  std::string m_name;

public:
  Dev_model(Package_type affinity, int age, int exp, const char* name) :
    m_affinity{affinity},
    m_age{age},
    m_exp{exp},
    m_name{name}
  { }

  Package_type get_affinity() const { return m_affinity; }

  int get_age() const { return m_age; }
  void set_age(int new_age) { m_age = new_age; }

  int get_exp() const { return m_exp; }
  void set_exp(int new_exp) { m_exp = new_exp; }
};

#endif // DEV_MODEL_HPP_INCLUDED
