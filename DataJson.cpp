#include "DataJson.h"

DataJson::DataJson(Theatre theat, std::string infile, std::string outfile){
	this->theat = theat; this->infile = infile; this->outfile = outfile;
}

Theatre DataJson::get_theat(){
    return theat;
}

std::string DataJson::get_infile(){
    return infile;
}

std::string DataJson::get_outfile(){
    return outfile;
}

void DataJson::set_theat(Theatre theat){
    this->theat = theat;
}

void DataJson::set_infile(std::string filename){
    this->infile = filename;
}

void DataJson::set_outfile(std::string filename){
    this->outfile = filename;
}

void DataJson::read() {
    std::ifstream ifs{ infile };
    if (!ifs.is_open()) {
        std::cerr << "Unable to open file\n";
        throw 1;
    }
    json j;
    ifs >> j;
    ifs.close();

    if (j.find("actor") != j.end())
        for (int i = 0; i < j["actor"].size(); i++) {
            int code = j["actor"][i]["code"];
            std::string surname = j["actor"][i]["surname"];
            std::string name = j["actor"][i]["name"];
            std::string secname = j["actor"][i]["secname"];
            std::string rank = j["actor"][i]["rank"];
            int exp = j["actor"][i]["experience"];
            theat.create_actor(code, surname, name, secname, rank, exp);
        }
    if (j.find("spectacle") != j.end())
        for (int i = 0; i < j["spectacle"].size(); i++) {
            int code = j["spectacle"][i]["code"];
            std::string title = j["spectacle"][i]["title"];
            int year = j["spectacle"][i]["year"];
            double budget = j["spectacle"][i]["budget"];
            theat.create_spectacle(code, title, year, budget);
        }
    if (j.find("occupation") != j.end())
        for (int i = 0; i < j["occupation"].size(); i++) {
            int code = j["occupation"][i]["code"];
            std::string role = j["occupation"][i]["role"];
            int cost = j["occupation"][i]["contract_cost"];
            int act_num = j["occupation"][i]["actor"];
            int spc_num = j["occupation"][i]["spectacle"];
            Actors act_value = theat.get_actor(act_num);
            Spectacle spc_value = theat.get_spectacle(spc_num);
            theat.create_occupation(code, act_value, spc_value, role, cost);
        }
}

void DataJson::write() {
    std::ofstream ofs{ outfile };
    json j;

    for (int i = 0; i < theat.get_actors_list().size(); i++) {
        j["actor"][i]["code"] = theat.get_actors_list()[i].get_code();
        j["actor"][i]["surname"] = theat.get_actors_list()[i].get_surname();
        j["actor"][i]["name"] = theat.get_actors_list()[i].get_name();
        j["actor"][i]["secname"] = theat.get_actors_list()[i].get_secname();
        j["actor"][i]["rank"] = theat.get_actors_list()[i].get_rank();
        j["actor"][i]["experience"] = theat.get_actors_list()[i].get_experience();
    }
    for (int i = 0; i < theat.get_spectacles_list().size(); i++) {
        j["spectacle"][i]["code"] = theat.get_spectacles_list()[i].get_code();
        j["spectacle"][i]["title"] = theat.get_spectacles_list()[i].get_title();
        j["spectacle"][i]["year"] = theat.get_spectacles_list()[i].get_year();
        j["spectacle"][i]["budget"] = theat.get_spectacles_list()[i].get_budget();
    }
    for (int i = 0; i < theat.get_occupations_list().size(); i++) {
        j["occupation"][i]["code"] = theat.get_occupations_list()[i].get_code();
        j["occupation"][i]["role"] = theat.get_occupations_list()[i].get_role();
        j["occupation"][i]["contract_cost"] = theat.get_occupations_list()[i].get_contract_cost();
        j["occupation"][i]["actor"] = theat.get_occupations_list()[i].get_actor().get_code();
        j["occupation"][i]["spectacle"] = theat.get_occupations_list()[i].get_spectacle().get_code();
    }
    ofs << std::setw(2) << j << std::endl;
    ofs.close();
}
