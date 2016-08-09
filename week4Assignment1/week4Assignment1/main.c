//
//  main.c
//  week4Assignment1
//
//  Created by Anh Luong on 8/5/16.
//  Copyright © 2016 Anh Luong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stackIntArray.h"

typedef enum {FALSE, TRUE} BOOLEAN;
typedef struct _node {
    int     label;
    BOOLEAN explored;
    int     distance;   // need to be initialized to -1
} node;

typedef struct _graph {
    int     numNode;
    int     numEdge;
} graph;

// Implement queue using doubly linked list
// Operation - remove from the front
// Operation - add to the end
typedef struct _queue {
    
} queue;

int main(int argc, const char * argv[]) {
    int stack[] = {1, 2, 3, 4, 5, 6};
    int i, temp ;
    int *ptr;
    int stackNum;
    
    printf("sizeof(stack) is %lu\n", sizeof(stack));
    ptr = (int *)malloc(sizeof(stack));
    for (i = 0; i < sizeof(stack) / sizeof(int); i++) {
        *(ptr + i) = stack[i];
        printf("ptr[%d] is %d\n", i, ptr[i]);
    }
    
    ptr = realloc(ptr, 10 * sizeof(int));
    printf("sizeof(stack) is %lu\n", 10 * sizeof(int));
    for (i = 0; i < 10 ; i++) {
        printf("ptr[%d] is %d\n", i, ptr[i]);
    }
    free(ptr);
    
    FILE *fp = NULL;
    
    printf("argv[1] is %s\n", argv[1]);
    if ((fp = fopen(argv[1], "r+")) == NULL) {
        printf("Failed to read %s\n", argv[1]);
        return 1;
    }
        
    fscanf(fp, "%d", &stackNum);
    stackInit(stackNum);
    printf("Stack push : ");
    while (fscanf(fp, "%d", &temp) != EOF) {
        printf("%d ", temp);
        push(temp);
    }
    printf("\nTop of stack %d\n", peek());
    i = stackNum;
    printf("Stack pop : ");
    while (stackNum-- > 0) {
        printf("%d ", pop());
    }
    printf("\n");
    fclose(fp);
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

// return the removed node
node *removeFromFront(queue *q)
{
    return NULL;
}
void bfs(graph *g, node s)
{
    // start with S, mark S as explored, then add it to the queue
    // if the queue is not empty,
    
}