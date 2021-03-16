 if (ans.length() == n)
    {
        vec.push_back(ans);
    }
    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        solution(ros, ans + ch, n, vec);
    }