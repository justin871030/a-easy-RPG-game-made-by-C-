#include"GeneralPlayer.h"
#include"AbstractMonster.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Battle.h"
#include"Field.h"
#include"system.h"
int main()
{
	cout << "��W,S,A,D�ޱ������m,���ť���i�˵��\����"<<endl;
	/*system("pause");*/
	vector<string> map_address{{"maze1.txt"}, { "maze2.txt" },{ "maze3.txt" } ,{ "maze4.txt" } ,{ "maze5.txt" } ,{ "maze6.txt" },{ "maze7.txt" },{ "maze8.txt" } };
	System aa(map_address);
	aa.SFML();
	system("pause");
}