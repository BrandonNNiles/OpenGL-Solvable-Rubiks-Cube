/*
 *  Author: Brandon, Shawn, Joey
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
