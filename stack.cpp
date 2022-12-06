
#include "stack.hpp"
#include "Node.hpp"
#include <stdio.h>
extern Stack theStack;

void Stack::push(GLint face, GLint num) {
	
	Node *n = new Node(face, num);
	(n->previous) = ((&theStack)->top);
	((&theStack)->top) = n;
	length++;

}
Node* Stack::pop() {
	
	Node *n = NULL;

	if(((&theStack)->top) != NULL){
		n = ((&theStack)->top);
		((&theStack)->top) = n->previous;
	}

	length--;



   return n;
}
