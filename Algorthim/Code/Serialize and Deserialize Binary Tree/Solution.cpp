#include <sstream>
#include <iostream>
#include <string>

using namespace std;



class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
      this->val = val;
      this->left = this->right = NULL;
  }
};

void _serialize(TreeNode * root, ostringstream &out)
{
    if(root)
    {
        out<<root -> val<<' ';
        _serialize(root -> left, out);
        _serialize(root -> right, out);
    }
    else
    {
        out<<"# ";
    }
}

TreeNode * _deserialize(istringstream &in)
{
    string val;
    in >> val;

    if(val == "#") return nullptr;

    TreeNode *root = new TreeNode(stoi(val));

    root -> left = _deserialize(in);
    root -> right = _deserialize(in);

    return root;
}

/**
 * This method will be invoked first, you should design your own algorithm 
 * to serialize a binary tree which denote by a root node to a string which
 * can be easily deserialized by your own "deserialize" method later.
 */
string serialize(TreeNode * root) {
    // write your code here
    ostringstream out;
    _serialize(root, out);

    return out.str();

}

/**
 * This method will be invoked second, the argument data is what exactly
 * you serialized at method "serialize", that means the data is not given by
 * system, it's given by your own serialize method. So the format of data is
 * designed by yourself, and deserialize it here as you serialize it in 
 * "serialize" method.
 */
TreeNode * deserialize(string &data) {
    // write your code here
    istringstream in(data);
    return _deserialize(in);
}


int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root-> right = new TreeNode(1);

    cout<<serialize(root);

    return 0;
}

