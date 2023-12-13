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

    void fixViolation(Node *z) {
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

        fixViolation(z);
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

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        Node *z = new Node(data);
        insertHelper(z);
    }
    void printTree() {
        printLevelOrder();
    }
};
