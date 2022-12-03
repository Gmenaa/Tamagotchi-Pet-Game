#include "Cerberus.h"

void Cerberus::nextHour() { // After every cerberus interaction, nextHour() will be called, either the cerberus will
   srand(time(0));            // get happier or stats will decrease/increase accordingly to affect cerberus negatively. 
   int moodSwing = (rand() % 2) + 1;
   switch (moodSwing) {
      case 1:
         happiness += 15; 
         break;
      case 2:
         happiness -= 15;
         hunger += 10;
         boredom += 15;
         sleepiness += 10;
         break;
      default:
         break;
   }
}
void Cerberus::threshold() { // Ensuring stats stay within a cerberus threshold:
   if (happiness > 100) {     // 0 <= happiness <= 100, 0 <= hunger <= 100, ...   
      happiness = 100;
   }
   if(happiness < 0) {
      happiness = 0;
   }
   if (hunger > 100) {
      hunger = 100;
      happiness -= 40;
      if(happiness < 0) {
         happiness = 0;
      }
   }
   if(hunger < 0) {
      hunger = 0;
      happiness += 30;
      if (happiness > 100) {
         happiness = 100;
      }
   }
   if (boredom > 100) {
      boredom = 100;
      sleepiness += 50;
      if(sleepiness > 150) {
         sleepiness = 150;
         happiness -= 40;
         if(happiness < 0) {
            happiness = 0;
         }
      }
   }
   if(boredom < 0) {
      boredom = 0;
   }
   if(sleepiness > 150) {
      sleepiness = 150;
      happiness -= 40;
      if(happiness < 0) {
         happiness = 0;
      }
   }
   if(sleepiness < 0) {
      sleepiness = 0;
   }
}
void Cerberus::petStatus() {  // User can call on petStatus() to check in on a cerberus; will display all stats.
   if(happiness == 100) {
      cout << "Happiness: " << name << " is as happy as a hellhound can be! Good job!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(happiness > 50 && happiness != 100) {
      cout << "Happiness: " << name << " is happy!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(happiness <= 50 && happiness != 0) {
      cout << "Happiness: " << name << " is unhappy!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(happiness == 0) {
      cout << "Happiness: " << name << " is miserable! Make " << name << " happy!" << endl;
      cout << setw(5) << happiness << "/100" << endl;
   }
   if(hunger == 100) {
      cout << "Hunger: " << name << " is famished! " << name << " will starve soon!" << endl; 
      cout << setw(5) << hunger << "/100" << endl;
   }
   if(hunger >= 50 && hunger != 100) {
      cout << "Hunger: " << name << " is hungry!" << endl;
      cout << setw(5) << hunger << "/100" << endl;
   }
   if(hunger < 50 && hunger != 0) {
      cout << "Hunger: " << name << " could use a snack!" << endl;
      cout << setw(5) << hunger << "/100" << endl;
   }
   if(hunger == 0) {
      cout << "Hunger: " << name << " is full! Even with three bellies!" << endl;
      cout << setw(5) << hunger << "/100" << endl;
   }
   if(boredom >= 50) {
      cout << "Boredom: " << name << " is bored!" << endl;
      cout << setw(5) << boredom << "/100" << endl;
   }
   if(boredom < 50) {
      cout << "Boredom: " << name << " is enthusiastic!" << endl;
      cout << setw(5) << boredom << "/100" << endl;
   }
   if(sleepiness > 100) {
      cout << "Sleepiness: " << name << " is tired!" << endl;
      cout << setw(5) << sleepiness << "/150" << endl;
   }
   if(sleepiness <= 100 && sleepiness != 0) {
      cout << "Sleepiness: " << name << " is rested!" << endl;
      cout << setw(5) << sleepiness << "/150" << endl;
   }
   if(sleepiness == 0) {
      cout << "Sleepiness: " << name << " is energized! " << name << " is ready to take on the world!"  << endl;
      cout << setw(5) << sleepiness << "/150" << endl;
   }
}

void Cerberus::howl() { // Implementing the howl() interaction for a cerberus pet.  
   cout << name << " howls at the crimson-lit moon!" << endl;
   happiness += 15; 
   hunger += 10;
   boredom -= 15;
   sleepiness += 10;
}
void Cerberus::fetch() { // Implementing the fetch() interaction for a cerberus pet.
   cout << name << " fetches and crushes the bone!" << endl;
   happiness += 20; 
   hunger += 15;
   boredom -= 20;
   sleepiness += 15;
}
void Cerberus::hunt() { // Implementing the hunt() interaction for a cerberus pet.
   srand(time(0));        // Randomize what a cerberus hunts, affecting stats accordingly; chance of hunting nothing.
   int prey = (rand() % 5) + 1;
   switch (prey)
   {
   case 1:
      cout << name << " hunted a jackalope!" << endl;
      happiness += 30; 
      hunger -= 15;
      boredom -= 30;
      sleepiness += 20;
      break;
   case 2:
      cout << name << " hunted a unicorn!" << endl;
      happiness += 40; 
      hunger -= 30;
      boredom -= 30;
      sleepiness += 30;
      break;
   case 3:
      cout << name << " hunted a harpy!" << endl;
      happiness += 30; 
      hunger -= 15;
      boredom -= 30;
      sleepiness += 20;
      break;
   case 4:
      cout << name << " hunted a fairy!" << endl;
      happiness += 30; 
      hunger -= 5;
      boredom -= 20;
      sleepiness += 20;
      break;
   default:
      cout << name << " caught nothing :(" << endl;
      happiness -= 15; 
      hunger += 15;
      boredom += 15;
      sleepiness += 15;
      break;
   }
}