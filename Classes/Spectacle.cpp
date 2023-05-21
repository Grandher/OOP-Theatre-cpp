#include "Spectacle.h"

std::string Spectacle::print_spectacle()
{
	return std::string("Спектакль #" + std::to_string(code) + ": " + title + ", " + std::to_string(year) + " год, " + std::to_string(budget) + " млн. рублей\n");
}

bool Spectacle::exist_spectacle() {
	if (title == "" and year == 0 and budget == 0)
		return false;
	else return true;
}

Spectacle::Spectacle()
{
	title = ""; year = 0; budget = 0;
}

Spectacle::Spectacle(int code, std::string title, int year, double budget)
{
	this->code = code; this->title = title; this->year = year; this->budget = budget;
}

void Spectacle::set_code(int code)
{
	this->code = code;
}

void Spectacle::set_title(std::string title)
{
	this->title = title;
}

void Spectacle::set_year(int year)
{
	this->year = year;
}

void Spectacle::set_budget(int budget)
{
	this->budget = budget;
}

int Spectacle::get_code()
{
	return code;
}

std::string Spectacle::get_title()
{
	return std::string(title);
}

int Spectacle::get_year()
{
	return year;
}

int Spectacle::get_budget()
{
	return budget;
}