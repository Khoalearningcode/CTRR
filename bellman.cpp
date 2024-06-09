#include "bellman.h"

void BF(int graph[][20], int num_vertices, char start_vertex, int current_value[], int current_previous[])
{
    bool check = true;

    // Kiểm tra nếu current_value và current_previous đã được khởi tạo hay chưa
    for (int i = 0; i < num_vertices; i++)
    {
        if (current_value[i] != -1 || current_previous[i] != -1)
        {
            check = false;
            break;
        }
    }

    int temp_value[num_vertices];
    int start_index = start_vertex - 'A';

    if (check)
    {
        // Khởi tạo giá trị ban đầu cho đỉnh xuất phát
        for (int i = 0; i < num_vertices; i++)
        {
            if (graph[start_index][i] != 0)
            {
                current_previous[i] = start_index;
                current_value[i] = graph[start_index][i];
            }
        }
        current_value[start_index] = 0;
    }
    else
    {
        // Sao chép current_value vào temp_value
        for (int i = 0; i < num_vertices; i++)
        {
            temp_value[i] = current_value[i];
        }

        // Thực hiện thư giãn các cạnh
        for (int u = 0; u < num_vertices; u++)
        {
            for (int v = 0; v < num_vertices; v++)
            {
                if (graph[u][v] != 0 &&
                    (temp_value[u] != -1 &&
                    (temp_value[u] + graph[u][v] < current_value[v] || current_value[v] == -1)))
                {
                    current_value[v] = temp_value[u] + graph[u][v];
                    current_previous[v] = u;
                }
            }
        }
    }
}

string BF_Path(int graph[][20], int num_vertices, char start_vertex, char goal_vertex)
{
    int current_value[num_vertices];
    int current_previous[num_vertices];

    // Khởi tạo mảng current_value và current_previous
    for (int i = 0; i < num_vertices; i++)
    {
        current_value[i] = -1;
        current_previous[i] = -1;
    }

    int start_index = start_vertex - 'A';
    int goal_index = goal_vertex - 'A';

    // Chạy thuật toán Bellman-Ford cho mỗi đỉnh
    for (int i = 0; i < num_vertices; i++)
    {
        BF(graph, num_vertices, start_vertex, current_value, current_previous);
    }

    // Xây dựng đường đi từ đỉnh xuất phát đến đỉnh đích
    string path = "";
    int temp_index = goal_index;

    while (temp_index != start_index)
    {
        path = string(1, char(temp_index + 'A')) + " " + path;
        temp_index = current_previous[temp_index];
    }

    path = string(1, char(start_index + 'A')) + " " + path;
    return path;
}