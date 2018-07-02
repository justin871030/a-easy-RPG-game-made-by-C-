#pragma once
#include"AbstractMonster.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


#ifndef ZB_MON
#define ZB_MON

class ZombieMonster :public AbstractMonster
{
public:
	ZombieMonster(string = "Zombie", int = 50, int = 65, int = 17, int = 150, int = 30);
	~ZombieMonster();

	string race = "Zombie";

	virtual void attackTo(GeneralPlayer*);
	void status();
};

#endif
