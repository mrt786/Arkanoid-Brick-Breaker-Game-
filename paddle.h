/*
 * paddle.h
 *
 *  Created on: Apr 30, 2024
 *      Author: rehan
 */

#ifndef PADDLE_H_
#define PADDLE_H_
#include "shape.h"
class paddle : public shape
{
	int speedFactor;
	int paddleLength;
	int paddleHeight;
public:
	paddle();
	virtual ~paddle();
	int getPaddleLength() const;
	void setPaddleLength(int paddleLength);
	int getPaddleHeight() const;
	void setPaddleHeight(int paddleLength);
	int getSpeedFactor() const;
	void setSpeedFactor(int speedFactor);
};

#endif /* PADDLE_H_ */
