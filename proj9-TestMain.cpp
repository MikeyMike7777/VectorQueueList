/* file: proj9-TestMain.cpp
* author: Michael Mathews
* course: CSI 1440
* assignment: project 9
* due date: 11/21/2021
*/

#include <iostream>
#include "proj9-MyList.h"

template <class T>
void display(MyList<T>);

int main() {
    MyList<int> a;
    int val;

    cout << "Testing isEmpty" << endl;
    if(a.isEmpty()){
        cout << "true" << endl;
    }

    cout << "Testing pushFront" << endl;
    a.pushFront(29);
    a.pushFront(27);
    a.pushFront(25);
    display(a);

    cout << "Testing getSize" << endl;
    cout << a.getSize() << endl;

    cout << "Testing pushBack" << endl;
    a.pushBack(31);
    a.pushBack(35);
    display(a);

    cout << "Testing getSize" << endl;
    cout << a.getSize() << endl;

    cout << "Testing copy constructor" << endl;
    MyList<int> b = a;
    display(b);

    cout << "Testing operator =" << endl;
    MyList<int> c;
    c = b;
    display(c);

    cout << "Testing popFront" << endl;
    a.popFront(val);
    cout << val << endl;
    display(a);

    cout << "Testing popBack" << endl;
    a.popBack(val);
    cout << val << endl;
    display(a);

    cout << "Testing popFront error" << endl;
    MyList<int> d;
    try {
        d.popFront(val);
    }
    catch (BADINDEX) {
        cout << "error caught" << endl;
    }

    cout << "Testing popBack error" << endl;
    try {
        d.popBack(val);
    }
    catch (BADINDEX) {
        cout << "error caught" << endl;
    }

    cout << "Testing front" << endl;
    cout << b.front() << endl;

    cout << "Testing back" << endl;
    cout << b.back() << endl;

    cout << "Testing erase" << endl;
    b.erase();
    if(b.isEmpty()){
        cout << "memory erased" << endl;
    }

    cout << "Testing operator[]" << endl;
    cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << endl;

    cout << "Testing operator[] error" << endl;
    try {
        cout << a[10] << endl;
    }
    catch (BADINDEX) {
        cout << "error caught" << endl;
    }
    try {
        cout << a[-1] << endl;
    }
    catch (BADINDEX) {
        cout << "error caught" << endl;
    }

    return 0;
}

template <class T>
void display(MyList<T> list){
    for (int i = 0; i < list.getSize(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
}