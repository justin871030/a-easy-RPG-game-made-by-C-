#include"AbstractMonster.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

GoblinMonster::GoblinMonster(string Name, int Attack, int Defense, int Exp, int Max_hp, int Max_mp)
	:AbstractMonster(Name,  Attack,  Defense,  Exp,  Max_hp,  Max_mp)
{
	setHP(max_hp);
	setMP(max_mp);
}
GoblinMonster::~GoblinMonster()
{
}
void GoblinMonster::attackTo(GeneralPlayer* player)
{
	if (getHP() == 0)
	{
		cout << "The monster HAD died !!";
	}
	else
	{
		if (player->getHp()==0)
		{
			cout << "The player HAD died !!";
		}
		else
		{
			player->increaseHP(-1 * damage_calculate(attack, player->getDefense()));
			if (player->hp == 0)
			{
				cout << "The Player die!!";
			}
		}
	}
	
}
void  GoblinMonster::status()
{
	/*cout << race << "-" << name << endl;
	cout << "Hp:" << getHP() << "/" << max_hp << endl;
	cout << "Mp:" << getHP() << "/" << max_mp << endl;
	cout << "Exp:" << exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;*/
	cout << "Name:" << name << endl;
	cout << "Race:" << race << endl;
	cout << "Hp:" << getHP() << "/" << max_hp << endl;
	cout << "Mp:" << getMP() << "/" << max_mp << endl;
	cout << "Exp:" << exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}