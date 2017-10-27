void levelOrder(node * root) {
    if(!root){
            return;
        }
    map<int , vector<int> > m;
    queue<pair<node* , int>> q;
    q.push(make_pair(root,0));
    vector<int> v;
    while(!q.empty()){
        pair<node*,int> p =q.front();
        node* Node = p.first;
        int level = p.second;
        q.pop();
        m[level].push_back(Node->data);
        cout<<Node->data<<" ";
        if(Node->left!=NULL){
            q.push(make_pair(Node->left,level+1));
        }
        if(Node->right!=NULL){
            q.push(make_pair(Node->right,level+1));
        }
    }
}

