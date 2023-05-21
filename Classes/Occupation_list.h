#pragma once
#include "Occupation.h"
#include <vector>

class Occupation_list :
    private Occupation
{
private:
    std::vector <Occupation> list;
public:
    void clear();
    void append_list(Occupation value);
    void remove_list(int code);
    Occupation find_by_code(int code);
    std::vector<int> get_codes();
    std::vector <Occupation> get_items();
    void create_item(int code, Actors actor, Spectacle spectacle, std::string role, int contract_cost);
};