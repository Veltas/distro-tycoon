#include "get_random_name.hpp"

#include "defs.hpp"
#include <random>

std::string get_random_name()
{
	auto firstname = std::uniform_int_distribution<unsigned long long>{0, g_firstnames->size()}(*g_RNE);
	auto lastname = std::uniform_int_distribution<unsigned long long>{0, g_lastnames->size()}(*g_RNE);
	return (*g_firstnames)[firstname] + " " + (*g_lastnames)[lastname];
}
