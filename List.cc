#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "List.h"

template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
}

List<T>::~List()
{
    Node* current = head;
    Node* prev;
    while(current != NULL) {
        prev = current;
        current = current->next;
        delete prev;
    }
}

void List<T>::add(Course *&c)
{
    //If the list is empty
    if(head == NULL) {
        head = new Node();
        head->data = c;
        tail = head;
        return;
    }
    Node* toAdd = new Node();
    toAdd->data = c;
    //New course is less than the head
    if(!(head->data->lessThan(c))) {
        toAdd->next = head;
        head = toAdd;
        return;
    }

    Node* current = head;
    //General add loop
    while(current->next != NULL) {
        if(!(current->next->data->lessThan(c))) {
            toAdd->next = current->next;
            current->next = toAdd;
            return;
        }
        current = current->next;
    }
    tail = toAdd;
    toAdd->next = current->next;
    current->next = toAdd;
}

void List<T>::print()
{
    Node* current = head;
    while(current != NULL) {
        current->data->print();
        current = current->next;
    }
    if(head == NULL) {
        return;
    }
    cout << "** HEAD: ";
    head->data->print();
    cout << "** TAIL: ";
    tail->data->print();
}

float List<T>::computeGPA()
{
    try {
    Node* current = head;
    float gpa = 0;
    int len = 0;
    while(current != NULL) {
        int grade;
        current->data->getGrade(grade);
        if(grade != -1) {
            gpa += (float)grade;
            len++;
            current = current->next;
        }
    }
    if(gpa > 0) {
        gpa = gpa/(float)len;
    }
    return gpa;
    }
}

int List<T>::computeNumFW()
{
    int numFW = 0;
    Node* current = head;
    while(current != NULL) {
        int grade;
        current->data->getGrade(grade);
        if(grade < 1) {
            numFW++;
        }
        current = current->next;
    }
    cout << "Num FW: " << numFW;
    return numFW;
}