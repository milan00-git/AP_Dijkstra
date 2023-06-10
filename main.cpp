#include <iostream>
#include <queue>
#include "src/include/graph.hpp"

/*
pseudocode Dijkstra's algoritme:

function Dijkstra (graph, source): 
    for each node n in graph.nodes:
        dist[n] = infinity //eerst zet alle nodes in dist op infinity 
        prev[n] = undefined //eerst zet alle previous nodes op undefined
        add n to eval
    dist[source] < 0 //de begin node / source op 0 zetten

    // evalueer alle nodes totdat eval leeg is. lege eval = path is gevonden
    while eval is not empty:
        k = node in eval met kleinste weight dist[k] //kijken naar de kleinste waarde
        remove k uit eval

        for each neighbor n of k still in eval: 
            alt = dist[k] + graph.edges(k, n)
            if alt < dist[k]:
                dist[n] <- alt
                prev[n] <- k

    return dist[], prev[] //geef de afgelegde afstanden en hun vorige punten terug
*/

int main()
{
    Node a = Node("a"); Node b = Node("b"); Node c = Node("c"); Node d = Node("d"); Node e = Node("e"); Node f = Node("f");

    Edge a1 = Edge(&a, &b, 4); Edge a2 = Edge(&a, &c, 3);    
    Edge b1 = Edge(&b, &a, 4); Edge b2 = Edge(&b, &c, 5); Edge b3 = Edge(&b, &d, 2);
    Edge c1 = Edge(&c, &a, 3); Edge c2 = Edge(&c, &b, 5); Edge c3 = Edge(&c, &d, 2); Edge c4 = Edge(&c, &e, 1);    
    Edge d1 = Edge(&d, &b, 2); Edge d2 = Edge(&d, &c, 2); Edge d3 = Edge(&d, &e, 1); Edge d4 = Edge(&d, &f, 1);    
    Edge e1 = Edge(&e, &c, 1); Edge e2 = Edge(&e, &d, 1); Edge e3 = Edge(&e, &f, 3);       
    Edge f1 = Edge(&f, &d, 1); Edge f2 = Edge(&f, &e, 3);

    Graph g = Graph(
        {&a, &b, &c, &d, &e, &f},
        {&a1, &a2, &b1, &b2, &b3, &c1, &c2, &c3, &c4, &d1, &d2, &d3, &d4, &e1, &e2, &e3, &f1, &f2}
    );

    std::cout << g << std::endl;

    std::priority_queue<Node*, std::vector<Node*>, Node::> pq; //pq = eval[]
    pq.push(&a);
    pq.push(&b);
    pq.push(&c);
    pq.push(&d);
    pq.push(&e);
    pq.push(&f);

    std::cout << (*pq.top()) << std::endl;    
    pq.pop();
    std::cout << (*pq.top()) << std::endl; 
    pq.pop();
    std::cout << (*pq.top()) << std::endl; 
    pq.pop();
    std::cout << (*pq.top()) << std::endl; 
    pq.pop();
    std::cout << (*pq.top()) << std::endl; 
    pq.pop();
    std::cout << (*pq.top()) << std::endl; 

    return 0;
}
