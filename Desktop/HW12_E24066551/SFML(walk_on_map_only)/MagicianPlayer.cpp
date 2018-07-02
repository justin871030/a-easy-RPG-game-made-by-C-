#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

MagicianPlayer::MagicianPlayer()// default constructor
{
	race = "Magic";
	setName();
	setLevel(1);
	setExp(0);
	recoverHP();
	recoverMP();
}
MagicianPlayer::MagicianPlayer(int Level) // normal constructor
{
	race = "Magic";
	setName();
	setLevel(Level);
	setExp(0);
	recoverHP();
	recoverMP();
}
MagicianPlayer::MagicianPlayer(string Name) // normal constructor
{
	race = "Magic";
	setName(Name);
	setLevel(1);
	setExp(0);
	recoverHP();
	recoverMP();
}
MagicianPlayer::MagicianPlayer(int Level, string Name) // normal constructor
{
	race = "Magic";
	setName(Name);
	setLevel(Level);
	setExp(0);
	recoverHP();
	recoverMP();
}
MagicianPlayer::MagicianPlayer(const MagicianPlayer&Player)
{
	race = "Magic";
	setName(Player.name);
	setLevel(Player.level);
	setExp(Player.exp);
	recoverHP();
	recoverMP();
}
void  MagicianPlayer::setLevel(int Level) // need to call setAttr() inside
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
void MagicianPlayer::setAttr(int Level) // parameter is level
{
	max_hp = 120 + 15 * Level;
	max_mp = 100 + 15 * Level;
	attack = 30 + 8 * Level + extra_attack;
	defense = 20 + 7 * Level + extra_defense;
	lvup_exp = pow(10, log(Level + 1) / log(2));
}
void MagicianPlayer::levelUp(void) // level++
{
	setLevel(level + 1);
}
void MagicianPlayer::increaseExp(int EXP)
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
void MagicianPlayer::specialSkill()
{
	pray();
}
void MagicianPlayer::pray()
{
	if (hp-(level * -5)>0)
	{
		increaseMP(level * 10);
		increaseHP(level * -5);
	}
}
void MagicianPlayer::status()
{
	/*cout << "Name:" << name << endl;
	cout << "Race:" << race << endl;
	cout << "Level:" << level << endl;
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;*/
	cout << race << "-" << name << " (Lv." << level << ")" << endl;
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}