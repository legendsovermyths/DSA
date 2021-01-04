#include <iostream>
#include <vector>
using namespace std;
void printKthPermutation(vector<string> &k, string number, string ans)
{
    if (number.length() == 0)
    {
        k.push_back(ans);
        return;
    }
    for (int i = 0; i < number.length(); i++)
    {
        char ch = number[i];
        string ros = number.substr(0, i) + number.substr(i + 1);
        printKthPermutation(k, ros, ans + ch);
    }
}
int main()
{
    vector<string> k;
    int i = 3;
    printKthPermutation(k, "1234", "");
    cout << k[i] << endl;
}