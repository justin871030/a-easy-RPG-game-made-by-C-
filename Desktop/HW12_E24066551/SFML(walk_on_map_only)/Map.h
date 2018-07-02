#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

class Map
{
public:
	/*█ Constructor █*/
	Map(string a = "maze1.txt");/*如果檔案名稱錯誤預設值為"maze1.txt"*/
	Map(int x=5,int y=5);
	/*█ 資訊 █*/
	string dataname;/*地圖檔名*/
	int start[2] = { 1,1 };/*存起點位置*/
	vector<vector<int>>info;/*存每一格的數字*/
	/*█ 使用者的工具 █*/
	void print();/*印出迷宮(圖形)*/
	void print_way();/*印出所有可能路徑*/
	void print_shortest_way();/*印出迷宮最短路徑(圖形)*/
	void print_info();/*印出迷宮(資料)*/
	int** pointer_2D();
private:
	/*█ function暫存資料 █*/
	int find_check = 0;/*是否找到路徑*/
	int score_add = 0;/*得到的點數*/
	int temp_print_way=0;/*已印出數量(印出所有可能路徑)*/
	int temp_short_step = 9999; 
	int temp_short_score = 0;
	vector<vector<int>>temp_short;/*用來暫存最短路徑的資料*/
	/*█ Public Function會用到的工具 █*/
	void printMap(vector<vector<int>>a);/*用來印答案(傳入的vector)*/
	void way(vector<vector<int>>a, int x, int y,int step=1, int score=0);/*用來走迷宮的遞迴*//*(要走的地圖資訊,起點x座標,起點y座標,已走步數,已得分數)*/
	void way_short(vector<vector<int>>a, int x, int y, int step = 1, int score = 0);/*用最短路徑走迷宮的遞迴(假如走完的step小於暫存,刷新它)*/
};
