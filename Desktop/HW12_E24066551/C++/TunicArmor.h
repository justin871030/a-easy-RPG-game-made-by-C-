#pragma once

using namespace std;

#ifndef TUNICARMOR
#define TUNICARMOR
#include"ArmorItem.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
class TunicArmor :public ArmorItem
{
public:
	TunicArmor(int, string, string, int, int,int = 7);
	string Type = "TunicArmor";
private:
};
TunicArmor::TunicArmor(int Level, string Name, string description, int Weight, int defense, int state)
	:ArmorItem(Level, Name, description, Weight, defense,state)
{
}
#endif
