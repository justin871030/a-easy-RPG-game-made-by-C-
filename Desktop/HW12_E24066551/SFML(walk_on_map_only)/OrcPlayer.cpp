#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

OrcPlayer::OrcPlayer()// default constructor
{
	race = "Orc";
	setName();
	setLevel(1);
	setExp(0);
	recoverHP();
	recoverMP();
}
OrcPlayer::OrcPlayer(int Level) // normal constructor
{
	race = "Orc";
	setName();
	setLevel(Level);
	setExp(0);
	recoverHP();
	recoverMP();
}
OrcPlayer::OrcPlayer(string Name) // normal constructor
{
	race = "Orc";
	setName(Name);
	setLevel(1);
	setExp(0);
	recoverHP();
	recoverMP();
}
OrcPlayer::OrcPlayer(int Level, string Name) // normal constructor
{
	race = "Orc";
	setName(Name);
	setLevel(Level);
	setExp(0);
	recoverHP();
	recoverMP();
}
OrcPlayer::OrcPlayer(const OrcPlayer&Player)
{
	race = "Orc";
	setName(Player.name);
	setLevel(Player.level);
	setExp(Player.exp);
	recoverHP();
	recoverMP();
}
void  OrcPlayer::setLevel(int Level) // need to call setAttr() inside
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
void OrcPlayer::setAttr(int Level) // parameter is level
{
	max_hp = 200 + 20 * Level;
	max_mp = 50 + 5 * Level;
	attack = 50 + 12 * Level + extra_attack;
	defense = 30 + 10 * Level + extra_defense;
	lvup_exp = pow(10, log(Level + 1) / log(2));
}
void OrcPlayer::levelUp(void) // level++
{
	setLevel(level + 1);
}
void OrcPlayer::increaseExp(int EXP)
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
void OrcPlayer::specialSkill()
{

}
void OrcPlayer::status()
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