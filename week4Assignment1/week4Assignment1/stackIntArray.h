//
//  stackIntArray.h
//  week4Assignment1
//
//  Created by Anh Luong on 8/7/16.
//  Copyright © 2016 Anh Luong. All rights reserved.
//

#ifndef stackIntArray_h
#define stackIntArray_h

#define DEFAULT_STACK_SIZE 10000

extern void stackInit(int capacity);
extern int isEmpty();
extern int size();
extern void push(int i);
extern int pop();
extern int peek();

#endif /* stackIntArray_h */
