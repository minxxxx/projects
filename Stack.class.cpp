#include "includes/Stack.class.hpp"
#include "includes/Process.class.hpp"
#include "includes/Exceptions.class.hpp"
#include "includes/VirtualMachine.class.hpp"
#include <stdio.h>
#include <string.h>

StackVM::StackVM(){
	// memory.reserve(1000000000);
}

// StackVM::StackVM(const StackVM &rhs) {
// 	this->_instruction = rhs.getInstruction();
// }

// StackVM& 	StackVM::operator=(const StackVM &rhs) {
// 	if (this != rhs)
// 		this->_instruction = rhs.getInstruction();
// 	return (*this);
// }

std::multimap<int, std::string>		StackVM::getInstruction() {
	return (this->_instruction);
}

int 		StackVM::read(std::string str) {
	std::ifstream	file(str, std::ios::in);
	std::string content;
	Process *toProcess;
	VirtualMachine 		*vm = new VirtualMachine;
	i32 i = 0;

	try {
		if (file) {
			i = 0;
			while (getline(file, content)) {
				if (strncmp(content.c_str(), "exit", 4) == 0)
					break ;
				toProcess = new Process(content);
				toProcess->delSpaces();
				this->storeInstructions(i, toProcess->getProcessed());
				delete(toProcess);
				i++;
			}
			file.close();
			vm->runVM(this->_instruction);
			return (0);
		} else if (!file) {
			throw "That file does not exist!";
		}
		/*
		 if (str.compare("cin") == 0) {
			while (getline(std::cin, content) && content.find(";;") != 0) {
				toProcess = new Process(content);
				toProcess->delSpaces();
				this->storeInstructions(i, toProcess->getProcessed());
				delete(toProcess);
				if (content.find("\n"))
					vm->runVM(this->_instruction);
				// this->_instruction.clear();
				i++;
				// std::cout << toProcess->getProcessed() << std::endl;
			}
			return (0);
		}
		*/
	} catch (const char* e) {
		std::cerr << "Error: " << e << std::endl;
	}
	delete (vm);
	return (1);
}

void	StackVM::storeInstructions(int line, std::string str) {
	Process *otherProcess = new Process(str);
	std::string add;
	std::string word;
	std::vector<int> location;
	int prev = 0;

	location = otherProcess->findCharLocation(location, str, ' ');
	auto found = str.find(";");
	if (found != std::string::npos) {
		word = str.c_str();
		if (strncmp(word.c_str(), ";", 1) == 0)
			this->_instruction.insert(std::pair<int, std::string>(line, str));
		else {
			for (size_t i = 0; i != location.size(); i++) {
				add = str.substr(prev, location[i] - prev);
				prev = location[i] + 1;
				if (str.find(";") != std::string::npos)
					str.erase(str.find(")") + 1);
				this->_instruction.insert(std::pair<int, std::string>(line, add));
				add.clear();
			}
		}
	} else {
		for (size_t i = 0; i != location.size(); i++) {
			add = str.substr(prev, location[i] - prev);
			prev = location[i] + 1;
			this->_instruction.insert(std::pair<int, std::string>(line, add));
			add.clear();
		}
	}
	delete (otherProcess);
}

StackVM::~StackVM(){}

/*
for (auto i = location.begin(); i != location.end(); ++i)
        		std::cout << "Location is: " << *i << std::endl;

std::multimap<int, std::string> getInstruction();
int	read(const std::string);
void  storeInstructions(int line, std::string str);
*/	
