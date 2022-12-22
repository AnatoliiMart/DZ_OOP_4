#include "Header.h"

void main()
{
    std::cout << "Wallpaper price" << std::endl;
    
    std::cout << "Enter amount of rooms: ";
    int count;
    std::cin  >> count;

    Apartment apt(count);
    apt.flatOutput();

    std::cout << "Total wallpaper cost - " << apt.getPrice() << " money to the sky :)" << std::endl;
}