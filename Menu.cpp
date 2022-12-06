/*
 *  Author: Brandon, Shawn, Joey
 */
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Rubiks.hpp"
#include "stack.hpp"
#include <stdio.h>

#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>

extern GLint csType;
extern Shape* selectObj;
extern GLint transType, xbegin;
extern World myWorld;
extern Camera myCamera;
extern CullMode cullMode;
extern Stack theStack;





void menu() {
	cullMode = GLCULL;
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	GLint RotateWhiteSub = glutCreateMenu(Rotate_Wrap);
	glutAddMenuEntry("CCW", 0);
	glutAddMenuEntry("2X", 1);
	glutAddMenuEntry("CW", 2);
	
	GLint RotateYellowSub = glutCreateMenu(Rotate_Wrap);
	glutAddMenuEntry("CCW", 3);
	glutAddMenuEntry("2X", 4);
	glutAddMenuEntry("CW", 5);
	
	GLint RotateBlueSub = glutCreateMenu(Rotate_Wrap);
	glutAddMenuEntry("CCW", 6);
	glutAddMenuEntry("2X", 7);
	glutAddMenuEntry("CW", 8);
	
	GLint RotateOrangeSub = glutCreateMenu(Rotate_Wrap);
	glutAddMenuEntry("CCW", 9);
	glutAddMenuEntry("2X", 10);
	glutAddMenuEntry("CW", 11);
	
	GLint RotateGreenSub = glutCreateMenu(Rotate_Wrap);
	glutAddMenuEntry("CCW", 12);
	glutAddMenuEntry("2X", 13);
	glutAddMenuEntry("CW", 14);
	
	GLint RotateRedSub = glutCreateMenu(Rotate_Wrap);
	glutAddMenuEntry("CCW", 15);
	glutAddMenuEntry("2X", 16);
	glutAddMenuEntry("CW", 17);

	GLint MCTrans_Menu = glutCreateMenu(MCSTransMenu);
	glutAddMenuEntry("Rotate x", 1);
	glutAddMenuEntry("Rotate y", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Scale", 4);

	GLint WCTrans_Menu = glutCreateMenu(WCSTransMenu);
	glutAddMenuEntry("Rotate x", 1);
	glutAddMenuEntry("Rotate y", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x", 4);
	glutAddMenuEntry("Translate y", 5);
	glutAddMenuEntry("Translate z", 6);

	GLint VCTrans_Menu = glutCreateMenu(VCSTransMenu);
	glutAddMenuEntry("Rotate x", 1);
	glutAddMenuEntry("Rotate y", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x", 4);
	glutAddMenuEntry("Translate y", 5);
	glutAddMenuEntry("Translate z", 6);
	glutAddMenuEntry("Clipping Near", 7);
	glutAddMenuEntry("Clipping Far", 8);

	glutCreateMenu(mainMenu);
	glutAddSubMenu("Rotate White", RotateWhiteSub);
	glutAddSubMenu("Rotate Yellow", RotateYellowSub);
	glutAddSubMenu("Rotate Blue", RotateBlueSub);
	glutAddSubMenu("Rotate Orange", RotateOrangeSub);
	glutAddSubMenu("Rotate Green", RotateGreenSub);
	glutAddSubMenu("Rotate Red", RotateRedSub);
	glutAddSubMenu("MCS Transformations", MCTrans_Menu);
	glutAddSubMenu("WCS Transformations", WCTrans_Menu);
	glutAddSubMenu("VCS Transformations", VCTrans_Menu);
	glutAddMenuEntry("Quit", 2);
	glutAddMenuEntry("Solve Cube", 3);
	glutAddMenuEntry("Randomize", 4);
}

void mainMenu(GLint option) {
	switch (option){
		case 2:
			exit(0);
			break;
		case 3:
			glutIdleFunc(Solve);
			break;
		case 4:
			random(20);
	}
	glutPostRedisplay();
}

void ObjSubMenu(GLint objectOption)
{
	selectObj = myWorld.searchById(objectOption);
	Matrix mp = selectObj->getMC();
	myCamera.setRef(mp.mat[0][3], mp.mat[1][3], mp.mat[1][3]);
	glutPostRedisplay();
}

void Rotate_Side(GLint face, GLint num) {
	for(int i=0;i<num;i++) {
		((Rubiks*)selectObj)->rotateSide(face);
	}

	(&theStack)->push(face, num);
	printf("n: %d\n", num);
}

void Rotate_Wrap(GLint n){
	GLint face = n / 3;
	GLint num = (n % 3) + 1;
	Rotate_Side(face, num);
}

void Solve_Face(GLint n, GLint face) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(face);
	}
}


void random(int n) {
    srand((unsigned) time(NULL)); //generate seed for randomness

    for(int i=0;i<n;i++) {
        int face = rand() % 6;
        int r = (rand() % 3) + 1;
        Rotate_Side(face, r);
    }
}



void MCSTransMenu(GLint transOption) {
	csType = 1;
	transType = transOption;
	glutPostRedisplay();
}


void WCSTransMenu(GLint transOption) {
	csType = 2;
	transType = transOption;
	glutPostRedisplay();
}

void VCSTransMenu(GLint transOption) {
	csType = 3;
	transType = transOption;
	glutPostRedisplay();
}

void MCSTransform(GLint x){
	GLfloat x0, y0, z0, rx, ry, rz, theta;
	theta = (xbegin - x > 0) ? 1 : -1;

	x0 = selectObj->getMC().mat[0][3];
	y0 = selectObj->getMC().mat[1][3];
	z0 = selectObj->getMC().mat[2][3];

	if (transType == 1) { //model rotate x
		rx = selectObj->getMC().mat[0][0];
		ry = selectObj->getMC().mat[1][0];
		rz = selectObj->getMC().mat[2][0];
		selectObj->rotate(x0, y0, z0, rx, ry, rz, theta * 0.5);
	}
	else if (transType == 2) { //model rotate y
		rx = selectObj->getMC().mat[0][1];
		ry = selectObj->getMC().mat[1][1];
		rz = selectObj->getMC().mat[2][1];
		selectObj->rotate(x0, y0, z0, rx, ry, rz, theta * 0.5);
	}else if (transType == 3){  //model rotate z
		rx = selectObj->getMC().mat[0][2];
		ry = selectObj->getMC().mat[1][2];
		rz = selectObj->getMC().mat[2][2];
		selectObj->rotate(x0, y0, z0, rx, ry, rz, theta * 0.5);
	}
	else if (transType == 4) { //model scale
		selectObj->scaleChange(theta * 0.02);
	}
}

void WCSTransform(GLint x){
	GLfloat theta = (xbegin - x > 0) ? 1 : -1;
	if (transType == 1) {
		selectObj->rotateOrigin(0, 0, 0, 1, 0, 0, theta * 0.5);
	}
	else if (transType == 2) {
		selectObj->rotateOrigin(0, 0, 0, 0, 1, 0, theta * 0.5);
	}
	else if(transType == 3){
		selectObj->rotateOrigin(0, 0, 0, 0, 0, 1, theta * 0.5);
	}
	else if (transType == 4) {
		selectObj->translate(theta * 0.02, 0, 0);
	}
	else if(transType == 5){ //WC translate y
		selectObj->translate(0, theta * 0.02, 0);
	}
	else if(transType == 6){ //WC translate z
		selectObj->translate(0, 0, theta * 0.02);
	}
}

void VCSTransform(GLint x){
	GLfloat theta = (xbegin - x > 0) ? 1 : -1;
	if (transType == 1) {  //eye rotate x
		myCamera.rotate(1.0, 0.0, 0.0, theta*0.5);
	}
	else if (transType == 2) { // eye rotate y
		myCamera.rotate(0.0, 1.0, 0.0, theta*0.5);
	}
	else if(transType == 3){ //eye rotate z
		myCamera.rotate(0.0, 0.0, 1.0, theta*0.5);
	}
	else if (transType == 4) { //eye translate x
		myCamera.translate(theta* 0.02, 0.0, 0.0);
	}
	else if(transType == 5){   // eye translate y
		myCamera.translate(0.0, theta* 0.02, 0.0);
	}
	else if(transType == 6){ // eye translate z
		myCamera.translate(0.0, 0.0, theta* 0.02);
	}
	else if(transType == 7){  // change dnear
		myCamera.dnear += theta * .1;
	}
	else if(transType == 8){  // change dfar
		myCamera.dfar += theta *.1;
	}
}

void Solve(void){
	if((&theStack)->top != NULL) {

		Node *n = (&theStack)->pop();
		GLint num = n->num;
		GLint face = n->face;

		printf("Popped n rotations off stack: %d\n", num);
		printf("Popped side %d off stack\n", face);
		GLint r = 0;
		if (num == 1) { //1x cw
			r = 3;
		}
		else if (num == 2) { //2x
			r = 2;
		}
		else{ //3x cw or 1x ccw
			r = 1;
		}

		Solve_Face(r, face);

		float wait;
		wait = 400.0 / sqrt((float)((&theStack)->length));
		Sleep(wait);
		glutPostRedisplay();
	} else {
		glutIdleFunc(NULL);
	}
}



