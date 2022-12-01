/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2022-10-03 (update)
 */
#include "Rubiks.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include <stdio.h>

extern Camera myCamera;
extern Light myLight;
extern CullMode cullMode;
extern RenderMode renderMode;

Rubiks::Rubiks()
{
    vertex[0][0] = -1; vertex[0][1] = -1; vertex[0][2] = -1;
    vertex[1][0] = -1; vertex[1][1] = 1;  vertex[1][2] = -1;
    vertex[2][0] = 1;  vertex[2][1] = 1;  vertex[2][2] = -1;
    vertex[3][0] = 1;  vertex[3][1] = -1; vertex[3][2] = -1;
    vertex[4][0] = -1; vertex[4][1] = -1; vertex[4][2] = 1;
    vertex[5][0] = -1; vertex[5][1] = 1;  vertex[5][2] = 1;
    vertex[6][0] = 1;  vertex[6][1] = 1;  vertex[6][2] = 1;
    vertex[7][0] = 1;  vertex[7][1] = -1; vertex[7][2] = 1;

    face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
    face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
    face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
    face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
    face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
    face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;

	faceNormal[0][0] =  0.0, faceNormal[0][1] =  0.0, faceNormal[0][2] = -1.0,
	faceNormal[1][0] =  0.0, faceNormal[1][1] =  0.0, faceNormal[1][2] =  1.0;
	faceNormal[2][0] = -1.0, faceNormal[2][1] =  0.0, faceNormal[2][2] =  0.0;
	faceNormal[3][0] =  0.0, faceNormal[3][1] =  1.0, faceNormal[3][2] =  0.0;
	faceNormal[4][0] =  1.0, faceNormal[4][1] =  0.0, faceNormal[4][2] =  0.0;
	faceNormal[5][0] =  0.0, faceNormal[5][1] = -1.0, faceNormal[5][2] =  0.0;

	vertexColor[0][0] = 1.0, vertexColor[0][1] = 0.0; vertexColor[0][2] = 0.0;
	vertexColor[1][0] = 0.0, vertexColor[1][1] = 1.0; vertexColor[1][2] = 0.0;
	vertexColor[2][0] = 0.0, vertexColor[2][1] = 0.0; vertexColor[2][2] = 1.0;
	vertexColor[3][0] = 1.0, vertexColor[3][1] = 1.0; vertexColor[3][2] = 0.0;
	vertexColor[4][0] = 1.0, vertexColor[4][1] = 0.0; vertexColor[4][2] = 1.0;
	vertexColor[5][0] = 0.0, vertexColor[5][1] = 1.0; vertexColor[5][2] = 1.0;
	vertexColor[6][0] = 0.5, vertexColor[6][1] = 0.5; vertexColor[6][2] = 0.5;
	vertexColor[7][0] = 0.0, vertexColor[7][1] = 0.0; vertexColor[7][2] = 0.0;

    vertexNormal[0][0] = -1; vertexNormal[0][1] = -1; vertexNormal[0][2] = -1;
    vertexNormal[1][0] = -1; vertexNormal[1][1] = 1;  vertexNormal[1][2] = -1;
    vertexNormal[2][0] = 1;  vertexNormal[2][1] = 1;  vertexNormal[2][2] = -1;
    vertexNormal[3][0] = 1;  vertexNormal[3][1] = -1; vertexNormal[3][2] = -1;
    vertexNormal[4][0] = -1; vertexNormal[4][1] = -1; vertexNormal[4][2] = 1;
    vertexNormal[5][0] = -1; vertexNormal[5][1] = 1;  vertexNormal[5][2] = 1;
    vertexNormal[6][0] = 1;  vertexNormal[6][1] = 1;  vertexNormal[6][2] = 1;
    vertexNormal[7][0] = 1;  vertexNormal[7][1] = -1; vertexNormal[7][2] = 1;

    r = 1.0;
    g = 0.0;
    b = 0.0;

    //new

    //W
    subVertex[0][0] = 0; subVertex[0][1] = 3; subVertex[0][2] = 0;
	subVertex[1][0] = 1; subVertex[1][1] = 3;  subVertex[1][2] = 0;
	subVertex[2][0] = 2;  subVertex[2][1] = 3;  subVertex[2][2] = 0;
	subVertex[3][0] = 3;  subVertex[3][1] = 3; subVertex[3][2] = 0;
	subVertex[4][0] = 0; subVertex[4][1] = 2; subVertex[4][2] = 0;
	subVertex[5][0] = 1; subVertex[5][1] = 2;  subVertex[5][2] = 0;
	subVertex[6][0] = 2;  subVertex[6][1] = 2;  subVertex[6][2] = 0;
	subVertex[7][0] = 3;  subVertex[7][1] = 2; subVertex[7][2] = 0;
	subVertex[8][0] = 0; subVertex[0][1] = 1; subVertex[0][2] = 0;
	subVertex[9][0] = 1; subVertex[1][1] = 1;  subVertex[1][2] = 0;
	subVertex[10][0] = 2;  subVertex[2][1] = 1;  subVertex[2][2] = 0;
	subVertex[11][0] = 3;  subVertex[3][1] = 1; subVertex[3][2] = 0;
	subVertex[12][0] = 0; subVertex[4][1] = 0; subVertex[4][2] = 0;
	subVertex[13][0] = 1; subVertex[5][1] = 0;  subVertex[5][2] = 0;
	subVertex[14][0] = 2;  subVertex[6][1] = 0;  subVertex[6][2] = 0;
	subVertex[15][0] = 3;  subVertex[7][1] = 0; subVertex[7][2] = 0;

	//Y
	subVertex[16][0] = 3; subVertex[0][1] = 3; subVertex[0][2] = 3;
	subVertex[17][0] = 2; subVertex[1][1] = 3;  subVertex[1][2] = 3;
	subVertex[18][0] = 1;  subVertex[2][1] = 3;  subVertex[2][2] = 3;
	subVertex[19][0] = 0;  subVertex[3][1] = 3; subVertex[3][2] = 3;
	subVertex[20][0] = 3; subVertex[4][1] = 2; subVertex[4][2] = 3;
	subVertex[21][0] = 2; subVertex[5][1] = 2;  subVertex[5][2] = 3;
	subVertex[22][0] = 1;  subVertex[6][1] = 2;  subVertex[6][2] = 3;
	subVertex[23][0] = 0;  subVertex[7][1] = 2; subVertex[7][2] = 3;
	subVertex[24][0] = 3; subVertex[0][1] = 1; subVertex[0][2] = 3;
	subVertex[25][0] = 2; subVertex[1][1] = 1;  subVertex[1][2] = 3;
	subVertex[26][0] = 1;  subVertex[2][1] = 1;  subVertex[2][2] = 3;
	subVertex[27][0] = 0;  subVertex[3][1] = 1; subVertex[3][2] = 3;
	subVertex[28][0] = 3; subVertex[4][1] = -1; subVertex[4][2] = 3;
	subVertex[29][0] = 2; subVertex[5][1] = 1;  subVertex[5][2] = 3;
	subVertex[30][0] = 1;  subVertex[6][1] = 1;  subVertex[6][2] = 3;
	subVertex[31][0] = 0;  subVertex[7][1] = -1; subVertex[7][2] = 3;

	//B
	subVertex[32][0] = 3; subVertex[0][1] = 3; subVertex[0][2] = 1;
	subVertex[33][0] = 3; subVertex[1][1] = 3;  subVertex[1][2] = 2;
	subVertex[34][0] = 3;  subVertex[2][1] = 2;  subVertex[2][2] = 1;
	subVertex[35][0] = 3;  subVertex[3][1] = 2; subVertex[3][2] = 2;
	subVertex[36][0] = 3; subVertex[4][1] = 1; subVertex[4][2] = 1;
	subVertex[37][0] = 3; subVertex[5][1] = 1;  subVertex[5][2] = 2;
	subVertex[38][0] = 3;  subVertex[6][1] = 0;  subVertex[6][2] = 1;
	subVertex[39][0] = 3;  subVertex[7][1] = 0; subVertex[7][2] = 2;

	//G
	subVertex[40][0] = 0; subVertex[0][1] = 3; subVertex[0][2] = 2;
	subVertex[41][0] = 0; subVertex[1][1] = 3;  subVertex[1][2] = 1;
	subVertex[42][0] = 0;  subVertex[2][1] = 2;  subVertex[2][2] = 2;
	subVertex[43][0] = 0;  subVertex[3][1] = 2; subVertex[3][2] = 1;
	subVertex[44][0] = 0; subVertex[4][1] = 1; subVertex[4][2] = 2;
	subVertex[45][0] = 0; subVertex[5][1] = 1;  subVertex[5][2] = 1;
	subVertex[46][0] = 0;  subVertex[6][1] = 0;  subVertex[6][2] = 2;
	subVertex[47][0] = 0;  subVertex[7][1] = 0; subVertex[7][2] = 1;

	//O
	subVertex[48][0] = 1;  subVertex[7][1] = 3; subVertex[7][2] = 2;
	subVertex[49][0] = 2; subVertex[0][1] = 3; subVertex[0][2] = 2;
	subVertex[50][0] = 1; subVertex[1][1] = 3;  subVertex[1][2] = 1;
	subVertex[51][0] = 2;  subVertex[2][1] = 3;  subVertex[2][2] = 1;

	//R
	subVertex[52][0] = 1;  subVertex[3][1] = 0; subVertex[3][2] = 1;
	subVertex[53][0] = 2; subVertex[4][1] = 0; subVertex[4][2] = 1;
	subVertex[54][0] = 1; subVertex[5][1] = 0;  subVertex[5][2] = 2;
	subVertex[55][0] = 2;  subVertex[6][1] = 0;  subVertex[6][2] = 2;


	//Color reference INTS
	W = 0;
	Y = 1;
	B = 2;
	O = 3;
	G = 4;
	R = 5;

	//define color list
    Colors[W] = new Color(1.0, 1.0, 1.0); //white
    Colors[Y] = new Color(1.0, 1.0, 0.0); //yellow
    Colors[B] = new Color(0.0, 0.0, 1.0); //blue
    Colors[O] = new Color(1.0, 0.647, 0.0); //orange
    Colors[G] = new Color(0.0, 1.0, 0.0); //green
    Colors[R] = new Color(1.0, 0.0, 0.0); //red

    // initialize colors
    for(int i = 0; i < 6; i++){
    	for(int j = 0; j < 9; j++){
    		faceColor[i][j] = Colors[i];
    	}
    }

    //Define subfaces


    //White
    subface[W][0][0] = 0; subface[W][0][1] = 1; subface[W][0][2] = 4; subface[W][0][3] = 5;
    subface[W][1][0] = 1; subface[W][1][1] = 2; subface[W][1][2] = 5; subface[W][1][3] = 6;
    subface[W][2][0] = 2; subface[W][2][1] = 3; subface[W][2][2] = 6; subface[W][2][3] = 7;
    subface[W][3][0] = 4; subface[W][3][1] = 5; subface[W][3][2] = 8; subface[W][3][3] = 9;
    subface[W][4][0] = 5; subface[W][4][1] = 6; subface[W][4][2] = 9; subface[W][4][3] = 10;
    subface[W][5][0] = 6; subface[W][5][1] = 7; subface[W][5][2] = 10; subface[W][5][3] = 11;
    subface[W][6][0] = 8; subface[W][6][1] = 9; subface[W][6][2] = 12; subface[W][6][3] = 13;
    subface[W][7][0] = 9; subface[W][7][1] = 10; subface[W][7][2] = 13; subface[W][7][3] = 14;
    subface[W][8][0] = 10; subface[W][8][1] = 11; subface[W][8][2] = 14; subface[W][8][3] = 15;

    //Yellow
    subface[Y][0][0] = 16; subface[Y][0][1] = 17; subface[Y][0][2] = 20; subface[Y][0][3] = 21;
    subface[Y][1][0] = 17; subface[Y][1][1] = 18; subface[Y][1][2] = 21; subface[Y][1][3] = 22;
    subface[Y][2][0] = 18; subface[Y][2][1] = 19; subface[Y][2][2] = 22; subface[Y][2][3] = 23;
    subface[Y][3][0] = 20; subface[Y][3][1] = 21; subface[Y][3][2] = 24; subface[Y][3][3] = 25;
    subface[Y][4][0] = 21; subface[Y][4][1] = 22; subface[Y][4][2] = 25; subface[Y][4][3] = 26;
    subface[Y][5][0] = 22; subface[Y][5][1] = 23; subface[Y][5][2] = 26; subface[Y][5][3] = 27;
    subface[Y][6][0] = 24; subface[Y][6][1] = 25; subface[Y][6][2] = 28; subface[Y][6][3] = 29;
    subface[Y][7][0] = 25; subface[Y][7][1] = 26; subface[Y][7][2] = 29; subface[Y][7][3] = 30;
    subface[Y][8][0] = 26; subface[Y][8][1] = 27; subface[Y][8][2] = 30; subface[Y][8][3] = 31;

    //Blue
    subface[B][0][0] = 0; subface[B][0][1] = 1; subface[B][0][2] = 2; subface[B][0][3] = 3;
    subface[B][1][0] = 0; subface[B][1][1] = 1; subface[B][1][2] = 2; subface[B][1][3] = 3;
    subface[B][2][0] = 0; subface[B][2][1] = 1; subface[B][2][2] = 2; subface[B][2][3] = 3;
    subface[B][3][0] = 0; subface[B][3][1] = 1; subface[B][3][2] = 2; subface[B][3][3] = 3;
    subface[B][4][0] = 0; subface[B][4][1] = 1; subface[B][4][2] = 2; subface[B][4][3] = 3;
    subface[B][5][0] = 0; subface[B][5][1] = 1; subface[B][5][2] = 2; subface[B][5][3] = 3;
    subface[B][6][0] = 0; subface[B][6][1] = 1; subface[B][6][2] = 2; subface[B][6][3] = 3;
    subface[B][7][0] = 0; subface[B][7][1] = 1; subface[B][7][2] = 2; subface[B][7][3] = 3;
    subface[B][8][0] = 0; subface[B][8][1] = 1; subface[B][8][2] = 2; subface[B][8][3] = 3;

    //Orange
    subface[O][0][0] = 0; subface[O][0][1] = 1; subface[O][0][2] = 2; subface[O][0][3] = 3;
    subface[O][1][0] = 0; subface[O][1][1] = 1; subface[O][1][2] = 2; subface[O][1][3] = 3;
    subface[O][2][0] = 0; subface[O][2][1] = 1; subface[O][2][2] = 2; subface[O][2][3] = 3;
    subface[O][3][0] = 0; subface[O][3][1] = 1; subface[O][3][2] = 2; subface[O][3][3] = 3;
    subface[O][4][0] = 0; subface[O][4][1] = 1; subface[O][4][2] = 2; subface[O][4][3] = 3;
    subface[O][5][0] = 0; subface[O][5][1] = 1; subface[O][5][2] = 2; subface[O][5][3] = 3;
    subface[O][6][0] = 0; subface[O][6][1] = 1; subface[O][6][2] = 2; subface[O][6][3] = 3;
    subface[O][7][0] = 0; subface[O][7][1] = 1; subface[O][7][2] = 2; subface[O][7][3] = 3;
    subface[O][8][0] = 0; subface[O][8][1] = 1; subface[O][8][2] = 2; subface[O][8][3] = 3;

    //Green
    subface[G][0][0] = 0; subface[G][0][1] = 1; subface[G][0][2] = 2; subface[G][0][3] = 3;
    subface[G][1][0] = 0; subface[G][1][1] = 1; subface[G][1][2] = 2; subface[G][1][3] = 3;
    subface[G][2][0] = 0; subface[G][2][1] = 1; subface[G][2][2] = 2; subface[G][2][3] = 3;
    subface[G][3][0] = 0; subface[G][3][1] = 1; subface[G][3][2] = 2; subface[G][3][3] = 3;
    subface[G][4][0] = 0; subface[G][4][1] = 1; subface[G][4][2] = 2; subface[G][4][3] = 3;
    subface[G][5][0] = 0; subface[G][5][1] = 1; subface[G][5][2] = 2; subface[G][5][3] = 3;
    subface[G][6][0] = 0; subface[G][6][1] = 1; subface[G][6][2] = 2; subface[G][6][3] = 3;
    subface[G][7][0] = 0; subface[G][7][1] = 1; subface[G][7][2] = 2; subface[G][7][3] = 3;
    subface[G][8][0] = 0; subface[G][8][1] = 1; subface[G][8][2] = 2; subface[G][8][3] = 3;

    //Red
    subface[R][0][0] = 0; subface[R][0][1] = 1; subface[R][0][2] = 2; subface[R][0][3] = 3;
    subface[R][1][0] = 0; subface[R][1][1] = 1; subface[R][1][2] = 2; subface[R][1][3] = 3;
    subface[R][2][0] = 0; subface[R][2][1] = 1; subface[R][2][2] = 2; subface[R][2][3] = 3;
    subface[R][3][0] = 0; subface[R][3][1] = 1; subface[R][3][2] = 2; subface[R][3][3] = 3;
    subface[R][4][0] = 0; subface[R][4][1] = 1; subface[R][4][2] = 2; subface[R][4][3] = 3;
    subface[R][5][0] = 0; subface[R][5][1] = 1; subface[R][5][2] = 2; subface[R][5][3] = 3;
    subface[R][6][0] = 0; subface[R][6][1] = 1; subface[R][6][2] = 2; subface[R][6][3] = 3;
    subface[R][7][0] = 0; subface[R][7][1] = 1; subface[R][7][2] = 2; subface[R][7][3] = 3;
    subface[R][8][0] = 0; subface[R][8][1] = 1; subface[R][8][2] = 2; subface[R][8][3] = 3;







}

void Rubiks::drawFace(int i, int j)
{
	GLfloat shade = 1, shade1=1, shade2=1, shade3=1;

	switch (renderMode) {
	case WIRE:
	   glColor3f(r, g, b);
	   glBegin(GL_LINE_LOOP);
	   glVertex3fv(vertex[face[i][0]]);
       glVertex3fv(vertex[face[i][1]]);
       glVertex3fv(vertex[face[i][2]]);
       glVertex3fv(vertex[face[i][3]]);
       glEnd();
	   break;
	case CONSTANT:
	  if (myLight.on == true) {
	    shade = getFaceShade(i, myLight);
	  }
	   glColor3f(faceColor[i][j]->r*shade, faceColor[i][j]->g*shade, faceColor[i][j]->b*shade);
	   glBegin(GL_POLYGON);
	   glVertex3fv(vertex[face[i][0]]);
	   glVertex3fv(vertex[face[i][1]]);
	   glVertex3fv(vertex[face[i][2]]);
	   glVertex3fv(vertex[face[i][3]]);
	   glEnd();
	  break;
	case FLAT:
		// your code
	   break;
	case SMOOTH:
		// your code
	   break;
	case PHONE:
		// your
	   break;
	case TEXTURE:
		// your code

		break;
	}
}

void Rubiks::draw()
{
	glPushMatrix();
    this->ctmMultiply();
    glScalef(s, s, s);

	for (int i = 0; i < 6; i++) {
		for(int j = 0; j < 9; j++){

			if  (cullMode == BACKFACE ) {
				if (isFrontface(i, myCamera)) {
					drawFace(i, j);
				}
			}
			else {
				drawFace(i, j);
			}
		}
	}
    glPopMatrix();
}


bool Rubiks::isFrontface(int faceindex, Camera camera) {
	GLfloat v[4];
	v[0] = faceNormal[faceindex][0];
	v[1] = faceNormal[faceindex][1];
	v[2] = faceNormal[faceindex][2];
	v[3] = 0.0;
	mc.multiplyVector(v);
	if (pmc != NULL) {
		pmc->multiplyVector(v);
		return (pmc->mat[0][3] - camera.eye.x) * v[0] + (pmc->mat[1][3] - camera.eye.y) * v[1] + (pmc->mat[2][3] - camera.eye.z) * v[2] < 0;
	} else {
		return (mc.mat[0][3] - camera.eye.x) * v[0] + (mc.mat[1][3] - camera.eye.y) * v[1] + (mc.mat[2][3] - camera.eye.z) * v[2] < 0;
	}
}

GLfloat Rubiks::getFaceShade(int faceindex, Light light) {
	GLfloat shade = 1, v[4], s[4], temp;


	return shade;
}


GLfloat Rubiks::getVertexShade(int i, Light light) {
	GLfloat shade = 1, v[4], s[4], temp;

	return shade;
}



