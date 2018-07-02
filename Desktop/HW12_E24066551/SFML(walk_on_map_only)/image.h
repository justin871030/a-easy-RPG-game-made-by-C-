#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
#include<math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;

#ifndef IMAGE
#define IMAGE

class Image_char
{
public:
	Image_char(string texture,Vector2u imageCount,float switchTime);
	IntRect uvRect;
	Texture playerTexture;
	void Update(int row, float deltaTime);
private:
	string TextName;
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;
	int side=0;
};



#endif
