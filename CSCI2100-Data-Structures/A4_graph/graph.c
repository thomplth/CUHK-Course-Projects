/* graph.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "graph.h"
#include "list.h"
#include "DisjSet.h"
#include "priorityQueue.h"

#define MAX_N 100
/* Possible nodes are node 0, node 1, ..., node 99. */

struct GraphCDT {
    float W[MAX_N*(MAX_N+1)/2];
    bool NodeExists[MAX_N];
};

struct ArcCDT {
    Node i, j; // make sure that both nodes exist, and i <= j
};

GraphADT EmptyGraph() {
    GraphADT G = (GraphADT) malloc(sizeof(*G));
    for(int i = 0; i < MAX_N; i++) {
        G->NodeExists[i] = false;
        for(int j = i + 1; j < MAX_N; j++)
            G->W[j + i*MAX_N - i*(i+1)/2] = INFINITY;
    }
    return G;
}

bool GraphIsEmpty(GraphADT G) {
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            return false;
    return true;
}

bool AddNode(GraphADT G, Node n) {
    if(NodeExists(G, n)) return false;
    G->NodeExists[n] = true;
    return true;
}

bool NodeExists(GraphADT G, Node n) {
    return G->NodeExists[n];
}

listADT AdjacentNodes(GraphADT G, Node n) {
    if(!NodeExists(G, n)) exit(EXIT_FAILURE);
    listADT list = EmptyList();
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            if(ArcExists(G, Arc(n, i)))
                Cons(i, list);
    return list;
}

int Degree(GraphADT G, Node n) {
    if(!NodeExists(G, n)) exit(EXIT_FAILURE);
    int d = 0;
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            if(ArcExists(G, Arc(n, i)))
                d++;
    return d;
}

ArcADT Arc(Node n1, Node n2) {
    if(n1 > 100 || n2 > 100 || n1 < 0 || n2 < 0) exit(EXIT_FAILURE);
    // existence of the nodes and the arc cannot be checked in this function
    /* approved by Mr. Jianwen Zhao */
    ArcADT a = (ArcADT) malloc(sizeof(*a));
    a->i = n1 > n2 ? n2 : n1; // rearrange the order if i > j
    a->j = n1 > n2 ? n1 : n2; //
    return a;
}

Node NodeI(ArcADT a) {
    return a->i;
}

Node NodeJ(ArcADT a) {
    return a->j;
}

bool AddArc(GraphADT G, ArcADT a, float w) {
    if(!NodeExists(G, NodeI(a))) return false;
    if(!NodeExists(G, NodeJ(a))) return false;
    if(ArcExists(G, a)) return false;
    G->W[ArctoIndex(G,a)] = w;
    return true;
}

float ArcWeight(GraphADT G, ArcADT a) {
    if(!NodeExists(G, NodeI(a))) exit(EXIT_FAILURE);
    if(!NodeExists(G, NodeJ(a))) exit(EXIT_FAILURE);
    // We cannot call ArcExists as ArcWeight is required for verification
    return G->W[ArctoIndex(G, a)];
}

bool ArcExists(GraphADT G, ArcADT a) {
    if(ArcWeight(G, a) == INFINITY) return false;
    return true;
}

void PrintAllNodes(GraphADT G) {
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            printf("%d\n", i);
}

void PrintAllArcs(GraphADT G) {
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            for(int j = i + 1; j < MAX_N; j++)
                if(NodeExists(G, j))
                    if(ArcExists(G, Arc(i, j)))
                        printf("(%d,%d) %.0f\n", i, j, ArcWeight(G, Arc(i, j)));
}

/* given */
int ArctoIndex(GraphADT G, ArcADT a) {
    // if (!ArcExists(G, a)) exit(EXIT_FAILURE);
    /* removed due to the loop ArcExists -> ArcWeight -> ArctoIndex -> ArcExists */
    /* approved by Mr. Jianwen Zhao */
    return a->j + a->i*MAX_N - a->i*(a->i+1)/2;
}

/* given */
ArcADT IndextoArc(GraphADT G, int x) {
    ArcADT a = (ArcADT) malloc(sizeof(*a));
    int x1; a->i = 1;
    while (x >= (x1 = (a->i) * MAX_N - (a->i) * (a->i - 1) / 2))
        a->i++;
    a->i--;
    a->j = MAX_N + x - x1;
    return a; // whether the arc exists is not checked!
}

GraphADT mspK(GraphADT G) {
    priorityQueueADT q = EmptyPriorityQueue();
    DisjSetADT s = NewDisjointSet();
    GraphADT min = EmptyGraph();
    
    // add all nodes to the Minimum Spanning Tree min
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            AddNode(min, i);
    
    // enqueue all arcs from graph G to priority queue q
    for(int i = 0; i < MAX_N; i++)
        if(NodeExists(G, i))
            for(int j = i + 1; j < MAX_N; j++)
                if(NodeExists(G, j)) {
                    ArcADT a = Arc(i, j);
                    if(ArcExists(G, a))
                        PriorityEnqueue(q, a, G);
                }
    
    // loop untill all arcs are dequeued
    while(!PriorityQueueIsEmpty(q)) {
        ArcADT a = PriorityDequeue(q, G);
        float w = ArcWeight(G, a);
        // add arc to min when its nodes are not in the same class
        if(Find(NodeI(a), s) != Find(NodeJ(a), s)) {
            AddArc(min, a, w);
            SetUnion(s, NodeI(a), NodeJ(a));
        }
    }
    
    return min;
}
