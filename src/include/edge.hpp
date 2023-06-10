#pragma once
#include <vector>
#include <iostream>
//#include "node.hpp" Dit zou verkeerd gaan, want Node.hpp heeft edge.hpp nodig...

class Node; //...dit (a.k.a. Forward declaration) werkt ook, maar alleen als ik pointers van Nodes gebruik

class Edge //dit is mijn abstracte classe
{
    private:
        // Node from; Dit kan dus niet, probeer maar!
        Node* from;
        Node* to;
        float weight;

    public:    
        Edge(Node* from, Node* to, float weight);
        Node* getFrom() const;
        Node* getTo() const;
        virtual float getWeight();
        virtual void setWeight(float newWeight);
};