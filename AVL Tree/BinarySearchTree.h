#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "TreeNode.h"

template <typename keytype, typename infotype>
class BinarySearchTree
{
public:
    BinarySearchTree()
        :root(nullptr)
    {}

    void insert(keytype key, infotype info)
    {
        root = TreeNode<keytype, infotype>::insert(key, info, root);
    }

    infotype find(keytype key)
    {
        TreeNode<keytype, infotype>* tp = TreeNode<keytype, infotype>::find(key, root);
        if (!tp)
        {
            insert(key, 0);
            tp = TreeNode<keytype, infotype>::find(key, root);
        }
        return tp->info;
    }

    infotype& operator [](keytype key)
    {
        TreeNode<keytype, infotype>* tp = TreeNode<keytype, infotype>::find(key, root);
        if (!tp)
            cout << "Not Found" << endl;
        else
            return tp->info;
    }

    void remove(keytype key)
    {
        root = TreeNode<keytype, infotype>::remove(key, root);
    }

    int height()
    {
        return TreeNode<keytype, infotype>::height(root);
    }
    
    void print(ostream& out)
    {
        TreeNode<keytype, infotype>::inOrderPrint(out, root);
    }

    ~BinarySearchTree()
    {
        TreeNode<keytype, infotype>::deleteTree(root);
    }
private:
    TreeNode<keytype, infotype>* root;
};

template <typename keytype, typename infotype>
ostream& operator << (ostream& out, BinarySearchTree<keytype, infotype>& bst)
{
    bst.print(out);
    return out;
}

#endif // BINARYSEARCHTREE_H
