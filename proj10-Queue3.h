/* file: proj10-Queue3.h
* author: Michael Mathews
* course: CSI 1440
* assignment: project 10
* due date: 12/6/2021
*/

#ifndef PROJECT_10_PROJ10_QUEUE3_H
#define PROJECT_10_PROJ10_QUEUE3_H

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
    /**
    function: enqueue
    description: adds value to end
    pre-condition: MyList exists
    post-condition: added value to end of MyList
    return: nothing
    */
    void enqueue( T );
    /**
    function: dequeue
    description: removes value from front
    pre-condition: MyList exists
    post-condition: removed value from front of MyList
    return: nothing
    */
    void dequeue( T& );
};

template <class T>
void Queue3<T>::enqueue( T e){
    this->pushBack(e);
}

template <class T>
void Queue3<T>::dequeue( T& e){
    if(this->head == NULL){
        throw BADINDEX();
    }
    else {
        this->popFront(e);
    }
} // throws BADINDEX

#endif //PROJECT_10_PROJ10_QUEUE3_H
