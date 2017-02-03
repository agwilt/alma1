#include <iostream>
#include "graph.h"

bool digraph_ist_kreis(Graph const & graph)
{
	if (graph.num_nodes() <= 1) return true;

	Graph::NodeId num_nodes = graph.num_nodes();
	Graph::NodeId node = 0;
	std::vector<bool> visited(num_nodes, false);
	std::cout << num_nodes << std::endl;

	for (Graph::NodeId i = 0; i < num_nodes; ++i) {
		visited[node] = true;
		if (graph.get_node(node).adjacent_nodes().size() != 1)
			return false;
		node = graph.get_node(node).adjacent_nodes()[0].id();
	}

	for (bool found_node : visited) {
		if (not found_node) return false;
	}
	return true;

}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		Graph g(argv[1], Graph::directed);
//		g.print();
		if (digraph_ist_kreis(g)) {
			std::cout << "Graph is a circle.\n";
		} else {
			std::cout << "Graph isn't a circle.\n";
		}
	}
	return 0;
}
