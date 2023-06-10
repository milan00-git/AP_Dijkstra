#pragma once
#include <map>
#include "node.hpp"
#include "edge.hpp"

class Graph
{
    private:
        std::vector<Node*> nodes;
        std::vector<Edge*> edges;

    public:
        Graph(std::vector<Node*> nodes, std::vector<Edge*> edges);
        void addNode(Node* node);
        void addEdge(Edge* edge);
        Edge* getEdge(Node* from, Node* to);

        friend std::ostream& operator<<(std::ostream& os, const Graph& g);
};