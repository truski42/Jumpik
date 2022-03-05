   #include <iostream>
   #include "langEN.hpp"
   void en::introducitonEN(){
   std::cout << "You have set out on a long journey in search of new adventures and a good income, because your village has been taken over by the enemy army and all the settlers have been exterminated.\nAfter several long and exhausting days of wandering, you came upon a settlement, where you were greeted by the local mayor.\n" << std::endl;
    std::cout << "Hello, my name is Leo, I'm the village chief here." << std::endl;
    std::cout << "What's your name, stranger?" << std::endl; // insert name.
    std::cin.getline(nick, 50);
   };