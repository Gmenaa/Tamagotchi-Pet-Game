#include "Pet.h"

void Pet::setName(string _name) { // Implementing the accessors and mutators.
    name = _name;
}
void Pet::setHappiness(int _happiness) {
    happiness = _happiness; 
}
void Pet::setHunger(int _hunger) {
    hunger = _hunger;
}
void Pet::setBoredom(int _boredom) {
    boredom = _boredom;
}
void Pet::setSleepiness(int _sleepiness) {
    sleepiness = _sleepiness;
} 
string Pet::getName() {
    return name;
}
int Pet::getHappiness() {
    return happiness;
}
int Pet::getHunger() {
    return hunger;
}
int Pet::getBoredom() {
    return boredom;
}
int Pet::getSleepiness() {
    return sleepiness;
}


void Pet::feed() { // Implementing the generic Pet actions. 
    hunger -= 30;
    happiness += 25;

    cout << name << " has been fed!" << endl;
}
void Pet::play() {
    happiness += 40;
    hunger += 15;
    sleepiness += 15;
    boredom -= 30;

    cout << name << " had a lot of fun!" << endl;
}
void Pet::rest() {
    sleepiness = 0;
    hunger += 30;

    cout << name << " has gotten plenty of rest!" << endl;
}