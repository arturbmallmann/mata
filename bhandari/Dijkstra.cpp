#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include "Dijkstra.h"

#define EPSILON 0.00000001

using namespace std;

//Comparar números com duplo envolvimento é tentar dizer se os números estão próximos o suficiente.
int compare_double (double a, double b) {
	return abs (a - b) < EPSILON;
}


void Dijkstra::ajacent_nodes (vector< vector<int> > &AjacentNodes, vector< vector<double> > NodesWeight) {

	vector <int> HAjecentNodes;

	for (int i = 0; i < network->NumofNodes; i++) {
		for (int j = 0; j <network->NumofNodes; j++) {
			if (!compare_double (NodesWeight[i][j], INT_MAX) && (j != i))
				HAjecentNodes.push_back (j); 	
		}
		AjacentNodes.push_back (HAjecentNodes);
		network->NumofAjacentNodes.push_back (HAjecentNodes.size ());
		HAjecentNodes.clear ();
	}
}


void Dijkstra::shortest_path (int src, int dest, vector<int> &predecessors, vector< vector<double> > NodesWeight) {

	vector<double> dist;	
	vector<bool> visited;
	int next;
	int MinDist;
	list<int>::iterator k, indexMD;

	// Inicialização
	for (int i = 0; i < network->NumofNodes; i++) {
		dist.push_back (INFINITY);
		predecessors.push_back (-1);
	}

	dist[src] = 0;
	next = src;
	for (int i = 0; i < AjacentNodes[next].size (); i++) {
		dist[AjacentNodes[next][i]] = dist[src] + NodesWeight[next][AjacentNodes[next][i]];
		predecessors[AjacentNodes[next][i]] = src;
		PendingNodes.push_back (AjacentNodes[next][i]);
	}


	// Interação
	while (!PendingNodes.empty ()) {
		MinDist = INFINITY;
		for (k = PendingNodes.begin (); k != PendingNodes.end (); k++) {
			if (dist[*k] < MinDist) {
				MinDist = dist[*k];
				indexMD = k;
			}
		}
		next = *indexMD;
		PendingNodes.erase (indexMD);

		if (next == dest) {
			break;
		}
		else {
			for (int i = 0; i < AjacentNodes[next].size (); i++) {
				if (dist[next] + NodesWeight[next][AjacentNodes[next][i]] < dist[AjacentNodes[next][i]]) {
					dist[AjacentNodes[next][i]] = dist[next] + NodesWeight[next][AjacentNodes[next][i]];
					bool IdenticalFlag = false;
					for (k = PendingNodes.begin (); k != PendingNodes.end (); k++) {
					if (*k == AjacentNodes[next][i]) IdenticalFlag = true;
					}
					if (IdenticalFlag == false)
						PendingNodes.push_back (AjacentNodes[next][i]);
					predecessors[AjacentNodes[next][i]] = next;
				}
			}
		}
	}
}

