#include <iostream>
#define SPACE 10

using namespace std;

class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        value = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int v){
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class AVLTree{
public: 
    TreeNode *root;
    AVLTree(){
        root = nullptr;
    }

    bool isTreeEmpty(){
        return ((root == nullptr) ? true : false);
    }

    int height (TreeNode *r){
        if (r == nullptr){
            return -1;
        }
        else{
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    int getBalanceFactor(TreeNode *n){
        if (n == nullptr)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode *rightRotate(TreeNode *y){
        TreeNode *x = y->left;
        TreeNode *T2 = x -> right;

        // Perform rotation
        x -> right = y;
        y -> left = T2;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x){
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // Perform rotation
        y -> left = x;
        x -> right = T2;

        return y;
    }

    TreeNode* insert(TreeNode *r, TreeNode *new_node){
        if(r == nullptr){
            r = new_node;
            cout << "Value inserted successfully " << endl;
            return r;
        }

        if (new_node -> value < r -> value){
            r -> left = insert(r -> right, new_node);
        }
        else if(new_node -> value > r -> value){
            r -> right = insert(r -> right, new_node);
        }
        else{
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left left Case
        if (bf > 1 && new_node -> value < r -> left -> value)
            return rightRotate(r);

        // Right Right case
        if (bf < -1 && new_node -> value > r -> left -> value)
            return leftRotate(r);

        // Left Right case
        if (bf > 1 && new_node -> value > r -> left -> value){
            r -> left = leftRotate(r -> left);
            return rightRotate(r);
        }

        // Right Left Case
        if (bf < -1 && new_node -> value < r -> right -> value){
            r -> right = rightRotate(r -> right);
            return leftRotate(r);
        }

        /* Return the (maybe unchanged) node pointer */
        return r;
    }

    void print2D(TreeNode *r, int space){
        if (r != nullptr){
            space += SPACE;
            print2D(r->right, space);
            cout << endl;
            for (int i = SPACE; i < space; i++){
                cout << " ";
            }
            cout << r -> value << endl;
            print2D(r -> left, space);
        }
    }

    TreeNode* recursiveSearch(TreeNode* r, int val){
        if (r == nullptr || r-> value == val)
            return r;
        else if (val < r -> value)
            return recursiveSearch(r -> left, val);
        else
            return recursiveSearch(r -> right, val);
    }
};