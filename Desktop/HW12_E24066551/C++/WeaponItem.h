#pragma once


#ifndef WEAPON
#define WEAPON
#include"Item.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
class WeaponItem:public Item
{
public:
	WeaponItem(int, string, string, int, int,int = 7);
	int attack_increment; //the number of increment on attack after
	string Type = "WeaponItem";
private:
};
WeaponItem::WeaponItem(int Level, string Name, string description, int Weight, int attack , int state)
	:Item(Level, Name, description, Weight, 'w',state)
{
	attack_increment = attack;
}
#endif
