#include <iostream>
#include "Actors_list.h"

void Actors_list::clear()
{
	list.clear();
}

void Actors_list::append_list(Actors value)
{
	list.push_back(value);
}

void Actors_list::remove_list(int code)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].get_code() == code)
			list.erase(list.begin() + i);
	//for (std::vector<Actors>::iterator it = list.begin(); it != list.end(); it++)
}

Actors Actors_list::find_by_code(int code)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].get_code() == code)
			return list[i];
}

std::vector<int> Actors_list::get_codes()
{
	std::vector <int> codes;
	for (int i = 0; i < list.size(); i++)
		codes.push_back(list[i].get_code());
	return codes;
}

std::vector<Actors> Actors_list::get_items()
{
	return list;
}

void Actors_list::create_item(int code, std::string surname, std::string name, std::string secname, std::string rank, int experience)
{
	bool flag = false;
	std::vector<int> codes = this->get_codes();
	for (int i = 0; i < codes.size(); i++)	{
		if (codes[i] == code)
			flag = true;
	}
	if (flag)
		std::cout << "Error, actor with code " << code << " exist!";
	else {
		Actors value(code, surname, name, secname, rank, experience);
		list.push_back(value);
	}
}
