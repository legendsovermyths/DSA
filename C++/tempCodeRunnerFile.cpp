{
        if (node == NULL)
            return 0;
        else
        {
            int lheight = height(node->left);
            int rheight = height(node->right);
            if (lheight > rheight)
                return (1 + lheight);
            else
                return (1 + rheight);
        }
    }