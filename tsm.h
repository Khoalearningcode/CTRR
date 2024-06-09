#ifndef TRAVELLING_SALES_MAN
#define TRAVELLING_SALES_MAN

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

const int MAX = 1e9;

int tsp(int mask, int pos, int start_index, int VISITED_ALL, int G[20][20], vector<vector<int>>& dp, vector<vector<int>>& parent);

string Traveling(int G[20][20], int n, char start);

#endif