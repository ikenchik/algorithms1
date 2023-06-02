/*#include <iostream>
#include <cstring>
using namespace std;
#define INF INT_MAX
#define V 6
double G[V][V] = {
  {0, 1.97, 21.6, 10.7, 22.3, 10.4},
  {1.97, 0, 22.3, 11.4, 23, 11.1},
  {21.6, 22.3, 0, 11.5, 5.2, 12},
  {10.7, 11.4, 11.5, 0, 13.4, 0.68},
  {22.3, 23, 5.2, 13.4, 0, 13.8},
  {10.4, 11.1, 12, 0.68, 13.8, 0}
};
int main() {
    int no_edge;           
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x;          
    int y;
    setlocale(LC_ALL, "rus");
    cout << "Путь" << " : " << "Длина";
    cout << endl;
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}*/

/*
//определение числа связности графа на основе матрицы смежности :
#include <iostream>
using namespace std;
const int N = 7;
int G[N][N] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 0}
};
void DFS(int vertex, bool visited[]) {
    visited[vertex] = true;
    for (int i = 0; i < N; i++) {
        if (G[vertex][i] && !visited[i]) {
            DFS(i, visited);
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int count = 0;
    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(i, visited);
            count++;
        }
    }
    cout << "Число компонент связности: " << count << endl;
    return 0;
}
*/

/*
//определение числа связности графа на основе матрицы инцидентности :
#include <iostream>
using namespace std;
const int N = 7;
int G[N][N] = {
    {1, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1}
};
bool visited[N];
void DFS(int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < N; i++) {
        if (G[i][vertex] && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (G[i][j]) {
                for (int k = 0; k < N; k++) {
                    visited[k] = false;
                }
                G[i][j] = G[j][i] = 0;
                DFS(i);
                if (!visited[j]) {
                    count++;
                }
                G[i][j] = G[j][i] = 1;
            }
        }
    }
    cout << "Число компонент связности: " << count << endl;
    return 0;
}*/

/*
#include <iostream>
using namespace std;
const int MAX = INT_MAX; //Максимальное значение
int main() {
    int V = 7; //Количество вершин
    int G[7][7] = { {0, 1, 3, MAX, MAX, MAX, MAX}, //Матрица смежности
                   {1, 0, 2, 3, MAX, MAX, MAX},
                   {3, 2, 0, MAX, 4, MAX, MAX},
                   {MAX, 3, MAX, 0, 5, 6, MAX},
                   {MAX, MAX, 4, 5, 0, 7, 8},
                   {MAX, MAX, MAX, 6, 7, 0, 9},
                   {MAX, MAX, MAX, MAX, 8, 9, 0} };

    int selected[7]; //Массив выбранных вершин
    memset(selected, false, sizeof(selected));
    selected[0] = true;
    int no_edge = 0;
    int x;
    int y;
    cout << "Edge : Weight" << endl;
    while (no_edge < V - 1) {
        int min = MAX;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << G[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}*/