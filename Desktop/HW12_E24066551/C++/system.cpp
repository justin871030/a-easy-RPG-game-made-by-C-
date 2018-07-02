#include"system.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
#include <iomanip>
#include"GeneralPlayer.h"
#include"AbstractMonster.h"
using namespace std;
#define VILLAGE 0;

void gotoxy(int xpos=0, int ypos=0)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void cout_title()
{
	cout << "\n\n\n";
	cout << "                   ╔═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗ " << endl;
	cout << "                   ╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣ " << endl;
	cout << "                   ╠═╬═╬═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╬═╬═╣ " << endl;
	cout << "                   ╠═╬═╣ ◢███◣     ◢███◣     ◢███◣     ◢███◣     ◢███◣╠═╬═╣" << endl;
	cout << "                   ╠═╬═╣ █      █     █      █     █      █     █      █     █      █╠═╬═╣" << endl;
	cout << "                   ╠═╬═╣ █             █      █     █      █     █             █      █╠═╬═╣" << endl;
	cout << "                   ╠═╬═╣ █             █      █     █      █     █             █      █╠═╬═╣" << endl;
	cout << "                   ╠═╬═╣ █      █     █      █     █      █     █      █     █      █╠═╬═╣" << endl;
	cout << "                   ╠═╬═╣ ◥███◤     ◥███◤     ◥███◤     ◥███◤     ◥███◤╠═╬═╣ " << endl;
	cout << "                   ╠═╬═╬═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╬═╬═╣ " << endl;
	cout << "                   ╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣ " << endl;
	cout << "                   ╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝ " << endl;
}
string iss(int input)
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
int stin(string in)
{
	int out=0;
	for (int i = 0; i < in.size(); i++)
	{
		int temp = in[i] - 48;
		out += temp * pow(10,in.size()-1-i);
	}
	return out;
}
System::System(vector<string>map_data, int width, int length)
{

	for (int i = 0; i < map_data.size(); i++)
	{
		Map temp(map_data[i]);
		maps.push_back(temp);
	}
	sight_length = length;
	sight_width = width;

}
void System::set_mapname(vector<string> name)
{
	map_name=name;
}
void  System::print_title(Field*field,int num)
{
	cout << map_name[num];
	cout.width(field->map_length_x*2- map_name[num].size());
	cout  << "(" + iss(field->getCurrentPositionX()) + "," + iss(field->getCurrentPositionY()) + ")"<<endl ;
}
void System::run()
{
    KnightPlayer temp;
	MagicianPlayer temp2;
	OrcPlayer temp3;
	players.push_back(&temp);
	players.push_back(&temp2);
	players.push_back(&temp3);
	players_backpack.backpack_setup();
	players_backpack.setMoney(500);
	vector<string> mapname{"Dragon's Lair","Village","Forest Trail","XXXX","Volcanic Tunnel","Devil Nest","ＨＯＭＥ","Weapon Shop","Castle","Trial field","Villagers' House" ,"Seal land"};
	set_mapname(mapname);
	int check = 0;
	int start = 0;
	while (position < 212312321312312)
	{
		int next_position = position;
		if (next_position == current_position&&check != 0)
		{
			if (next_position==0)
			{
				next_position = 4;
				
			}
			else
			{
				next_position--;
			}
			check = 0;
		}
		Field field(maps[next_position].info, sight_width, sight_length, next_position, current_position);
		field.set_players(players, &players_backpack,&tasks);
		current_position = next_position;
		while (field.arrive_end() == -1)
		{
			field.QQ.update_state();
			if (field.die==-1)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n                                         ";
				string temp = "You Dead";
				for (int i = 0; i < temp.size(); i++)
				{
					cout << temp[i];
					Sleep(30);
				}
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
				Sleep(200);
				string temp2 = "Back to Home or Revive here(B/R)";
				for (int i = 0; i < temp2.size(); i++)
				{
					cout << temp2[i];
					Sleep(30);
				}
				char aa = _getch();
				while (aa != 'b'&&aa != 'r')
				{
					aa = _getch();
				}
				if (aa=='b')
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n                                     ";
					string tempp = "You wake up after a burst of dizziness";
					for (int i = 0; i < tempp.size(); i++)
					{
						cout << tempp[i];
						Sleep(30);
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					Sleep(200);
					players[0]->increaseHP(50);
					players[1]->increaseHP(50);
					players[2]->increaseHP(50);
					position = 6;
					current_position = 1;
					start_point = 1;
					field.die = 0;
					break;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n                                     ";
					string tempp = "You are favored by the goddess of war";
					for (int i = 0; i < tempp.size(); i++)
					{
						cout << tempp[i];
						Sleep(30);
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					Sleep(200);
					players[0]->increaseHP(50);
					players[1]->increaseHP(50);
					players[2]->increaseHP(50);
					players[0]->setExp(players[0]->getExp() - 50);
					players[1]->setExp(players[1]->getExp() - 50);
					players[2]->setExp(players[2]->getExp() - 50);
					field.die = 0;
				}
			}
			field.make_monster();
			players_backpack.setMoney(players_backpack.getMoney() + players[0]->getMoney() + players[1]->getMoney() + players[2]->getMoney());
			players[0]->setMoney(0);
			players[1]->setMoney(0);
			players[2]->setMoney(0);
			if (start == 0)
			{
				char aa = 'y';
				while (start == 0)
				{
					int choose = 0;
					while (start == 0)
					{
						system("cls");
						cout_title();
						gotoxy(55, 18);
						if (choose == 0)
						{
							cout << "->New game" << endl;
						}
						else
						{
							cout << "New game" << endl;
						}

						gotoxy(55, 19);
						if (choose == 1)
						{
							cout << "->Load" << endl;
						}
						else
						{
							cout << "Load" << endl;
						}

						gotoxy(55, 20);
						if (choose == 2)
						{
							cout << "->Leave" << endl;
						}
						else
						{
							cout << "Leave" << endl;
						}
						char hh = _getch();
						if (hh == 'd')
						{
							if (choose == 0)
							{
								start++;
								vector<string>temp{ "Warrior...","Warrior...","Wake up..."};
								for (int i = 0; i < temp.size(); i++)
								{
									system("cls");
									cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n                                                     ";
									for (int y = 0; y < temp[i].size(); y++)
									{
										cout << temp[i][y];
										Sleep(50);
									}
									Sleep(1500);
								}
								system("cls");
								vector<string>story{"Welcome to the world","Please enter names"};
								for (int i = 0; i < story.size(); i++)
								{
									for (int y = 0; y < story[i].size(); y++)
									{
										cout << story[i][y];
										Sleep(30);
									}
									Sleep(200);
									cout << endl;
								}
								cout << endl<<"Player-Knight:";
								cin >> players[0]->name;
								cout << endl << "Player-Magician:";
								cin >> players[1]->name;
								cout << endl << "Player-Orc:";
								cin >> players[2]->name;
							}
							if (choose == 1)
							{
								if (Load())
								{
									start++;
								}
							}
							if (choose == 2)
							{
								int leavech = 0;
								while (1)
								{
									system("cls");
									cout_title();
									gotoxy(55, 18);
									if (leavech == 0)
									{
										cout << "->";
									}
									cout << "Continue the game" << endl;
									gotoxy(55, 19);
									if (leavech == 1)
									{
										cout << "->";
									}
									cout << "Leave the game" << endl;
									char hhh = _getch();
									if (hhh == 'd')
									{
										if (leavech == 0)
										{
											break;
										}
										if (leavech == 1)
										{
											return;
										}

									}
									if (hhh == 'w')
									{
										if (leavech == 0)
										{
											leavech = 1;
										}
										else
										{
											leavech--;
										}
									}
									if (hhh == 's')
									{
										if (leavech == 1)
										{
											leavech = 0;
										}
										else
										{
											leavech++;
										}
									}
									if (hhh == 'a')
									{
										break;
									}
								}
							}
						}
						if (hh == 'w')
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
						if (hh == 's')
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
						if (hh == '`' || hh == 'a')
						{
							break;
						}
					}
					if (start == 0)
					{
						aa = _getch();
					}
				}
			}
			system("cls");
			print_title(&field, current_position);
			field.display();
			char aa = _getch();
			if (aa == 'w')
			{
				field.moveUp();
				check++;
			}
			if (aa == 's')
			{
				field.moveDown();
				check++;
			}
			if (aa == 'a')
			{
				field.moveLeft();
				check++;
			}
			if (aa == 'd')
			{
				field.moveRight();
				check++; 
			}
			if (aa == 'm')
			{
				field.monster_close=!field.monster_close;
			}
			if (aa == 't')
			{
				field.QQ.check_tasks();
			}
			if (aa == ' ')
			{
				system("cls");
				cout << aa;
				cout << "ＵＰ:Ｗ\nＤＯＷＮ：Ｓ\nＬＥＦＴ：Ａ\nＲＩＧＨＴ：Ｄ\nＰＬＡＹＥＲ　ＳＴＡＴＥ：Ｐ\nＯＰＥＮ　ＢＡＣＫＰＡＣＫ：Ｉ\nＯＰＴＩＯＮ：～\nＴＡＳＫ：Ｔ\nＣＬＯＳＥ＼ＯＰＥＮ　ＭＯＮＳＴＥＲ：Ｍ\n";
				while (1)
				{
					char out = _getch();
					if (out == ' ' || out == 'a')
					{
						break;
					}
				}
			}
			if (aa == 'i')
			{
				system("cls");
				int choose = 0;
				int state = 0;
				int state_item = 0;
				while (1)
				{
					if (players_backpack.equip(players, choose) == -1)
					{
						choose = 0;
						players_backpack.equip(players, choose);
					}
					else
					{
						choose = players_backpack.equip(players, choose);
					}
					char out = _getch();
					if (out == 'i' || out == 'a')
					{
						break;
					}
					if (out == 'w')
					{
						if (choose == 0)
						{
							choose = 999;
						}
						else
						{
							choose--;
						}

					}
					if (out == 's')
					{
						choose++;
					}
					if (out == 'd')
					{
						state++;
						while (1)
						{

							if (choose >= players_backpack.Sword_Weapon.size() + players_backpack.Axe_Weapon.size() + players_backpack.Magic_Weapon.size() + players_backpack.Shield_Armor.size() + players_backpack.Tunic_Armor.size())
							{
								system("cls");

								if (state_item == 1)
								{
									state_item = 0;
								}
								if (state_item == 0)
								{
									cout << "->";
								}
								cout << "Use" << endl;
							}
							else
							{
								system("cls");
								if (state_item == 0)
								{
									cout << "->";
								}
								cout << "Equip" << endl;
								if (state_item == 1)
								{
									cout << "->";
								}
								cout << "UnEquip" << endl;
							}
							char out_out = _getch();
							if (out_out == 's')
							{
								if (state_item == 1)
								{
									state_item = 0;
								}
								else
								{
									state_item++;
								}
							}
							if (out_out == 'w')
							{
								if (state_item == 0)
								{
									state_item = 1;
								}
								else
								{
									state_item--;
								}
							}
							if (out_out == 'a')
							{
								state--;
								break;
							}
							if (out_out == 'd')
							{
								if (state_item == 0)
								{
									state = 2;
								}
								else if (state_item == 1)
								{
									state = 3;
								}
								state_item = 0;
								while (1)
								{
									state_item = players_backpack.equip(players, choose, state, state_item);
									if (state == 2)
									{
										char out_out_out = _getch();
										if (out_out_out == 's')
										{
											if (state_item == 2)
											{
												state_item = 0;
											}
											else
											{
												state_item++;
											}
										}
										if (out_out_out == 'w')
										{
											if (state_item == 0)
											{
												state_item = 2;
											}
											else
											{
												state_item--;
											}
										}
										if (out_out_out == 'a')
										{
											state = 1;
											state_item = 0;
											break;
										}
										if (out_out_out == 'd')
										{
											players_backpack.equip(players, choose, state + 2, state_item);
										}
									}
									else
									{
										for (int i = 0; i < players.size(); i++)
										{
											players_backpack.equip(players, choose, state + 2, i);
										}
										state = 1;
										state_item = 1;
										system("cls");
										cout << "Done!"; 
										Sleep(500);
										break;
									}

								}
							}
						}

					}
				}
			}
			if (aa == '/')
			{
				players_backpack.setMoney(999999);
				for (int i = 0; i <players.size(); i++)
				{
					players[i]->setLevel(20);
					players[i]->Awaken();
				}
			}
			if (aa == '.')
			{
				players_backpack.setMoney(players_backpack.getMoney()+1000);
				for (int i = 0; i <players.size(); i++)
				{
					players[i]->setLevel(players[i]->getLevel()+1);
				}
			}
			if (aa == 'p')
			{
				system("cls");
				cout << "Money:" << players_backpack.getMoney() << endl << endl;
				for (int i = 0; i < players.size(); i++)
				{
					players[i]->status();
					cout << endl;
				}
				while (1)
				{
					char out = _getch();
					if (out == 'p' || out == 'a')
					{
						break;
					}
				}
			}
			if (aa == '-')
			{
				cout << "Save!";
				Save();
				system("pause");
			}
			if (aa == '=')
			{
				cout << "Load!";
				Load();
				system("pause");
			}
			if (aa == '`')
			{
				int choose = 0;
				while (1)
				{
					system("cls");
					cout_title();
					gotoxy(55, 18);
					if (choose == 0)
					{
						cout << "->";
					}
					cout << "Save" << endl;
					gotoxy(55, 19);
					if (choose == 1)
					{
						cout << "->";
					}
					cout << "Load" << endl;
					gotoxy(55, 20);
					if (choose == 2)
					{
						cout << "->";
					}
					cout << "Leave" << endl;
					char hh = _getch();
					if (hh == 'd')
					{
						if (choose == 0)
						{
							Save();
						}
						if (choose == 1)
						{
							Load();
						}
						if (choose == 2)
						{
							int leavech = 0;
							while (1)
							{
								system("cls");
								cout_title();
								gotoxy(55, 18);
								if (leavech == 0)
								{
									cout << "->";
								}
								cout << "Continue the game" << endl;
								gotoxy(55, 19);
								if (leavech == 1)
								{
									cout << "->";
								}
								cout << "Leave the game" << endl;
								char hhh = _getch();
								if (hhh == 'd')
								{
									if (leavech == 0)
									{
										break;
									}
									if (leavech == 1)
									{
										return;
									}
									
								}
								if (hhh == 'w')
								{
									if (leavech == 0)
									{
										leavech = 1;
									}
									else
									{
										leavech--;
									}
								}
								if (hhh == 's')
								{
									if (leavech == 1)
									{
										leavech = 0;
									}
									else
									{
										leavech++;
									}
								}
								if (hhh == 'a')
								{
									break;
								}
							}
						}
					}
					if (hh == 'w')
					{
						if (choose==0)
						{
							choose = 2;
						}
						else
						{
							choose--;
						}
					}
					if (hh == 's')
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
					if (hh == '`' || hh == 'a')
					{
						break;
					}
				}
			}
			position = field.arrive_end();
		}
	}
}
void System::Save()
{
	int choose = 0;
	while (1)
	{
		system("cls");
		cout_title();
		gotoxy(55, 18);
		if (choose == 0)
		{
			cout << "->";
		}
		cout << "Save1" << endl;
		gotoxy(55, 19);
		if (choose == 1)
		{
			cout << "->";
		}
		cout << "Save2" << endl;
		gotoxy(55, 20);
		if (choose == 2)
		{
			cout << "->";
		}
		cout << "Save3" << endl;
		char hh = _getch();
		if (hh == 'd')
		{
			break;
		}
		if (hh == 'w')
		{
			if (choose <= 0)
			{
				choose = 2;
			}
			else
			{
				choose--;
			}
		}
		if (hh == 's')
		{
			if (choose >= 2)
			{
				choose = 0;
			}
			else
			{
				choose++;
			}
		}
		if (hh == '`' || hh == 'a')
		{
			return;
		}
	}
	fstream data("data"+ iss(choose) + ".txt", ios::out);
	data << players_backpack.getMoney()<<endl;
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->name << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getLevel() << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getExp() << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getHp() << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getMp() << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->Awaked << endl;
	}
	players_backpack.Save(data);
	data.close();
	system("cls");
	cout_title();
	gotoxy(55, 18);
	cout << "Save!";
	Sleep(500);
}
int System::Load()
{
	int retu = 0;
	int choose = 0;
	while (1)
	{
		system("cls");
		cout_title();
		gotoxy(55, 18);
		if (choose == 0)
		{
			cout << "->";
		}
		cout << "Load1" << endl;
		gotoxy(55, 19);
		if (choose == 1)
		{
			cout << "->";
		}
		cout << "Load2" << endl;
		gotoxy(55, 20);
		if (choose == 2)
		{
			cout << "->";
		}
		cout << "Load3" << endl;
		char hh = _getch();
		if (hh == 'd')
		{
			break;
		}
		if (hh == 'w')
		{
			if (choose <= 0)
			{
				choose = 2;
			}
			else
			{
				choose--;
			}
		}
		if (hh == 's')
		{
			if (choose >= 2)
			{
				choose = 0;
			}
			else
			{
				choose++;
			}
		}
		if (hh == '`' || hh == 'a')
		{
			return 0;
		}
	}
	fstream data("data" + iss(choose) + ".txt", ios::in);
	string temp2;
	getline(data, temp2);
	players_backpack.setMoney(stin(temp2));
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data, temp);
		players[i]->name = temp;
	}
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data, temp);
		players[i]->setLevel(stin(temp));
	}
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data, temp);
		players[i]->setExp(stin(temp));
	}
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data, temp);
		players[i]->setHp(stin(temp));
	}
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data, temp);
		players[i]->setMp(stin(temp));
	}
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data, temp);
		players[i]->Awaked =stin(temp);
	}
	players_backpack.Load(data);
	data.close();
	system("cls");
	cout_title();
	gotoxy(55, 18);
	cout << "Load!";
	Sleep(500);
	return 1;
}






















