#include "Ability.h"
#include "Battle.h"
#include "Game.h"
#include "PokeMove.h"
#include "Pokemon.h"
#include "StatsData.h"
#include "utility.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    std::ifstream f("movelist.json");
    json data = json::parse(f);

    struct PokeMove attack1;
    attack1.name = "attack1";
    
    struct PokeMove attack2;
    attack2.name = "attack2";

    struct PokeMove attack3;
    attack3.name = "attack3";

    struct PokeMove attack4;
    attack4.name = "attack4";

    Pokemon myPokemon = Pokemon();
    myPokemon.setName("my pokemon");
    Pokemon enemyPokemon = Pokemon();
    enemyPokemon.setName("enemy pokemon");

    std::vector<PokeMove> moveList;
    moveList.push_back(attack1);
    moveList.push_back(attack2);
    moveList.push_back(attack3);
    moveList.push_back(attack4);

    myPokemon.setMoves(moveList);
    enemyPokemon.setMoves(moveList);

    std::vector<Pokemon*> myPkmnList;
    myPkmnList.push_back(&myPokemon);

    std::vector<Pokemon*> enemyPkmnList;
    enemyPkmnList.push_back(&enemyPokemon);

    Battle newBattle = Battle(myPkmnList, enemyPkmnList);
    newBattle.doBattle();


    return 0;
}
