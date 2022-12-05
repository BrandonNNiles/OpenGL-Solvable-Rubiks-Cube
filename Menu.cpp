/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2022-10-03
 */
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Rubiks.hpp"
#include "stack.hpp"
#include <stdio.h>

extern GLint csType;
extern Shape* selectObj;
extern GLint transType, xbegin;
extern World myWorld;
extern Camera myCamera;
extern Light myLight;
extern CullMode cullMode;
extern RenderMode renderMode;
extern Stack theStack;


void menu() {
	GLint Object_Menu = glutCreateMenu(ObjSubMenu);
	glutAddMenuEntry("Cube", 1);
	glutAddMenuEntry("Pyramid", 2);
	glutAddMenuEntry("House", 3);
	
	GLint RotateWhiteSub = glutCreateMenu(Rotate_White);
	glutAddMenuEntry("CW", 1);
	glutAddMenuEntry("2X", 2);
	glutAddMenuEntry("CCW", 3);
	
	GLint RotateYellowSub = glutCreateMenu(Rotate_Yellow);
	glutAddMenuEntry("CW", 1);
	glutAddMenuEntry("2X", 2);
	glutAddMenuEntry("CCW", 3);
	
	GLint RotateBlueSub = glutCreateMenu(Rotate_Blue);
	glutAddMenuEntry("CW", 1);
	glutAddMenuEntry("2X", 2);
	glutAddMenuEntry("CCW", 3);
	
	GLint RotateOrangeSub = glutCreateMenu(Rotate_Orange);
	glutAddMenuEntry("CW", 1);
	glutAddMenuEntry("2X", 2);
	glutAddMenuEntry("CCW", 3);
	
	GLint RotateGreenSub = glutCreateMenu(Rotate_Green);
	glutAddMenuEntry("CW", 1);
	glutAddMenuEntry("2X", 2);
	glutAddMenuEntry("CCW", 3);
	
	GLint RotateRedSub = glutCreateMenu(Rotate_Red);
	glutAddMenuEntry("CW", 1);
	glutAddMenuEntry("2X", 2);
	glutAddMenuEntry("CCW", 3);

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

	GLint Cull_Menu = glutCreateMenu(cullMenu);
	glutAddMenuEntry("No culling", 1);
	glutAddMenuEntry("My back-face", 2);
	glutAddMenuEntry("OpenGL back-face & depth buffer", 3);

	GLint Light_Menu = glutCreateMenu(lightMenu);
	glutAddMenuEntry("Turn on light", 8);
	glutAddMenuEntry("Turn off light", 9);
	glutAddMenuEntry("Change intensity", 7);
	glutAddMenuEntry("Rotate x ", 1);
	glutAddMenuEntry("Rotate y ", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x ", 4);
	glutAddMenuEntry("Translate y ", 5);
	glutAddMenuEntry("Translate z", 6);

	GLint Shading_Menu = glutCreateMenu(shadeMenu);
	glutAddMenuEntry("No shading", 1);
	glutAddMenuEntry("My constant shading", 2);
	glutAddMenuEntry("OpenGL flat shading", 3);
	glutAddMenuEntry("OpenGL smooth shading", 4);

	GLint Animate_Menu = glutCreateMenu(animateMenu);
	glutAddMenuEntry("Single object", 1);
	glutAddMenuEntry("Multiple object", 2);
	glutAddMenuEntry("Stop animation", 3);


	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Reset", 1);
	//glutAddSubMenu("Select Object", Object_Menu);
	glutAddSubMenu("Rotate White", RotateWhiteSub);
	glutAddSubMenu("Rotate Yellow", RotateYellowSub);
	glutAddSubMenu("Rotate Blue", RotateBlueSub);
	glutAddSubMenu("Rotate Orange", RotateOrangeSub);
	glutAddSubMenu("Rotate Green", RotateGreenSub);
	glutAddSubMenu("Rotate Red", RotateRedSub);
	glutAddSubMenu("MCS Transformations", MCTrans_Menu);
	glutAddSubMenu("WCS Transformations", WCTrans_Menu);
	glutAddSubMenu("VCS Transformations", VCTrans_Menu);
	glutAddSubMenu("Culling", Cull_Menu);
	glutAddSubMenu("Light", Light_Menu);
	glutAddSubMenu("Shading", Shading_Menu);
	glutAddSubMenu("Animation", Animate_Menu);
	glutAddMenuEntry("Quit", 2);
	glutAddMenuEntry("Solve Cube", 3);
}

void mainMenu(GLint option) {
	switch (option){
		case 1:
			myWorld.reset();
			//myCamera.setDefaultCamera();
			break;
		case 2:
			exit(0);
			break;
		case 3:
			Solve();
			break;
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

void Rotate_White(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(0);
	}
	GLint side = 0;
	(&theStack)->push(side);
	printf("n: %d\n", n);
	(&theStack)->push(n);

}

void Rotate_Yellow(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(1);
	}
	GLint side = 1;
	(&theStack)->push(side);
	printf("n: %d\n", n);
	(&theStack)->push(n);
}

void Rotate_Blue(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(2);
	}
	GLint side = 2;
	(&theStack)->push(side);
	printf("n: %d\n", n);
	(&theStack)->push(n);
}

void Rotate_Orange(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(3);
	}
	GLint side = 3;
	(&theStack)->push(side);
	printf("n: %d\n", n);
	(&theStack)->push(n);
}

void Rotate_Green(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(4);
	}
	GLint side = 4;
	(&theStack)->push(side);
	printf("n: %d\n", n);
	(&theStack)->push(n);
}

void Rotate_Red(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(5);
	}

	GLint side = 5;
	(&theStack)->push(side);
	printf("n: %d\n", n);
	(&theStack)->push(n);
}

void Solve(){

	while((&theStack)->top >= -1) {
		GLint num = (&theStack)->pop(); //number of rotations in stack
		GLint face = (&theStack)->pop(); //face
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
		
		switch(face) {
			case 0: {
				Solve_White(r);
				break;
			}
			case 1: {
				Solve_Yellow(r);
				break;
			}
			case 2: {
				Solve_Blue(r);
				break;
			}
			case 3: {
				Solve_Orange(r);
				break;
			}
			case 4: {
				Solve_Green(r);
				break;
			}
			case 5: {
				Solve_Red(r);
				break;
			}
		
			
		}

		//(&theStack)->pop();
		//(&theStack)->pop();


	}
}
void Solve_White(GLint n) {
	
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(0);
	}
}

void Solve_Yellow(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(1);
	}
}

void Solve_Blue(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(2);
	}
}

void Solve_Orange(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(3);
	}
}

void Solve_Green(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(4);
	}
}

void Solve_Red(GLint n) {
	for(int i=0;i<n;i++) {
		((Rubiks*)selectObj)->rotateSide(5);
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

void cullMenu(GLint option) {
	switch (option){
	  case 1:
		cullMode = NONE;
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		break;
	  case 2:
		cullMode = BACKFACE;
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		break;
	  case 3:
		cullMode = GLCULL;
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		break;
	}
	glutPostRedisplay();
}

void lightMenu(GLint option) {
	csType = 4;
	transType = option;

	switch (option) {
	   case 8:
		myLight.on = true;
		break;
	  case 9:
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_DEPTH_TEST);
		myLight.on = false;
		break;
	}

	glutPostRedisplay();
}

void lightTransform(GLint x){
	GLfloat theta = (xbegin - x > 0) ? 1 : -1;
	if (transType == 1) {   // rotate x
		myLight.rotate(0, 0, 0, 1.0, 0.0, 0.0, theta*0.5);
	}
	else if (transType == 2) { // rotate y
		myLight.rotate(0, 0, 0, 0.0, 1.0, 0.0, theta*0.5);
	}
	else if(transType == 3){ // rotate z
		myLight.rotate(0, 0, 0, 0.0, 0.0, 1.0, theta*0.5);
	}
	else if (transType == 4) { // translate x
		myLight.translate(theta*0.1, 0.0, 0.0);
	}
	else if(transType == 5){   // eye translate y
		myLight.translate(0.0, theta*0.1, 0.0);
	}
	else if(transType == 6){ // eye translate z
		myLight.translate(0.0, 0.0, theta*0.1);
	}
	else if(transType == 7){  // change intensity
		myLight.I += theta *0.01;
	}

	glutPostRedisplay();
}

void shadeMenu(GLint option) {
	switch (option){
	  case 1:
		renderMode = WIRE;
		break;
	  case 2:
		renderMode = CONSTANT;
		break;
	  case 3:
		renderMode = FLAT;
		break;
	  case 4:
		renderMode = SMOOTH;
		break;
	}
	glutPostRedisplay();
}



void move(void){
	selectObj->rotate(selectObj->getMC().mat[0][3], selectObj->getMC().mat[1][3], selectObj->getMC().mat[2][3], 0, 0, 1, 0.1);
	glutPostRedisplay();
}


void solar(void){
	GLfloat x1,y1,z1, x2,y2,z2, x3, y3, z3;
	GLfloat sunSpeed = 0.1, earthSpeed = 0.2, earthSunSpeed = 0.1, moonSpeed = 0.2, moonEarthSpeed = 0.2;

	Shape *sun = myWorld.searchById(3);
	Shape *earth = myWorld.searchById(1);
	Shape *moon = myWorld.searchById(2);

	x1 = sun->getMC().mat[0][3];
	y1 = sun->getMC().mat[1][3];
	z1 = sun->getMC().mat[2][3];

	x2 = earth->getMC().mat[0][3];
	y2 = earth->getMC().mat[1][3];
	z2 = earth->getMC().mat[2][3];

	x3 = moon->getMC().mat[0][3];
	y3 = moon->getMC().mat[1][3];
	z3 = moon->getMC().mat[2][3];

	// sun motion
    sun->rotate(x1, y1, z1, 0, 0, 1, sunSpeed);

    // earth motion
    earth->rotate(x2, y2, z2, 0, 0, 1, earthSpeed);
    earth->rotateOrigin(x1, y1, z1, 0, 0, 1, earthSunSpeed);

    // moon motion
    moon->rotate(x3, y3, z3,  0, 0, 1, moonSpeed);
    moon->rotateOrigin(x1, y1, z1, 0, 0, 1, earthSunSpeed);
    moon->rotateOrigin(x2, y2, z2,  0, 0, 1, moonEarthSpeed);

	glutPostRedisplay();
}

void animateMenu(GLint option) {
	switch (option){
	  case 1:
		glutIdleFunc(move);
		break;
	  case 2:
		myLight.on = false;
		glDisable(GL_LIGHTING);
		glutIdleFunc(solar);
		break;
	  case 3:
		glutIdleFunc(NULL);
		break;
	}
	glutPostRedisplay();
}

