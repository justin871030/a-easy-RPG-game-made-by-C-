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
RenderWindow Field::window(sf::VideoMode(1000, 1000), "Fuck");
Image_char PLA("char.png", Vector2u(3, 4), 0.3f);
Image_char Portal ("Portal.png", Vector2u(3, 1), 0.8f);
Image_char Weaponsale("charl.png", Vector2u(3, 4), 2.0f);


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
}
void NPC::put_line(vector<string>input)
{
	Line = input;
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
void Field::set_players(vector<GeneralPlayer*>playerdata, GeneralPlayer* bag)
{
	players = playerdata;
	backpack = bag;
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
				system("pause");
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
		vector<string>Weapon_Saler_line{ "Wellcome to the Weapon Store!!" };
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
			side = 1;
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
			side = 2;
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
			side = 3;
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
			side = 0;
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
	window.clear();
	RectangleShape Blue(Vector2f(32, 32));
	Texture background;
	background.loadFromFile("blue.png");
	Blue.setTexture(&background);
	RectangleShape Brown(Vector2f(32, 32));
	Texture bbackground;
	bbackground.loadFromFile("brown.png");
	Brown.setTexture(&bbackground);
	RectangleShape Gray(Vector2f(32, 32));
	Texture bbbackground;
	bbbackground.loadFromFile("gray.png");
	Gray.setTexture(&bbbackground);
	RectangleShape Mons(Vector2f(32, 32));
	Texture bbbbackground;
	bbbbackground.loadFromFile("monster.png");
	Mons.setTexture(&bbbbackground);
	RectangleShape player(Vector2f(32, 32));
	player.setTexture(&PLA.playerTexture);
	PLA.Update(side, deltaTime);
	player.setTextureRect(PLA.uvRect);
	RectangleShape portal(Vector2f(32, 32));
	portal.setTexture(&Portal.playerTexture);
	Portal.Update(0, deltaTime);
	portal.setTextureRect(Portal.uvRect);
	RectangleShape Weaponsale(Vector2f(32, 32));
	Texture bbbbbackground;
	bbbbbackground.loadFromFile("char1.png");
	Weaponsale.setTexture(&bbbbbackground);

	for (int i = start_y; i < end_y; i++)
	{
		for (int j = start_x; j < end_x; j++)
		{
			if (j == current_position_x && i == current_position_y)
			{
				Gray.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
				window.draw(Gray);
				player.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
				window.draw(player);
				cout << "○";
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
					Gray.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(Gray);
					cout << ROAD;
				}
				else if (map_data[i][j] == 1)
				{
					Blue.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(Blue);
					cout << WALL;
				}
				else if (map_data[i][j] >= 100 && map_data[i][j] <= 150)
				{
					Gray.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(Gray);
					if (map_data[i][j]==102)
					{
						Weaponsale.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
						window.draw(Weaponsale);
					}
					cout << ADD;
				}
				else if (map_data[i][j] >= 1000 && map_data[i][j] <= 1050)
				{
					Gray.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(Gray);
					portal.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(portal);
				}
				else if (map_data[i][j] >= 202&& map_data[i][j] <= 250)
				{
					Gray.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(Gray);
					Mons.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(Mons);
					cout << ADD;
				}
				else 
				{
					cout << POINT;
				}
				if (j == current_position_x && i == current_position_y)
				{
					player.setPosition(Vector2f(j * 32 + 100, i * 32 + 100));
					window.draw(player);
				}
			}
		}
		cout << endl;
	}
	window.display();
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
	if (position!=5&& position != 6&&position != 1 && position != 7)
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
}
void Field::battle()
{
	if (position == 5)
	{
		cout << "BIG BOSS !!!!!!!!!!!!!!(press 5 times to enter)";
		system("pause");
		system("pause");
		system("pause");
		system("pause");
		system("pause");
		vector<AbstractMonster*>monsters;/*怪獸設定的陣列*/
		JWMonster JWMonster("VeryBigBoss");
		monsters.push_back(&JWMonster);
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		battle.run();
	}
	else if (position == 0)
	{
		cout << "Accident happened!!(press 5 times to enter)";
		system("pause");
		system("pause");
		system("pause");
		system("pause");
		system("pause");
		vector<AbstractMonster*>monsters(2);/*怪獸設定的陣列*/
		GoblinMonster GoblinMonster1("LittleGoblin", 20, 10, 10, 50, 20);
		GoblinMonster GoblinMonster2("LittleGoblin", 20, 10, 10, 50, 20);
		GoblinMonster1.money = 10;
		monsters[0] = &GoblinMonster1;
		monsters[1] = &GoblinMonster2;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		battle.run();
	}
	else
	{
		cout << "Accident happened!!(press 5 times to enter)";
		system("pause");
		system("pause");
		system("pause");
		system("pause");
		system("pause");
		vector<AbstractMonster*>monsters(2);/*怪獸設定的陣列*/
		ZombieMonster ZombieMonster1;
		GoblinMonster GoblinMonster1("MotherFucker");
		monsters[0] = &GoblinMonster1;
		monsters[1] = &ZombieMonster1;
		Battle battle(players, monsters, players.size(), monsters.size(), 5);
		battle.run();
	}
}
RenderWindow* Field::send_window()
{
	return &(window) ;
}