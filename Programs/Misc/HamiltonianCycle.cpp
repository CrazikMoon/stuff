#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// буллевская переменная для проверки наличия гамильтонского цикла
bool hasCycle;

// функция для проверки вершины графа для добавления в цикл на позицию pos
bool isSafe(int v, int graph[][6], vector<int> path, int pos)
{
    //если вершина графа не соединена с предыдущей добавленной вершиной
    if (graph[path[pos - 1]][v] == 0)
        return false;
    // есть ли эта вершина уже в цикле
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    //иначе вершину можно добавить в нынешний цикл
    return true;
}

// рекурсивная функция для нахождения всех гамильтонских циклов
void FindHamCycle(int graph[][6], int pos, vector<int> path, bool visited[], int N,int st)
{
    // если все точки включены в цикл
    if (pos == N) {

        // если есть ребро от конечной к начальной вершине
        if (graph[path[path.size() - 1]][path[0]] != 0) {
            // добавить начальную вершину в строку и вывести путь
            path.push_back(st);
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << endl;

            // удалить начальную вершину
            path.pop_back();

            // Существование гамильтонского цикла
            hasCycle = true;
        }
        return; //выход из функции с результатом
    }

    // пробуем различные вершины
    for (int v = 0; v < N; v++) {

        // проверка валидности вершины графа для добавления в цикл
        if (isSafe(v, graph, path, pos) && !visited[v]) {

            path.push_back(v); // добавление в цикл
            visited[v] = true; // отметка включения в цикл

            // рекурсивно строим конец пути
            FindHamCycle(graph, pos + 1, path, visited, N, st);

            // после рекурсии определенной вершины убираем её из пути и пробуем другие вершины
            visited[v] = false;
            path.pop_back();
        }
    }
}

// функция для нахождения всех возможных гамильтоновых циклов
void hamCycle(int graph[][6], int N)
{
    //изначально флаг отрицателен
    hasCycle = false;

    //строка для хранения пути по вершинам
    vector<int> path;
    int st = 1;
    path.push_back(st);

    // массив для проверки нахождения в цикле
    bool visited[N];

    for (int i = 0; i < N; i++)
        visited[i] = false;

    visited[st] = true;

    // вызов функции нахождения всех гамильтоновых циклов
    FindHamCycle(graph, 1, path, visited, N, st);

    if (!hasCycle) {

        // если гамильтонового цикла на этом графе не существует, то выводим:
        cout << "No Hamiltonian Cycle was found" << endl;
        return;
    }
}

int main()
{
    int graph[][6] = { // граф в виде матрицы с доступными путям (типа 1 задача ЕГЭ)
            { 0, 0, 0, 1, 1, 0 },
            { 0, 0, 1, 1, 1, 0 },
            { 0, 1, 0, 1, 0, 1 },
            { 1, 1, 1, 0, 1, 1 },
            { 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 1, 1, 0 },
        };
    hamCycle(graph, 6);//вызов главной функции

    return 0;
}
