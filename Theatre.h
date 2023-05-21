#include "Classes/Actors_list.h"
#include "Classes/Spectacle_list.h"
#include "Classes/Occupation_list.h"
#pragma once
class Theatre
{
private:
	Actors_list actors;
	Spectacle_list spectacles;
	Occupation_list occupations;
public:
	void create_actor(int code, std::string surname, std::string name, std::string secname, std::string rank, int experience);
	void create_spectacle(int code, std::string title, int year, double budget);
	void create_occupation(int code, Actors actor, Spectacle spectacle, std::string role, int contract_cost);
	std::vector <Actors> get_actors_list();
	std::vector <Spectacle> get_spectacles_list();
	std::vector <Occupation> get_occupations_list();
	Actors get_actor(int code);
	Spectacle get_spectacle(int code);
	Occupation get_occupation(int code);
};

