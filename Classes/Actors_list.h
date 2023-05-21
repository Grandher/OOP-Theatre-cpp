#pragma once
#include "Actors.h"
#include <vector>
class Actors_list :
    private Actors
{
private:
    std::vector <Actors> list;
public:
    void clear();
    void append_list(Actors value);
    void remove_list(int code);
    Actors find_by_code(int code);
    std::vector<int> get_codes();
    std::vector <Actors> get_items();
    void create_item(int code, std::string surname, std::string name, std::string secname, std::string rank, int experience);
};

