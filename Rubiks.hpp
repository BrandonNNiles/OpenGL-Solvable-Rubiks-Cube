/*
 *  Author: Brandon, Shawn, Joey
 */
#ifndef CRubiks_H
#define CRubiks_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"
#include "Color.hpp"

class Rubiks: public Shape {

protected:

	Color* Colors[6]; // 6 different colours
	GLint subface[6][9][4]; // 6 main faces, each with 9 sub-faces, each with 4 vertices
	GLfloat subVertex[56][3]; // 56 different vertices, each with an (x, y, z) coordinate


public:
	Color* faceColor[6][9];
	Rubiks();
	void draw();
	void drawFace(int i, int j);
	void rotateSide(GLint Face);

};

#endif
