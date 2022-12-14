#include "reverseorder.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


void reverse_order(std::string date1, std::string date2) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.is_open()) {
        std::vector<std::string> reverselines;
        std::string line;
        while (std::getline(fin, line)) {
            reverselines.insert(reverselines.begin(), line);
        }
        reverselines.erase(reverselines.end() - 1);

        std::string filedate;
        double eastSt;
        double eastEl;
        double westSt;
        double westEl;
        bool date2found = 0;

		for (const std::string& fline : reverselines) {
            std::stringstream linestream(fline);
            linestream >> filedate >> eastSt >> eastEl >> westSt >> westEl;
            if (date2 == filedate) {
                std::cout << filedate << " " << westEl << " ft" << std::endl;
                date2found = true;
            } else if (date1 == filedate) {
                std::cout << filedate << " " << westEl << " ft" << std::endl;
                return;
            }  else if (date2found) {
                std::cout << filedate << " " << westEl << " ft" << std::endl;
            }
        }
    }
}
