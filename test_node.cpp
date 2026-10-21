#include <iostream>
#include "Node.hpp"

int main() {
    Node a;               // constructeur par defaut
    Node b(1.5, 2);      // constructeur (x, y)
    Node c(b);            // constructeur par copie

    std::cout << "a = " << a << std::endl;   // (0, 0)
    std::cout << "b = " << b << std::endl;   // (1.5, 2)
    std::cout << "c = " << c << std::endl;   // (1.5, 2)

    // accesseur non const : on peut modifier
    a.get_x() = 3;
    a.get_y() = 4;
    std::cout << "a modifie = " << a << std::endl;   // (3, 4)

    // accesseur const : lecture seule
    const Node d(5, 6);
    std::cout << "d.x = " << d.get_x() << ", d.y = " << d.get_y() << std::endl;

    return 0;
}
