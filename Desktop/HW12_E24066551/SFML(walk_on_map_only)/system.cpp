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
	players_backpack.setMoney(5000);
	vector<string> mapname{"Dragon's Lair","Village","Forest Trail","XXXX","Volcanic Tunnel","Devil Nest","¢Ö¢Ý¢Û¢Ó","Weapon Shop" };
	set_mapname(mapname);
	int check = 0;
	while (position < 8)
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
		field.set_players(players, &players_backpack);
		current_position = next_position;
		while (field.arrive_end() == -1)
		{
			field.make_monster();
			system("cls");
			print_title(&field, current_position);
			field.display();
			players_backpack.setMoney(players_backpack.getMoney() + players[0]->getMoney() + players[1]->getMoney() + players[2]->getMoney());
			players[0]->setMoney(0);
			players[1]->setMoney(0);
			players[2]->setMoney(0);
			system("cls");
			print_title(&field, current_position);
			field.display();
			char aa = _getch();
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				field.moveUp();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				field.moveDown();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				field.moveLeft();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				field.moveRight();
				check++;
			}
			if (aa == ' ')
			{
				system("cls");
				cout << "¢ã¢Þ:¢å\n¢Ò¢Ý¢å¢Ü¡G¢á\n¢Ú¢Ó¢Ô¢â¡G¢Ï\n¢à¢×¢Õ¢Ö¢â¡G¢Ò\n¢Þ¢Ú¢Ï¢ç¢Ó¢à¡@¢á¢â¢Ï¢â¢Ó¡G¢Þ\n¢Ý¢Þ¢Ó¢Ü¡@¢Ð¢Ï¢Ñ¢Ù¢Þ¢Ï¢Ñ¢Ù¡G¢×";
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
										system("pause");
										break;
									}

								}
							}
						}

					}
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
					if (choose == 0)
					{
						cout << "->";
					}
					cout << "Save" << endl;
					if (choose == 1)
					{
						cout << "->";
					}
					cout << "Load" << endl;
					char hh = _getch();
					if (hh == 'd')
					{
						if (choose == 0)
						{
							cout << "Save!";
							Save();
							system("pause");
						}
						else
						{
							cout << "Load!";
							Load();
							system("pause");
						}
					}
					if (hh == 'w'|| hh == 's')
					{
						choose = !choose;
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
void System::SFML()
{
	KnightPlayer temp;
	MagicianPlayer temp2;
	OrcPlayer temp3;
	players.push_back(&temp);
	players.push_back(&temp2);
	players.push_back(&temp3);
	players_backpack.backpack_setup();
	players_backpack.setMoney(5000);
	vector<string> mapname{ "Dragon's Lair","Village","Forest Trail","XXXX","Volcanic Tunnel","Devil Nest","¢Ö¢Ý¢Û¢Ó","Weapon Shop" };
	set_mapname(mapname);
	int check = 0;
	while (position < 8)
	{
		int next_position = position;
		if (next_position == current_position && check != 0)
		{
			if (next_position == 0)
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
		field.set_players(players, &players_backpack);
		window = field.send_window();
		current_position = next_position;
		while (field.arrive_end() == -1)
		{
			Event event;
			while (field.window.pollEvent(event))
			{
				field.clocks.restart();
				if (event.type == sf::Event::Closed)
					field.window.close();
			}
			field.deltaTime = field.clocks.restart().asSeconds();
			field.make_monster();
			system("cls");
			print_title(&field, current_position);
			field.display();
			players_backpack.setMoney(players_backpack.getMoney() + players[0]->getMoney() + players[1]->getMoney() + players[2]->getMoney());
			players[0]->setMoney(0);
			players[1]->setMoney(0);
			players[2]->setMoney(0);
			system("cls");
			print_title(&field, current_position);
			field.display();
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				field.moveUp();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				field.moveDown();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				field.moveLeft();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				field.moveRight();
				check++;
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				system("cls");
				cout << "¢ã¢Þ:¢å\n¢Ò¢Ý¢å¢Ü¡G¢á\n¢Ú¢Ó¢Ô¢â¡G¢Ï\n¢à¢×¢Õ¢Ö¢â¡G¢Ò\n¢Þ¢Ú¢Ï¢ç¢Ó¢à¡@¢á¢â¢Ï¢â¢Ó¡G¢Þ\n¢Ý¢Þ¢Ó¢Ü¡@¢Ð¢Ï¢Ñ¢Ù¢Þ¢Ï¢Ñ¢Ù¡G¢×";
				while (1)
				{
					char out = _getch();
					if (out == ' ' || out == 'a')
					{
						break;
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::I))
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
					if (Keyboard::isKeyPressed(Keyboard::I) || Keyboard::isKeyPressed(Keyboard::A))
					{
						break;
					}
					if (Keyboard::isKeyPressed(Keyboard::W))
					{
						if (choose == 0)
						{
							choose = 999;
						}
						else
						{
							choose--;
						}
						Sleep(50);
					}
					if (Keyboard::isKeyPressed(Keyboard::S))
					{
						choose++;
						Sleep(50);
					}
					if (Keyboard::isKeyPressed(Keyboard::D))
					{
						state++;
						Sleep(150);
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
							if (Keyboard::isKeyPressed(Keyboard::S))
							{
								if (state_item == 1)
								{
									state_item = 0;
								}
								else
								{
									state_item++;
								}
								Sleep(150);
							}
							if (Keyboard::isKeyPressed(Keyboard::W))
							{
								if (state_item == 0)
								{
									state_item = 1;
								}
								else
								{
									state_item--;
								}
								Sleep(150);
							}
							if (Keyboard::isKeyPressed(Keyboard::A))
							{
								state--;
								break;
							}
							if (Keyboard::isKeyPressed(Keyboard::D))
							{
								Sleep(100);
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
									Sleep(50);
									state_item = players_backpack.equip(players, choose, state, state_item);
									if (state == 2)
									{
										if (Keyboard::isKeyPressed(Keyboard::S))
										{
											if (state_item == 2)
											{
												state_item = 0;
											}
											else
											{
												state_item++;
											}
											Sleep(100);
										}
										if (Keyboard::isKeyPressed(Keyboard::W))
										{
											if (state_item == 0)
											{
												state_item = 2;
											}
											else
											{
												state_item--;
											}
											Sleep(100);
										}
										if (Keyboard::isKeyPressed(Keyboard::A))
										{
											state = 1;
											state_item = 0;
											break;
										}
										if (Keyboard::isKeyPressed(Keyboard::D))
										{
											players_backpack.equip(players, choose, state + 2, state_item);
											Sleep(150);
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
								Sleep(150);
							}
						}
						Sleep(50);
					}
					Sleep(50);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				system("cls");
				cout << "Money:" << players_backpack.getMoney() << endl << endl;
				for (int i = 0; i < players.size(); i++)
				{
					players[i]->status();
					cout << endl;
				}
				Sleep(200);
				while (1)
				{
					if (Keyboard::isKeyPressed(Keyboard::P) || Keyboard::isKeyPressed(Keyboard::A))
					{
						break;
					}
				}
				Sleep(100);
			}
			if (Keyboard::isKeyPressed(Keyboard::Dash))
			{
				cout << "Save!";
				Sleep(500);
				Save();
			}
			if (Keyboard::isKeyPressed(Keyboard::Equal))
			{
				cout << "Load!";
				Load();
			}
			if (Keyboard::isKeyPressed(Keyboard::Tilde))
			{
				Sleep(100);
				int choose = 0;
				while (1)
				{
					system("cls");
					if (choose == 0)
					{
						cout << "->";
					}
					cout << "Save" << endl;
					if (choose == 1)
					{
						cout << "->";
					}
					cout << "Load" << endl;
					char hh = _getch();
					if (Keyboard::isKeyPressed(Keyboard::D))
					{
						if (choose == 0)
						{
							cout << "Save!";
							Save();
						}
						else
						{
							cout << "Load!";
							Load();
						}
						Sleep(100);
					}
					if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S))
					{
						choose = !choose;
						Sleep(100);
					}
					if (Keyboard::isKeyPressed(Keyboard::Tilde) || Keyboard::isKeyPressed(Keyboard::A))
					{
						Sleep(100);
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
	fstream data("data.txt",ios::out);
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->name << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getExp()<< endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getHp() << endl;
	}
	for (int i = 0; i < players.size(); i++)
	{
		data << players[i]->getMp() << endl;
	}
	players_backpack.Save(data);
	data.close();
}
void System::Load()
{
	fstream data("data.txt", ios::in);
	for (int i = 0; i < players.size(); i++)
	{
		string temp;
		getline(data,temp);
		players[i]->name =temp;
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
	players_backpack.Load(data);
	data.close();
}






















