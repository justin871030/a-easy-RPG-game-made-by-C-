#pragma once


#ifndef CONSUME
#define CONSUME
#include"Item.h"
#include"GeneralPlayer.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
class ConsumableItem:public Item
{
public:
	ConsumableItem(int, string, string, int, int, int,int = 7);
	int hp_recover;
	int mp_recover;
	string Type = "ConsumableItem";
	int number = 0;
	bool set_num(int);
	bool add_num(int);
private:
};
ConsumableItem::ConsumableItem(int Level, string Name, string description, int Weight, int hp, int mp, int state)
	:Item(Level, Name, description, Weight, 'c', state)
{
	hp_recover=hp;
	mp_recover=mp;
}
bool ConsumableItem::add_num(int num)
{
	if (num+number>=0)
	{
		number = num + number;
		if (number>0)
		{
			get = 1;
		}
		else
		{
			get = 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
bool ConsumableItem::set_num(int num)
{
	if (num  >= 0)
	{
		number =num;
		if (number>0)
		{
			get = 1;
		}
		else
		{
			get = 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
#endif
