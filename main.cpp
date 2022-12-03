#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

#ifdef _WIN32 
#include <Windows.h> 
#else
#include <unistd.h>
#endif

#include "Pet.h"
#include "Cerberus.h" 
#include "Dragon.h"
#include "Unicorn.h"

using namespace std;

/*
  Feel free to change Sleep() in typeWriter() to its alternative (sleep()) for whatever system you are using.
*/

void typeWriter(string s, int speed) { // Produces a typing affect
  for(int i = 0; i < s.length(); i++) {
    cout << s[i];
    Sleep(speed); // Sleep() for #include <Windows.h>, would be sleep() for #include <unistd.h>
  }
  cout << endl;
}


// These functions output ASCII art from files
void printASCII_startMenu() { 
  ifstream ASCIIin;
  string ASCII_line;
  ASCIIin.open("ASCII_StartMenu.txt");

  while(!ASCIIin.eof()) {
    getline(ASCIIin, ASCII_line);
    cout << ASCII_line << endl;
  }
  ASCIIin.close();
}
void printASCII_gameOver() {
  ifstream ASCIIin;
  string ASCII_line;
  ASCIIin.open("ASCII_GameOver.txt");

  while(!ASCIIin.eof()) {
    getline(ASCIIin, ASCII_line);
    cout << ASCII_line << endl;
  }
  ASCIIin.close();

}
void printASCII_C() {
  ifstream ASCIIin;
  string ASCII_line;
  ASCIIin.open("ASCII_Cerberus.txt");

  while(!ASCIIin.eof()) {
    getline(ASCIIin, ASCII_line);
    cout << ASCII_line << endl;
  }
  ASCIIin.close();
}
void printASCII_D() {
  ifstream ASCIIin;
  string ASCII_line;
  ASCIIin.open("ASCII_Dragon.txt");

  while(!ASCIIin.eof()) {
    getline(ASCIIin, ASCII_line);
    cout << ASCII_line << endl;
  }
  ASCIIin.close();
}
void printASCII_U() {
  ifstream ASCIIin;
  string ASCII_line;
  ASCIIin.open("ASCII_Unicorn.txt");

  while(!ASCIIin.eof()) {
    getline(ASCIIin, ASCII_line);
    cout << ASCII_line << endl;
  }
  ASCIIin.close();
}


// These functions are the actual game for respective pets.
void gameMenuC(ofstream& save, Cerberus c) {
  save.open(c.getName() + ".txt"); // opening the save file for when the user saves & quits.
  string interaction = "1";
  int hungerCount = 0;

  while(interaction != "0") {
    cout << "============================================================================" << endl;
    cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
    cout << "0. Save and quit game" << endl;
    cout << "1. Feed " << c.getName() << endl;
    cout << "2. Play with " << c.getName() << endl;
    cout << "3. Sleep" << endl;
    cout << "4. Howl at the blood moon" << endl;
    cout << "5. Fetch bones with " << c.getName() << endl;
    cout << "6. Hunt creatures of nature with " << c.getName() << endl;
    cout << "7. Check in on " << c.getName() << endl;
    cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
    cout << "============================================================================" << endl;
    cin >> interaction;
    if(c.getHunger() == 100) { // for starved cerberus'
      hungerCount++;
      if(interaction == "1" || interaction == "6") { // if fed, count resets and cerberus survives.
        hungerCount = 0;
      }
      if(hungerCount == 5) { // if cerberus is at 100 hunger 5 times in a row, the cerberus dies.
        save.close();
        typeWriter("A terrible event has transpired...", 150);
        typeWriter("Your cerberus has starved to death...", 150);
        typeWriter("...", 200);
        typeWriter("...", 200);
        typeWriter("...", 200);
        typeWriter("May your cerberus find peace in the Underworld...", 150);
        remove((c.getName() + ".txt").c_str()); // deleting the save file forever
        printASCII_gameOver();
        exit(0);
      }
    }
    if(c.getSleepiness() == 150) { // for exhausted cerberus'
      typeWriter("Exhaustion has struck! The three heads begin to droop...", 100);
      typeWriter("Your cerberus has passed out...", 150);
      typeWriter("...", 200);
      typeWriter("...", 200);
      typeWriter("...", 200);
      typeWriter("No thanks to your neglect...", 75);
      interaction = "3"; // goes to the rest action so the cerberus sleeps.
    }
    if(interaction == "0") { // saving the game
      c.threshold();
      typeWriter(" ~~~ Saving game! ~~~ ", 50);
      typeWriter(". . . . . . . . . . . ." , 80);
      printASCII_C();
      save << "Cerberus" << endl;
      save << c.getName() << endl;
      save << c.getHappiness() << endl;
      save << c.getHunger() << endl;
      save << c.getBoredom() << endl;
      save << c.getSleepiness() << endl;
      typeWriter("Save Successful! Thank you for playing!", 50);
      save.close();
      exit(0);
    }
    else if(interaction == "1") {
      c.feed();
      c.nextHour();
      c.threshold();
    }
    else if(interaction == "2") {
      c.play();
      c.nextHour();
      c.threshold();
    }
    else if(interaction == "3") {
      c.rest();
      c.nextHour();
      c.threshold();
    }
    else if(interaction == "4") {
      c.howl();
      c.nextHour();
      c.threshold();
    }
    else if(interaction == "5") {
      c.fetch();
      c.nextHour();
      c.threshold();
    }
    else if(interaction == "6") {
      c.hunt();
      c.nextHour();
      c.threshold();
    }
    else if(interaction == "7") {
      c.petStatus();
    }
    else {
      typeWriter("INVALID OPTION!", 50);
    }
  } 
}
void gameMenuD(ofstream& save, Dragon d) {
  save.open(d.getName() + ".txt"); // opening the save file for when the user saves & quits.
  string interaction = "1";
  int hungerCount = 0;

  while(interaction != "0") {
    cout << "============================================================================" << endl;
    cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
    cout << "0. Save and quit game" << endl;
    cout << "1. Feed " << d.getName() << endl;
    cout << "2. Play with " << d.getName() << endl;
    cout << "3. Sleep" << endl;
    cout << "4. Roar at the sky" << endl;
    cout << "5. Fly with " << d.getName() << endl;
    cout << "6. Annihilate a village with " << d.getName() << endl;
    cout << "7. Check in on " << d.getName() << endl;
    cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
    cout << "============================================================================" << endl;
    cin >> interaction;
    if(d.getHunger() == 500) { // for starved dragons
      hungerCount++;
      if(interaction == "1" || interaction == "6") {
        hungerCount = 0;
      }
      if(hungerCount == 3) { // if dragon is at 500 hunger 3 times in a row, the dragon kills you and the game ends.
        save.close();
        typeWriter("A horrible chill goes down your spine...", 150);
        typeWriter("And a feeling of dread looms over you...", 150);
        typeWriter("...", 200);
        typeWriter("...", 200);
        typeWriter("...", 200);
        typeWriter("Your dragon devours you to satisfy an insatiable hunger...", 150);
        typeWriter("You have been devoured and your dragon flies away...", 150);
        remove((d.getName() + ".txt").c_str()); // deleting save file.
        printASCII_gameOver();
        exit(0);
      }
    }
    if(d.getSleepiness() == 300) { // for exhausted dragons
      typeWriter("Exhaustion has struck! The mighty beast trembles!", 100);
      typeWriter("Your dragon has passed out...", 150);
      typeWriter("...", 200);
      typeWriter("...", 200);
      typeWriter("...", 200);
      typeWriter("No thanks to your neglect...", 75);
      interaction = "3"; // goes to the rest action so the dragon sleeps.
    }
    if(interaction == "0") { // saving game
      d.threshold();
      typeWriter(" ~~~ Saving game! ~~~ ", 50);
      typeWriter(". . . . . . . . . . . ." , 80);
      printASCII_D();
      save << "Dragon" << endl;
      save << d.getName() << endl;
      save << d.getHappiness() << endl;
      save << d.getHunger() << endl;
      save << d.getBoredom() << endl;
      save << d.getSleepiness() << endl;
      typeWriter("Save Successful! Thank you for playing!", 50);
      save.close();
      exit(0);
    }
    else if(interaction == "1") { // though user can feed a dragon, dragons wont be satisfied, user needs to attack towns.
      d.feed();
      d.nextHour();
      d.threshold();
      cout << "The big belly of a dragon cannot be satisfied by your mean of food offering" << endl;
      cout << d.getName() << " appreciates the gesture nonetheless..." << endl;
    }
    else if(interaction == "2") {
      d.play();
      d.nextHour();
      d.threshold();
    }
    else if(interaction == "3") {
      d.rest();
      d.nextHour();
      d.threshold();
    }
    else if(interaction == "4") {
      d.roar();
      d.nextHour();
      d.threshold();
    }
    else if(interaction == "5") {
      d.fly();
      d.nextHour();
      d.threshold();
    }
    else if(interaction == "6") {
      d.annihilate();
      d.nextHour();
      d.threshold();
    }
    else if(interaction == "7") {
      d.petStatus();
    }
    else {
      typeWriter("INVALID OPTION!", 50);
    }
  }
}
void gameMenuU(ofstream& save, Unicorn u) {
  save.open(u.getName() + ".txt"); // opening the save file
  string interaction = "1";
  int hungerCount = 0;

  while(interaction != "0") {
    cout << "============================================================================" << endl;
    cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
    cout << "0. Save and quit game" << endl;
    cout << "1. Feed " << u.getName() << endl;
    cout << "2. Play with " << u.getName() << endl;
    cout << "3. Sleep" << endl;
    cout << "4. Gallop with " << u.getName() << endl;
    cout << "5. Chase rainbows with " << u.getName() << endl;
    cout << "6. Nurse creatures of nature with " << u.getName() << endl;
    cout << "7. Check in on " << u.getName() << endl;
    cout << "=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|" << endl;
    cout << "============================================================================" << endl;
    cin >> interaction;
    if(u.getHunger() == 100) { // for starved unicorns.
      hungerCount++;
      if(interaction == "1") {
        hungerCount = 0;
      }
      if(hungerCount == 8) { // if unicorn is at 100 hunger 8 times in a row, the unicorn dies of heartbreak.
        save.close();
        typeWriter("You are a horrible unicorn caregiver...", 150);
        typeWriter("Betrayed by your neglectful nature...", 150);
        typeWriter("Your unicorn dies of a broken heart...", 150);
        typeWriter("...", 200);
        typeWriter("</3", 200);
        typeWriter("...", 200);
        typeWriter("May this unicorn find peace in the world beyond; the world of rainbows...", 150);
        typeWriter("You truly are despicable...", 150);
        remove((u.getName() + ".txt").c_str()); // deleting the save file
        printASCII_gameOver();
        exit(0);
      }
    }
    if(u.getSleepiness() == 200) { // exhausted unicorn
      typeWriter("Exhaustion has struck! The golden horn beings to bow!", 100);
      typeWriter("Your unicorn has passed out...", 150);
      typeWriter("...", 200);
      typeWriter("...", 200);
      typeWriter("...", 200);
      typeWriter("No thanks to your neglect...", 75);
      interaction = "3";
    }
    if(interaction == "0") { // saving the game
      u.threshold();
      typeWriter(" ~~~ Saving game! ~~~ ", 50);
      typeWriter(". . . . . . . . . . . ." , 80);
      printASCII_U();
      save << "Unicorn" << endl;
      save << u.getName() << endl;
      save << u.getHappiness() << endl;
      save << u.getHunger() << endl;
      save << u.getBoredom() << endl;
      save << u.getSleepiness() << endl;
      typeWriter("Save Successful! Thank you for playing!", 50);
      save.close();
      exit(0);
    }
    else if(interaction == "1") {
      u.feed();
      u.nextHour();
      u.threshold();
    }
    else if(interaction == "2") {
      u.play();
      u.nextHour();
      u.threshold();
    }
    else if(interaction == "3") {
      u.rest();
      u.nextHour();
      u.threshold();
    }
    else if(interaction == "4") {
      u.gallop();
      u.nextHour();
      u.threshold();
    }
    else if(interaction == "5") {
      u.rainbow();
      u.nextHour();
      u.threshold();
    }
    else if(interaction == "6") {
      u.nurse();
      u.nextHour();
      u.threshold();
    }
    else if(interaction == "7") {
      u.petStatus();
    }
    else {
      typeWriter("INVALID OPTION!", 50);
    }
  }
}


// Option1 : Create a pet, Option2: Load game.
void option1(ofstream& save) {
  char petChoice;
  string petName;

  typeWriter("Choose your mythical pet! Type the corresponding letter to select a desired pet", 50);
  typeWriter("==============================================================================", 10);
  cout << "Cerberus(C/c): The hound of the Underworld! The cerberus is easily bored and loves to hunt friendly creatures.\n" << endl;
  cout << "Dragon(D/d): Ravenous and slumberous, this mighty creature adores annihilating villages and towns for amusement.\n" << endl;
  cout << "Unicorn(U/u): Majestic by nature, the unicorn is always in a feeling of great elation and loves chasing rainbows with you!" << endl;
  typeWriter("==============================================================================", 10); 
  cin >> petChoice; // creating a Cerberus, Dragon, or Unicorn object depending on petChoice.
  if(petChoice == 'C' || petChoice == 'c') {
    Cerberus C;
    typeWriter("You have selected the CERBERUS, please name your new and loyal three-headed hound!", 50);
    getline(cin >> ws, petName);
    replace(petName.begin(), petName.end(), ' ', '_'); // in case petName has spaces in between, replace with _ to work with files.
    C.setName(petName);
    printASCII_C();
    cout << C.getName(); typeWriter(" is a great name for a cerberus! now time to play!", 50);
    C.setHunger(50); 
    C.setHappiness(50);
    C.setBoredom(50);
    C.setSleepiness(50);
    gameMenuC(save, C); // Calling cerberus game menu.
  } 
  else if(petChoice == 'D' || petChoice == 'd') {
    Dragon D;
    typeWriter("You have selected the DRAGON, please name your new cold-blooded, and fire-breathing lizard!", 50);
    getline(cin >> ws, petName);
    replace(petName.begin(), petName.end(), ' ', '_');
    D.setName(petName);
    printASCII_D();
    cout << D.getName(); typeWriter(" is a great name for a dragon! now time to play!", 50);
    D.setHunger(250);
    D.setHappiness(50);
    D.setBoredom(120);
    D.setSleepiness(150);
    gameMenuD(save, D); // Calling dragon game menu.
  }
  else if(petChoice == 'U' || petChoice == 'u') {
    Unicorn U;
    typeWriter("You have selected the UNICORN, please name your new best friend :)", 50);
    getline(cin >> ws, petName);
    replace(petName.begin(), petName.end(), ' ', '_');
    U.setName(petName);
    printASCII_U();
    cout << U.getName(); typeWriter(" is a great name for a unicorn! now time to play!", 50);
    U.setHunger(50);
    U.setHappiness(250);
    U.setBoredom(25);
    U.setSleepiness(50);
    gameMenuU(save, U); // Calling unicorn game menu.
  }
  else {
    option1(save); // in case of invalid input. 
  }
} 
void option2(ifstream& load, ofstream& save) {
  string petFileName;
  string petFileChoice;
  string savedName, savedHappiness, savedHunger, savedBoredom, savedSleepiness;
  bool validSave = false;
  
  while(validSave == false) {
    typeWriter("Type the name of an existing pet.", 50);
    getline(cin >> ws, petFileName);
    replace(petFileName.begin(), petFileName.end(), ' ', '_'); // In case pet name had spaces in between.
    load.open(petFileName + ".txt");                            // user can type space or '_', both work
    if(load.is_open()) {
      validSave = true;
      load >> petFileChoice; // petFileChoice(first line on save file) is the pet type.
      if(petFileChoice == "Cerberus") { 
        Cerberus C;
        load >> savedName; 
        C.setName(savedName);
        load >> savedHappiness;
        C.setHappiness(stoi(savedHappiness)); // stoi() to convert numerical strings into integer types.
        load >> savedHunger;
        C.setHunger(stoi(savedHunger));
        load >> savedBoredom;
        C.setBoredom(stoi(savedBoredom));
        load >> savedSleepiness;
        C.setSleepiness(stoi(savedSleepiness));
        typeWriter("~~~ Load successful! ~~~" , 50);
        typeWriter(". . . . . . . . . . . ." , 80);
        printASCII_C();
        load.close();
        gameMenuC(save, C); // calling cerberus game menu.
      }
      else if(petFileChoice == "Dragon") {
        Dragon D;
        load >> savedName; 
        D.setName(savedName);
        load >> savedHappiness;
        D.setHappiness(stoi(savedHappiness));
        load >> savedHunger;
        D.setHunger(stoi(savedHunger));
        load >> savedBoredom;
        D.setBoredom(stoi(savedBoredom));
        load >> savedSleepiness;
        D.setSleepiness(stoi(savedSleepiness));
        typeWriter("~~~ Load successful! ~~~" , 50);
        typeWriter(". . . . . . . . . . . ." , 80);
        printASCII_D();
        load.close();
        gameMenuD(save, D); // calling dragon game menu.
      }
      else if(petFileChoice == "Unicorn") {
        Unicorn U;
        load >> savedName; 
        U.setName(savedName);
        load >> savedHappiness;
        U.setHappiness(stoi(savedHappiness));
        load >> savedHunger;
        U.setHunger(stoi(savedHunger));
        load >> savedBoredom;
        U.setBoredom(stoi(savedBoredom));
        load >> savedSleepiness;
        U.setSleepiness(stoi(savedSleepiness));
        typeWriter("~~~ Load successful! ~~~" , 50);
        typeWriter(". . . . . . . . . . . ." , 80);
        printASCII_U();
        load.close();
        gameMenuU(save, U); // calling unicorn game menu.
      }
    }
    else {
      typeWriter("~~~ FILE NOT FOUND! ~~~ ", 50); // if a save file is not found.
      cout << "Reasons for this include..." << endl;
      cout << "\t 1. The name provided does not exist." << endl;
      cout << "\t 2. A pet is dead." << endl;
      cout << "\t 3. User typo." << endl;
    }
  }

}


// The start menu: (1)new game, (2)load game, (3)quit.
string startMenu() {
  string userOption; 
  bool validOption = false;

  printASCII_startMenu();
  while(validOption == false) {
    getline(cin, userOption);
    if(userOption == "1") {
      validOption = true;
    }
    else if(userOption == "2") {
      validOption = true;
    }
    else if(userOption == "3") {
      validOption = true;
      exit(0);
    }
    else {
      typeWriter("Invalid option! Please type 1 to create a new game, 2 to load a game, or 3 to quit!", 50);
    }
  }
  return userOption;
}


int main() {
  ifstream load; // For the save/load system
  ofstream save;
  string menuChoice;

  menuChoice = startMenu(); // Whichever option the user chooses, dictates which function is called 
  if(menuChoice == "1") {    
    option1(save);
  }
  else if(menuChoice == "2") {
    option2(load, save);
  }

  return 0;
}