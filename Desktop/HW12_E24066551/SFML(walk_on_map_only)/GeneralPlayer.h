#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
/*#include"SwordWeapon.h"
#include"AxeWeapon.h"
#include"ShieldArmor.h"
#include"TunicArmor.h"
#include"LifePotion.h"
#include"MagicPotion.h"*/
using namespace std;
class AbstractMonster;
class Item;
class WeaponItem;
class ArmorItem;
class ConsumableItem;
class SwordWeapon;
class AxeWeapon;
class MagicWeapon;
class ShieldArmor;
class TunicArmor;
class MagicPotion;
class LifePotion;
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#ifndef GeneralPlayerclass
#define GeneralPlayerclass
class GeneralPlayer
{
public:
	string race="General";
	string name; // Stores the name of the player
	int hp; // Stores the HP of the player, >= 0
	int mp; // Stores the MP of the player, >= 0
	int exp; // Stores the experience of the player, >= 0
			 // Will not reset to zero after level-up

	GeneralPlayer(); // default constructor
	//With level = 1, name = ¡§anonymous¡¨
	GeneralPlayer(int); // normal constructor
	//Initializes level of the player, name = ¡§anonymous¡¨
	GeneralPlayer(string); // normal constructor
	GeneralPlayer(int, string); // normal constructor
	//Initializes level  and name of the player
	GeneralPlayer(int, int, int, int);
	GeneralPlayer(int, int, int, int, string);
	GeneralPlayer(const GeneralPlayer&);
	//Copy constructor
		//Call setAttr() in setLevel() to set attributes

	void setName(string = "anonymous");
	string getName(void) const;
	void setLevel(int); // need to call setAttr() inside
	int getLevel(void) const;
	void setHp(int);
	int getHp(void) const;
	void setMp(int);
	int getMp(void) const;
	void setExp(int);
	int getExp(void) const;
	void setMoney(int);
	int getMoney() const;
	int getAttack(void) const;
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;

	virtual void setAttr(int); // parameter is level
	virtual void levelUp(void); // level++

	void increaseHP(int);
	void increaseMP(int);
	void increaseExp(int);
	void recoverHP(void); // hp = max_hp;
	void recoverMP(void); // mp = max_mp;

	virtual void specialSkill();
	void attackTo(AbstractMonster*);

	virtual void status();
	string serialize() const;
	void unserialize(string);


	vector<SwordWeapon*> Sword_Weapon; // weapon item
	vector<AxeWeapon*> Axe_Weapon; // armor item
	vector<MagicWeapon*> Magic_Weapon; // armor item
	vector<ShieldArmor*> Shield_Armor; // consumable item
	vector<TunicArmor*> Tunic_Armor; // weapon item
	vector<LifePotion*>Life_Potion; // armor item
	vector<MagicPotion*> Magic_Potion; // consumable item
	int backpack_weight=0; // current weight of player¡¦s backpack
	int backpack_weight_limit=999; // limit on weight of backpack
	int backpack_slot_limit=999; // limit on number of backpack¡¦s slots
	/*Limits may vary according to job, level, etc.
		They should be set within setAttr() !*/

	void backpack_setup();
	void backpack_setup(vector<SwordWeapon*> ,vector<AxeWeapon*>,vector<ShieldArmor*>,vector<TunicArmor*> ,vector<LifePotion*>,vector<MagicPotion*>);
	void backpack_put(SwordWeapon*);
	void backpack_put(AxeWeapon*);
	void backpack_put(MagicWeapon*);
	void backpack_put(ShieldArmor*);
	void backpack_put(TunicArmor*);
	void backpack_put(LifePotion*);
	void backpack_put(MagicPotion*);

	bool backpack_oversize(Item*);
	void backpack_status();

	void item_get(int);
	bool fit_up(SwordWeapon*);
	bool fit_up(AxeWeapon*);
	bool fit_up(MagicWeapon*);
	bool fit_up(ShieldArmor*);
	bool fit_up(TunicArmor*);
	bool put_off(SwordWeapon*);
	bool put_off(AxeWeapon*);
	bool put_off(MagicWeapon*);
	bool put_off(ShieldArmor*);
	bool put_off(TunicArmor*);
	bool use(LifePotion*);
	bool use(MagicPotion*);
	SwordWeapon*Sword_Weapon_equip = NULL;
	AxeWeapon*Axe_Weapon_equip = NULL;
	MagicWeapon*Magic_Weapon_equip = NULL;
	ShieldArmor*Shield_Armor_equip = NULL;
	TunicArmor*Tunic_Armor_equip = NULL;
	Item*Item_point = NULL;
	char Item_point_type ='n';
	RenderWindow* window;
	void buy_weapon();
	void buy_armor();
	void buy_potion();
	int equip(vector<GeneralPlayer*>,int, int=0, int=0);

	void Save(fstream&);
	void Load(fstream&);
protected:
	int level; // Stores the level of the player, >= 1
	int attack; // stores attack of the player
	int defense; // stores defense of the player
	int max_hp; // stores max. HP of the player
	int max_mp; // stores max. MP of the player
	int lvup_exp; // stores needed exp. to level-up
	int money; // represents the number of money, >=0
	int extra_attack=0;
	int extra_defense=0;

private:

};




#endif
#ifndef KnightPlayerPlayerclass
#define KnightPlayerPlayerclass





class KnightPlayer :public GeneralPlayer
{
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(string);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void increaseExp(int EXP);

	virtual void specialSkill();
	void heal(void);

	virtual void status();
};
#endif
#ifndef MagicianPlayerclass
#define MagicianPlayerclass





class MagicianPlayer :public GeneralPlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(string);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void increaseExp(int EXP);

	virtual void specialSkill();
	void pray(void);

	virtual void status();
};
#endif
#ifndef OrcPlayerclass
#define OrcPlayerPlayerclass

class OrcPlayer :public GeneralPlayer
{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(string);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void increaseExp(int EXP);

	virtual void specialSkill();

	virtual void status();
};
#endif