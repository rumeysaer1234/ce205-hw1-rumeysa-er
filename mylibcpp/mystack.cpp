#include "mystack.h"

#pragma region STACK FUNCTIONS
/**
* @name push
* @param [in] myStack [\b MyStack]
* @param [in] data [\b Data*]
* @retval [\b int]
* push function is used to insert or push an element at the top of the stack
**/
int push(MyStack* myStack, Data* data) {
	if (myStack->top == myStack->capacity - 1)
	{
		return -1;
	}
	myStack->arr[++myStack->top] = data;
}
/**
* @name pop
* @param [in] myStack [\b MyStack*]
* @retval [\b Data*]
* The pop function is used to remove or pop an element from the top of the stack
**/
Data* pop(MyStack* myStack) {
	if (myStack->top == -1)
	{
		return 0;
	}
	return myStack->arr[myStack->top--];
}
/**
* @name top
* @param [in] myStack [\b MyStack*]
* @retval [\b Data*]
* Function is used to reference the top or the newest element of the stack
**/
Data* top(MyStack* myStack)
{
	if (myStack->top == -1)
	{
		return 0;
	}
	return myStack->arr[myStack->top];
}
/**
* @name bottom
* @param [in] myStack [\b MyStack*]
* @retval [\b Data*]
* C++ program to print the elements of a stack from bottom to top
**/
Data* bottom(MyStack* myStack)
{
	if (myStack->top == -1)
	{
		return 0;
	}
	return myStack->arr[0];
}
/**
* @name stackLength
* @param [in] myStack [\b MyStack*]
* @retval [\b int]
* CPP program to illustrate Application of size function
**/
int stackLength(MyStack* myStack) {
	return myStack->top + 1;
}
#pragma endregion