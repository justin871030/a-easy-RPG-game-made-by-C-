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
int OrcPlayer::specialSkill(vector<AbstractMonster*>monster)
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
			cout << "anger" << endl;
			if (choose == 1)
			{
				cout << "->";
			}
			cout << "lifeattack" << endl;
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
					anger();
				}
				else if (choose == 1)
				{
					lifeattack();
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
				cout << "anger" << endl;
				if (choose == 1)
				{
					cout << "->";
				}
				cout << "lifeattack" << endl;
				if (aa == 'd')
				{
					if (choose == 0)
					{
						anger();
					}
					else
					{
						lifeattack();
					}
					return 1;
				}
				aa = _getch();
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
				cout << "anger" << endl;
				aa = _getch();
				if (aa == 'd')
				{
					anger();
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
void OrcPlayer::anger()
{
	if (mp-10>=0)
	{
		Anger = 20;
		mp -= 10;
	}
}
void OrcPlayer::lifeattack()
{
	if (hp - 10 >= 0&& mp - 20 >= 0)
	{
		Anger = 50;
		hp -= 20;
		mp -= 20;
	}
}
void OrcPlayer::status()
{
	cout << "      ¢©      ¢¨" << endl;
	cout << "      ¢i¢©  ¢¨¢i      " << race << "-" << name << " (Lv." << level << ")" << endl;
	cout << "    ¢¨¢i¢i¢i¢i¢i¢©" << endl;
	cout << "    ¢i¢i¢ª¢i¢i¢ª¢i    ";
	SetColor(4);
	perentbox(max_hp, hp, 4);
	SetColor(7);
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "    ¢i  ¡´'  ¡´ ¢i    ";
	SetColor(4);
	perentbox(max_mp, mp, 1);
	SetColor(7);
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "    ¢ª     ¤H   ¢«    ";
	SetColor(4);
	perentbox(lvup_exp, exp, 6);
	SetColor(7);
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "      ¢ª¢i¢i¢i¢«    ";
	cout << "  Attack/Defense:" << attack << "/" << defense << endl;
}
void OrcPlayer::status_pic()
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