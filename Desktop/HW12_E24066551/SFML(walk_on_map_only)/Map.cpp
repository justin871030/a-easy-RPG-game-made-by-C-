#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
#include<math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include"Map.h"
using namespace std;
#define POINT "��";
#define ADD "��";
#define WALL "�i";
#define ROAD "��";
#define RIGHT "��";
#define LEFT "��";
#define UP "��";
#define DOWN "��";
int** Map::pointer_2D()
{
	int** pointer;
	pointer = new int*[info.size()];
	for (int i = 0; i < info.size(); i++)
	{
		pointer[i] = new int[info[i].size()];
		for (int j = 0; j < info[i].size(); j++)
		{
			pointer[i][j] = info[i][j];
		}
	}
	return pointer;
}
int strnum(string a)/*str��int*/
{
	int store = 0;
	for (int i = 0; i < a.size(); i++)
	{
		store += (a[i] - 48) *pow(10, a.size() - i - 1);
	}
	return store;
}
Map::Map(string a)
{
	/*���function���bŪ?*/
	dataname = a;
	fstream Mapdata;
    Mapdata.open(dataname, ios::in);/*Ū��*/
	if (Mapdata)
	{
		string rulecheck;/*�s�Ĥ@���T*/
		string temp;
		vector<int> rule(0);
		getline(Mapdata, rulecheck);
		if (!isdigit(rulecheck[0]))
		{
			cout << "Check your data name!";
		}
		else
		{
			for (int i = 0; i < rulecheck.size(); i++)
			{
				if (rulecheck[i] == ',')
				{
					rule.push_back(strnum(temp));
					temp.resize(0);
				}
				else if (i == rulecheck.size() - 1)
				{
					temp.push_back(rulecheck[i]);
					rule.push_back(strnum(temp));
					temp.resize(0);
				}
				else
				{
					temp.push_back(rulecheck[i]);
				}
			}
			vector<vector<int>> Mapvec(rule[1], vector<int>(0));
			for (int j = 0; j < rule[1]; j++)
			{
				getline(Mapdata, temp);
				string tempp;
				for (int i = 0; i < temp.size(); i++)
				{
					if (temp[i] == ',')
					{
						Mapvec[j].push_back(strnum(tempp));
						tempp.resize(0);
					}
					else if (i == temp.size() - 1)
					{
						tempp.push_back(temp[i]);
						Mapvec[j].push_back(strnum(tempp));
						tempp.resize(0);
					}
					else
					{
						tempp.push_back(temp[i]);
					}
				}
			}
			for (int i = 0; i < Mapvec.size(); i++)
			{
				for (int j = 0; j < Mapvec[i].size(); j++)
				{
					if (Mapvec[i][j] == 200)
					{
						start[0] = i;
						start[1] = j;
					}
				}
				/*��Ȧs�s�iinfo*/
				info = Mapvec;
				/*�ƻsinfo�i�O���禡�|�Ψ쪺�Ȧs*/
				temp_short = info;
				/*for (int i = 0; i < Mapvec.size(); i++)
				{
				for (int j = 0; j < Mapvec[i].size(); j++)
				{
				if (Mapvec[i][j] == 0)
				{
				cout << ROAD;
				}
				else if (Mapvec[i][j] == 1)
				{
				cout << WALL;
				}
				else if (Mapvec[i][j] == 200)
				{
				cout << POINT;
				start[0] = i;
				start[1] = j;
				}
				else
				{
				cout << POINT;
				}
				}
				cout << endl;
				}*/
			}
		}
	}
	else
	{
		cout << "Data Open Error";
		system("pause");
	}
}
Map::Map(int x, int y)
{
	srand(time(NULL));
	vector<vector<int>>temp(y, vector<int>(x, 1));
	info = temp;
	if (1 == 1)
	{

		int step = 1;
		int temp_last=1;
		while (step < temp[0].size() - 2)
		{
			int dis = rand() % (temp.size() - 2) + 1;
			if (temp_last>dis)
			{
				for (int i = dis; i <= temp_last; i++)
				{
					temp[i][step] = 0;
				}
			}
			else
			{
				for (int i = temp_last; i <= dis; i++)
				{
					temp[i][step] = 0;
				}
			}
			int step_last = step;
			if (step + 5 >= temp[0].size() - 2)
			{
				step = temp[0].size() - 2;
				for (int i = step_last; i <= step; i++)
				{
					temp[dis][i] = 0;
				}
				for (int i = dis; i <= temp.size() - 2; i++)
				{
					temp[i][step] = 0;
				}
			}
			else
			{
				step += rand() % 3 + 2;
				for (int i = step_last; i <= step; i++)
				{
					temp[dis][i] = 0;
				}
				if (rand() % 2 == 1 && (step - step_last) >= 4)
				{
					if (rand() % 2 == 1)
					{
						int choose = rand() % (step - step_last - 3) + step_last + 2;
						for (int i = dis; i <= temp.size() - 2 - rand() % (temp.size() - dis); i++)
						{
							temp[i][choose] = 0;
						}
					}
					else
					{
						int choose = rand() % (step - step_last - 3) + step_last + 2;
						for (int i = dis; i >= rand() % dis + 2; i--)
						{
							temp[i][choose] = 0;
						}
					}
				}
			}
			temp_last = dis;
		}
		/*int addpoint=0;/*�[�[���I
		while (addpoint <= x / 10 + y / 10)
		{
			int xx = rand() % x;
			int yy = rand() % y;
			if (temp[yy][xx]==0)
			{
				temp[yy][xx] = 202;
				addpoint++;
			}
		}*/
	}
	if (1==1)
	{
		int step = 1;
		int temp_last = 1;
		while (step < temp.size() - 2)
		{
			int dis = rand() % (temp[0].size() - 2) + 1;
			if (temp_last>dis)
			{
				for (int i = dis; i <= temp_last; i++)
				{
					temp[y-1-step][i] = 0;
				}
			}
			else
			{
				for (int i = temp_last; i <= dis; i++)
				{
					temp[y-1-step][i] = 0;
				}
			}
			int step_last = step;
			if (step + 5 >= temp.size() - 2)
			{
				step = temp.size() - 2;
				for (int i = step_last; i <= step; i++)
				{
					temp[y-1-i][dis] = 0;
				}
				for (int i = dis; i <= temp[0].size() - 2; i++)
				{
					temp[y-1-step][i] = 0;
				}
			}
			else
			{
				step += rand() % 3 + 2;
				for (int i = step_last; i <= step; i++)
				{
					temp[y-1-i][dis] = 0;
				}
				if ( rand() %2==1 && (step - step_last)>=4)
				{
					if (rand() % 2==1)
					{
						int choose = rand() % (step - step_last - 3) + step_last + 2;
						for (int i = dis; i <= temp[0].size() - 2 - rand() % (temp[0].size() - dis); i++)
						{
							temp[y-1-choose][i] = 0;
						}
					}
					else
					{
						int choose = rand() % (step - step_last - 3) + step_last + 2;
						for (int i = dis; i >=rand()%dis+2; i--)
						{
							temp[y-1-choose][i] = 0;
						}
					}
				}
			}
			temp_last = dis;
		}
		int addpoint = 0;/*�[�[���I*/
		while (addpoint <= x / 10 + y / 10)
		{
			int xx = rand() % x;
			int yy = rand() % y;
			if (temp[yy][xx] == 0)
			{
				temp[yy][xx] = 202;
				addpoint++;
			}
		}
	}
	switch (rand() % 12)
	{
	case 0:
		temp[1][1] = 200;
		temp[1][x - 2] = 201;
		break;
	case 1:
		temp[1][1] = 200;
		temp[y-2][1] = 201;
		break;
    case 2:
		temp[1][1] = 200;
		temp[y - 2][x - 2] = 201;
		break;
    case 3:
		temp[1][x-2] = 200;
		temp[y-2][x - 2] = 201;
		start[1] = x - 2;
		break;
   
	case 4:
	    temp[1][x-2] = 200;
	    temp[y-2][x - 2] = 201;
	    start[1] = x - 2;
	    break;
	case 5:
		temp[1][x-2] = 200;
		temp[y - 2][1] = 201;
		start[1] = x - 2;
		break;
	case 6:
		temp[y-2][1] = 200;
		temp[1][1] = 201;
		start[0] = y - 2;
		break;
	case 7:
		temp[y - 2][1] = 200;
		temp[y - 2][x-2] = 201;
		start[0] = y - 2;
		break;
	case 8:
		temp[y - 2][1] = 200;
		temp[1][x-2] = 201;
		start[0] = y - 2;
		break;
	case 9:
		temp[y - 2][x - 2] = 200;
		temp[1][1] = 201;
		start[0] = y - 2;
		start[1] = x - 2;
		break;
	case 10:
		temp[y - 2][x - 2] = 200;
		temp[y - 2][1] = 201;
		start[0] = y - 2;
		start[1] = x - 2;
		break;
	case 11:
		temp[y - 2][x - 2] = 200;
		temp[1][x - 2] = 201;
		start[0] = y - 2;
		start[1] = x - 2;
		break;
	}

	info = temp;
	temp_short = info;
}
void Map::print()/*�L�X�a��*/
{
	printMap(info);/*info���a�ϸ��*/
}
void Map::printMap(vector<vector<int>>a)/*�Ϲ��ƦL�X�ǤJ���a��a*/
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j] >= 2&& a[i][j] <= 5)
			{
				/*cout << a[i][j] << " ";*/
				switch (a[i][j])
				{
				case 2:cout << UP; break;
				case 3:cout << DOWN; break;
				case 4:cout << LEFT; break;
				case 5:cout << RIGHT; break;
				}
			}
			else if (a[i][j] == 0)
			{
				cout << ROAD;
			}
			else if (a[i][j] == 1)
			{
				cout << WALL;
			}
			else if (a[i][j] >= 202)
			{
				cout << ADD;
			}
			else
			{
				cout << POINT;
			}
		}
		cout << endl;
	}
}
void Map::way(vector<vector<int>>a, int x, int y, int step,int score)/*�ΨӨ��g�c�����j*/
{
	if (x - 1 >= 0)
	{
		if (a[x - 1][y] == 0 || a[x - 1][y] >= 202)
		{
			/*cout << "1";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 2;
			}
			if (/*temp_print_way < 10*/find_check == 0)
			{
				way(a, x - 1, y, step + 1, score);/*(��(x-1,y)�i��),�i*/
			}
		}
		if (a[x - 1][y] == 201)
		{
			a[x][y] = 2;
			if (/*temp_print_way < 10*/find_check == 0)
			{
				find_check = 1;
				printMap(a);
				cout <<  "Point you will get:" << score << endl << endl;
				temp_print_way++;
			}
		}
	}
	if (x + 1 < a.size())
	{
		if (a[x + 1][y] == 0 || a[x + 1][y] >= 202)
		{
			/*cout << "2";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 3;
			}
			if (/*temp_print_way < 10*/find_check == 0)
			{
				way(a, x + 1, y, step + 1, score);/*(��(x+1,y)�i��),�i*/
			}
			
		}
		if (a[x + 1][y] == 201)
		{
			a[x][y] = 3;
			/*cout << step << endl;*/
			if (/*temp_print_way < 10*/find_check == 0)
			{
				find_check = 1;
				printMap(a);
				cout  << "Point you will get:" << score << endl << endl;
				temp_print_way++;
			}
		}
	}
	if (y - 1 >= 0)
	{
		if (a[x][y - 1] == 0 || a[x][y - 1] >= 202)
		{
			/*cout << "3";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 4;
			}
			if (/*temp_print_way < 10*/find_check == 0)
			{
				way(a, x, y - 1, step + 1, score);/*(��(x,y-1)�i��),�i*/
			}
		}
		if (a[x][y - 1] == 201)
		{
			a[x][y] = 4;
			if (/*temp_print_way < 10*/find_check == 0)
			{
				find_check = 1;
				printMap(a);
				cout << "Point you will get:" << score << endl << endl;
				temp_print_way++;
			}
		}
	}
	if (y + 1 < a[0].size())
	{
		if (a[x][y + 1] == 0 || a[x][y + 1] >= 202)
		{
			/*cout << "4";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 5;
			}
			if (/*temp_print_way < 10*/find_check == 0)
			{
				way(a, x, y + 1, step + 1, score);/*(��(x,y+1)�i��),�i*/
			}
		}
		if (a[x][y + 1] == 201
			
			)
		{
			a[x][y] = 5;
			if (/*temp_print_way < 10*/find_check == 0)
			{
				find_check = 1;
				printMap(a);
				cout << "Point you will get:" << score << endl << endl;
				temp_print_way++;
			}
		}
	}
}
void Map::way_short(vector<vector<int>>a, int x, int y, int step,int score)/*�γ̵u���|���g�c�����j(���p������step�p��Ȧs,��s��)*/
{
	if (x - 1 >= 0)
	{
		if (a[x - 1][y] == 0 || a[x - 1][y] >= 202)
		{
			/*cout << "1";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x
			][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 2;
			}
			way_short(a, x - 1, y, step + 1, score);/*(��(x-1,y)�i��),�i*/
		}
		if (a[x - 1][y] == 201&& step<temp_short_step)/*������I�B�B�Ƥ�Ȧs�u*/
		{
		    a[x][y] = 2;
			temp_short = a;
			temp_short_step = step;
			temp_short_score = score;
		}
	}
	if (x + 1 < a.size())
	{
		if (a[x + 1][y] == 0 || a[x + 1][y] >= 202)
		{
			/*cout << "2";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 3;
			}
			way_short(a, x + 1, y, step + 1, score);/*(��(x+1,y)�i��),�i*/
		}
		if (a[x + 1][y] == 201 && step<temp_short_step)/*������I�B�B�Ƥ�Ȧs�u*/
		{
			a[x][y] = 3;
			temp_short = a;
			temp_short_step = step;
			temp_short_score = score;
		}
	}
	if (y - 1 >= 0)
	{
		if (a[x][y - 1] == 0 || a[x][y - 1] >= 202)
		{
			/*cout << "3";*/
			if ((a[x][y] >= 0 && a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 4;
			}
			way_short(a, x, y - 1, step + 1, score);/*(��(x,y-1)�i��),�i*/
		}
		if (a[x][y -1] == 201 && step<temp_short_step)/*������I�B�B�Ƥ�Ȧs�u*/
		{
			a[x][y] = 4;
			temp_short = a;
			temp_short_step = step;
			temp_short_score = score;
		}
	}
	if (y + 1 < a[0].size())
	{
		if (a[x][y + 1] == 0 || a[x][y + 1] >= 202)
		{
			/*cout << "4";*/
			if ((a[x][y] >= 0&& a[x][y] <= 5) || a[x][y] >= 202)
			{
				if (a[x][y] >= 202)
				{
					score++;
				}
				a[x][y] = 5;
			}
			way_short(a, x, y + 1, step + 1, score);/*(��(x,y+1)�i��),�i*/
		}
		if (a[x][y + 1] == 201 && step<temp_short_step)/*������I�B�B�Ƥ�Ȧs�u*/
		{
			a[x][y] = 5;
			temp_short = a;
			temp_short_step = step;
			temp_short_score = score;
		}
	}
}
void Map::print_shortest_way()/*�L�X�q�_�I������I���̵u���|*/
{
	way_short(temp_short, start[0], start[1], 1);/*(�n�����a�ϸ�T,�_�Ix�y��,�_�Iy�y��,�w���B��,�w�o����)*/
	cout<<"Used step:"<< temp_short_step<<endl;/*�B��*/
	printMap(temp_short);/*�L�X���|*/
	cout << "Point you will get:" << temp_short_score << endl << endl;/*�o���I��*/
	/*�H�U�O��ƪ���l��*/
	temp_short.resize(0);
	temp_short=info;
	temp_short_step = 9999;
	temp_short_score = 0;
	system("pause");
}
void Map::print_info()/*�H�Ʀr���覡�L�X�a�ϨC�@�檺��T*/
{
	for (int i = 0; i < info.size(); i++)
	{
		for (int j = 0; j < info[i].size(); j++)
		{
			cout <<setw(5)<< info[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void Map::print_way()/*�L�X�q�_�I������I����k*/
{
	find_check = 0;
	way(info, start[0], start[1]);/*(�n�����a�ϸ�T,�_�Ix�y��,�_�Iy�y��)*/
	/*if (temp_print_way >= 10)/*�i���i��W�L�Q�ث��L�Q��
	{
		cout << "The possible ways are too much.Just print 10 of those.";
	}*/
	temp_print_way=0;/*�Ѽƪ�l��*/
	system("pause");
}