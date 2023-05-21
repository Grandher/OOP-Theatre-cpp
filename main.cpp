#include <iostream>
#include "Theatre.h"
#include "DataJson.h"
#include "DataSql.h"

int main(){
    setlocale(LC_ALL, "Russian");
    Theatre theat;
    std::string infile, outfile;
    std::cout << "Введите имя файла (с расширением):\n";
    std::cin >> infile;
    std::string ext = infile.substr(infile.rfind('.'), infile.size());
    if (ext == ".json") {
        std::cout << "Как назвать новые файлы?:\n";
        std::cin >> outfile;
        DataJson testjs(theat, infile, outfile + ".json");
        testjs.read(); theat = testjs.get_theat();
        DataSql testsql(theat, "", outfile + ".sqlite");
        testjs.write(); testsql.write();
    }
    else if (ext == ".sqlite" or ext == ".db") {
        std::cout << "Как назвать новые файлы?:\n";
        std::cin >> outfile;
        DataSql testsql(theat, infile, outfile + ".sqlite");
        testsql.read(); theat = testsql.get_theat();
        DataJson testjs(theat, "", outfile + ".json");
        testjs.write(); testsql.write();
    }
    else std::cout << "Ошибка чтения файла";
}

/*
for (int i = 0; i < act_test.get_items().size(); i++){
    std::cout << act_test.get_items()[i].print_actors();
}
for (int i = 0; i < spc_test.get_items().size(); i++){
    std::cout << spc_test.get_items()[i].print_spectacle();
}
*/