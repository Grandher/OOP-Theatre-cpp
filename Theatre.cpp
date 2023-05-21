#include "Theatre.h"

void Theatre::create_actor(int code, std::string surname, std::string name, std::string secname, std::string rank, int experience)
{
	actors.create_item(code, surname, name, secname, rank, experience);
}

void Theatre::create_spectacle(int code, std::string title, int year, double budget)
{
	spectacles.create_item(code, title, year, budget);
}

void Theatre::create_occupation(int code, Actors actor, Spectacle spectacle, std::string role, int contract_cost)
{
	occupations.create_item(code, actor, spectacle, role, contract_cost);
}

std::vector<Actors> Theatre::get_actors_list()
{
	return actors.get_items();
}

std::vector<Spectacle> Theatre::get_spectacles_list()
{
	return spectacles.get_items();
}

std::vector<Occupation> Theatre::get_occupations_list()
{
	return occupations.get_items();
}

Actors Theatre::get_actor(int code)
{
	return actors.find_by_code(code);
}

Spectacle Theatre::get_spectacle(int code)
{
	return spectacles.find_by_code(code);
}

Occupation Theatre::get_occupation(int code)
{
	return occupations.find_by_code(code);
}
