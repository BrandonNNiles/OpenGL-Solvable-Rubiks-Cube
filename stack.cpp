
#include "stack.hpp"
#include <stdio.h>
extern Stack theStack;
using namespace std;

void Stack::push(GLint val) {
	
	//if((&theStack)->top>=((&theStack)->n)-1){} //do nothing, stack full
	//else {
		((&theStack)->top)++;
		(&theStack)->stack[top]=val;

}
GLint Stack::pop() {
	
  // if((&theStack)->top<=-1){} //do nothing, stack empty
  // else {

      int n  = (&theStack)->stack[top];
      ((&theStack)->top)--;


   //}
   return n;
}