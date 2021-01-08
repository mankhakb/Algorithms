struct Queue
{
    int data;
    struct Queue *next;

};

struct Queue * frontnode =nullptr;
struct Queue * backnode =nullptr;


void enqueue(int data)
{
    struct Queue *node = new Queue();

    if(frontnode ==nullptr && backnode == nullptr)
    {
        node->data = data;
        frontnode = node;
        backnode = node;
        return;
    }
    else
    {
        node->data = data;
        backnode->next = node;
        backnode = node;

    }

}
void dequeue()
{
    if(frontnode == nullptr && backnode == nullptr)
    {
        cout << "queue empty" << endl;
        return;
    }

    Queue *tmp = frontnode;
    frontnode =frontnode->next;
    delete tmp;
    cout << "dequeued" << endl;

}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "front-->" << frontnode->data <<endl;
    cout << "back-->" << backnode->data <<endl;

    dequeue();
    dequeue();

    cout << "front-->" << frontnode->data <<endl;
    cout << "back-->" << backnode->data <<endl;
    return 0;
}
