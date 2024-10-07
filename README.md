# Module 2 Open-Ended Project
#### Beau Albritton
#### Advanced Programming

## Summary
This project intends to be a text-based role playing game inspired by early MS DOS terminal games of the same nature.
When the game starts, the player is prompted with a few limited menu options. 
User input is handled and validated appropriately. 
The main focus of the program is to simulate a game loop of "wild" random encounters
with enemies. A player can attack, view enemy information, run, or exit from an encounter.

These options are pretty self-explanatory. An encounter lasts as long as the creature is alive (health>0), or until a player runs away. The game will continue to progress with random encounters until the player exits the game.
Each creature has a unique name, description, health and experience attributes that can be found in the filepath `../data/entity-data/enemy_creatureinfo.csv`



## Concepts Used 
 * C++ Inherited Class
   * The inherited class for this project, `enemy` can be found in `data/enemy.h`. An `enemy` is-a entity, and inherits all of its base class methods. This class inherited all methods from the `entity` class.
   * *Overridden methods* in the `enemy` class, there are a few overridden methods: generateEntity(), defendAgainst(), attackAgainst(). These use the `virtual` keywords in the base `entity` class and `override` keyword in the child class.
     * For example, generateEntity() in the parent class either generates a null entity or an entity based on parameter input, whereas the generateEntity() in the child class uses unique input from a csv file
 * C++ Component Class
   * The component class for this project `player` can be found in `data/player.h` a `player` has-a entity. A player is supposed to represent you (the user), which has control over the main character in the game. This character can be customized given validated input and has a few methods, like makePlayer() or save()
 * C++ File Input/Output
   * Multiple instances of File Input/Output occur throughout this project:
     * the first example of file input can be seen in `entity.cpp`'s implementation of generateEntity() which reads in information from enemy_creatureinfo.csv
     * the second example (file output) can be seen in `player.cpp`'s implementation of save() which reads player character info into a dedicated csv file for saving progress, and the makePlayer() method which reads in those same values (input vs. output)

## Known Bugs
* Currently, there are no known bugs, the game loop progresses on. For a while, I was not handling if the player's health was less than 0, so for a time the values for player health would go below zero. This has been adjusted for in the main loop.

## Future Work
* Add more entity types, like allied or neutral entities
* Implement multiple entities per each  individual encounter (group or horde class)
* Add inventory or some sort of way to modify player attack beyond experience level manipulation
* Add more functionality to player class, like a list of slain entities or tracking encounters.

## Citations
* At this time, I have really only used concepts from other guided/assisted projects in this class. Otherwise, all code authored by me is authentic (as probably evident) C++ code written by my hands only.

## Grading
* Based on the rubric:
  * **Main Complexity and Usability**
    * 30 points. Since the description for 20 points is the complexity of a guided project, I believe I surpass the complexity of a guided project by quite a bit, as they have been based on inheritance and polymorphism. While I don't incorporate everything from module 2, I still think the program is fairly complex given multiple points of file input/output, large is-a or has-a relationship complexity.
  * **Concept is-a Class**
    * 20 points. I think the `enemy` class written demonstrates inheritance and polymorphism fully, multiple overriden methods that alter class to make distinct child class
  * **Concept has-a class**
    * 15-20 points. I think the `player` class written demonstrates what a component class is supposed to be, it contains an object (in this case an `entity`) and uses this object for unique method calls, such as save()
  * **Concept file input**
    * 10 points Found in `enemy.cpp`, this is the main file input for this project is reading from data/enemy_creatureinfo.csv, loops through and creates unique characters randomly and simulates them in the main loop.
  * * **Concept file output**
    * 5-10 points. Found in `player.cpp`, this is the only file output found in this project. The save() method writes all playerEntity information into entitydata/playerinfo.csv for saving progress and safekeeping. Not extremely complex method but still demonstrates file output
  * **Style and Documentation**
    * 0 points deducted. I made sure to comment and document the code extensively. Concepts are defined in README, in the code. Class entity has been separated into game.h and game.cpp
  * **Video**
    * 0 points deducted. Recorded video
  * **Lifespan of Project**
    * -10 points. All contributions made within 72 hours. *Guilty!!*