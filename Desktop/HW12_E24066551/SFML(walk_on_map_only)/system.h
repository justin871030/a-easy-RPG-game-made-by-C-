#pragma once
#ifndef SYSTEM
#define STSTEM
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Battle.h"
#include"Field.h"
class GeneralPlayer;
class OrcPlayer;
class KnightPlayer;
class MagicianPlayer;
class AbstractMonster;
class GoblinMonster;
class ZombieMonster;
class JWMonster;

class System
{
public:
	System(vector<string>,int=10,int=10);
	vector<Map> maps;
	vector<string> map_name;
	vector<GeneralPlayer*>players;
	GeneralPlayer players_backpack;
	vector<vector<string>> storys;

	int sight_length;
	int sight_width;
	void print_title(Field*,int);
	void run();
	void set_mapname(vector<string>);
	
	void Save();
	void Load();
    
	RenderWindow* window;
	int position = 6;
	int current_position = 1;
	int start_point=1;

	int save = 0;

	void SFML();

};

#endif