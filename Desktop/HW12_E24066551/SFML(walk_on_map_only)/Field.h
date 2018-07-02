#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<time.h>
#include<string>
#include<conio.h>
#include"Map.h"
#include"Image.h"
#include"Battle.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;
class GeneralPlayer;

#ifndef FIELD
#define FIELD
class Field
{
public:
	Field(vector<vector<int>>,int width, int height, int, int);
	/*Field(int**, int, int, int, int);*/
	//The first parameter is the map data
	//The second and third parameter are the current place(x, y) of player
	//The forth and fifth parameter are the(width, height) of vision
	Field(const char*, int, int, int, int, int, int);
	//Similar to first one, but the first parameter is name of file that stores map data
	Field(int, int, int, int, int, int);

	bool move(char);
	bool moveUp(void);
	bool moveDown(void);
	bool moveLeft(void);
	bool moveRight(void);
	int side=0;
	//The same as move(char), move player to next position
	//But the direction is determined

	int getCurrentPositionX(void) const;
	int getCurrentPositionY(void) const;
	int getVisionWidth(void) const;
	int getVisionHeight(void) const;
	string getMapName(void) const;
	int getMapSymbol(int, int);
	//Parameter is the position(x, y)
	void setPosition(int, int);
	//Set the position of player, prameters are position(x, y)
	void setMapSymbol(int, int, int);
	//Set the symbol on a specific position
	//The first parameter is symbol, the rest are position(x, y)
	void setVisionSize(int, int);
	//Set the size of vision, parameters are(width, height)
	void display(void) const;
	//Displaying the map
	void display_full (void) const;
	void run();
	bool NPC_(int,int);
	void set_start();
	GeneralPlayer* backpack;
	void set_players(vector<GeneralPlayer*>, GeneralPlayer*);
	int arrive_end();/*沒到終點傳回-1,否則傳回傳點編號*/
	int map_length_x;
	int map_length_y;
	void make_monster();
	void battle();
/*private:*/
	vector<vector<int>> map_data;
	vector<GeneralPlayer*> players;
	int point = 0;
	//The actual map data with symbols and items
	//This is a double dimension array of integers
	int current_position_x=1;
	int current_position_y=1;
	string map_name;
	//The name of this map
	int vision_width;
	int vision_height;
	//The width and height of visio
	int start_point;
	int position;
	int last_position;
	int start_x;
	int start_y;
	vector<int> end_x;
	vector<int> end_y;
	int step = 0;

	static RenderWindow window;
	Clock clocks;
	float deltaTime = 0.0f;
	RenderWindow* send_window();
	void SFML();
};
class NPC
{
public:
	NPC(vector<string>);
	vector<string>Line;
	void speak();
	void put_line(vector<string>);
};

#endif

