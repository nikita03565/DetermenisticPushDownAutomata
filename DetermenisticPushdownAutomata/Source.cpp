#include "DPDA.h"
#include <iostream>
#include <string>
int main()
{
    DPDA dpda;
    std::string input;
    while (true)
    {
        std::cout << "input string:\n";
        std::cin >> input;
        dpda.check(input);
    }
    system("pause");
    return 0;
}
