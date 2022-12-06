#ifndef CNode_H
#define CNode_H
#include <GL/glut.h>


class Node {

public:
	GLint face;
	GLint num;
	Node *previous;


	Node(GLint f, GLint n) {
		face = f;
		num = n;
		previous = NULL;

	}

};

#endif
