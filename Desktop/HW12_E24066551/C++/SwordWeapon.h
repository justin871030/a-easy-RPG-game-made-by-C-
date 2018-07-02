#pragma once

using namespace std;

#ifndef SWORDWEAPON
#define SWORDWEAPON
#include"WeaponItem.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
class SwordWeapon :public WeaponItem
{
public:
	SwordWeapon(int, string, string, int, int,int = 7);
	string Type = "SwordWeapon";
private:
};
SwordWeapon::SwordWeapon(int Level, string Name, string description, int Weight, int attack, int state)
	:WeaponItem(Level, Name, description, Weight, attack,state)
{
}
#endif
