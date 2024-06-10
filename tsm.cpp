#include "tsm.h"

int tsp(int G[20][20], vector<vector<int>> &dynaprogram, vector<vector<int>> &stored_value, int bitmask, int current_position, int start_index, int numofcities)
{
    if (bitmask == numofcities)
    {
        if (G[current_position][start_index] == 0)
        {
            return 10000;
        }
        else
        {
            return G[current_position][start_index];
        }
    }

    if (dynaprogram[current_position][bitmask] != -1)
        return dynaprogram[current_position][bitmask];

    int min_cost = 10000;
    int city = 0;
    while (city < dynaprogram.size())
    {
        if (G[current_position][city] != 0 && (bitmask & (1 << city)) == 0)
        {
            int new_cost = G[current_position][city] + tsp(G, dynaprogram, stored_value, bitmask | (1 << city), city, start_index, numofcities);
            if (new_cost < min_cost)
            {
                min_cost = new_cost;
                stored_value[current_position][bitmask] = city;
            }
        }
        city++;
    }
    return dynaprogram[current_position][bitmask] = min_cost;
}

string Traveling(int G[20][20], int n, char start_vertex)
{
    int numofcities = (1 << n) - 1;
    int start = start_vertex - 'A';

    vector<vector<int>> dynaprogram(n, vector<int>(1 << n, -1));
    vector<vector<int>> stored_value(n, vector<int>(1 << n, -1));

    int bitmask = 1 << start;
    int current_position = start;
    vector<int> way;
    way.push_back(start);
    int min_cost = tsp(G, dynaprogram, stored_value, bitmask, start, start, numofcities);

    while (true)
    {
        current_position = stored_value[current_position][bitmask];
        if (current_position == -1)
            break;
        way.push_back(current_position);
        bitmask |= (1 << current_position);
    }
    way.push_back(start);

    string result;
    for (int i = 0; i < way.size(); ++i)
    {
        if (i != 0)
        {
            result += " ";
        }
        result += static_cast<char>(way[i] + 'A');
    }

    return result;
}