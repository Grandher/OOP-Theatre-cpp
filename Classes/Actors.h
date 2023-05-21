#pragma once
#include <string>
//(Surname, Name, Secname , Rank  , Experience)
//(Фамилия, Имя , Отчество, Звание, Стаж)
class Actors
{
private:
    int code; std::string surname; std::string name; std::string secname; std::string rank; int experience;
public:
    Actors();
    Actors(int code, std::string surname, std::string name, std::string secname, std::string rank, int experience);
    void set_code(int code);
    void set_surname(std::string surname);
    void set_name(std::string name);
    void set_secname(std::string secname);
    void set_rank(std::string rank);
    void set_experience(int exp);

    int get_code();
    std::string get_surname();
    std::string get_name();
    std::string get_secname();
    std::string get_rank();
    int get_experience();

    std::string print_actors();
    bool exist_actor();
};

