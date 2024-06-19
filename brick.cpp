/*
 * brick.cpp
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#include "brick.h"
#include<iostream>
using namespace std;
brick::brick() 
{
	// TODO Auto-generated constructor stub
	brickHeight = 0;
	brickWidth = 0;
	numOfCollisions = 0;
	check = true;

}

int brick::getBrickHeight() const {
	return brickHeight;
}

void brick::setBrickHeight(int brickHeight) {
	this->brickHeight = brickHeight;
}

int brick::getBrickWidth() const {
	return brickWidth;
}

void brick::setBrickWidth(int brickWidth) {
	this->brickWidth = brickWidth;
}

bool brick::isCheck() const {
	return check;
}

void brick::setCheck(bool check) {
	this->check = check;
}
bool brick::getCheck()const
{
	return check;
}

void brick:: setBrick(brick*& obj,int numOfBricks)
{
	// srand(time(0));
	// 20 is the initial point 
	obj[0].setXcor(100);
	obj[0].setYcor(700);
	for(int i = 1; i < numOfBricks ; i++)
	{
		obj[i].setXcor( obj[i-1].getXcor() + obj[i-1].getBrickWidth());
		if (obj[i].getXcor() >= (screenWidth - 480))// screen width checking
		{
			
			obj[i].setXcor(100);
			obj[i].ycor = obj[i-1].getYcor() - obj[i].getBrickHeight();
		}
		else
		{
			obj[i].setYcor(obj[i-1].getYcor());
		}
	}
}
brick::~brick() 
{
	// TODO Auto-generated destructor stub
}

int brick::getNumOfCollisions() const {
	return numOfCollisions;
}

void brick::setNumOfCollisions(int numOfCollisions) {
	this->numOfCollisions = numOfCollisions;
}
void brick:: setLevel2Bricks(brick*& ptr,int num)
{
	if(num > 0)
	{
		ptr[0].setXcor((screenWidth - 500)/2);
		ptr[0].setYcor(800);
		bool check = true;
		for(int i = 1; i < num ; i++)
		{
			ptr[i].setYcor(ptr[i-1].getYcor()- brickHeight);
			if (i % 4 == 0)
			{
				if ((ptr[i-1].getXcor() + (ptr[i-1].getBrickWidth() * 2) > screenWidth - 300 && check != false) ||  (i == (num/2)+2))
				{
					check = false;
				}
				if (check)
				{
					ptr[i].setXcor(ptr[i-1].getXcor() + ptr[i].getBrickWidth());
				}
				else
				{
					ptr[i].setXcor(ptr[i-1].getXcor() - ptr[i].getBrickWidth());
				}
			}
			else
			{
				ptr[i].setXcor(ptr[i-1].getXcor());
			}
		}
	}
}

void brick:: setLevel3Bricks(brick*& ptr,int& i,int xcor,int& ycor,int numOfBricks)
{
	if (i == (numOfBricks/2) )
	{
		return;
	}
	else
	{
		ptr[i].setXcor(400);
		ptr[i].setYcor(ycor);
		ptr[i].setBrickWidth((360-xcor)/4);
		ptr[i].setBrickHeight(20);

		ptr[i+1].setXcor(400 + ptr[i].getBrickWidth() );
		ptr[i+1].setYcor(ycor);
		ptr[i+1].setBrickWidth((360-xcor)/4);
		ptr[i+1].setBrickHeight(20);

		ptr[i+2].setXcor(400+ptr[i+1].getBrickWidth()*2 + xcor);
		ptr[i+2].setYcor(ycor);
		ptr[i+2].setBrickWidth((360-xcor)/4);
		ptr[i+2].setBrickHeight(20);

		ptr[i+3].setXcor(400+ptr[i+2].getBrickWidth()*3 + xcor);
		ptr[i+3].setYcor(ycor);
		ptr[i+3].setBrickWidth((360-xcor)/4);
		ptr[i+3].setBrickHeight(20);
		i += 4;
		ycor -= 20;
		setLevel3Bricks(ptr,i,xcor+20,ycor,numOfBricks);
		ptr[i].setXcor(400);
		ptr[i].setYcor(ycor);
		ptr[i].setBrickWidth((360-xcor)/4);
		ptr[i].setBrickHeight(20);

		ptr[i+1].setXcor(400 + ptr[i].getBrickWidth() );
		ptr[i+1].setYcor(ycor);
		ptr[i+1].setBrickWidth((360-xcor)/4);
		ptr[i+1].setBrickHeight(20);

		ptr[i+2].setXcor(400+ptr[i+1].getBrickWidth()*2 + xcor);
		ptr[i+2].setYcor(ycor);
		ptr[i+2].setBrickWidth((360-xcor)/4);
		ptr[i+2].setBrickHeight(20);

		ptr[i+3].setXcor(400+ptr[i+2].getBrickWidth()*3 + xcor);
		ptr[i+3].setYcor(ycor);
		ptr[i+3].setBrickWidth((360-xcor)/4);
		ptr[i+3].setBrickHeight(20);
		i += 4;
		ycor -= 20;
		
	}
}
void brick::setlevel4Bricks(brick*& obj,int num)
{
	obj[0].setBrickWidth(121);
	obj[0].setBrickHeight(25);
	obj[0].setXcor(0);
	obj[0].setYcor(screenHeight - 50);
	for (int i = 1; i < num; i++)
	{
		obj[i].setBrickWidth(121);
		obj[i].setBrickHeight(25);
		obj[i].setXcor(obj[i-1].getXcor() + obj[i].getBrickWidth());
		if (obj[i].getXcor() + obj[i].getBrickWidth() > screenWidth - 300)
		{
			obj[i].setXcor(0);
			obj[i].setYcor(obj[i-1].getYcor() - 100);
		}
		else
		{
			obj[i].setYcor(obj[i-1].getYcor());
		}
	}
	
}	
