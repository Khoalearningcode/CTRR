#include "tsm.cpp"
#include "bellman.cpp"
#include <iostream>

using namespace std;

int main()
{
    int n = 4;
    int g[20][20] = {
        {0, 11, 14, 19},
        {11, 0, 34, 24},
        {14, 34, 0, 29},
        {19, 24, 29, 0}};

    char start = 'A';
    char goal = 'E';

    string tsp_result = Traveling(g, n, start);
    string BF_result = BF_Path(g, n, start, goal);

    cout << "Best Path: " << tsp_result << endl;
    cout << "Shortest Path using Bellman-Ford: " << BF_result << endl;

    return 0;
}