/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2022-10-03
 */
#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>

void menu();
void mainMenu(GLint option);
void ObjSubMenu(GLint objectOption);
void Rotate_Side(GLint face, GLint num);
void Rotate_Wrap(GLint n);
void Solve();
void Solve_Face(GLint n, GLint face);
void MCSTransMenu(GLint transOption);
void WCSTransMenu(GLint transOption);
void VCSTransMenu(GLint transOption);
void MCSTransform(GLint);
void WCSTransform(GLint);
void VCSTransform(GLint);
void random(int n);

void cullMenu(GLint option);
void lightMenu(GLint option);
void lightTransform(GLint);
void shadeMenu(GLint option);
void animateMenu(GLint option);
void move();

#endif
