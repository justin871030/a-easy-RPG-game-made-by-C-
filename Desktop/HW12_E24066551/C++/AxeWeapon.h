#pragma once


#ifndef AXEWEAPON
#define AXEWEAPON
#include"WeaponItem.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
class AxeWeapon :public WeaponItem
{
public:
	AxeWeapon(int, string, string, int, int,int = 7);
	string Type = "AxeWeapon";
private:
};
AxeWeapon::AxeWeapon(int Level, string Name, string description, int Weight, int attack, int state)
	:WeaponItem(Level, Name, description, Weight, attack, state)
{
}
#endif
