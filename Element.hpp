#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <cmath>
#include "Node.hpp"

// ---------- Q1 : classe abstraite ----------
class element_base {
public:
    virtual ~element_base() {}                                // destructeur virtuel
    virtual int get_NbNodes() const = 0;                      // nombre de noeuds
    virtual const Node& operator()(int i) const = 0;          // i-eme noeud
    virtual double get_Surface() const = 0;                   // aire (Q4)
};

// ---------- Q2 : triangle ----------
class triangle : public element_base {
private:
    Node nodes_[3];

public:
    triangle(const Node& a, const Node& b, const Node& c) {
        nodes_[0] = a;
        nodes_[1] = b;
        nodes_[2] = c;
    }

    int get_NbNodes() const { return 3; }

    const Node& operator()(int i) const { return nodes_[i]; }

    // aire = 1/2 |(xB-xA)(yC-yA) - (xC-xA)(yB-yA)|
    double get_Surface() const {
        double ax = nodes_[0].get_x(), ay = nodes_[0].get_y();
        double bx = nodes_[1].get_x(), by = nodes_[1].get_y();
        double cx = nodes_[2].get_x(), cy = nodes_[2].get_y();
        return 0.5 * std::fabs((bx - ax) * (cy - ay) - (cx - ax) * (by - ay));
    }
};

// ---------- Q3 : quadrangle ----------
class quadrangle : public element_base {
private:
    Node nodes_[4];

public:
    quadrangle(const Node& a, const Node& b, const Node& c, const Node& d) {
        nodes_[0] = a;
        nodes_[1] = b;
        nodes_[2] = c;
        nodes_[3] = d;
    }

    int get_NbNodes() const { return 4; }

    const Node& operator()(int i) const { return nodes_[i]; }

    // aire = somme des aires des triangles (A,B,C) et (A,C,D)
    // (les noeuds sont donnes dans l'ordre autour du quadrangle)
    double get_Surface() const {
        triangle t1(nodes_[0], nodes_[1], nodes_[2]);
        triangle t2(nodes_[0], nodes_[2], nodes_[3]);
        return t1.get_Surface() + t2.get_Surface();
    }
};

#endif
