#pragma once
#include"GeneralPlayer.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef ABS_MON
#define ABS_MON
class AbstractMonster
{
public:
	AbstractMonster(string, int, int, int, int, int);
	~AbstractMonster();

	const string name;
	string race="Abstract";
	const int attack;
	const int defense;
	const int exp;
	const int max_hp;
	const int max_mp;
	int money=5;

	void setHP(int);
	int getHP() const;
	void setMP(int);
	int getMP() const;

	virtual void attackTo(GeneralPlayer*)=0;

	virtual void status()=0;
	string serialize() const;
	void unserialize(string);

	static int count;
	int damage_calculate(int attack, int defense);
private:
	int hp;
	int mp;
	
};
#endif


#ifndef GBL_MON
#define GBL_MON

class GoblinMonster :public AbstractMonster
{
public:
	GoblinMonster(string = "Goblin", int = 60, int = 40, int = 12, int = 100, int = 50);
	~GoblinMonster();

	string race = "Goblin";

	virtual void attackTo(GeneralPlayer*);
	void status();
};
#endif
#ifndef ZB_MON
#define ZB_MON

class ZombieMonster :public AbstractMonster
{
public:
	ZombieMonster(string = "Zombie", int = 50, int = 65, int = 17, int = 150, int = 30);
	~ZombieMonster();

	string race = "Zombie";

	virtual void attackTo(GeneralPlayer*);
	void status();
};

#endif
#ifndef JW_MON
#define JW_MON

class JWMonster :public AbstractMonster
{
public:
	JWMonster(string = "JWHuang", int = 120, int = 100, int = 42, int = 250, int = 100);
	~JWMonster();

	string race = "JW";

	virtual void attackTo(GeneralPlayer*);
	void status();
};

#endif
