/*
 * shape.cpp
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#include "shape.h"

shape :: shape()
{
    ycor = 0;
    xcor = 0;
    color = 0;
    screenWidth  = 1400;
	screenHeight =  840;
}
void shape:: setXcor(int x)
{
    xcor = x;
}
void shape::setYcor(int y )
{
    ycor = y;
}
int shape:: getYcor()const
{
    return ycor;
}
int shape:: getXcor()const
{
    return xcor;
}
shape:: ~shape()
{

}

int shape::getColor() const {
	return color;
}

void shape::setColor(int color) {
	this->color = color;
}

int shape::getScreenHeight() const {
	return screenHeight;
}

int shape::getScreenWidth() const {
	return screenWidth;
}

void shape::setScreenHeight(int screenHeight) {
	this->screenHeight = screenHeight;
}

void shape::setScreenWidth(int screenWidth) {
	this->screenWidth = screenWidth;
}
