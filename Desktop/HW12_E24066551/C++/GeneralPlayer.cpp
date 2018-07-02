#include"GeneralPlayer.h"
#include"AbstractMonster.h"
#include"item.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;
extern SwordWeapon weapon1(1, "Normal Sword[Knight Only]", "Little...", 3, 10,100);
extern SwordWeapon weapon10(1, "Alloy Sword[Knight Only]", "Little...", 3, 20, 150,1);
extern SwordWeapon weapon11(1, "Samurai sword[Knight Only]", "Little...", 3, 35, 350,5);
extern SwordWeapon weapon12(1, "Alexander sword[Knight Only]", "Little...", 3, 60, 1200,6);
extern AxeWeapon weapon2(1, "Iron Axe[Orc Only]", "Big...", 4, 20, 150);
extern AxeWeapon weapon7(1, "Steel Axe[Orc Only]", "Big...", 4, 25, 200); 
extern AxeWeapon weapon8(1, "Grand Axe[Orc Only]", "Big...", 4, 40, 400);
extern AxeWeapon weapon9(1, "Bloodthirst Axe[Orc Only]", "Big...", 4, 70, 1500,6);
extern MagicWeapon weapon3(1, "Fire Wand[Magician Only]", "QQ...", 2, 15, 100);
extern MagicWeapon weapon4(1, "Ice Wand[Magician Only]", "Wow...", 2, 20, 150,1);
extern MagicWeapon weapon5(1, "Arch Mage Wand[Magician Only]", "Wow...", 2, 30, 300,5);
extern MagicWeapon weapon6(1, "World-tree's branch[Magician Only]", "Awesome...", 2, 50, 1000, 6);
extern ShieldArmor armor1(1, "Wood Shield[Knight Only]", "Little...", 3, 10, 50);
extern ShieldArmor armor3(1, "Iron Shield[Knight Only]", "Circle...", 3, 20, 150,1);
extern TunicArmor armor2(1, "Tunic", "Big...", 4, 20,100);
extern LifePotion potion1(1, "Life", "Low...", 1, 10,5);
extern LifePotion potion2(1, "Life", "Normal...", 1, 20,15);
extern LifePotion potion4(1, "Eternal potion", "Very Very Rare!!", 1, 10000, 500);
extern MagicPotion potion3(1, "Magicpower", "Low...", 1, 20, 5);
extern MagicPotion potion5(1, "Magicpower", "Normal...", 1, 30, 10);
vector<string>adj{"Cute","Handsome","Evil","Betrayed","Unrestrained"};
vector<string>noun{"Warrior","Warlock","Wizard","Killer","Knight"};
int GeneralPlayer::Cheer=0;
void GeneralPlayer::perentbox(double max, double num,int color)
{
	for (int i = 0; i < 20; i++)
	{
		if (num - max / 20 >= 0)
		{
			SetColor(0, color);
			cout << " ";
			SetColor(color, 0);
			num -= max / 20;
		}
		else
		{
			cout << " ";
		}
	}
}
void GeneralPlayer::SetColor(int f, int b )
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}
int damage_calculate(int attack, int defense)/*-10~10*/
{
	srand(time(NULL));
	int inaccuracy = rand() % 11;/*決定0~10%*/
	int p_n = (rand() % 2) * 2 - 1;/*決定正負(1or-1)*/

	if (attack <= defense)
	{
		return rand() % 2;
	}
	else
	{
		return (attack - defense)*(100 + p_n * inaccuracy) / 100;
	}
}
int stint(string in)
{
	int out = 0;
	if (in[0]=='-')
	{
		for (int i = 1; i < in.size(); i++)
		{
			int temp = in[i] - 48;
			out += temp * pow(10, in.size() - 1 - i);
		}
		out *= -1;
	}
	else
	{
		for (int i = 0; i < in.size(); i++)
		{
			int temp = in[i] - 48;
			out += temp * pow(10, in.size() - 1 - i);
		}
	}
	return out;
}
string isst(int input)
{
	string temp;
	string output;
	while (input >= 10)
	{
		temp.push_back(input % 10 + 48);
		input /= 10;
	}
	temp.push_back(input + 48);
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		output.push_back(temp[i]);
	}
	return output;
}
GeneralPlayer::GeneralPlayer()// default constructor
{
	setName();
	setLevel(1);
	setExp(0);
	setMoney(0);
	recoverHP();
	recoverMP();
}
GeneralPlayer::GeneralPlayer(int Level) // normal constructor
{
	setName();
	setLevel(Level);
	setExp(0);
	setMoney(0);
	recoverHP();
	recoverMP();
}
GeneralPlayer::GeneralPlayer(string Name) // normal constructor
{
	setName(Name);
	setLevel(1);
	setExp(0);
	setMoney(0);
	recoverHP();
	recoverMP();
}
GeneralPlayer::GeneralPlayer(int Level, string Name) // normal constructor
{
	setName(Name);
	setLevel(Level);
	setExp(0);
	setMoney(0);
	recoverHP();
	recoverMP();
}
GeneralPlayer::GeneralPlayer(int Level, int Hp, int Mp, int Exp)
{
	setName();
	setLevel(Level);
	setHp(Hp);
	setMp(Mp);
	setExp(Exp);
	setMoney(0);
}
GeneralPlayer::GeneralPlayer(int Level, int Hp, int Mp, int Exp, string Name)
{
	setName(Name);
	setLevel(Level);
	setHp(Hp);
	setMp(Mp);
	setExp(Exp);
	setMoney(0);
}
GeneralPlayer::GeneralPlayer(const GeneralPlayer&Player)
{
	setName(Player.name);
	setLevel(Player.level);
	setExp(Player.exp);
	setMoney(0);
	recoverHP();
	recoverMP();
}
void GeneralPlayer::setName(string Name)
{
	name = Name;
}
string  GeneralPlayer::getName(void) const
{
	return name;
}
void  GeneralPlayer::setLevel(int Level) // need to call setAttr() inside
{
	if (Level<0)
	{
		cout << "You set a wrong level !";
	}
	else
	{
		level = Level;
		setAttr(level);
		setHp(max_hp);
		setMp(max_mp);
	}
}
int  GeneralPlayer::getLevel(void) const
{
	return level;
}
void  GeneralPlayer::setHp(int Hp)
{
	if (Hp<0)
	{
		cout << "You set a wrong hp !";
	}
	else
	{
		if (Hp>max_hp)
		{
			hp = max_hp;
		}
		else
		{
			hp = Hp;
		}
	}
}
int  GeneralPlayer::getHp(void) const
{
	return hp;
}
void  GeneralPlayer::setMp(int Mp)
{
	if (Mp<0)
	{
		cout << "You set a wrong mp !";
	}
	else
	{
		mp = Mp;
		if (Mp>max_mp)
		{
			mp = max_mp;
		}
		else
		{
			mp = Mp;
		}
	}
}
int  GeneralPlayer::getMp(void) const
{
	return mp;
}
void  GeneralPlayer::setExp(int Exp)
{
	if (Exp<=0)
	{
		Exp=0;
	}
	else
	{
		exp = Exp;
		while (exp >= lvup_exp)
		{
			levelUp();
		}
	}
}
int  GeneralPlayer::getExp(void) const
{
	return exp;
}
void GeneralPlayer::setMoney(int Money)
{
	if (Money<0)
	{
		cout << "Money CAN'T be less than zero !!!";
	}
	else
	{
		money = Money;
	}
}
int GeneralPlayer::getMoney() const
{
	return money;
}
int  GeneralPlayer::getAttack(void) const
{
	return attack;
}
int  GeneralPlayer::getDefense(void) const
{
	return defense;
}
int  GeneralPlayer::getMaxHP(void) const
{
	return max_hp;
}
int  GeneralPlayer::getMaxMP(void) const
{
	return max_mp;
}
int  GeneralPlayer::getLvupExp(void) const
{
	return lvup_exp;
}
void GeneralPlayer::setAttr(int Level) // parameter is level
{
	max_hp = 100 + 10 * Level;
	max_mp = 40 + 5 * Level;
	attack = 20 + 5 * Level + extra_attack;
	defense = 20 + 5 * Level + extra_defense;
	lvup_exp = pow(10,log(Level+1)/log(2));

}
/*cdddddddddddd*/
void GeneralPlayer::levelUp(void) // level++
{
	setLevel(level+1);
}
void GeneralPlayer::increaseHP(int HP)
{
	if (hp+HP>= max_hp)
	{
		hp = max_hp;
	}
	else if (hp + HP<0)
	{
		hp = 0;
	}
	else
	{
		hp = hp + HP;
	}
}
void GeneralPlayer::increaseMP(int MP)
{
	if (mp + MP >= max_mp)
	{
		mp = max_mp;
	}
	else if (mp + MP<0)
	{
		mp = 0;
	}
	else
	{
		mp = mp + MP;
	}
}
void GeneralPlayer::increaseExp(int EXP)
{
	if (exp + EXP>=0)
	{
		exp += EXP;
	}
	while (exp >= lvup_exp)
	{
		levelUp();
	}
}
void GeneralPlayer::get_rand()
{
	srand(time(NULL));
	int aa = rand() % 100;
	if (aa==1)
	{
		Sword_Weapon[1]->get=1; // weapon item
	}
	if (aa == 2)
	{
		Axe_Weapon[1]->get = 1; // weapon item
	}
	if (aa == 3)
	{
		Magic_Weapon[1]->get = 1; // weapon item
	}
	if (aa == 4)
	{
		Shield_Armor[1]->get = 1; // weapon item
	}
	if (aa == 5)
	{
		Tunic_Armor[1]->get = 1; // weapon item
	}
	if (aa == 6)
	{
		Life_Potion[1]->number += 1; // weapon item
	}
	if (aa == 7)
	{
		Magic_Potion[1]->number += 1; // weapon item
	}
}
void GeneralPlayer::recoverHP(void) // hp = max_hp;
{
	hp = max_hp;
}
void GeneralPlayer::recoverMP(void) // mp = max_mp;
{
	mp = max_mp;
}
int GeneralPlayer::specialSkill(vector<AbstractMonster*>monster)
{
	return 1;
}
int GeneralPlayer::attackTo(AbstractMonster*monster)
{
	if (hp==0)
	{
		cout << "The Player HAD died !!";
	}
	else
	{
		if (monster->getHP() == 0)
		{
			cout << "You CAN'T hit the dead body!!";
		}
		else
		{
			cout << name << " attack to " << monster->name << endl;
			int Damage = damage_calculate(attack+Anger+Cheer, monster->defense);
			if (monster->getHP() <= Damage)
			{
				monster->setHP(0);
				increaseExp(monster->exp);
				setMoney(money+monster->money);
			}
			else
			{
				monster->setHP(monster->getHP() - Damage);
			}
			return 1;
		}
		Anger = 0;
		Cheer = 0;
	}
	return 0;
}
int GeneralPlayer::attackToAll(vector<AbstractMonster*>monster)
{
	for (int i = 0; i < monster.size(); i++)
	{
		if (hp == 0)
		{
			cout << "The Player HAD died !!";
		}
		else
		{
			if (monster[i]->getHP() == 0)
			{
				cout << "You CAN'T hit the dead body!!";
			}
			else
			{
				cout << name << " attack to " << monster[i]->name << endl;
				int Damage = damage_calculate(attack + Anger + Cheer, monster[i]->defense);
				if (monster[i]->getHP() <= Damage)
				{
					monster[i]->setHP(0);
					increaseExp(monster[i]->exp);
					setMoney(money + monster[i]->money);
				}
				else
				{
					monster[i]->setHP(monster[i]->getHP() - Damage);
				}
			}
			Anger = 0;
			Cheer = 0;
		}
	}
	return 1;
}
void GeneralPlayer::status()
{
	cout << race << "-" << name << " (Lv." << level<<")" << endl;
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}
void GeneralPlayer::status_pic()
{
	cout << race << "-" << name << " (Lv." << level << ")" << endl;
	cout << "Hp:" << hp << "/" << max_hp << endl;
	cout << "Mp:" << mp << "/" << max_mp << endl;
	cout << "Exp:" << exp << "/" << lvup_exp << endl;
	cout << "Attack/Defense:" << attack << "/" << defense << endl;
}
string GeneralPlayer::serialize() const
{
	string serialize;
	serialize += "$race:" + race;
	serialize += "$name:" + name;
	serialize += "$hp:" + to_string(hp);
	serialize += "$mp:" + to_string(mp);
	serialize += "$exp:" + to_string(exp);
	serialize += "$level:" + to_string(level);
	serialize += "$attack:" + to_string(attack);
	serialize += "$defense:" + to_string(defense);
	serialize += "$max_hp:" + to_string(max_hp);
	serialize += "$max_mp:" + to_string(max_mp);
	serialize += "$lvup_exp:" + to_string(lvup_exp);
	serialize += "$money:" + to_string(money);
	return serialize;
}
void GeneralPlayer::unserialize(string data)
{
	string temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i]=='$')
		{
			string type;
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[j]==':')
				{
					string value;
					for (int k = j+1; k < temp.size(); k++)
					{
						value += temp[k];
					}
					if (type=="race")
					{
						race = value;
					}
					else if (type == "name")
					{
						name = value;
					}
					else if (type == "hp")
					{
						hp=stoi(value);
					}
					else if (type == "mp")
					{
						mp=stoi(value);
					}
					else if (type == "exp")
					{
						exp=stoi(value);
					}
					else if (type == "level")
					{
						level=stoi(value);
					}
					else if (type == "attack")
					{
						attack=stoi(value);
					}
					else if (type == "defense")
					{
						defense=stoi(value);
					}
					else if (type == "max_hp")
					{
						max_hp=stoi(value);
					}
					else if (type == "max_mp")
					{
						max_mp=stoi(value);
					}
					else if (type == "lvup_exp")
					{
						lvup_exp=stoi(value);
					}
					else if (type == "money")
					{
						money=stoi(value);
					}
				}
				else
				{
					type.push_back(temp[j]);
				}
			}
			temp.clear();
		}
		else
		{
			temp.push_back(data[i]);
		}
	}
}
void GeneralPlayer::backpack_setup()
{
	backpack_put(&weapon1);
	backpack_put(&weapon2);
	backpack_put(&weapon3);
	backpack_put(&weapon4);
	backpack_put(&weapon5);
	backpack_put(&weapon6);
	backpack_put(&weapon7);
	backpack_put(&weapon8);
	backpack_put(&weapon9);
	backpack_put(&weapon10);
	backpack_put(&weapon11);
	backpack_put(&weapon12);
	backpack_put(&armor1);
	backpack_put(&armor2);
	backpack_put(&armor3);
	potion1.set_num(5);
	backpack_put(&potion1);
	backpack_put(&potion2);
	backpack_put(&potion3);
	backpack_put(&potion4);
	backpack_put(&potion5);
}
bool GeneralPlayer::backpack_oversize(Item* item)
{
	if (backpack_weight+ item->weight>backpack_weight_limit)
	{
		return 1;
	}
	if(backpack_slot_limit<= Sword_Weapon.size() + Axe_Weapon.size() + Shield_Armor.size() + Tunic_Armor.size() + Life_Potion.size() + Magic_Potion.size())
	{
		return 1;
	}
	return 0;
}
void GeneralPlayer::backpack_put(SwordWeapon* item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Sword_Weapon.push_back(item);
	}
}
void GeneralPlayer::backpack_put(AxeWeapon*item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Axe_Weapon.push_back(item);
	}
}
void GeneralPlayer::backpack_put(MagicWeapon*item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Magic_Weapon.push_back(item);
	}
}
void GeneralPlayer::backpack_put(ShieldArmor*item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Shield_Armor.push_back(item);
	}
}
void GeneralPlayer::backpack_put(TunicArmor*item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Tunic_Armor.push_back(item);
	}
}
void GeneralPlayer::backpack_put(LifePotion*item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Life_Potion.push_back(item);
	}
}
void GeneralPlayer::backpack_put(MagicPotion*item)
{
	if (!backpack_oversize((Item*)item))
	{
		backpack_weight += item->weight;
		Magic_Potion.push_back(item);
	}
}
void GeneralPlayer::backpack_status()
{
	system("cls");
	cout << "|||Weapon|||" << endl;
	for (int i = 0; i < Sword_Weapon.size(); i++)
	{
		cout << Sword_Weapon[i]->Type <<"-" << Sword_Weapon[i]->name << endl;
		cout << Sword_Weapon[i]->description << endl;
		cout << "Weight:" << Sword_Weapon[i]->weight << endl;
		cout << "Level:" << Sword_Weapon[i]->level_required << endl;
	}
	for (int i = 0; i < Axe_Weapon.size(); i++)
	{
		cout << Axe_Weapon[i]->Type << "-" << Axe_Weapon[i]->name << endl;
		cout << Axe_Weapon[i]->description << endl;
		cout << "Weight:" << Axe_Weapon[i]->weight << endl;
		cout << "Level:" << Axe_Weapon[i]->level_required << endl;
	}
	for (int i = 0; i < Magic_Weapon.size(); i++)
	{
		cout << Magic_Weapon[i]->Type << "-" << Magic_Weapon[i]->name << endl;
		cout << Magic_Weapon[i]->description << endl;
		cout << "Weight:" << Magic_Weapon[i]->weight << endl;
		cout << "Level:" << Magic_Weapon[i]->level_required << endl;
	}
	cout << "|||Armor|||" << endl;
	for (int i = 0; i < Shield_Armor.size(); i++)
	{
		cout << Shield_Armor[i]->Type << "-" << Shield_Armor[i]->name << endl;
		cout << Shield_Armor[i]->description << endl;
		cout << "Weight:" << Shield_Armor[i]->weight << endl;
		cout << "Level:" << Shield_Armor[i]->level_required << endl;
	}
	for (int i = 0; i < Tunic_Armor.size(); i++)
	{
		cout << Tunic_Armor[i]->Type << "-" << Tunic_Armor[i]->name << endl;
		cout << Tunic_Armor[i]->description << endl;
		cout << "Weight:" << Tunic_Armor[i]->weight << endl;
		cout << "Level:" << Tunic_Armor[i]->level_required << endl;
	}
	cout << "|||Consume|||" << endl;
	for (int i = 0; i < Life_Potion.size(); i++)
	{
		cout << Life_Potion[i]->Type << "-" << Life_Potion[i]->name << endl;
		cout << Life_Potion[i]->description << endl;
		cout << "Weight:" << Life_Potion[i]->weight << endl;
		cout << "Level:" << Life_Potion[i]->level_required << endl;
		cout << "Number:" << Life_Potion[i]->number << endl;
	}
	for (int i = 0; i < Magic_Potion.size(); i++)
	{
		cout << Magic_Potion[i]->Type << "-" << Magic_Potion[i]->name << endl;
		cout << Magic_Potion[i]->description << endl;
		cout << "Weight:" << Magic_Potion[i]->weight << endl;
		cout << "Level:" << Magic_Potion[i]->level_required << endl;
		cout << "Number:" << Magic_Potion[i]->number << endl;
	}
}
bool GeneralPlayer::fit_up(SwordWeapon* equip)
{
	if (Sword_Weapon_equip ==NULL && race == "Knight" && ((SwordWeapon*)equip)->get == 1)
	{
		Sword_Weapon_equip =equip;
		extra_attack += equip->attack_increment;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::fit_up(AxeWeapon*equip)
{
	if (Axe_Weapon_equip == NULL && race == "Orc" && ((AxeWeapon*)equip)->get == 1)
	{
		Axe_Weapon_equip = equip;
		extra_attack += equip->attack_increment;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::fit_up(MagicWeapon*equip)
{
	if (Magic_Weapon_equip == NULL&&race=="Magic"&&((MagicWeapon*)equip)->get == 1)
	{
		Magic_Weapon_equip = equip;
		extra_attack += equip->attack_increment;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::fit_up(ShieldArmor*equip)
{
	if (Shield_Armor_equip == NULL && race == "Knight"&& ((ShieldArmor*)equip)->get == 1)
	{
		Shield_Armor_equip = equip;
		extra_attack += equip->defense_increment;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::fit_up(TunicArmor*equip)
{
	if (Tunic_Armor_equip == NULL && ((TunicArmor*)equip)->get == 1)
	{
		Tunic_Armor_equip = equip;
		extra_attack += equip->defense_increment;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::put_off(SwordWeapon* equip)
{
	if (Sword_Weapon_equip != NULL)
	{
		Sword_Weapon_equip = NULL;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::put_off(AxeWeapon*equip)
{
	if (Axe_Weapon_equip != NULL)
	{
		Axe_Weapon_equip = NULL;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::put_off(MagicWeapon*equip)
{
	if (Magic_Weapon_equip != NULL)
	{
		Magic_Weapon_equip = NULL;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::put_off(ShieldArmor*equip)
{
	if (Shield_Armor_equip != NULL)
	{
		Shield_Armor_equip = NULL;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::put_off(TunicArmor*equip)
{
	if (Tunic_Armor_equip != NULL)
	{
		Tunic_Armor_equip = NULL;
		setAttr(level);
		return 1;
	}
	return 0;
}
bool GeneralPlayer::use(LifePotion*Potion)
{
	if (Potion->number>0)
	{
		setHp(getHp() + Potion->hp_recover);
		setMp(getMp() + Potion->mp_recover);
		Potion->number--;

		return 1;
	}
	return 0;
}
bool GeneralPlayer::use(MagicPotion*Potion)
{
	if (Potion->number>0)
	{
		setHp(getHp() + Potion->hp_recover);
		setMp(getMp() + Potion->mp_recover);
		Potion->number--;
		return 1;
	}
	return 0;
}
void GeneralPlayer::buy_weapon()
{
	int choose = 0;
	int state = 0;
	int state_item = 0;
	while (1)
	{
		system("cls");
		cout << "|||Weapon|||" << endl;
		for (int i = 0; i < Sword_Weapon.size(); i++)
		{
			if (choose == i)
			{
				cout << "->";
				Item_point = Sword_Weapon[i];
				Item_point_type = 'a';
			}
			if (Sword_Weapon[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Sword_Weapon[i]->item_state, 0);
			}
			cout << Sword_Weapon[i]->Type << "-" << Sword_Weapon[i]->name << "(" << Sword_Weapon[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		for (int i = 0; i < Axe_Weapon.size(); i++)
		{
			if (choose == i + Sword_Weapon.size())
			{
				cout << "->";
				Item_point = Axe_Weapon[i];
				Item_point_type = 'b';
			}
			if (Axe_Weapon[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Axe_Weapon[i]->item_state, 0);
			}
			cout << Axe_Weapon[i]->Type << "-" << Axe_Weapon[i]->name << "(" << Axe_Weapon[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		for (int i = 0; i < Magic_Weapon.size(); i++)
		{
			if (choose == i + Sword_Weapon.size() + Axe_Weapon.size())
			{
				cout << "->";
				Item_point = Magic_Weapon[i];
				Item_point_type = 'b';
			}
			if (Magic_Weapon[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Magic_Weapon[i]->item_state, 0);
			}
			cout << Magic_Weapon[i]->Type << "-" << Magic_Weapon[i]->name << "(" << Magic_Weapon[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		char aa = _getch();
		if (aa == 'a')
		{
			break;
		}
		if (aa == 's')
		{
			choose++;
			if (choose>= Sword_Weapon.size()+ Axe_Weapon.size() + Magic_Weapon.size())
			{
				choose = 0;
			}
		}
		if (aa == 'w')
		{
			choose--;
			if (choose <0)
			{
				choose = Sword_Weapon.size() + Axe_Weapon.size() + Magic_Weapon.size() - 1;
			}
		}
		int buy_c = 0;
		if (aa == 'd')
		{
			system("cls");
			cout << "Do you want to buy this ?(Y/N)";
			while (1)
			{
				char bb = _getch();
				if (bb == 'y')
				{
					if (choose<Sword_Weapon.size())
					{
						if (money>= Sword_Weapon[choose]->price&&Sword_Weapon[choose]->get==0)
						{
							Sword_Weapon[choose]->get = 1;
							money -= Sword_Weapon[choose]->price;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
					else if (choose>=Sword_Weapon.size()&& choose < Sword_Weapon.size()+ Axe_Weapon.size())
					{
						choose -= Sword_Weapon.size();
						if (money >= Axe_Weapon[choose]->price&&Axe_Weapon[choose]->get == 0)
						{
							Axe_Weapon[choose]->get = 1;
							money -= Axe_Weapon[choose]->price;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
					else
					{
						choose -= Sword_Weapon.size() + Axe_Weapon.size();
						if (money >= Magic_Weapon[choose]->price&&Magic_Weapon[choose]->get == 0)
						{
							Magic_Weapon[choose]->get = 1;
							money -= Magic_Weapon[choose]->price;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
				}
				if (bb == 'a')
				{
					break;
				}
				if (bb == 'n')
				{
					break;
				}
			}
		}
	}
}
void GeneralPlayer::buy_armor()
{
	int choose = 0;
	int state = 0;
	int state_item = 0;
	while (1)
	{
		system("cls");
		cout << "|||Armor|||" << endl;
		for (int i = 0; i < Shield_Armor.size(); i++)
		{
			if (choose == i)
			{
				cout << "->";
				Item_point = Shield_Armor[i];
				Item_point_type = 'a';
			}
			if (Shield_Armor[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Shield_Armor[i]->item_state, 0);
			}
			cout << Shield_Armor[i]->Type << "-" << Shield_Armor[i]->name << "(" << Shield_Armor[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		for (int i = 0; i < Tunic_Armor.size(); i++)
		{
			if (choose == i + Shield_Armor.size())
			{
				cout << "->";
				Item_point = Tunic_Armor[i];
				Item_point_type = 'b';
			}
			if (Tunic_Armor[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Tunic_Armor[i]->item_state, 0);
			}
			cout << Tunic_Armor[i]->Type << "-" << Tunic_Armor[i]->name << "(" << Tunic_Armor[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		char aa = _getch();
		if (aa == 'a')
		{
			break;
		}
		if (aa == 's')
		{
			choose++;
			if (choose >= Shield_Armor.size() + Tunic_Armor.size())
			{
				choose = 0;
			}
		}
		if (aa == 'w')
		{
			choose--;
			if (choose <0)
			{
				choose = Shield_Armor.size() + Tunic_Armor.size() - 1;
			}
		}
		int buy_c = 0;
		if (aa == 'd')
		{
			system("cls");
			cout << "Do you want to buy this ?(Y/N)";
			while (1)
			{
				char bb = _getch();
				if (bb == 'y')
				{
					if (choose<Shield_Armor.size())
					{
						if (money >= Shield_Armor[choose]->price&&Shield_Armor[choose]->get == 0)
						{
							Shield_Armor[choose]->get = 1;
							money -= Shield_Armor[choose]->price;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
					else
					{
						choose -= Shield_Armor.size();
						if (money >= Tunic_Armor[choose]->price&&Tunic_Armor[choose]->get == 0)
						{
							Tunic_Armor[choose]->get = 1;
							money -= Tunic_Armor[choose]->price;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
				}
				if (bb == 'a')
				{
					break;
				}
				if (bb == 'n')
				{
					break;
				}
			}
		}
	}
}
void GeneralPlayer::buy_potion()
{
	int choose = 0;
	int state = 0;
	int state_item = 0;
	while (1)
	{
		system("cls");
		cout << "|||Potion|||" << endl;
		for (int i = 0; i < Life_Potion.size(); i++)
		{
			if (choose == i)
			{
				cout << "->";
				Item_point = Life_Potion[i];
				Item_point_type = 'a';
			}
			if (Life_Potion[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Life_Potion[i]->item_state, 0);
			}
			cout << Life_Potion[i]->Type << "-" << Life_Potion[i]->name << "(" << Life_Potion[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		for (int i = 0; i < Magic_Potion.size(); i++)
		{
			if (choose == i + Life_Potion.size())
			{
				cout << "->";
				Item_point = Magic_Potion[i];
				Item_point_type = 'b';
			}
			if (Magic_Potion[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Magic_Potion[i]->item_state, 0);
			}
			cout << Magic_Potion[i]->Type << "-" << Magic_Potion[i]->name << "(" << Magic_Potion[i]->description << ")";
			cout << endl;
			SetColor(7, 0);
		}
		char aa = _getch();
		if (aa == 'a')
		{
			break;
		}
		if (aa == 's')
		{
			choose++;
			if (choose >= Life_Potion.size() + Magic_Potion.size())
			{
				choose = 0;
			}
		}
		if (aa == 'w')
		{
			choose--;
			if (choose <0)
			{
				choose = Life_Potion.size() + Magic_Potion.size() - 1;
			}
		}
		int buy_c = 0;
		if (aa == 'd')
		{
			system("cls");
			cout << "Do you want to buy this ?(Y/N)";
			while (1)
			{
				char bb = _getch();
				if (bb == 'y')
				{
					if (choose<Life_Potion.size())
					{
						int num=-1;
						cout << endl << "Number?";
						while (num<=0)
						{
							cin >> num;
						}
						if (money >= Life_Potion[choose]->price*num&&Life_Potion[choose]->get == 0)
						{
							Life_Potion[choose]->get = 1;
							Life_Potion[choose]->number += num;
							money -= Life_Potion[choose]->price*num;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
					else
					{
						choose -= Life_Potion.size();
						int num = -1;
						cout << endl << "Number?";
						while (num <= 0)
						{
							cin >> num;
						}
						if (money >= Magic_Potion[choose]->price*num&&Magic_Potion[choose]->get == 0)
						{
							Magic_Potion[choose]->get = 1;
							Magic_Potion[choose]->number += num;
							money -= Magic_Potion[choose]->price*num;
							cout << "You buy this item !";
							system("pause");
							break;
						}
						else
						{
							cout << "You can't buy this item !";
							system("pause");
							break;
						}
					}
				}
				if (bb == 'a')
				{
					break;
				}
				if (bb == 'n')
				{
					break;
				}
			}
		}
	}
}
int GeneralPlayer::equip(vector<GeneralPlayer*>players, int choose,int state,int state_item)
{
	system("cls");
	if (state==0)
	{
		if (choose == 999)
		{
			choose = Sword_Weapon.size() + Axe_Weapon.size() + Magic_Weapon.size() + Shield_Armor.size() + Tunic_Armor.size() + Life_Potion.size()+Magic_Potion.size()-1;
		}
		cout << "|||Weapon|||" << endl;
		for (int i = 0; i < Sword_Weapon.size(); i++)
		{
			if (choose == i)
			{
				cout << "->";
				Item_point = Sword_Weapon[i];
				Item_point_type = 'a';
			}
			if (Sword_Weapon[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Sword_Weapon[i]->item_state, 0);
			}
			cout << Sword_Weapon[i]->Type << "-" << Sword_Weapon[i]->name << "(" << Sword_Weapon[i]->description << ")";
			if (Sword_Weapon[i]->owner != -1)
			{
				cout <<"  Owner:"<<players[Sword_Weapon[i]->owner]->name;
			}
			cout<< endl;
			SetColor(7, 0);
		}
		for (int i = 0; i < Axe_Weapon.size(); i++)
		{
			if (choose == i + Sword_Weapon.size())
			{
				cout << "->";
				Item_point = Axe_Weapon[i];
				Item_point_type = 'b';
			}
			if (Axe_Weapon[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Axe_Weapon[i]->item_state, 0);
			}
			cout << Axe_Weapon[i]->Type << "-" << Axe_Weapon[i]->name << "(" << Axe_Weapon[i]->description << ")" ;
			if (Axe_Weapon[i]->owner != -1)
			{
				cout << "  Owner:" << players[Axe_Weapon[i]->owner]->name;
			}
			cout << endl;
			SetColor();
		}
		for (int i = 0; i < Magic_Weapon.size(); i++)
		{
			if (choose == i + Sword_Weapon.size()+Axe_Weapon.size())
			{
				cout << "->";
				Item_point = Magic_Weapon[i];
				Item_point_type = 'm';
			}
			if (Magic_Weapon[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Magic_Weapon[i]->item_state, 0);
			}
			cout << Magic_Weapon[i]->Type << "-" << Magic_Weapon[i]->name << "(" << Magic_Weapon[i]->description << ")";
			if (Magic_Weapon[i]->owner != -1)
			{
				cout << "  Owner:" << players[Magic_Weapon[i]->owner]->name;
			}
			cout << endl;
			SetColor();
		}
		cout << "|||Armor|||" << endl;
		for (int i = 0; i < Shield_Armor.size(); i++)
		{
			if (choose == i + Sword_Weapon.size() + Axe_Weapon.size()+Magic_Weapon.size())
			{
				cout << "->";
				Item_point = Shield_Armor[i];
				Item_point_type = 'c';
			}
			if (Shield_Armor[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Shield_Armor[i]->item_state, 0);
			}
			cout << Shield_Armor[i]->Type << "-" << Shield_Armor[i]->name << "(" << Shield_Armor[i]->description << ")" ;
			if (Shield_Armor[i]->owner != -1)
			{
				cout << "  Owner:" << players[Shield_Armor[i]->owner]->name;
			}
			cout << endl;
			SetColor(7,0);
		}
		for (int i = 0; i < Tunic_Armor.size(); i++)
		{
			if (choose == i + Sword_Weapon.size() + Axe_Weapon.size()+Magic_Weapon.size() + Shield_Armor.size())
			{
				cout << "->";
				Item_point = Tunic_Armor[i];
				Item_point_type = 'd';
			}
			if (Tunic_Armor[i]->get == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Tunic_Armor[i]->item_state, 0);
			}
			cout << Tunic_Armor[i]->Type << "-" << Tunic_Armor[i]->name << "(" << Tunic_Armor[i]->description << ")";
			if (Tunic_Armor[i]->owner != -1)
			{
				cout << "  Owner:" << players[Tunic_Armor[i]->owner]->name;
			}
			cout << endl;
			SetColor();
		}
		cout << "|||Consume|||" << endl;
		for (int i = 0; i < Life_Potion.size(); i++)
		{
			if (choose == i + Sword_Weapon.size() + Axe_Weapon.size()+Magic_Weapon.size() + Shield_Armor.size() + Tunic_Armor.size())
			{
				cout << "->";
				Item_point = Life_Potion[i];
				Item_point_type = 'e';
			}
			if (Life_Potion[i]->number == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Life_Potion[i]->item_state, 0);
			}
			cout << Life_Potion[i]->Type << "-" << Life_Potion[i]->name << "(" << Life_Potion[i]->description << ")" << " Number:" << Life_Potion[i]->number << endl;
			SetColor();
		}
		for (int i = 0; i < Magic_Potion.size(); i++)
		{
			if (choose == i + Sword_Weapon.size() + Axe_Weapon.size()+Magic_Weapon.size() + Shield_Armor.size() + Tunic_Armor.size() + Life_Potion.size())
			{
				cout << "->";
				Item_point = Magic_Potion[i];
				Item_point_type = 'f';
			}
			if (Magic_Potion[i]->number == 0)
			{
				SetColor(8, 0);
			}
			else
			{
				SetColor(Magic_Potion[i]->item_state, 0);
			}
			cout << Magic_Potion[i]->Type << "-" << Magic_Potion[i]->name << "(" << Magic_Potion[i]->description << ")"<<" Number:"<< Magic_Potion[i]->number << endl;
			SetColor(7, 0);
		}
		if (choose ==  Sword_Weapon.size() + Axe_Weapon.size()+Magic_Weapon.size() + Shield_Armor.size() + Tunic_Armor.size() + Life_Potion.size() + Magic_Potion.size())
		{
			return-1;
		}
		else
		{
			return choose;
		}
	}
	else if (state == 2)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (state_item == i)
			{
				cout << "->";
			}
			cout <<players[i]->name<<endl;
		}
		return state_item;
	}
	else if (state == 3)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (state_item == i)
			{
				cout << "->";
			}
			cout << players[i]->name << endl;
		}
		return state_item;
	}
	else if (state == 4)
	{
		if (Item_point_type=='a')
		{
			if (players[state_item]->fit_up((SwordWeapon*)Item_point)&&Item_point->owner==-1 && Item_point->get == 1)
			{
				Item_point->owner = state_item;
			}
			else
			{
				cout << "You Can't Fit Up the Equipment !!";
				Sleep(500);
			}
		}
		if (Item_point_type == 'b')
		{
			if (players[state_item]->fit_up((AxeWeapon*)Item_point) && Item_point->owner == -1 && Item_point->get == 1)
			{
				Item_point->owner = state_item;
			}
			else
			{
				cout << "You Can't Fit Up the Equipment !!";
				Sleep(500);
			}
		}
		if (Item_point_type == 'm')
		{
			if (players[state_item]->fit_up((MagicWeapon*)Item_point) && Item_point->owner == -1 && Item_point->get == 1)
			{
				Item_point->owner = state_item;
			}
			else
			{
				cout << "You Can't Fit Up the Equipment !!";
				Sleep(500);
			}
		}
		if (Item_point_type == 'c')
		{
			if (players[state_item]->fit_up((ShieldArmor*)Item_point) && Item_point->owner == -1)
			{
				Item_point->owner = state_item;
			}
			else
			{
				cout << "You Can't Fit Up the Equipment !!";
				Sleep(500);
			}
		}
		if (Item_point_type == 'd')
		{
			if (players[state_item]->fit_up((TunicArmor*)Item_point) && Item_point->owner == -1 && Item_point->get == 1)
			{
				Item_point->owner = state_item;
			}
			else
			{
				cout << "You Can't Fit Up the Equipment !!";
				Sleep(500);
			}
		}
		if (Item_point_type == 'e')
		{
			if (!(players[state_item]->use((LifePotion*)Item_point)))
			{
				cout << "Error";
				Sleep(500);
			}
		}
		if (Item_point_type == 'f')
		{
			if (!(players[state_item]->use((MagicPotion*)Item_point)))
			{
				cout << "Error";
				Sleep(500);
			}
		}
		return state_item;
	}
	else if (state == 5)
	{
		if (Item_point_type == 'a')
		{
			if (players[state_item]->put_off((SwordWeapon*)Item_point) && Item_point->owner != -1)
			{
				Item_point->owner = -1;
			}
		}
		if (Item_point_type == 'b')
		{
			if (players[state_item]->put_off((AxeWeapon*)Item_point) && Item_point->owner != -1)
			{
				Item_point->owner = -1;
			}
		}
		if (Item_point_type == 'm')
		{
			if (players[state_item]->put_off((MagicWeapon*)Item_point) && Item_point->owner != -1)
			{
				Item_point->owner = -1;
			}
		}
		if (Item_point_type == 'c')
		{
			if (players[state_item]->put_off((ShieldArmor*)Item_point) && Item_point->owner != -1)
			{
				Item_point->owner = -1;
			}
		}
		if (Item_point_type == 'd')
		{
			if (players[state_item]->put_off((TunicArmor*)Item_point) && Item_point->owner != -1)
			{
				Item_point->owner = -1;
			}
		}
		if (Item_point_type == 'e')
		{
		}
		if (Item_point_type == 'f')
		{
		}
		return state_item;
	}
}
void GeneralPlayer::Save(fstream&file)
{
	for (int i = 0; i < Sword_Weapon.size(); i++)
	{
		file << Sword_Weapon[i]->get << endl;
		file << Sword_Weapon[i]->owner << endl;
	}
	for (int i = 0; i < Axe_Weapon.size(); i++)
	{
		file << Axe_Weapon[i]->get << endl;
		file << Axe_Weapon[i]->owner << endl;
	}
	for (int i = 0; i < Magic_Weapon.size(); i++)
	{
		file << Magic_Weapon[i]->get << endl;
		file << Magic_Weapon[i]->owner << endl;
	}
	for (int i = 0; i < Shield_Armor.size(); i++)
	{
		file << Shield_Armor[i]->get << endl;
		file << Shield_Armor[i]->owner << endl;
	}
	for (int i = 0; i < Tunic_Armor.size(); i++)
	{
		file << Tunic_Armor[i]->get << endl;
		file << Tunic_Armor[i]->owner << endl;
	}
	for (int i = 0; i < Life_Potion.size(); i++)
	{
		file << Life_Potion[i]->number << endl;
	}
	for (int i = 0; i < Magic_Potion.size(); i++)
	{
		file << Magic_Potion[i]->number << endl;
	}
}
void GeneralPlayer::Load(fstream&file)
{
	for (int i = 0; i < Sword_Weapon.size(); i++)
	{
		string temp;
		getline(file,temp);
		Sword_Weapon[i]->get = stint(temp);
	}
	for (int i = 0; i < Sword_Weapon.size(); i++)
	{
		string temp;
		getline(file, temp);
		Sword_Weapon[i]->owner = stint(temp);
	}
	for (int i = 0; i < Axe_Weapon.size(); i++)
	{
		string temp;
		getline(file, temp);
		Axe_Weapon[i]->get = stint(temp);
	}
	for (int i = 0; i < Axe_Weapon.size(); i++)
	{
		string temp;
		getline(file, temp);
		Axe_Weapon[i]->owner = stint(temp);
	}
	for (int i = 0; i < Magic_Weapon.size(); i++)
	{
		string temp;
		getline(file, temp);
		Magic_Weapon[i]->get = stint(temp);
	}
	for (int i = 0; i < Magic_Weapon.size(); i++)
	{
		string temp;
		getline(file, temp);
		Magic_Weapon[i]->owner = stint(temp);
	}
	for (int i = 0; i < Shield_Armor.size(); i++)
	{
		string temp;
		getline(file, temp);
		Shield_Armor[i]->get = stint(temp);
	}
	for (int i = 0; i < Shield_Armor.size(); i++)
	{
		string temp;
		getline(file, temp);
		Shield_Armor[i]->owner = stint(temp);
	}
	for (int i = 0; i < Tunic_Armor.size(); i++)
	{
		string temp;
		getline(file, temp);
		Tunic_Armor[i]->get = stint(temp);
	}
	for (int i = 0; i < Tunic_Armor.size(); i++)
	{
		string temp;
		getline(file, temp);
		Tunic_Armor[i]->owner = stint(temp);
	}
	for (int i = 0; i < Life_Potion.size(); i++)
	{
		string temp;
		getline(file, temp);
		Life_Potion[i]->number = stint(temp);
	}
	for (int i = 0; i < Magic_Potion.size(); i++)
	{
		string temp;
		getline(file, temp);
		Magic_Potion[i]->number = stint(temp);
	}
}