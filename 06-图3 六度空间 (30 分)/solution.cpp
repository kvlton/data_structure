#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<std::vector<bool>> Graph;

void InsertEdge(Graph& graph, int vertex1, int vertex2) {
  graph[vertex1][vertex2] = graph[vertex2][vertex1] = true;
}

void BFS(const Graph& graph, int vertex, std::vector<bool>& Visited) {
  std::queue<int> Q;
  Q.push(vertex);
  Visited[vertex] = true;
  int level = 0;
  while (!Q.empty() && level <= 5) {
    int size = Q.size();
    for (size_t i = 0; i < size; ++i) {
      int tmp_vertex = Q.front();
      Q.pop();
      for (size_t i = 0; i < graph[tmp_vertex].size(); ++i) {
        if (graph[tmp_vertex][i] == 1 && !Visited[i]) {
          Q.push(i);
          Visited[i] = true;
        }
      }
    }
    ++level;
  }
}

int main() {
  size_t N, E;
  std::cin >> N >> E;
  Graph graph(N, std::vector<bool>(N, false));

  for (size_t i = 0; i < E; ++i) {
    int num1, num2;
    std::cin >> num1 >> num2;
    InsertEdge(graph, num1-1, num2-1);
  }

  for (size_t i = 0; i < N; ++i) {
    std::vector<bool> Visited(N, false);
    BFS(graph, i, Visited);

    int count = 0;
    for (size_t j = 0; j < Visited.size(); ++j) {
      if (Visited[j]) ++count;
    }
    printf("%d: %.2f\%\n", i+1, 100. * count / Visited.size());
  }

  return 0;
}
