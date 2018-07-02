#include"AbstractMonster.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

JWMonster::JWMonster(string Name, int Attack, int Defense, int Exp, int Max_hp, int Max_mp)
	:AbstractMonster(Name, Attack, Defense, Exp, Max_hp, Max_mp)
{
	money = 50;
	setHP(max_hp);
	setMP(max_mp);
}
JWMonster::~JWMonster()
{
}
void JWMonster::attackTo(GeneralPlayer* player)
{
	if (getHP()==0)
	{
		cout << "The monster HAD died !!";
	}
	else
	{
		if (player->getHp() == 0)
		{
			cout << "The player HAD died !!";
		}
		else
		{
			setHP(getHP() + max_hp * (0.1));
			setMP(getMP() + max_mp * (0.05));
			srand(time(NULL));
			int act = rand() % 2;
			if (act == 0 && getMP() >= 10)
			{
				setMP(getMP() - 10);
				player->increaseHP(-1 * (damage_calculate(attack, player->getDefense()) * 2));
				if (getMP() >= 10)
				{
					setMP(getMP() - 10);
					player->increaseHP(-1 * (damage_calculate(attack, player->getDefense()) * 2));
				}
			}
			else
			{
				player->increaseHP(-1 * damage_calculate(attack, player->getDefense()));
			}
			if (player->hp == 0)
			{
				cout << "The Player die!!";
			}
		}
	}
}
void  JWMonster::status()
{
	cout << "Name:" << name << endl;
	cout << "Race:" << race << endl;
	cout << "Hp:" << getHP() << "/" << max_hp << endl;
	cout << "Mp:" << getMP() << "/" << max_mp << endl;
	cout << "Exp:" << exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}