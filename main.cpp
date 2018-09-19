#include "includes/Stack.class.hpp"
#include "includes/Process.class.hpp"
#include <iostream>
#include <vector>

int		main(int argc, char const *argv[])
{
		StackVM vm;

		if (argc == 2) {
			std::string fle = argv[1];
			vm.read(fle);
		}

	// std::vector<char> path;

	// for ()

	/*
	std::vector<char> path;
	// ...
	for (std::vector<char>::const_iterator i = path.begin(); i != path.end(); ++i)
    	std::cout << *i << ' ';
	
	if (argc < 2) {
		std::cout << "An error occured, usage: " << argv[0] << " || " << argv[0] << " + <filename>" << std::endl;
		return (0);
	} else
	*/

	return 0;
}
