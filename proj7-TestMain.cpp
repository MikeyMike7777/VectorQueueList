/* file: proj7-TestMain.cpp
* author: Michael Mathews
* course: CSI 1440
* assignment: project 7
* due date: 11/2/2021 - extension
*/

#include <iostream>
#include "proj7-MyVector.h"

template <class T>
void display(MyVector<T>);

int main() {
    MyVector<int> a;
    MyVector<int> b;
    int test, front, back;

    try {
        //insert data
        a.pushFront(20);
        a.pushFront(10);
        a.pushBack(30);
        a.pushBack(40);

        display(a);

        //remove from front
        a.popFront(front);

        display(a);
        cout << "First element was: " << front << endl;

        //remove from back
        a.popBack(back);

        display(a);
        cout << "Last element was: " << back << endl;

        cout << endl;

        cout << "Testing operator = ..." << endl;
        //operator =
        b = a;
        display(a);

        cout << "Testing copy constructor..." << endl;
        MyVector<int> c = b;
        display(a);

        cout << endl;

        //testing getSize
        cout << "List's size is: "<< b.getSize() << endl;

        if(a.isEmpty()) {
            cout << "List is empty" << endl;
        }
        else {
            cout << "List is not empty" << endl;
        }
        display(a);

        //testing front and back values
        cout << "Front Data is: " << a.front() << endl;
        cout << "Back Data is: " << a.back() << endl;

        //operator [] overloading
        cout << "Data at index 0: " << a[0] << endl;

        //operator= overloading
        b = a;
        display(b);

        cout << endl;

        b.erase();
        //popBack empty list
        cout << "Should find fail bit: " << endl;
        b.popBack(test);
    }
    catch(BADINDEX bad){
        cout << '\t' << "fail bit found" << endl;
    }
    cout << endl;
    try {
        cout << "Should not find fail bit 2: " << endl;
        a.popFront(test);
    }
    catch(BADINDEX bad){
        cout << '\t' << "fail bit 2 found" << endl;
    }
    cout << endl;
    try {
        cout << "Should find fail bit 3: " << endl;
        cout << b.front() << endl;
    }
    catch(BADINDEX bad){
        cout << '\t' << "fail bit 3 found" << endl;
    }
    cout << endl;
    try {
        cout << "Should find fail bit 4: " << endl;
        cout << b.back() << endl;
    }
    catch(BADINDEX bad){
        cout << '\t' << "fail bit 4 found" << endl;
    }
    cout << endl;
    try {
        cout << "Should find fail bit 5: " << endl;
        cout << a[12] << endl;
    }
    catch(BADINDEX bad){
        cout << '\t' << "fail bit 5 found" << endl;
    }
    return 0;
}

/**
function: display()
description: displays a vector - added function
pre-condition: a object exists
post-condition: the elements of a MyVector are displayed
return: nothing
*/
template <class T>
void display(MyVector<T> obj){
    for(int i = 0; i < obj.getSize(); i++){
        cout << obj[i] << " ";
    }
    cout << endl;
}