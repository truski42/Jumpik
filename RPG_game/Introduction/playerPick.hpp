#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "class.hpp"
int playerSelect;
class chooseClass
{
public:
    bool isWarrior = false;
    bool isMage = false;
    void getClass(){
        Warrior statsW;
        Mage statsM;
        Hero *info;
        do{
            std::cout << "\nWhats your class?"; // choosing class
            std::cout << "\n[1]. Warrior [2]. Mage";
            std::cout << "\nChoose a class: ";
            std::cin >> playerSelect;
            
        
                if(playerSelect == 1){
                    system("cls");
                    std::cout << "You choose a Warrior" << std::endl;
                    info = &statsW;
                    info -> currentStats();
                    Sleep(3000);
                }else if (playerSelect == 2){
                    system("cls");
                    std::cout << "You choose a Mage" << std::endl;
                    info = &statsM;
                    info -> currentStats();
                    Sleep(3000);
                } else{
                    std::cout << "\nPress either '1' or '2', nothing else!";
                }
        }while(playerSelect != 1 && playerSelect != 2);
    }
};