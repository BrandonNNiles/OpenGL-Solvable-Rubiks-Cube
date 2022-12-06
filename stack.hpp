#ifndef CStack_H
#define CStack_H
#include <GL/glut.h>

#include "Node.hpp"


class Stack {
	
	
public:
	Node *top;
	int length;
	
	Stack() {
		top = NULL;
		length = 1;
	}
	
	void push(GLint face, GLint num);
	Node* pop();

};

#endif
