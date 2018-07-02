#include"Event.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

Event::Event(int Level, int Money, string Name, vector<string>line, string Describe)
{
	describe = Describe;
	Line = line;
	name = Name;
	money = Money;
	level = Level;
}
void Event::get_task()
{
	for (int i = 0; i < Line.size(); i++)
	{
		for (int j = 0; j < Line[i].size(); j++)
		{
			cout << Line[i][j];
			Sleep(30);
		}
		Sleep(100);
		cout << endl;
	}
	string ask = "Your choose(Y/N):";
	for (int j = 0; j < ask.size(); j++)
	{
		cout << ask[j];
		Sleep(30);
	}
	char choose = 's';
	do
	{
		choose = _getch();
	} while (!(choose == 'y' || choose == 'n'));
	if (choose == 'y')
	{
		state = 1;
	}
}

void Task::update_state()
{
	vector<Event*>temp;
	for (int i = 0; i < Tasks.size(); i++)
	{
		if (Tasks[i]->state==1)
		{
			temp.push_back(Tasks[i]);
		}
	}
	Tasks_get = temp;
}

void Task::check_tasks()
{
	int choose = 0;
	int delet = 0;
	char aa='c';
	do
	{
		system("cls");
		for (int i = 0; i < Tasks_get.size(); i++)
		{
			if (choose == i)
			{
				cout << "->";
			}
			Tasks_get[i]->check_progress();
			cout << Tasks_get[i]->name << endl;
		}
		if (aa=='a'|| aa == 't')
		{
			return;
		}
		if (aa=='w')
		{
			if (choose==0)
			{
				choose = Tasks_get.size() - 1;
			}
			else
			{
				choose--;
			}
		}
		if (aa == 's')
		{
			if (choose == Tasks_get.size() - 1)
			{
				choose = 0;
			}
			else
			{
				choose++;
			}
		}
		if (aa == 'd')
		{
			char bb='c';
			while(1)
			{
				system("cls");
				if (delet==0)
				{
					cout << "->";
				}
				cout << "Check content"<<endl;
				if (delet == 1)
				{
					cout << "->";
				}
				cout << "Give up" << endl;
				bb = _getch();
				if (bb == 'a' || aa == 't')
				{
					break;
				}
				if (bb == 'w')
				{
					if (delet == 0)
					{
						delet = 1;
					}
					else
					{
						delet--;
					}
				}
				if (bb == 's')
				{
					if (delet == 1)
					{
						delet = 0;
					}
					else
					{
						delet++;
					}
				}
				if (bb == 'd'&&delet == 1)
				{
					Tasks_get[choose]->reset();
					system("cls");
					cout << "done";
					Sleep(200);
					return;
				}
				if (bb == 'd'&&delet == 0)
				{
					system("cls");
					for (int i = 0; i < Tasks_get[choose]->describe.size(); i++)
					{
						cout << Tasks_get[choose]->describe[i];
						Sleep(30);
					}
					Sleep(200);
				}
			}
		}
	} while (aa = _getch());
}