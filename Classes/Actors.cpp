#include "Actors.h"

std::string count_experience(int e) {
	if (e % 10 == 1)
		return std::to_string(e) + " год";
	else if ((e % 10 == 2 or e % 10 == 3 or e % 10 == 4) and (e < 10 or e > 20))
		return std::to_string(e) + " года";
	else
		return std::to_string(e) + " лет";
}

bool Actors::exist_actor() {
	if (surname == "" and name == "" and secname == "" and rank == "" and experience == 0)
		return false;
	else return true;
}

std::string Actors::print_actors()
{
	return std::string("јктЄр #"+ std::to_string(code)+':'+' '+surname+" "+name[0]+". "+secname[0]+"., "+rank+", "+count_experience(experience)+"\n");
}

Actors::Actors()
{
	code = 0; surname = ""; name = ""; secname = ""; rank = ""; experience = 0;
}

Actors::Actors(int code, std::string surname, std::string name, std::string secname, std::string rank, int experience)
{
	this->code = code;
	this->surname = surname; this->name = name; this->secname = secname; this->rank = rank; this->experience = experience;
}

void Actors::set_code(int code) {
	this->code = code;
}

void Actors::set_surname(std::string surname) {
	this->surname = surname;
}
void Actors::set_name(std::string name) {
	this->name = name;
}
void Actors::set_secname(std::string secname) {
	this->secname = secname;
}
void Actors::set_rank(std::string rank) {
	this->rank = rank;
}
void Actors::set_experience(int exp) {
	this->experience = exp;
}

int Actors::get_code() {
	return code;
}

std::string Actors::get_surname() {
	return surname;
}
std::string Actors::get_name() {
	return name;
}
std::string Actors::get_secname() {
	return secname;
}
std::string Actors::get_rank() {
	return rank;
}
int Actors::get_experience() {
	return experience;
}