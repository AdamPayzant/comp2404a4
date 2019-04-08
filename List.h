#ifndef LIST_H
#define LIST_H

#include "Course.h"

template <class T>
class List
{
    template <class T>
    class Node {
        template <class T>
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
        float computeGPA();
        int computeNumFW();
    private:
        Node* head;
        Node* tail;
};

#endif