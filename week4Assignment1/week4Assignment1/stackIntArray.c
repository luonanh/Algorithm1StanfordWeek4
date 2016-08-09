//
//  stackIntArray.c
//  week4Assignment1
//
//  Created by Anh Luong on 8/7/16.
//  Follow http://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/ResizingArrayStack.java.html
//  Copyright © 2016 Anh Luong. All rights reserved.
//

#include "stackIntArray.h"
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

static void resize(int capacity);

int *a = NULL;          // array of integers
int n;                  // number of integers on stack. Index is n - 1
int currentCapacity;    // current capacity of stack in number of integers

/*
 *  Initialize empty stack
 */
void stackInit(int capacity)
{
    if (capacity <= 0)
        capacity = DEFAULT_STACK_SIZE;
    a = (int *)calloc(capacity, sizeof(int));
    assert(a != NULL);
    n = 0;
    currentCapacity = capacity;
}

/*
 *  Is this stack empty?
 *  @return true if this stack is empty; false otherwise
 */
int isEmpty()
{
    return n == 0;
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
 *  resize the underlying array holding the elements
 */
static void resize(int capacity)
{
    a = realloc(a, capacity * sizeof(int));
    assert(a != NULL);
    currentCapacity = capacity;
}

/*
 *  Adds the item to this stack.
 *  @param item the item to add
 */
void push(int i)
{
    if (n == currentCapacity)
        resize(2 * currentCapacity);
    a[n++] = i;
}

/*
 *  Removes and returns the item most recently added to this stack.
 *  @return the item most recently added
 */
int pop()
{
    assert(!isEmpty());
    int temp = a[n-1];
    a[n-1] = INT_MAX;
    n--;
    
    // shrink size of array if necessary
    if (n > 0 && n == currentCapacity / 4)
        resize(currentCapacity / 2);
    return temp;
}

/*
 *  Returns (but does not remove) the item most recently added to this stack.
 *  @return the item most recently added to this stack
 */
int peek()
{
    assert(!isEmpty());
    return a[n-1];
}

