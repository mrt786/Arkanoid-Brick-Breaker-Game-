//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Programmer   : Muhammad Rehan Tariq AI-A 23I0034
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "ball.h"
#include "paddle.h"
#include "food.h"
#include "brick.h"
#include "ObjectsOfGame.h"
#include <iostream>
#include<string>

#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
ObjectsOfGame g1;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) 
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */
void GameDisplay()/**/{
	glClearColor(0.2f /* Red */, 0.2f /* Green */, 0.2f /* Blue */, 1.0f /* Alpha */);  // light grey
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawCircle(g1.ball1.getXcor(), g1.ball1.getYcor(), 10, colors[g1.ball1.getColor()]);
	DrawCircle(g1.ball1.getXcor(), g1.ball1.getYcor(), 5, colors[BLACK]);
	for (int i = 0; i < g1.getNumOfBricks(); i++)
	{
		if (g1.bricks[i].getCheck())
			DrawRectangle(g1.bricks[i].getXcor() + 5,g1.bricks[i].getYcor(),g1.bricks[i].getBrickWidth(),g1.bricks->getBrickHeight(),colors[g1.bricks[i].getColor()]);
			DrawRectangle(g1.bricks[i].getXcor() + 30,g1.bricks[i].getYcor() + 6,g1.bricks[i].getBrickWidth() - 60, g1.bricks[i].getBrickHeight() - 15 ,colors[BLACK]);
	
	}
	for (int i = 4; i < g1.Food->getNumOfFoods(); i++)
	{
		if (g1.Food[i].isCheck() == true)// if the food is present
		{
			int c = g1.Food[i].getColor();
			if (c == 30)
			{
				// for green power up
				DrawTriangle(g1.Food[i].getXcor(),g1.Food[i].getYcor(),g1.Food[i].getXcor()+30,g1.Food[i].getYcor(),g1.Food[i].getXcor()+15,g1.Food[i].getYcor()+15,colors[c]);
				g1.Food[i].setFoodWidth(g1.Food[i].getXcor() + 30);
			}
			else if (c == 87)
			{
				DrawSquare(g1.Food[i].getXcor(),g1.Food[i].getYcor(),20,colors[c]);
				g1.Food[i].setFoodWidth(g1.Food[i].getXcor() + 10);
			}
			else if (c == 68)
			{
				DrawCircle(g1.Food[i].getXcor(),g1.Food[i].getYcor(),10,colors[c]);
				g1.Food[i].setFoodWidth(g1.Food[i].getXcor() + 10);
			}
			else if (c == 5)
			{
				// make a rectangle
				DrawSquare(g1.Food[i].getXcor(),g1.Food[i].getYcor(),20,colors[c]);
				DrawSquare(g1.Food[i].getXcor()+18,g1.Food[i].getYcor(),20,colors[c]);
				g1.Food[i].setFoodWidth(g1.Food[i].getXcor() + 28);
			}
			else if(c == 22)
			{
				g1.Food[i].setFoodWidth(g1.Food[i].getXcor() + 10);
				DrawSquare(g1.Food[i].getXcor(),g1.Food[i].getYcor(),20,colors[c]);
			}
		}		
	}	
	DrawLine(g1.getScreenWidth()-300,0,g1.getScreenWidth()-300,g1.getScreenHeight(),5,colors[6]);
	DrawLine(0,0,0,g1.getScreenHeight(),5,colors[6]);
	DrawString(g1.getScreenWidth() - 295, 800, "Score: ", colors[MISTY_ROSE]);
	DrawString(g1.getScreenWidth() - 235, 800, g1.toString(g1.score), colors[MISTY_ROSE]);
	DrawString(g1.getScreenWidth() - 295, 770, "Lives: ", colors[MISTY_ROSE]);
	DrawString(g1.getScreenWidth() - 235, 770, g1.toString(g1.getLives()), colors[MISTY_ROSE]);
	DrawString(g1.getScreenWidth() - 295, 710, "Total Level: 4 ", colors[MISTY_ROSE]);
	// DrawString(g1.getScreenWidth() - 295, 740, "M.Rehan Tariq ", colors[MISTY_ROSE]);
	// DrawString(g1.getScreenWidth() - 295, 710, "23I-0034 ", colors[MISTY_ROSE]);
	DrawString(g1.getScreenWidth() - 295, 680, g1.getLevel(), colors[MISTY_ROSE]);
	DrawString(g1.getScreenWidth() - 295, 470, "INSTRUCTIONS: ", colors[MISTY_ROSE]);

	DrawLine(0,0,g1.getScreenWidth(),3,5,colors[6]);
	DrawLine(0,g1.getScreenHeight(),g1.getScreenWidth(),g1.getScreenHeight() ,10,colors[6]);
	
	DrawLine(g1.getScreenWidth(),0,g1.getScreenWidth(),g1.getScreenHeight(),5,colors[6]);
	if(g1.getGameCondition() == "S")
	{
		DrawString(g1.getScreenWidth() - 295, 440, "Press Space To Start Game ", colors[MISTY_ROSE]);
	}
	else if (g1.getGameCondition() == "Start")
	{
		DrawString(g1.getScreenWidth() - 295, 440, "Press p to pause Game ", colors[MISTY_ROSE]);
	}
	
	else if(g1.getGameCondition() == "Pause")
	{
		DrawString(g1.getScreenWidth() - 295, 440, "Press R To Resume Game ", colors[MISTY_ROSE]);
	}
	else if(g1.getGameCondition() == "E")
	{
		DrawString(g1.getScreenWidth() - 295, 440, "Press Esc To Exit Game.", colors[MISTY_ROSE]);
		DrawString(g1.getScreenWidth() - 295, 410, "You lost all lives.", colors[MISTY_ROSE]);
	}
	else if (g1.getGameCondition() == "W")
	{
		DrawString(g1.getScreenWidth() - 295, 440, "You Won the Game", colors[MISTY_ROSE]);
		DrawString(g1.getScreenWidth() - 295, 410, "Press Esc To Exit Game", colors[MISTY_ROSE]);

	}
	
	DrawRoundRect(g1.Paddle1->getXcor(), g1.Paddle1->getYcor(), g1.Paddle1->getPaddleLength(), 20, colors[g1.Paddle1->getColor()], 10);
	DrawRectangle(g1.Paddle1->getXcor()+ (g1.Paddle1->getPaddleLength())/4  + + 5,g1.Paddle1->getYcor() + 5 ,(g1.Paddle1->getPaddleLength())/2,g1.Paddle1->getPaddleHeight()/4+ 5,colors[BLACK]);
	if (g1.paddle2 != nullptr)
	{
		DrawRoundRect(g1.paddle2->getXcor(), g1.paddle2->getYcor(), g1.paddle2->getPaddleLength(), 20, colors[g1.paddle2->getColor()], 10);
		DrawRectangle(g1.paddle2->getXcor()+ (g1.paddle2->getPaddleLength())/4  + + 5,g1.paddle2->getYcor() + 5 ,(g1.paddle2->getPaddleLength())/2,g1.paddle2->getPaddleHeight()/4+ 5,colors[BLACK]);
	}
	
	for (int i = 0; i < g1.balls->getNumOfFoods(); i++)
	{
		if(g1.balls[i].isCheck())
		{
			DrawCircle(g1.balls[i].Balls.getXcor(), g1.balls[i].Balls.getYcor(), 10, colors[g1.balls[i].Balls.getColor()]);	
		}
	}
	glutSwapBuffers(); // do not modify this line..

}

void NonPrintableKeys(int key, int x, int y)
{
	if(g1.paddle2 != nullptr)
	{
		if (key == GLUT_KEY_LEFT &&  g1.paddle2->getXcor() > 0/*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
		{
			g1.paddle2->setXcor(g1.paddle2->getXcor()- g1.paddle2->getSpeedFactor() );
			// what to do when left key is pressed...
		}
		else if (key == GLUT_KEY_RIGHT  && g1.paddle2->getXcor() + g1.paddle2->getPaddleLength() < (g1.getScreenWidth())-300/*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
		{
				g1.paddle2->setXcor(g1.paddle2->getXcor() + g1.paddle2->getSpeedFactor() );
		}
		else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
		{

		}

		else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) 
		{

		}
	}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) 
{
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (g1.getLives() > 0)
	{
		if (key == 32)
		{
			g1.setGameCondition("Start");
		}
		// ascii for R
		else if (key == 82 || key == 114)
		{
			g1.setGameCondition("Start");
		}
		// ascii for p
		else if (key == 80 || key == 112)
		{
			g1.setGameCondition("Pause");
		}
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m)
{

	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS
	if(g1.getGameCondition() == "Start")
	{
			g1.ball1.moveBall();	
			g1.gameCheck();
			g1.checkPaddleCollison(g1.ball1,g1.Paddle1);
			g1.checkBrickCollison(g1.ball1);
			g1.foodFunctions();
	}
	// for paddle 3
	if(g1.getLevel() == "level 3")
	{
		g1.paddle2->setColor(g1.Paddle1->getColor());
		g1.paddle2->setPaddleLength(g1.Paddle1->getPaddleLength());
		if (g1.paddle2->getXcor() + g1.paddle2->getPaddleLength() > g1.getScreenWidth()-300)
		{
			g1.paddle2->setXcor(g1.getScreenWidth()-300 - g1.paddle2->getPaddleLength() );
		}
		if(g1.checkPaddleCollison(g1.ball1,g1.paddle2))
		{
			g1.ball1.setYFactor(-g1.ball1.getYFactor());
		}
		
	}
	glutPostRedisplay();
		// glutTimerFunc(10, Timer, 0);
	glutTimerFunc(80/FPS, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) 
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) 
{
	if(g1.getGameCondition() == "Start")
	{
		if (x + g1.Paddle1->getPaddleLength() < g1.getScreenWidth() - 300 && x >= 0)
		{
			g1.Paddle1->setXcor(x);
		}
		else if (x+g1.Paddle1->getPaddleLength() > g1.getScreenWidth() - 300)
		{
			g1.Paddle1->setXcor(g1.getScreenWidth() - 300 - g1.Paddle1->getPaddleLength());
		}
		
	}
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char *argv[]) {

	int width = 1400, height = 840; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rehan's OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	GameDisplay();
	// glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	 glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	 glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000, Timer, 0);
//	 glutMouseFunc(MouseClicked);
	 glutPassiveMotionFunc(MouseMoved); // Mouse
//	 glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */

