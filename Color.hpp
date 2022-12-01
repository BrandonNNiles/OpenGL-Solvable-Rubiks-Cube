/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2022-10-06
 */
#ifndef CColor_H
#define CColor_H

#include <GL/glut.h>

class Color{

public:
	GLfloat r, g, b;
	Color(GLfloat red, GLfloat green, GLfloat blue){
		r = red;
		g = green;
		b = blue;
	}
};

#endif
