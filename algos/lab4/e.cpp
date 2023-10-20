// #include <iostream>
// #include <vector>
// using namespace std;

// struct node{
//     int val, level;
//     node * left;
//     node * right;
//     node(int val){
//         this->val = val;
//         left = NULL;
//         right = NULL;
//     }
//     node(int val, int lvl){
//         level=lvl;
//         this->val = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// struct bst{
//     public:
//         bst(){
//             root = new node(1, 0);
//             v.push_back(0);
//         }
//         void add(int parent, int val, int side){
//             add(root, parent, val, side);
//         }
       
//         void level(){
//             level(root);
//         }
//         void count(){
//             count(root);
//         }
//     private:
//         node * root ;
//         vector<int> v;
//         node * add(node* cur, int parent, int val, int side){
//             node* parent_node=find(root, parent);
//             node* current= new node(val, parent_node->level+1);
            
//             if(side==0){
//                 parent_node->left=current;
//             }
//             if(side==1){
//                 parent_node->right=current;
//             }
            
//             return current;
//         }

   
//         node * find(node * current, int val){
//             if(current->val == val) return current;
//             node* l;
//             node* r;
//             if(current->left!=NULL){
//                 l= find(current->left, val);
//             }
//             if(l!=NULL){
//                 return l;
//             }
//             if(current->right!=NULL){
//                 r=find(current->right, val);
//             }
//             if(r!=NULL){
//                 return r;
//             }
//             return NULL;
//         }

        
      
//         void count(node* current){
//             if(v.size()<current->level+1){
//                     v.push_back(0);
//                 }
//             v[current->level]+=1;
//             if(current->left!=NULL){
//                 count(current->left);
//             }
//             if(current->right!=NULL){
//                 count(current->right);
//             }
//             return;
//         }
//         void level(node* current){
//             int max=v[0];
//             for(int i=0; i<v.size(); i++){
//                 if(max<v[i]){
//                     max=v[i];
//                 }
//             }
//             cout<<max;
//         }
// };

// int main() {
//     int n;
//     cin >> n;
//     bst* b= new bst();
//     for(int i=0; i<n-1; i++){
//         int x, y, z;
//         cin>>x>>y>>z;
//         b->add(x,y,z);
//     }
 

//     b->count();
//     b->level();
    
// }
#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;

  Node(int x) {
    this->val = x;
    this->left = this->right = NULL;
  }
};

Node *search(Node *root, int x) {
  if (root == NULL) return NULL;
  if (root->val == x) return root;
  Node *found = search(root->left, x);
  if (found == NULL) found = search(root->right, x);
  return found;
}

int getHeight(Node *root) {
  if (root == NULL) return 0;
  int lHeight = getHeight(root->left);
  int rHeight = getHeight(root->right);
  return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}

int getWidth(Node *root, int level) {
  if (root == NULL) return 0;
  if (level == 1)
    return 1;
  else {
    return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
  }
}

int getMaxWidth(Node *root) {
  int max = 0, width;
  int h = getHeight(root);
  for (int i = 1; i <= h; i++) {
    width = getWidth(root, i);
    if (width > max) max = width;
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  Node *root = NULL;
  Node *current;
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (root == NULL) {
      current = new Node(x);
      root = current;
    } else {
      current = search(root, x);
    }
    Node *tmp = new Node(y);
    if (z == 0)
      current->left = tmp;
    else
      current->right = tmp;
  }
  cout << getMaxWidth(root);
}