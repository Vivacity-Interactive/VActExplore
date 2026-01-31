#include <iostream>

int main(int argc, char* argv[])
{
	std::string greeting = "World";
	if (argc >= 2) { greeting = argv[1]; }
    std::cout << "Hello, " << greeting << "!\n";
}