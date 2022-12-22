#pragma once
#include <iostream>
#include <windows.h>
class Wallpaper
{
    char* wallpaperName = nullptr;
    float  wallpaperLength{ 0.0 };
    float  wallpaperWidth{ 0.0 };
    float  price{ 0.0 };

public:
    Wallpaper()
    {
        if (wallpaperName != nullptr)
        {
            delete[] wallpaperName;
        }
        char tmp[20];
        std::cout << "Enter wallpaper name: ";
        std::cin.ignore();
        std::cin.getline(tmp, 20);

        wallpaperName = new char[strlen(tmp) + 1];
        strcpy_s(wallpaperName, strlen(tmp) + 1, tmp);

        std::cout << "Enter wallpaper length: ";
        std::cin >> wallpaperLength;

        std::cout << "Enter wallpaper width: ";
        std::cin >> wallpaperWidth;

        std::cout << "Enter price per 1 wallpaper roll: ";
        std::cin >> price;
    }

    float getRollLength() { return wallpaperLength; }
    float getRollWidth() { return wallpaperWidth; }
    float getRollP() { return price; }

    void rollOutput()
    {
        std::cout << "\n"
            << "Wallpapers name:         " << wallpaperName << std::endl
            << "Length of wallpaper:     " << wallpaperLength << std::endl
            << "Width of wallpaper:      " << wallpaperWidth << std::endl
            << "Price per one roll:      " << price << std::endl;
    }

    ~Wallpaper()
    {
        if (wallpaperName != nullptr)
        {
            delete[] wallpaperName;
        }
    }
};