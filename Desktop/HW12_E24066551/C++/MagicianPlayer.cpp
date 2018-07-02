#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
#include"AbstractMonster.h"
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
int MagicianPlayer::specialSkill(vector<AbstractMonster*>monster)
{
	char aa = 'o';
	int choose = 0;
	while (1)
	{
		system("cls");
		if (level >= 5 && Awaked==1)
		{
			if (choose == 0)
			{
				cout << "->";
			}
			cout << "pray" << endl;
			if (choose == 1)
			{
				cout << "->";
			}
			cout << "freeze" << endl;
			if (choose == 2)
			{
				cout << "->";
			}
			cout << "all attack" << endl;
			aa = _getch();
			if (aa == 'd')
			{
				if (choose == 0)
				{
					pray();
				}
				else if (choose == 1)
				{
					freeze();
				}
				else
				{
					attackToAll(monster);
				}
				return 1;
			}
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
				cout << "pray" << endl;
				if (choose == 1)
				{
					cout << "->";
				}
				cout << "freeze" << endl;
				aa = _getch();
				if (aa == 'd')
				{
					if (choose == 0)
					{
						pray();
					}
					else
					{
						freeze();
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
				cout << "pray" << endl;
				aa = _getch();
				if (aa == 'd')
				{
					pray();
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
void MagicianPlayer::pray()
{
	if (hp-(level * -5)>0&&mp>=10)
	{
		increaseMP(level * 10);
		increaseHP(level * -5);
		mp -= 10;
	}
}
void MagicianPlayer::freeze()
{
	if (hp - (level * -5)>0 && mp >= 20)
	{
		GoblinMonster GoblinMonster1("LittleGoblin1", 20, 10, 10, 50, 20);
		GoblinMonster1.cant_attack = 1;
		mp -= 20;
	}
}
void MagicianPlayer::status()
{
	cout << "      ¢¨¢©" << endl;
	cout << "¢ª¢©¢¨¢i¢i¢©" << endl;
	cout << "  ¢ª¢«¢¨¢i¢i¢©        " << race << "-" << name << " (Lv." << level << ")" << endl;
	cout << "    ¢¨¢i¢i¢i¢i¢i¢©" << endl;
	cout << " ¢¨¢i¢i¢ª¢i¢i¢ª¢i¢i¢© ";
	SetColor(4);
	perentbox(max_hp, hp, 4);
	SetColor(7);
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "     |  ¡´'    ¡´|    ";
	SetColor(4);
	perentbox(max_mp, mp, 1);
	SetColor(7);
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "     \\           /    ";
	SetColor(4);
	perentbox(lvup_exp, exp, 6);
	SetColor(7);
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "    ¢ª¢i¢i¢i¢i¢i¢«    ";
	cout << " Attack/Defense:" << attack << "/" << defense << endl;
}
void MagicianPlayer::status_pic()
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