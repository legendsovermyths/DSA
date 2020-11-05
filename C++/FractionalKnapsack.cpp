#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
float round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
class item
{
public:
    int index = 0;
    float weight = 1;
    float value = 1;
    float valuePerWeight = value / weight;
};
float solution(item arr[], int n, int W)
{

    float value = 0;
    float MaxValuePerWeight = -1;
    int index = 0;
    for (int j = 0; j < n; j++)
    {
        arr[j].valuePerWeight = arr[j].value / arr[j].weight;
    }
    while (W >= 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i].valuePerWeight > MaxValuePerWeight)
            {
                MaxValuePerWeight = arr[i].valuePerWeight;
                index = arr[i].index;
            }
        }
        if (arr[index].weight >= W)
        {
            return value + arr[index].valuePerWeight * W;
        }
        value = value + arr[index].weight * MaxValuePerWeight;
        W = W - arr[index].weight;
        arr[index].valuePerWeight = 0;
        MaxValuePerWeight = -1;
    }
    return value;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, W;
        cin >> n >> W;
        item arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value;
            cin >> arr[i].weight;
            arr[i].index = i;
        }
        cout << setprecision(2) << solution(arr, n, W) << endl;
    }
}