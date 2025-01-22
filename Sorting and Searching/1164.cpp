// Problem Link: https://cses.fi/problemset/task/1164

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<std::pair<int, int>, int>> arr(n);
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }
    
    std::sort(begin(arr), end(arr));
    int avail_room = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        if (pq.empty() or pq.top().first >= arr[i].first.first) {
            avail_room += 1;
            pq.push({arr[i].first.second, avail_room});
            res[arr[i].second] = avail_room;
        } else {
            auto f = pq.top();
            pq.pop();
            pq.push({arr[i].first.second, f.second});
            res[arr[i].second] = f.second;
        }
    }

    std::cout << avail_room << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " \n"[i == n - 1];
    }
}