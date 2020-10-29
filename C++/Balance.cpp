#include <iostream>
#include <vector>
using namespace std;
string checker(string input)
{
    vector<char> open;
    vector<char> open_2;
    vector<char> close;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            open.push_back(input[i]);
            open_2.push_back(input[i]);
        }
        else
        {
            if (!open.size())
                return "unbalanced";

            if (input[i] == ')' && open.back() != '(')
            {
                return "not balanced";
            }

            if (input[i] == '}' && open.back() != '{')
            {
                return "not balanced";
            }

            if (input[i] == ']' && open.back() != '[')
            {
                return "not balanced";
            }

            else
            {

                close.push_back(input[i]);
                if (open.size())
                    open.pop_back();
            }
        }
    }
    if (open_2.size() != close.size())
    {

        return "not balanced";
    }
    return "balanced";
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string input;
        cin >> input;
        cout << checker(input) << endl;
    }
}