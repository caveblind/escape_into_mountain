//
// Created by beau on 10/6/2024.
//

#include "enemy.h"

#include <complex>
#include <fstream>
#include <memory>

/*
 *Enemy base constructor, calls parent constructor, then overriden generateEntity();
 *sets fPower to the enemies experience divided by 10
 */

enemy::enemy(){
    this->generateEntity();
    fPower = (this->fExperience) / 10;

}

//Calls generate entity parent class with specific filepath in mind,
/*
 * This void type method creates a random entity using data/entity-data/enemy_creatureinfo.csv.
 *
 * Firstly, the amount of creatures in the csv file is hardcoded as a constant value for easier looping.
 *
 * the creatureinfo.csv file is loaded into an ifStream file, and a random line is chosen to generate a creature,
 * these values are either read in from getline() or the extractor operator >> and assigned to "this" object via
 * previously defined get and set methods.
 *
 * This overrides the entity.cpp implementation as those two either return a specific entity or a null value (see parent class for idea)
 */
void enemy::generateEntity() {
    const int NUM_CREATURES = 52;
    ifstream fileIn;
    fileIn.open("../data/entity-data/enemy_creatureinfo.csv");
    string line,name,description = "nil";
    float health,experience = -1.0;
    int alignment = -2;

    if(fileIn) {
        srand(time(NULL));
        int randomNumber = rand()%NUM_CREATURES;
        char comma = ',';

        for(int i = 0 ; i<randomNumber; ++i) {
            getline(fileIn,line,'\n');
        }

        //Reading input from filein
        getline(fileIn, name, comma);
        getline(fileIn, description, comma);
        fileIn>>health;
        fileIn>>comma;
        fileIn>>experience;
        fileIn>>comma;
        fileIn>>alignment;
        //Setting input with read values
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
/*
 * Helper method for attackAgainst()
 */
void attack(entity &pTarget,int pLowerBy) {
    cout <<  pLowerBy << " damage!"<<endl;
    //Lowers reference entity's health by specific int value
    pTarget.setHealth(pTarget.getHealth()-pLowerBy);
}
/*
 * attackAgainst(entity &pTarget) takes in an entity reference to attack.
 *
 * Firstly, it checks if the status of the entity is set to "Defending" or not (Enemy cannot attack defending target),
 * if so, simulates a random dice roll from a d20, and does dammage according to if it's a critical hit,failure, or normal attack
 *
 * Otherwise, a target is defending, so enemy will try to break the defense with a 1/10 chance of success.
 */
void enemy::attackAgainst(entity &pTarget) {
    //random seed at current time for later rand use
    srand(time(NULL));
    cout << this->getName() + " is attacking!"<<endl;
    if(pTarget.getStatus() != "Defending") {
        //Target is not defending

        //Simulate rolling a 20 sided dice
        int random = rand()%20;

        //If 20 was rolled or if the player character is prone returns 0 so !0 is 1
        if(random == 0 || pTarget.getStatus() == "Prone") {
            //If 20, roll a critical success
            cout << "Critical Hit!"<<endl;
            attack(pTarget,fPower* (rand()%2)+1);

        }
        else if (random == 1 ) {
            //If 1, (1%20 = 1) roll a critical fail
            cout << "Critical Failure!"<<endl;
            attack(pTarget,fPower*.1);
        }
        else {
            //Normal attack
            cout << "Attack! ";
            attack(pTarget,fPower);
        }
        this->setStatus("Attacking");
    }
    else {
        //Target is defending, 1/10 chance that an attack will break defense, damaging an enemy and leaving them prone

        if(rand()%10 == 0 ) {
            //Defense has been broken
            pTarget.attackAgainst(pTarget, (rand()%100)/100);
            this->setStatus("Attacking");
            pTarget.setStatus("Prone");
        }
        else
            //Still kicking
            cout << "Defended attack succesfully."<<endl;
    }

}
/*
 * defendAgainst(entity &pTarget) takes in an entity reference to defend against.
 *
 * There is a 1% chance that a defense can be broken randomly, which causes the creature to be exposed.
 * Instead, there is a successful change to the entity's status set as "Defending"
 *
 * Overrides parent method
 */
void enemy::defendAgainst(entity &pTarget) {
    srand(time(NULL));
    //1% chance defense fails
    cout << this->getName() << " is defending!"<<endl;
    if(rand()%100 == 0) {
        cout << "Failed to defend! Creature is now exposed"<<endl;
        this->setStatus("Prone");
    }
    else {
        this->setStatus("Defending");
    }

}

/*
 * bool move_against(entity &pTarget) uses the two methods attackAgainst() and defendAgainst()
 * with various conditionals to decide the 'optimal' move for the enemy,
 *
 * returns true if enemy attacks, and false otherwise (Defense)
 */
bool enemy::move_against(entity &pTarget) {
    srand(time(NULL));
    //If the target is prone, always attack
    if(pTarget.getStatus()=="Prone"){
            attackAgainst(pTarget);
        return true;
    }
    //Else check health if under half of base health
    if(this->getHealth() < this->getBaseHealth()/2) {
        //Then 50/50 chance of attacking/defending
        if(rand()%2 == 0) {
            this->attackAgainst(pTarget);
            return true;
        }
        else {
            this->defendAgainst(pTarget);
            return false;
        }
    }

    //Else 75/25 chance to attack or defend
    if(rand()% 4 != 0 ) {
        this->attackAgainst(pTarget);
        return true;
    }
    else {
        this->defendAgainst(pTarget);
        return false;
    }






}



