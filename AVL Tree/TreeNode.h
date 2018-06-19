#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <algorithm>
using namespace std;

template <typename keytype, typename infotype>
class TreeNode
{
public:
    TreeNode(keytype new_key, infotype new_info, int new_height, TreeNode* new_left, TreeNode* new_right)
        :key(new_key), info(new_info), height(new_height), left(new_left), right(new_right)
    {}
    
    static int calc_dif(TreeNode* root)
    {
        return root ? calc_height(root->left) - calc_height(root->right) : 0;
    }

    static int calc_height(TreeNode* root)
    {
        return root ? root->height : -1;                                                                                        
    }

    static TreeNode* ll_rotate(TreeNode* root)
    {
        TreeNode* p1 = root->left;
        TreeNode* p2 = root->left->right;
        p1->right = root;
        p1->right->left = p2;
        root->height = 1 + max(calc_height(root->left), calc_height(root->right));
        p1->height = 1 + max(calc_height(p1->left), calc_height(p1->right));

        return p1;
    }

    static TreeNode* rr_rotate(TreeNode* root)
    {
        TreeNode* p1 = root->right;
        TreeNode* p2 = root->right->left;
        p1->left = root;
        root->right = p2;
        root->height = 1 + max(calc_height(root->left), calc_height(root->right));
        p1->height = 1 + max(calc_height(p1->left), calc_height(p1->right));

        return p1;
    }

    static TreeNode* lr_rotate(TreeNode* root)
    {
        root->left = rr_rotate(root->left);
        return ll_rotate(root);
    }

    static TreeNode* rl_rotate(TreeNode* root)
    {
        root->right = ll_rotate(root->right);
        return rr_rotate(root);
    }

    static TreeNode* insert(keytype key, infotype info, TreeNode* root)
    {
        if (!root)
            return new TreeNode(key, info, 0, nullptr, nullptr);
        if (root->key > key)
            root->left = insert(key, info, root->left);
        else if (root->key < key)
            root->right = insert(key, info, root->right);
        else{
            ++root->info;
            return root;
        }
        root->height = 1 + max(calc_height(root->right), calc_height(root->left));
        int difference = calc_dif(root);

        if (difference > 1 && root->left->key > key) // left, left
            return ll_rotate(root);
        else if (difference > 1 && root->left->key < key) // left, right
            return lr_rotate(root);
        else if (difference < -1 && root->right->key < key) // right, right
            return rr_rotate(root);
        else if (difference < -1 && root->right->key > key) // right, left
            return rl_rotate(root);

        return root;
    }

    static TreeNode* find(keytype key, TreeNode* root)
    {
        if (!root)
            return nullptr;
        else if (root->key > key)
            return find(key, root->left);
        else if (root->key < key)
            return find(key, root->right);
        return root;
    }

    static TreeNode* remove(keytype key, TreeNode* root)
    {
        if (!root)
            return root;
        if (root->key > key)
            root->left = remove(key, root->left);
        else if (root->key < key)
            root->right = remove(key, root->right);
        else{
            if (!root->left){
                TreeNode* p = root->right;
                delete root;
                return p;
            }    
            else if (!root->right){
                TreeNode* p = root->left;
                delete root;
                return p;
            }
            else{
                TreeNode* p = min(root->right);
                root->key = p->key;
                root->info = p->info;
                root->right = remove(p->key, root->right);
            }
        }
        root->height = 1 + max(calc_height(root->left), calc_height(root->right));
        int difference = calc_dif(root);

        if (difference > 1 && calc_dif(root->left) >= 0)
            return ll_rotate(root);
        else if (difference > 1 && calc_dif(root->left) < 0)
            return lr_rotate(root);
        else if (difference < -1 && calc_dif(root->right) <= 0)
            return rr_rotate(root);
        else if (difference < -1 && calc_dif(root->right) > 0)
            return rl_rotate(root);

        return root;
    }

    static TreeNode* min(TreeNode* root)
    {
        if (root)
        {
            while(root->left)
                root = root->left;
        }
        return root;
    }
    
    static void inOrderPrint(ostream& out, TreeNode* root)
    {
        if (root)
        {
            inOrderPrint(out, root->left);
            out << root->key << ", " << root->info << endl;
            inOrderPrint(out, root->right);
        }
    }

    static void deleteTree(TreeNode* root)
    {
        if (root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
private:
    template <typename k, typename i>
    friend class BinarySearchTree;
    
    keytype key;
    infotype info;
    int height;
    TreeNode* left;
    TreeNode* right;
};

#endif // TREENODE_H
