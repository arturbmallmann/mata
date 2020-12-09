#ifndef _DIJKSTRA_H
#define  _DIJKSTRA_H

#include <vector>
#include <list>
#include "Topology.h" //incluindo cabeçalho de "Network.h"

using namespace std;

class Dijkstra {
	public:
		Dijkstra (Network * net) {network = net;}
		~Dijkstra () {}

		void shortest_path (int src, int dest, vector<int> &predecessors, vector< vector<double> > NodesWeight);
		void ajacent_nodes (vector< vector<int> > &AjacentNodes, vector< vector<double> > NodesWeight);

		vector< vector<int> > AjacentNodes;
		list<int> PendingNodes;		
	private:
		Network * network;
};

#endif
