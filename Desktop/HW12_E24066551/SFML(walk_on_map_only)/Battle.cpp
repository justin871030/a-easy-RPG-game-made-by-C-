#include"Battle.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include <iomanip>
using namespace std;

Battle::Battle(GeneralPlayer** player, AbstractMonster** monster, int num_p, int num_m, int turn_lim)
{
	num_player = num_p;
	num_monster = num_m;
	n_turn = 0;
	turn_limit = turn_lim;
	player_list = new Character[num_p];
	monster_list = new Character[num_m];
	action_list = new Character[num_p+num_m];
	for (int i = 0; i < num_p; i++)
	{
		player_list[i].type = 'p';
		action_list[i].type = 'p';
		if (player[i]->getHp()==0)
		{
			player_list[i].alive = 0;
			action_list[i].alive = 0;
		}
		else
		{
			player_list[i].alive = 1;
			action_list[i].alive = 1;
		}
		player_list[i].instance = player[i];
		action_list[i].instance = player[i];
	}
	for (int i = 0; i < num_m; i++)
	{
		monster_list[i].type = 'm';
		action_list[i+ num_p].type = 'm';
		if (monster[i]->getHP() == 0)
		{
			monster_list[i].alive = 0;
			action_list[i+num_p].alive = 0;
		}
		else
		{
			monster_list[i].alive = 1;
			action_list[i + num_p].alive = 1;
		}
		monster_list[i].instance = monster[i];
		action_list[i + num_p].instance = monster[i];
	}
}
Battle::Battle(GeneralPlayer** player, AbstractMonster** monster, int num_p, int num_m)
{
	num_player = num_p;
	num_monster = num_m;
	n_turn = 0;
	turn_limit = 0;
	player_list = new Character[num_p];
	monster_list = new Character[num_m];
	action_list = new Character[num_p + num_m];
	for (int i = 0; i < num_p; i++)
	{
		player_list[i].type = 'p';
		action_list[i].type = 'p';
		if (player[i]->getHp() == 0)
		{
			player_list[i].alive = 0;
			action_list[i].alive = 0;
		}
		else
		{
			player_list[i].alive = 1;
			action_list[i].alive = 1;
		}
		player_list[i].instance = player[i];
		action_list[i].instance = player[i];
	}
	for (int i = 0; i < num_m; i++)
	{
		monster_list[i].type = 'm';
		action_list[i + num_p].type = 'm';
		if (monster[i]->getHP() == 0)
		{
			monster_list[i].alive = 0;
			action_list[i + num_p].alive = 0;
		}
		else
		{
			monster_list[i].alive = 1;
			action_list[i + num_p].alive = 1;
		}
		monster_list[i].instance = monster[i];
		action_list[i + num_p].instance = monster[i];
	}
}
Battle::Battle(vector<GeneralPlayer*>player, vector<AbstractMonster*>monster, int num_p, int num_m, int turn_lim)
{
	num_player = num_p;
	num_monster = num_m;
	n_turn = 0;
	turn_limit = turn_lim;
	player_list = new Character[num_p];
	monster_list = new Character[num_m];
	action_list = new Character[num_p + num_m];
	for (int i = 0; i < num_p; i++)
	{
		player_list[i].type = 'p';
		action_list[i].type = 'p';
		if (player[i]->getHp() == 0)
		{
			player_list[i].alive = 0;
			action_list[i].alive = 0;
		}
		else
		{
			player_list[i].alive = 1;
			action_list[i].alive = 1;
		}
		player_list[i].instance = player[i];
		action_list[i].instance = player[i];
	}
	for (int i = 0; i < num_m; i++)
	{
		monster_list[i].type = 'm';
		action_list[i + num_p].type = 'm';
		if (monster[i]->getHP() == 0)
		{
			monster_list[i].alive = 0;
			action_list[i + num_p].alive = 0;
		}
		else
		{
			monster_list[i].alive = 1;
			action_list[i + num_p].alive = 1;
		}
		monster_list[i].instance = monster[i];
		action_list[i + num_p].instance = monster[i];
	}
}
Battle::Battle(vector<GeneralPlayer*>player, vector<AbstractMonster*>monster, int num_p, int num_m)
{
	num_player = num_p;
	num_monster = num_m;
	n_turn = 0;
	turn_limit = 0;
	player_list = new Character[num_p];
	monster_list = new Character[num_m];
	action_list = new Character[num_p + num_m];
	for (int i = 0; i < num_p; i++)
	{
		player_list[i].type = 'p';
		action_list[i].type = 'p';
		if (player[i]->getHp() == 0)
		{
			player_list[i].alive = 0;
			action_list[i].alive = 0;
		}
		else
		{
			player_list[i].alive = 1;
			action_list[i].alive = 1;
		}
		player_list[i].instance = player[i];
		action_list[i].instance = player[i];
	}
	for (int i = 0; i < num_m; i++)
	{
		monster_list[i].type = 'm';
		action_list[i + num_p].type = 'm';
		if (monster[i]->getHP() == 0)
		{
			monster_list[i].alive = 0;
			action_list[i + num_p].alive = 0;
		}
		else
		{
			monster_list[i].alive = 1;
			action_list[i + num_p].alive = 1;
		}
		monster_list[i].instance = monster[i];
		action_list[i + num_p].instance = monster[i];
	}
}
Battle::Battle(vector<GeneralPlayer>player, vector<AbstractMonster>monster, int num_p, int num_m)
{
	num_player = num_p;
	num_monster = num_m;
	n_turn = 0;
	turn_limit = 0;
	player_list = new Character[num_p];
	monster_list = new Character[num_m];
	action_list = new Character[num_p + num_m];
	for (int i = 0; i < num_p; i++)
	{
		player_list[i].type = 'p';
		action_list[i].type = 'p';
		if (player[i].getHp() == 0)
		{
			player_list[i].alive = 0;
			action_list[i].alive = 0;
		}
		else
		{
			player_list[i].alive = 1;
			action_list[i].alive = 1;
		}
		player_list[i].instance = &player[i];
		action_list[i].instance = &player[i];
	}
	for (int i = 0; i < num_m; i++)
	{
		monster_list[i].type = 'm';
		action_list[i + num_p].type = 'm';
		if (monster[i].getHP() == 0)
		{
			monster_list[i].alive = 0;
			action_list[i + num_p].alive = 0;
		}
		else
		{
			monster_list[i].alive = 1;
			action_list[i + num_p].alive = 1;
		}
		monster_list[i].instance = &monster[i];
		action_list[i + num_p].instance = &monster[i];
	}
}
bool Battle::nextActor(void)
{
	if (getMonsterCount(1)==0|| getPlayerCount(1) == 0)
	{
		if (getMonsterCount() == 0)
		{
			cout << "Game Over !!";
			return 0;
		}
		else
		{
			return 0;
		}
	}
	else if (action_turn>=num_player+num_monster)
	{
		n_turn++;
		action_turn = 0;
		if (n_turn >= turn_limit && turn_limit != 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (n_turn >= turn_limit && turn_limit != 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
int Battle::getTurnCount(void) const
{
	return n_turn;
}
int Battle::getTurnLimit(void) const
{
	return turn_limit;
}
int Battle::getPlayerCount(void) const
{
	return num_player;
}
int Battle::getPlayerCount(bool live_death) const
{
	int count = 0;
	if (live_death)
	{
		for (int i = 0; i < num_player; i++)
		{
			if (player_list[i].alive == 1)
			{
				count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < num_player; i++)
		{
			if (player_list[i].alive == 0)
			{
				count++;
			}
		}
	}
	return count;
}
int Battle::getMonsterCount(void) const
{
	return num_monster;
}
int Battle::getMonsterCount(bool live_death) const
{
	int count = 0;
	if (live_death)
	{
		for (int i = 0; i < num_monster; i++)
		{
			if (monster_list[i].alive == 1)
			{
				count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < num_monster; i++)
		{
			if (monster_list[i].alive == 0)
			{
				count++;
			}
		}
	}
	return count;
}
Character Battle::getCurrentActor(void)
{
	return action_list[action_turn];
}
Character* Battle::getPlayers(void)
{
	return player_list;
}
Character* Battle::getMonsters(void)
{
	return monster_list;
}
void Battle::run()
{
	int end = 0;
	while (nextActor()&&!end)
	{
		status();
		for (int i = 0; i < num_player+ num_monster; i++)
		{
			/*if (play_alive==0|| mons_alive == 0)
			{
				end = 1;
				break;
			}*/
			if (action_list[i].type=='p'&&action_list[i].alive==1&& getMonsterCount(1)!=0)
			{
				int sk_at=999;
				cout << "Skill or Attack ?? (1/0)";
				while (sk_at != 0 && sk_at != 1)
				{
					cin >> sk_at;
				}
				if (sk_at)
				{
					((GeneralPlayer*)action_list[i].instance)->specialSkill();
					status();
				}
				else
				{
					int att_choose=999;
					cout << "Choose the monster you want to attack (1~"<<num_monster<< ") (enter 0 for ramdon)";
					while (att_choose>num_monster|| att_choose<0)
					{
						cin >> att_choose;
					}
					if (att_choose==0)
					{
						srand(time(NULL));
						while (((AbstractMonster*)monster_list[att_choose].instance)->getHP() == 0)
						{
							att_choose = rand() % num_monster;
						}
						((GeneralPlayer*)action_list[i].instance)->attackTo((AbstractMonster*)monster_list[att_choose].instance);
						if (((AbstractMonster*)monster_list[att_choose].instance)->getHP()==0)
						{
							monster_list[att_choose].alive = 0;
							action_list[att_choose+num_player].alive = 0;
						}
						status();
					}
					else 
					{
						((GeneralPlayer*)action_list[i].instance)->attackTo((AbstractMonster*)monster_list[att_choose - 1].instance);
						if (((AbstractMonster*)monster_list[att_choose-1].instance)->getHP() == 0)
						{
							monster_list[att_choose-1].alive = 0;
							action_list[att_choose -1+ num_player].alive = 0;
						}
						status();
					}
				}
			}
			else if(monster_list[i - num_player].alive == 1 && getPlayerCount(1) != 0)
			{
				cout << "Attack~~~~~~~~~~~~~~~~~~~" << endl;
				system("pause");
				int att_choose = 999;
				srand(time(NULL));
				att_choose = rand() % num_player;
				((AbstractMonster*)action_list[i].instance)->attackTo((GeneralPlayer*)player_list[att_choose].instance);
				if (((GeneralPlayer*)player_list[att_choose].instance)->getHp() == 0)
				{
					player_list[att_choose].alive = 0;
					action_list[att_choose].alive = 0;
				}
				status();
			}
		}
		action_turn++;
	}
}
#define P_INS ((GeneralPlayer*)player_list[i].instance)
#define M_INS ((AbstractMonster*)monster_list[i].instance)
string is(int input)
{
	string temp;
	string output;
	while (input >= 10)
	{
		temp.push_back(input % 10 + 48);
		input /= 10;
	}
	temp.push_back(input + 48);
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		output.push_back(temp[i]);
	}
	return output;
}
void Battle::status()
{
	/*cout << race << "-" << name << endl;
	cout << "Hp:" << getHP() << "/" << max_hp << endl;
	cout << "Mp:" << getHP() << "/" << max_mp << endl;
	cout << "Exp:" << exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;*/
	system("cls");
	cout << "PLAYER~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < num_player|| i <num_monster; i++)
	{
		cout <<left<<setw(50)<<  P_INS->name + " (Lv." + is(P_INS->getLevel()) + ")" ;
		if (i < num_monster)
		{
			cout << left << setw(50)<< M_INS->name << endl;
		}
		else
		{
			cout << endl;
		}
		cout << left << setw(50) << "Hp:" + is(P_INS->hp) + "/" + is(P_INS->getMaxHP()) ;
		if (i < num_monster)
		{
			cout << left << setw(50) << "Hp:" + is(M_INS->getHP()) + "/" + is(M_INS->max_hp)<< endl;
		}
		else
		{
			cout << endl;
		}
		cout << left << setw(50) << "Mp:" + is(P_INS->mp) + "/" + is(P_INS->getMaxMP()) ;
		if (i < num_monster)
		{
			cout << left << setw(50) << "Mp:" + is(M_INS->getMP()) + "/" + is(M_INS->max_mp) << endl;
		}
		else
		{
			cout << endl;
		}
		cout << left << setw(50) << "Exp:" + is(P_INS->exp) + "/" + is(P_INS->getLvupExp());
		if (i < num_monster)
		{
			cout << left << setw(50) << "Exp:" + is(M_INS->exp) << endl;
		}
		else
		{
			cout << endl;
		}
		cout << left << setw(50) << "Attack/Defense:" + is(P_INS->getAttack()) + "/" + is(P_INS->getDefense());
		if (i < num_monster)
		{
			cout << left << setw(50) <<"Attack/Defense:" + is(M_INS->attack) + "/"+ is(M_INS->defense) << endl;
		}
		else
		{
			cout << endl;
		}
		cout << endl;
	}
}
