/**
 * FILE: DIJKSTRA.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED OF DIJKSTRA'S ALGORITHM 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THAT THEY REQUIRE. 
 *
 * THE FUNCTIONS RETURN VALUES TO REPRESENT SUCCESS, ERROR,
 * OR, IN SOME CASES, DATA THAT HAS TO BE RETURNED. THE CALLER 
 * OF THESE FUNCTIONS WILL EXPECT TO RECEIVE THESE RETURN VALUES 
 * IN ORDER TO VERIFY THE OUTCOME OF THE FUNCTION CALL. 
 *
 * IF THERE ARE ANY FUNCTIONS THAT YOU DON'T HAVE TIME TO 
 * IMPLEMENT, PLEASE LEAVE THE EMPTY / DO-NOTHING IMPLEMENTATION
 * FOR THEM IN THIS FILE, OTHERWISE YOUR PROGRAM WON'T COMPILE
 * WHEN IT IS FED INTO OUR TESTER PROGRAM.
 * 
 */

/** 
 * ### INCLUDES
 */
#include <stddef.h>
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "dijkstra.h"   // provides the definition of structs and functions for the Dijkstra implementation

/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * This function should perform the Dijkstra algorithm. It expects to receive a 
 * ready-made graph to work with in the form of an AdjacencyMatrix. It 
 * also expects to receive an empty DijkstraTable which will be pre-initialised and 
 * ready to use. It also expects to receive the starting node on the graph to commence 
 * the algorithm from. 
 * 
 * This function should implement the algorithm, running it on the graph 
 * provided and updating the DijkstraTable with the outcome. After the function 
 * is called, the DijkstraTable will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode)
{
    //set up Dijkstra Table
    for (int x = 0; x < NUMBER_OF_VERTICES; x++){
        pTable->table[x].distance = 999999;
        pTable->table[x].visited = false;
        pTable->table[x].predecessor = 1;

    }

    //check tables are null
    if ((pMatrix == NULL) || (pTable == NULL)) {
        return INVALID_INPUT_PARAMETER;
    }

    //set up. variables
    int current = startNode;
    pTable->table[startNode].distance = 0;

    //loop for nodes 
    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        if (pMatrix->matrix[current][i] > 0) {
            int dist = pTable->table[current].distance + pMatrix->matrix[current][i];
            if (pTable->table[i].visited == false) {
                if (dist < pTable->table[i].distance){
                pTable->table[i].distance = dist;
                pTable->table[i].predecessor = current;
                pTable->table[i].visited = true;
                }
            }
        }

        //change current node for new loop
        int minDistance = 99999;
        for (int y = 0; y < NUMBER_OF_VERTICES; y++) {
        if ((pTable->table[y].distance < minDistance) && (pTable->table[y].visited == false)) {
             minDistance = pTable->table[y].distance;
             current = y;
        } 
        
    }
    return SUCCESS;
}


/**
 * This function should determine the shortest path that exists on a graph 
 * from a given starting node (nodeFrom) to a given end node (nodeTo). 
 * The function expects to receive a pre-populated DijkstraTable which already 
 * contains the outcome of running the Dijkstra algorithm on a graph. It will 
 * also be provided with an array (pathFound) into which the shortest path should 
 * be recorded. The path should be recorded in reverse order; showing, from the 
 * end node, the predecessors that lead us there from the start node. 
 * For example, if the shortest path on graph from node 2 to node 8 was found 
 * to be 2 -> 4 -> 5 -> 8. The content that would be recorded in the ‘pathFound’ 
 * variable would be as follows: [8][5][4][2]. I.e., it shows the relevant nodes 
 * in the path, in reverse order. This includes the start and end node too. After the 
 * function is called, the 'pathFound' will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[])
{
    //check tables and not null
    if ((pTable == NULL) || (pathFound == NULL)) {
        return INVALID_INPUT_PARAMETER; 
    }

    //check nodes are valid 
    if (nodeFrom < 0 || nodeTo < 0) {
        return INVALID_INPUT_PARAMETER;
    }
    
    //set up variables
    int current = nodeTo;
    int index = 0;

    //loop through table till shortest found 
    while (true) {
        pathFound[index] = current;
        index = index + 1;

        if (current == nodeFrom) {
            return SUCCESS;
        }

        if (pTable->table[current].predecessor == -1) {
            return INVALID_INPUT_PARAMETER;
        }

        //set up predecessor
        current = pTable->table[current].predecessor;
    }
    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}