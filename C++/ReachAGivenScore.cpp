#include <iostream>
using namespace std;
int solution(int N)
{
    int arr[4][N + 1];
    int arrValues[] = {3, 5, 10};
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (j == 0)
            {
                arr[i][j] = 1;
            }
            else if (i == 0)
            {
                arr[i][j] = 0;
            }
            else if (j >= arrValues[i - 1])
            {
                arr[i][j] = arr[i - 1][j] + arr[i][j - arrValues[i - 1]];
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    for (int s = 1; s < 4; s++)
    {
        for (int i = 1; i <= N; i++)
        {
            cout << arr[s][i] << " ";
        }
        cout << "\n";
    }
    return arr[3][N];
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int N;
        cin >> N;
        cout << solution(N) << endl;
    }
}