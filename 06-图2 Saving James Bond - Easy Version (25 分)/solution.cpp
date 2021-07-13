#include <cmath>
#include <iostream>
#include <vector>

template <class T>
struct Point {
  Point(T _x, T _y) : x(_x), y(_y) {}
  T x;
  T y;
};
typedef Point<int> Point2i;
typedef std::vector<std::vector<bool>> Graph;

double dist(const Point2i& p1, const Point2i& p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void InsertEdge(Graph& graph, int vertex1, int vertex2) {
  graph[vertex1][vertex2] = graph[vertex2][vertex1] = true;
}

bool DFS(const Graph& graph, int vertex, std::vector<bool>& Visited,
         const std::vector<bool>& isDestination) {
  if (Visited[vertex]) return false;
  Visited[vertex] = true;
  if (isDestination[vertex]) return true;
  for (size_t i = 0; i < graph[vertex].size(); ++i) {
    if (graph[vertex][i]) {
      if (DFS(graph, i, Visited, isDestination)) return true;
    }
  }
  return false;
}

int main() {
  int N, D;
  std::cin >> N >> D;

  std::vector<Point2i> points;
  points.reserve(N);
  for (int i = 0; i < N; ++i) {
    int x, y;
    std::cin >> x >> y;
    points.emplace_back(x, y);
  }

  Graph graph(N, std::vector<bool>(N, false));
  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = i + 1; j < points.size(); ++j) {
      if (dist(points[i], points[j]) <= D) {
        InsertEdge(graph, i, j);
      }
    }
  }

  std::vector<bool> isOrigin(N, false);       // 是否为起点
  std::vector<bool> isDestination(N, false);  // 是否为终点
  for (size_t i = 0; i < points.size(); ++i) {
    if (dist(points[i], Point2i(0, 0)) <= D + 7.5) {
      isOrigin[i] = true;
    }
    if (points[i].x >= 50 - D || points[i].x <= -50 + D ||
        points[i].y >= 50 - D || points[i].y <= -50 + D) {
      isDestination[i] = true;
    }
  }

  bool isOK = false;
  std::vector<bool> Visited(N, false);
  for (size_t i = 0; i < points.size(); ++i) {
    if (!Visited[i] && isOrigin[i]) {
      if (DFS(graph, i, Visited, isDestination)) {
        isOK = true;
        break;
      }
    }
  }
  if (isOK) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
