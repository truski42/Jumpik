#pragma once
#ifndef CLASS_HPP_
#define CLASS_HPP_
#include <iostream>
#include "playerPick.hpp"
#include <math.h>
#include <fstream>

class Hero{
    public:
    std::string monsterName [5] = { "Witch", "Werewolf", "Goblin", "Centaur", "Dwarf"};
    int currentMonsterNames = 5;
    std::string currentMonster = " ";
    bool isLevel = true;
    int shopChoice, coins, choice, potion, totalPotion, monsterHP, monsterLevel, monsterXP;
    virtual void addStats() = 0;
    virtual void losehp() = 0;
    virtual void currentStats() = 0;    
    virtual void addmoral() = 0;
    virtual void minusmoral() = 0;
    virtual void addPotion() = 0;
    virtual void HUD() = 0;
    virtual void actionForest() = 0;
    virtual void CreateMonster() = 0;
    virtual void Combat() = 0;
    virtual void CombatHUD() = 0;
    virtual void LevelUP() = 0;
    virtual void Trader() = 0;
    virtual void maxHP() = 0;
};
class Warrior: public Hero{
    public:
    // SAVE and Load
    void saveload(){
    std::string sss;
    std::cout << "Welcome to the program!\n" <<std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "| save - Save to a file   |" << std::endl;
    std::cout << "| load - Load from a file |" << std::endl;
    std::cout << "---------------------------\n" << std::endl;
    getline(std::cin, sss);

     if(sss == "load") {

          std::ifstream loadFile;

          loadFile.open ("Save.txt", std::ifstream::in);

          std::cout << "The file contained: ";
          
          while (loadFile.good()){
                
               std::cout << (char) loadFile.get();

          }
          
          std::cout << "" << std::endl;
          
    loadFile.close();
  
     }
          
     if (sss == "save") {
     
       std::string textToSave;
       std::cout << "Enter the string you want saved: " << std::endl;
        getline(std::cin, textToSave);

       std::ofstream saveFile ("Save.txt");

       saveFile << textToSave;

       saveFile.close();    
              
     }
}
    // STATS
    int hp = 100, strenght = 7, agility = 5, coins = 10, moral = 0, totalMoral = moral, smallPotion = 0, middPotion = 0, bigPotion = 0, totalHP = hp, temp, trader;
    // LVL, XP etc
    int level = 1, maxHealth = totalHP, heal = 0;
    
    int current_xp = 0, base_xp = 83, xp_to_level = base_xp, minLevel = 1, maxLevel = 20;
    /*std::string zmiana() const{
        return 
        std::to_string(strenght) + " "
        + name + " "
        + std::to_string(level) + " "
        + std::to_string(current_xp) + " "
        + std::to_string(xp_to_level) + " "
        + std::to_string(totalHP) + " "
        + std::to_string(coins) + " "
        + std::to_string(agility) + " ";
    }*/
    virtual void maxHP(){
    }
    virtual void currentStats(){ // info about stats
        std::cout << "Health: " << totalHP << std::endl;
        std::cout << "Strenght: " << strenght << std::endl;
        std::cout << "Agility: " << agility << std::endl;
        std::cout << "Coins: " << coins << "         Moral: " << totalMoral << std::endl;
    }
    virtual void losehp(){ // losing hp
        totalHP = totalHP - 5;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
    virtual void addStats(){ // adding stats from buying items in blacksmith
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> shopChoice;
        if(shopChoice == 1){
            coins = coins - 1;
            strenght = strenght + 1;
            std::cout << "Narrator: You have purchased a long sword which gives you +1 to strength" << std::endl;
            std::cout << "Narrator: Your current strenght is: " << strenght << " your coins: " << coins << std::endl;
        } else if (shopChoice == 2){
            coins = coins - 2;
            totalHP = totalHP + 5;
            std::cout << "Narrator: You have purchased a Plate armor which gives you +5 to health" << std::endl;
            std::cout << "Narrator: Your current hp is: " << totalHP << " your coins: " << coins << std::endl;      
        } else if(shopChoice == 3){
            coins = coins - 1;
            agility = agility + 1;
            std::cout << "Narrator: You have purchased a Light boots which gives you +1 to agility" << std::endl;
            std::cout << "Narrator: Your current hp is: " << agility << " your coins: " << coins <<std::endl;
        } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }
    }
    virtual void addmoral(){ // adding 1 point of moral
        totalMoral = totalMoral + 1;
        std::cout << "# Moral is: " << totalMoral << std::endl;
    }
    virtual void minusmoral(){ // minus 1 point of moral
        totalMoral = totalMoral - 1;
        std::cout << "# Moral is: " << totalMoral << std::endl;
    }
    virtual void addPotion(){ // adding 1 bottle of potion 
        retry:
        std::cout << "[1]. Small HP bottle [+5 HP, -1 coin]" << std::endl;
        std::cout << "[2]. Medium HP bottle [+10 HP, -3 coin]" << std::endl;
        std::cout << "[3]. Big HP bottle [+15 HP, -5 coin]" << std::endl;
        std::cin >> choice;
        if(choice == 1){
            smallPotion = smallPotion + 1;
            coins = coins - 1;
            std::cout << "You have " << smallPotion << " small bottle" << std::endl;
        }else if(choice == 2){
            middPotion = middPotion + 1;
            coins = coins - 3;            
            std::cout << "You have " << middPotion << " medium bottle"<< std::endl;
        }else if(choice == 3){
            coins = coins - 5;
            bigPotion = bigPotion + 1;
            std::cout << "You have " << bigPotion << " big bottle"<< std::endl;
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl; 
            goto retry;
        }
    }
////////////////////////////////////////////////////////////////////////////////
                            //CHAPTER FOREST//
    virtual void HUD(){ // HUD player in forest
        std::cout << "Name: " << name << "              |Health: " << totalHP << std::endl;
        std::cout << "Level: " << level << "                  |Coins: " << coins << std::endl;
        std::cout << "XP: " << current_xp << "                     |Strenght: " << strenght << std::endl;
        std::cout << "XP to level up: " << xp_to_level << "        |Agility: " << agility << std::endl;
        actionForest();
    }
    virtual void CombatHUD(){
        Sleep(500);
        system("cls");
        std::cout << "Name: " << name << "          |           Monster Name: " << currentMonster << "\nHealth: " << totalHP << "           |            Monster Health: " <<
            monsterHP << "\nLevel: " << level << "              |             Monster Level: " << monsterLevel << std::endl;
    }
    virtual void Combat(){

        CombatHUD();
        int playerAttack;
        int playerDamage = strenght;
        int monsterAttack = 6 * monsterLevel / 2;
        int monsterCoins = rand() % monsterLevel;

        if(totalHP >= 1 && monsterHP >= 1){
            std::cout << "\n";
            std::cout << "[1]. Attack\n";
            //std::cout << "[2]. Block\n";
            std::cout << "[2]. Inventory\n";            
            std::cout << "[3]. RUN!\n";
            std::cout << "\n";
            std::cin >> playerAttack;

            if(playerAttack == 1){//ATTACK
                std::cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << std::endl;
                monsterHP = monsterHP - playerDamage;
                Sleep(2000);
                CombatHUD();
                    if(monsterHP >= 1){
                        std::cout << "\n";
                        std::cout << "Monster is Attacking...\n";
                        totalHP = totalHP - monsterAttack;
                        std::cout << "You suffered " << monsterAttack << " hp " << totalHP << std::endl;
                        //change to fuction
                        if(totalHP <= 0){
                            totalHP = 0;
                            system("cls");
                            std::cout << "You died! \nYou were level: " << level << " you got killed by " << currentMonster << std::endl;
                            Sleep(2000);
                            exit(0);                            
                        }
                    } else if (monsterHP <= 0){
                        monsterHP = 0;
                        std::cout << "\n";
                        std::cout << "You Defeated " << currentMonster << " you are rewarded with " << monsterXP << " xp.\nWell Done!\n";
                        coins += monsterCoins;
                        std::cout << "In dead body you find " << monsterCoins << " coin now you have " << coins << " coins\n";
                        
                        if(level != maxLevel){
                            current_xp += monsterXP;
                            LevelUP();
                        }
                        system("cls");
                        Sleep(2000);   
                        HUD();                      
                    }
                    Sleep(2000);
                    Combat();
            } else if(playerAttack == 2){//BLOCK
               /* std::cout << "Blocking\n";
                int i = rand() % 100 + 1;
                if(i >= 50){
                    std::cout << i;
                    std::cout << "You Blocked the incoming attack\n";
                    heal = level * 10 / 2;
                    std::cout << "You have been Healed for " << heal << std::endl;
                    totalHP += heal;
                    Sleep(1000);
                    Combat();

                }else {
                    std::cout << "You failed to block the savage attack\n";
                    totalHP -= monsterAttack;
                    std::cout << "You were stabbed in the back for " << monsterAttack << " current hp " << totalHP << std::endl;
                    Sleep(1000);
                    Combat(); 
                }
                */
               system("cls");
               retry:
                std::cout << "[1]. Small potions [+ 5 hp] " << smallPotion << std::endl;
                std::cout << "[2]. Medium potions [+ 10 hp] " << middPotion << std::endl;
                std::cout << "[3]. Big potions [+ 15 hp] " << bigPotion << std::endl;  
                std::cout << "[4]. Exit" << std::endl;
                std::cout << "Use: ";
                std::cin >> choice;
                if(choice == 1){
                    if(smallPotion == 0){
                        std::cout << "# You don't have any Small potions! Try Again!" << std::endl;
                        goto retry;
                    }else if(smallPotion > 0){
                        smallPotion -= 1;
                        totalHP += 5;
                        std::cout << "# You drink a potion, your HP now is " << totalHP << std::endl;
                        goto retry;                        
                    }
                } else if(choice == 2){
                    if(middPotion == 0){
                        std::cout << "# You don't have any Medium potions! Try Again!" << std::endl;
                        goto retry;
                    }else if(middPotion > 0){
                        middPotion-= 1;
                        totalHP += 10;
                        std::cout << "# You drink a potion, your HP now is " << totalHP << std::endl;
                        goto retry;
                    }
                } else if(choice == 3){
                    if(bigPotion == 0){
                        std::cout << "# You don't have any Big potions! Try Again!" << std::endl;
                        goto retry;
                    }else if(bigPotion > 0){
                        bigPotion-= 1;
                        totalHP += 15;
                        std::cout << "# You drink a potion, your HP now is " << totalHP << std::endl;
                        goto retry;                        
                    }
                } else if(choice == 4){
                    Combat();
                }
                else{
                    std::cout << "Invalid number! Try again!" << std::endl;
                    goto retry;
                }              
            } else if(playerAttack == 3){//RUN
                std::cout << "You try to run\n";
                int x = rand() % 100 + 1;
                if(x >= 50){
                    std::cout << "You run away\n";
                    HUD();
                } else {
                    if(totalHP <= 0){
                        totalHP = 0;
                        system("cls");
                        std::cout << "You died! \nYou were level: " << level << " you got killed by " << currentMonster << std::endl;
                        Sleep(2000);
                        exit(0);                            
                    }
                    std::cout << "You failed to run away\n";
                    std::cout << "Monster does a savage attack on you!\n";
                    totalHP -= monsterAttack + 10;
                    std::cout << "You suffered " << monsterAttack + 10 << " Your current Health is " << totalHP << std::endl;
                    Sleep(1000);
                    Combat();
                }
            }else{
                std::cout << "Invalid number";
                Sleep(500);
                Combat();
            }
        }
    }    
    virtual void actionForest(){ // Searching for monsters in forest
        while(isLevel){
            if(level == 20){
            isLevel = false;
                std::cout << "you pass the game thx for playing";
                Sleep(2000);
                exit(0);
                }
        std::cout << "[1]. Searching the front area" << std::endl;
        std::cout << "[2]. Rest" << std::endl;
        std::cout << "[3]. Searching the backwards area";
        std::cout << "\n\n";

        std::cin >> choice;
        if(choice == 1){
            std::cout << "# You begin search forward...\n";  
            Trader();
            temp = rand() % 100 + 1; 
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        } else if(choice == 2){
            std::cout << "You want to set up camp for the evening\n";
            if(totalHP <= 99)
            {
                totalHP += 10 * level;
                if(level == 1)
                {
                    totalHP = 100;
                    maxHealth = totalHP;
                }else if(level == 2)
                {
                    totalHP = 120;
                    maxHealth = totalHP;
                }
                else if(level == 3)
                {
                    totalHP = 140;
                    maxHealth = totalHP;
                }
                else if(level == 4)
                {
                    totalHP = 160;
                    maxHealth = totalHP;
                }
                else if(level == 5)
                {
                    totalHP = 180;
                    maxHealth = totalHP;
                }
                else if(level == 6)
                {
                    totalHP = 200;
                    maxHealth = totalHP;
                }
                else if(level == 7)
                {
                    totalHP = 220;
                    maxHealth = totalHP;
                }
                else if(level == 8)
                {
                    totalHP = 240;
                    maxHealth = totalHP;
                }
                else if(level == 9)
                {
                    totalHP = 260;
                    maxHealth = totalHP;
                }
                else if(level == 10)
                {
                    totalHP = 280;
                    maxHealth = totalHP;
                }
                else if(level == 11)
                {
                    totalHP = 300;
                    maxHealth = totalHP;
                }
                else if(level == 12)
                {
                    totalHP = 320;
                    maxHealth = totalHP;
                }
                else if(level == 13)
                {
                    totalHP = 340;
                    maxHealth = totalHP;
                }
                else if(level == 14)
                {
                    totalHP = 360;
                    maxHealth = totalHP;
                }
                else if(level == 15)
                {
                    totalHP = 380;
                    maxHealth = totalHP;
                }
                else if(level == 16)
                {
                    totalHP = 400;
                    maxHealth = totalHP;
                }
                else if(level == 17)
                {
                    totalHP = 420;
                    maxHealth = totalHP;
                }
                else if(level == 18)
                {
                    totalHP = 440;
                    maxHealth = totalHP;
                }
                else if(level == 19)
                {
                    totalHP = 460;
                    maxHealth = totalHP;
                }
                else if(level == 20)
                {
                    totalHP = 480;
                    maxHealth = totalHP;
                }
        }
            std::cout << "You healed by resting. Health is now: " << totalHP << std::endl; 
            Sleep(1000);
            HUD();
        } else if(choice == 3){
            Trader();
            temp = rand() % 100 + 1;
            std::cout << "# You begin search backwards...\n";
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        }else{
            std::cout << "Invalid number";
            Sleep(500);
            actionForest();
        }
        }
    }    
    virtual void LevelUP(){ // LVL UP
        if(current_xp >= xp_to_level){
            xp_to_level = static_cast<int>((50/3)*((pow(level, 3)
                            - 6 * pow(level, 2))
                            + 17 * level - 12));
            if(level >= minLevel && level <= maxLevel){
                level++;
            } else{
                level = 20;
            }
            if(level == 1)
                {
                    totalHP = 100;
                    maxHealth = totalHP;
                }else if(level == 2)
                {
                    totalHP = 120;
                    maxHealth = totalHP;
                }
                else if(level == 3)
                {
                    totalHP = 140;
                    maxHealth = totalHP;
                }
                else if(level == 4)
                {
                    totalHP = 160;
                    maxHealth = totalHP;
                }
                else if(level == 5)
                {
                    totalHP = 180;
                    maxHealth = totalHP;
                }
                else if(level == 6)
                {
                    totalHP = 200;
                    maxHealth = totalHP;
                }
                else if(level == 7)
                {
                    totalHP = 220;
                    maxHealth = totalHP;
                }
                else if(level == 8)
                {
                    totalHP = 240;
                    maxHealth = totalHP;
                }
                else if(level == 9)
                {
                    totalHP = 260;
                    maxHealth = totalHP;
                }
                else if(level == 10)
                {
                    totalHP = 280;
                    maxHealth = totalHP;
                }
                else if(level == 11)
                {
                    totalHP = 300;
                    maxHealth = totalHP;
                }
                else if(level == 12)
                {
                    totalHP = 320;
                    maxHealth = totalHP;
                }
                else if(level == 13)
                {
                    totalHP = 340;
                    maxHealth = totalHP;
                }
                else if(level == 14)
                {
                    totalHP = 360;
                    maxHealth = totalHP;
                }
                else if(level == 15)
                {
                    totalHP = 380;
                    maxHealth = totalHP;
                }
                else if(level == 16)
                {
                    totalHP = 400;
                    maxHealth = totalHP;
                }
                else if(level == 17)
                {
                    totalHP = 420;
                    maxHealth = totalHP;
                }
                else if(level == 18)
                {
                    totalHP = 440;
                    maxHealth = totalHP;
                }
                else if(level == 19)
                {
                    totalHP = 460;
                    maxHealth = totalHP;
                }
                else if(level == 20)
                {
                    totalHP = 480;
                    maxHealth = totalHP;
                }
            std::cout << "Wait whats this a level up! you are now level " << level << std::endl;
            std::cout << "You have 1 power point to give away" << std::endl;
            retry:
            std::cout << "[1]. +1 Strenght" << std::endl;
            std::cout << "[2]. +1 Agility" << std::endl;
            std::cin >> choice;
            if(choice == 1){
                strenght += 1;
                std::cout << "Now your strenght is " << strenght << std::endl;
            } else if(choice == 2){
                agility += 1;
                std::cout << "Now your agility is " << agility << std::endl;
            } else {
                goto retry;
            }
            std::cout << "Your total health increased now your health is " << totalHP << std::endl;
            std::cout << "\n";
            Sleep(1000);
            LevelUP();
        }
            Sleep(2000);
            HUD();
    }
    virtual void Trader(){
    trader = rand() % 100 + 1;
        if(trader >= 90){
            retry:
            std::cout << trader;
            std::cout << "# You foud Travelling salesman\n";
            std::cout << "Trader: Hello traveler, you are lucky to have met me, I have the best creations around" << std::endl;
            std::cout << "[1]. Show me your stuff."<< std::endl;
            std::cout << "[2]. Exit" << std::endl;
            std::cout << "\n";
            
            std::cin >> choice;
            if(choice == 1){
                system("cls");
                std::cout << "# You can only buy one thing" << std::endl;
                std::cout << "[1]. Two-handed sword [+2 strenght, coin -3]" << std::endl;
                std::cout << "[2]. Heavy leather armor [+15 HP, coin -4]" << std::endl;
                std::cout << "[3]. Gloves [+2 agility, coin -3]" << std::endl;
                std::cout << "[4]. Medium potion [+10 HP, coin -5]" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> shopChoice;
                if(shopChoice == 1){
                    if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    strenght += 2;
                    coins -= 3;
                    std::cout << "Your strenght now is: " << strenght << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 2){
                    if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    totalHP += 15;
                    maxHealth = totalHP;
                    coins -= 4;
                    std::cout << "Your max health now is: " << maxHealth << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 3){
                   if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    agility += 2;
                    coins -= 3;
                    std::cout << "Your agility now is: " << agility << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 4){
                   if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    middPotion += 1;
                    coins -= 4;
                    std::cout << "Now you have " << middPotion << " medium potions." << std::endl;
                    std::cout << "# You leave trader\n";
                }else if(shopChoice == 5){
                    std::cout << "# You leave trader\n";
                    Combat();
                }
                else{
                    std::cout << "Invalid numer! Try again";
                    Trader();
                }
            } else if(choice == 2){
                system("cls");
                HUD();
            }
        }    
    }
    virtual void CreateMonster(){ // Create Monsters
        monsterHP = 30;

        monsterLevel = (rand() % 4) + level;
        monsterHP = (rand() % 50) * monsterLevel;

        monsterXP = monsterHP;

        if(monsterHP == 0)
            CreateMonster();
        if(monsterLevel == 0)
            CreateMonster();
    }
///////////////////////////////////////////////////////////////////////////////
};
class Mage: public Hero{
    public:
    int hp = 60, inteligence = 10, mana = 5, coins = 10, moral = 0, totalMoral = moral, smallPotion = 0, middPotion = 0, bigPotion = 0, trader, totalHP = hp, temp;
    int level = 1, maxHealth = totalHP, heal = 0;
    
    int current_xp = 0, base_xp = 83, xp_to_level = base_xp, minLevel = 1, maxLevel = 20;
    virtual void currentStats(){ // info about stats
        std::cout << "HP: " << totalHP << std::endl;
        std::cout << "Inteligence: " << inteligence << std::endl;
        std::cout << "Mana: " << mana << std::endl;
        std::cout << "Coins: " << coins << " Moral: " << totalMoral << std::endl;
    }
    virtual void maxHP() {

    }
    virtual void losehp(){ //losing hp
    totalHP = totalHP - 1;
        std::cout << "Narrator: Your current life is: " << totalHP << std::endl;
    }
    virtual void addStats(){ // adding stats from buying items in blacksmith
        retry:
        std::cout << "\nEnter your choice: ";
        std::cin >> shopChoice;
        if(shopChoice == 1){
            coins = coins - 1;
            inteligence = inteligence + 1;
            std::cout << "Narrator: You have purchased a staff which gives you +1 to inteligence" << std::endl;
            std::cout << "Narrator: Your current strenght is: " << inteligence << " your coins: " << coins << std::endl;
        } else if (shopChoice == 2){
            coins = coins - 2;
            totalHP = totalHP + 5;
            std::cout << "Narrator: You have purchased a magic robe which gives you +1 to health" << std::endl;
            std::cout << "Narrator: Your current hp is: " << totalHP << " your coins: " << coins << std::endl;      
        } else if(shopChoice == 3){
            coins = coins - 1;
            mana = mana + 1;
            std::cout << "Narrator: You have purchased a ring which gives you +1 to mana" << std::endl;
            std::cout << "Narrator: Your current hp is: " << mana << " your coins: " << coins << std::endl;
        } else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2' or '3', nothing else!" << std::endl;
			goto retry;
        }
    }
    virtual void addmoral(){ // adding 1 point of moral
        totalMoral = totalMoral + 1;
        std::cout << "# Moral is: " << totalMoral << std::endl;
    }
    virtual void minusmoral(){ // minus 1 point of moral
        totalMoral = totalMoral - 1;
        std::cout << "# Moral is: " << totalMoral << std::endl;
    }
    virtual void addPotion(){ // adding 1 bottle of potion 
        retry:
        std::cout << "[1]. Small HP bottle [+1 HP, -1 coin]" << std::endl;
        std::cout << "[2]. Medium HP bottle [+2 HP, -3 coin]" << std::endl;
        std::cout << "[3]. Big HP bottle [+3 HP, -5 coin]" << std::endl;
        std::cin >> choice;
        if(choice == 1){
            smallPotion = smallPotion + 1;
            coins = coins - 1;
            std::cout << "You have " << smallPotion << " small bottle"<< std::endl;
        }else if(choice == 2){
            middPotion = middPotion + 1;
            coins = coins - 3;            
            std::cout << "You u have " << middPotion << " medium bottle"<< std::endl;
        }else if(choice == 3){
            coins = coins - 5;
            bigPotion = bigPotion + 1;
            std::cout << "You u have " << bigPotion << " big bottle"<< std::endl;
        }else{
            std::cout << "Narrator: You are doing it wrong, warrior! Press either '1' or '2', nothing else!" << std::endl; 
            goto retry;
        }
    }
////////////////////////////////////////////////////////////////////////////////
                            //CHAPTER FOREST//
    virtual void HUD(){ // HUD player in forest
        std::cout << "Name: " << name << "              |Health: " << totalHP << std::endl;
        std::cout << "Level: " << level << "                  |Coins: " << coins << std::endl;
        std::cout << "XP: " << current_xp << "                     |Inteligence: " << inteligence << std::endl;
        std::cout << "XP to level up: " << xp_to_level << "        |Mana: " << mana << std::endl;
        actionForest();
    }
    virtual void CombatHUD(){
        Sleep(500);
        system("cls");
        std::cout << "Name: " << name << "          |           Monster Name: " << currentMonster << "\nHealth: " << totalHP << "           |            Monster Health: " <<
            monsterHP << "\nLevel: " << level << "              |             Monster Level: " << monsterLevel << std::endl;
    }
    virtual void Combat(){

        CombatHUD();
        int playerAttack;
        int playerDamage = inteligence;
        int monsterAttack = 6 * monsterLevel / 2;
        int monsterCoins = rand() % monsterLevel;

        if(totalHP >= 1 && monsterHP >= 1){
            std::cout << "\n";
            std::cout << "[1]. Attack\n";
            //std::cout << "[2]. Block\n";
            std::cout << "[2]. Inventory\n";            
            std::cout << "[3]. RUN!\n";
            std::cout << "\n";
            std::cin >> playerAttack;

            if(playerAttack == 1){//ATTACK
                std::cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << std::endl;
                monsterHP = monsterHP - playerDamage;
                Sleep(2000);
                CombatHUD();
                    if(monsterHP >= 1){
                        std::cout << "\n";
                        std::cout << "Monster is Attacking...\n";
                        totalHP = totalHP - monsterAttack;
                        std::cout << "You suffered " << monsterAttack << " hp " << totalHP << std::endl;
                        //change to fuction
                        if(totalHP <= 0){
                            totalHP = 0;
                            system("cls");
                            std::cout << "You died! \nYou were level: " << level << " you got killed by " << currentMonster << std::endl;
                            Sleep(2000);
                            exit(0);                            
                        }
                    } else if (monsterHP <= 0){
                        monsterHP = 0;
                        std::cout << "\n";
                        std::cout << "You Defeated " << currentMonster << " you are rewarded with " << monsterXP << " xp.\nWell Done!\n";
                        coins += monsterCoins;
                        std::cout << "In dead body you find " << monsterCoins << " coin now you have " << coins << " coins\n";
                        
                        if(level != maxLevel){
                            current_xp += monsterXP;
                            LevelUP();
                        }
                        system("cls");
                        Sleep(2000);   
                        HUD();                      
                    }
                    Sleep(2000);
                    Combat();
            } else if(playerAttack == 2){//BLOCK
               /* std::cout << "Blocking\n";
                int i = rand() % 100 + 1;
                if(i >= 50){
                    std::cout << i;
                    std::cout << "You Blocked the incoming attack\n";
                    heal = level * 10 / 2;
                    std::cout << "You have been Healed for " << heal << std::endl;
                    totalHP += heal;
                    Sleep(1000);
                    Combat();

                }else {
                    std::cout << "You failed to block the savage attack\n";
                    totalHP -= monsterAttack;
                    std::cout << "You were stabbed in the back for " << monsterAttack << " current hp " << totalHP << std::endl;
                    Sleep(1000);
                    Combat(); 
                }
                */
               system("cls");
               retry:
                std::cout << "[1]. Small potions [+ 5 hp] " << smallPotion << std::endl;
                std::cout << "[2]. Medium potions [+ 10 hp] " << middPotion << std::endl;
                std::cout << "[3]. Big potions [+ 15 hp] " << bigPotion << std::endl;  
                std::cout << "[4]. Exit" << std::endl;
                std::cout << "Use: ";
                std::cin >> choice;
                if(choice == 1){
                    if(smallPotion == 0){
                        std::cout << "# You don't have any Small potions! Try Again!" << std::endl;
                        goto retry;
                    }else if(smallPotion > 0){
                        smallPotion -= 1;
                        totalHP += 5;
                        std::cout << "# You drink a potion, your HP now is " << totalHP << std::endl;
                        goto retry;                        
                    }
                } else if(choice == 2){
                    if(middPotion == 0){
                        std::cout << "# You don't have any Medium potions! Try Again!" << std::endl;
                        goto retry;
                    }else if(middPotion > 0){
                        middPotion-= 1;
                        totalHP += 10;
                        std::cout << "# You drink a potion, your HP now is " << totalHP << std::endl;
                        goto retry;
                    }
                } else if(choice == 3){
                    if(bigPotion == 0){
                        std::cout << "# You don't have any Big potions! Try Again!" << std::endl;
                        goto retry;
                    }else if(bigPotion > 0){
                        bigPotion-= 1;
                        totalHP += 15;
                        std::cout << "# You drink a potion, your HP now is " << totalHP << std::endl;
                        goto retry;                        
                    }
                } else if(choice == 4){
                    Combat();
                }
                else{
                    std::cout << "Invalid number! Try again!" << std::endl;
                    goto retry;
                }              
            } else if(playerAttack == 3){//RUN
                std::cout << "You try to run\n";
                int x = rand() % 100 + 1;
                if(x >= 50){
                    std::cout << "You run away\n";
                    HUD();
                } else {
                    if(totalHP <= 0){
                        totalHP = 0;
                        system("cls");
                        std::cout << "You died! \nYou were level: " << level << " you got killed by " << currentMonster << std::endl;
                        Sleep(2000);
                        exit(0);                            
                    }
                    std::cout << "You failed to run away\n";
                    std::cout << "Monster does a savage attack on you!\n";
                    totalHP -= monsterAttack + 10;
                    std::cout << "You suffered " << monsterAttack + 10 << " Your current Health is " << totalHP << std::endl;
                    Sleep(1000);
                    Combat();
                }
            }else{
                std::cout << "Invalid number";
                Sleep(500);
                Combat();
            }
        }
    }    
    virtual void actionForest(){ // Searching for monsters in forest
        while(isLevel){
            if(level == 20){
            isLevel = false;
                std::cout << "you pass the game thx for playing";
                Sleep(2000);
                exit(0);
                }
        std::cout << "[1]. Searching the front area" << std::endl;
        std::cout << "[2]. Rest" << std::endl;
        std::cout << "[3]. Searching the backwards area";
        std::cout << "\n\n";

        std::cin >> choice;
        if(choice == 1){
            std::cout << "# You begin search forward...\n";  
            Trader();
            temp = rand() % 100 + 1; 
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        } else if(choice == 2){
            std::cout << "You want to set up camp for the evening\n";
                totalHP += 10 * level;
                if(level == 1)
                {
                    totalHP = 60;
                    maxHealth = totalHP;
                }else if(level == 2)
                {
                    totalHP = 80;
                    maxHealth = totalHP;
                }
                else if(level == 3)
                {
                    totalHP = 100;
                    maxHealth = totalHP;
                }
                else if(level == 4)
                {
                    totalHP = 120;
                    maxHealth = totalHP;
                }
                else if(level == 5)
                {
                    totalHP = 140;
                    maxHealth = totalHP;
                }
                else if(level == 6)
                {
                    totalHP = 160;
                    maxHealth = totalHP;
                }
                else if(level == 7)
                {
                    totalHP = 180;
                    maxHealth = totalHP;
                }
                else if(level == 8)
                {
                    totalHP = 200;
                    maxHealth = totalHP;
                }
                else if(level == 9)
                {
                    totalHP = 220;
                    maxHealth = totalHP;
                }
                else if(level == 10)
                {
                    totalHP = 240;
                    maxHealth = totalHP;
                }                
                else if(level == 11)
                {
                    totalHP = 260;
                    maxHealth = totalHP;
                }
                else if(level == 12)
                {
                    totalHP = 280;
                    maxHealth = totalHP;
                }                
                else if(level == 13)
                {
                    totalHP = 300;
                    maxHealth = totalHP;
                }
                else if(level == 14)
                {
                    totalHP = 320;
                    maxHealth = totalHP;
                }
                else if(level == 15)
                {
                    totalHP = 340;
                    maxHealth = totalHP;
                }
                else if(level == 16)
                {
                    totalHP = 360;
                    maxHealth = totalHP;
                }
                else if(level == 17)
                {
                    totalHP = 380;
                    maxHealth = totalHP;
                }
                else if(level == 18)
                {
                    totalHP = 400;
                    maxHealth = totalHP;
                }
                else if(level == 19)
                {
                    totalHP = 420;
                    maxHealth = totalHP;
                }
                else if(level == 20)
                {
                    totalHP = 440;
                    maxHealth = totalHP;
                }                
            std::cout << "You healed by resting. Health is now: " << totalHP << std::endl; 
            Sleep(1000);
            HUD();
        } else if(choice == 3){
            Trader();
            temp = rand() % 100 + 1;
            std::cout << "# You begin search backwards...\n";
            if(temp >= 50){
                CreateMonster();
                std::string tempName = monsterName[rand() % currentMonsterNames];
                std::cout << "A " << tempName << "| Prepare to fight\n";
                currentMonster = tempName;
                Sleep(1000);
                Combat();
            }
            std::cout << "# You find nothing of interest\n";
            Sleep(1000);
            HUD();
        }else{
            std::cout << "Invalid number";
            Sleep(500);
            actionForest();
        }
        }
    }    
    virtual void LevelUP(){ // LVL UP
        if(current_xp >= xp_to_level){
            xp_to_level = static_cast<int>((50/3)*((pow(level, 3)
                            - 6 * pow(level, 2))
                            + 17 * level - 12));
            if(level >= minLevel && level <= maxLevel){
                level++;
            } else{
                level = 20;
            }
            if(totalHP <= 60)
            {
                totalHP += 10 * level;
                if(level == 1)
                {
                    totalHP = 60;
                    maxHealth = totalHP;
                }else if(level == 2)
                {
                    totalHP = 80;
                    maxHealth = totalHP;
                }
                else if(level == 3)
                {
                    totalHP = 100;
                    maxHealth = totalHP;
                }
                else if(level == 4)
                {
                    totalHP = 120;
                    maxHealth = totalHP;
                }
                else if(level == 5)
                {
                    totalHP = 140;
                    maxHealth = totalHP;
                }
                else if(level == 6)
                {
                    totalHP = 160;
                    maxHealth = totalHP;
                }
                else if(level == 7)
                {
                    totalHP = 180;
                    maxHealth = totalHP;
                }
                else if(level == 8)
                {
                    totalHP = 200;
                    maxHealth = totalHP;
                }
                else if(level == 9)
                {
                    totalHP = 220;
                    maxHealth = totalHP;
                }
                else if(level == 10)
                {
                    totalHP = 240;
                    maxHealth = totalHP;
                }                
                else if(level == 11)
                {
                    totalHP = 260;
                    maxHealth = totalHP;
                }
                else if(level == 12)
                {
                    totalHP = 280;
                    maxHealth = totalHP;
                }                
                else if(level == 13)
                {
                    totalHP = 300;
                    maxHealth = totalHP;
                }
                else if(level == 14)
                {
                    totalHP = 320;
                    maxHealth = totalHP;
                }
                else if(level == 15)
                {
                    totalHP = 340;
                    maxHealth = totalHP;
                }
                else if(level == 16)
                {
                    totalHP = 360;
                    maxHealth = totalHP;
                }
                else if(level == 17)
                {
                    totalHP = 380;
                    maxHealth = totalHP;
                }
                else if(level == 18)
                {
                    totalHP = 400;
                    maxHealth = totalHP;
                }
                else if(level == 19)
                {
                    totalHP = 420;
                    maxHealth = totalHP;
                }
                else if(level == 20)
                {
                    totalHP = 440;
                    maxHealth = totalHP;
                }                
            }
            std::cout << "Wait whats this a level up! you are now level " << level << std::endl;
            std::cout << "You have 1 power point to give away" << std::endl;
            retry:
            std::cout << "[1]. +1 Inteligence" << std::endl;
            std::cout << "[2]. +1 Mana" << std::endl;
            std::cin >> choice;
            if(choice == 1){
                inteligence += 1;
                std::cout << "Now your inteligence is " << inteligence << std::endl;
            } else if(choice == 2){
                mana += 1;
                std::cout << "Now your mana is " << mana << std::endl;
            } else {
                goto retry;
            }
            std::cout << "Your total health increased now your health is " << totalHP << std::endl;
            std::cout << "\n";
            Sleep(1000);
            LevelUP();
        }
            Sleep(2000);
            HUD();
    }
    virtual void Trader(){
    trader = rand() % 100 + 1;
        if(trader >= 90){
            retry:
            std::cout << trader;
            std::cout << "# You foud Travelling salesman\n";
            std::cout << "Trader: Hello traveler, you are lucky to have met me, I have the best creations around" << std::endl;
            std::cout << "[1]. Show me your stuff."<< std::endl;
            std::cout << "[2]. Exit" << std::endl;
            std::cout << "\n";
            
            std::cin >> choice;
            if(choice == 1){
                system("cls");
                std::cout << "# You can only buy one thing" << std::endl;
                std::cout << "[1]. Magician's wand [+2 inteligence, coin -3]" << std::endl;
                std::cout << "[2]. Cloak of a magic apprentice [+10 HP, coin -4]" << std::endl;
                std::cout << "[3]. Golden ring [+2 mana, coin -3]" << std::endl;
                std::cout << "[4]. Medium potion [+10 HP, coin -5]" << std::endl;   
                std::cout << "[5]. Exit" << std::endl;             
                std::cout << "Enter your choice: ";
                std::cin >> shopChoice;
                if(shopChoice == 1){
                    if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    inteligence += 2;
                    coins -= 3;
                    std::cout << "Your strenght now is: " << inteligence << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 2){
                    if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    totalHP += 10;
                    maxHealth = totalHP;
                    coins -= 4;
                    std::cout << "Your max health now is: " << maxHealth << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 3){
                   if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    mana += 2;
                    coins -= 3;
                    std::cout << "Your agility now is: " << mana << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 4){
                   if(coins == 0){
                        std::cout << "# You don't have enought coins" << std::endl;
                        Trader();
                    }
                    middPotion += 1;
                    coins -= 4;
                    std::cout << "Now you have " << middPotion << " medium potions." << std::endl;
                    std::cout << "# You leave trader\n";
                } else if(shopChoice == 5){
                    std::cout << "# You leave trader\n";
                    Combat();
                }
                 else{
                    std::cout << "Invalid numer! Try again";
                    Trader();
                }
            } else if(choice == 2){
                system("cls");
                HUD();
            }
        }    
    }
    virtual void CreateMonster(){ // Create Monsters
        monsterHP = 30;

        monsterLevel = (rand() % 4) + level;
        monsterHP = (rand() % 50) * monsterLevel;

        monsterXP = monsterHP;

        if(monsterHP == 0)
            CreateMonster();
        if(monsterLevel == 0)
            CreateMonster();
    }
///////////////////////////////////////////////////////////////////////////////
};
#endif