#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "edge.hpp"

class Node
{
    private:
        std::vector<Edge*> edges; //vector genaamd edges
        std::string name; 

    public:
        Node(std::string name); //constructor
        std::string getName() const;

        void addEdge(Edge* edge); //voegt edge toe aan de lijst van edges
        std::vector<Edge*> getEdges() const;

        //operator overloading voor vergelijkingen en output
        friend bool operator<(const Node& lhs, const Node& rhs);
        friend bool operator>(const Node& lhs, const Node& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Node& n);

        
};

struct node_greater_than
{
    //operator overloading voor nodes vergelijken (nodegreaterthan)
    bool operator()(const Node* lhs, const Node* rhs) const;
};