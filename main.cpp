//
// Created by beau on 9/9/2024.
//
#include <iostream>
using namespace std;

#include "game.h"

/*
 * Method declarations before main
 */
void displayOptions();
char getInput();
void displayInformation();
int gameLoop();

int main()
{
    /*
     * This main function contains the main gameplay loop. Options are displayed to a user, which selects an input.
     * This input is validated and then handled by a few conditional statements.
     *
     *  There are two while loops (one explicitly called in main, the other called in gameLoop() )that occur to simulate
     *  an endless amount of encounters until the player selects the input for exit.
     *
     */
    cout << "Hello! Welcome to my randomly generated text-based RPG."<<endl;

    //boolean value representing whether or not the game is being played (running)
    bool playing = true;
    while(playing) {
        //Prints a variety of input options for the player
        displayOptions();
        //char input is set to a validated user input
        char input = getInput();
        //conditional statement using input, checking to see if either information, playing the game or exit.
        if(input == 'i') {
            //Prints a variety of input options for an encounter
            displayInformation();
        }
        else if (input == 'p') {
            //See method body for in-depth explanation. Main game loop until 0 is returned.
            gameLoop();
        }
        else if(input == 'e')
        {
            //Exit main loop
            cout<<"Thanks for playing!";
            playing = false;
        }
        else {

            //Error! Try again bozo.
            cout << "Invalid input. Try again.";
        }
    }
    return 0;
}

void displayOptions() {
    //Simple print statements for player input
    cout << "Enter (i) for information about the game."<<endl;
    cout << "Enter (p) to play the game."<<endl;
    cout << "Enter (e) to exit." <<endl;
}
void displayInformation() {
    //Basic information for input in encounter loop
    cout << "This is a turn based text rpg with random encounters."<<endl;
    cout << "Each encounter, you can choose to (a)ttack (r)un or (e)xit to menu." <<endl;
    cout << "Press enter to continue: ";
    cin.get();
}

int gameLoop() {

    //Flavor text
    cout << "You are a nameless knight wandering the Emerald Plains." <<endl;
    //boolean for while loop that represents if the game is played. modified in conditional statements
    bool playing = true;
    while(playing) {
        //More flavor text
        cout << "As you venture on your quest, you see someone approaching!" <<endl;

        //Calls the entity() constructor, evokes generateEntity() method. see game.cpp for detailed description
        entity creature;
        bool inEncounter = true;
        /*
         * Nested while loop. This might seem a little unintuitive at first,
         * however I want to separate the encounter part of gameplay from the actual 'playing'
         * The logic here is that an encounter finishes once the user defeats an entity or
         * if the (r)un option is selected, once this occurs another encounter needs to be generated
         * in an outer loop before another encounter can occur.
         */
        while(inEncounter) {
            //Flavor text and options. The four options will be compared in the following conditionals for char choice;
            cout<< "In front of you is a " <<creature.getName() <<endl;
            cout << "What will you do?" << endl;
            cout << "(a)ttack, (v)iew enemy, (r)un, or (e)xit"<<endl;

            //Sets char choice to a validated user input from getInput();
            char choice = getInput();
            //Then compares if its a, v, r or e.
            if(choice == 'a') {
                /*
                 * Attacking conditional
                 *
                 * srand(time(0) sets a unique float returned from time(0) to use as the seed
                 *
                 * int attack sets a random number in the ranger of 1-100
                 */
                srand(time(0));
                int attack = rand()%100;
                cout << "Attacked for " <<attack << " damage!"<<endl;
                //Uses attackEntity method to subtract health from entity
                creature.attackEntity(attack);
                //Checks to see if the creature has been slain. If so, end encounter
                if(creature.getHealth() <=0) {
                    cout << creature.getName() << " has been slain! There is less evil in the world." <<endl;
                    inEncounter = false;
                    cout <<endl;
                    cout<<"You continue on your quest"<<endl<<endl;
                }
            }
            //Checks the stats/information for an entity
            else if (choice == 'v') {
                //Using overloaded << operator for easy printing to stream
                cout << creature;
            }
            else if (choice == 'r') {
                //Run option, encounter immediately ends.
                cout << "You ran away as fast as you could!";
                cout<<"You continue on your quest"<<endl<<endl;
                inEncounter = false;
            }
            else if (choice == 'e') {
                //Switches off booleans for playing and encounter and returns 0 so that gameLoop() terminates
                inEncounter = false;
                playing = false;
                return 0;

            }
        }

    }

    return 0;
}


char getInput() {
    //rehashing char input from AP1. Hope thats cool
    /*
     *input for "Character" is defined as a *string* of length 1.
     *even though the return value is char. So, I declared
     *two inputs, charInput will be returned, but stringInput
     *is what is being fed the input and being evaluated.
     *
     *Since a string is just a collection of chars, when input is validated
     *to be no longer than one, that means stringInput contains 1 char
     *at stringInput[0] (index 0).
     */
        string stringInput;
        char charInput;
        cout << "Enter a single character:";
        getline(cin,stringInput);
        while(stringInput.empty() || stringInput.length()>1) {
            if(stringInput.empty()) {
                cout<<"No input. ";
            }
            else if(stringInput.length()>1) {
                cout <<"Invalid input. ";
            }
            cout << "Enter a single character:";
            getline(cin,stringInput);
        }
        charInput = stringInput[0];
        return charInput;
}
