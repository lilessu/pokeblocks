#include "Pokemon.h"
#include "Ability.h"

using namespace std;

Pokemon::Pokemon() :
    currHp(0), 
    hp(0), 
    attack(0), 
    defense(0), 
    spAttack(0), 
    spDefense(0), 
    speed(0),
    baseHp(0),
    baseAttack(0),
    baseDefense(0),
    baseSpAttack(0),
    baseSpDefense(0),
    baseSpeed(0),
    ivHp(0),
    ivAttack(0),
    ivDefense(0),
    ivSpAttack(0),
    ivSpDefense(0),
    ivSpeed(0),
    evHp(0),
    evAttack(0),
    evDefense(0),
    evSpAttack(0),
    evSpDefense(0),
    evSpeed(0),
    level(0),
    nature(),
    gender(),
    types(),
    moves(),
    ability(),
    catchRate(0)
{}

Pokemon::Pokemon(const StatsData& stats)
    : currHp(stats.currHp)
    , hp(stats.hp)
    , attack(stats.attack)
    , defense(stats.defense)
    , spAttack(stats.spAttack)
    , spDefense(stats.spDefense)
    , speed(stats.speed)
    , baseHp(stats.baseHp)
    , baseAttack(stats.baseAttack)
    , baseDefense(stats.baseDefense)
    , baseSpAttack(stats.baseSpAttack)
    , baseSpDefense(stats.baseSpDefense)
    , baseSpeed(stats.baseSpeed)
    , ivHp(stats.ivHp)
    , ivAttack(stats.ivAttack)
    , ivDefense(stats.ivDefense)
    , ivSpAttack(stats.ivSpAttack)
    , ivSpDefense(stats.ivSpDefense)
    , ivSpeed(stats.ivSpeed)
    , evHp(stats.evHp)
    , evAttack(stats.evAttack)
    , evDefense(stats.evDefense)
    , evSpAttack(stats.evSpAttack)
    , evSpDefense(stats.evSpDefense)
    , evSpeed(stats.evSpeed)
    , level(stats.level)
    , nature(stats.nature)
    , gender(stats.gender)
    , types(stats.types)
    , moves(stats.moves)
    , ability(stats.ability)
    , catchRate(stats.catchRate) {}

    std::vector<PokeMove>& Pokemon::getMoves() {
        return moves;
    }

    void Pokemon::setMoves(std::vector<PokeMove> moveList) {
        for (size_t i = 0; i < moveList.size(); i++) {
            Pokemon::moves.push_back(moveList[i]);
        }
    }

std::string Pokemon::getName() {
    return Pokemon::name;
}

void Pokemon::setName(std::string param) {
    Pokemon::name = param;
}