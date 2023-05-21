#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Theatre.h"

using json = nlohmann::json;

class DataJson
{
private:
	Theatre theat;
	std::string infile = "";
	std::string outfile = "";
public:
	DataJson(Theatre theat, std::string infile, std::string outfile);
	Theatre get_theat();
	std::string get_infile();
	std::string get_outfile();
	void set_theat(Theatre theat);
	void set_infile(std::string filename);
	void set_outfile(std::string filename);
	void read();
	void write();
};

