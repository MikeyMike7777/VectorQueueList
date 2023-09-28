//
// Created by Michael Mathews on 12/1/21.
//

#ifndef PROJECT_10_PROJ10_NODE_H
#define PROJECT_10_PROJ10_NODE_H

template <class T>
class Node {
public:
    T data;
    Node <T>*next;

    Node( T d ) {
        data = d;
        next = NULL;
    }

    ~Node( ) {
        delete next;
    }
};

#endif //PROJECT_10_PROJ10_NODE_H
