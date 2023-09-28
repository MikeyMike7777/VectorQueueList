/* file: proj10-Queue2.h
* author: Michael Mathews
* course: CSI 1440
* assignment: project 10
* due date: 12/6/2021
*/

#ifndef PROJECT_10_PROJ10_QUEUE2_H
#define PROJECT_10_PROJ10_QUEUE2_H

#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front, rear;
public:
    /**
    function: Queue2
    description: class constructor
    pre-condition: none
    post-condition: front and rear = -1
    return: nothing
    */
    Queue2();
    /**
    function: enqueue
    description: adds value to end
    pre-condition: MyVector exists
    post-condition: added value to end of MyVector
    return: nothing
    */
    void enqueue( T );
    /**
    function: dequeue
    description: removes value from front
    pre-condition: MyVector exists
    post-condition: removed value from front of MyVector
    return: nothing
    */
    void dequeue( T& ); // throws BADINDEX
};

template <class T>
Queue2<T>::Queue2(){
    this->front = -1;
    this->rear = -1;
}

template <class T>
void Queue2<T>::enqueue( T e ){
    if (this->size == this->capacity) {
        this->grow();
    }
    //circular array algorithm
    this->rear = (this->rear+1) % this->capacity;
    this->data[this->rear] = e;
    this->size++;
}

template <class T>
void Queue2<T>::dequeue( T &e ){
    if(this->size == 0){
        throw BADINDEX();
    }
    else {
        //circular array algorithm
        this->front = (this->front+1) % this->capacity;
        e = this->data[this->front];
        this->size--;
    }
}
#endif //PROJECT_10_PROJ10_QUEUE2_H
