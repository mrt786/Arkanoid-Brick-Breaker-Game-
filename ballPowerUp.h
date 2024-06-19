/*
 * ballPowerUp.h
 *
 *  Created on: May 3, 2024
 *      Author: rehan
 */

#ifndef BALLPOWERUP_H_
#define BALLPOWERUP_H_
#include "shape.h"
#include "food.h"
#include "ball.h"




class ballPowerUp:public food
{
	public:
		ball Balls;
		ballPowerUp();
		virtual ~ballPowerUp();
		// const ball& getBalls() const;
		// void setBalls(const ball &balls);
		ballPowerUp operator=(int);
};

#endif /* BALLPOWERUP_H_ */
