#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

KnightPlayer::KnightPlayer()// default constructor
{
	race = "Knight";
	setName();
	setLevel(1);
	setExp(0);
	recoverHP();
	recoverMP();
}
KnightPlayer::KnightPlayer(int Level) // normal constructor
{
	race = "Knight";
	setName();
	setLevel(Level);
	setExp(0);
	recoverHP();
	recoverMP();
}
KnightPlayer::KnightPlayer(string Name) // normal constructor
{
	race = "Knight";
	setName(Name);
	setLevel(1);
	setExp(0);
	recoverHP();
	recoverMP();
}
KnightPlayer::KnightPlayer(int Level, string Name) // normal constructor
{
	race = "Knight";
	setName(Name);
	setLevel(Level);
	setExp(0);
	recoverHP();
	recoverMP();
}
KnightPlayer::KnightPlayer(const KnightPlayer&Player)
{
	race = "Knight";
	setName(Player.name);
	setLevel(Player.level);
	setExp(Player.exp);
	recoverHP();
	recoverMP();
}
void  KnightPlayer::setLevel(int Level) // need to call setAttr() inside
{
	if (Level<0)
	{
		cout << "You set a wrong level !";
	}
	else
	{
		level = Level;
		setAttr(level);
	}
}
void KnightPlayer::setAttr(int Level) // parameter is level
{
	max_hp = 150 + 25 * Level;
	max_mp = 70 + 10 * Level;
	attack = 40 + 10 * Level + extra_attack;
	defense = 20 + 12 * Level + extra_defense;
	lvup_exp = pow(10, log(Level + 1) / log(2));
}
void KnightPlayer::levelUp(void) // level++
{
	setLevel(level + 1);
}
void KnightPlayer::increaseExp(int EXP)
{
	if (exp + EXP >= 0)
	{
		exp += EXP;
	}
	while (exp >= lvup_exp)
	{
		levelUp();
	}
}
void KnightPlayer::specialSkill()
{
	heal();
}
void KnightPlayer::heal(void)
{
	if (mp - (level * -5)>0)
	{
		increaseHP(level * 10);
		increaseMP(level * -5);
	}
}
void KnightPlayer::status()
{
	cout << race << "-" << name << " (Lv." << level << ")" << endl;
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}