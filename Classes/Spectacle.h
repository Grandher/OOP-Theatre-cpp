#pragma once
#include <string>
//(Title   , Year, Budget)
//(Название, Год , Бюджет)
class Spectacle
{
private:
    int code; std::string title; int year; double budget;
public:
    Spectacle();
    Spectacle(int code, std::string title, int year, double budget);
    void set_code(int code);
    void set_title(std::string title);
    void set_year(int year);
    void set_budget(int budget);
    int get_code();
    std::string get_title();
    int get_year();
    int get_budget();

    std::string print_spectacle();
    bool exist_spectacle();
};