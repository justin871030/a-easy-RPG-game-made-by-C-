#pragma once


#ifndef SHIELDARMOR
#define SHIELDARMOR
#include"ArmorItem.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
class ShieldArmor :public ArmorItem
{
public:
	ShieldArmor(int, string, string, int, int,int=7);
	string Type = "ShieldArmor";
private:
};
ShieldArmor::ShieldArmor(int Level, string Name, string description, int Weight, int defense, int state)
	:ArmorItem( Level, Name, description, Weight,defense,state)
{
}
#endif
