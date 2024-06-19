/*
 * ObjectsOfGame.cpp
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */
#include "ObjectsOfGame.h"
#include "ball.h"
#include<ctime>
#include <fstream>
#include<cstdlib>
ObjectsOfGame::ObjectsOfGame()
{
	// TODO Auto-generated constructor stub
	gameCondition = "S";
	screenHeight = 840;
	screenWidth = 1400;
	colour = new int[5];
	score = 0;
	colour[0] = 30;//green
	colour[1] = 87;//pink
	colour[2] = 68;//blue
	colour[3] = 5;// red
	colour[4] = 22;//yellow
	ball1.setScreenHeight(840);
	ball1.setScreenWidth(1400);
	ball1.setXcor((screenWidth/2) - 150);
	ball1.setYcor(90);
	ball1.setXFactor(5);
	ball1.setYFactor(5);
	lives = 2;
	setLevel("Level 1");
	numOfBricks = 63;
	// numOfBricks = 0;
	bricks = new brick [numOfBricks];
	// this function will set the brick in Level 1
	int x   = 0;
	srand(time(0));
	for (int i = 0; i < numOfBricks; i++)
	{
		x = rand()%5;
		bricks[i].setNumOfCollisions(1);
		bricks[i].setBrickWidth(120);
		bricks[i].setBrickHeight(25);
		bricks[i].setColor(colour[x]);
		bricks[i].setNumOfCollisions(x+1);
	}
	Paddle1 = new paddle;
	bricks->setBrick(bricks,numOfBricks);
	score = 0;
	balls = new ballPowerUp[2];
	Food = new food[25];
	Food->setNumOfFoods(25);
	balls->setNumOfFoods(2);
	// 0,1 for paddle length increase or decrease
	Food[0].setFactor(Paddle1->getPaddleLength()+ 1);
	cout << "DONE " << endl;
	Food[1].setFactor(-Paddle1->getPaddleLength()-1);
	// 2,3 for ball speed 
	Food[2].setFactor(6);
	Food[3].setFactor(-4);
	cout << "DONEl " << endl;
}
void ObjectsOfGame:: setLevel(string l)
{
	level = l;
}
string ObjectsOfGame:: getLevel()const

{
	return level;
}
const string& ObjectsOfGame::getGameCondition() const {

	return gameCondition;
}

void ObjectsOfGame::setGameCondition(const string &gameCondition) {
	this->gameCondition = gameCondition;
}

int ObjectsOfGame::getLives() const {
	return lives;
}

void ObjectsOfGame::setLives(int lives) {
	this->lives = lives;
}

int ObjectsOfGame::getScore() const {
	return score;
}

int ObjectsOfGame::getNumOfBricks() const {
	return numOfBricks;
}

void ObjectsOfGame::setNumOfBricks(int numOfBricks) {
	this->numOfBricks = numOfBricks;
}

void ObjectsOfGame::setScore(int score) {
	this->score = score;
}

int ObjectsOfGame::getScreenHeight() const {
	return screenHeight;
}

void ObjectsOfGame::setScreenHeight(int screenHeight) {
	this->screenHeight = screenHeight;
}

int ObjectsOfGame::getScreenWidth() const {
	return screenWidth;
}

void ObjectsOfGame:: setLevel2()
{
	lives = 2;
	numOfBricks = 20;
	// numOfBricks = 0;
	Paddle1->setYcor(50);
	bricks = new brick [numOfBricks];
	ball1.setXcor((screenWidth/2) - 150);
	ball1.setYcor(90);
	gameCondition = "S";
	ball1.setXFactor(abs(ball1.getXFactor()));
	ball1.setYFactor(abs(ball1.getYFactor()));
	Food->setNumOfFoods(40);
	balls->setNumOfFoods(2);
	int x = 0;
	srand(time(0));
	for (int i = 0; i < numOfBricks; i++)
	{
		x = rand()%5;
		bricks[i].setNumOfCollisions(1);
		bricks[i].setBrickWidth(140);
		bricks[i].setBrickHeight(25);
		bricks[i].setColor(colour[x]);
		bricks[i].setNumOfCollisions(x+1);
	}
	// set Level 2 bricks
	bricks->setLevel2Bricks(bricks,numOfBricks);

}
void ObjectsOfGame:: setLevel3()
{
	lives = 2;
	numOfBricks = 80;
	// numOfBricks = 0;
	Paddle1->setYcor(50);
	paddle2 = new paddle;
	paddle2->setYcor(screenHeight - 80);
	paddle2->setXcor((screenWidth-300)/2);
	paddle2->setSpeedFactor(10);
	bricks = new brick [numOfBricks];
	ball1.setXcor((screenWidth/2) - 150);
	ball1.setYcor(90);
	gameCondition = "S";
	ball1.setXFactor(abs(ball1.getXFactor()));
	ball1.setYFactor(abs(ball1.getYFactor()));
	Food->setNumOfFoods(40);
	balls->setNumOfFoods(2);
	int x = 0;
	srand(time(0));
	for (int i = 0; i < numOfBricks; i++)
	{
		x = rand()%5;
		bricks[i].setColor(colour[x]);
		bricks[i].setNumOfCollisions(x+1);
	}
	int i = 0;
	int j = screenHeight-200;
	bricks->setLevel3Bricks(bricks,i,0,j,numOfBricks);
}
void ObjectsOfGame::setLevel4()
{
	lives = 2;
	numOfBricks = 54;
	Paddle1->setYcor(50);
	bricks = new brick [numOfBricks];
	ball1.setXcor((screenWidth/2) - 150);
	ball1.setYcor(90);
	gameCondition = "S";
	ball1.setXFactor(abs(ball1.getXFactor()));
	ball1.setYFactor(abs(ball1.getYFactor()));
	Food->setNumOfFoods(40);
	balls->setNumOfFoods(2);
	int x = 0;
	srand(time(0));
	for (int i = 0; i < numOfBricks; i++)
	{
		x = rand()%5;
		bricks[i].setColor(colour[x]);
		bricks[i].setNumOfCollisions(x+1);
	}
	int i = 0;
	int j = screenHeight-250;
	bricks->setlevel4Bricks(bricks,numOfBricks);
}
void ObjectsOfGame::setScreenWidth(int screenWidth) {
	this->screenWidth = screenWidth;
}

bool ObjectsOfGame:: checkPaddleCollison(ball& ball1,paddle* Paddle1)
{
	if(Paddle1 != nullptr)
	{
		if (ball1.getYcor() - Paddle1->getYcor( ) >= 0 && (ball1.getYcor() - Paddle1->getYcor() <= Paddle1->getPaddleHeight() && ball1.getYcor()- Paddle1->getYcor() >= Paddle1->getPaddleHeight() - 10 )&& ((- Paddle1->getXcor() + ball1.getXcor() <= Paddle1->getPaddleLength())&& ball1.getXcor() -  Paddle1->getXcor() >= 0))
		{
			cout << "COLLIDE\n";
			int y1 = ball1.getXcor();
			int y2 = Paddle1->getXcor() + Paddle1->getPaddleLength();
			y2 = y2 - y1;
			if (y2  == Paddle1->getPaddleLength()/2 && ((y2 - (Paddle1->getPaddleLength())/2 >=0  && (y2 - Paddle1->getPaddleLength()))/2 <= 10))// ball hit in the middle
			{
				cout << "LOL" << endl;
				ball1.setYFactor(10);
				ball1.setXFactor(0);
			}
			else
			{
				// when the ball hits on the right side of paddle
				// sum of both factors will be equal to speed of the ball
				cout << "Paddle collision" << endl;
				cout << "else" << endl;
				if (y2 < Paddle1->getPaddleLength()/2 )
				{
					cout << "if" << endl;
					ball1.setYFactor((y2/ball1.getBallSpeed()) );
					if (ball1.getYFactor() > ball1.getBallSpeed())
					{
						ball1.setYFactor(ball1.getBallSpeed()-1);
					}
					ball1.setXFactor((ball1.getBallSpeed() - abs(ball1.getYFactor())));
					
				}
				// when hit on the left the xcordinate will be negative
				else if(y2 > Paddle1->getPaddleLength()/2)
				{
					cout << "else" << endl;
					ball1.setYFactor((Paddle1->getPaddleLength()-y2)/ball1.getBallSpeed());
					if (ball1.getYFactor() > ball1.getBallSpeed())
					{
						ball1.setYFactor(ball1.getBallSpeed()-1);
					}
					ball1.setXFactor((ball1.getBallSpeed() - abs(ball1.getYFactor())));
					ball1.setXFactor(-(ball1.getBallSpeed()- abs(ball1.getYFactor())));
				}
			}
			if (ball1.getYFactor() == 0)
			{
				ball1.setYFactor(1);
			}
			ball1.setXcor(ball1.getXcor() + ball1.getXFactor());
			ball1.setXcor(ball1.getXcor() + ball1.getXFactor());
			Paddle1->setColor(ball1.getColor());
			for (int  i = 2; i < Food->getNumOfFoods(); i++)
			{
				if (Food[i].getTimer() == 0.7)
				{
					Food[i].setTimer(0.5);
				}
			}
			return true;	
		}
	}
	return false;
}

void ObjectsOfGame:: checkBrickCollison(ball & ball1)
{
	for(int i =0; i < numOfBricks ;i++)
	{
		if ((ball1.getYcor() - bricks[i].getYcor() >=0 
			&&  ball1.getYcor() - bricks[i].getYcor() <= bricks[i].getBrickHeight()  ) && 
			( ball1.getXcor() - bricks[i].getXcor() >=0 && 
				ball1.getXcor() - bricks[i].getXcor() <= bricks[i].getBrickWidth()))
		{
			score += 5;
			if (ball1.getXcor() - bricks[i].getXcor() >= 10 && 
				ball1.getXcor() - bricks[i].getXcor() <= bricks[i].getBrickWidth() -10 )
			{
					cout << "Top or bottom" << endl;
				ball1.setYFactor(-ball1.getYFactor());
			}
			// the brick touches from right or left
			else
			{	

				cout << "Left or Right" << endl;
				ball1.setXFactor(-ball1.getXFactor());	
			}
			
			ball1.setColor(bricks[i].getColor());
			bricks[i].setNumOfCollisions(bricks[i].getNumOfCollisions()-1);
			if (bricks[i].getNumOfCollisions() <= 0)
			{
				if (bricks[i].getColor() != 4)
				{
					generatePowerUp(bricks[i]);	
				}
				bricks[i].setXcor(screenWidth+ screenHeight);
				bricks[i].setYcor(screenWidth+ screenHeight);
				bricks[i].setCheck(false);
			}
			ball1.setXcor(ball1.getXcor() + ball1.getXFactor());
			ball1.setXcor(ball1.getXcor() + ball1.getXFactor());
			i = getNumOfBricks();
		}	
	}
}

void  ObjectsOfGame :: generatePowerUp(brick& ptr)
{
	// first four are used for when the player takes the food
	int i = 4;
	while (i < Food->getNumOfFoods())
	{
		if (!Food[i].isCheck())
		{
			Food->setFood(Food[i],ptr);
			return ;
		}
		i++;
	}
	// resizing the food array
	if (i == Food->getNumOfFoods())
	{
		cout << "SEG" << endl;
		food* ptr2 ;
		ptr2 = Food;
		int x = Food->getNumOfFoods();
		Food = new food[x + 15];
		cout << "Fault" << endl;
		Food->setNumOfFoods(Food->getNumOfFoods()+15);
		int i = 0;
		while (i < ptr2->getNumOfFoods())
		{
			Food[i] = ptr2[i];
			i++;
		}
		delete[] ptr2;
	}
	Food->setFood(Food[i],ptr);
	return;
}
void ObjectsOfGame:: foodFunctions()
{
	Food->moveFood(Food);
	Food->removeFoodEffect(Food,ball1);
	// if the Paddle1 collides with the yellow food
	if(Food->checkFoodCollision(ball1,Paddle1,Food))
	{
		generateBallFood();
	}
	for (int i = 0; i < balls->getNumOfFoods(); i++)
	{
		if(balls[i].isCheck())
		{
			balls[i].Balls.moveBall();
			checkPaddleCollison(balls[i].Balls,Paddle1);
			if(checkPaddleCollison(balls[i].Balls,paddle2))
			{
				balls[i].Balls.setYFactor(-balls[i].Balls.getYFactor());
			}
			checkBrickCollison(balls[i].Balls);
			balls[i].setTimer(balls[i].getTimer() - 0.00159);
			if (balls[i].getTimer() <= 0 || balls[i].getYcor() <= 10)
			{
				balls[i].setXcor(100);
				balls[i].setYcor(100);
				balls[i].setTimer(-1);
				balls[i].setCheck(false);
			}
		}	
	}	
}
void ObjectsOfGame:: generateBallFood()
{
	int x = -10;
	for (int i = 0; i < balls->getNumOfFoods(); i++)
	{
		// if the food is not present on the screen
		if(((!balls[i].isCheck())) || (balls[i].getYcor() <= 5) || (balls[i].getTimer() <= 0))
		{
			balls[i].Balls.setXcor(ball1.getXcor() + x);
			balls[i].Balls.setYcor(ball1.getYcor()) ;
			balls[i].Balls.setBallSpeed(ball1.getBallSpeed());
			balls[i].Balls.setYFactor(abs(ball1.getYFactor()));
			balls[i].Balls.setColor(ball1.getColor());
			balls[i].Balls.setXFactor(-ball1.getXFactor());
			balls[i].setCheck(true);
			x = x - 10;
			if (i == 1)
			{
				balls[1].Balls.setXFactor(-ball1.getXFactor());
				balls[1].Balls.setYFactor(-ball1.getYFactor());
				balls[i].Balls.setYcor(ball1.getYcor()+( x/ 2)) ;
			}
			
		}
		balls[i].setTimer(0.5);

	}
}
void ObjectsOfGame:: Deallocation()
{
	if (numOfBricks > 0 )
		delete[] bricks;
	for (int i = 0; i < Food->getNumOfFoods(); i++)
	{
		Food[i].setCheck(false);
	}
	for (int i = 0; i < balls->getNumOfFoods(); i++)
	{
		balls[i].setCheck(false);
	}	
	Paddle1->setPaddleLength(140);
	ball1.setBallSpeed(12);
	
}
void ObjectsOfGame:: storeScore(int score,string fileName)
{
    ofstream file1;
    file1.open(fileName,ios:: app);
    if (!file1.is_open())
    {
        cout << "File is not present in the project folder" << endl;
        exit(0);
    }
    else
    {
        file1 << endl << score;
    }
    
}
void ObjectsOfGame:: gameCheck()
{
	if (ball1.getYcor() < Paddle1->getYcor() - 10 || ( paddle2 != nullptr && ball1.getYcor() > paddle2->getYcor() + 50 ))
	{
		for (int i = 0; i < balls->getNumOfFoods(); i++)
		{
			if (balls[i].isCheck())
			{
				cout << "DONE" << endl;
				ball1.setXcor(balls[i].Balls.getXcor());
				ball1.setYcor(balls[i].Balls.getXcor());
				balls[i].Balls.setYcor(0);
				balls[i].setCheck(false);
				return;
			}
		}
		setLives(getLives()-1);
		Paddle1->setYcor(50);
		ball1.setXcor((screenWidth/2) - 150);
		ball1.setYcor(90);
		ball1.setBallSpeed(12);
		ball1.setXFactor(5);
		ball1.setYFactor(5);
		gameCondition = "S";
	}
	bool check = false;
	for (int  i = 0; i < numOfBricks; i++)
	{
		if (bricks[i].getNumOfCollisions())
		{
			check = true;
		}
		
	}
	if (check == false &&  getLevel() == "Level 1")
	{
		setLevel("Level 2");
		Deallocation();
		setLevel2();
	}
	else if (check == false &&  getLevel() == "Level 2")
	{
		setLevel("Level 3");
		Deallocation();
		setLevel3();
	}
	else if (check == false && getLevel() == "Level 3")
	{
		paddle2 = nullptr;
		setLevel("Level 4");
		Deallocation();
		setLevel4();
	}
	else if(((check == false && getLevel() == "Level 4")))
	{
		gameCondition = "W";
		storeScore(score , "scores.txt");
	}
	if (lives == 0)
	{
		storeScore(score , "scores.txt");
		gameCondition = "E";
	}
	
}

string ObjectsOfGame:: toString(int num)
{
	string temp = "";
	if (num == 0 )
	{
		temp = "0";
	}
	
	else
		while (num)
		{
			temp = (char)((num%10)+48)  + temp;
			num /= 10;
		}
	return temp;
}
ObjectsOfGame::~ObjectsOfGame() 
{
	if (numOfBricks != 0)
	{

		delete[] bricks;
	}
	delete[] balls;
	delete[] Food;
	if (paddle2 != nullptr)
	{
		delete paddle2;
	}
}
