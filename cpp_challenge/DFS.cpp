#include <iostream>
#include <random>
#include <stack>
#include <ctime>

class Node {
    class Node* left;
    class Node* right;
    int randomData;

    //void setData(int data);
    public:
    void setData(int data) {
        randomData = data;
    }
    void setLeftChild(class Node* leftChild) { // self keyword?
        left = leftChild;
    }
    void setRightChild(class Node* rightChild) {
        right = rightChild;
    }
};

class Node* fillNode(class Node* node) { // replace w ctor
    class Node* leftNode = new Node();
    class Node* rightNode = new Node();
    leftNode->setData(rand() % 1000);
    rightNode->setData(rand() % 1000);
}

void buildRandomTree(class Node* root, int size) { // recursion?
    std::stack childlessNodes;
    childlessNodes.push_back(root);
    while(size > 0) {
        // fill children of stack
    }
}

int main() {

    std::cout << "Hello DFS" << std::endl;
    srand(time(0));
    class Node* root = new Node();
    root->setData(rand() % 1000);

    buildRandomTree(root, 15);
}