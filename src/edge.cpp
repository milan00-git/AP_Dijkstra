#include "include/edge.hpp"

Edge::Edge(Node* from, Node* to, float weight) :
    from(from),
    to(to),
    weight(weight)
{ }

Node* Edge::getFrom() const
{
    return from;
}

Node* Edge::getTo() const
{
    return to;
}

float Edge::getWeight()
{
    return weight;
}

void Edge::setWeight(float newWeight)
{
    this-> weight = newWeight;
}