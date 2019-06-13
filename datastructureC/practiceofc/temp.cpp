class node{   //一種class叫node 有兩個東西叫nodeptr,value 
  node *nextptr;
  int value;	 
};
class  list  //a(三)引入node結構 
{
  private:
  node *firstptr;
  node *lastptr;
  public:
  void insertatfront(node *,int);
  void removefromfront(node *,node *);
}
//直接寫成function
void insertatfront(node *firstptr,int value)
{
	node *newptr=new(node);   //給他記憶體
	newptr->value=value;      //操作pointer
    newptr->nextptr=NULL;
    newptr->nextptr=firstptr;
	firstptr=newptr;   
}
void removefromfront(node *firstptr,node *lastptr)
{
	if(firstptr==lastptr)  //如果空的 
	{
	   cout<<"list empty";
	   return;
	}
	else
	{
	   node *x;
	   x=firstptr;
	   firstptr=x->nextptr;
	   free(x);	
	}
}
//b
//stack first in first out 所以push 就是insert from first function 
//pop 就是remove from top 然後當firstptr等於lastptr時就是空的
//c
//就是叫你 overload ++ 和 -- 分別當作push 和pop 
//第五題
//a 畫一棵binary tree
class treenode
{
	node *lptr;
	node *rptr;
	int data;
}
//b
//用tree node 結構寫一個function 叫boolean searchnode 會找說特定的value 是否存在 tree裡
bool searchtreeenode(tree t,int v)  //傳入一棵tree,然後搜v是否在tree裡(binary search tree 的結構是=>左<中<右)
{
  treenode *ptr;   //用這個pointer存取
  ptr=t->root;   //將ptr指向根然後再traversal
  if(ptr==NULL)   
   {
     cout<<"tree empty";
   }
   else
   {
      while(x!=NULL)
      {
       if(v>ptr->value)   //如果value比現在node大，代表只可能出現在右邊
         x=x->rptr;
       else if(v==ptr->value)   //找到了
        return true;  
       else if(v<ptr->value)    //如果value比現在node小，代表只可能出現在左邊
        x=x->lptr;
      }
      return false;
   }
}
//c
//利用iterative 方法來traversal這個binary search tree 用stack
 vector<int> inorderTraversal(TreeNode* root)   //inorder
 {
  vector<int> res;  //用來output 結果的陣列
  if (!root) return res;   //如果樹為空，傳空陣列
  stack<TreeNode *> s;   //宣告存 treenode 結構的stack s
  TreeNode *cur = root;   //利用pointer cur 存取整棵樹
  while (cur || !s.empty()) //當cur pointer 指向null 且stack 為空則結束
  {   
    if (cur)   //如果cur 不是null 就把現在的node push 進入stack
    {     
      s.push(cur);
      cur = cur->left;  //向左訪問
    } else 
    {
      TreeNode *node = s.top();   
      s.pop();
      res.push_back(node->val);    //把pop出來的node放入 res
      cur = node->right;    //向右
    }
  }
  return res;
}
//predrder
vector<int> preorderTraversal(TreeNode *root) 
{
  vector<int> res;
  if (!root) return res;
  stack<TreeNode*> s;
  s.push(root);       //先將root放入stack
  while (s.size()>0) 
  {
    TreeNode *node = s.top();   
    s.pop();
    res.push_back(node->val);  //將pop 出的 item 放入 res array
    if (node->right)        //將右邊node push 進入 stack
     s.push(node->right);
    if (node->left)      //將左邊...
     s.push(node->left);
  }
  return res;
}
//postorder
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;
  if (!root) return res;

  stack<TreeNode *> s;
  s.push(root);

  while (s.size()) {    //postorder 順序是左->右->root
    TreeNode *node = s.top();
    if (!node->left && !node->right) {   //如果兩個child皆空再print出來(左右都走過)
      s.pop();
      res.push_back(node->val);
    }
    if (node->right) {      //如果右邊還有child
      s.push(node->right);
      node->right = NULL;    //走過設為空
    }
    if (node->left) {       //如果左邊還有child
      s.push(node->left);
      node->left = NULL;   //走過設null
    }
  }
  return res;
}
//d
//用recursive 方法來traversal這個binary search tree
//preorder
void BinaryTree::Preorder(TreeNode *current){
    if (current) {                          // if current != NULL
        std::cout << current->str << " ";   // V
        Preorder(current->leftchild);       // L
        Preorder(current->rightchild);      // R
    }
}
//inorder
void BinaryTree::Inorder(TreeNode *current){
    if (current) {                          // if current != NULL
        Inorder(current->leftchild);        // L
        std::cout << current->str << " ";   // V
        Inorder(current->rightchild);       // R
    }
}
//postorder
void BinaryTree::Postorder(TreeNode *current){  
    if (current) {                         // if current != NULL
        Postorder(current->leftchild);     // L
        Postorder(current->rightchild);    // R
        std::cout << current->str << " ";  // V
    }
}