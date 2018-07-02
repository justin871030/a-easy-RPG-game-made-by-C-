#include"Battle.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
void Gotoxy(int xpos = 0, int ypos = 0)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void Setcolor(int f=0, int b=0)
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}
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
			if (((AbstractMonster*)monster_list[i].instance)->getHP() >0)
			{
				count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < num_monster; i++)
		{
			if (((AbstractMonster*)monster_list[i].instance)->getHP() <=0)
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
int Battle::run()
{
	while (nextActor() &&getPlayerCount(1) != 0&& getMonsterCount(1) != 0)
	{
		status();
		for (int i = 0; i < num_player + num_monster &&getPlayerCount(1) != 0 && getMonsterCount(1) != 0; i++)
		{
			/*if (play_alive==0|| mons_alive == 0)
			{
			end = 1;
			break;
			}*/
			if (action_list[i].type == 'p'&&action_list[i].alive == 1 && getPlayerCount(1) != 0 && getMonsterCount(1) != 0)
			{
				((AbstractMonster*)monster_list[i].instance)->cant_attack = 0;
				int sk_at = 999;
				int choose = 0;
				int choose_over = 0;
				while (!choose_over)
				{
					while (1)
					{
						status();
						cout << "Now is " << ((GeneralPlayer*)action_list[i].instance)->name << "'s term\n-----------------------" << endl;
						if (choose == 0)
						{
							cout << "->";
						}
						cout << "Attack!" << endl;;
						if (choose == 1)
						{
							cout << "->";
						}
						cout << "Use Skill!" << endl;;
						if (choose == 2)
						{
							cout << "->";
						}
						cout << "Escape!" << endl;
						char aa = _getch();
						if (aa == 's')
						{
							choose++;
							if (choose > 2)
							{
								choose = 0;
							}
						}
						if (aa == 'w')
						{
							choose--;
							if (choose < 0)
							{
								choose = 2;
							}
						}
						if (aa == 'd')
						{
							if (choose == 1)
							{
								vector<AbstractMonster*>list;
								for (int i = 0; i < num_monster; i++)
								{
									list.push_back((AbstractMonster*)monster_list[i].instance);
								}
								if (((GeneralPlayer*)action_list[i].instance)->specialSkill(list))
								{
									status();
									choose_over = 1;
									break;
								}
							}
							if (choose == 2)
							{
								choose_over = 1;
								srand(time(NULL));
								int escape = rand()%4;
								//if (!escape)
								//{
								//	return 0;
								//}
								//break;
								return 0;
							}
							if (choose == 0)
							{
								int att_choose = 0;
								int monsters_count = 0;
								while (1)
								{
									monsters_count = 0;
									status();
									for (int i = 0; i < num_monster; i++)
									{
										if (!(((AbstractMonster*)monster_list[i].instance)->getHP() == 0))
										{
											if (monsters_count == att_choose)
											{
												cout << "->";
												monsters_count++;
												cout << ((AbstractMonster*)monster_list[i].instance)->name << endl;
											}
											else
											{
												cout << ((AbstractMonster*)monster_list[i].instance)->name << endl;
												monsters_count++;
											}
										}
									}
									char aaa = _getch();
									if (aaa == 's')
									{
										if (att_choose >= monsters_count - 1)
										{
											att_choose = 0;
										}
										else
										{
											att_choose++;
										}
									}
									if (aaa == 'w')
									{
										if (att_choose <= 0)
										{
											att_choose = monsters_count - 1;
										}
										else
										{
											att_choose--;
										}
									}
									if (aaa == 'd')
									{
										int count_mon = 0;
										for (int q = 0; q < num_monster; q++)
										{
											if (((AbstractMonster*)monster_list[q].alive))
											{
												if (att_choose == count_mon )
												{
													if (((GeneralPlayer*)action_list[i].instance)->attackTo((AbstractMonster*)monster_list[q].instance))
													{
														if (((GeneralPlayer*)action_list[i].instance)->race == "Knight")
														{
															system("cls");
															status();
															cout << "      ¢¨¢©¢¨¢¨¢©" << endl;
															cout << "    ¢¨¢i¢i¢i¢i¢i¢©" << endl;
															cout << "   ¢¨¢i¢ª¢i¢i¢ª¢i¢©  " << endl;
															cout << "    ¢ª  ¡´¢ª  ¡´¢«    " << endl;
															cout << "      \\        /    " << endl;
															cout << "       ¢@¡Ä¡Ä¡þ  " << endl;
															Sleep(200);
															system("cls");
															status();
															cout << "      ¢¨¢©¢¨¢¨¢©                " << endl;
															cout << "    ¢¨¢i¢i¢i¢i¢i¢©      ¢i¢i        " << endl;
															cout << "   ¢¨¢i¢ª¢i¢i¢ª¢i¢© ùþùþ¢i¢i ¢i¢i¢i¢i¢i¢©      " << endl;
															cout << "    ¢ª  ¡´¢ª  ¡´¢«  ùþùþ¢i¢i ¢i¢i¢i¢i¢i¢«      " << endl;
															cout << "      \\        /        ¢i¢i        " << endl;
															cout << "       ¢@¡Ä¡Ä¡þ  " << endl;
														}
														if (((GeneralPlayer*)action_list[i].instance)->race == "Magic")
														{
															system("cls");
															status();
															cout << "      ¢¨¢©" << endl;
															cout << "¢ª¢©¢¨¢i¢i¢©" << endl;
															cout << "  ¢ª¢«¢¨¢i¢i¢©" << endl;
															cout << "    ¢¨¢i¢i¢i¢i¢i¢©" << endl;
															cout << " ¢¨¢i¢i¢ª¢i¢i¢ª¢i¢i¢©  " << endl;
															cout << "     |  ¡´'    ¡´|    " << endl;
															cout << "     \\           /    " << endl;
															cout << "    ¢ª¢i¢i¢i¢i¢i¢«    " << endl;
															Sleep(200);
															system("cls");
															status();
															cout << "      ¢¨¢©" << endl;
															cout << "¢ª¢©¢¨¢i¢i¢©" << endl;
															cout << "  ¢ª¢«¢¨¢i¢i¢©" << endl;
															cout << "    ¢¨¢i¢i¢i¢i¢i¢©        ¢i¢i        " << endl;
															cout << " ¢¨¢i¢i¢ª¢i¢i¢ª¢i¢i¢© ùþùþ¢i¢i ¢i¢i¢i¢i¢i¢©      " << endl;
															cout << "     |  ¡´'    ¡´|    ùþùþ¢i¢i ¢i¢i¢i¢i¢i¢«      " << endl;
															cout << "     \\           /        ¢i¢i        " << endl;
															cout << "    ¢ª¢i¢i¢i¢i¢i¢«    " << endl;
														}
														if (((GeneralPlayer*)action_list[i].instance)->race == "Orc")
														{
															system("cls");
															status();
															cout << "      ¢©      ¢¨" << endl;
															cout << "      ¢i¢©  ¢¨¢i" << endl;
															cout << "    ¢¨¢i¢i¢i¢i¢i¢©" << endl;
															cout << "    ¢i¢i¢ª¢i¢i¢ª¢i  " << endl;
															cout << "    ¢i  ¡´'  ¡´ ¢i  " << endl;
															cout << "    ¢ª     ¤H   ¢«    " << endl;
															cout << "      ¢ª¢i¢i¢i¢«    " << endl;
															Sleep(200);
															system("cls");
															status();
															cout << "      ¢©      ¢¨" << endl;
															cout << "      ¢i¢©  ¢¨¢i" << endl;
															cout << "    ¢¨¢i¢i¢i¢i¢i¢©      ¢i¢i        "  << endl;
															cout << "    ¢i¢i¢ª¢i¢i¢ª¢i  ùþùþ¢i¢i ¢i¢i¢i¢i¢i¢©      " << endl;
															cout << "    ¢i  ¡´'  ¡´ ¢i  ùþùþ¢i¢i ¢i¢i¢i¢i¢i¢«      " << endl;
															cout << "    ¢ª     ¤H   ¢«      ¢i¢i        " << endl;
															cout << "      ¢ª¢i¢i¢i¢«    " << endl;
														}
														Sleep(500);
													}
													if (((AbstractMonster*)monster_list[q].instance)->getHP() == 0)
													{
														monster_list[q].alive = 0;
														action_list[q + num_player].alive = 0;
													}
													break;
												}
												else
												{
													count_mon++;
												}
											}
										}
										status(); 
										choose_over = 1;
										break;
									}
									if (aaa == 'a')
									{
										break;
									}
								}
							}
							break;
						}
					}
				}
				
			}
			else if (monster_list[i - num_player].alive == 1 && getPlayerCount(1) != 0 && getMonsterCount(1) != 0)
			{
				int att_choose = 999;
				srand(time(NULL));
				att_choose = rand() % num_player;
				((AbstractMonster*)action_list[i].instance)->attackTo((GeneralPlayer*)player_list[att_choose].instance);
				system("cls");
				status();
				cout << "  ¡¶              ¡¶ "<< endl;
				cout << "  ¢i¢©¢¨¢i¢i¢i¢©¢¨¢i" << endl;
				cout << "  ¢ª¢i¢i¢«  ¢ª¢i¢i¢«" << endl;
				cout << "    ¢i¢i  ¡´  ¢i¢i  " << endl;
				cout << "    ¢i¢i¢©  ¢¨¢i¢i  " << endl;
				cout << "    ¢ª¢i¡¾  ¡¾¢i¢«    " << endl;
				cout << "      ¢i¡µ  ¡µ¢i    " << endl;
				cout << "      ¢ª¢i¢i¢i¢«    " << endl;
				Sleep(300);
				system("cls");
				status();
				cout << "  ¡¶              ¡¶ " << endl;
				cout << "  ¢i¢©¢¨¢i¢i¢i¢©¢¨¢i" << endl;
				cout << "  ¢ª¢i¢i¢«  ¢ª¢i¢i¢«" << endl;
				cout << "    ¢i¢i  ¡´  ¢i¢i  " << endl;
				cout << "    ¢i¢i¢©  ¢¨¢i¢i  " << endl;
				cout << "    ¢ª¢i¡µ¢i¡µ¢i¢«    " << endl;
				cout << "      ¢ª¢i¢i¢i¢«    " << endl;
				Sleep(500);
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
	if (getPlayerCount(1) == 0)
	{
		return -1;
	}
	else
	{
		return getMonsterCount(0);
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

void Battle::status_new()
{
	system("cls");
	
	/*for (int i = 0; i < num_player; i++)
	{
		P_INS->status();
		cout << endl;
	}
	for (int i = 0; i < num_monster; i++)
	{
		Gotoxy(40,i*5+3);
		cout << "      ¢¨¢©¢¨¢¨¢©      " << M_INS->race << "-" << M_INS->name ;
		Gotoxy(40, i * 5 + 6);
		Setcolor(4);
		perentbox(max_hp, hp, 4);
		SetColor(7);
		cout << "Hp:" << hp << "/" << max_hp << endl;
		cout << "    ¢ª  ¡´¢ª  ¡´¢«    ";
		SetColor(4);
		perentbox(max_mp, mp, 1);
		SetColor(7);
		cout << "Mp:" << mp << "/" << max_mp << endl;
		cout << "      \\        /      ";
		SetColor(4);
		perentbox(lvup_exp, exp, 6);
		SetColor(7);
		cout << "Exp:" << exp << "/" << lvup_exp << endl;
		cout << "       ¢@¡Ä¡Ä¡þ  ";
		cout << "     Attack/Defense:" << attack << "/" << defense << endl;
	}*/
}
