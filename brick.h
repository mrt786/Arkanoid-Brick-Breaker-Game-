/*
 * brick.h
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#ifndef BRICK_H_
#define BRICK_H_
#include "shape.h"
class brick: public shape
{
	bool check;// to check that it is present or not
	int brickWidth;
	int brickHeight;
	int numOfCollisions;
public:
	brick();
	virtual ~brick();
	int getBrickHeight() const;
	void setBrickHeight(int brickHeight);
	int getBrickWidth() const;
	void setBrickWidth(int brickWidth);
	bool isCheck() const;
	void setCheck(bool check);
	bool getCheck()const;
	void setBrick(brick*& obj,int numOfBricks);
	int getNumOfCollisions() const;
	void setNumOfCollisions(int numOfCollisions);
	void setLevel2Bricks(brick*& obj,int numOfBricks);
	void setLevel3Bricks(brick*&,int&,int,int&,int);
	void setlevel4Bricks(brick*&,int);
};

#endif /* BRICK_H_ */
