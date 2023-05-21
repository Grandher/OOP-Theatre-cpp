#include "DataSql.h"

DataSql::DataSql(Theatre theat, std::string infile, std::string outfile) {
	this->theat = theat; this->infile = infile; this->outfile = outfile;
}

Theatre DataSql::get_theat() {
    return theat;
}

std::string DataSql::get_infile() {
    return infile;
}

std::string DataSql::get_outfile() {
    return outfile;
}

void DataSql::set_theat(Theatre theat) {
    this->theat = theat;
}

void DataSql::set_infile(std::string filename) {
    this->infile = filename;
}

void DataSql::set_outfile(std::string filename) {
    this->outfile = filename;
}

void DataSql::read() {
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(infile.c_str(), &DB);
    char* messaggeError;
    sqlite3_stmt* stmt;
    std::string query = "select code, surname, name, secname, rank, experience from actor";
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int code = sqlite3_column_int(stmt, 0);
            std::string surname = (const char*) sqlite3_column_text(stmt, 1);
            std::string name = (const char*) sqlite3_column_text(stmt, 2);
            std::string secname = (const char*) sqlite3_column_text(stmt, 3);
            std::string rank = (const char*) sqlite3_column_text(stmt, 4);
            int experience = sqlite3_column_int(stmt, 5);
            theat.create_actor(code, surname, name, secname, rank, experience);
            
        }
    }
    query = "select code, title, year, budget from spectacle";
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int code = sqlite3_column_int(stmt, 0);
            std::string title = (const char*)sqlite3_column_text(stmt, 1);
            int year = sqlite3_column_int(stmt, 2);
            double budget = sqlite3_column_double(stmt, 3);
            theat.create_spectacle(code, title, year, budget);
        }
    }
    query = "select code, role, contract_cost, actor, spectacle from occupation";
    if (sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int code = sqlite3_column_int(stmt, 0);
            std::string role = (const char*)sqlite3_column_text(stmt, 1);
            int contract_cost = sqlite3_column_int(stmt, 2);
            int act_num = sqlite3_column_int(stmt, 3);
            int spc_num = sqlite3_column_int(stmt, 4);
            theat.create_occupation(code, theat.get_actor(act_num), theat.get_spectacle(spc_num), role, contract_cost);
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(DB);
}

void DataSql::write() {
    sqlite3* DB;
    std::string sql = "PRAGMA foreign_keys = ON;"
        "create table actor"
        "(code integer primary key,"
        "surname text,"
        "name text,"
        "secname text,"
        "rank text,"
        "experience integer);"

        "create table spectacle"
        "(code integer primary key,"
        "title text,"
        "year integer,"
        "budget real);"

        "create table occupation"
        "(code integer primary key,"
        "role text,"
        "contract_cost text,"
        "actor integer references actor(code) on update cascade on delete set null,"
        "spectacle integer references spectacle(code) on update cascade on delete set null);";

    int exit = 0;
    exit = sqlite3_open(outfile.c_str(), &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK)
        sqlite3_free(messaggeError);
    for (int i = 0; i < theat.get_actors_list().size(); i++) {
        std::string query = "insert into actor(code, surname, name, secname, rank, experience) values(";
        query += std::to_string(theat.get_actors_list()[i].get_code()) + ", '";
        query += theat.get_actors_list()[i].get_surname() + "', '";
        query += theat.get_actors_list()[i].get_name() + "', '";
        query += theat.get_actors_list()[i].get_secname() + "', '";
        query += theat.get_actors_list()[i].get_rank() + "', ";
        query += std::to_string(theat.get_actors_list()[i].get_experience()) + ')';
        sqlite3_exec(DB, query.c_str(), NULL, 0, &messaggeError);
    }
    for (int i = 0; i < theat.get_spectacles_list().size(); i++) {
        std::string query = "insert into spectacle(code, title, year, budget) values(";
        query += std::to_string(theat.get_spectacles_list()[i].get_code()) + ", '";
        query += theat.get_spectacles_list()[i].get_title() + "', ";
        query += std::to_string(theat.get_spectacles_list()[i].get_year()) + ", ";
        query += std::to_string(theat.get_spectacles_list()[i].get_budget()) + ')';
        sqlite3_exec(DB, query.c_str(), NULL, 0, &messaggeError);
    }
    for (int i = 0; i < theat.get_occupations_list().size(); i++) {
        std::string query = "insert into occupation(code, role, contract_cost, actor, spectacle) values(";
        query += std::to_string(theat.get_occupations_list()[i].get_code()) + ", '";
        query += theat.get_occupations_list()[i].get_role() + "', '";
        query += std::to_string(theat.get_occupations_list()[i].get_contract_cost()) + "', ";
        query += std::to_string(theat.get_occupations_list()[i].get_actor().get_code()) + ", ";
        query += std::to_string(theat.get_occupations_list()[i].get_spectacle().get_code()) + ')';
        sqlite3_exec(DB, query.c_str(), NULL, 0, &messaggeError);
    }
    sqlite3_close(DB);
}