#include "Unicorn.h"

void Unicorn::nextHour() { // After every unicorn interaction, nextHour() will be called, either the unicorn will
   srand(time(0));          // get happier or stats will decrease/increase accordingly to affect unicorn negatively.
   int moodSwing = (rand() % 2) + 1; // Happiness cannot decrease for unicorns with nextHour();
   switch (moodSwing) {
      case 1:
         happiness += 20; 
         break;
      case 2:
         hunger += 10;
         boredom += 10;
         sleepiness += 15;
         break;
      default:
         break;
   }
}
void Unicorn::threshold() { // Ensuring stats stay within a unicorn threshold:
   if (happiness > 500) {    // 0 <= happiness <= 500, ...
      happiness = 500;
   }
   if(happiness < 0) {
      happiness = 0; 
   }
   if (hunger > 100) {
      hunger = 100;
      happiness -= 100;
      if(happiness < 0) {
         happiness = 0; 
      }
   }
   if(hunger < 0) {
      hunger = 0;
      happiness += 100;
      if (happiness > 500) {
         happiness = 500;
      }
   }
   if (boredom > 100) {
      boredom = 100;
      sleepiness += 50;
      if (sleepiness > 200) {
         sleepiness = 200;
         happiness -= 100;
         if(happiness < 0) {
            happiness = 0; 
         }     
      }
   }
   if(boredom < 0) {
      boredom = 0;
      sleepiness -= 50;
      if(sleepiness < 0) {
         sleepiness = 0;
      }
   }
   if (sleepiness > 200) {
      sleepiness = 200;
      happiness -= 100;
      if(happiness < 0) {
         happiness = 0; 
      }  
   }
   if(sleepiness < 0) {
      sleepiness = 0;
   }
}
void Unicorn::petStatus() { // User can call on petStatus() to check in on a unicorn; will display all stats.
   if(happiness == 500) {
      cout << "Happiness: " << name << " is euphoric! just like every Unicorn!" << endl;
      cout << setw(5) << happiness << "/500" << endl;
   }
   if(happiness > 100 && happiness != 500) {
      cout << "Happiness: " << name << " is happy!" << endl;
      cout << setw(5) << happiness << "/500" << endl;
   }
   if(happiness <= 100 && happiness != 0) {
      cout << "Happiness: " << name << " is unhappy! you managed to make a unicorn unhappy!" << endl;
      cout << setw(5) << happiness << "/500" << endl;
   }
   if(happiness == 0) {
      cout << "Happiness: " << name << " is a somber, dreary unicorn. This is unnatural..."<< endl;
      cout << setw(5) << happiness << "/500" << endl;
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
      cout << "Hunger: " << name << " could nibble on some skittles!" << endl;
      cout << setw(5) << hunger << "/100" << endl;
   }
   if(hunger == 0) {
      cout << "Hunger: " << name << " is full! " << endl;
      cout << setw(5) << hunger << "/100" << endl;
   }
   if(boredom >= 80) {
      cout << "Boredom: " << name << " is bored!" << endl;
      cout << setw(5) << boredom << "/100" << endl;
   }
   if(boredom < 80) {
      cout << "Boredom: " << name << " is ecstatic! as every unicorn should!" << endl;
      cout << setw(5) << boredom << "/100" << endl;
   }
   if(sleepiness > 150) {
      cout << "Sleepiness: " << name << " is tired!" << endl;
      cout << setw(5) << sleepiness << "/200" << endl;
   }
   if(sleepiness <= 150 && sleepiness != 0) {
      cout << "Sleepiness: " << name << " is rested!" << endl;
      cout << setw(5) << sleepiness << "/200" << endl;
   }
   if(sleepiness == 0) {
      cout << "Sleepiness: " << name << " is energized! " << name << " is ready to take on the world!"  << endl;
      cout << setw(5) << sleepiness << "/200" << endl;
   }
}

void Unicorn::gallop() { // Implementing the gallop() interaction for a unicorn pet. 
    cout << "You and " << name << " gallop through a flower field" << endl;
    happiness += 30; 
    hunger += 10;
    boredom -= 30;
    sleepiness += 10;
} 
void Unicorn::rainbow() { // Implementing the rainbow() interaction for a unicorn pet. 
    srand(time(0));        // 1/7 chance of encountering a leprechaun, affecting a unicorn positively:
    int luck = (rand() % 7) + 1; // no hunger, boredom, sleepiness, and max happiness (can be affected by nextHour()).
    switch (luck)
    {
    case 1:
        cout << "You and " << name << " found a leprechaun at the end of the rainbow!" << endl;
        cout << "Today is your lucky day!" << endl;
        happiness = 500; 
        hunger = 0;
        boredom = 0;
        sleepiness = 0;
        break;
    default:
        cout << "You and " << name << " have reached the end of the rainbow!" << endl;
        happiness += 100; 
        hunger += 15;
        boredom -= 30;
        sleepiness += 15;
        break;
    }
}
void Unicorn::nurse() { // Implementing the nurse() interaction for a unicorn pet.
    srand(time(0));      // Randomize what creature a unicorn heals, will get very sad if no creature is found.
    int familiar = (rand() % 5) + 1;
    switch (familiar) 
    {
    case 1:
        cout << name << "'s whimsical golden horn heals a jackalope!" << endl;
        happiness += 40; 
        hunger += 10;
        sleepiness += 10;
        break;
    case 2:
        cout << name << "'s whimsical golden horn heals another unicorn!" << endl;
        happiness += 60; 
        hunger += 10;
        sleepiness += 10;
        break;
    case 3:
        cout << name << "'s whimsical golden horn heals a harpy!" << endl;
        happiness += 40; 
        hunger += 10;
        sleepiness += 10;
        break;
    case 4:
        cout << name << "'s whimsical golden horn heals a fairy!" << endl;
        happiness += 40; 
        hunger += 10;
        sleepiness += 10;
        break;
    default:
        cout << name << " found no creature in need of nursing :(" << endl;
        happiness -= 120; 
        hunger += 25;
        sleepiness += 25;
        break;
    }
}  