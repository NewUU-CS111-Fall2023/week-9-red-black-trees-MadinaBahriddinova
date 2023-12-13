enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node *root;
    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        
        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        
        if (x->right != nullptr)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    void insertFix(Node *z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right;

                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }

                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node *y = z->parent->parent->left;

                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }

                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }
    void deleteFix(Node *x) {
        while (x != root && (x == nullptr || x->color == BLACK)) {
            if (x == x->parent->left) {
                Node *w = x->parent->right;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }

                if ((w->left == nullptr || w->left->color == BLACK) &&
                    (w->right == nullptr || w->right->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right == nullptr || w->right->color == BLACK) {
                        if (w->left != nullptr)
                            w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->right != nullptr)
                        w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node *w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }

                if ((w->right == nullptr || w->right->color == BLACK) &&
                    (w->left == nullptr || w->left->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left == nullptr || w->left->color == BLACK) {
                        if (w->right != nullptr)
                            w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->left != nullptr)
                        w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }

        if (x != nullptr)
            x->color = BLACK;
    }

    void insertHelper(Node *z) {
        Node *y = nullptr;
        Node *x = root;

        while (x != nullptr) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        insertFix(z);
    }
    void deleteNode(Node *z) {
        Node *y, *x;

        if (z->left == nullptr || z->right == nullptr)
            y = z;
        else {
            y = z->right;
            while (y->left != nullptr)
                y = y->left;
        }

        if (y->left != nullptr)
            x = y->left;
        else
            x = y->right;

        if (x != nullptr)
            x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        if (y != z)
            z->data = y->data;

        if (y->color == BLACK)
            deleteFix(x);

        delete y;
    }

    void printLevelOrder() {
        if (root == nullptr)
            return;

        std::queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int nodeCount = q.size();

            while (nodeCount > 0) {
                Node *temp = q.front();
                q.pop();

                if (temp != nullptr) {
                    std::cout << "(" << temp->data << "(";
                    if (temp->color == BLACK)
                        std::cout << "BLACK";
                    else
                        std::cout << "RED";

                    if (temp->left != nullptr || temp->right != nullptr)
                        std::cout << ")(";

                    q.push(temp->left);
                    q.push(temp->right);
                } else {
                    std::cout << "NULL";
                }

                nodeCount--;

                if (nodeCount == 0)
                    std::cout << ")";
                else
                    std::cout << ")";
            }
            std::cout << std::endl;
        }
    }
    void printReverse(Node* node) {
        if (node == nullptr)
            return;

        printReverse(node->left);
        std::cout << "(" << node->data << "(";
        if (node->color == BLACK)
            std::cout << "BLACK)";
        else
            std::cout << "RED)";

        if (node->left != nullptr || node->right != nullptr)
            std::cout << "(";

        printReverse(node->right);

        if (node->left != nullptr || node->right != nullptr)
            std::cout << ")";
        std::cout << ")";
    }

public:
    RedBlackTree() : root(nullptr) {}
    void insert(int data) {
        Node *z = new Node(data);
        insertHelper(z);
    }
    void deleteNode(int data) {
        Node *z = root;
        while (z != nullptr) {
            if (z->data == data) {
                deleteNode(z);
                return;
            } else if (data < z->data) {
                z = z->left;
            } else {
                z = z->right;
            }
        }
        std::cout << "Node with value " << data << " not found in the tree." << std::endl;
    }
    void printTree() {
        printLevelOrder();
    }
    void printTree() {
        printReverse(root);
        std::cout << std::endl;
    }
};
