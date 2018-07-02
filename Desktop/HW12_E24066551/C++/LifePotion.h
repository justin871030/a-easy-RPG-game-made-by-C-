#pragma once

using namespace std;

#ifndef LIFEITEM
#define LIFEITEM
#include"ConsumableItem.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
class LifePotion :public ConsumableItem
{
public:
	LifePotion(int, string, string, int, int,int = 7);
	string Type = "LifePotion";
private:
};
LifePotion::LifePotion(int Level, string Name, string description, int Weight, int hp, int state)
	:ConsumableItem(Level, Name, description, Weight, hp, 0,state)
{
}
#endif
