#include <iostream>
#include <climits>
#include <vector>
#include <list>
void primitive_calculator(int64_t number)
{
    std::vector<int64_t> min_steps(number + 1, INT_MAX);
    std::list<int64_t> *path = new std::list<int64_t>[number + 1];
    min_steps[0] = 0;
    min_steps[1] = 0;
    path[0].push_back(0);
    path[1].push_back(1);
    for (int i = 2; i <= number; i++)
    {
        if (i % 3 == 0)
        {
            if (min_steps[i / 3] < min_steps[i])
            {
                min_steps[i] = min_steps[i / 3] + 1;
                path[i] = path[i / 3];
                path[i].push_back(i);
            }
        }
        if (i % 2 == 0)
        {
            if (min_steps[i / 2] < min_steps[i])
            {
                min_steps[i] = min_steps[i / 2] + 1;
                path[i] = path[i / 2];
                path[i].push_back(i);
            }
        }
        if (min_steps[i - 1] < min_steps[i])
        {
            min_steps[i] = min_steps[i - 1] + 1;
            path[i] = path[i - 1];
            path[i].push_back(i);
        }
    }
    std::cout << min_steps[number] << "\n";
    while (!path[number].empty())
    {
        std::cout << path[number].front() << " ";
        path[number].pop_front();
    }
}
int main()
{
    int64_t number;
    std::cin >> number;
    primitive_calculator(number);
    return 0;
}