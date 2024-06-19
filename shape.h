/*
 * shape.h
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#ifndef SHAPE_H_
#define SHAPE_H_
class shape
{
protected:
    int color;
    int xcor;
    int ycor;
    int screenWidth;
    int  screenHeight;
public:
    shape();
    void setXcor(int x);
    void setYcor(int y );
    int getYcor()const;
    int getXcor()const;
    ~shape();
	int getColor() const;
	void setColor(int c);
	int getScreenHeight() const;
	int getScreenWidth() const;
	void setScreenHeight(int screenHeight);
	void setScreenWidth(int screenWidth);
};
#endif /* SHAPE_H_ */
