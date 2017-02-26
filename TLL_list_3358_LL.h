//
// Created by Adam on 2/26/2017.
//

#ifndef STACK_3358_TLL_LIST_3358_LL_H
#define STACK_3358_TLL_LIST_3358_LL_H

/*
 * TLL_list_3358_LL.h
 *
 *  Created on: Mar 22, 2015
 *      Author: Adam
 */

#include <iostream>
#include <assert.h>

using namespace std;

template<typename T>
class List_3358 {

public:

    //***********************************************************
    // List_3358: default constructor
    // Preconditions: None.
    // Postconditions: list is empty, cursor at EOL.

    List_3358();

    //***********************************************************
    // List_3358: copy constructor
    // Preconditions: None
    // Postconditions: New list is created, which is a deep copy of src List.
    //   Cursor position is preserved.

    List_3358(const List_3358 &src);

    //***********************************************************
    // ~List_3358: destructor
    // Preconditions: None.
    // Postconditions: List is destroyed, if dynamically allocated.

    ~List_3358();


    //************************************
    // insert:
    // Preconditions: List is not full.
    // Postconditions: The item has been inserted into the list, the cursor
    //   points to the same element it did before the insert.
    //   The new item is the predecessor of the element at the cursor.
    //   If the cursor is at EOL, the new item is the last element.

    void insert(const T &item);


    //************************************
    // remove:
    // Preconditions: Cursor is not at EOL and list is not empty.
    // Postconditions: The item at the original cursor is removed from the list.
    //   The cursor points to that item's successor,
    //   or EOL if the removed item was the last element in the list.

    void remove();


    //************************************
    // resetFront:
    // Preconditions: None.
    // Postconditions: Cursor points to the first element in the list,
    //   or EOL if the list is empty.

    void resetFront();

    //************************************
    // resetBack:
    // Preconditions: None.
    // Postconditions: Cursor points to the last element in the list.
    //   or EOL if the list is empty.

    void resetBack();


    //************************************
    // advance:
    // Preconditions: None.
    // Postconditions: Cursor points to the successor of the element it was
    //   previously pointing to.  If it was the last element, it is now EOL.
    //   If it was EOL, it remains EOL.

    void advance();

    //************************************
    // backup:
    // Preconditions: None.
    // Postconditions: Cursor points to the predecessor of the element it was
    //   previously pointing to.  If it was the first element, it is now EOL.
    //   If it was EOL, it remains EOL.

    void backup();


    //*******************
    // isEmpty:
    // Preconditions: None.
    // Postconditions: Returns true if the list contains no elements,
    //   and false otherwise.

    bool isEmpty() const;


    //*******************
    // atEOL:
    // Preconditions: None.
    // Postconditions: Returns true if the cursor is at EOL,
    //   and false otherwise.

    bool atEOL() const;


    //*******************
    // isFull:
    // Preconditions: None.
    // Postconditions: Return value is true if the list contains its capacity
    //  of elements, and false otherwise.

    bool isFull() const;


    //*******************
    // getCurrent:
    // Preconditions: Cursor is not at EOL.
    // Postconditions: Returns a copy of the element at the cursor.

    T getCurrent() const;

private:

    // Node type for doubly linked list.
    struct Node {
        T value;
        Node *next;
        Node *previous;
    };

    Node *head;       // first element
    Node *tail;       // last element
    Node *cursor;     // current element

};

template<typename T>
List_3358<T>::List_3358() {
    head = NULL;        //Set head, tail, and cursor to NULL for empty list.
    tail = NULL;
    cursor = NULL;
}

template<typename T>
List_3358<T>::List_3358(const List_3358 &src) {
    head = NULL;    //Initialize had, tail and cursor to NULL for empty list.
    tail = NULL;
    cursor = NULL;

    //to construct a copy of the list
    for (Node *p = src.head; p != NULL; p = p->next) {
        insert(p->value);
    }
    //to put this->cursor in the right position:
    if (src.cursor) {
        //then list isn't empty and cursor isn't NULL
        cursor = head;
        for (Node *p = src.head; p != src.cursor; p = p->next) {
            advance();
        }
    }

}

template<typename T>
List_3358<T>::~List_3358() {
    Node *n;
    Node *p = head;
    while (p != NULL) {
        n = p->next;
        delete p;
        p = n;
    }
}

template<typename T>
void List_3358<T>::insert(const T &item) {
    Node *newNode = new Node; //Create new node passing it value from driver.
    newNode->value = item;
    newNode->next = NULL;        //Set both ends of new node to NULL
    newNode->previous = NULL;
    assert(!isFull());            //Test for precondition

    if (isEmpty())            //if list is empty insert first node.
    {
        head = newNode;
        tail = newNode;
        cursor = newNode->next;


    } else if (cursor != NULL)    //list not empty cursor not at NULL
    {
        if (cursor == head)    //insert newNode after resetFront has been called.
        {
            head->previous = newNode;
            newNode->next = head;
            newNode->previous = NULL;
            head = newNode;
        } else        //insert for cursor at any position except head and NULL.
        {
            Node *n = cursor->previous;
            newNode->next = cursor;
            newNode->previous = n;
            n->next = newNode;
            cursor->previous = newNode;
        }
    } else        //cursor is at EOL insert and update tail.
    {
        tail->next = newNode;
        newNode->previous = tail;
        newNode->next = cursor;
        tail = newNode;
    }

}

template<typename T>
void List_3358<T>::remove() {
    assert(!atEOL() && !isEmpty());

    Node *before = cursor->previous; //points to node before cursor
    Node *after = cursor->next;        //points to node after cursor

    //reset before's next pointer
    if (before == NULL)                //cursor is on first item
    {
        head = after;
    } else {
        before->next = after;
    }
    //reset after's previous pointer
    if (after == NULL) {
        tail = before;
    } else {
        after->previous = before;
    }

    Node *p = cursor;            //save for delete
    cursor = after;

    //deallocate the node we removed
    delete p;

}

template<typename T>
void List_3358<T>::resetFront() {
    cursor = head;                    //set cursor to head of list.
}

template<typename T>
void List_3358<T>::resetBack() {
    cursor = tail;                    //set cursor to tail of list.
}

template<typename T>
void List_3358<T>::advance() {
    cursor = cursor->next;            //move the cursor forward.
}

template<typename T>
void List_3358<T>::backup() {
    cursor = cursor->previous;        //move the cursor back.
}

template<typename T>
bool List_3358<T>::isEmpty() const {
    if (head == NULL && tail == NULL) //if head and tail are NULL list is empty.
    {
        return true;
    }

    return false;
}

template<typename T>
bool List_3358<T>::atEOL() const {
    if (cursor == NULL)    //if cursor equals NULL then it is at EOL
    {
        return true;
    }
    return false;
}

template<typename T>
bool List_3358<T>::isFull() const {
    return false;        //List is never full.
}

template<typename T>
T List_3358<T>::getCurrent() const {
    assert(!atEOL());    //test for precondition then return value at cursor.
    return cursor->value;
}

#endif //STACK_3358_TLL_LIST_3358_LL_H
