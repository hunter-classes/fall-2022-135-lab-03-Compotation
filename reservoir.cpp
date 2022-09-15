#include "reservoir.h"
#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>

double get_east_storage(std::string date) {
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
    		exit(1); // exit if failed to open the file
	}
	
	std::string junk;
	std::getline(fin, junk);

	std::string filedate;
	double eastSt;
	double eastEl;
	double westSt;
	double westEl;
	while(fin >> filedate >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (date.compare(filedate) == 0) {
			std::cout << "East basin storage: " << eastSt << " billion gallons" << std::endl;
		}
	}

	fin.close();
	return 0.0;
}
