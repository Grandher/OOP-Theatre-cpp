#include "Occupation_list.h"
#include <iostream>

void Occupation_list::clear()
{
	list.clear();
}

void Occupation_list::append_list(Occupation value)
{
	list.push_back(value);
}

void Occupation_list::remove_list(int code)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].get_code() == code)
			list.erase(list.begin() + i);
}

Occupation Occupation_list::find_by_code(int code)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].get_code() == code)
			return list[i];
}

std::vector<int> Occupation_list::get_codes()
{
	std::vector <int> codes;
	for (int i = 0; i < list.size(); i++)
		codes.push_back(list[i].get_code());
	return codes;
}

std::vector<Occupation> Occupation_list::get_items()
{
	return list;
}

void Occupation_list::create_item(int code, Actors actor, Spectacle spectacle, std::string role, int contract_cost)
{
	bool flag = false;
	std::vector<int> codes = this->get_codes();
	for (int i = 0; i < codes.size(); i++) {
		if (codes[i] == code)
			flag = true;
	}
	if (flag)
		std::cout << "Error, actor with code " << code << " exist!";
	else {
		Occupation value(code, actor, spectacle, role, contract_cost);
		list.push_back(value);
	}
}
