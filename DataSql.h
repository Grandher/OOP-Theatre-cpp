#pragma once
#include <iostream>
#include <fstream>
#include <sqlite3.h>
#include "Theatre.h"

class DataSql
{
private:
	Theatre theat;
	std::string infile = "";
	std::string outfile = "";
public:
	DataSql(Theatre theat, std::string infile, std::string outfile);
	Theatre get_theat();
	std::string get_infile();
	std::string get_outfile();
	void set_theat(Theatre theat);
	void set_infile(std::string filename);
	void set_outfile(std::string filename);
	void read();
	void write();
};

