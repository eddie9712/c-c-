#include <iostream>
#include <string>
#include <queue>
using namespace std;
class BST;
class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    string element;
public:
    TreeNode():leftchild(0),rightchild(0),parent(0),key(0),element(""){};
    TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0),key(a),element(b){};

    int GetKey(){return key;}              // 為了在main()要能夠檢視node是否正確
    string GetElement(){return element;}   // 才需要這兩個member function讀取private data

    // 其餘情況, 因為class BST是class TreeNode的friend class
    // 在class BST的member function中, 可以直接存取class TreeNode的private data

    friend class BST;   // 放在 private 或 public 都可以 
};
class BST{
public:
     TreeNode *root;
    BST():root(0){};
     TreeNode* Leftmost(TreeNode *current);
    TreeNode* rightmost(TreeNode *current);
    TreeNode* Successor(TreeNode *current);
    TreeNode* Predecessor(TreeNode *current);
    TreeNode* Search(int key);
    void InsertBST(int key, string element);
    void InorderPrint();        // 可以用來確認BST是否建立成功
    void Levelorder();          // 可以確認BST是否建立成功
    friend class TreeNode;
     void DeleteBST(int key);

};
TreeNode* BST::Search(int KEY){    //search

    TreeNode *current = root;               
         
    while (current != NULL && KEY != current->key) {  
        if (KEY < current->key){                      
            current = current->leftchild;   
        }
        else {
            current = current->rightchild;  
        }
    }
    return current;
}
void BST::InsertBST(int key, string element){    //insert
    TreeNode *y = 0;        
    TreeNode *x = 0;        
    TreeNode *insert_node = new TreeNode(key, element); 
    x = root;
    while (x != NULL) {                      
        y = x;                                
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                
    insert_node->parent = y;           
    if (y == NULL){                    
        this->root = insert_node;
    }
    else if (insert_node->key < y->key){
        y->leftchild = insert_node;
    }
    else{
        y->rightchild = insert_node;
    }
}
TreeNode* BST::Leftmost(TreeNode *current){   //the min of the BST
    
    while (current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}
TreeNode* BST::Successor(TreeNode *current){   //successor
    if (current->rightchild != NULL){
        return Leftmost(current->rightchild);
    }
    
    TreeNode *new_node = current->parent;
    
    while (new_node != NULL && current == new_node->rightchild) {
        current = new_node;
        new_node = new_node->parent;
    }
    return new_node;
}
TreeNode* BST::Predecessor(TreeNode *current){       //predecessor
    if (current->leftchild != NULL){
        return rightmost(current->leftchild);
    }
    
    TreeNode *new_node = current->parent;
    
    while (new_node != NULL && current == new_node->leftchild) {
        current = new_node;
        new_node = new_node->parent;
    }
    return new_node;
}
void BST::InorderPrint(){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);
    while(current){
        cout << current->element << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}
void BST::Levelorder(){
    std::queue<TreeNode*> q;
    q.push(this->root);					    // 把root作為level-order traversal之起點
    								        // 推進queue中
    while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

    	TreeNode *current = q.front();      // 取出先進入queue的node
    	q.pop();                          
    	cout << current->element << "(" << current->key << ")" << " ";   

    	if (current->leftchild != NULL){    // 若leftchild有資料, 將其推進queue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // 若rightchild有資料, 將其推進queue
            q.push(current->rightchild);
        }
    }
}
TreeNode* BST::rightmost(TreeNode *current){   //max of the tree
    while (current->rightchild != NULL){
        current = current->rightchild;
    }
    return current;
}
void BST::DeleteBST(int KEY){               // delete

    TreeNode *delete_node = Search(KEY);    
    if (delete_node == NULL) {
        std::cout << "data not found.\n";
        return;
    }

    TreeNode *y = 0;      
    TreeNode *x = 0;      

    if (delete_node->leftchild == NULL || delete_node->rightchild == NULL){
        y = delete_node;
    }
    else{
        y = Successor(delete_node);       
    }                                      
    if (y->leftchild != NULL){
        x = y->leftchild;                  
    }                                      
    else{
        x = y->rightchild;
    }

    if (x != NULL){                        
        x->parent = y->parent;             
    }
    if (y->parent == NULL){             
        this->root = x;
    }
    else if (y == y->parent->leftchild){   
        y->parent->leftchild = x;           
    }
    else{                                   
        y->parent->rightchild = x;          
    }                                       
    if (y != delete_node) {                 
        delete_node->key = y->key;          
        delete_node->element = y->element;  
    }
    delete y;                              
    y = 0;
}
int main() {

    BST T;
    
    T.InsertBST(8,"A");     //insert and build the BST 
    T.InsertBST(1000,"B");
    T.InsertBST(2,"C");
    T.InsertBST(513,"D");

    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl;
    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl;
    cout<<"try to search;"<<"\n";
    TreeNode *node = T.Search(1000);
    if(node != NULL){
    }
    else {
    	cout << "no element with Key(1000)" << endl;
    }
    node = T.Search(73);      //the search not found
    if(node != NULL){
    	cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key(73)" << endl;
    }
    node = T.Search(8); 
    node=T.rightmost(node);//test max
    if(node!=NULL) 
    {
      cout<<"the max item of the BST:"<<node->GetElement()<< "(" << node->GetKey() << ")" << endl;
    }
    node = T.Search(8); 
     node=T.Leftmost(node);//test min 
     if(node!=NULL)
    {
      cout<<"the min item of the BST:"<<node->GetElement()<< "(" << node->GetKey() << ")" << endl;
    }
    cout<<"find the successor of 513(D)"<<"\n";
     node = T.Search(8); 
    node=T.Successor(node);//cceccors
     if(node!=NULL)
    {
      cout<<"the  successor of 513(D):"<<node->GetElement()<< "(" << node->GetKey() << ")" << endl;
    }
    cout<<"find the predecessor of 513(D):"<<"\n";
    node = T.Search(8); 
    node=T.Predecessor(node);//predecessors
     if(node!=NULL)
    {
     cout<<"the predecessor of 513(D):"<<node->GetElement()<< "(" << node->GetKey() << ")" << endl;
    }
    cout<<"delete the 513(D) item\n";//delete the item
    T.DeleteBST(513);//delete
    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    return 0;
}
