#ifndef POKEMON_H
#define POKEMON_H

#include "Ability.h"
#include "PokeType.h"
#include "PokeMove.h"
#include "StatsData.h"
#include <vector> // Include necessary header for vector
#include <string.h>

using namespace std;

class Pokemon {
public:
    Pokemon();
    Pokemon(const StatsData& stats);

    void setName(std::string param);
    std::string getName();

    void setBaseHp(int param);
    void setBaseAttack(int param);
    void setBaseDefense(int param);
    void setBaseSpAttack(int param);
    void setBaseSpDefense(int param);
    void setBaseSpeed(int param);

    int getBaseHp();
    int getBaseAttack();
    int getBaseDefense();
    int getBaseSpAttack();
    int getBaseSpDefense();
    int getBaseSpeed();

    void setIvHp(int param);
    void setIvAttack(int param);
    void setIvDefense(int param);
    void setIvSpAttack(int param);
    void setIvSpDefense(int param);
    void setIvSpeed(int param);

    int getIvHp();
    int getIvAttack();
    int getIvDefense();
    int getIvSpAttack();
    int getIvSpDefense();
    int getIvSpeed();

    void setEvHp(int param);
    void setEvAttack(int param);
    void setEvDefense(int param);
    void setEvSpAttack(int param);
    void setEvSpDefense(int param);
    void setEvSpeed(int param);

    int getEvHp();
    int getEvAttack();
    int getEvDefense();
    int getEvSpAttack();
    int getEvSpDefense();
    int getEvSpeed();

    void setLevel(int param); 
    int getLevel(); 
    void setNature(Nature param); 
    Nature getNature(); 
    void setGender(Gender param); 
    Gender getGender(); 
    void setTypes(const vector<PokeType>& param); 
    vector<PokeType> getTypes(); 

    std::vector<PokeMove>& getMoves();
    void setMoves(const vector<PokeMove> param);

    void takeDamage(int param);
    void healDamage(int param);
    bool isAlive();

private:
    std::string name;
    int currHp;

    int hp;   // max hp, calculated based on baseHp, ivHp, evHp, level
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;

    int baseHp;
    int baseAttack;
    int baseDefense;
    int baseSpAttack;
    int baseSpDefense;
    int baseSpeed;

    int ivHp;
    int ivAttack;
    int ivDefense;
    int ivSpAttack;
    int ivSpDefense;
    int ivSpeed;

    int evHp;
    int evAttack;
    int evDefense;
    int evSpAttack;
    int evSpDefense;
    int evSpeed;

    int level;
    Nature nature;
    Gender gender;
    std::vector<PokeType> types;
    std::vector<PokeMove> moves;
    Ability ability;
    int catchRate;
};

#endif   // POKEMON_H
