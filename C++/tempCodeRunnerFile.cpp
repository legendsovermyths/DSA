if (root == NULL)
    {
        return root;
    }
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->right)
        {
            if (temp->right->data < X)
            {
                temp = temp->right;
            }
            if (temp->right->data == X)
            {
                temp->right = NULL;
                break;
            }
        }
        if (temp->left)
        {
            if (temp->left->data < X)
            {
                temp = temp->left;
            }
            if (temp->left->data == X)
            {
                temp->left = NULL;
                break;
            }
        }
        if (temp->left == NULL && temp->right == NULL)
            break;
    }
    return root;