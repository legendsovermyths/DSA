#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cout << max(-9, max(-2, max(-2, max(-1, -9999))));
}