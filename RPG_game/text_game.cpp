#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "Introduction\langEN.hpp"
#include "Introduction\playerPick.hpp"
#include "Main\main.hpp"
#include <ctime>
int main(){
    srand( time( NULL ) );
    en menuEN;
    chooseClass player;
    village move;
    system("cls");
    std::cout << "\n----------------------WELCOME TO TEXT GAME----------------------\n";
    menuEN.introducitonEN(); // intro
    player.getClass(); // player choose class

    move.dialog(); // first dialog
    move.movePlayer(); // first and second chapter
    ////////////////////////////////////////////////////////////////////////////////////
    move.HUD();
    move.actionForest();
}
