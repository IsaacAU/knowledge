

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

// 1. recursion
void recursor(TreeNode *root, vector<int> &res){
  if(!root) return;
  recursor(root->left, res);
  res.push_back(root->val);
  recursor(root->right, res);
}

vector<int> inorder1(TreeNode *root){
  vector<int> res;
  recursor(root, res);
  return res;
}

// 2. stack
vector<int> inorder2(TreeNode *root){
  vector<int> res;
  TreeNode *nd=root;
  stack<TreeNode*> stk;
  while(nd || !stk.empty()){
    if(nd){
      stk.push(nd);
      nd=nd->left;
    }else{
      nd=stk.top(); stk.pop();
      res.push_back(nd->val);
      nd=nd->right;
    }
  }
  return res;
}

// 3. moore's traverse
vector<int> inorder3(TreeNode *root){
  vector<int> res;
  TreeNode *nd=root;
  while(nd){
    if(nd->left){
      TreeNode *prev=nd->left;
      while(prev->right && prev->right!=nd)
        prev=prev->right;
      if(prev->right){
        prev->right=nullptr;
        res.push_back(nd->val);
        nd=nd->right;
      }else{
        prev->right=nd;
        nd=nd->left;
      }
    }else{
      res.push_back(nd->val);
      nd=nd->right;
    }
  }
  return res;
}



