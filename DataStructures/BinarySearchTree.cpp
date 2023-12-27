#include <iostream>
#include <stack>
#include <queue>

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int data)
    {
        key = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insertNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return new Node(key);
        }

        if (key < root->key)
        {
            root->left = insertNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = insertNode(root->right, key);
        }

        return root;
    }

    bool searchKey(Node *root, int key)
    {
        if (root == nullptr)
            return false;

        if (key == root->key)
        {
            return true;
        }
        else if (key < root->key)
        {
            return searchKey(root->left, key);
        }
        else
        {
            return searchKey(root->right, key);
        }
    }

    void inorderTraversalRecursive(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorderTraversalRecursive(root->left);
        std::cout << root->key << " ";
        inorderTraversalRecursive(root->right);
    }

    void preorderTraversalRecursive(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        std::cout << root->key << " ";
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }

    void postorderTraversalRecursive(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        std::cout << root->key << " ";
    }

    void inorderTraversalIterative()
    {
        std::stack<Node *> stk;
        Node *current = root;

        while (current != nullptr || !stk.empty())
        {
            while (current != nullptr)
            {
                stk.push(current);
                current = current->left;
            }

            current = stk.top();
            stk.pop();

            std::cout << current->key << " ";
            current = current->right;
        }
    }

    void preorderTraversalIterative()
    {
        if (root == nullptr)
            return;

        std::stack<Node *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            Node *current = stk.top();
            stk.pop();

            std::cout << current->key << " ";

            if (current->right != nullptr)
            {
                stk.push(current->right);
            }
            if (current->left != nullptr)
            {
                stk.push(current->left);
            }
        }
    }

    void postorderTraversalIterative()
    {
        std::stack<Node *> stk;
        Node *current = root;
        Node *lastVisited = nullptr;

        while (current != nullptr || !stk.empty())
        {
            if (current != nullptr)
            {
                stk.push(current);
                current = current->left;
            }
            else
            {
                Node *peekNode = stk.top();

                if (peekNode->right != nullptr && lastVisited != peekNode->right)
                {
                    current = peekNode->right;
                }
                else
                {
                    std::cout << peekNode->key << " ";
                    lastVisited = stk.top();
                    stk.pop();
                }
            }
        }
    }

    void breadthFirstTraversal()
    {
        if (root == nullptr)
            return;

        std::queue<Node *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            Node *current = queue.front();
            queue.pop();

            std::cout << current->key << " ";

            if (current->left != nullptr)
            {
                queue.push(current->left);
            }
            if (current->right != nullptr)
            {
                queue.push(current->right);
            }
        }
    }

    Node *removeNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->key)
        {
            root->left = removeNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = removeNode(root->right, key);
        }
        else
        {
            // In case the node has no children
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
            }

            // In case the node has one child
            else if (root->left == nullptr)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }

            // In case the node has two children
            else
            {
                Node *successor = findMin(root->right);
                root->key = successor->key;
                root->right = removeNode(root->right, successor->key);
            }
        }
        return root;
    }

    Node *findMin(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insertNode(root, key);
    }

    bool search(int key)
    {
        return searchKey(root, key);
    }

    void inorderRecursive()
    {
        inorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    void preorderRecursive()
    {
        preorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    void postorderRecursive()
    {
        postorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    void inorderIterative()
    {
        inorderTraversalIterative();
        std::cout << std::endl;
    }

    void preorderIterative()
    {
        preorderTraversalIterative();
        std::cout << std::endl;
    }

    void postorderIterative()
    {
        postorderTraversalIterative();
        std::cout << std::endl;
    }

    void breadthFirst()
    {
        breadthFirstTraversal();
        std::cout << std::endl;
    }

    void remove(int key)
    {
        root = removeNode(root, key);
    }
};

int main()
{
    BinarySearchTree bst;

    // Inserting elements into the binary search tree;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.insert(62);

    // Inorder traversal (recursive)
    std::cout << "Inorder traversal (recursive): ";
    bst.inorderRecursive();
    std::cout << std::endl;

    // Preorder traversal (recursive)
    std::cout << "Preorder traversal (recursive): ";
    bst.preorderRecursive();
    std::cout << std::endl;

    // Postorder traversal (recursive)
    std::cout << "Postorder traversal (recursive): ";
    bst.postorderRecursive();
    std::cout << std::endl;

    // Inorder traversal (iterative)
    std::cout << "Inorder traversal (iterative): ";
    bst.inorderIterative();
    std::cout << std::endl;

    // Preorder traversal (iterative)
    std::cout << "Preorder traversal (iterative): ";
    bst.preorderIterative();
    std::cout << std::endl;

    // Postorder traversal (iterative)
    std::cout << "Postorder traversal (iterative): ";
    bst.postorderIterative();
    std::cout << std::endl;

    // Breadth-first traversal
    std::cout << "Breadth-first traversal: ";
    bst.breadthFirst();
    std::cout << std::endl;

    // Search elements
    int key{40};
    if (bst.search(key))
    {
        std::cout << key << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << key << " not found in the tree." << std::endl;
    }

    key = 90;
    if (bst.search(key))
    {
        std::cout << key << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << key << " not found in the tree." << std::endl;
    }

    bst.remove(60);
    return 0;
}