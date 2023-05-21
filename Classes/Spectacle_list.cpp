#include "Spectacle_list.h"
#include <iostream>

void Spectacle_list::clear()
{
	list.clear();
}

void Spectacle_list::append_list(Spectacle value)
{
	list.push_back(value);
}

void Spectacle_list::remove_list(int code)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].get_code() == code)
			list.erase(list.begin() + i);
}

Spectacle Spectacle_list::find_by_code(int code)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].get_code() == code)
			return list[i];
}

std::vector<int> Spectacle_list::get_codes()
{
	std::vector <int> codes;
	for (int i = 0; i < list.size(); i++)
		codes.push_back(list[i].get_code());
	return codes;
}

std::vector<Spectacle> Spectacle_list::get_items()
{
	return list;
}

void Spectacle_list::create_item(int code, std::string title, int year, double budget)
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
		Spectacle value(code, title, year, budget);
		list.push_back(value);
	}
}
