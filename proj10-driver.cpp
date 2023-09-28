/* file: proj10-driver.cpp
* author: Michael Mathews
* course: CSI 1440
* assignment: project 10
* due date: 12/6/2021
*/

#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
    Queue1<int> q1;
    Queue2<int> q2;
    Queue3<int> q3;
    srand(time(0));
    double initial, final, seconds;
    int val;

    //Queue 1
    for(int i = 0; i < 100; i++){
        q1.enqueue(rand()%1000);
    }
    initial = time(0);
    for(int i = 0; i < 100; i++){
        q1.dequeue(val);
        cout << val << setw(4);
    }
    cout << endl;
    final = time(0);

    //calculate time difference
    seconds = final-initial;
    cout << "Dequeue time: " << setprecision(4) << fixed << seconds << " seconds" << endl;

    //Queue 2
    for(int i = 0; i < 100; i++){
        q2.enqueue(rand()%1000);
    }
    initial = time(0);
    for(int i = 0; i < 100; i++){
        q2.dequeue(val);
        cout << val << setw(4);
    }
    cout << endl;
    final = time(0);

    //calculate time difference
    seconds = final-initial;
    cout << "Dequeue time: " << setprecision(4) << fixed << seconds << " seconds" << endl;

    //Queue 3
    for(int i = 0; i < 100; i++){
        q3.enqueue(rand()%1000);
    }
    initial = time(0);
    for(int i = 0; i < 100; i++){
        q3.dequeue(val);
        cout << val << setw(4);
    }
    cout << endl;
    final = time(0);

    //calculate time difference
    seconds = final-initial;
    cout << "Dequeue time: " << setprecision(4) << fixed << seconds << " seconds" << endl;

    return 0;
}

