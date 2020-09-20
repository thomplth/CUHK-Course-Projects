/* graph.h */

#include <stdbool.h>
#include "list.h"

typedef struct GraphCDT * GraphADT;
typedef struct ArcCDT * ArcADT;
typedef int Node;

GraphADT EmptyGraph(void);
/* returns an empty undirected graph */
bool GraphIsEmpty(GraphADT);
/* returns whether graph is empty */

bool AddNode(GraphADT, Node);
/* returns whether the operation succeeds */
bool NodeExists(GraphADT, Node);
/* returns whether the node exists */
listADT AdjacentNodes(GraphADT, Node);
/* returns a list of adjacent nodes */
int Degree(GraphADT, Node);
/* returns the degree of node */

ArcADT Arc(Node, Node);
/* returns an arc, if it exists; error otherwise */
/* note that Arc(i,j) is the same as Arc(j,i) */

Node NodeI(ArcADT);
/* returns the node of an arc with smaller index */
Node NodeJ(ArcADT);
/* returns the node of an arc with larger index */

bool AddArc(GraphADT, ArcADT, float);
/* returns whether the operation succeeds */
/* note that the third argument is the weight */
float ArcWeight(GraphADT, ArcADT);
/* returns the weight of an arc, if it exists */
bool ArcExists(GraphADT, ArcADT);
/* returns whether the arc exists */

void PrintAllNodes(GraphADT);
/* prints all existing nodes */
void PrintAllArcs(GraphADT);
/* prints all existing arcs */

int ArctoIndex(GraphADT, ArcADT);
ArcADT IndextoArc(GraphADT, int);

GraphADT mspK(GraphADT);
