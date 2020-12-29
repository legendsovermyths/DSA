bool isValid(int v, bool graph[101][101], int m, int V, vector<int> &color, int c)
{
    for (int i = 1; i <= V; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool DFSUtil(int v, bool graph[101][101], int m, int V, vector<int> &color)
{
    if (v == V)
    {
        return true;
    }
    for (int c = 1; c < m; c++)
    {
        if (isValid(v, graph, m, V, color, c))
        {
            color[v] = c;
            if (DFSUtil(v + 1, graph, m, V, color) == true)
            {
                return true;
            }

            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<bool> visited(V, false);
    vector<int> Color(V + 1, 0);
    return (DFSUtil(1, graph, m, V, Color));
}