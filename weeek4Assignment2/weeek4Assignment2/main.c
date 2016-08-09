//
//  main.c
//  weeek4Assignment2
//
//  Created by Anh Luong on 8/6/16.
//  Copyright © 2016 Anh Luong. All rights reserved.
//

/*
 Problem description:
 The file contains the edges of a directed graph. Vertices are labeled as positive integers from 1 to 875714. Every row indicates an edge, the vertex label in first column is the tail and the vertex label in second column is the head (recall the graph is directed, and the edges are directed from the first column vertex to the second column vertex). So for example, the 11th row looks liks : "2 47646". This just means that the vertex with label 2 has an outgoing edge to the vertex with label 47646
 
 Your task is to code up the algorithm from the video lectures for computing strongly connected components (SCCs), and to run this algorithm on the given graph.
 
 Output Format: You should output the sizes of the 5 largest SCCs in the given graph, in decreasing order of sizes, separated by commas (avoid any spaces). So if your algorithm computes the sizes of the five largest SCCs to be 500, 400, 300, 200 and 100, then your answer should be "500,400,300,200,100" (without the quotes). If your algorithm finds less than 5 SCCs, then write 0 for the remaining terms. Thus, if your algorithm computes only 3 SCCs whose sizes are 400, 300, and 100, then your answer should be "400,300,100,0,0" (without the quotes). (Note also that your answer should not have any spaces in it.)
 */
#include <stdio.h>
#include <stdlib.h>
#include "stackIntLinked.h"

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
// Operation - remove from the back
// Operation - add to the back
typedef struct _stack {
    
} stack;
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

// 1st implementation: modify BFS and use stack instead of queue
// 2nd implementation: recursive
void dfs(graph *g, node *start)
{
    // mark start as explored
    
    // for every edge (start, v):
    // if v unexplored, then recursively dfs(g, v)
}

// application: when there's precedence contraints. Example: course prerequisite in college. Question: does a directed graph has topological ordering? Requirement: graph must be acyclic. Use DFS to compute topological ordering in linear time. Observation: every directed acyclic graph has a sink vertex (a vertex without any outgoing arcs).
void topologicalSort(graph *g)
{
    // mark all nodes unexplored
    
    // bookeeping: current_label = n: to keep track of ordering
    
    // for each vertex v in G: can be in arbitrary order
    //      if v not yet explored (in some previous DFS call), dfs(g, v)
    
    // dfs()
    // mark node start as explored
    // for every edge (start, v):
    //      if v unexplored, then recursively dfs(g, v)
    // (could be in base case) set f(s) = current_label. f() is the function provides topological ordering.
    // current_label--
}

void scc(graph *g)
{
    // Algorithm
    // 1st step: Let g_rev = g with all arcs reserved
    
    // 2nd step: run DFS_loop on g_rev --> goal: compute "magical ordering" of nodes. Let f(v) = "finishing time" of the each v in V (set of vertices in g).
    // 3rd step: run DFS_loop on G --> goal: discover the SCCs one-by-one. Processing nodes in decreasing order of finishing times. Strongly connected components (SCCs) = nodes with the same "leader".
    
    // Implementation
    
    /*
     DFS_Loop (graph G)
     global variable t = 0 (for finishing times in 1st pass). t indicates the number of nodes processed so far.	
     global variable s = NULL (for leaders in 2nd pass). s indicates the current source vertex (aka the most recent vertex from which the DFS was initiated).
     Assume nodes labelled 1 to n.
     For i = n down to 1
        if i not yet explored
            s = i;
            DFS(G, i)
     */
    /*
     DFS(graph G, node i)
     - mark i as explored (for rest of DFS_loop)
     - set leader(i) = node s
     - for each arc (i, j) in G:
        - if j not yet explored:
            - DFS(G, j)
     - t++
     - set f(i) = t, f() is the finishing time function of node i
     */
}