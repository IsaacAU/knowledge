
struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

// 1. recursion
void recursor(TreeNode *root, vector<int> &res){
  if(!root) return;
  recursor(root->left, res);
  recursor(root->right, res);
  res.push_back(root->val);
}

vector<int> postorder1(TreeNode *root){
  vector<int> res;
  recursor(root, res);
  return res;
}

// 2. stack iterative
vector<int> postorder2(TreeNode *root){
  vector<int> res;
  if(!root) return res;
  stack<TreeNode*> stk;
  stk.push(root);
  TreeNode *prev=nullptr;
  while(!stk.empty()){
    TreeNode *nd=stk.top(); stk.pop();
    if(!prev || prev->left==nd || prev->right==nd){
      if(nd->left)
        stk.push(nd->left);
      else if(nd->right)
        stk.push(nd->right);
    }else if(nd->left==prev){
      if(nd->right)
        stk.push(nd->right);
    }else{
      res.push_back(nd->val);
    }
    prev=nd;
  }
  return res;
}

// moore traverse
TO DO










