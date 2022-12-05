#ifndef CStack_H
#define CStack_H
#include <GL/glut.h>


class Stack {
	
	GLint stack[100];
	
	
public:
	
	GLint n;
	GLint top;
	
	Stack() {
		int top = -1;
		int n = 100;
		
	}
	
	void push(GLint val);
	GLint pop();

};

#endif