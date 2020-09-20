#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* create graph */
    GraphADT graph = EmptyGraph();
    
    /* open data file */
    FILE *fp;
    fp = fopen("GraphData.dat", "r");
    
    if(fp == NULL) {
        perror("Error opening file data.txt");
        exit(EXIT_FAILURE);
    }
    
    /* process data */
    char str[100];
    char type;
    int m, n, w;
    
    // each loop represents one line
    while(fgets(str, 100, fp)) {
        // execute when line is not blank
        if(str[0] != '\n') {
            // determine the type of data
            sscanf(str, " %c", &type);
            if(type == 'n') {
                sscanf(str, " %c %d", &type, &m);
                AddNode(graph, m);
            } else if(type == 'a') {
                sscanf(str, " %c %d %d %d", &type, &m, &n, &w);
                AddArc(graph, Arc(m,n), w);
            }
        }
    }
    
    /* print result */
    printf("Printing all Nodes:\n");
    PrintAllNodes(graph);
    printf("\nPrinting all Arcs:\n");
    PrintAllArcs(graph);
    
    graph = mspK(graph);
    
    printf("\nPrinting all Nodes for the Minimum Spanning Tree:\n");
    PrintAllNodes(graph);
    printf("\nPrinting all Arcs for the Minimum Spanning Tree:\n");
    PrintAllArcs(graph);
    
    fclose(fp);
    return 0;
}
