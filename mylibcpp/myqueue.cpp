#include "myqueue.h"

#pragma region QUEUE FUNCTIONS
/**
* @name enqueue
* @param [in] myQueue [\b MyQueue*]
* @param [in] data [\b Data*]
* @retval [\b int]
* A queue can be implemented using two stacks. Let queue to be implemented be q and stacks used to implement q be stack1 and stack2.
**/
int enqueue(MyQueue* myQueue, Data* data) {
	if (myQueue->size == myQueue->capacity)
	{
		return 0;
	}
	myQueue->back = (myQueue->back + 1) % myQueue->capacity;
	myQueue->arr[myQueue->back] = data;
	myQueue->size = myQueue->size + 1;
}
/**
* @name dequeue
* @param [in] myQueue [\b MyQueue*]
* @retval [\b Data*]
* Dequeue is a sequence container with the ability of expansion and contraction on both ends.
**/
Data* dequeue(MyQueue* myQueue) {
	if (myQueue->size == 0)
	{
		return 0;
	}
	Data* data = myQueue->arr[myQueue->front];
	myQueue->front = (myQueue->front + 1) % myQueue->capacity;
	myQueue->size = myQueue->size - 1;
	return data;
}
/**
* @name front
* @param [in] myQueue [\b MyQueue*]
* @retval [\b Data*]
* push the elements into a deque from the front
**/
Data* front(MyQueue* myQueue) {
	// Empty condition to check
	if (myQueue->size == 0) {
		return 0;
	}
	return myQueue->arr[myQueue->front];
}
/**
* @name back
* @param [in] myQueue [\b MyQueue*]
* @retval [\b Data*]
* Back stack to be cleared of all activities except the root activity when the user leaves the task
**/
Data* back(MyQueue* myQueue) {
	// Empty condition to check
	if (myQueue->size == 0) {
		return 0;
	}
	return myQueue->arr[myQueue->back];
}
/**
* @name queueLenght
* @param [in] myQueue [\b MyQueue*]
* @retval [\b int]
* The length is an inbuilt function in Ruby returns the current length of the Queue or the number of objects present in it.
**/
int queueLength(MyQueue* myQueue) {
	return myQueue->capacity;
}
#pragma endregion