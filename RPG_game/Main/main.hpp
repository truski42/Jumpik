#pragma once
#ifndef MAIN_HPP_
#define LANGEN_HPP_
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include "..\Introduction\langEN.hpp"
#include "..\Introduction\class.hpp"
void dialog();
void movePlayer();
void walk();
void goinTavern();
void tavern();
void tavernMenu();
void blacksmith();
void blacksmithMenu();
void town_hall();
void HUD();
void witch();
void forest();
class village{
    public:
    int choice, witchChoice;
    Hero *infoHP;
    Warrior statsW;
    Mage statsM;
///////////////////////////////////////////////
// OTHER STUFF // 
    void witch(){ // potions for second chapter
    system("cls");
    std::cout << "# After a few minutes you spot a store and enter it" << std::endl;
    std::cout << "Hello young man, what for you ?" << std::endl;
    std::cout << "[1]. Show me your stuff." << std::endl;
    std::cout << "[2]. Exit" << std::endl;
    retry:
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    if(choice == 1){
        if(playerSelect == 1){
            infoHP ->addPotion();
            std::cout << "Thanks for your purchase" << std::endl;
            std::cout << "# You leave the store";
            Sleep(2000);
            walk();
            forest();
            }else if (playerSelect == 2){
            infoHP ->addPotion();
            std::cout << "Thanks for your purchase";
            std::cout << "# You leave the store";
            Sleep(2000);
            walk();
            forest();
            }
    } else if(choice == 2){
        std::cout << "# You leave the store";
        walk();
        forest();
    } else {
        std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
		goto retry;
    }
    system("pause>0");
    }
///////////////////////////////////////////////
// INTRO //
    void dialog(){ // FIRST DIALOG
        Sleep(2000);
        system("cls");
        std::cout << "# Mayor: Hi " << name << ". What brings you to our village ?" << std::endl;
        do{
        std::cout << "\t >> [1]. I was looking for new adventures and new assignments. [+1 moral]" << std::endl;
        std::cout << "\t >> [2]. What do you care. [-1 moral]" << std::endl;
        std::cout << "\nMake your choice: "; // Making choice for 
        std::cin >> choice;
        if(playerSelect == 1){
            if(choice == 1){
			infoHP = &statsW;
            std::cout << "Mayor: Thank you for being so brave and being able to help us. " <<  std::endl;
            infoHP ->addmoral();
            } else if(choice == 2){
            infoHP = &statsW;
            std::cout << "Mayor: Thanks, my lord, for your kindness.... " << std::endl;
            infoHP ->minusmoral();
            } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
            }
        } else if (playerSelect == 2){
            if(choice == 1){
            infoHP = &statsM;
            std::cout << "Mayor: Thank you for being so brave and being able to help us. " << std::endl;
			infoHP ->addmoral();
            } else if(choice == 2){
            infoHP = &statsM;
            std::cout << "Mayor: Thanks, my lord, for your kindness.... " << std::endl;
			infoHP ->minusmoral();
            } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
            }
        }
	}while(choice == 1 && choice ==2);
            std::cout << "\n----------------------Press any key to move on----------------------" << std::endl;
            _getch();
    }
    void movePlayer(){ // here we are doing first chapter decision
    system("cls");
	int choiceOne_Path;
	std::cout << "Narrator: What would you like to do?" << std::endl;
	std::cout << "\t >> Enter '1' to follow the mayor to city hall. [MAIN PLOT]" << std::endl;
	std::cout << "\t >> Enter '2' to look around the village on your own. [SIDE PLOT]" << std::endl;
	retry:
	std::cout << "\nEnter your choice: ";
	std::cin >> choiceOne_Path;
	if(choiceOne_Path == 1)
	{
		std::cout << "\n# You run behind the mayor." << std::endl;
		std::cout << "\nYou: Why are you leading me to city hall??" << std::endl;
		std::cout << "Mayor: Soon you will know. Just follow me." << std::endl;
		town_hall();
	}
	else if(choiceOne_Path == 2)
	{
		system("cls");
		std::cout << "Walking." << std::endl;
		Sleep(1000);
		system("cls");
		std::cout << "Walking.." << std::endl;
		Sleep(1000);
		system("cls");
		std::cout << "Walking..." << std::endl;
		Sleep(1000);
		goinTavern();
	}
	else
	{
		std::cout << "You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
		goto retry;
	}
    }
    void walk(){// walking
        system("cls");
		std::cout << "Walking." << std::endl;
		Sleep(500);
		system("cls");
		std::cout << "Walking.." << std::endl;
		Sleep(500);
		system("cls");
		std::cout << "Walking..." << std::endl;
		Sleep(500);
    }
    void search(){// exploring
        system("cls");
		std::cout << "Searching." << std::endl;
		Sleep(500);
		system("cls");
		std::cout << "Searching.." << std::endl;
		Sleep(500);
		system("cls");
		std::cout << "Searching..." << std::endl;
		Sleep(500);
    }
// START CHAPTER ONE //
	void goinTavern(){ // option for go in
        std::cout << "You came across a tavern\n";
		char choiceGo_In;
		std::cout << "Narrator: Do you want to go inside, enter 'y' or 'n'" << std::endl;
		retry:
		std::cout << "[1]. Yes" << std::endl;
		std::cout << "[2]. No" << std::endl;
		std::cout << "\nEnter your choice: ";
		std::cin >> choiceGo_In;
		if(choiceGo_In == 'y' || choiceGo_In == 'Y'){
			tavern();
		} else if (choiceGo_In == 'n' || choiceGo_In == 'N'){
			blacksmith();
		}else{
			std::cout << "Narrator: You are doing it wrong, warrior! Press either 'y' or 'n', nothing else!" << std::endl;
			goto retry;
		}
	}
    void tavern(){ //action in tavern
        system("cls");
        std::cout << "Narrator: You slowly enter the tavern..." << std::endl;
        Sleep(2000);
        std::cout << "Narrator: The locals immediately notice that you are a stranger and direct their attention to you. " << std::endl;
        Sleep(4000);
        std::cout << "Narrator: Behind the counter is a barman." << std::endl;
        Sleep(2000);
        std::cout << "\nBarman: Hey " << name << " what to get you ?" << std::endl;
        Sleep(3000);
        std::cout << "You: Does everyone in this village already know who I am!?" << std::endl;
        Sleep(3000);
        std::cout << "Barman: Why are you so hotheaded ?\n" << std::endl;
        Sleep(2000);
        tavernMenu();
        }
    void tavernMenu(){// menu tavern
        std::cout << "Barman: Doesn't matter what I give you ?" << std::endl;
        std::cout << "[1]. Beer, please." << std::endl;
        std::cout << "[2]. Tell me a little about your village." << std::endl;
        std::cout << "[3]. Exit" << std::endl;
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        if(choice == 1){
            system("cls");
            std::cout << "Narrator: The bartender hands you a beer, you drink it right away." << std::endl;
            Sleep(3000);
            std::cout << "Narrator: You like the local beer so much that you buy three more." << std::endl;
            Sleep(3000);
            std::cout << "Narrator: After a few beers you are already drunk and get into a fight." << std::endl;
            Sleep(3000);
            std::cout << "Narrator: You were not able to fight and you lose one hp" << std::endl;
            if(playerSelect == 1){
                infoHP = &statsW;
                infoHP ->losehp();
                Sleep(2000);
            }else if (playerSelect == 2){
                infoHP = &statsM;
                infoHP ->losehp();
            }
            std::cout << "\n# They throw you out of the tavern";
            Sleep(3000);
            walk();
            std::cout << "You came across the local blacksmith\n";
            blacksmith();
        } else if (choice == 2){
            system("cls");
            Sleep(1000);
            std::cout << "Barman: I know as much as my parents told me, but Leo has been in charge here since I was a kid, I don't know how old this guy is anymore." << std::endl;
            Sleep(4000);
            std::cout << "Barman: There's been better years where we've had plenty, and there's been years like this where we can barely get by." << std::endl;
            Sleep(4000);
            std::cout << "Barman: We don't know if it's because of him, but maybe you can help him." << std::endl;
            Sleep(4000);
            std::cout << "You: How am I supposed to help him?" << std::endl;
            Sleep(4000);
            std::cout << "Barman: You'll have to talk to Leo.\n" << std::endl;
            tavernMenu();
        } else if(choice == 3){
            std::cout << "# You leave the tavern";
            Sleep(2000);
            walk();
            std::cout << "You came across the local blacksmith\n";
            blacksmith();              
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }        
        }
    void blacksmith(){ //blacksmith action
        Sleep(2000);
        system("cls");
        std::cout << "Blacksmith: Hello " << name << " what brings you to me ?" << std::endl;
        Sleep(4000);
        std::cout << "You: How do you know who I am ?" << std::endl;
        Sleep(4000);
        std::cout << "Blacksmith: It's rare for a new face to show up here and our ladies have already started gossiping about the newcomer." << std::endl;
        Sleep(4000);
        /*if(playerSelect == 1){
                infoHP = &statsW;
                infoHP ->currentStats();
                Sleep(2000);
        }else if (playerSelect == 2){
                infoHP = &statsM;
                infoHP ->currentStats();
        }*/
        Sleep(2000);
        blacksmithMenu();        
        }
    void blacksmithMenu(){ // blacksmith menu
        std::cout << "Blacksmith: What checks you into my humble props ?" << std::endl;        
        std::cout << "[1]. Show me your stuff." << std::endl;
        std::cout << "[2]. Tell me a little about your village." << std::endl;
        std::cout << "[3]. Exit" << std::endl;
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        if(choice == 1){
            if(playerSelect == 1){
                system("cls");
                std::cout << "[1]. Long sword [+1 strenght, -1 coin]" << std::endl;
                std::cout << "[2]. Plate armor [+5 health, -2 coin]" << std::endl;
                std::cout << "[3]. Light boots [+1 agility, -1 coin]" << std::endl;
                infoHP ->addStats();
                std::cout << "# You leave the blacksmith";
                Sleep(4000);
                walk();
                town_hall();
            } else if(playerSelect == 2){
                system("cls");
                std::cout << "[1]. Staff [+1 inteligence, -1 coin]" << std::endl;
                std::cout << "[2]. Magic robe [+5 health, -2 coin]" << std::endl;
                std::cout << "[3]. Ring [+1 mana, -1 coin]" << std::endl;
                infoHP ->addStats();
                std::cout << "# You leave the blacksmith";
                Sleep(4000);
                walk();
                town_hall();
            }
        } else if (choice == 2){
            system("cls");
            Sleep(1000);
            std::cout << "Barman: I know as much as my parents told me, but Leo has been in charge here since I was a kid, I don't know how old this guy is anymore." << std::endl;
            Sleep(4000);
            std::cout << "Barman: There's been better years where we've had plenty, and there's been years like this where we can barely get by." << std::endl;
            Sleep(4000);
            std::cout << "Barman: We don't know if it's because of him, but maybe you can help him." << std::endl;
            Sleep(4000);
            std::cout << "You: How am I supposed to help him?" << std::endl;
            Sleep(4000);
            std::cout << "Barman: You'll have to talk to Leo.\n" << std::endl;
            blacksmithMenu();
        } else if(choice == 3){
            std::cout << "# You leave the blacksmith";
            Sleep(2000);
            walk();
        } 
        else {
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;           
        }
    }
// END CHAPTER ONE //
///////////////////////////////////////////////
// STATR CHAPTER TWO //
    void town_hall(){ // action in town_hall
        system("cls");
        std::cout << "# After a few minutes, you finally arrived at the town hall." << std::endl;
        std::cout << "\nMayor: Well, " << name << " I have a very important matter for you." << std::endl;
        Sleep(4000);
        std::cout << "You: What's the matter ?" << std::endl;
        std::cout << "Mayor: Namely, from time to time we are attacked by monsters from the nearby forest," << std::endl;
        std::cout << "with difficulty we managed to repel the previous attack" << std::endl;
        std::cout << "You: Okey, I think I know what you're getting at. " << std::endl;
        std::cout << "Mayor: Are you able to help us deal with the monsters ?" << std::endl;
        std::cout << "Mayor: Of course you'll get a good reward." << std::endl;

        std::cout << "\n[1]. Sure, I'd love to help you. [+1 moral]" << std::endl;
        std::cout << "[2]. Nah, now that I'm here, let's go. [-1 moral]" << std::endl;
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        if(playerSelect == 1){
            if(choice == 1){
            infoHP = &statsW;
            std::cout << "Mayor: Thank you for being so brave and being able to help us. " << std::endl;
            infoHP ->addmoral();
            } else if(choice == 2){
            infoHP = &statsW;
            std::cout << "Mayor: Thanks, my lord, for your kindness.... " << std::endl;
            infoHP ->minusmoral();
            } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
			goto retry;
            }
        } else if (playerSelect == 2){
            if(choice == 1){
            infoHP = &statsM;
            std::cout << "Mayor: Thank you for being so brave and being able to help us. " << std::endl;
            infoHP ->addmoral();
            } else if(choice == 2){
            infoHP = &statsM;
            std::cout << "Mayor: Thanks, my lord, for your kindness.... " << std::endl;
            infoHP ->minusmoral();
            } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
			goto retry;
            }
        }
        std::cout << "\n----------------------Press any key to move on----------------------" << std::endl;
        _getch();
        system("cls");
        do{ // go to forest or witch
        std::cout << "\nMayor: So what's your plan now ?" << std::endl;
        std::cout << "[1]. I'm going to go fight monsters immediately." << std::endl;
        std::cout << "[2]. I'm going to go look around for more potions." << std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        if(choice == 1){
            std::cout << "Mayor: Fantastic, hope it goes well with them.";
            walk();
        } else if(choice == 2){
            std::cout << "Mayor: Of course, we have one witch here, she has a store near the town hall.";
            walk();
            witch();
        } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl;
        }
        }while(choice != 1 && choice != 2);
    }
    void forest(){
        system("cls");
        std::cout << "# You leave the village" << std::endl;
        Sleep(2000);
        std::cout << "# After a few hours you get to the place Leo showed you on the map" << std::endl;
        Sleep(2000);
        std::cout << "# You set up camp and go for a short nap" << std::endl;
        Sleep(2000);
        std::cout << "# Suddenly you are awakened by an unfamiliar sound" << std::endl;
        Sleep(2000);
        std::cout << "You: Fuck, they won't even let you rest" << std::endl;
        Sleep(3000);
        std::cout << "\n----------------------Press any key to move on----------------------" << std::endl;
        _getch();
    }
    void HUD(){
        system("cls");
        if(playerSelect == 1){
            infoHP ->HUD();
        } else if(playerSelect == 2){
            infoHP ->HUD();
        }
    }
    void actionForest(){
        forest();
        if(playerSelect == 1){
            infoHP ->actionForest();
        } else if(playerSelect == 2){
            infoHP ->actionForest();
        }
    }
//////////////////////////////////////////////
};
#endif