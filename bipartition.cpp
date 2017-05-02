#include <iostream>
#include <queue>

#include "graph.h"

void qprint(std::queue<Graph::NodeId> q)
{
	std::cout << "Queue has " << q.size() << " elements:\n";
	std::cout << "Front: " << q.front() << std::endl;
	std::cout << "Back: " << q.back() << std::endl;
	return;
}

// 0: not visited, 'a': \in A, 'b': \in B
void print_bipartite(Graph graph)
{
	Graph::NodeId cur_nodeid;
	Graph::NodeId r = 0;

	std::vector<bool> visited(graph.num_nodes(), false);
	std::vector<Graph::NodeId> A;
	std::vector<int> dist(graph.num_nodes(), -1);

	std::queue<Graph::NodeId> Q;

	while (r < graph.num_nodes()) {

		Q.push(r);
		visited[r] = true;

		while (not Q.empty()) {
			cur_nodeid = Q.front();
			Q.pop();
			if (dist[cur_nodeid] % 2 == 0) {
				A.push_back(cur_nodeid);
			}
			for (auto neighbour : graph.get_node(cur_nodeid).adjacent_nodes()) {
				if (not visited[neighbour.id()]) {
					visited[neighbour.id()] = true;
					dist[neighbour.id()] = dist[cur_nodeid] + 1;
					Q.push(neighbour.id());
				}
			}
		}

		// find new r
		while (r < graph.num_nodes() && visited[r]) ++r;

	}

	// Now, check that all edges in delta(A) land in B.
	for (auto node : A) {
		// Check if neighbours are in A
		for (auto neighbour : graph.get_node(node).adjacent_nodes()) {
			if (dist[neighbour.id()] % 2 == 0) {
				std::cout << "Oh dear. It would appear that there's an odd circle.\n";
				return;
			}
		}
	}

	// A, V(G)\A is a Bipartition
	std::cout << "A = {";
	for (auto node : A) {
		std::cout << node << ", ";
	}
	std::cout << "\b\b}\n";

	return;
}

int main(int argc, char *argv[])
{
	if (argc < 2) return 1;
	Graph g(argv[1], Graph::undirected);
	print_bipartite(g);
	return 0;
}
