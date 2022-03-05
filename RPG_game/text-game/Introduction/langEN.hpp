#pragma once
#ifndef LANGEN_HPP_
#define LANGEN_HPP_ 
#include <iostream>
#include <iomanip>
    char nick[50];
    char *name = nick;
    bool Intro = true;
class en{
    
    public:
     
    void introducitonEN(){
        std::string Intro_story = "# You have set out on a long journey in search of new adventures and a good income,\n"
        "because your village has been taken over by the enemy army and all the settlers have been exterminated.\n"
        "After several long and exhausting days of wandering,\n"
        "you came upon a settlement, where you were greeted by the local mayor.\n"
        "Mayor: Hello, my name is Leo, I'm the village chief here.\n"
        "Mayor: What's your name, stranger ?\n\n";
        if(Intro)
        {
            int i = 0;
            while (Intro_story[i] != '\0'){
                std::cout << Intro_story[i];
                Sleep(40);
                i++;
            }
            Intro = false;
        }
    std::cout << "Enter your name: ";
    Sleep(150);
    std::cin.getline(nick, 50);
    }
};
#endif
