#ifndef __BTREE_HPP__
#define __BTREE_HPP__

namespace mpb
{
    class Tree
    {
    private:
        struct Node
        {
            int data;
            Node* left = nullptr;
            Node* right = nullptr;
            Node(int _d) : data{ _d }
            {}
        };
    public:
        ~Tree();

        void insert(int data);

        bool exist(int value);

        void print();
    private:

        void insert(Node* nd, int data);
        
        bool valueExistInTree(Node* nd, int value);

        void printElements(Node* temp);
        
        void printElements2(Node* tmp);

        void printElements3(Node* tmp);

        void destroy(Node* tmp);

        Node* root = nullptr;
    };
}
#endif