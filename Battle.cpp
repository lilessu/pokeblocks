#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "PokeMove.h"
#include "PokeType.h"
#include "StatsData.h"
#include "utility.h"
#include "Ability.h"
#include "Pokemon.h"
#include "Battle.h"

void Battle::printBattleStartMsg() {
    // teamA: 
    if (Battle::teamA.size() == 1) {
        std::cout << "You sent out " << Battle::teamA[0]->getName() << "!" << std::endl;
    }
    else if (Battle::teamA.size() > 1) {
        std::cout << "You sent out " << Battle::teamA[0]->getName() << "!" << std::endl;

        for (size_t i = 1; i < Battle::teamA.size(); i++) {
            std::cout << "You also sent out " << Battle::teamA[i]->getName() << "!" << std::endl;
        }
    }
    else {  // teamA size somehow 0 
        std::cout << "ERROR: TEAM A HAS 0 POKEMON... TERMINATING" << std::endl;
        exit(1);
    }

    // teamB:
    if (Battle::teamB.size() == 1) {
        std::cout << "Opponent sent out " << Battle::teamB[0]->getName() << "!" << std::endl;
    }
    else if (Battle::teamB.size() > 1) {
        std::cout << "Opponent sent out " << Battle::teamB[0]->getName() << "!" << std::endl;

        for (size_t i = 1; i < Battle::teamB.size(); i++) {
            std::cout << "Opponent also sent out " << Battle::teamB[i]->getName() << "!" << std::endl;
        }
    }
    else {  // teamB size somehow 0 
        std::cout << "ERROR: TEAM B HAS 0 POKEMON... TERMINATING" << std::endl;;
        exit(1);
    }

    return;
}

void Battle::doTurn() {
    


        

    
}

void Battle::getPokemonAttackTarget(Pokemon* currPokemon, int chosenMoveInt, bool& param) {
    int playerChoice;

    while (true) {
        for (size_t i = 0; i < Battle::teamB.size() + 1; i++) {
            if (i < Battle::teamB.size()) {
                std::cout << "(" << i << "): " << "Opponent's " << Battle::teamB[i]->getName() << std::endl;
            }
            else {
                std::cout << "-------" << std::endl;
                std::cout << "(" << i << "): Back" << std::endl;
            }
        }
        std::cin >> playerChoice;
        if (static_cast<size_t>(playerChoice) == Battle::teamB.size()) {
            return; // let player go back a menu
        }
        else if (static_cast<size_t>(playerChoice) == 0 && static_cast<size_t>(playerChoice) < Battle::teamB.size()) {
            param = true;
            Battle::TurnChoice newTurnChoice;
            newTurnChoice.team = 'a';
            newTurnChoice.movingPokemon = currPokemon;
            newTurnChoice.chosenMove = &currPokemon->getMoves()[chosenMoveInt];
            newTurnChoice.chosenTarget = Battle::teamB[playerChoice];
            Battle::turnChoiceVec.push_back(newTurnChoice);
            std::cout << "CHOICE MADE: " << newTurnChoice.chosenMove->name << std::endl;
            return;

        }
        else if (static_cast<size_t>(playerChoice) == 1 && static_cast<size_t>(playerChoice) < Battle::teamB.size()) {
            param = true;
            Battle::TurnChoice newTurnChoice;
            newTurnChoice.team = 'a';
            newTurnChoice.movingPokemon = currPokemon;
            newTurnChoice.chosenMove = &currPokemon->getMoves()[chosenMoveInt];
            newTurnChoice.chosenTarget = Battle::teamB[playerChoice];
            Battle::turnChoiceVec.push_back(newTurnChoice);
            std::cout << "CHOICE MADE: " << newTurnChoice.chosenMove->name << std::endl;
            return;
        }
        else {
            std::cout << "Invalid Choice." << std::endl;
        }
        if (param) {
            break;
        }
    }
}

void Battle::getPokemonAttackChoice(Pokemon* currPokemon, bool& param) {
    int playerChoice;

    while (true) {
        const std::vector<PokeMove>& movesList = currPokemon->getMoves();

        for (size_t i = 0; i < movesList.size() + 1; i++) {
            if (i < movesList.size()) {
                std::cout << "(" << i << "): " << movesList[i].name << std::endl;
            } else {  // give option to leave if param is false
                std::cout << "-------" << std::endl;
                std::cout << "(" << i << "): Back" << std::endl;
            }
        }
        std::cin >> playerChoice;
        if (static_cast<size_t>(playerChoice) == movesList.size()) {
            param = false; // User chose to go back
            return; // Exit the method to allow choosing again
        } else if (playerChoice >= 0 && static_cast<size_t>(playerChoice) < movesList.size()) {
            Battle::getPokemonAttackTarget(currPokemon, playerChoice, param);
            if (param) {
                return; // A choice was made
            }
            // If param is false here, it means the user chose to go back from the target selection, continue choosing moves
        } else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

void Battle::getAttackChoice(bool& param) {
    // This loop structure assumes that going back is handled within getPokemonAttackChoice
    for (size_t i = 0; i < Battle::teamA.size() && !param; i++) {
        getPokemonAttackChoice(Battle::teamA[i], param);
        if (!param) {
            break; // If param is false after returning, the user chose to go back
        }
    }
}

void Battle::getItemChoice(bool& param) {
    param = true;
    std::cout << "made item choice" << std::endl;
}

void Battle::getSwitchChoice(bool& param) {
    param = true;
    std::cout << "made switch choice" << std::endl;
}

void Battle::getRunChoice(bool& param) {
    param = true;
    std::cout << "made run choice" << std::endl;
}

void Battle::getChoice() {
    int playerInput;
    bool choiceMade = false;

    while (true) {
        std::cout << "(0): Attack" << std::endl;
        std:: cout << "(1): Use Item" << std::endl;
        std::cout << "(2): Switch" << std::endl;
        std::cout << "(3): Run" << std::endl;

        std::cin >> playerInput;

        if (playerInput == 0) { // attack
            Battle::getAttackChoice(choiceMade);
        }
        else if (playerInput == 1) {    // item
            Battle::getItemChoice(choiceMade);
        }
        else if (playerInput == 2) {    // switch
            Battle::getSwitchChoice(choiceMade);
        }
        else if (playerInput == 3) {    // run
            Battle::getRunChoice(choiceMade);
        }
        else {
            std::cout << "Invalid input." << std::endl;
        }

        if (choiceMade) {
            break;
        }
    }
}


void Battle::doBattle() {
    Battle::printBattleStartMsg();

    while (true) {
        getChoice();
        std::cout << "Turn done. Continue?" << std::endl;
        bool answer;
        std::cin >> answer;
        if (!answer) {
            std::cout << "ending game" << std::endl;
            exit(1);
        }

    }
}


Battle::Battle( std::vector<Pokemon*>& paramTeamA,  std::vector<Pokemon*>& paramTeamB)
    : teamA(paramTeamA), teamB(paramTeamB), turnNum(0) {
}