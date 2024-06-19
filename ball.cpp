/*
 * ball.cpp
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#include "ball.h"
#include <iostream>
using namespace std;
ball::ball() 
{
	// TODO Auto-generated constructor stub
	ballSpeed =12;
	xFactor = 10;
	yFactor = 2;
	color = 5;
}
int ball::getXFactor() const {
	return xFactor;
}

void ball::setXFactor(int XFactor) {
	xFactor = XFactor;
}

int ball::getYFactor() const {
	return yFactor;
}
int ball::getBallSpeed() const {
	return ballSpeed;
}
void ball::setBallSpeed(int s) {
	ballSpeed = s;
}
void ball::setYFactor(int yFactor) {
	this->yFactor = yFactor;
}
ball::~ball() {
	// TODO Auto-generated destructor stub
}

void ball:: moveBall()
{
	if (xcor >= (screenWidth - 300) )
	{
		// it makes the xfactor to -ve
		xFactor *= -1;
		xcor -= 5;
	}
	else if (xcor <= 0 )
	{
		// it makes the xfactor to +ve
		xFactor *= -1;
		xcor += 5;
	}
	if (ycor > screenHeight)
	{
		yFactor *= -1;
		xcor -= 5;
	}
	xcor += xFactor;
	ycor += yFactor;
}
