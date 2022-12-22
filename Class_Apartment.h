#pragma once
#include"Class_Room.h"

class Apartment
{
    Room* rooms = nullptr;
    int roomsAmount = 0;

public:
    Apartment(int count) : rooms{ new Room[count] {} }, roomsAmount{ count } {}
    float getPrice()
    {
        float totalCost = 0;

        for (int i = 0; i < roomsAmount; ++i)
        {
            totalCost += rooms[i].priceCalculation();
        }
        return totalCost;
    }

    void flatOutput()
    {
        for (int i = 0; i < roomsAmount; ++i)
        {
            std::cout << "Room: " << i + 1 << "\n";
            rooms[i].Output();
        }
        std::cout << std::endl;
    }

    ~Apartment()
    {
        delete[] rooms;
    }
};
