#include <iostream>
#include "graph.h"

int main(int argc, char *argv[])
{
	if (argc < 2) return 1;

	Graph g(argv[1], Graph::directed);
	std::vector<std::vector<double>> flow;

	do {
		augment along s-t-aumg.path
	}
	while (there exists a s-t-path in residual graph)
}
