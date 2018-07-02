#pragma once

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

#ifndef ITEM
#define ITEM
class Item
{
public:
	Item(int, string, string, int, char, int,int);
	int level_required; // level limit of equip/use this item
	string name; // the name of this item
				 /*E.g., ¡§JW¡¦s Hand¡¨
				 string effects; // a short description of its effect
				 E.g., ¡§Attack + 100, 20 % of probability making opponents cannot act at the next turn¡¨*/
	string description; // a short description of this item
						/*E.g., ¡§A silver - made hand - shaped weapon.There¡¦s a folklore said that once upon a time, a blacksmith encountered and was beaten by the JWMaster.While fighting with JWM, he found that the shape of JWM¡¦s hand is so beautiful.So he made a weapon that mimics the shape of JWM¡¦s hand for increasing his ability in self - defense.¡¨*/
	int weight; // the weight of the item
	char type;

	int owner = -1;
	int get = 0;/*If players get this item,set thid integer to 1.*/
	int price=15;

	/*Type of this item, ¡§w¡¨ for weapons, ¡§a¡¨ for armors, ¡§c¡¨ for consumables*/
	int item_state = 7;/*7=white,1=blue,5=purple,6=yellow;*/

	bool fit_out(int);
	void show();
private:

};
Item::Item(int Level, string Name, string Description, int Weight, char Type, int Price, int state)
{
	price = Price;
	item_state = state;
	level_required = Level;
	name = Name;
	description = Description;
	weight = Weight;
	type = Type;
}
bool Item::fit_out(int player)
{
	if (player >= 0 && player <= 2)
	{
		owner = player;
		return 1;
	}
	return 0;
}
void Item::show()
{
	cout << name << "(" << description << ")" << endl;
}
#endif

#ifndef WEAPON
#define WEAPON
class WeaponItem :public Item
{
public:
	WeaponItem(int, string, string, int, int, int,int = 7);
	int attack_increment; //the number of increment on attack after
	string Type = "WeaponItem";
private:
};
WeaponItem::WeaponItem(int Level, string Name, string description, int Weight, int attack, int price, int state)
	:Item(Level, Name, description, Weight, 'w', price, state)
{
	attack_increment = attack;
}
#endif

#ifndef ARMOR
#define ARMOR
class ArmorItem :public Item
{
public:
	ArmorItem(int, string, string, int, int, int,int = 7);
	int defense_increment; //the number of increment on defense after equipping this item
	string Type = "ArmorItem";
private:
};
ArmorItem::ArmorItem(int Level, string Name, string description, int Weight, int defense,int price, int state)
	:Item(Level, Name, description, Weight, 'a', price, state)
{
	defense_increment = defense;
}
#endif

#ifndef CONSUME
#define CONSUME
class ConsumableItem :public Item
{
public:
	ConsumableItem(int, string, string, int, int, int, int, int = 7);
	int hp_recover;
	int mp_recover;
	string Type = "ConsumableItem";
	int number = 0;
	bool set_num(int);
	bool add_num(int);
private:
};
ConsumableItem::ConsumableItem(int Level, string Name, string description, int Weight, int hp, int mp,int price, int state)
	:Item(Level, Name, description, Weight, 'c', price, state)
{
	hp_recover = hp;
	mp_recover = mp;
}
bool ConsumableItem::add_num(int num)
{
	if (num + number >= 0)
	{
		number = num + number;
		if (number>0)
		{
			get = 1;
		}
		else
		{
			get = 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
bool ConsumableItem::set_num(int num)
{
	if (num >= 0)
	{
		number = num;
		if (number>0)
		{
			get = 1;
		}
		else
		{
			get = 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
#endif

#ifndef SWORDWEAPON
#define SWORDWEAPON
class SwordWeapon :public WeaponItem
{
public:
	SwordWeapon(int, string, string, int, int, int, int = 7);
	string Type = "SwordWeapon";
private:
};
SwordWeapon::SwordWeapon(int Level, string Name, string description, int Weight, int attack, int price, int state)
	:WeaponItem(Level, Name, description, Weight, attack, price, state)
{
}
#endif

#ifndef AXEWEAPON
#define AXEWEAPON
class AxeWeapon :public WeaponItem
{
public:
	AxeWeapon(int, string, string, int, int, int, int = 7);
	string Type = "AxeWeapon";
private:
};
AxeWeapon::AxeWeapon(int Level, string Name, string description, int Weight, int attack, int price, int state)
	:WeaponItem(Level, Name, description, Weight, attack, price, state)
{
}
#endif

#ifndef MAGICWEAPON
#define  MAGICWEAPON
class MagicWeapon :public WeaponItem
{
public:
	MagicWeapon(int, string, string, int, int, int, int = 7);
	string Type = "MagicWeapon";
private:
};
MagicWeapon::MagicWeapon(int Level, string Name, string description, int Weight, int attack, int price, int state)
	:WeaponItem(Level, Name, description, Weight, attack, price, state)
{
}
#endif

#ifndef TUNICARMOR
#define TUNICARMOR
class TunicArmor :public ArmorItem
{
public:
	TunicArmor(int, string, string, int, int, int,int = 7);
	string Type = "TunicArmor";
private:
};
TunicArmor::TunicArmor(int Level, string Name, string description, int Weight, int defense, int price,int state)
	:ArmorItem(Level, Name, description, Weight, defense, price, state)
{
}
#endif

#ifndef SHIELDARMOR
#define SHIELDARMOR
class ShieldArmor :public ArmorItem
{
public:
	ShieldArmor(int, string, string, int, int, int,int = 7);
	string Type = "ShieldArmor";
private:
};
ShieldArmor::ShieldArmor(int Level, string Name, string description, int Weight, int defense, int price, int state)
	:ArmorItem(Level, Name, description, Weight, defense, price, state)
{
}
#endif

#ifndef LIFEITEM
#define LIFEITEM
class LifePotion :public ConsumableItem
{
public:
	LifePotion(int, string, string, int, int, int, int = 7);
	string Type = "LifePotion";
private:
};
LifePotion::LifePotion(int Level, string Name, string description, int Weight, int hp, int price, int state)
	:ConsumableItem(Level, Name, description, Weight, hp, 0, price, state)
{
}
#endif

#ifndef MAGICITEM
#define MAGICITEM
class MagicPotion :public ConsumableItem
{
public:
	MagicPotion(int, string, string, int, int, int,int = 7);
	string Type = "MagicPotion";
private:
};
MagicPotion::MagicPotion(int Level, string Name, string description, int Weight, int mp, int price, int state)
	:ConsumableItem(Level, Name, description, Weight, 0, mp, price, state)
{
}
#endif