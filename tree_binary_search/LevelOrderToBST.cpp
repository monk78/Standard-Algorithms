struct NodeDetails
{
    Node *ptr;
    int min, max;
};
Node* getNode(int data)
{
    Node *newNode =
        (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;

    Node *root;
    queue<NodeDetails> q;
    int i=0;
    NodeDetails newNode;
    newNode.ptr = getNode(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
    root = newNode.ptr;
    while (i != n)
    {
        NodeDetails temp = q.front();
        q.pop();
        if (i < n && (arr[i] < temp.ptr->data &&
                          arr[i] > temp.min))
        {
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);


            temp.ptr->left = newNode.ptr;
        }
        if (i < n && (arr[i] > temp.ptr->data &&
                               arr[i] < temp.max))
        {
            // Create NodeDetails for newNode
            /// and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);

            // make this 'newNode' as right child
            // of 'temp.ptr'
            temp.ptr->right = newNode.ptr;
        }
    }

    // root of the required BST
    return root;
}
