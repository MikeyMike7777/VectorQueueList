/* file: proj10-MyVector.h
* author: Michael Mathews
* course: CSI 1440
* assignment: project 10
* due date: 12/6/2021
*/

#ifndef PROJECT_10_PROJ10_MYVECTOR_H
#define PROJECT_10_PROJ10_MYVECTOR_H

#include "proj10-ContainerIfc.h"
#include <iostream>

using namespace std;

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    /**
     * function: MyVector ()
     * description: class constructor
     * pre-condition: none
     * post-condition: n class object created with size = 0 ,capacity = 10,
     *      data points to an array of size capacity and type T
     * return: nothing
     */
    MyVector ();

    /**
    function: ~ MyVector ()
    description: class destructorpre-condition: a MyVector object exists
    post-condition: all memory allocated to the MyVector is deleted
    return: nothing
     */
    ~MyVector ();

    /**
    function: MyVector (const MyVector & v)
    description: class copy constructor
    pre-condition: a MyVector object exists
    post-condition: a copy of the class object v is made
    return: nothing
    */
    MyVector (const MyVector& obj);

    /**
    function: operator =(const MyVector & v)
    description: overloaded assignment operator
    pre-condition: a object exists
    post-condition: the object n is unchanged and *this is an exact copy of n
    return: a reference to self
    */
    MyVector<T>& operator= (const MyVector& obj);

    /**
    function: pushFront(T e)
    description: add data element e to the front of the vector
    pre-condition: a MyVector object exists
    post-condition: if size == capacity, double capacity shift all elements in data to the right data element e has been
        added to the front of the array, increment size
    return: a reference to self
    */
    MyVector<T>& pushFront(T item);

    /**
    function: pushBack(T e)
    description: store data element e in end of the vector
    pre-condition: a MyVector object exists
    post-condition if size == capacity, double capacity data element e has been added to the end of the array,
        increment size
    return: a reference to self
     */
    ContainerIfc<T>& pushBack(T);

    /**
    function: popFront(T& e)
    description: removes a data element from the front of the data structure (MyVector)
    pre-condition: a object exists
    post-condition: the first element has been removed from the front of the MyVector, decrement size, and set e equal
        to the element removed, error if MyVector is empty
    return: a reference to self
    */
    MyVector<T>& popFront(T& e);

    /**
    function: popBack(T& e)
    description: removes a data element from the rear (end) of the data structure (MyVector)
    pre-condition: a object exists
    post-condition: a data element has been removed from the rear of the MyVector, decrement currentSize,
        and set e equal to the element removed, error if MyVector is empty
    return: a reference to self
    */
    MyVector<T>& popBack(T& e);

    /**
    function: front()
    description: returns a copy of the first data item in the MyVector
    pre-condition: a object exists
    post-condition: the object is unchanged, error if MyVector is empty
    return: a copy of the object at the beginning of the array
     */
    T  front();

    /**
    function: back()
    description: returns a copy of the last data item in MyVector
    pre-condition: a object exists
    post-condition: the object is unchanged, error if MyVector is empty
    return: a copy of the object at the end of the array
     */
    T  back();

    /**
    function: operator []
    description: returns a reference to data element n in MyVector
    pre-condition: a object exists
    post-condition: the object is unchanged, error: n >= capacity or n < 0
    return: a reference to the object stored at offset of n within data
    */
    T&  operator [](int n);

    /**
    function: getSize()
    description: returns the number of elements currently in the MyVector
    pre-condition: a object exists
    post-condition: the MyVector is unchanged
    return: an integer value representing the number of elements in the list
    */
    int getSize();

    /**
    function: isEmpty()
    description: returns state information about the list
    pre-condition: a object exists
    post-condition: the MyVector is unchanged
    return: true if the MyVector is empty false otherwise
     */
    bool isEmpty();

    /**
    function: erase()
    description: erases a vector
    pre-condition: a object exists
    post-condition: the elements of a MyVector are erased
    return: nothing
     */
    void erase();

protected:
    T  *data;
    int size;
    int capacity;

    /**
    function: grow()
    description: increases the capacity of data by doubling the previous value and allocating the appropriate memory
         for data
    pre-condition: a MyVector object exists
    post-condition: capacity’s value is doubled and data points to an array of size capacity
    return: nothing
     */
    void grow();

    /**
    function: shiftRight()
    description: shifts all values in the array one space to the right
    pre-condition: a MyVector object exists
    post-condition: all values are shifted to the right (opens up one space at the beginning of the array)
    return: nothing
     */
    void shiftRight();

    /**
    function: shiftLeft()
    description: shifts all values in the array one space to the left
    pre-condition: a MyVector object exists
    post-condition: all values are shifted to the left (removes first value from the array)
    return: nothing
    */
    void shiftLeft();
};

//default constructor
template <class T>
MyVector<T>::MyVector (){
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

//destructor
template <class T>
MyVector<T>::~MyVector (){
    delete [] this->data;
}

//copy constructor
template <class T>
MyVector<T>::MyVector (const MyVector& obj){
    this->size = obj.size;
    this->capacity = obj.capacity;
    this->data = new T[this->capacity];
    for(int i = 0; i < obj.size; i++){
        this->data[i] = obj.data[i];
    }
}

//operator =
template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& obj){
    if(this != &obj) {
        delete[] this->data;

        this->size = obj.size;
        this->capacity = obj.capacity;
        this->data = new T[this->capacity];
        for (int i = 0; i < obj.size; i++) {
            this->data[i] = obj.data[i];
        }
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T item){
    //increase size if necessary
    if(this->size == this->capacity){
        this->grow();
    }
    //create space for new item
    this->size++;
    this->shiftRight();
    //add item to front
    this->data[0] = item;
    return *this;
}

template <class T>
ContainerIfc<T>& MyVector<T>::pushBack(T item){
    //increase size if necessary
    if(this->size == this->capacity){
        this->grow();
    }
    //add item to end
    this->data[this->size] = item;
    this->size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e){
    //if no data
    if(this->size == 0){
        throw BADINDEX();
    }
    else {
        //store first element
        e = this->data[0];
        //delete first element
        this->shiftLeft();
        this->size--;
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e){
    //if no data in MyVector
    if(this->size == 0){
        throw BADINDEX();
    }
    else {
        //store last element
        e = this->data[this->size-1];
        //delete lats element
        this->size--;
    }
    return *this;
}

template <class T>
T MyVector<T>::front() {
    //if no data in MyVector
    if (this->size == 0) {
        BADINDEX bad;
        throw bad;
    } else {
        return this->data[0];
    }
}

template <class T>
T MyVector<T>::back(){
    //if no data in MyVector
    if(this->size == 0){
        BADINDEX bad;
        throw bad;
    }
    else {
        return this->data[this->size-1];
    }
}

template <class T>
T& MyVector<T>::operator [](int n){
    //if index is greater than capacity or less than 0, throw error
    if(n >= this->capacity or n < 0){
        BADINDEX bad;
        throw bad;
    }
    return this->data[n];
}

template <class T>
int MyVector<T>::getSize(){
    //return size
    return this->size;
}

template <class T>
bool MyVector<T>::isEmpty(){
    //if size = 0, will return true to "isEmpty()"
    bool flag = false;
    if (this->size == 0){
        flag = true;
    }
    return flag;
}

template <class T>
void MyVector<T>::erase(){
    //erase all elements and set size to 0
    delete [] this->data;
    this->size = 0;
    this->data = nullptr;
}

template <class T>
void MyVector<T>::grow(){
    //algorithm for dynamically resizing array
    this->capacity *= 2;
    T *temp = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->data[i];
    }
    delete [] this->data;
    this->data = temp;
}

template <class T>
void MyVector<T>::shiftRight(){
    //set every item equal to one before it starting from end
    for(int i = this->size-1; i >= 0; i--){
        this->data[i+1] = this->data[i];
    }
}

template <class T>
void MyVector<T>::shiftLeft(){
    //set every item equal to one after it starting from front
    for(int i = 0; i < this->size; i++){
        this->data[i] = this->data[i+1];
    }
}

#endif //PROJECT_10_PROJ10_MYVECTOR_H
