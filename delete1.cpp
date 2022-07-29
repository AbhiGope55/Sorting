#include<iostream>
#define N 5
using namespace std;
class avl{
public:
    int data;
    avl* left;
    avl* right;
    int height;

    avl(){
        data=0;
        left=NULL;
        right=NULL;
        height=1;
    }
    avl(int d){
        data=d;
        left=right=NULL;
        height=1;
    }
   
};
int Height(avl* node){
    if(node==NULL)
        return 0;
    return node->height;
}
int max(int a,int b){
    return (a<b?b:a);
}
avl* leftRotate(avl* root){
    avl* x=root->right;
    avl* t=x->left;
    x->left=root;
    root->right=t;
    root->height=max(Height(root->left),Height(root->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return x;
}
avl* rightRotate(avl* root){
    avl* x=root->left;
    avl* t=x->right;
    x->right=root;
    root->left=t;
    root->height=max(Height(root->left),Height(root->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return x;
}
int balFactor(avl* root){
    if(root==NULL)
        return 0;//
    return Height(root->left)-Height(root->right);
}
avl* insert(avl* root,int d){
    if(root==NULL){
        return new avl(d);
    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    else if(d>root->data){
        root->right=insert(root->right,d);
    }
    else{
        cout<<"\nDuplicate data is not inserted in avl tree";
    }
    root->height=max(Height(root->left),Height(root->right))+1;
    //now cheak for requried rotation required
    int bf=balFactor(root);
    if(bf>1 && d<root->left->data){
        return rightRotate(root);
    }
    if(bf>1 && d>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf<-1 && d>root->right->data ){
        return leftRotate(root);
    }
    if(bf<-1 && d<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
avl* minValuenode(avl* root){
    avl* current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

avl* Delete(avl* root,int key){
    if(root==NULL)
        return NULL;
    if(key<root->data){
        root->left=Delete(root->left,key);
    }
    else if(key>root->data){
        root->right=Delete(root->right,key);
    }
    else{
        //node has no left and no right child
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else if(root->left==NULL){
            return root->right;
        }
        else{
            avl *temp=minValuenode(root->right);
            //or we can do max value in left of sub tree
            root->data=temp->data;
            root->right= Delete(root->right,temp->data);
        }
    }
    root->height=1+max(Height(root->left),Height(root->right));
        int bf=balFactor(root);
        if(bf>1){
            if( balFactor(root->left)>=0){
                return rightRotate(root);
            }
            else{
                root->left= leftRotate(root->left);
                rightRotate(root);
            }

        }
        if(bf<-1){
            if(balFactor(root->right)<=0){
                return leftRotate(root);
            }
            else{
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
}
void inOrder(avl* root){
    //base case
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<"  data :  "<<root->data<<" , height "<<root->height<<endl;
    inOrder(root->right);
}
void preOrder(avl* root){
    if(root==NULL){
        return ;
    }
    cout<<" "<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}
void print2d(avl* root,int space){
    if(root==NULL){
        return ;
    }
    space=space+N;
    print2d(root->right,space);
    cout<<endl;
    for(int i=N;i<space;i++){
        cout<<" ";
    }
    cout<<root->data<<"\n";
    print2d(root->left,space);

}
int main(){
    avl *root=NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    preOrder(root);
    print2d(root,5);
    root=Delete(root,9);
    cout<<"After deleting 9 from the tree : \n";
    print2d(root,8);
    return 0;
}
