void topView(node * root) {
    
    if(root==NULL){
        return;
    }
    map<int ,int > m;
    queue<pair<node*,int>> q;  
    
    vector<int> v;
    int inital_h_distance=0;
    q.push(make_pair(root,inital_h_distance));
    while(!q.empty()){
        pair<node* , int> p = q.front();
        node *Node = p.first;
        int h_distance = p.second;
        q.pop();
        
        if(m.find(h_distance)==m.end()){
            m[h_distance] = Node->data;
            v.push_back(Node->data);
            cout<<Node->data<<" ";
        }
        if(Node->left!=NULL){
            q.push(make_pair(Node->left, h_distance-1));
        }
        if(Node->right!=NULL){
            q.push(make_pair(Node->right , h_distance+1));
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}

