#include <iostream>
#include <vector>
using namespace std;
bool isValid(int i, int j, int M, int N, vector<vector<int>> &vis)
{
    return i >= 0 && j >= 0 && i < M && j < N && !vis[i][j];
}
int solutionUtil() {}
int solution(int i, int j, int M, int N, vector<vector<int>> &vis, vector<int> &solutions, int d1, int d2)
{
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
}
int main() {}