/* file: proj10-Queue1.h
* author: Michael Mathews
* course: CSI 1440
* assignment: project 10
* due date: 12/6/2021
*/

#ifndef PROJECT_10_PROJ10_QUEUE1_H
#define PROJECT_10_PROJ10_QUEUE1_H

#include "proj10-MyVector.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
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
void Queue1<T>::enqueue( T e){
    this->pushBack(e);
}

template <class T>
void Queue1<T>::dequeue( T &e){
    if (this->size == 0){
        throw BADINDEX();
    }
    else {
        this->popFront(e);
    }
} // throws BADINDEX

#endif //PROJECT_10_PROJ10_QUEUE1_H
