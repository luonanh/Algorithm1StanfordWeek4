//
//  stackIntLinked.c
//  weeek4Assignment2
//
//  Created by Anh Luong on 8/7/16.
//  Copyright © 2016 Anh Luong. All rights reserved.
//

#include "stackIntLinked.h"

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct _node {
    int             val;
    struct _node    *next;
} node;

static int check(void);
static node *createNode(int n);

node *first;            // top of stack
int *a = NULL;          // array of integers
int n;                  // number of integers on stack. Index is n - 1
int currentCapacity;    // current capacity of stack in number of integers

/*
 *  Initialize empty stack
 */
void stackInit(int capacity)
{
    first = NULL;
    n = 0;
}

/*
 *  Is this stack empty?
 *  @return true if this stack is empty; false otherwise
 */
int isEmpty()
{
    return first == NULL;
}

/*
 *  Returns the number of items in the stack.
 *  @return the number of items in the stack
 */
int size()
{
    return n;
}

/*
 *  Adds the item to this stack.
 *  @param item the item to add
 */
void push(int i)
{
    /* my way
     node *n1 = createNode(i);
     n1->next = first;
     first = n1;
     n++;
     */
    node *oldFirst = first;
    first = createNode(i);
    first->next = oldFirst;
    n++;
}

/*
 *  Removes and returns the item most recently added to this stack.
 *  @return the item most recently added
 */
int pop()
{
    assert(!isEmpty());
    node *oldFirst = first;     // save item to return
    first = first->next;        // delete first node
    int temp = oldFirst->val;
    free(oldFirst);
    n--;
    assert(check());
    return temp;                // return the saved integer
}

/*
 *  Returns (but does not remove) the item most recently added to this stack.
 *  @return the item most recently added to this stack
 */
int peek()
{
    assert(!isEmpty());
    return first->val;
}

/*
 *  Check internal invariants.
 *  @return true if the current stack is valid. False if there's a problem with the current stack.
 */
static int check(void)
{
    // check a few properties of instance variable "first"
    if (n < 0)
        return 0;
    if (n == 0) {
        if (first != NULL)
            return 0;
    } else if (n == 1) {
        if (first == NULL)
            return 0;
        if (first->next != NULL)
            return 0;
    } else {
        if (first == NULL)
            return 0;
        if (first->next == NULL)
            return 0;
    }
    
    // check internal consistency of instance variable n
    int numberOfNodes;
    node *n1;
    for (n1 = first, numberOfNodes = 0; n1 != NULL && numberOfNodes <= n; n1 = n1->next)    // there's equal sign in numberOfNodes <= n to make the loop exit with n1 != NULL condition and that way, we know the numberOfNodes n is consistent with the number of nodes in the single linked list.
        numberOfNodes++;
    
    if (numberOfNodes != n)
        return 0;
    
    return 1;
}

static node *createNode(int i)
{
    node *n1;
    
    n1 = (node *)calloc(1, sizeof(node));
    assert(n1 != NULL);
    n1->val = i;
    n1->next = NULL;
    return n1;
}