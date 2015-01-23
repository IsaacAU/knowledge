

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 1. recursion
vector<int> preorder1(TreeNode *root){
  vector<int> res;
  recursor(root, res);
  return res;
}

void recursor(TreeNode *root, vector<int> &res){
  if(!root) return;
  res.push_back(root->val);
  recursor(root->left, res);
  recursor(root->right, res);
}

// 2. stack iterative
vector<int> preorder2(TreeNode *root){
  vector<int> res;
  if(!root) return res;
  stack<TreeNode*> stk;
  stk.push(root);
  while(!stk.empty()){
    TreeNode *nd=stk.top(); stk.pop();
    res.push_back(nd->val);
    if(nd->right) stk.push(nd->right);
    if(nd->left)  stk.push(nd->left);
  }
  return res;
}

// 3. moore traverse
vector<int> preorder3(TreeNode *root){
  vector<int> res;
  TreeNode *nd=root;
  while(nd){
    if(nd->left){
      TreeNode *prev=nd->left;
      while(prev->right && prev->right!=nd)
        prev=prev->right;
      if(prev->right){
        prev->right=nullptr;
        nd=nd->right;
      }else{
        res.push_back(nd->val);
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









