#include"AbstractMonster.h"
#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

int AbstractMonster::count = 0;
int AbstractMonster::damage_calculate(int attack, int defense)/*-10~10*/
{
	srand(time(NULL));
	int inaccuracy = rand() % 11;/*決定0~10%*/
	int p_n = (rand() % 2) * 2 - 1;/*決定正負(1or-1)*/

	if (attack <= defense)
	{
		return rand() % 2;
	}
	else
	{
		return (attack - defense)*(100 + p_n * inaccuracy) / 100;
	}
}
AbstractMonster::AbstractMonster(string Name, int Attack, int Defense, int Exp, int Max_hp, int Max_mp)
	:name(Name),attack(Attack),defense(Defense),exp(Exp),max_hp(Max_hp),max_mp(Max_mp)
{
	count++;
	setHP(max_hp);
	setMP(max_mp);
}
AbstractMonster::~AbstractMonster()
{
	count--;
}
void AbstractMonster::setHP(int Hp)
{
	if (Hp<0)
	{
		cout << "You set a wrong hp !";
	}
	else
	{
		if (Hp>max_hp)
		{
			hp = max_hp;
		}
		else
		{
			hp = Hp;
		}
	}
}
int AbstractMonster::getHP() const
{
	return hp;
}
void AbstractMonster::setMP(int Mp)
{
	if (Mp<0)
	{
		cout << "You set a wrong mp !";
	}
	else
	{
		mp = Mp;
		if (Mp>max_mp)
		{
			mp = max_mp;
		}
		else
		{
			mp = Mp;
		}
	}
}
int AbstractMonster::getMP() const
{
	return mp;
}
string AbstractMonster::serialize() const
{
	string serialize;
	serialize += "$race:" + race;
	serialize += "$name:" + name;
	serialize += "$hp:" + to_string(hp);
	serialize += "$mp:" + to_string(mp);
	serialize += "$exp:" + to_string(exp);
	serialize += "$attack:" + to_string(attack);
	serialize += "$defense:" + to_string(defense);
	serialize += "$max_hp:" + to_string(max_hp);
	serialize += "$max_mp:" + to_string(max_mp);
	serialize += "$money:" + to_string(money);
	return serialize;
}
void AbstractMonster::unserialize(string data)
{
	string temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == '$')
		{
			string type;
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[j] == ':')
				{
					string value;
					for (int k = j + 1; k < temp.size(); k++)
					{
						value += temp[k];
					}
					if (type == "race")
					{
						race = value;
					}
					else if (type == "hp")
					{
						hp = stoi(value);
					}
					else if (type == "mp")
					{
						mp = stoi(value);
					}
				}
				else
				{
					type.push_back(temp[j]);
				}
			}
			temp.clear();
		}
		else
		{
			temp.push_back(data[i]);
		}
	}
}