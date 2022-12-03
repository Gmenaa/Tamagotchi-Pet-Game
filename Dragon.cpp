#include "Dragon.h"

void Dragon::nextHour() { // After every dragon interaction, nextHour() will be called, either the dragon will
   srand(time(0));         // get happier or stats will decrease/increase accordingly to affect dragon negatively.
   int moodSwing = (rand() % 2) + 1;
   switch (moodSwing) {
      case 1:
         happiness += 5; 
         break;
      case 2:
         happiness -= 15;
         hunger += 40;
         boredom += 30;
         sleepiness += 45;
         break;
      default: 
         break;
   }
}
void Dragon::threshold() { // Ensuring stats stay within a dragon threshold:
   if (happiness > 100) {   // 0 <= hunger <= 500, 0 <= boredom <= 250, ...
      happiness = 100;
   }
   if(happiness < 0) {
      happiness = 0;
   }
   if (hunger > 500) {
      hunger = 500;
      happiness -= 50;
      if(happiness < 0) {
         happiness = 0;
      }
   }
   if(hunger < 0) { 
      hunger = 0;
      happiness += 50;
      if (happiness > 100) {
         happiness = 100;
      }
   }
   if (boredom > 250) {
      boredom = 250;
      sleepiness += 100;
      if (sleepiness > 300) {
         sleepiness = 300;
         happiness -= 30;
         if (happiness < 0) {
            happiness = 0;
         }
      }
   }
   if(boredom < 0) {
      boredom = 0;
   }
   if (sleepiness > 300) {
      sleepiness = 300;
      happiness -= 30;
      if (happiness < 0) {
         happiness = 0;
      }
   }
   if(sleepiness < 0) {
      sleepiness = 0;
   }
}
void Dragon::petStatus() { // User can call on petStatus() to check in on a dragon; will display all stats.
   if(happiness == 100) {
      cout << "Happiness: " << name << " is as happy as a cold-blooded creature can be! Great work!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(happiness > 50 && happiness != 100) {
      cout << "Happiness: " << name << " is content!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(happiness <= 50 && happiness != 0) {
      cout << "Happiness: " << name << " is dissatisfied!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(happiness == 0) {
      cout << "Happiness: " << name << " is downhearted! Make " << name << " happy!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(hunger == 500) {
      cout << "Hunger: " << name << " is ravenous! " << name << " is willing to eat anything..." << endl; 
      cout << setw(5) << hunger << "/500" << endl;
   }
   if(hunger >= 200 && hunger != 500) {
      cout << "Hunger: " << name << " is hungry! " << name << " is craving human bodies!" << endl;
      cout << setw(5) << hunger << "/500" << endl;
   }
   if(hunger < 200 && hunger != 0) {
      cout << "Hunger: " << name << "'s bowels tremble, " << name << " could use a morsel of meat!" << endl;
      cout << setw(5) << hunger << "/500" << endl;
   }
   if(hunger == 0) {
      cout << "Hunger: " << name << " is full?!... Surprisingly!" << endl;
      cout << setw(5) << hunger << "/500" << endl;
   }
   if(boredom >= 200) {
      cout << "Boredom: " << name << " is bored!" << endl;
      cout << setw(5) << boredom << "/250" << endl;
   }
   if(boredom < 200) {
      cout << "Boredom: " << name << " is entertained!" << endl;
      cout << setw(5) << boredom << "/250" << endl;
   } 
   if(sleepiness >= 125) {
      cout << "Sleepiness: " << name << " is tired!" << endl;
      cout << setw(5) << sleepiness << "/300" << endl;
   }
   if(sleepiness < 125 && sleepiness != 0) {
      cout << "Sleepiness: " << name << " is rested!" << endl;
      cout << setw(5) << sleepiness << "/300" << endl;
   }
   if(sleepiness == 0) {
      cout << "Sleepiness: " << name << " is energized! " << name << " is ready to take on the world!"  << endl;
      cout << setw(5) << sleepiness << "/300" << endl;
   }
}

void Dragon::roar() { // Implementing the roar() interaction for a dragon pet.  
    cout << name << "'s shattering roar shakes the sky!" << endl;
    happiness += 20; 
    hunger += 20;
    boredom -= 40;
    sleepiness += 30
   ;
} 
void Dragon::fly() { // Implementing the fly() interaction for a dragon pet.  
    cout << "You and " << name << " take to the sky, flying past the clouds!" << endl;
    happiness += 25; 
    hunger += 40;
    boredom -= 80;
    sleepiness += 40;
} 
void Dragon::annihilate() { // Implementing the annihilate() interaction for a dragon pet.  
    srand(time(0));          // Randomize attacks: attack small, med, or large towns which impact stats accordingly.
    int villageSize = (rand() % 3) + 1;
    int sPrey = (rand() % 10) + 1;
    int mPrey = (rand() % (20 - 10 + 1)) + 10;
    int lPrey = (rand() % (30 - 20 + 1)) + 20;

    switch (villageSize) {
    case 1:
        cout << name << " found a small village and ate " << sPrey << " villagers, it was a light snack..." << endl;
        happiness += 30; 
        hunger -= 40;
        boredom -= 30;
        sleepiness += 20;  
        break;
    case 2:
        cout << name << " found a modest village and consumed " << mPrey << " villagers, it was a good lunch!" << endl;
        happiness += 40; 
        hunger -= 60;
        boredom -= 60;
        sleepiness += 40;
        break;
    case 3:
        cout << name << " found a large village and DEVOURED " << lPrey << " villagers, it was a feast!" << endl;
        happiness += 60; 
        hunger -= 100; 
        boredom -= 90;
        sleepiness += 60;
        break;
    default:
        break;
    }
}