#ifndef LIST_H
#define LIST_H

#include "Course.h"

template <class T>
class List
{
  protected:
        class Node {
            public:
                T* data;
                Node* next;
                Node() {
                    data = NULL;
                    next = NULL;
                }
                ~Node() {
                    delete data;
                }
        };
        Node* head;
        Node* tail;
    public:
        List();
        ~List();
        void add(T*&);
        void print();
        List& operator+=(T*&);
};

#endif
