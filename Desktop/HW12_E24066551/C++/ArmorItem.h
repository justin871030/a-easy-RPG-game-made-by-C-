#pragma once


#ifndef ARMOR
#define ARMOR
#include"Item.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
class ArmorItem :public Item
{
public:
	ArmorItem(int, string, string, int, int,int = 7);
	int defense_increment; //the number of increment on defense after equipping this item
	string Type = "ArmorItem";
private:
};
ArmorItem::ArmorItem(int Level, string Name, string description, int Weight, int defense,int state)
	:Item(Level, Name, description, Weight, 'a',state)
{
	defense_increment=defense;
}
#endif
