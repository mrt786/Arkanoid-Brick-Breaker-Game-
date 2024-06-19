/*
 * paddle.cpp
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#include "paddle.h"
#include <iostream>
using namespace std;
paddle::paddle() 
{
	// TODO Auto-generated constructor stub
	xcor = 400;
	ycor = 50;
	paddleLength  = 140;
	paddleHeight = 20;
	speedFactor = 8;
	color = 5;
}

int paddle::getPaddleLength() const {
	return paddleLength;
}

void paddle::setPaddleLength(int paddleLength) {
	this->paddleLength = paddleLength;
}

int paddle::getPaddleHeight() const {
	return paddleHeight;
}

void paddle::setPaddleHeight(int paddleHeight) {
	this->paddleHeight = paddleHeight;
}
int paddle::getSpeedFactor() const {
	return speedFactor;
}

void paddle::setSpeedFactor(int speedFactor) {
	this->speedFactor = speedFactor;
}
paddle::~paddle()
{
	
}

