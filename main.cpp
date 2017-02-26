/*
 * evalpostfix.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 3
 *      Description: This file uses stack_3358.h to evaluate a postfix
 *      notation expression using a stack.
 */

#include<cstdlib>
#include<sstream>
#include<iostream>
#include<cstring>
#include<string>
#include "stack_3358.h"

using namespace std;

/*****************************************************************************
 * isOperator function returns true if the char variable passed to it from
 * main is an operator symbol and false otherwise
 */

bool isOperator(char operation) {
    if (operation == '+' || operation == '-' || operation == '*' ||
        operation == '/')
        return true;
    else
        return false;
}

/*****************************************************************************
 * evaluate function takes the operands and operator passed from main and
 * evaluates the expression and returns the result to main.
 */
int evaluate(int op1, int op2, char op) {
    int result;
    switch (op) {
        case '+':
            result = op2 + op1;
            break;
        case '-':
            result = op2 - op1;
            break;
        case '*':
            result = op2 * op1;
            break;
        case '/':
            result = op2 / op1;
            break;
    }

    return result;
}

/****************************************************************************/

int main() {
    Stack_3358<int> stack;            //creates a stack of type int
    char statement[100];
    char alph_num[10];
    string exp;
    int operand1;
    int operand2;
    int size;
    int i;
    int j;
    int num;

    //Ask the user for input
    cout << "Please enter a postfix expression for evaluation: " << endl;

    //grab the string and subtract 1 from the length to erase the end line
    getline(cin, exp);
    exp.erase(exp.length() - 1);

    //convert the string into an array of char
    int c = 0;
    while (c < exp.length()) {
        statement[c] = exp[c];
        c++;
    }

    //Read the statement one character at a time
    j = 0;
    size = strlen(statement);
    for (i = 0; i < size; i++) {//if statement at i is a digit from 0 to 9 then accumulate digits
        if (statement[i] >= '0' && statement[i] <= '9') {
            alph_num[j++] = statement[i];
        }
            //if statement at i is a space then push num and re-initialize digits
        else if (statement[i] == ' ') {
            if (j > 0) {
                alph_num[j] = '\0';
                num = atoi(alph_num);
                stack.push(num);
                j = 0;
            }
        }
            //if statement at i is an operator then call isOperator function
        else if (isOperator(statement[i])) {
            operand1 = stack.pop();
            operand2 = stack.pop();
            stack.push(evaluate(operand1, operand2, statement[i]));
        }
    }

    //Check to make sure expression has valid input.
    if (stack.isEmpty()) {
        cout << "Please enter a valid postfix expression!";
        return 0;
    }
        //Check to make sure expression is valid then pop and display result.
    else {
        int result1 = stack.pop();
        if (!stack.isEmpty()) {
            cout << "Please enter a valid postfix expression!";
            return 0;
        }
        //send an output of the result.
        cout << "The result is " << result1 << ".";
    }

    return 0;
}
