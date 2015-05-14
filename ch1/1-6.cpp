#include <iostream>
#include <string>

int main()
{
    std::cout << "what is your name? ";
    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name
        << std::endl << "Amd what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
        << "; nice to meet you too!" << std::endl;

    return 0;
}
