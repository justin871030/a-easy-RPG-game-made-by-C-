#include"image.h"
#include<math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;


Image_char::Image_char(string texture, Vector2u imageCount, float switchTime)
{
	TextName=texture;
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	playerTexture.loadFromFile(TextName);
	uvRect.width = playerTexture.getSize().x / float(imageCount.x);
	uvRect.height = playerTexture.getSize().y / float(imageCount.y);
}
void Image_char::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime>=switchTime)
	{
		totalTime -= switchTime;
		if (currentImage.x >= imageCount.x-1)
		{
			currentImage.x = 0;
		}
		else
		{
			currentImage.x++;
		}
	}
	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;
}