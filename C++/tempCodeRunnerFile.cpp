int main()
{
    loop(i, N)
    {
        initialize(i);
    }
    int m, n;
    cin >> m >> n;
    vector<vector<int>> edges;
    int cost = 0;
    loop(i, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        if (find_n(u) == find_n(v))
        {
            continue;
        }
        else
        {
            cout << u << " " << v << endl;
            Union(u, v);
            cost += w;
        }
    }
    cout << cost << endl;
    return 0;
}