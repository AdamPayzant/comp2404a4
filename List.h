#ifndef LIST_H
#define LIST_H

#include "Course.h"

template <class T>
class List
{
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

    public:
        List();
        ~List();
        void add(T*&);
        void print();
        List& operator+=(T*&);
    private:
        Node* head;
        Node* tail;
};

#endif
