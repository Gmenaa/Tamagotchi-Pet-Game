#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Pet.h" 

#ifndef DRAGON_H 
#define DRAGON_H

class Dragon : public Pet {
    public:
        void nextHour(); // Overriding pure virtual functions declared in the Pet class.
        void threshold();
        void petStatus(); 

        void roar(); // Declaring unique interactions for the "Dragon" pet.
        void fly(); 
        void annihilate();
}; 

#endif /*DRAGON_H*/