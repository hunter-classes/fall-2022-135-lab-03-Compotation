#include <iostream>
#include "reservoir.h"

int main() {
	get_east_storage("01/01/2018");
	get_east_storage("05/20/2018");
	get_east_storage("02/20/2018");

	std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  	return 0;
}
