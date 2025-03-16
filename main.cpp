#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start, vector<int>& distances) {
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distances[neighbor] == INT_MAX) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ifstream infile("graph.txt");
    int vertices, edges;
    infile >> vertices >> edges;

    vector<vector<int>> graph(vertices);
    for (int i = 0; i < edges; ++i) {
        int u, v;
        infile >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    int start;
    infile >> start;

    vector<int> distances(vertices, INT_MAX);
    bfs(graph, start, distances);

    for (int distance : distances) {
        cout << distance << endl;
    }

    return 0;
}