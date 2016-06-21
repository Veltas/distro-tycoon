#ifndef DEFS_HPP_INCLUDED
#define DEFS_HPP_INCLUDED

#include <experimental/optional>
#include <random>

#define PROGNAME "Distro Tycoon"
#define FIRSTNAMES "assets/firstnames.txt"
#define LASTNAMES "assets/lastnames.txt"

extern std::experimental::optional<float> g_DPI_scale;

extern std::experimental::optional<std::mt19937> g_RNE;

extern std::experimental::optional<std::vector<std::string>> g_firstnames;
extern std::experimental::optional<std::vector<std::string>> g_lastnames;

#endif // DEFS_HPP_INCLUDED
