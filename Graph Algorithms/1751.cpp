// Problem Link: https://cses.fi/problemset/task/1751

#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (auto &x : p) {
        std::cin >> x;
        x--;
    }

    std::queue<int> path;
    std::vector<int> res(n), used(n);
    int steps = 0;

    auto dfs = [&] (auto &&self, int planet) {
        path.push(planet);
        if (used[planet]) {
            steps += res[planet];
            return;
        }
        used[planet] = 1;
        steps++;
        self(self, p[planet]);
    };

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            steps = 0;
            dfs(dfs, i);
            int dec = 1;
            
            while (!path.empty()) {
                if (path.front() == path.back()) {
                    dec = 0;
                }
                res[path.front()] = steps;
                steps -= dec;
                path.pop();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " \n"[i == n - 1];
    }   
}