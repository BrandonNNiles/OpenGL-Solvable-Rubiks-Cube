/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2022-10-06
 */
#ifndef CRubiks_H
#define CRubiks_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"
#include "Light.hpp"
#include "Color.hpp"

class Rubiks: public Shape {

protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceNormal[6][3];
	GLfloat vertexColor[8][3];
	GLfloat vertexNormal[8][3];
	GLfloat r, g, b; //unneeded?

	//modifications

	Color* Colors[6];
	GLint subface[6][9][4]; // 6 main faces, each with 9 sub-faces, each with 4 vertices
	GLfloat subVertex[56][3]; // 6 main faces, each with 9 sub-faces, each with 4 vertices


public:
	Color* faceColor[6][9];
	Rubiks();
	void draw();
	void drawFace(int i, int j);

	bool isFrontface(int faceindex, Camera camera);
	GLfloat getFaceShade(int faceindex, Light light);
	GLfloat getVertexShade(int vertexindex, Light light);
	void rotateSide(GLint Face);

};

#endif
