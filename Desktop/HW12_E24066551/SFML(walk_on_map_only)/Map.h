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
	/*�i Constructor �i*/
	Map(string a = "maze1.txt");/*�p�G�ɮצW�ٿ��~�w�]�Ȭ�"maze1.txt"*/
	Map(int x=5,int y=5);
	/*�i ��T �i*/
	string dataname;/*�a���ɦW*/
	int start[2] = { 1,1 };/*�s�_�I��m*/
	vector<vector<int>>info;/*�s�C�@�檺�Ʀr*/
	/*�i �ϥΪ̪��u�� �i*/
	void print();/*�L�X�g�c(�ϧ�)*/
	void print_way();/*�L�X�Ҧ��i����|*/
	void print_shortest_way();/*�L�X�g�c�̵u���|(�ϧ�)*/
	void print_info();/*�L�X�g�c(���)*/
	int** pointer_2D();
private:
	/*�i function�Ȧs��� �i*/
	int find_check = 0;/*�O�_�����|*/
	int score_add = 0;/*�o�쪺�I��*/
	int temp_print_way=0;/*�w�L�X�ƶq(�L�X�Ҧ��i����|)*/
	int temp_short_step = 9999; 
	int temp_short_score = 0;
	vector<vector<int>>temp_short;/*�ΨӼȦs�̵u���|�����*/
	/*�i Public Function�|�Ψ쪺�u�� �i*/
	void printMap(vector<vector<int>>a);/*�ΨӦL����(�ǤJ��vector)*/
	void way(vector<vector<int>>a, int x, int y,int step=1, int score=0);/*�ΨӨ��g�c�����j*//*(�n�����a�ϸ�T,�_�Ix�y��,�_�Iy�y��,�w���B��,�w�o����)*/
	void way_short(vector<vector<int>>a, int x, int y, int step = 1, int score = 0);/*�γ̵u���|���g�c�����j(���p������step�p��Ȧs,��s��)*/
};
