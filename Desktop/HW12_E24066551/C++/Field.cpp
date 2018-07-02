#include"Field.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
#include"GeneralPlayer.h"
#include"AbstractMonster.h"
#include<windows.h>
using namespace std;

enum { Road = 0, Wall = 1, Start = 200, End = 201 ,Bed=101};
#define POINT "※";
#define ADD "●";
#define WALL "█";
#define ROAD "□";
#define RIGHT "→";
#define LEFT "←";
#define UP "↑";
#define DOWN "↓";

Task Field::QQ;
GrowingMonster Field::growingmonster;
vector<string>Transfer_str{ "You have grown strong enough,", "Are you ready for the trial?" };
Event Transfer(1, 0, "[Transfer]Path to Grow", Transfer_str,"Find the Coach somewhere at Volcanic Tunnel");
vector<string>Transfer_hunt_str{ "Please Kill 10 Monsters at XXXX" };
Hunt Transfer_hunt(1, 0, "[Transfer]Training!!!", Transfer_hunt_str, "Kill ten monsters");

vector<string>Hunt_str{ "Many monsters appear near the village,","please kill ten of those.", "Can you help me?" };
Hunt Hunting(1, 0, "[General]Hunt every day", Hunt_str,"Kill ten monster");

vector<string>Find_str{ "I lost my key near the village,","please help me find it.", "Can you help me?" };
Find Finding(1, 0, "[General]Find the Key", Find_str, "Find the key at Forest Trail");

NPC::NPC(vector<string>line)
{
	Line = line;
}
void NPC::speak()
{
	for (int i = 0; i < Line.size(); i++)
	{
		for (int j = 0; j < Line[i].size(); j++)
		{
			cout << Line[i][j];
			Sleep(30);
		}
		Sleep(100);
	}
	Sleep(300);
}
void NPC::put_line(vector<string>input)
{
	Line = input;
}
string iiss(int input)
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
Field::Field(const char* data, int x, int y, int width, int height,int Position,int start_input)
{
	position = Position;
	start_point = start_input;
	Map a(data);
	map_data = a.info;
	current_position_x = x;
	current_position_y = y;
	map_length_x = a.info[0].size();
	map_length_y = a.info.size();
	vision_width = width;
	vision_height = height;
}
//Similar to first one, but the first parameter is name of file that stores map data
Field::Field(vector<vector<int>>map_input, int width, int height, int Position, int start_input)
{
	position = Position;
	start_point = start_input;
	map_data = map_input;
	current_position_x = 1;
	current_position_y = 1;
	for (int i = 0; i < map_data.size(); i++)
	{
		for (int j = 0; j < map_data[i].size(); j++)
		{
			if (map_data[i][j]==200)
			{
				current_position_x = j;
				current_position_y = i;
			}
		}
	}
	map_length_x = map_data[0].size();
	map_length_y = map_data.size();
	if (Position)
	{
		vision_width = 100;
		vision_height = 100;
	}
	else
	{
		vision_width = width;
		vision_height = height;
	}
	set_start();
}
Field::Field(int x, int y, int width, int height, int Position, int start_input)
{
	position = Position;
	start_point = start_input;
	Map a(x,y);
	map_data = a.info;
	current_position_x = 1;
	current_position_y = 1;
	map_length_x = x;
	map_length_y = y;
	vision_width = width;
	vision_height = height;
	set_start();
}
void Field::set_players(vector<GeneralPlayer*>playerdata, GeneralPlayer* bag,Task* ptr)
{
	task_ptr = ptr;
	players = playerdata;
	backpack = bag;
	while (QQ.Tasks.size()==0)
	{
		QQ.Tasks.push_back(&Transfer);
		QQ.Tasks.push_back(&Transfer_hunt);
		QQ.Tasks.push_back(&Hunting);
		QQ.Tasks.push_back(&Finding);
	}
}
bool Field::NPC_(int x,int y)
{
	if (map_data[y][x]==101)
	{
		vector<string>Bed_line{ "Do You Want To Sleep?(Y/N)" };
		NPC Bed(Bed_line);
		Bed.speak();
		while (1)
		{
			int aa = _getch();
			if (aa=='y')
			{
				system("cls");
				for (int i =0; i < players.size(); i++)
				{
					players[i]->recoverHP();
					players[i]->recoverMP();
				}
				Sleep(1000);
				cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n                                         ";
				string temp = "The day breaks.";
				for (int i = 0; i < temp.size(); i++)
				{
					cout << temp[i];
					Sleep(30);
				}
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
				Sleep(200);
				break;
			}
			else if (aa == 'n')
			{
				break;
			}
		}
		
		return 1;
	}
	else if (map_data[y][x] == 102)
	{
		vector<string>Weapon_Saler_line{ "Welcome to the Weapon Store!!" };
		NPC Weapon_Saler(Weapon_Saler_line);
		Weapon_Saler.speak();
		backpack->buy_weapon();
		
	}
	else if (map_data[y][x] == 103)
	{
		vector<string>Weapon_Saler_line{ "Wellcome to the Armor Store!!" };
		NPC Weapon_Saler(Weapon_Saler_line);
		Weapon_Saler.speak();
		backpack->buy_armor();

	}
	else if (map_data[y][x] == 104)
	{
		vector<string>Weapon_Saler_line{ "Wellcome to the Potion Store!!" };
		NPC Weapon_Saler(Weapon_Saler_line);
		Weapon_Saler.speak();
		backpack->buy_potion();

	}
	else if (map_data[y][x] == 105)
	{
		vector<string>Weapon_Saler_line{ "..." };
		if (QQ.Tasks[0]->state==0&&players[0]->getLevel()+ players[1]->getLevel() + players[2]->getLevel() >=10 )
		{
			QQ.Tasks[0]->get_task();
		}
		else
		{
			TaskNPC Weapon_Saler(Weapon_Saler_line);
			Weapon_Saler.speak();
		}
	}
	else if (map_data[y][x] == 106)
	{
		if (QQ.Tasks[1]->state == 2 || QQ.Tasks[0]->state == 0)
		{
			vector<string>Weapon_Saler_line{ "..." };
			TaskNPC Weapon_Saler(Weapon_Saler_line);
			Weapon_Saler.speak();
		}
		else
		{
			if (QQ.Tasks[1]->state == 1)
			{
				if (!(QQ.Tasks[1]->is_finish()))
				{
					vector<string>Weapon_Saler_line{ iiss(QQ.Tasks[1]->progress_max-QQ.Tasks[1]->progress)+" monsters last" };
					TaskNPC Weapon_Saler(Weapon_Saler_line);
					Weapon_Saler.speak();
				}
				else
				{
					vector<string>Weapon_Saler_line{ "Congratulations on your completion of the test\n","You got new skills!" };
					TaskNPC Weapon_Saler(Weapon_Saler_line);
					Weapon_Saler.speak();
					QQ.Tasks[1]->state = 2;
					for (int i = 0; i < players.size(); i++)
					{
						players[i]->Awaken();
					}
				}
			}
			else
			{
				vector<string>Weapon_Saler_line{};
				TaskNPC Weapon_Saler(Weapon_Saler_line);
				Weapon_Saler.speak();
				QQ.Tasks[1]->get_task();
				QQ.Tasks[0]->state = 2;
			}
		}
	}
	else if (map_data[y][x] == 107)
	{
		if (QQ.Tasks[2]->state == 1&&QQ.Tasks[2]->is_finish())
		{
			vector<string>Weapon_Saler_line{ "Very thank you!","There are the gifts" };
			TaskNPC Weapon_Saler(Weapon_Saler_line);
			Weapon_Saler.speak();
			backpack->setMoney(backpack->getMoney() + 100);
			backpack->get_rand();
			QQ.Tasks[2]->state = 0;
			QQ.Tasks[2]->progress = 0;
		}
		else
		{
			if (QQ.Tasks[2]->state == 0)
			{
				QQ.Tasks[2]->get_task();
			}
			else if (QQ.Tasks[2]->state == 1)
			{
				vector<string>Weapon_Saler_line{ "Please help me..." };
				TaskNPC Weapon_Saler(Weapon_Saler_line);
				Weapon_Saler.speak();
			}
		}
	}
	else if (map_data[y][x] == 108)
	{
		if (QQ.Tasks[3]->state == 1 && QQ.Tasks[3]->is_finish())
		{
			vector<string>Weapon_Saler_line{ "Very thank you!","There are the $200" };
			TaskNPC Weapon_Saler(Weapon_Saler_line);
			Weapon_Saler.speak();
			backpack->setMoney(backpack->getMoney()+200);
			QQ.Tasks[3]->state = 0;
			QQ.Tasks[3]->progress = 0;
		}
		else
		{
			if (QQ.Tasks[3]->state == 0)
			{
				QQ.Tasks[3]->get_task();
			}
			else if (QQ.Tasks[3]->state == 1)
			{
				vector<string>Weapon_Saler_line{ "Please help me..." };
				TaskNPC Weapon_Saler(Weapon_Saler_line);
				Weapon_Saler.speak();
			}
		}
	}
	else
	{
		return 0;
	}
}
bool Field::move(char direction)
{
	switch (direction)
	{
	case('w'):
		if (moveUp())
		{
			step++;
			return 1;
		}
		return 0;
		break;
	case('s'):
		if (moveDown())
		{
			step++;
			return 1;
		}
		return 0;
		break;
	case('a'):
		if (moveLeft())
		{
			step++;
			return 1;
		}
		return 0;
		break;
	case('d'):
		if (moveRight())
		{
			step++;
			return 1;
		}
		return 0;
		break;
	default:
		cout << "Choose Error !";
		return 0;
		break;

	}
}
//Move player to next position, the parameter is the direction
//The return value indicates whether this move is legal or not
bool Field::moveLeft(void)
{
	if (current_position_x>0)
	{
		if (map_data[current_position_y][current_position_x - 1] != Wall && !NPC_(current_position_x-1, current_position_y))
		{
			setPosition(current_position_x - 1, current_position_y);
			if (map_data[current_position_y][current_position_x] >= 202 && map_data[current_position_y][current_position_x] <= 250)
			{
				map_data[current_position_y][current_position_x] = 0;
				battle();
				point++;
			}
			step++;
			return 1;
		}
	}
	return 0;
}
bool Field::moveRight(void)
{
	if (current_position_x<map_length_x - 1)
	{
		if (map_data[current_position_y][current_position_x + 1] != Wall && !NPC_(current_position_x+1, current_position_y))
		{
			setPosition(current_position_x + 1, current_position_y);
			if (map_data[current_position_y][current_position_x] >= 202 && map_data[current_position_y][current_position_x] <= 250)
			{
				map_data[current_position_y][current_position_x] = 0;
				battle();
				point++;
			}
			step++;
			return 1;
		}
	}
	return 0;
}
bool Field::moveUp(void)
{
	if (current_position_y>0)
	{
		if (map_data[current_position_y - 1][current_position_x] != Wall&&!NPC_(current_position_x,current_position_y-1))
		{
			setPosition(current_position_x, current_position_y - 1);
			if (map_data[current_position_y][current_position_x] >= 202&& map_data[current_position_y][current_position_x] <=250 )
			{
				map_data[current_position_y][current_position_x] = 0;
				battle();
				point++;
			}
			step++;
			return 1;
		}
	}
	return 0;
}
bool Field::moveDown(void)
{
	if (current_position_y<map_length_y - 1)
	{
		if (map_data[current_position_y + 1][current_position_x] != Wall && !NPC_(current_position_x, current_position_y + 1))
		{
			setPosition(current_position_x, current_position_y + 1);
			if (map_data[current_position_y][current_position_x] >= 202 && map_data[current_position_y][current_position_x] <= 250)
			{
				map_data[current_position_y][current_position_x] = 0;
				battle();
				point++;
			}
			step++;
			return 1;
		}
	}
	return 0;
}
//The same as move(char), move player to next position
//But the direction is determined

int Field::getCurrentPositionX(void) const
{
	return current_position_x;
}
int Field::getCurrentPositionY(void) const
{
	return current_position_y;
}
int Field::getVisionWidth(void) const
{
	return vision_width;
}
int Field::getVisionHeight(void) const
{
	return vision_height;
}
string Field::getMapName(void) const
{
	return map_name;
}
int Field::getMapSymbol(int x, int y)
{
	if (!(x<0 || y<0 || x >= map_length_x || y <= map_length_y))
	{
		cout << "Error";
		return 999;
	}
	else
	{
		return map_data[y][x];
	}
}
//Parameter is the position(x, y)
void Field::setPosition(int x, int y)
{
	if (x<0 || y<0 || x >= map_length_x || y >= map_length_y)
	{
		cout << "Error";
	}
	else
	{
		current_position_x = x;
		current_position_y = y;
	}
}
//Set the position of player, prameters are position(x, y)
void Field::setMapSymbol(int x, int y, int type)
{
	if (x<0 || y<0 || x >= map_length_x || y <= map_length_y)
	{
		cout << "Error";
	}
	else
	{
		map_data[y][x]=type;
	}
}
//Set the symbol on a specific position
//The first parameter is symbol, the rest are position(x, y)
void Field::setVisionSize(int width, int height)
{
	if (width<0 || height<0 || width >= map_length_x || height <= map_length_y)
	{
		cout << "Error";
	}
	else
	{
		vision_height = height;
		vision_width = width;
	}
}
//Set the size of vision, parameters are(width, height)
void Field::display_full(void) const
{
	for (int i = 0; i < map_length_y; i++)
	{
		for (int j = 0; j < map_length_x; j++)
		{
			if (j == current_position_x&&i==current_position_y)
			{
				cout << "幹";
			}
			else
			{
				if (map_data[i][j] >= 2 && map_data[i][j] <= 5)
				{
					/*cout << map_data[i][j] << " ";*/
					switch (map_data[i][j])
					{
					case 2:cout << UP; break;
					case 3:cout << DOWN; break;
					case 4:cout << LEFT; break;
					case 5:cout << RIGHT; break;
					}
				}
				else if (map_data[i][j] == 0)
				{
					cout << ROAD;
				}
				else if (map_data[i][j] == 1)
				{
					cout << WALL;
				}
				else if (map_data[i][j] >= 202)
				{
					cout << ADD;
				}
				else
				{
					cout << POINT;
				}
			}
		}
		cout << endl;
	}
}
void Field::display(void) const
{
	int count_x = 1;
	int count_y = 1;
	int start_x=current_position_x, start_y= current_position_y,end_x= current_position_x,end_y= current_position_y;
	int round=0;
	while (count_x<vision_width&& count_x<= map_data[0].size())
	{
		if (round%2==0&& start_x>0)
		{
			start_x--;
			count_x++;
		}
		else if(round % 2 == 1 && end_x < map_length_x)
		{
			end_x++;
			count_x++;
		}
		round++;
	}
	round = 0;
	while (count_y<vision_height && count_y <= map_data.size())
	{
		if (round % 2==0 && start_y > 0)
		{
			start_y--;
			count_y++;
		}
		else if (round % 2 == 1 && end_y < map_length_y)
		{
			end_y++;
			count_y++;
		}
		round++;
	}
	for (int i = start_y; i < end_y; i++)
	{
		for (int j = start_x; j < end_x; j++)
		{
			if (j == current_position_x && i == current_position_y)
			{
				cout << "★";
			}
			else
			{
				if (map_data[i][j] >= 2 && map_data[i][j] <= 5)
				{
					/*cout << map_data[i][j] << " ";*/
					switch (map_data[i][j])
					{
					case 2:cout << UP; break;
					case 3:cout << DOWN; break;
					case 4:cout << LEFT; break;
					case 5:cout << RIGHT; break;
					}
				}
				else if (map_data[i][j] == 0)
				{
					cout << ROAD;
				}
				else if (map_data[i][j] == 1)
				{
					cout << WALL;
				}
				else if (map_data[i][j] >= 202&& map_data[i][j] <= 250)
				{
					cout << ADD;
				}
				else 
				{
					cout << POINT;
				}
			}
		}
		cout << endl;
	}
}
void Field::run()
{
	/*display();
	cout << "use W,S,A,D to control,X to leave" << endl;
	cout << "(" << current_position_x << "," << current_position_y << ")" << endl;*/
	/*while (!arrive_end())
	{*/
    system("cls");
	display();
	cout << "use W,S,A,D to control" << endl;
		char aa = _getche();
		if (aa == 'w')
		{
			if (moveUp())
			{
				setPosition(current_position_x, current_position_y - 1);
				if (map_data[current_position_y][current_position_x]>=202)
				{
					map_data[current_position_y][current_position_x]=0;
					point++;
				}
			}
		}
		if (aa == 's')
		{
			if (moveDown())
			{
				setPosition(current_position_x, current_position_y + 1);
				if (map_data[current_position_y][current_position_x] >= 202)
				{
					map_data[current_position_y][current_position_x] = 0;
					point++;
				}
			}
		}
		if (aa == 'a')
		{
			if (moveLeft())
			{
				setPosition(current_position_x - 1, current_position_y);
				if (map_data[current_position_y][current_position_x] >= 202)
				{
					map_data[current_position_y][current_position_x] = 0;
					point++;
				}
			}
		}
		if (aa == 'd')
		{
			if (moveRight())
			{
				setPosition(current_position_x + 1, current_position_y);
				if (map_data[current_position_y][current_position_x] >= 202)
				{
					map_data[current_position_y][current_position_x] = 0;
					point++;
				}
			}
		}
		/*if (aa == 'x')
		{
			break;
		}*/
		system("cls");
		display();
		cout << "use W,S,A,D to control" << endl;
		cout <<"You are now at (" <<current_position_x<<","<< current_position_y<< ")" <<"POINT:"<<point<< endl;
		if (arrive_end())
		{
			cout << "Arrive!!";
		}
	/*}*/
	
}
//Displaying the map
void Field::set_start()
{
	for (int i = 0; i < map_length_y; i++)
	{
		for (int j = 0; j < map_length_x; j++)
		{
			if (map_data[i][j]== start_point+1000)
			{
				start_x=j;
				start_y=i;
				current_position_x = j;
				current_position_y = i;
			}
			if (map_data[i][j] >= 1000)
			{
				end_x.push_back(j);
				end_y.push_back(i);
			}
		}
	}
}
int Field::arrive_end()
{
	for (int i = 0; i < end_x.size(); i++)
	{
		if (current_position_x == end_x[i] && current_position_y == end_y[i]&&step>=2)
		{
			return map_data[current_position_y][current_position_x]-1000;
		}
	}
	return -1;
}
void Field::make_monster()
{
	if ((!monster_close)&&position!=5&& position != 6&&position != 1 && position != 7 && position != 1 && position != 8 && position != 5 && position != 10 && position != 11)
	{
		int max = map_length_x * map_length_y / 15;
		int count = 0;
		srand(time(NULL));
		for (int i = 0; i < map_data.size(); i++)
		{
			for (int j = 0; j < map_data[0].size(); j++)
			{
				if (map_data[i][j] >= 202 && map_data[i][j] <= 250)
				{
					count++;
				}
			}
		}
		if (count<max&&rand() % 5 == 0)
		{
			int get = 0;
			while (get == 0)
			{
				int y = rand() % map_data.size();
				int x = rand() % map_data[0].size();
				if (map_data[y][x] == 0)
				{
					map_data[y][x] = 202;
					get = 1;
				}
			}
		}
	}
	else if (position == 5 &&players[0]->getLevel()+ players[1]->getLevel()+ players[2]->getLevel()>=20&&QQ.Tasks[1]->state==2)
	{
		map_data[5][4] = 202;
	}
}
int  Field::monster_close=0;
void Field::battle()
{
	if (position == 5)
	{
		cout << "BIG BOSS !!!!!!!!!!!!!!";
		Sleep(500);
		vector<AbstractMonster*>monsters;/*怪獸設定的陣列*/
		JWMonster JWMonster("VeryBigBoss");
		monsters.push_back(&JWMonster);
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		die = battle.run();
		if (die == 1)
		{
			vector<string>temp{ "Warrior...","Congratulations on defeating the devil!","This village restore peace again!","Thanks for playing~" };
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
		}
	}
	else if (position == 0)
	{
		cout << "Accident happened!!";
		Sleep(500);
		vector<AbstractMonster*>monsters(2);/*怪獸設定的陣列*/
		GoblinMonster GoblinMonster1("LittleGoblin1", 20, 10, 10, 50, 20);
		GoblinMonster GoblinMonster2("LittleGoblin2", 20, 10, 10, 50, 20);
		GoblinMonster1.money = 10;
		monsters[0] = &GoblinMonster1;
		monsters[1] = &GoblinMonster2;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		die = battle.run();
		QQ.Tasks[2]->progress += die;
	}
	else if (position == 3)
	{
		cout << "Accident happened!!";
		Sleep(500);
		vector<AbstractMonster*>monsters(1);/*怪獸設定的陣列*/
		ZombieMonster GoblinMonster1("Unknown monster", 80, 80, 50, 200, 80);
		GoblinMonster1.money = 30;
		monsters[0] = &GoblinMonster1;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		die = battle.run();
		if (QQ.Tasks[1]->state == 1)
		{
			/*cout << battle.run();
			system("pause");*/
			QQ.Tasks[1]->progress += die;
		}
	}
	else if (position ==11)
	{
		growingmonster.grow();
		cout << "Accident happened!!";
		Sleep(500);
		vector<AbstractMonster*>monsters(1);/*怪獸設定的陣列*/
		monsters[0] = &growingmonster;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		die = battle.run();
	}
	else if(position == 2)
	{
		cout << "Accident happened!!";
		Sleep(500);
		vector<AbstractMonster*>monsters(2);/*怪獸設定的陣列*/
		ZombieMonster ZombieMonster1("ZombieMonster1");
		GoblinMonster GoblinMonster1("GoblinMonster1");
		monsters[0] = &GoblinMonster1;
		monsters[1] = &ZombieMonster1;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		srand(time(NULL));
		int aa = rand()%2;
		if (aa==1)
		{
			QQ.Tasks[3]->progress = 1;
		}
		die = battle.run();
		QQ.Tasks[2]->progress+=die;
	}
	else
	{
		cout << "Accident happened!!";
		Sleep(500);
		vector<AbstractMonster*>monsters(2);/*怪獸設定的陣列*/
		ZombieMonster ZombieMonster1("ZombieMonster1");
		GoblinMonster GoblinMonster1("GoblinMonster1");
		monsters[0] = &GoblinMonster1;
		monsters[1] = &ZombieMonster1;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		die=battle.run();
	}
}