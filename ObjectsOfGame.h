/*
 * ObectsOfGame.h
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#ifndef OBECTSOFGAME_H_
#define OBECTSOFGAME_H_
#include "ball.h"
#include "paddle.h"
#include "food.h"
#include "brick.h"
#include "ballPowerUp.h"
#include <iostream>
using namespace std;
class ObjectsOfGame 
{
	int lives;
	string gameCondition;// p for pause, r for resume q for quit
	int numOfBricks;
	int screenWidth;
	int screenHeight;
	int highScore;
	string level;
	void storeScore(int score,string fileName);
	void setLevel4();
	void setLevel2();
	void setLevel3();
	public:
	int* colour;
	int score;
	ball  ball1;
	paddle* Paddle1;
	paddle* paddle2;
	food * Food;//to store multiple foods in it
	brick* bricks;
	ballPowerUp *balls;// to store multiple balls
	ObjectsOfGame();
	virtual ~ObjectsOfGame();
	const string& getGameCondition() const;
	void setGameCondition(const string &gameCondition);
	int getLives() const;
	void setLives(int lives);
	int getScore() const;
	void setScore(int score);
	int getNumOfBricks() const;
	void setNumOfBricks(int numOfBricks);
	bool checkPaddleCollison(ball&,paddle*);
	int getScreenHeight() const;
	void setScreenHeight(int screenHeight);
	int getScreenWidth() const;
	void setScreenWidth(int screenWidth);
	void checkBrickCollison(ball& );
	void generatePowerUp(brick& ptr);
	void gameCheck();
	void foodFunctions();
	void generateBallFood();
	void setLevel(string level);
	void Deallocation();
	string getLevel()const;
	string toString(int num);
};

#endif /* OBECTSOFGAME_H_ */
