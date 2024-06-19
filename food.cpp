/*
 * food.cpp
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#include "food.h"
#include "ballPowerUp.h"
#include <iostream>
using namespace std;
food::food()
{
	// TODO Auto-generated constructor stub
	check = false;
	factor = 0;
	timer = 0;
	numOfFoods++;
}

food::~food() {
	// TODO Auto-generated destructor stub
}

bool food::isCheck() const {
	return check;
}

void food::setCheck(bool check) {
	this->check = check;
}

int food::getFactor() const {
	return factor;
}

void food::setFactor(int factor) {
	// cout << "LOL" << endl;
	this->factor = factor;
}

int food::getNumOfFoods() const {
	return numOfFoods;
}

void food::setNumOfFoods(int numOfFoods) {
	this->numOfFoods = numOfFoods;
}
void food:: setFood(food& f1,brick& b1)
{
	f1.setXcor(b1.getXcor() + (b1.getBrickWidth()/2));
	f1.setYcor(b1.getYcor());
	f1.setColor(b1.getColor());	
	f1.setCheck(true);
}
void food:: moveFood(food*& ptr)
{
	for (int  i = 4; i < numOfFoods; i++)
	{
		if (ptr[i].isCheck())
		{
			ptr[i].ycor = ptr[i].ycor - 2  ;
			// cout << ptr[i].ycor << endl;
			// paddle fails to hit the power up
			if (ptr[i].ycor < 10 )
			{
				ptr[i].check = false;
			}
		}
	}
}

int food::getFoodHeight() const 
{
	return foodHeight;
}

void food::setFoodHeight(int foodHeight) 
{
	this->foodHeight = foodHeight;
}

int food::getFoodWidth() const 
{
	return foodWidth;
}

void food::setFoodWidth(int foodWidth)
{
	this->foodWidth = foodWidth;
}

float food::getTimer() const 
{
	return timer;
}

void food::setTimer(float timer) 
{
	this->timer = timer;
}
// if the yellow powerup collides then returns true
bool food::checkFoodCollision(ball& b1, paddle*& p1,food*& f1)
{
	for (int i = 4; i < numOfFoods; i++)
	{
		if (f1[i].isCheck())
		{
			if ((p1->getXcor() + p1->getPaddleLength() - f1[i].getFoodWidth() <= p1->getPaddleLength() && p1->getXcor() + p1->getPaddleLength() - f1[i].getFoodWidth() >=0 )
			&& p1->getYcor()-f1[i].getYcor() >= 0 && p1->getYcor()-f1[i].getYcor() <= p1->getPaddleHeight())
			{
				f1[i].check = false;
				int c = f1[i].color ;
				// cout << c << endl;
				if (c == 30 )
				{
					if(p1->getPaddleLength()+ f1[0].factor <= (f1[0].factor *2))
					{
						// cout << "Length inc" << endl;
						p1->setPaddleLength(p1->getPaddleLength()+ f1[0].factor);
					}
				}
				else if(c == 22)
				{
					// cout << "COLLIDE\n";
					return 1;
				}
				else if (c == 87)
				{
					if(p1->getPaddleLength()+ f1[1].factor > 0)
					{	
						// cout << "Length dec" << endl;
						p1->setPaddleLength(p1->getPaddleLength()+ f1[1].factor);
					}
				}
				else if(c == 68 || c == 5)
				{
					if (c == 5 && f1[2].timer != 0.7) 
					{
						// max speed of the ball is 5
						if(!f1[3].isCheck())
							f1[3].timer = 0.7; 
						else
							 f1[3].timer = 0.5;
						f1[3].setCheck(true);
						if(b1.getBallSpeed() + f1[3].factor > 0 )
						{
							// cout << "Speed  Inc" << endl;
							b1.setBallSpeed(b1.getBallSpeed() + f1[3].factor);
						}
						// setting the 2nd to false
						f1[2].setCheck(false);
					}
					else if (c == 68 && f1[3].timer != 0.7)
					{
						// min speed of the ball is 15
						if(!f1[2].isCheck())
							f1[2].timer = 0.7;
						else
							 f1[2].timer = 0.5;//timer reset
						f1[2].setCheck(true); 
						if(b1.getBallSpeed() + f1[2].factor <= (f1[2].factor ) * 3)
						{
							// cout << "speed dec" << endl;
							b1.setBallSpeed(b1.getBallSpeed() + f1[2].factor);
						}
						f1[3].setCheck(false);
					}
				}
			}	
		}
	}
	return 0;
}

void food:: removeFoodEffect(food*& f1,ball& b1)
{
	for (int i = 2; i < 5; i++)
	{
		if (f1[i].check && f1[i].timer <= 0.5)
		{
			f1[i].timer -=  0.00159;
			if (f1[i].timer <= 0 )
			{
				if (i == 2 || i == 3 )
				{
					// cout << "Reset" << endl;
					b1.setBallSpeed(b1.getBallSpeed() - f1[i].factor );
					f1[i].check = false;
				}
			}
		}
	}
}
