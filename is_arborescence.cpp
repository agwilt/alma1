#include <iostream>
#include "graph.h"

bool is_arborescence_with_root_zero(Graph g)
{
	if (g.num_nodes() < 1) return false;
	int m = 0;
	std::vector<Graph::NodeId> Q;
	std::vector<bool> visited(g.num_nodes(), false);

	visited[0] = true;
	Q.push_back(0);

	while (Q.size() > 0) {
		Graph::NodeId cur_node = Q.back();
		Q.pop_back();
		for (auto neighbour : g.get_node(cur_node).adjacent_nodes()) {
			++m;
			if (not visited[neighbour.id()]) {
				Q.push_back(neighbour.id());
				visited[neighbour.id()] = true;
			}
		}
	}
	
	// return false if anything not reachable
	for (int i = 0; i<g.num_nodes(); ++i) {
		if (visited[i] == false) {
			std::cout << "Haven't visited node " << i << "!\n";
			return false;
		}
	}
	
	return m == g.num_nodes() - 1;
}

int main(int argc, char *argv[])
{
	if (argc < 2) return 1;

	Graph g(argv[1], Graph::directed);
	if (is_arborescence_with_root_zero(g)) {
		std::cout << "Your graph is an arborescence with root 0\n";
	} else {
		std::cout << "Your graph isn't an arborescence with root 0\n";
	}
}
