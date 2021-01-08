struct Node
{
    int data;
    Node *next;
};

struct Node * top =nullptr;

void push(int data)
{
    struct Node * newnode = new Node();
    if(top == nullptr)
    {
        newnode->data =data;
        newnode->next =nullptr;
        top= newnode;
    }
    else
    {
        newnode->data= data;
        newnode->next =top;
        top=newnode;
    }

}

void pop()
{
    struct Node* newtop;
    if(top == nullptr)
    {
        cout << "nothing to pop" <<endl;
        return;
    }

    if(top->next ==nullptr)
    {
        delete top;
        top=nullptr;
        return;
    }

    newtop = top->next;
    cout << "popped: " << top->data <<endl;
    delete top;
    top = newtop;
    cout << "new top is: " <<top->data <<endl;

}

void displayStack()
{
    if(top ==nullptr)
    {
        cout << "empty stack" <<endl;
        return;
    }

    struct Node * ptr = top;
    while(ptr !=nullptr)
    {
        cout << ptr->data <<endl;
        ptr=ptr->next;
    }
}

void topOfStack()
{
    cout << "top data is "<<top->data <<endl;
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    topOfStack();

    displayStack();

    pop();
    topOfStack();

    pop();
    topOfStack();

    displayStack();

    pop();
    topOfStack();
    pop();

    displayStack();

    pop();

    displayStack();
    pop();
    return 0;

}
