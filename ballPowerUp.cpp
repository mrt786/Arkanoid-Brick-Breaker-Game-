/*
 * ballPowerUp.cpp
 *
 *  Created on: May 3, 2024
 *      Author: rehan
 */

#include "ballPowerUp.h"
#include "food.h"
ballPowerUp::ballPowerUp() 
{
	// TODO Auto-generated constructor stub
	*this = 0;
}
ballPowerUp ballPowerUp :: operator=(int n)
{
	xcor = 100;
	ycor = 100;
	Balls.setBallSpeed (0);
	Balls.setXFactor(0);
	Balls.setYFactor(0);
	Balls.setBallSpeed(0);
	setCheck(0);
	return *this;
}
ballPowerUp::~ballPowerUp() 
{
	// TODO Auto-generated destructor stub
}

