/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2022-10-03 (update)
 */
#include "Rubiks.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include <stdio.h>
#include "Menu.hpp"
#include "stack.hpp"

#include<windows.h>

extern Camera myCamera;
extern Light myLight;
extern CullMode cullMode;
extern RenderMode renderMode;
Stack theStack;
//Color reference INTS
const GLint W = 0;
const GLint Y = 1;
const GLint B = 2;
const GLint O = 3;
const GLint G = 4;
const GLint R = 5;



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
    subVertex[0][0] = 0;   subVertex[0][1] = 3;   subVertex[0][2] = 0;
	subVertex[1][0] = 1;   subVertex[1][1] = 3;   subVertex[1][2] = 0;
	subVertex[2][0] = 2;   subVertex[2][1] = 3;   subVertex[2][2] = 0;
	subVertex[3][0] = 3;   subVertex[3][1] = 3;   subVertex[3][2] = 0;
	subVertex[4][0] = 0;   subVertex[4][1] = 2;   subVertex[4][2] = 0;
	subVertex[5][0] = 1;   subVertex[5][1] = 2;   subVertex[5][2] = 0;
	subVertex[6][0] = 2;   subVertex[6][1] = 2;   subVertex[6][2] = 0;
	subVertex[7][0] = 3;   subVertex[7][1] = 2;   subVertex[7][2] = 0;
	subVertex[8][0] = 0;   subVertex[8][1] = 1;   subVertex[8][2] = 0;
	subVertex[9][0] = 1;   subVertex[9][1] = 1;   subVertex[9][2] = 0;
	subVertex[10][0] = 2;  subVertex[10][1] = 1;  subVertex[10][2] = 0;
	subVertex[11][0] = 3;  subVertex[11][1] = 1;  subVertex[11][2] = 0;
	subVertex[12][0] = 0;  subVertex[12][1] = 0;  subVertex[12][2] = 0;
	subVertex[13][0] = 1;  subVertex[13][1] = 0;  subVertex[13][2] = 0;
	subVertex[14][0] = 2;  subVertex[14][1] = 0;  subVertex[14][2] = 0;
	subVertex[15][0] = 3;  subVertex[15][1] = 0;  subVertex[15][2] = 0;

	//Y
	subVertex[16][0] = 3;  subVertex[16][1] = 3;  subVertex[16][2] = 3;
	subVertex[17][0] = 2;  subVertex[17][1] = 3;  subVertex[17][2] = 3;
	subVertex[18][0] = 1;  subVertex[18][1] = 3;  subVertex[18][2] = 3;
	subVertex[19][0] = 0;  subVertex[19][1] = 3;  subVertex[19][2] = 3;
	subVertex[20][0] = 3;  subVertex[20][1] = 2;  subVertex[20][2] = 3;
	subVertex[21][0] = 2;  subVertex[21][1] = 2;  subVertex[21][2] = 3;
	subVertex[22][0] = 1;  subVertex[22][1] = 2;  subVertex[22][2] = 3;
	subVertex[23][0] = 0;  subVertex[23][1] = 2;  subVertex[23][2] = 3;
	subVertex[24][0] = 3;  subVertex[24][1] = 1;  subVertex[24][2] = 3;
	subVertex[25][0] = 2;  subVertex[25][1] = 1;  subVertex[25][2] = 3;
	subVertex[26][0] = 1;  subVertex[26][1] = 1;  subVertex[26][2] = 3;
	subVertex[27][0] = 0;  subVertex[27][1] = 1;  subVertex[27][2] = 3;
	subVertex[28][0] = 3;  subVertex[28][1] = 0; subVertex[28][2] = 3;
	subVertex[29][0] = 2;  subVertex[29][1] = 0;  subVertex[29][2] = 3;
	subVertex[30][0] = 1;  subVertex[30][1] = 0;  subVertex[30][2] = 3;
	subVertex[31][0] = 0;  subVertex[31][1] = 0; subVertex[31][2] = 3;

	//B
	subVertex[32][0] = 3;  subVertex[32][1] = 3;  subVertex[32][2] = 1;
	subVertex[33][0] = 3;  subVertex[33][1] = 3;  subVertex[33][2] = 2;
	subVertex[34][0] = 3;  subVertex[34][1] = 2;  subVertex[34][2] = 1;
	subVertex[35][0] = 3;  subVertex[35][1] = 2;  subVertex[35][2] = 2;
	subVertex[36][0] = 3;  subVertex[36][1] = 1;  subVertex[36][2] = 1;
	subVertex[37][0] = 3;  subVertex[37][1] = 1;  subVertex[37][2] = 2;
	subVertex[38][0] = 3;  subVertex[38][1] = 0;  subVertex[38][2] = 1;
	subVertex[39][0] = 3;  subVertex[39][1] = 0;  subVertex[39][2] = 2;

	//G
	subVertex[40][0] = 0;  subVertex[40][1] = 3;  subVertex[40][2] = 2;
	subVertex[41][0] = 0;  subVertex[41][1] = 3;  subVertex[41][2] = 1;
	subVertex[42][0] = 0;  subVertex[42][1] = 2;  subVertex[42][2] = 2;
	subVertex[43][0] = 0;  subVertex[43][1] = 2;  subVertex[43][2] = 1;
	subVertex[44][0] = 0;  subVertex[44][1] = 1;  subVertex[44][2] = 2;
	subVertex[45][0] = 0;  subVertex[45][1] = 1;  subVertex[45][2] = 1;
	subVertex[46][0] = 0;  subVertex[46][1] = 0;  subVertex[46][2] = 2;
	subVertex[47][0] = 0;  subVertex[47][1] = 0;  subVertex[47][2] = 1;

	//O
	subVertex[48][0] = 1;  subVertex[48][1] = 3;  subVertex[48][2] = 2;
	subVertex[49][0] = 2;  subVertex[49][1] = 3;  subVertex[49][2] = 2;
	subVertex[50][0] = 1;  subVertex[50][1] = 3;  subVertex[50][2] = 1;
	subVertex[51][0] = 2;  subVertex[51][1] = 3;  subVertex[51][2] = 1;

	//R
	subVertex[52][0] = 1;  subVertex[52][1] = 0;  subVertex[52][2] = 1;
	subVertex[53][0] = 2;  subVertex[53][1] = 0;  subVertex[53][2] = 1;
	subVertex[54][0] = 1;  subVertex[54][1] = 0;  subVertex[54][2] = 2;
	subVertex[55][0] = 2;  subVertex[55][1] = 0;  subVertex[55][2] = 2;


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
    subface[B][0][0] = 3; subface[B][0][1] = 32; subface[B][0][2] = 7; subface[B][0][3] = 34;
    subface[B][1][0] = 32; subface[B][1][1] = 33; subface[B][1][2] = 34; subface[B][1][3] = 35;
    subface[B][2][0] = 33; subface[B][2][1] = 16; subface[B][2][2] = 35; subface[B][2][3] = 20;
    subface[B][3][0] = 7; subface[B][3][1] = 34; subface[B][3][2] = 11; subface[B][3][3] = 36;
    subface[B][4][0] = 34; subface[B][4][1] = 35; subface[B][4][2] = 36; subface[B][4][3] = 37;
    subface[B][5][0] = 35; subface[B][5][1] = 20; subface[B][5][2] = 37; subface[B][5][3] = 24;
    subface[B][6][0] = 11; subface[B][6][1] = 36; subface[B][6][2] = 15; subface[B][6][3] = 38;
    subface[B][7][0] = 36; subface[B][7][1] = 37; subface[B][7][2] = 38; subface[B][7][3] = 39;
    subface[B][8][0] = 37; subface[B][8][1] = 24; subface[B][8][2] = 39; subface[B][8][3] = 28;

    //Orange
    subface[O][0][0] = 19; subface[O][0][1] = 18; subface[O][0][2] = 40; subface[O][0][3] = 48;
    subface[O][1][0] = 18; subface[O][1][1] = 17; subface[O][1][2] = 48; subface[O][1][3] = 49;
    subface[O][2][0] = 17; subface[O][2][1] = 16; subface[O][2][2] = 49; subface[O][2][3] = 33;
    subface[O][3][0] = 40; subface[O][3][1] = 48; subface[O][3][2] = 41; subface[O][3][3] = 50;
    subface[O][4][0] = 48; subface[O][4][1] = 49; subface[O][4][2] = 50; subface[O][4][3] = 51;
    subface[O][5][0] = 49; subface[O][5][1] = 33; subface[O][5][2] = 51; subface[O][5][3] = 32;
    subface[O][6][0] = 41; subface[O][6][1] = 50; subface[O][6][2] = 0; subface[O][6][3] = 1;
    subface[O][7][0] = 50; subface[O][7][1] = 51; subface[O][7][2] = 1; subface[O][7][3] = 2;
    subface[O][8][0] = 51; subface[O][8][1] = 32; subface[O][8][2] = 2; subface[O][8][3] = 3;

    //Green
    subface[G][0][0] = 19; subface[G][0][1] = 40; subface[G][0][2] = 23; subface[G][0][3] = 42;
    subface[G][1][0] = 40; subface[G][1][1] = 41; subface[G][1][2] = 42; subface[G][1][3] = 43;
    subface[G][2][0] = 41; subface[G][2][1] = 0; subface[G][2][2] = 43; subface[G][2][3] = 4;
    subface[G][3][0] = 23; subface[G][3][1] = 42; subface[G][3][2] = 27; subface[G][3][3] = 44;
    subface[G][4][0] = 42; subface[G][4][1] = 43; subface[G][4][2] = 44; subface[G][4][3] = 45;
    subface[G][5][0] = 43; subface[G][5][1] = 4; subface[G][5][2] = 45; subface[G][5][3] = 8;
    subface[G][6][0] = 27; subface[G][6][1] = 44; subface[G][6][2] = 31; subface[G][6][3] = 46;
    subface[G][7][0] = 44; subface[G][7][1] = 45; subface[G][7][2] = 46; subface[G][7][3] = 47;
    subface[G][8][0] = 45; subface[G][8][1] = 8; subface[G][8][2] = 47; subface[G][8][3] = 12;

    //Red
    subface[R][0][0] = 12; subface[R][0][1] = 13; subface[R][0][2] = 47; subface[R][0][3] = 52;
    subface[R][1][0] = 13; subface[R][1][1] = 14; subface[R][1][2] = 52; subface[R][1][3] = 53;
    subface[R][2][0] = 14; subface[R][2][1] = 15; subface[R][2][2] = 53; subface[R][2][3] = 38;
    subface[R][3][0] = 47; subface[R][3][1] = 52; subface[R][3][2] = 46; subface[R][3][3] = 54;
    subface[R][4][0] = 52; subface[R][4][1] = 53; subface[R][4][2] = 54; subface[R][4][3] = 55;
    subface[R][5][0] = 53; subface[R][5][1] = 38; subface[R][5][2] = 55; subface[R][5][3] = 39;
    subface[R][6][0] = 46; subface[R][6][1] = 54; subface[R][6][2] = 31; subface[R][6][3] = 30;
    subface[R][7][0] = 54; subface[R][7][1] = 55; subface[R][7][2] = 30; subface[R][7][3] = 29;
    subface[R][8][0] = 55; subface[R][8][1] = 39; subface[R][8][2] = 29; subface[R][8][3] = 28;

    //rotateSide(W); //test

}

void Rubiks::drawFace(int i, int j)
{
	GLfloat shade = 1, shade1=1, shade2=1, shade3=1;

	switch (renderMode) {
	case WIRE:
	   glColor3f(r, g, b);
	   glBegin(GL_LINE_LOOP);
	   glVertex3fv(subVertex[subface[i][j][0]]);
       glVertex3fv(subVertex[subface[i][j][1]]);
       glVertex3fv(subVertex[subface[i][j][3]]);
       glVertex3fv(subVertex[subface[i][j][2]]);
       glEnd();
	   break;
	case CONSTANT:
	  if (myLight.on == true) {
	    shade = getFaceShade(i, myLight);
	  }
	   glColor3f(faceColor[i][j]->r*shade, faceColor[i][j]->g*shade, faceColor[i][j]->b*shade);
	   glBegin(GL_POLYGON);
	   glVertex3fv(subVertex[subface[i][j][0]]);
       glVertex3fv(subVertex[subface[i][j][1]]);
       glVertex3fv(subVertex[subface[i][j][3]]);
       glVertex3fv(subVertex[subface[i][j][2]]);
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

void Rubiks::rotateSide(GLint Face)
{

	// General case for shuffling side that is being rotated
	Color *temp;
	Color *temp2;

	// Corners
	temp = faceColor[Face][2];
	faceColor[Face][2] = faceColor[Face][0];
	temp2 = faceColor[Face][8];
	faceColor[Face][8] = temp;
	temp = faceColor[Face][6];
	faceColor[Face][6] = temp2;
	faceColor[Face][0] = temp;

	// Edges
	temp = faceColor[Face][5];
	faceColor[Face][5] = faceColor[Face][1];
	temp2 = faceColor[Face][7];
	faceColor[Face][7] = temp;
	temp = faceColor[Face][3];
	faceColor[Face][3] = temp2;
	faceColor[Face][1] = temp;

	// Specific cases for cross-face rotation
	switch (Face)
	{

		Color *temprow[3];
		Color *temprow2[3];

	case W:
		temprow[0] = faceColor[R][0];
		temprow[1] = faceColor[R][1];
		temprow[2] = faceColor[R][2];

		faceColor[R][0] = faceColor[B][0];
		faceColor[R][1] = faceColor[B][3];
		faceColor[R][2] = faceColor[B][6];

		temprow2[0] = faceColor[G][2];
		temprow2[1] = faceColor[G][5];
		temprow2[2] = faceColor[G][8];

		faceColor[G][2] = temprow[0];
		faceColor[G][5] = temprow[1];
		faceColor[G][8] = temprow[2];

		temprow[0] = faceColor[O][6];
		temprow[1] = faceColor[O][7];
		temprow[2] = faceColor[O][8];

		faceColor[O][6] = temprow2[0];
		faceColor[O][7] = temprow2[1];
		faceColor[O][8] = temprow2[2];

		faceColor[B][0] = temprow[0];
		faceColor[B][3] = temprow[1];
		faceColor[B][6] = temprow[2];

		break;
	case Y:
		temprow[0] = faceColor[O][0];
		temprow[1] = faceColor[O][1];
		temprow[2] = faceColor[O][2];

		faceColor[O][0] = faceColor[B][2];
		faceColor[O][1] = faceColor[B][5];
		faceColor[O][2] = faceColor[B][8];

		temprow2[0] = faceColor[G][0];
		temprow2[1] = faceColor[G][3];
		temprow2[2] = faceColor[G][6];

		faceColor[G][6] = temprow[0];
		faceColor[G][3] = temprow[1];
		faceColor[G][0] = temprow[2];

		temprow[0] = faceColor[R][6];
		temprow[1] = faceColor[R][7];
		temprow[2] = faceColor[R][8];

		faceColor[R][6] = temprow2[0];
		faceColor[R][7] = temprow2[1];
		faceColor[R][8] = temprow2[2];

		faceColor[B][8] = temprow[0];
		faceColor[B][5] = temprow[1];
		faceColor[B][2] = temprow[2];
		break;
	case O:
		temprow[0] = faceColor[G][0];
		temprow[1] = faceColor[G][1];
		temprow[2] = faceColor[G][2];

		faceColor[G][0] = faceColor[W][0];
		faceColor[G][1] = faceColor[W][1];
		faceColor[G][2] = faceColor[W][2];

		temprow2[0] = faceColor[Y][0];
		temprow2[1] = faceColor[Y][1];
		temprow2[2] = faceColor[Y][2];

		faceColor[Y][0] = temprow[0];
		faceColor[Y][1] = temprow[1];
		faceColor[Y][2] = temprow[2];

		temprow[0] = faceColor[B][0];
		temprow[1] = faceColor[B][1];
		temprow[2] = faceColor[B][2];

		faceColor[B][0] = temprow2[0];
		faceColor[B][1] = temprow2[1];
		faceColor[B][2] = temprow2[2];

		faceColor[W][0] = temprow[0];
		faceColor[W][1] = temprow[1];
		faceColor[W][2] = temprow[2];
		break;
	case R:
		temprow[0] = faceColor[B][6];
		temprow[1] = faceColor[B][7];
		temprow[2] = faceColor[B][8];

		faceColor[B][6] = faceColor[W][6];
		faceColor[B][7] = faceColor[W][7];
		faceColor[B][8] = faceColor[W][8];

		temprow2[0] = faceColor[Y][6];
		temprow2[1] = faceColor[Y][7];
		temprow2[2] = faceColor[Y][8];

		faceColor[Y][6] = temprow[0];
		faceColor[Y][7] = temprow[1];
		faceColor[Y][8] = temprow[2];

		temprow[0] = faceColor[G][6];
		temprow[1] = faceColor[G][7];
		temprow[2] = faceColor[G][8];

		faceColor[G][6] = temprow2[0];
		faceColor[G][7] = temprow2[1];
		faceColor[G][8] = temprow2[2];

		faceColor[W][6] = temprow[0];
		faceColor[W][7] = temprow[1];
		faceColor[W][8] = temprow[2];
		break;
	case G:
		temprow[0] = faceColor[R][0];
		temprow[1] = faceColor[R][3];
		temprow[2] = faceColor[R][6];

		faceColor[R][0] = faceColor[W][0];
		faceColor[R][3] = faceColor[W][3];
		faceColor[R][6] = faceColor[W][6];

		temprow2[0] = faceColor[Y][2];
		temprow2[1] = faceColor[Y][5];
		temprow2[2] = faceColor[Y][8];

		faceColor[Y][8] = temprow[0];
		faceColor[Y][5] = temprow[1];
		faceColor[Y][2] = temprow[2];

		temprow[0] = faceColor[O][6];
		temprow[1] = faceColor[O][3];
		temprow[2] = faceColor[O][0];

		faceColor[O][6] = temprow2[0];
		faceColor[O][3] = temprow2[1];
		faceColor[O][0] = temprow2[2];

		faceColor[W][6] = temprow[0];
		faceColor[W][3] = temprow[1];
		faceColor[W][0] = temprow[2];
		break;
	case B:
		temprow[0] = faceColor[O][2];
		temprow[1] = faceColor[O][5];
		temprow[2] = faceColor[O][8];

		faceColor[O][2] = faceColor[W][2];
		faceColor[O][5] = faceColor[W][5];
		faceColor[O][8] = faceColor[W][8];

		temprow2[0] = faceColor[Y][0];
		temprow2[1] = faceColor[Y][3];
		temprow2[2] = faceColor[Y][6];

		faceColor[Y][6] = temprow[0];
		faceColor[Y][3] = temprow[1];
		faceColor[Y][0] = temprow[2];

		temprow[0] = faceColor[R][2];
		temprow[1] = faceColor[R][5];
		temprow[2] = faceColor[R][8];

		faceColor[R][8] = temprow2[0];
		faceColor[R][5] = temprow2[1];
		faceColor[R][2] = temprow2[2];

		faceColor[W][2] = temprow[0];
		faceColor[W][5] = temprow[1];
		faceColor[W][8] = temprow[2];
		break;
	}
	draw();
	glutPostRedisplay();

}