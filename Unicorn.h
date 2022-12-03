#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Pet.h"
 
#ifndef UNICORN_H
#define UNICORN_H 

class Unicorn : public Pet {
    public:
        void threshold(); // Overriding pure virtual functions declared in the Pet class. 
        void nextHour();
        void petStatus();

        void gallop(); // Declaring unique interactions for the "Unicorn" pet.
        void rainbow();
        void nurse(); 
}; 

#endif /*UNICORN_H*/