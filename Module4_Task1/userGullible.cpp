#include <iostream>
//Task1:

int main()
{
    int num;
    int counter = 10;
    do
    {
        std::cout << "Enter any number other than 5: ";
        std::cin >> num;
        counter--;

        if (num == 5)
        {
            std::cout << "Hey you weren't supposed to enter 5!" << std::endl;
            break;
        }
    } 
    while (counter != 0);

    if (counter == 0)
    {
        std::cout << "Wow, you're more patient than I am, you win." << std::endl;
    }

    return 0;
}
