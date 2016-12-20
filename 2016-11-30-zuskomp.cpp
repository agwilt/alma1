// testgraph.cpp (Read Digraph from File and Print)

#include "graph.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2) return 1;
	Graph g(argv[1], Graph::undirected);
	std::cout << g.zus_komp() << std::endl;
	// Can't be bothered to wait for stupid, slow, unnecessary destructors
	quick_exit(0);
}
