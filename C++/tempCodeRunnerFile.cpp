int CalculateHorizontalDistance(int a, Node *root, int horizonalDistance)
{
    if (root == NULL)
        return 0;
    if (root->data == a)
        return horizonalDistance;
    CalculateHorizontalDistance(a, root->right, horizonalDistance + 1);
    CalculateHorizontalDistance(a, root->left, horizonalDistance - 1);
}
int findDist(Node *root, int a, int b)
{
    int horizontal_distance_a = 0;
    int horizontal_distance_b = 0;
    horizontal_distance_a = CalculateHorizontalDistance(a, root, horizontal_distance_a);
    horizontal_distance_b = CalculateHorizontalDistance(b, root, horizontal_distance_b);
    return (abs(horizontal_distance_a - horizontal_distance_b));
}