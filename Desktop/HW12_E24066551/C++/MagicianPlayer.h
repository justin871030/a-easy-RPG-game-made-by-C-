#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include"GeneralPlayer.h"
using namespace std;

#ifndef MagicianPlayerclass
#define MagicianPlayerclass





class MagicianPlayer :public GeneralPlayer
{
public:
	string race = "Magician";
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(string);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void increaseExp(int EXP);

	virtual void specialSkill();
	void pray(void);

	virtual void status();
};
#endif