#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<vector>
#include<string>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
using namespace std;


#ifndef EVENT
#define EVENT



class Event
{
public:

	Event(int, int , string , vector<string>, string );//level,money,name,story,describe


	int progress = 0;
	int progress_max = 1;
	string describe = "";
	vector<string>Line;
	virtual bool is_finish()
	{
		return (progress >= progress_max);
	}
	void get_task();
	void check_progress()
	{
		cout <<"(" <<progress<<"/"<< progress_max<<")";
	}
	string name;
	int money = 0;
	int state =0;//-1不可接,0可接,1已接:
	int NPC_NO;
				   //限制
	int level;
	int event_num_limit = 10;

	void reset()
	{
		state = 0;
		progress = 0;
	}

	static int Event_num;
	static int Event_get;



};

class Find :public Event
{
public:
	Find(int level, int money, string name, vector<string> story, string describe, int Find = 1)
		:Event(level, money, name, story, describe)
	{
		find_need = Find;
	}

	int find_need = 1;
	int find=0;
	virtual bool is_finish()
	{
		find= progress;
		return (progress >=progress_max);
	}

};

class Hunt :public Event
{
public:
	Hunt(int level, int money, string name, vector<string> story, string describe,int monsters=10)
		:Event(level, money, name, story, describe)
	{
		monster_num = monsters;
		progress_max = monster_num;
	}
	int monster_num = 10;
	int killed_num = 0;

	virtual bool is_finish()
	{
		killed_num = progress;
		return(progress >= progress_max);
	}




};
class Get :public Event
{
public:
	int monster_num = 0;
	int killed_num = 0;

	virtual bool is_finish()
	{
		return(monster_num >= killed_num);
	}




};

class Task
{
public:

	Task()
	{
		vector<Event*>Task_input;
		Tasks = Task_input;
	}
	Task(vector<Event*>Task_input)
	{
		Tasks = Task_input;

	}

	vector<Event*>Tasks;
	vector<Event*>Tasks_get;
	void update_state();
	void check_tasks();

};

#endif

