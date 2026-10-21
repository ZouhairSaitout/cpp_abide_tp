#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;


// Un noeud du maillage : simplement ses coordonnees (x, y)
class Node {
private:
    double x_, y_;

public:
    // 3 constructeurs
    Node();                          // par defaut : (0, 0)
    Node(double x, double y);        // avec les coordonnees
    Node(const Node& n);             // par copie

    // operateur d'affectation (necessaire car on a ecrit le constructeur par copie)
    Node& operator=(const Node& n);

    // 2 accesseurs + leurs versions const
    double& get_x();
    double& get_y();
    const double& get_x() const;
    const double& get_y() const;
};

// surcharge de l'operateur de flux
ostream& operator<<(ostream& out, const Node& n);

#endif