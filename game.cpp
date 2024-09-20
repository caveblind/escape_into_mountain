//
// Created by beau on 9/15/2024.
//

#include "game.h"
#include <string>
#include <fstream>
#include <iostream>
#include <random>
using namespace std;

entity::entity() {
    /*
     * Default constructor that generates a random entity and sets its fields appropriately. See method body for more detailed explanation
     */
    generateEntity();
}
// Basic implementation of getters, descriptive names for easy reading
float entity::getHealth() {
    return fHealth;
}

float entity::getExperience() {
    return fExperience;
}


string entity::getName() {
    return fName;
}

string entity::getDescription() {
    return fDescription;
}

int entity::getAlignment() {
    return fAlignment;
}

// Setters, with descriptive names and parameters for easy reading
void entity::setHealth(float pHealth) {
    fHealth = pHealth;
}

void entity::setExperience(float pExperience) {
    fExperience = pExperience;
}

void entity::addExperience(float pExperience) {
    fExperience += pExperience;
}

void entity::setName(string pName) {
    fName = pName;
}

void entity::setDescription(string pDescription) {
    fDescription = pDescription;
}

void entity::setAlignment(int pAlignment) {
    fAlignment = pAlignment;
}

void entity::generateEntity() {
    /*
     * This void type method creates a random entity using data/entity-data/creatureinfo.csv.
     *
     * Firstly, the amount of creatures in the csv file is hardcoded as a constant value for easier looping.
     *
     * the creatureinfo.csv file is loaded into an ifStream file, and a random line is chosen to generate a creature,
     * these values are either read in from getline() or the extractor operator >> and assigned to "this" object via
     * previously defined get and set methods
     */
    const int NUM_CREATURES = 32;
    ifstream fileIn;
    fileIn.open("../data/entity-data/creatureinfo.csv");
    string line,name,description = "nil";
    float health,experience = -1.0;
    int alignment = -2;

    if(fileIn) {
        srand(time(0));
        int randomNumber = rand()%NUM_CREATURES;
        char comma = ',';

        for(int i = 0 ; i<randomNumber; ++i) {
            getline(fileIn,line,'\n');
        }

        getline(fileIn, name, comma);
        getline(fileIn, description, comma);
        fileIn>>health;
        fileIn>>comma;
        fileIn>>experience;
        fileIn>>comma;
        fileIn>>alignment;

        this->setName(name);
        this->setDescription(description);
        this->setHealth(health);
        this->setExperience(experience);
        this->setAlignment(alignment);
    }
    else {
        std::cout << "error";
    }
}

void entity::attackEntity(int pAttackPower) {
    /*
     * This method subtracts the amount of damage an entity receives if attacked during the game.
     */
    this->setHealth(getHealth()-pAttackPower);
}
