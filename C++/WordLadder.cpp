#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(string s1, string s2)
{
    int count = 0;
    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == s2[i])
        {
            count = count + 1;
        }
    }
    return count + 1 == len;
}
void SolutionUtil(int &answer, string curr, vector<string> &wordList, string endWord, int currNumber)
{
    if (currNumber > wordList.size())
    {
        return;
    }
    if (curr == endWord)
    {
        if (answer > currNumber)
        {
            std::cout << answer << std::endl;
            answer = currNumber;
            return;
        }
    }
    if (answer < currNumber)
    {
        return;
    }
    for (int i = 0; i < wordList.size(); i++)
    {
        string ne = wordList[i];
        if (isValid(ne, curr))
        {
            SolutionUtil(answer, ne, wordList, endWord, currNumber + 1);
        }
    }
}
int main()
{
    vector<string> wordList = {"hot", "dog", "dot"};
    int answer = 10000;
    SolutionUtil(answer, "hot", wordList, "dog", 1);
    std::cout << answer << std::endl;
    return answer;
}
// "hot"
// "dog"
// ["hot","dog","dot"]
// "qa"
// "sq"
// ["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
// "hit"
// "cog"
// ["hot","dot","dog","lot","log","cog"]