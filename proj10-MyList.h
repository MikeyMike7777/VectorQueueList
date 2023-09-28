/* file: proj10-MyList.h
* author: Michael Mathews
* course: CSI 1440
* assignment: project 10
* due date: 12/6/2021
*/

#ifndef PROJECT_10_PROJ10_MYLIST_H
#define PROJECT_10_PROJ10_MYLIST_H

#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"
#include <iostream>

using namespace std;

template <class T>
class MyList : public ContainerIfc <T> {
public:
    /**
    function: MyList()
    description: class constructor
    pre-condition: none
    post-condition: head points to NULL
    return: nothing
    */
    MyList();

    /**
    function: ~ MyList()
    description: class destructor
    pre-condition: a MyList object exists
    post-condition: all memory allocated to the MyList is deleted
    return: nothing
    */
    ~ MyList();

    /**
    function: MyList(const MyList& n)
    description: class copy constructor
    pre-condition: a MyList object exists
    post-condition: a copy of the class object n is made
    return: nothing
    */
    MyList(const MyList&);

    /**
    function: operator =(MyList& n);
    description: overloaded assignment operator
    pre-condition: a object exists
    post-condition: the object n is unchanged and *this is an exact copy of n
    return: *this
    */
    MyList <T>& operator = (const MyList&);

    /**
    function: pushFront(T n)
    description: store data element n in a new Node and adds the Node to the front of a data structure (MyList)
    pre-condition: a MyList object exists
    post-condition: a new Node has been added to the front of the MyList
    return: a reference to self
    */
    MyList <T>& pushFront(T);

    /**
    function: pushBack(T n)
    description: store data element n in a new Node and adds the Node to the rear (end) of a data structure (MyList)
    pre-condition: a MyList object exists
    post-condition: a new data element has been added to the rear (end) of the MyList
    return: a reference to self
    */
    MyList <T>& pushBack(T);

    /**
    function: popFront(T &n)
    description: removes a data element from the front of the data structure (MyList)
    pre-condition: a object exists
    post-condition: a Node has been removed from the front of the linked MyList pointed to by head, and set n equal to the data of the node removed
    error: if the MyList is empty throw a BADINDEX exception
    return: a reference to self
    */
    MyList <T>& popFront(T&);

    /**
    function: popBack(T &n)
    description: removes a data element from the rear (end) of the data structure (MyList)
    pre-condition: a object exists
    post-condition: a Node has been removed from the rear of the linked MyList pointed to by head and set n to the data of the node removed
    error: if the MyList is empty throw a BADINDEX exception
    return: a reference to self
    */
    MyList <T>& popBack(T&);

    /**
    function: getSize()
    description: returns the number of Nodes currently in the linked MyList
    pre-condition: a object exists
    post-condition: the linked MyList is unchanged
    return: an integer value representing the number of elements in the MyList
    */
    int getSize();

    /**
    function: isEmpty()
    description: returns true if MyList is empty and false if not
    pre-condition: a object exists
    post-condition: the linked MyList is unchanged
    return: a bool describing if MyList is empty
    */
    bool isEmpty();

    /**
    function: front();
    description: returns a copy of the first data item in the linked list
    pre-condition: a object exists
    post-condition: the object is unchanged
    error: throw BADINDEX if the linked MyList is empty
     */
    T front();

    /**
    function: back();
    description: returns a copy of the last data item in the linked list
    pre-condition: a object exists
    post-condition: the object is unchanged
    error: throw BADINDEX if the linked MyList is empty
    */
    T back();

    /**
    function: operator [](int);
    description: returns a reference to data element n in the linked list
    pre-condition: a object exists
    post-condition: the object is unchanged
    error: throw BADINDEX if n >= currentSize or n < 0
    */
    T& operator [](int);

    /**
    function: erase();
    description: removes all nodes from MyList
    pre-condition: a object exists
    post-condition: the object is an empty MyList
    */
    void erase();

protected:
    Node<T> *head;
    Node<T> *tail;
};


template <class T>
MyList<T>::MyList(){
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
MyList<T>::~MyList(){
    if(this->head != NULL){
        delete this->head->next;
    }
}

template <class T>
MyList<T>::MyList(const MyList &list){
    this->head = NULL;
    Node<T> *ptr = list.head;
    while(ptr != NULL){
        //add node
        this->pushBack(ptr->data);
        //increment
        ptr = ptr->next;
    }
}

template <class T>
MyList <T>& MyList<T>::operator=(const MyList &list){
    Node<T> *ptr = list.head;
    this->head = NULL;
    if (this != &list){
        //clear previous data
        this->erase();
        while(ptr != NULL){
            //add node
            this->pushBack(ptr->data);
            //increment
            ptr = ptr->next;
        }
    }
    return *this;
}

template <class T>
MyList<T>& MyList<T>::pushFront(T item){
    //create new node with data and next = NULL
    Node<T> *newNode = new Node<T>(item);
    //set next to first node
    newNode->next = this->head;
    //set head to new node
    this->head = newNode;
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushBack(T item){
    //create new node with data and next = NULL
    Node<T> *newNode = new Node<T>(item);
    //make sure head has memory
    if(this->head == NULL){
        this->head = newNode;
    }
    else {
        Node<T> *ptr = this->head;
        //go to node at end of list
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        this->tail = ptr;
        //set new node at end of list
        this->tail->next = newNode;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::popFront(T &n){
    //if list not empty
    if(this->head != NULL) {
        //point to front so location not lost
        Node<T> *temp = this->head;
        //store data removed
        n = this->head->data;
        //set head to next
        this->head = this->head->next;
        //delete old node
        temp->next = NULL;
        delete temp;
    }
    else {
        throw BADINDEX();
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::popBack(T &n){
    Node<T> *temp = this->head;
    //if not empty
    if(this->head != NULL){
        //go to second to last node
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        this->tail = temp;
        //save value
        n = this->tail->next->data;
        //delete last node
        delete this->tail->next;
        //set new last node next to NULL
        this->tail->next = NULL;
    }
    else {
        throw BADINDEX();
    }
    return *this;
}


template <class T>
int MyList<T>::getSize(){
    int count = 0;
    Node<T> *temp = this->head;
    //count to end of list
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
bool MyList<T>::isEmpty(){
    bool empty = false;
    //make sure head isn't the end
    if (this->head == NULL){
        empty = true;
    }
    return empty;
}

template <class T>
T MyList<T>::front(){
    T item;
    //make sure not empty
    if(this->head != NULL){
        //set item to first nodes data
        item = this->head->data;
    }
    else {
        throw BADINDEX();
    }
    return item;
}

template <class T>
T MyList<T>::back(){
    T item;
    if (this->head != NULL){
        Node<T> *temp = this->head;
        //go to end of list
        while(temp->next != NULL){
            temp = temp->next;
        }
        //set item to last nodes data
        item = temp->data;
    }
    else {
        throw BADINDEX();
    }
    return item;
}

template <class T>
T& MyList<T>::operator [](int n){
    Node<T> *temp = this->head;
    //n can't be too big or less than 0
    if(n >= this->getSize() or n < 0){
        throw BADINDEX();
    }
    else {
        //count to point
        for(int i = 0; i < n; i++) {
            temp = temp->next;
        }
    }
    return temp->data;
}

template <class T>
void MyList<T>::erase(){
    Node<T> *temp = this->head;
    while(this->head != NULL){
        //set head to next
        this->head = this->head->next;
        //delete old node
        temp->next = NULL;
        delete temp;
        //set temp to incremented head
        temp = this->head;
    }
}

#endif //PROJECT_10_PROJ10_MYLIST_H
