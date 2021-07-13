#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void InsertEdge(Graph& graph, int vertex1, int vertex2) {
  graph[vertex1][vertex2] = graph[vertex2][vertex1] = 1;
}

void DFS(const Graph& graph, int vertex, std::vector<bool>& Visited) {
  if (Visited[vertex]) return;
  std::cout << vertex << " ";
  Visited[vertex] = true;
  for (size_t i = 0; i < graph[vertex].size(); ++i) {
    if (graph[vertex][i] == 1) DFS(graph, i, Visited);
  }
}

void BFS(const Graph& graph, int vertex, std::vector<bool>& Visited) {
  std::queue<int> Q;
  Q.push(vertex);
  Visited[vertex] = true;
  while (!Q.empty()) {
    int tmp_vertex = Q.front();
    Q.pop();
    std::cout << tmp_vertex << " ";
    for (size_t i = 0; i < graph[tmp_vertex].size(); ++i) {
      if (graph[tmp_vertex][i] == 1 && !Visited[i]) {
        Q.push(i);
        Visited[i] = true;
      }
    }
  }
}

int main() {
  size_t N, E;
  std::cin >> N >> E;
  Graph graph(N, std::vector<int>(N, 0));

  for (size_t i = 0; i < E; ++i) {
    int num1, num2;
    std::cin >> num1 >> num2;
    InsertEdge(graph, num1, num2);
  }

  std::vector<bool> Visited(N, false);
  for (size_t i = 0; i < Visited.size(); ++i) {
    if (!Visited[i]) {
      std::cout << "{ ";
      DFS(graph, i, Visited);
      std::cout << "}" << std::endl;
    }
  }

  for (size_t i = 0; i < Visited.size(); ++i) {
    Visited[i] = false;
  }
  for (size_t i = 0; i < Visited.size(); ++i) {
    if (!Visited[i]) {
      std::cout << "{ ";
      BFS(graph, i, Visited);
      std::cout << "}" << std::endl;
    }
  }

  return 0;
}
