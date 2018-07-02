#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include"GeneralPlayer.h"
using namespace std;

#ifndef OrcPlayerclass
#define OrcPlayerclass

class OrcPlayer:public GeneralPlayer
{
public:
	string race = "Orc";
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(string);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void increaseExp(int EXP);

	virtual void specialSkill();

	virtual void status();
};
#endif
