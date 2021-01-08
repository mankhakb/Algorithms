class node
{
public:

     node(int value)
     {
         this->value =value;
         this->left =nullptr;
         this->right =nullptr;
     }

    int value;
    node *left;
    node *right;
};


void printPreOrder(class node *node)
{
    if(node == nullptr)
    {
        return;
    }

    cout << node->value << " " ;

    printPreOrder(node->left);

    printPreOrder(node->right);

}

void printInOrder(class node * node)
{
    if(node == nullptr)
    {
        return;
    }

    printInOrder(node->left);

    cout << node->value <<" ";

    printInOrder(node->right);
}

void printPostOrder(class node *node)
{
    if(node == nullptr)
    {
        return;
    }

   printPostOrder(node->left);
   printPostOrder(node->right);
    cout <<node->value << " ";

}

void printBFSOrder(class node* root)
{
    if(root == nullptr)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while(q.empty() == false)
    {
        node* node = q.front();
        cout << node->value <<" ";
        q.pop();

        if(node->left != nullptr)
        {
            q.push(node->left);
        }
        if(node->right !=nullptr)
        {
            q.push(node->right);
        }
    }


}

int main()
{
   node *root = new node(10);
   root->left = new node(20);
   root->right =new node(30);
   root->left->left = new node(40);


   printPreOrder(root);
   cout << endl;
   printInOrder(root);
   cout << endl;
   printPostOrder(root);
   cout << endl;
   printBFSOrder(root);

   return 0;



}
