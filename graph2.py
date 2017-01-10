#!/usr/bin/env python3

class Graph():

    def __init__(self):
        self.vertices = 0
        self.edges = []

    def load_from_file(self, filename):
        fp = open(filename, "r")
        self.vertices = int(fp.readline())
        for edge in [x.split() for x in fp.read().split('\n')[:-1]]:
            if len(edge) == 2:
                edge.append(1.0)
            self.add_edge((int(edge[0]), int(edge[1]), float(edge[2])))

    def sort_edges(self):
        self.edges.sort(key = lambda a: a[2])

    def add_edge(self, edge):
        if edge[0]<self.vertices and edge[1]<self.vertices:
            self.edges.append(edge)
        else:
            raise ValueError

    def mst(self):
        self.sort_edges()
        T = Graph()
        T.vertices = self.vertices
        reached = [False for x in range(self.vertices)]

        for edge in self.edges:
            # TODO: put a test that actually works here ...
            if reached[edge[0]] == False or reached[edge[1]] == False:
                T.add_edge(edge)
                reached[edge[0]] = True;
                reached[edge[1]] = True;

        return T

    def print(self):
        print("%d vertices, %d edges:" % (self.vertices, len(self.edges)))
        for edge in self.edges:
            print("\tFrom %d to %d weight %f" % edge)


if __name__ == "__main__":
    import sys

    G = Graph()
    G.load_from_file(sys.argv[1])
    G.mst().print()
