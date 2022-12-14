#include "reservoir.h"
#include <iostream>
#include <fstream>
#include <climits>
#include <cfloat>

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
			fin.close();
			return eastSt;
		}
	}

	return 0.0;
}

double get_min_east() {
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
	double minStorage = DBL_MAX;
	while(fin >> filedate >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (minStorage > eastSt) {
			minStorage = eastSt;
		}
	}
	fin.close();
	return minStorage;
}

double get_max_east() {
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
	double maxStorage = -DBL_MAX;
	while(fin >> filedate >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (maxStorage < eastSt) {
			maxStorage = eastSt;
		}
	}
	fin.close();
	return maxStorage;
}

std::string compare_basins(std::string date) {
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
		if (date.compare(filedate) == 0) {
			if (eastSt > westSt) {
				return "East";
			} else if (westSt > eastSt) {
				return "West";
			} else {
				return "Equal";
			}
		}
	}
	return "Not found";
}


