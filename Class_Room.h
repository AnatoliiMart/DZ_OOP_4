#pragma once
#include"Class_Wallpaper.h"

class Room
{
    char* roomName = nullptr;
    float roomLength = 0;
    float roomWidth = 0;
    float roomHeight = 0;
    bool roomCeil = 0;
    Wallpaper* roll = nullptr;

public:

    Room()
    {
        char tmp[20];
        std::cout << "\nEnter room name: ";
        std::cin.ignore();
        std::cin.getline(tmp, 20);
        SelectRName(tmp);

        std::cout << "Enter room length: ";
        std::cin >> roomLength;

        std::cout << "Enter room width: ";
        std::cin >> roomWidth;

        std::cout << "Enter room heigth: ";
        std::cin >> roomHeight;

        std::cout << "Glue the ceiling: 1 - Yes / 0 - No ";
        std::cin >> roomCeil;
        std::cout << std::endl;

        roll = new Wallpaper[1]{};
    }

    void SelectRName(const char* name)
    {
        roomName = new char[strlen(name) + 1];
        strcpy_s(roomName, strlen(name) + 1, name);
    }
    void Output()
    {
        std::cout << "\n"
            << "Room name:           " << roomName << "\n"
            << "Length of the room:  " << roomLength << "\n"
            << "Width of the room:   " << roomWidth << "\n"
            << "Heigth of the room:  " << roomHeight << "\n"
            << "Glue the ceiling:    " << ((roomCeil) ? "Yes" : "No") << std::endl;
        roll[0].rollOutput();
    }
    float priceCalculation()
    {
        float perimeter;
        float stripsAmount;
        float stripsInRoll;
        float rollAmountForRoom;
        float rollAmountForCeil;

        perimeter = 2 * (roomLength + roomWidth);

        stripsAmount = perimeter / roll->getRollWidth();

        stripsInRoll = roll->getRollLength() / roomHeight;

        rollAmountForRoom = stripsAmount / stripsInRoll;

        rollAmountForCeil = (roomWidth / roll->getRollWidth()) / (roll->getRollLength() / roomLength);

        if (roomCeil)
        {
            return roll->getRollP() * (rollAmountForRoom + rollAmountForCeil);
        }
        else
        {
            return roll->getRollP() * rollAmountForRoom;
        }
    }
    ~Room()
    {
        if (roomName != nullptr)
        {
            delete[] roomName;
        }

        delete[] roll;
    }
};
