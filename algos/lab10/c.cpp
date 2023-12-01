#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int bfs(int a, int b) {
    queue<int> q;
    vector<int> distance(99999, INT_MAX);
    vector<int> parent(99999, -1);

    q.push(a);
    distance[a] = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == b) {
            vector<int> path;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }

            cout << path.size() - 1 << endl;
            for (int i = path.size() - 2; i >= 0; --i) {
                cout << path[i] << " ";
            }
            return distance[b];
        }

        int number_one = current * 2;
        if (number_one < 99999 && distance[number_one] == INT_MAX) {
            q.push(number_one);
            distance[number_one] = distance[current] + 1;
            parent[number_one] = current;
        }

        int number_two = current - 1;
        if (number_two >= 0 && distance[number_two] == INT_MAX) {
            q.push(number_two);
            distance[number_two] = distance[current] + 1;
            parent[number_two] = current;
        }
    }

    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;

    int result = bfs(a, b);
    // cout << endl;

    return 0;
}