#include "Occupation.h"

Occupation::Occupation()
{
	code = 0; role = ""; contract_cost = 0; actor = Actors(); spectacle = Spectacle();
}

Occupation::Occupation(int code, Actors actor, Spectacle spectacle, std::string role, int contract_cost)
{
	this->code = code; this->actor = actor; this->spectacle = spectacle;
	this->role = role; this->contract_cost = contract_cost;
}

std::string Occupation::print_all()
{
	std::string act, spc;
	act = actor.exist_actor() ? actor.print_actors() : "Нет актёра\n";
	spc = spectacle.exist_spectacle() ? spectacle.print_spectacle() : "Нет спектакля\n";
	return std::string(act + spc + "Роль: " + role + "\nСтоимость контракта: " + std::to_string(contract_cost) + " тыс. рублей\n\n");
}

void Occupation::set_code(int code) {
	this->code = code;
}

void Occupation::set_role(std::string role) {
	this->role = role;
}
void Occupation::set_contract_cost(int cost) {
	this->contract_cost = cost;
}
void Occupation::set_actor(Actors actor) {
	this->actor = actor;
}
void Occupation::set_spectacle(Spectacle scpectacle) {
	this->spectacle = spectacle;
}


int Occupation::get_code() {
	return code;
}
std::string Occupation::get_role() {
	return role;
}
int Occupation::get_contract_cost() {
	return contract_cost;
}
Actors Occupation::get_actor() {
	return actor;
}
Spectacle Occupation::get_spectacle() {
	return spectacle;
}