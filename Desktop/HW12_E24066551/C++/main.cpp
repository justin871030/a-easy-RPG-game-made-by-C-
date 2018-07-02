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
	/*cout << "用W,S,A,D操控角色位置,按空白鍵可檢視功能鍵"<<endl;*/
	/*cout << "      ◢◣◢◢◣" << endl;
	cout << "    ◢█████◣" << endl;
	cout << "   ◢█◥██◥█◣  " << endl;
	cout << "    ◥  ●◥  ●◤    " << endl;
	cout << "      \\        /    " << endl;
	cout << "       ＼＿＿／  " << endl;
	cout << "      ◢◣             " << endl;
	cout << "◥◣◢██◣           " << endl;
	cout << "  ◥◤◢██◣         " << endl;
	cout << "    ◢█████◣     " << endl;
	cout << " ◢██◥██◥██◣  " << endl;
	cout << "     |  ●'    ●|     " << endl;
	cout << "     \\           /    " << endl;
	cout << "    ◥█████◤     " << endl;
	cout << "      ◣      ◢       " << endl;
	cout << "      █◣  ◢█       " << endl;
	cout << "    ◢█████◣     " << endl;
	cout << "    ██◥██◥█     " << endl;
	cout << "    █  ●'  ● █     " << endl;
	cout << "    ◥     人   ◤     " << endl;
	cout << "      ◥███◤       " << endl;*/

	vector<string> map_address{{"maze1.txt"}, { "maze2.txt" },{ "maze3.txt" } ,{ "maze4.txt" } ,{ "maze5.txt" } ,{ "maze6.txt" },{ "maze7.txt" },{ "maze8.txt" } ,{ "maze9.txt" },{ "maze10.txt" },{ "maze11.txt" } ,{ "maze12.txt" } };
	System aa(map_address);
	aa.run();
}