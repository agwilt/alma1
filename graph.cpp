// graph.cpp (Implementation of Class Graph)

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <stack>

#include "graph.h"

int fast_atoi( char ** str )
{
	int val = 0;
	while( not (**str == ' ' || **str == '\n' || **str == '\0')) {
		val = val*10 + (*(*str)++ - '0');
	}
	return val;
}

const Graph::NodeId Graph::invalid_node = -1;
const double Graph::infinite_weight = std::numeric_limits<double>::max();


void Graph::add_nodes(NodeId num_new_nodes)
{
	_nodes.resize(num_nodes() + num_new_nodes);
}

Graph::Neighbor::Neighbor(Graph::NodeId n, double w): _id(n), _edge_weight(w) {}

Graph::Graph(NodeId num, DirType dtype): dirtype(dtype), _nodes(num) {}

void Graph::add_edge(NodeId tail, NodeId head, double weight)
{
	if (tail >= num_nodes() or tail < 0 or head >= num_nodes() or head < 0) {
		throw std::runtime_error("Edge cannot be added due to undefined endpoint.");
	}
	_nodes[tail].add_neighbor(head, weight);
	if (dirtype == Graph::undirected) {
		_nodes[head].add_neighbor(tail, weight);
	}
}

void Graph::Node::add_neighbor(Graph::NodeId nodeid, double weight)
{
	_neighbors.push_back(Graph::Neighbor(nodeid, weight));
}

const std::vector<Graph::Neighbor> & Graph::Node::adjacent_nodes() const
{
	return _neighbors;
}

Graph::NodeId Graph::num_nodes() const
{
	return _nodes.size();
}

const Graph::Node & Graph::get_node(NodeId node) const
{
	if (node < 0 or node >= static_cast<int>(_nodes.size())) {
		throw std::runtime_error("Invalid nodeid in Graph::get_node.");
	}
	return _nodes[node];
}

Graph::NodeId Graph::Neighbor::id() const
{
	return _id;
}

double Graph::Neighbor::edge_weight() const
{
	return _edge_weight;
}

void Graph::print() const
{
	if (dirtype == Graph::directed) {
		std::cout << "Digraph ";
	} else {
		std::cout << "Undirected graph ";
	}
	std::cout << "with " << num_nodes() << " vertices, numbered 0,...,"
			<< num_nodes() - 1 << ".\n";

	for (auto nodeid = 0; nodeid < num_nodes(); ++nodeid) {
		std::cout << "The following edges are ";
		if (dirtype == Graph::directed) {
			std::cout << "leaving";
		} else {
			std::cout << "incident to";
		}
		std::cout << " vertex " << nodeid << ":\n";
		for (auto neighbor: _nodes[nodeid].adjacent_nodes()) {
			std::cout << nodeid << " - " << neighbor.id()
					<< " weight = " << neighbor.edge_weight() << "\n";
		}
	}
}

// Warning: this constructor is less careful about checking proper file format
// and totally ignores weight (to strip weight)
Graph::Graph(char const *filename, DirType dtype): dirtype(dtype)
{
	/* Smaller, slower version:
	FILE *fp = fopen(filename, "r");
	Graph::NodeId num = 0;
	Graph::NodeId head, tail;

	if (fp == NULL) {
		throw std::runtime_error("Cannot open file.");
	}

	if (fscanf(fp, "%d\n", &num) != 1) {
		fclose(fp);
		throw std::runtime_error("Invalid file format.");
	}
	add_nodes(num);

	while (fscanf(fp, "%d %d", &head, &tail) == 2) {
		if (tail != head) {
			add_edge(tail, head, 1.0);
		} else {
			throw std::runtime_error("Invalid file format: loops not allowed.");
		}
	}
	fclose(fp);
	*/
	FILE *fp = fopen(filename, "r");
	Graph::NodeId num = 0;	// Number of vertices
	Graph::NodeId head, tail;

	char *line = NULL;		// Line from getline
	char *p;				// Helps parsing line
	size_t len = 0;			// For getline
	//double weight;

	if (fp == NULL) {
		//throw std::runtime_error("Cannot open file.");
		std::cerr << "Error: Cannot open file: " << filename << "\n";
		exit(1);
	}

	// Get number of vertices
	if (fscanf(fp, "%d\n", &num) != 1) {
		fclose(fp);
		//throw std::runtime_error("Invalid file format.");
		std::cerr << "Error: Invalid file format.\n";
		exit(1);
	}
	add_nodes(num);

	// Get edges
	while (getline(&line, &len, fp) != -1) {
		// line has "%d %d"
		p = line;

		// fast_atoi advances p as well as return an int
		head = fast_atoi(&p);
		tail = fast_atoi(&++p);

		/*
		weight = 1.0;
		if (*p == ' ')
			weight = atof(p+1);
			*/

		if (tail != head) {
			add_edge(tail, head, 1.0);
		} else {
			fclose(fp);
			//throw std::runtime_error("Invalid file format: loops not allowed.");
			std::cerr << "Error: Invalid file format: loops not allowed.";
			exit(1);
		}
	}

	free(line);
	fclose(fp);
}

int Graph::zus_komp()
{
	// Current root to DFS from
	int r = 0;
	// Number of Zusammenhangskomponenten
	int components = 0;
	// Should be a boolean, but they're horribly slow
	std::vector<bool> visited(num_nodes(), 0);
	std::stack<int> unexplored;

	// This loops once per Zusammenhangskomponente
	while (r < num_nodes()) {

		// increment number of components every time the loop loops
		++components;
		// then set up some stuff
		unexplored.push(r);
		visited[r] = true;
		if (num_nodes() < MAX_NUM_NODES) std::cout << r;

		while (! unexplored.empty()) {
			auto cur_node = unexplored.top();
			unexplored.pop();
			for (auto node : get_node(cur_node).adjacent_nodes()) {
				if (! visited[node.id()]) {
					visited[node.id()] = true;
					unexplored.push(node.id());
					if (num_nodes() < MAX_NUM_NODES) std::cout << ", " << node.id();
				}
			}
			// if nothing found, pop node
		}

		// find new r
		while (r < num_nodes() && visited[r]) ++r;

		if (num_nodes() < MAX_NUM_NODES) std::cout << std::endl;
	}

	return components;
}

void Graph::nuke_nodes()
{
	_nodes.clear();
}
