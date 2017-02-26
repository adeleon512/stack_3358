//
// Created by Adam on 2/26/2017.
//

#ifndef STACK_3358_T_LIST_3358_H
#define STACK_3358_T_LIST_3358_H

/*
 * T_List_3358.h
 *
 *  Created on: Mar 22, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 3
 *      Description: This header file is a template version of list_3358. It
 *      creates a list of any type specified by the user and performs various
 *      functions for that list. This file contains the function declarations
 *      and function definitions.
 */

#include <assert.h>

using namespace std;

template<class ItemType>
class List_3358 {

public:

    static const int MAX_ITEMS = 100; // maximum number of items in a list.
    static const int EOL = -1;        // represents End of List

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

    void insert(const ItemType &item);


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
    // advance:
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

    ItemType getCurrent() const;


private:

    ItemType values[MAX_ITEMS];  //the list of items in an array
    int cursor;             //the current position
    int currentSize;        //the actual number of elements in the array

};

template<class ItemType>
List_3358<ItemType>::List_3358() {
    currentSize = 0;
    cursor = EOL;
}

template<class ItemType>
List_3358<ItemType>::List_3358(const List_3358 &src) {

    cursor = src.cursor;
    currentSize = src.currentSize;

    for (int i = 0; i < currentSize; i++)
        values[i] = src.values[i];

}

template<class ItemType>
List_3358<ItemType>::~List_3358() {
    //Do nothing, no dynamically allocated memory here
}

template<class ItemType>
void List_3358<ItemType>::insert(const ItemType &item) {
    assert(!isFull());

    if (cursor == EOL)
        values[currentSize] = item;
    else {
        //shift elements after the cursor up by one
        for (int i = currentSize; i > cursor; i--)
            values[i] = values[i - 1];
        //insert at cursor
        values[cursor] = item;
        //advance to successor
        cursor++;
    }

    // count is increased by one
    currentSize++;
}

template<class ItemType>
void List_3358<ItemType>::remove() {
    assert(!atEOL() && !isEmpty());

    //shift elements after the cursor down by one
    for (int i = cursor; i < currentSize - 1; i++)
        values[i] = values[i + 1];

    //decrease number of elements
    currentSize--;

    //if the last item was removed, set cursor to EOL
    if (cursor == currentSize)
        cursor = EOL;

}

template<class ItemType>
void List_3358<ItemType>::resetFront() {
    if (!isEmpty())
        cursor = 0;
}

template<class ItemType>
void List_3358<ItemType>::resetBack() {
    if (!isEmpty())
        cursor = currentSize - 1;
}

template<class ItemType>
void List_3358<ItemType>::advance() {
    if (cursor == EOL)
        return;

    if (cursor < currentSize - 1)
        cursor++;
    else
        cursor = EOL;

}

template<class ItemType>
void List_3358<ItemType>::backup() {
    if (cursor == EOL)
        return;

    if (cursor > 0)
        cursor--;
    else
        cursor = EOL;

}

template<class ItemType>
bool List_3358<ItemType>::isEmpty() const {
    return currentSize == 0;
}

template<class ItemType>
bool List_3358<ItemType>::atEOL() const {
    return cursor == EOL;
}

template<class ItemType>
bool List_3358<ItemType>::isFull() const {
    return currentSize == MAX_ITEMS;
}

template<class ItemType>
ItemType List_3358<ItemType>::getCurrent() const {
    assert(cursor != EOL);

    return values[cursor];
}

#endif //STACK_3358_T_LIST_3358_H
