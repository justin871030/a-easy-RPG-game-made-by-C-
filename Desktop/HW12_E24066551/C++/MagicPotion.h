#pragma once


#ifndef MAGICITEM
#define MAGICITEM
#include"ConsumableItem.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
class MagicPotion :public ConsumableItem
{
public:
	MagicPotion(int, string, string, int, int,int = 7);
	string Type = "MagicPotion";
private:
};
MagicPotion::MagicPotion(int Level, string Name, string description, int Weight, int mp, int state)
	:ConsumableItem(Level, Name, description, Weight, 0,  mp,state)
{
}
#endif