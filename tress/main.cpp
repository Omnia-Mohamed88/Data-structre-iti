#include <iostream>

using namespace std;

struct TreeNode
{
    TreeNode *leftChild;
    TreeNode *rightChild;
    int value;
    TreeNode()
    {
        leftChild = NULL;
        rightChild = NULL;
    }
    TreeNode(int val)
    {
        value = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BinaryStructure
{

public:
    TreeNode *root;
    BinaryStructure()
    {
        root = NULL;
    }

    void insertValue(int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            TreeNode *currentNode = root;
            while (true)
            {
                if (currentNode->value > newNode->value)
                {
                    if (currentNode->leftChild == NULL)
                    {
                        currentNode->leftChild = newNode;
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->leftChild;
                    }
                }
                else
                {
                    if (currentNode->rightChild == NULL)
                    {
                        currentNode->rightChild = newNode;
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->rightChild;
                    }
                }
            }
        }
    }

    int countTreeNodes(TreeNode *node)
    {
        if (node != NULL)
        {
            return 1 + countTreeNodes(node->leftChild) + countTreeNodes(node->rightChild);
        }
        else
        {
            return 0;
        }
    }

    void displayStructuredTree()
    {
        cout << "InOrder Sequence: ";
        inOrderTraversal(root);
        cout << endl;
        cout << "PreOrder Sequence: ";
        preOrderTraversal(root);
        cout << endl;
        cout << "PostOrder Sequence: ";
        postOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal(TreeNode *node)
    {
        if (node != NULL)
        {
            inOrderTraversal(node->leftChild);
            cout << node->value << " ";
            inOrderTraversal(node->rightChild);
        }
    }

    void preOrderTraversal(TreeNode *node)
    {
        if (node != NULL)
        {
            cout << node->value << " ";
            preOrderTraversal(node->leftChild);
            preOrderTraversal(node->rightChild);
        }
    }

    void postOrderTraversal(TreeNode *node)
    {
        if (node != NULL)
        {
            postOrderTraversal(node->leftChild);
            postOrderTraversal(node->rightChild);
            cout << node->value << " ";
        }
    }

    void eraseValue(int val)
    {
        root = eraseRecursive(root, val);
    }

    TreeNode *eraseRecursive(TreeNode *node, int val)
    {
        if (node == NULL)
        {
            return node;
        }

        if (node->value < val)
        {
            node->rightChild = eraseRecursive(node->rightChild, val);
            return node;
        }

        if (node->value > val)
        {
            node->leftChild = eraseRecursive(node->leftChild, val);
            return node;
        }

        if (node->leftChild == NULL)
        {
            TreeNode *temp = node->rightChild;
            delete node;
            return temp;
        }
        else if (node->rightChild == NULL)
        {
            TreeNode *temp = node->leftChild;
            delete node;
            return temp;
        }
        else
        {
            TreeNode *valParent = node;

            TreeNode *nodeToDelete = root->rightChild;
            while (nodeToDelete->leftChild != NULL)
            {
                valParent = nodeToDelete;
                nodeToDelete = nodeToDelete->leftChild;
            }
            if (valParent != node)
                valParent->leftChild = nodeToDelete->rightChild;
            else
                valParent->rightChild = nodeToDelete->rightChild;

            node->value = nodeToDelete->value;

            delete nodeToDelete;
            return node;
        }
    }
};

int main()
{
    BinaryStructure BinaryTree;

    BinaryTree.insertValue(5);
    BinaryTree.insertValue(12);
    BinaryTree.insertValue(6);
    BinaryTree.insertValue(4);
    BinaryTree.insertValue(10);
    BinaryTree.insertValue(21);
    BinaryTree.insertValue(17);

    BinaryTree.displayStructuredTree();

    cout << "Number of nodes in the main root = " << BinaryTree.countTreeNodes(BinaryTree.root) << endl;

    BinaryTree.eraseValue(17);

    cout << "Node Removed" << endl;

    BinaryTree.displayStructuredTree();
}



