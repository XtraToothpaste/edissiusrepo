#include <iostream>
#include "Location.h"
#include "Character.h"
#include "Item.h"
#include "Weapon.h"

using namespace std;


const int NUM_LOCATIONS = 8;
//editing from github.com and pulling...

void options(){
    cout << "| N |go North\n"
            "| E |go East\n"
            "| S |go South\n"
            "| W |go West\n"
            "| T |take an item from the ground\n"
            "| D |drop an item on the ground\n"
            "| R |read something\n"
            "| I |display your inventory\n"
            "| L |get description of your location\n"
            "| C |check up on yourself\n"
            "| Q |exit the game\n"
            "| HP |check up on your health\n"
            "| CLEAR |clear the screen\n\n"
            "t [Enter] note [Enter] is how you should take something from the ground. Do not type: 'Take the note'\n\n"
            "Do not use spaces. 'Glass bottle' is 'bottle' and 'Zippo Lighter' is 'zippo' or 'lighter'.\n\n"
            "Do not use CAPS\n\n";
}

void anxDeath(){
    cout << "Your anxiety levels have risen too greatly for you to handle.\nYou end your life.\n\n";
}

void buildMap(Location allLocations[]){

    //
    //Declaration  of all locations in the game.
    //Numbered 0 - X
    //false if not final room, true if final room
    //

    allLocations[0] = Location("Field", "You're in a grassy field with only the horizon in sight in all directions.\n"
                                        "A note lies on the ground.", false);
    allLocations[1] = Location("Concrete Room", "The room is empty. There is a small round window up too high for you to peek through.", false);
    allLocations[2] = Location("Twisting Shaft", "A passage leads east and south.", false);
    allLocations[3] = Location("Dusty Alcove", "A passage leads south.", false);
    allLocations[4] = Location("Collapsed Cavern", "A passage leads north.", false);
    allLocations[5] = Location("Shores of an Underground Lake", "A passage leads north and west", false);
    allLocations[6] = Location("Passage to the Surface", "A passage leads north and west.", false);
    allLocations[7] = Location("Surface", "This passage gives me the creeps.", true);

    //Declaration of neighbors of all locations.
    //if a location has a neighbor north, user can type N to go to the new location

    allLocations[1].setNeighbor(EAST, &allLocations[2]);

    allLocations[2].setNeighbor(NORTH, &allLocations[1]);
    allLocations[2].setNeighbor(EAST, &allLocations[3]);
    allLocations[2].setNeighbor(SOUTH, &allLocations[5]);

    allLocations[3].setNeighbor(SOUTH, &allLocations[6]);

    allLocations[5].setNeighbor(NORTH, &allLocations[2]);

    allLocations[6].setNeighbor(NORTH, &allLocations[3]);
    allLocations[6].setNeighbor(WEST, &allLocations[7]);
}

int main(){

    //------------------------------------------------------------------
    //CREATING CHARACTER AND MAP ---------------------------------------
    //------------------------------------------------------------------

    Character mainChar("Edissius");
    Location allLocations[NUM_LOCATIONS];
    buildMap(allLocations);

    //------------------------------------------------------------------
    //DECLARATION OF ALL ITEMS -----------------------------------------
    //------------------------------------------------------------------

    Item note("Note", 0);
    note.setDescription("\tHello Edissius,\n"
                        " Next to you is a knife, a glass bottle filled with a dark, viscous liquid, and a Zippo Lighter.\n"
                        " You may take only one.\n"
                        " We will be in touch soon.");
    allLocations[0].aquire(&note);

    Weapon knife("Knife", 10, 10);
    allLocations[0].aquire(&knife);

    Item bottle("Bottle", 10);
    allLocations[0].aquire(&bottle);

    Item zippo("Zippo Lighter", 10);
    allLocations[0].aquire(&zippo);

    //------------------------------------------------------------------
    //SAMPLE TEXT SAMPLE TEXT. -----------------------------------------
    //------------------------------------------------------------------

    //Sets players current location to starting location 0.
    Location* currentLocation = &allLocations[0];

    //Begin the game
    cout << "Type 'h' for help.\n\n"
         << currentLocation->getDescription() << endl << endl;
    currentLocation->visit();

    //Game loop. While the player is not in the room that is an exit, continue playing.
    while(currentLocation->isExit() == false){
        string userInput;

        //Checks if user is dead at end of userInput functions. May need to implement this differently.
        if(mainChar.getHealthPoints() <= 0){
            cout << "Try again?\n\n"
                    ">";
            cin >> userInput;
            if(userInput == "y" || userInput == "yes"){
                mainChar = Character("Edissius");
                currentLocation = &allLocations[0];
                cout << currentLocation->getDescription() << endl << endl;
                currentLocation->visit();
            }
            else{
                exit(0);
            }
        }
        cout << ">";
        cin >> userInput;
        if(userInput == "n" || userInput == "n" || userInput == "NORTH" || userInput == "north" || userInput == "North"){
            if(currentLocation->hasNeighbor(NORTH)){
                currentLocation = currentLocation->getNeighbor(NORTH);
                cout << currentLocation->getDescription() << endl << endl;
                currentLocation->visit();
            }
            else{
                cout << "You can't go that way.\n\n";
            }
        }
        else if(userInput == "e" || userInput == "e" || userInput == "EAST" || userInput == "east" || userInput == "East"){
            if(currentLocation->hasNeighbor(EAST)){
                currentLocation = currentLocation->getNeighbor(EAST);
                cout << currentLocation->getDescription() << endl << endl;
                currentLocation->visit();
            }
            else{
                cout << "You can't go that way.\n\n";
            }
        }
        else if(userInput == "s" || userInput == "s" || userInput == "SOUTH" || userInput == "south" || userInput == "South"){
            if(currentLocation->hasNeighbor(SOUTH)){
                currentLocation = currentLocation->getNeighbor(SOUTH);
                cout << currentLocation->getDescription() << endl << endl;
                currentLocation->visit();
            }
            else{
                cout << "You can't go that way.\n\n";
            }
        }
        else if(userInput == "w" || userInput == "w" || userInput == "WEST" || userInput == "west" || userInput == "West"){
            if(currentLocation->hasNeighbor(WEST)){
                currentLocation = currentLocation->getNeighbor(WEST);
                cout << currentLocation->getDescription() << endl << endl;
                currentLocation->visit();
            }
            else{
                cout << "You can't go that way.\n\n";
            }
        }
        else if(userInput == "t" || userInput == "take"){
            cout << "What do you want to take?\n\n"
                    ">";
            cin >> userInput;
//            if(currentLocation->contains(&userInput) == true){
//                currentLocation->drop(&userInput);
//                mainChar.aquire(&userInput);
//                cout << userInput << " taken.\n\n";
//            }
            if(userInput == "note"){
                if(currentLocation->contains(&note) == true){
                    currentLocation->drop(&note);
                    mainChar.aquire(&note);
                    cout << "Note taken.\n\n";
                }
                else {cout << "You can't take that\n\n";}
            }
            else if(userInput == "knife"){
                if(currentLocation->contains(&knife) == true){
                    currentLocation->drop(&knife);
                    mainChar.aquire(&knife);
                    cout << "Knife taken.\n\n";
                }
                else {cout << "You can't take that\n\n";}
            }
            else if(userInput == "bottle"){
                if(currentLocation->contains(&bottle) == true){
                    currentLocation->drop(&bottle);
                    mainChar.aquire(&bottle);
                    cout << "Bottle taken.\n\n";
                }
                else {cout << "You can't take that\n\n";}
            }
            else if(userInput == "lighter" || userInput == "zippo"){
                if(currentLocation->contains(&zippo) == true){
                    currentLocation->drop(&zippo);
                    mainChar.aquire(&zippo);
                    cout << "Zippo lighter taken.\n\n";
                }
                else{
                    cout << "You can't take that\n\n";
                }
            }
            else {
                cout << "You can't take that\n\n";
            }
            //Teleports the player to the next room after they have chosen their first item.
            if((mainChar.contains(&zippo) || mainChar.contains(&knife) || mainChar.contains(&bottle)) && currentLocation == &allLocations[0]){
                currentLocation = &allLocations[1];
                cout << "You've been teleported to a new area.\n\n";
                cout << currentLocation->getDescription() << endl << endl;
                currentLocation->visit();
            }
        }
        else if(userInput == "d" || userInput == "drop"){
            cout << "What do you want to drop?\n\n"
                    ">";
            cin >> userInput;
            if(userInput == "note"){
                if(mainChar.contains(&note)){
                    mainChar.drop(&note);
                    cout << "Note dropped.\n\n";
                    currentLocation->aquire(&note);
                }
                else{
                    cout << "You can't drop that.\n\n";
                }
            }
            else if(userInput == "knife"){
                if(mainChar.contains(&knife)){
                    mainChar.drop(&knife);
                    cout << "Knife dropped.\n\n";
                    currentLocation->aquire(&knife);
                }
                else{
                    cout << "You can't drop that.\n\n";
                }
            }
            else if(userInput == "lighter"){
                if(mainChar.contains(&zippo)){
                    mainChar.drop(&zippo);
                    cout << "Zippo lighter dropped.\n\n";
                    currentLocation->aquire(&zippo);
                }
                else{
                    cout << "You can't drop that.\n\n";
                }
            }
            else if(userInput == "bottle"){
                if(mainChar.contains(&bottle)){
                    mainChar.drop(&bottle);
                    cout << "Glass bottle dropped.\n\n";
                    currentLocation->aquire(&bottle);
                }
                else{
                    cout << "You can't drop that.\n\n";
                }
            }
            else{
                cout << "You can't drop that.\n\n";
            }
        }
        else if(userInput == "i" || userInput == "inventory"){
            mainChar.showInventory();
        }
        else if(userInput == "c" || userInput == "check" || userInput == "Check" || userInput == "CHECK"){
            cout << mainChar.getAnxDescription() << endl << endl;
            if(mainChar.getAnxLevel() >= 65){
                anxDeath();
                //mainChar.takeDamage(mainChar.getHealthPoints());
            }
        }
        else if(userInput == "hp" || userInput == "HP"){
            cout << "Health: " << mainChar.getHealthPoints() << endl << endl;
        }
        else if(userInput == "h" || userInput == "H" || userInput == "Help"){
            options();
        }
        else if(userInput == "l" || userInput == "look" || userInput == "Look"){
            cout << currentLocation->getDescription() << endl;
            cout << currentLocation->getDetails() << endl;
            currentLocation->showInventory();
            cout << endl;
        }
        else if(userInput == "kms"){
            mainChar.takeDamage(100);
        }
        else if(userInput == "clear"){
            for(int i = 0; i < 75; i++){
                cout << endl;
            }
        }
        else if(userInput == "r" || userInput == "read"){
            cout << "What do you want to read?\n\n"
                    ">";
            cin >> userInput;
            if(userInput == "note"){
                if(mainChar.contains(&note)){
                    cout << note.getDescription() << "\n\n";
                }
                else{
                    cout << "You can't read that.\n\n";
                }
            }
            else{
                cout << "You can't read that.\n\n";
            }
        }
        else if(userInput == "q" || userInput == "quit" || userInput == "Quit"){
            cout << "Are you sure?" << endl << endl;
            cout << ">";
            cin >> userInput;
            if(userInput == "y" || userInput == "yes" || userInput == "YES" || userInput == "Yes"){
                exit(0);
            }
            else {
                cout << currentLocation->getDescription() << endl << endl;
            }
        }
        else if(userInput == "thereisnocowlevel"){
            break;
        }
        else{
            cout << "I do not understand\n\n";
        }
    }

    //End of While Loop, game ends.

    cout << "\nYou've beaten the game. Well done.\n\n";
}
