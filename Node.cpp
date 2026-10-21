#include "Node.hpp"

Node::Node() : x_(0.), y_(0.) {}

Node::Node(double x, double y) : x_(x), y_(y) {}

Node::Node(const Node& n) : x_(n.x_), y_(n.y_) {}

Node& Node::operator=(const Node& n) {
    x_ = n.x_;
    y_ = n.y_;
    return *this;
}

double& Node::get_x() { return x_; }
double& Node::get_y() { return y_; }

const double& Node::get_x() const { return x_; }
const double& Node::get_y() const { return y_; }

std::ostream& operator<<(std::ostream& out, const Node& n) {
    out << "(" << n.get_x() << ", " << n.get_y() << ")";
    return out;
}
