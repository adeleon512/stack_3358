//
// Created by Adam on 2/26/2017.
//

#ifndef STACK_3358_STACK_3358_H
#define STACK_3358_STACK_3358_H

/*
 * stack_3358.h
 *
 *  Created on: Mar 22, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 3
 *      Description: This file is a Stack ADT. This implementation is a
 *      template. This file uses T_List_3358.h, which is also a template,
 *      to implement all of its functions. This file performs all of the
 *      necessary stack operations.
 */

#include"T_list_3358.h"
#include <assert.h>

using namespace std;

template<class ItemType>
class Stack_3358 {

public:

    //***********************************************************
    // Stack_3358: default constructor
    // Preconditions: None.
    // Postconditions: stack is empty.

    Stack_3358();

    //***********************************************************
    // Stack_3358: copy constructor
    // Preconditions: None.
    // Postconditions: New stack is created, which is a deep copy of src stack.

    Stack_3358(const Stack_3358 & src);

    //****************************
    // makeEmpty: Removes all the items from the stack.
    // Preconditions: None.
    // Postconditions: All the items have been removed

    void makeEmpty();

    //****************************
    // isEmpty: Checks to see if there are any items on the stack.
    // Preconditions: None.
    // Postconditions: Returns true if there are no items on the stack,
    //   else false.

    bool isEmpty() const;

    //****************************
    // isFull: Determines if you have any more room to add items to the stack.
    // Preconditions: None.
    // Postconditions: Returns true if there is no more room to add items,
    //   else false.

    bool isFull() const;

    //****************************
    // push: Adds newItem to the top of the stack.
    // Preconditions: Stack is not full.
    // Postconditions: newItem is at the top of the stack.

    void push(const ItemType & newItem);

    //****************************
    // pop: Removes topItem from stack and returns it.
    // Preconditions: Stack is not empty.
    // Postconditions: Top element has been removed from stack and a copy of the
    //    removed element is returned.

    ItemType pop();

private:

    // insert the necessary member variable(s) here
    List_3358<ItemType> stk;

};
/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ()
{
    List_3358<ItemType> stk;
}

template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty()
{
    while(!isEmpty())	//pop stack until it is empty.
    {
        stk.remove();
    }
}

template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty() const
{
    return stk.isEmpty();
}

template<class ItemType>
bool Stack_3358 <ItemType>::isFull() const
{
    return stk.isFull();
}

template<class ItemType>
void Stack_3358 <ItemType>::push(const ItemType& newItem)
{
    assert(!isFull());		//check if stack is full then reset front and insert.
    stk.resetFront();
    stk.insert(newItem);
}

template<class ItemType>
ItemType Stack_3358 <ItemType>::pop()
{
    assert(!isEmpty());	//check if stack is empty then reset front and save
    ItemType popped;	//and pop and return item.
    stk.resetFront();
    popped = stk.getCurrent();
    stk.remove();
    return popped;
}

#endif //STACK_3358_STACK_3358_H
