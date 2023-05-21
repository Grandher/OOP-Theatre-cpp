#pragma once
#include "Spectacle.h"
#include <vector>

class Spectacle_list :
    private Spectacle
{
private:
    std::vector <Spectacle> list;
public:
    void clear();
    void append_list(Spectacle value);
    void remove_list(int code);
    Spectacle find_by_code(int code);
    std::vector<int> get_codes();
    std::vector <Spectacle> get_items();
    void create_item(int code, std::string title, int year, double budget);
};

