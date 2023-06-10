#include <limits>
#include "include/node.hpp"

Node::Node(std::string name) :
    edges({}),
    name(name)
{}

std::string Node::getName() const
{
    return name;
}

void Node::addEdge(Edge* edge)
{
    edges.push_back(edge);
}

std::vector<Edge*> Node::getEdges() const
{
    return edges;
}

std::ostream &operator<<(std::ostream &os, const Node &n)
{
    os << n.name << ": ";
    for(Edge* edge : n.edges)
    {
        os << edge->getTo()->getName() << " (" << edge->getWeight() << ") ";
    }

    return os;
}

bool operator<(const Node& lhs, const Node& rhs)
{
    //Ja, je leest het goed: Nodes worden vergeleken a.d.h.v. het aantal edges wat ze hebben.
    //In jouw implementatie wil je dit natuurlijk niet. Maar waar sorteer je wel op?
    return lhs.edges.size() < rhs.edges.size();
}

bool operator>(const Node& lhs, const Node& rhs)
{
    return lhs.edges.size() > rhs.edges.size();
}

//nodes met elkaar vergelijken (nodegreaterthan)
bool node_greater_than::operator()(const Node* lhs, const Node* rhs) const
{
    return *lhs > *rhs;
}