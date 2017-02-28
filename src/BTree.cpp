#include "BTree.hpp"
#include <iostream>

namespace mpb
{
    
Tree::~Tree()
{
    destroy(root);
}

void Tree::insert(int data)
{
    if (!root)
        root = new Node{ data };
    else
        insert(root, data);
}

bool Tree::exist(int value)
{
    if (!root)
        return false;
    else
        return valueExistInTree(root, value);
}

void Tree::print()
{
    if (!root)
    {
        return;
    }
    else
    {
        printElements(root);
        cout << '\n';
        printElements2(root);
        cout << '\n';
        printElements3(root);
    }
}

void Tree::insert(Node* nd, int data)
{
    if (nd->data > data)
    {
        if (nd->left)
            insert(nd->left, data);
        else
            nd->left = new Node{data};
    }
    else if (nd->data < data)
    {
        if (nd->right)
            insert(nd->right, data);
        else
            nd->right = new Node{data};
    }
}
        
        bool Tree::valueExistInTree(Node* nd, int value)
{
    if (nd->data <= value)
    {
        if (nd->data == value)
            return true;
        else
            valueExistInTree(root->right, value);
    }
    else if (nd->data >= value)
    {
        if (nd->data == value)
            return true;
        else
            valueExistInTree(root->left, value);
    }
    else
        return false;
}

void Tree::printElements(Node* temp)
{
    if (temp)
    {
        std::cout << temp->data << ' ';
        printElements(temp->left);
        printElements(temp->right);
    }
}
        
void Tree::printElements2(Node* tmp)
{
    if (tmp)
    {
        printElements(tmp->left);
        std::cout << tmp->data <<' ';
        printElements2(tmp->right);
    }
}

void Tree::printElements3(Node* tmp)
{
    if (tmp)
    {
        printElements3(tmp->left);
        printElements3(tmp->right);
        std::cout << tmp->data << ' ';
    }
}

void Tree::destroy(Node* tmp)
{
    if (tmp)
    {
        destroy(tmp->left);
        destroy(tmp->right);
        delete tmp;
    }
}

}