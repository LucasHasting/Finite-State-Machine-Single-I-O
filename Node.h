#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node* one = nullptr;
    Node* zero = nullptr;
    bool data = 0;
    Node();
    Node(bool);
};

#endif