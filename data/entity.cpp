//
// Created by beau on 9/15/2024.
//

#include "entity.h"
#include <string>
#include <fstream>
#include <iostream>
#include <random>
using namespace std;

/*
 * Default constructor that generates a random entity and sets its fields appropriately. See method body for more detailed explanation
 */
entity::entity() {

    generateEntity();
}
/*
 * Other constructor that generates a random entity and sets its fields appropriately. See method body for more detailed explanation
 */
entity::entity(float pHealth, float pExperience, string pName, string pDescription, int pAlignment) {

    generateEntity(pHealth, pExperience, pName, pDescription, pAlignment);
}
/*
 * Generates null entity on base call for later demonstration of overriding
 */
void entity::generateEntity() {


    generateEntity(0, 0, "nil", "nil", -1);
};

/*
 * Generates entity specific to parameters
 */
void entity::generateEntity(float pHealth, float pExperience, string pName, string pDescription, int pAlignment) {
    setHealth(pHealth);
    setBaseHealth(pHealth);
    setExperience(pExperience);
    setName(pName);
    setDescription(pDescription);
    setAlignment(pAlignment);
}


// Basic implementation of getters, descriptive names for easy reading
float entity::getHealth() {
    return fHealth;
}

int entity::getExperience() {
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

void entity::setExperience(int pExperience) {
    fExperience = pExperience;
}

void entity::addExperience(int pExperience) {
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

/*
 *Sets status to defending, overriden in child class
 */
void entity::defendAgainst(entity &pTaraget) {
    this->setStatus("Defending");
}

/*
 * void attackAgainst() takes in a reference to an entity and a integer value to lower attack
 *
 * Checks to see if the other entity is "Defending" if not, lower health and announce damage.
 */
void entity::attackAgainst(entity &pTarget, int pLowerBy){
    if(pTarget.getStatus().compare("Defending")) {
        pTarget.setHealth(pTarget.getHealth()-pLowerBy);
        cout << pLowerBy << " damage!"<<endl;
        this->setStatus("Attacking");
    }
    else {
        cout << ".. Creature defended attack!" << endl;
    }
}

//Set methods for new fields
void entity::setStatus(string pStatus) {
    this->fStatus = pStatus;
}
string entity::getStatus() {
    return this->fStatus;
}

void entity::setBaseHealth(float pHealth) {
    this->fBaseHealth = pHealth;
}
float entity::getBaseHealth() {
    return fBaseHealth;
}

