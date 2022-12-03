#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Pet.h"
 
#ifndef CERBERUS_H 
#define CERBERUS_H  

class Cerberus : public Pet {
    public: 
        void nextHour(); // Overriding pure virtual functions declared in the Pet class. 
        void threshold();
        void petStatus();

        void howl(); // Declaring unique interactions for the "Cerberus" pet.
        void fetch();
        void hunt();
};

#endif /*CERBERUS_H*/