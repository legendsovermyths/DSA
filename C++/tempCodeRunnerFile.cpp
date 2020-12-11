Node *temp = root;
    while (temp)
    {
        if (temp->left && Key < temp->data)
        {
            temp = temp->left;
        }
        if (temp->right && Key >= temp->data)
        {
            temp = temp->right;
        }
        else
        {
            if (Key >= temp->data)
            {
                Node *node = new Node(Key);
                temp->right = node;
                break;
            }
            if (Key < temp->data)
            {
                Node *node = new Node(Key);
                temp->left = node;
                break;
            }
        }
    }

    return root;