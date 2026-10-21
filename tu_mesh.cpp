#include <iostream>
#include <vector>
#include "Node.hpp"
#include "Element.hpp"

// Q5 : maillage hybride de la figure 1 (a droite)
void test() {
    // les 8 noeuds, numerotes comme sur la figure
    Node n[8];
    n[0] = Node(0., 1.);
    n[1] = Node(1., 1.);   // noeud central
    n[2] = Node(1., 2.);
    n[3] = Node(0., 2.);
    n[4] = Node(2., 1.);
    n[5] = Node(2., 2.);
    n[6] = Node(1., 0.);
    n[7] = Node(2., 0.);

    // le maillage : tableau de cellules (triangles ou quadrangles)
    std::vector<element_base*> mesh;
    mesh.push_back(new triangle(n[0], n[1], n[3]));
    mesh.push_back(new triangle(n[3], n[1], n[2]));
    mesh.push_back(new quadrangle(n[1], n[4], n[5], n[2]));
    mesh.push_back(new quadrangle(n[6], n[7], n[4], n[1]));

    // liste des surfaces (appel polymorphe)
    double total = 0.;
    for (int i = 0; i < (int)mesh.size(); i++) {
        std::cout << "element " << i << " : " << mesh[i]->get_NbNodes()
                  << " noeuds, surface = " << mesh[i]->get_Surface() << std::endl;
        total += mesh[i]->get_Surface();
    }
    std::cout << "surface totale = " << total << std::endl;

    // liberation de la memoire
    for (int i = 0; i < (int)mesh.size(); i++)
        delete mesh[i];
}

int main() {
    test();
    return 0;
}
