/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/

bool search(node* root,int key,vector<node*> &v){
    if(root==NULL){
       return false;
    }
    v.push_back(root);
    if(root->data==key){
        return true;
    }
    
    if((root->left && search(root->left,key,v)) || (root->right && search(root->right,key,v))){
        return true;
    } 
    v.pop_back();
    return false;
}

node *lca(node *root, int v1,int v2)
{
    vector<node*> vec1,vec2;
    search(root,v1,vec1);
    search(root,v2,vec2);
    int i;
    for(i=0;i<vec1.size() && i<vec2.size();i++){
        if(vec1[i]!=vec2[i]){
            break;
        }
    }
    return vec1[i-1];
}
