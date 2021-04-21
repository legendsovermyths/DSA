Node *lca(Node *root, int n1, int n2)
    {
        queue<Node *> q;
        Node *temp = root;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();

            q.pop();
            if (temp->left)
            {
                if (temp->left->data == n1 || temp->left->data == n2)
                {
                    return temp;
                }
                q.push(temp->left);
            }
            if (temp->right)
            {
                if (temp->right->data == n1 || temp->right->data == n2)
                {
                    return temp;
                }
                q.push(temp->right);
            }
        }
        return temp;
    }