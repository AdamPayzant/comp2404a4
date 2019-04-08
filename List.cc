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

template <class T>
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

template <class T>
void List<T>::add(T *&c)
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

template <class T>
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

template <class T>
List<T>& List<T>::operator+=(T*& c)
{
  this->add(c);
  return *this;
}
