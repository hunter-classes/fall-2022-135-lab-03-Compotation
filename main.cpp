#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main() {
	std::cout << "East basin storage: " << get_east_storage("01/01/2018") << " billion gallons" << std::endl;
	std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl;
	std::cout << "East basin storage: " << get_east_storage("02/20/2018") << " billion gallons" << std::endl << std::endl;

	std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
	std::cout << "MAXimum storage in East basin: " << get_max_east() << " billion gallons" << std::endl << std::endl;

	std::cout << "09/13/2018 " << compare_basins("09/13/2018") << std::endl;
	std::cout << "09/14/2018 " << compare_basins("09/13/2018") << std::endl;
	std::cout << "01/14/2018 " << compare_basins("09/13/2018") << std::endl;

	reverse_order("01/01/2018", "03/01/2018");
    std::cout << std::endl << std::endl;
    reverse_order("05/01/2018", "08/25/2018");
    std::cout << std::endl << std::endl << "done" << std::endl;
    // line below isn't working properly starts at 12/30/2018 and ends 1/02/2018
    reverse_order("01/02/2018", "01/05/2018");
    std::cout << std::endl << std::endl;


    return 0;
}
