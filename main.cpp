#include <iostream>
#include "reservoir.h"

int main() {
	std::cout << "East basin storage: " << get_east_storage("01/01/2018") << " billion gallons" << std::endl;
	std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl;
	std::cout << "East basin storage: " << get_east_storage("02/20/2018") << " billion gallons" << std::endl;

	std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
	std::cout << "MAXimum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;
  	return 0;
}
