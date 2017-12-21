/*CS 3100
Liz (Frankie) Ruttenbur
Assignment 1 - Linked Lists... where prev = stack->head will break things and you won't know why for an enitre day. 
*/

//header files, yo.
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


///creates the new stack with the head = null
stackT *NewStack (void){
    stackT *newNode = malloc(sizeof(stackT)); //allocate

    if (newNode == NULL){ //makes sure the new Node is null and will return it

        return NULL; 
    }

    newNode->head=NULL; //sets the head to null

    return newNode; //returns the newNode head


}

////PUSH FUNCTION
/* Allocate Space for a nodeT type in the heap
2-Set the next field of that new Node to point to the head node in the stack (set it to NULL if there is no head.
3-Set the head field of the stack to point to the new node
*/

void Push(stackT *stack, valueT value){

    nodeT* newNode = malloc(sizeof(nodeT)); //allocate

    newNode->value=value; //sets the value to the value of the new node
    
    if(stack->head == NULL){ //if the stack's pointer is null then..

        stack->head = newNode; //point it to the newNode
        newNode->next = NULL; 
    }
    else{

        newNode->next=stack->head;
        stack->head = newNode;
    }

}//end Push function..Ahhhh...shhh Push it... PUSH IT REAL GOOD!


///pops the value off the top of the stack
//Free the space associated with the old node.

valueT Pop(stackT *stack){
  
  nodeT *prev; //temp pointer to point to previous node
  valueT value; //temp value to return

  //Return 0 and print out an error if the stack is empty.
  if (stack->head == NULL){

    printf ("Error! Stack is empty, bro!");
    return 0;

  }
  else{

    value = stack->head->value; //whatever the value is of that node it gets put into the temp value.

    prev = stack->head->next; //Set the head field to point to the next node
    free(stack->head); //frees up the space of the old node

    stack->head = prev; //sets the head to the prev. I had it at prev = stack->head and it gave me a bunch of gobbledy goop. It took me forever to figure it out. I would get abort errors and corruption with a bunch of library stuff.
   
    return value;
  }
}

/*
This function should take as its argument a pointer to a stackT	and it should
free up the space associated with every node in the linked list in the stack, but it should not
free up the space associated with the stackT	structure in memory, but should set the head pointer to NULL.
*/
void EmptyStack(stackT *stack){
    
    //need another pointer here
    nodeT *prev; //temporary pointer to set it to the previous node.
  
  while (!IsEmpty(stack)){ //if the stack is not null
    prev = stack->head->next; 

    free(stack->head); //frees all that memory, yay.

    stack->head = prev; //sets the head of the stack to the previous node...this one line of code....*shakes fist*
  }
}

/*This function should take as its argument a pointer to a stackT	and should	free
up the space associated with the stackT	struct allocated in dynamic memory. This function
should only free up memory associated with an empty stack, and should print an error to the
screen when the user attempts to free a non-empty stack.
*/
void FreeStack(stackT *stack){

  if (!IsEmpty(stack)){
    printf("ERROR! This is a non-empty stack");//if they try to free a non empty stack this error prints.
  }
  else{
    free(stack);//frees up space in dynamic memory
  }
}

/*
This function takes as its argument a pointer to a stackT	in memory and
returns true if it is empty, and false otherwise. Your stack is defined as empty when its head
pointer is NULL. The function returns a boolean enumerated type, which is defined as
*/

bool IsEmpty(stackT *stack){

  if (stack->head == NULL){
    return true; //if the pointer is null then it returns true
  }
  else{
    
    return false; //else it is false. 
  }
  
}//end IsEmpty

//BOOYA FIN

