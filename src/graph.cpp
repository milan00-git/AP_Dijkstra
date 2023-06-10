#include "include/graph.hpp"
#include <iostream>

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) :
    nodes(nodes),
    edges(edges)
{
    for(Edge* edge : edges)
    {
        edge->getFrom()->addEdge(edge);
    }
}

void Graph::addNode(Node* node)
{
    nodes.push_back(node);
}
void Graph::addEdge(Edge* edge)
{
    edge->getFrom()->addEdge(edge);
} 

Edge* Graph::getEdge(Node* from, Node* to)
{
    
    std::cout << std::endl;
    std::cout << nodes.size() << std::endl;
    std::cout << edges.size() << std::endl;

    std::cout << from->getName() << std::endl;
    std::cout << from->getEdges().size() << std::endl;
    for(Edge* edge : from->getEdges())
    {
        if(edge->getTo()->getName() == to->getName())
        {
            return edge;
        }
    }

    return nullptr;
} 

std::ostream& operator<<(std::ostream& os, const Graph& g)
{
    for(Node* node : g.nodes)
    {
        os << (*node) << std::endl;
    }

    return os;
}