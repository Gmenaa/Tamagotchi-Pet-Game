#include <iostream>
#include <string>

using namespace std;

#ifndef PET_H
#define PET_H 
 
class Pet {
    public:
        void setName(string _name); // Declaring accessors and mutators.
        void setHappiness(int _happiness);
        void setHunger(int _hunger);
        void setBoredom(int _boredom);
        void setSleepiness(int _sleepiness);
        string getName();
        int getHappiness();
        int getHunger();
        int getBoredom();
        int getSleepiness();

        void feed(); // Generic interactions for ALL pets.
        void play();
        void rest();

        virtual void nextHour() = 0; // Pure virtual functions that will change for each pet.
        virtual void threshold() = 0;
        virtual void petStatus() = 0;

    protected: // Protected member variables that ALL pets can access.
        string name; 
        int happiness;
        int hunger;
        int boredom;
        int sleepiness;
};

#endif /*PET_H*/