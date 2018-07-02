#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
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
int KnightPlayer::specialSkill(vector<AbstractMonster*>monster)
{
	char aa = 'o';
	int choose = 0;
	while (1)
	{
		system("cls");
		if (level >= 5 && Awaked == 1)
		{
			if (choose == 0)
			{
				cout << "->";
			}
			cout << "heal" << endl;
			if (choose == 1)
			{
				cout << "->";
			}
			cout << "cheer" << endl;
			if (choose == 2)
			{
				cout << "->";
			}
			cout << "all attack" << endl;
			if (aa == 'd')
			{
				if (choose == 0)
				{
					heal();
				}
				else if (choose == 1)
				{
					cheer();
				}
				else
				{
					attackToAll(monster);
				}
				return 1;
			}
			aa = _getch();
			if (aa == 's')
			{
				if (choose == 2)
				{
					choose = 0;
				}
				else
				{
					choose++;
				}
			}
			if (aa == 'w')
			{
				if (choose == 0)
				{
					choose = 2;
				}
				else
				{
					choose--;
				}
			}
			if (aa == 'a')
			{
				return 0;
			}
		}
		else
		{
			if (level >= 5)
			{
				if (choose == 0)
				{
					cout << "->";
				}
				cout << "heal" << endl;
				if (choose == 1)
				{
					cout << "->";
				}
				cout << "cheer" << endl;
				aa = _getch();
				if (aa == 'd')
				{
					if (choose == 0)
					{
						heal();
					}
					else
					{
						cheer();
					}
					return 1;
				}
				if (aa == 's')
				{
					if (choose == 1)
					{
						choose = 0;
					}
					else
					{
						choose++;
					}
				}
				if (aa == 'w')
				{
					if (choose == 0)
					{
						choose = 1;
					}
					else
					{
						choose--;
					}
				}
				if (aa == 'a')
				{
					return 0;
				}
			}
			else
			{
				cout << "->";
				cout << "heal" << endl;
				aa = _getch();
				if (aa == 'd')
				{
					heal();
					return 1;
				}
				if (aa == 'a')
				{
					return 0;
				}
			}
		}
	}
}
void KnightPlayer::heal(void)
{
	if (mp - (level * -5)>0)
	{
		increaseHP(level * 10);
		increaseMP(level * -5);
	}
}
void KnightPlayer::cheer(void)
{
	if (mp - 20 >= 0)
	{
		Cheer = 10;
		mp -= 20;
	}
}
void KnightPlayer::status_pic()
{
	cout << race << "-" << name << " (Lv." << level << ")" << endl;
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}
void KnightPlayer::status()
{
	cout << "      ¢¨¢©¢¨¢¨¢©      " << race << "-" << name << " (Lv." << level << ")"<<endl;
	cout << "    ¢¨¢i¢i¢i¢i¢i¢©"  << endl;
	cout << "   ¢¨¢i¢ª¢i¢i¢ª¢i¢©   " ;
	SetColor(4);
	perentbox(max_hp, hp, 4);
	SetColor(7);
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "    ¢ª  ¡´¢ª  ¡´¢«    " ;
	SetColor(4);
	perentbox(max_mp,mp, 1);
	SetColor(7);
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "      \\        /      " ;
	SetColor(4);
	perentbox(lvup_exp, exp, 6);
	SetColor(7);
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "       ¢@¡Ä¡Ä¡þ  ";
	cout << "     Attack/Defense:" << attack << "/" << defense << endl;
}