#pragma once
#include"GeneralPlayer.h"
#include"AbstractMonster.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef BATTLE
#define BATTLE

struct Character {
	char type; // monster(．m・) or player(．p・)?
	bool alive; // alive(true) or dead(false)?

	//template<class N>
	void *instance; // pointer to instance
};


class Battle
{
public:
	Battle(GeneralPlayer**, AbstractMonster**, int, int, int);
	//First parameter indicates the array / list of players to attend
	//The second one is for monsters
	//The third and forth parameter indicates the number of players and monsters
	//The fifth parameter represents the limit on number of turns
	Battle(GeneralPlayer**, AbstractMonster**, int, int);
	//The fifth parameter is omitted, set turn_limit to 0
	//This means this battle has no limit on number of turns
	Battle(vector<GeneralPlayer*>, vector<AbstractMonster*>, int, int, int);
	Battle(vector<GeneralPlayer*>, vector<AbstractMonster*>, int, int);
	Battle(vector<GeneralPlayer>player, vector<AbstractMonster>monster, int num_p, int num_m);
	bool nextActor(void);
	//Move to next actor, if all character were done, n_turn++
	//The return value indicates whether it exceeds limit on number of turns
	int getTurnCount(void) const;
	//Get the current number of turn
	int getTurnLimit(void) const;
	//Get the limit on number of turns, 0 for no limit
	int getPlayerCount(void) const;
	int getPlayerCount(bool) const;
	//Get the current number of players
		//If the second parameter set to true, only alive players will be counted
		//If the second parameter is omitted, return count for all players
	int getMonsterCount(void) const;
	int getMonsterCount(bool) const;
	//Similar to above ones, but this set of methods return the information of monsters
	Character getCurrentActor(void);
	//Get the current actor within the action list
		//Note that the type of return value is struct Character
	Character* getPlayers(void);
	//Get a full list of players, no matter dead of alive ones
	Character* getMonsters(void);
	//Get a full list of monsters, no matter dead of alive ones
	void run();

private:

	int n_turn;//The number of turn, should be initialized to 0 in constructor
	int turn_limit;//Maximum number of turn, 0 for no limit
	Character* action_list;
	//An ordered action list, indicates the order of action
	int action_turn;
	Character* player_list;
	Character* monster_list;
	int num_player;
	int num_monster;

	
	void status();
};

#endif