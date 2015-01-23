
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
    TreeNode *nd=stk.top();
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
      stk.pop();
    }
    prev=nd;
  }
  return res;
}

// 3. 1 stacks  (preorder first right then left is reversed postorder)
vector<int> postorder3(TreeNode *root){
  vector<int> res;
  if(!root) return res;
  stack<TreeNode*> stk;
  stk.push(root);
  while(!stk.empty()){
    TreeNode *nd=stk.top(); stk.pop();
    res.push_back(nd->val);
    if(nd->left)
      stk.push(nd->left);
    if(nd->right)
      stk.push(nd->right);
  }
  reverse(begin(res), end(res));
  return res;
}

// 4. moore traverse
vector<int> postorder4(TreeNode *root){
  vector<int> res;
  TreeNode dummy(-1);
  dummy->left=root;
  TreeNode *nd=&dummy;
  while(nd){
    if(nd->left){
      TreeNode *prev=nd->left;
      while(prev->right && prev->right!=nd)
        prev=prev->right;
      if(prev->right){
        int sz=res.size();
        TreeNode *tmp=nd->left;
        while(tmp!=nd){
          res.push_back(tmp->val);
          tmp=tmp->right;
        }
        reverse(next(begin(res), sz), end(res));
        prev->right=nullptr;
        nd=nd->right;
      }else{
        prev->right=nd;
        nd=nd->left;
      }
    }else{
      nd=nd->right;
    }
  }
  return res;
}










