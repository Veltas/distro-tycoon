#ifndef GAME_MODEL_HPP_INCLUDED
#define GAME_MODEL_HPP_INCLUDED

#include <memory>
#include <vector>
#include <string>
#include <cstdint>
#include <utility>

#include "Dev_model.hpp"
#include "Other_distro.hpp"

class Game_model {
  std::string m_savename;
  std::vector<Dev_model> m_volunteer_devs;
  std::vector<Dev_model> m_paid_devs;
  std::string m_distro_name;
  std::string m_current_version;
  std::string m_dev_version;
  std::int_fast64_t m_user_count;
  std::vector<Other_distro> m_other_distros;

public:
  Game_model(const char* savename, 
};

#endif // GAME_MODEL_HPP_INCLUDED
