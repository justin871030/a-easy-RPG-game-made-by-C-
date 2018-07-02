#pragma once
#include"AbstractMonster.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


#ifndef GBL_MON
#define GBL_MON

class GoblinMonster:public AbstractMonster
{
public:
	GoblinMonster(string= "Goblin", int=60, int=40, int=12, int=100, int=50);
	~GoblinMonster();

	string race = "Goblin";

	virtual void attackTo(GeneralPlayer*);
	void status();
};
#endif
