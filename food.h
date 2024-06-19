/*
 * food.h
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#ifndef FOOD_H_
#define FOOD_H_
#include "shape.h"
#include "brick.h"
#include "ball.h"
#include "paddle.h"
class food: public shape
{
	float timer;
	int factor;// factor is for what the powerup or power down will do
	int numOfFoods;
	int foodWidth;
	int foodHeight;
	bool check ;

public:
	food();
	virtual ~food();
	
	bool isCheck() const;
	void setCheck(bool check);
	int getFactor() const;
	void setFactor(int factor);
	int getNumOfFoods() const;
	void setNumOfFoods(int numOfFoods);
	void setFood(food& f1,brick& b1);

	void moveFood(food*&);
	void removeFoodEffect(food*&,ball&);
	
	bool checkFoodCollision(ball& b1, paddle*&,food*&);
	int getFoodHeight() const;
	void setFoodHeight(int foodHeight);
	int getFoodWidth() const;
	void setFoodWidth(int foodWidth);
	float getTimer() const;
	void setTimer(float timer);
};

#endif /* FOOD_H_ */
