#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include"GeneralPlayer.h"
using namespace std;

#ifndef KnightPlayerPlayerclass
#define KnightPlayerPlayerclass





class KnightPlayer :public GeneralPlayer
{
public:
	string race = "Knight";
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(string);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void increaseExp(int EXP);

	virtual void specialSkill();
	void heal(void);

	virtual void status();
};
#endif
