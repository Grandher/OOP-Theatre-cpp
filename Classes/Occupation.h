#pragma once
#include "Spectacle.h"
#include "Actors.h"
#include <string>
//(Actor, Spectacle, Role, Contract_Cost)
//(Актёр, Спектакль, Роль, Стоимость контракта)
class Occupation
{
private:
    int code; std::string role; int contract_cost; Actors actor; Spectacle spectacle;
public:
    Occupation();
    Occupation(int code, Actors actor, Spectacle spectacle, std::string role, int contract_cost);
    void set_code(int code);
    void set_role(std::string role);
    void set_contract_cost(int cost);
    void set_actor(Actors actor);
    void set_spectacle(Spectacle scpectacle);

    int get_code();
    std::string get_role();
    int get_contract_cost();
    Actors get_actor();
    Spectacle get_spectacle();

    std::string print_all();
};

