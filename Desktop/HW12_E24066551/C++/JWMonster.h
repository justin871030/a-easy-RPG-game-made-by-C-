#pragma once
#include"AbstractMonster.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


#ifndef JW_MON
#define JW_MON

class JWMonster:public AbstractMonster
{
public:
	JWMonster(string = "JWHuang", int = 120, int = 100, int = 42, int = 250, int = 100);
	~JWMonster();

	string race = "JW";

	virtual void attackTo(GeneralPlayer*);
	void status();
};

#endif

