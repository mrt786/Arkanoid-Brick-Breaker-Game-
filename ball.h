/*
 * ball.h
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#ifndef BALL_H_
#define BALL_H_
#include "shape.h"
class ball:public shape
{
private:
    int ballSpeed;
    int xFactor;
    int yFactor;
public:
    ball();
    int getBallSpeed() const;
	void setBallSpeed(int ballSpeed);
    int getXFactor() const;
	void setXFactor(int xFactor);
	int getYFactor() const;
	void setYFactor(int yFactor);
    void moveBall();
	virtual ~ball();
};
#endif /* BALL_H_ */
