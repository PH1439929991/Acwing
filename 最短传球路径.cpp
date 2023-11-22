#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义队伍的行数和列数
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// 定义四个方向的移动
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Position {
    int x, y;
    int steps;
};

int bfs(vector<vector<char>>& classroom, int m, int n) {
    // 使用队列进行BFS
    queue<Position> q;

    // 初始化队列，从第一列的男同学开始
    for (int i = 0; i < m; ++i) {
        if (classroom[i][0] == '1') {
            q.push({i, 0, 0});
        }
    }

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        // 到达最后一列的男同学，返回传球次数
        if (current.y == n - 1) {
            return current.steps;
        }

        // 向四个方向传球
        for (int dir = 0; dir < 4; ++dir) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];

            // 检查是否越界，是否能够传球
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] == '1') {
                q.push({nx, ny, current.steps + 1});
                // 标记已经传球过的位置，避免重复传球
                classroom[nx][ny] = 'X';
            }
        }
    }

    // 无法完成任务
    return -1;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> classroom(MAX_ROWS, vector<char>(MAX_COLS));

    // 读入班级队伍信息
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> classroom[i][j];
        }
    }

    int minSteps = bfs(classroom, m, n);

    if (minSteps == -1) {
        cout << -1 << endl;
    } else {
        cout << minSteps << endl;
    }

    return 0;
}

