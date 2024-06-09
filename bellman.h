#ifndef BELLMAN_FORD
#define BELLMAN_FORD

#include <bits/stdc++.h>
using namespace std;

void BF(int graph[][20], int num_vertices, char start_vertex, int current_value[], int current_previous[]);

string BF_Path(int graph[][20], int num_vertices, char start_vertex, char goal_vertex);

#endif