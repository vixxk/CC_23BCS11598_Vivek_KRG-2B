#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto flight : flights){
        adj[flight[0]].push_back({flight[1], flight[2]});
    }
    queue<pair<int, int>> q;
    q.push({src, 0});
    vector<int> minCost(n, INT_MAX);
    int stops = 0;
    while(!q.empty() && stops <= k){
        int size = q.size();
        while (size--) {
            auto [currNode, cost] = q.front();
            q.pop();
            for (auto& [neighbour, price] : adj[currNode]) {
                if (price + cost < minCost[neighbour]){
                    minCost[neighbour] = price + cost;
                    q.push({neighbour, minCost[neighbour]});
                }
            }
        }
        stops++;
    }
    if(minCost[dst] == INT_MAX)
        return -1;
    return minCost[dst];
}

int main() {
    int n = 4;

    vector<vector<int>> flights = 
    {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int result = findCheapestPrice(n, flights, src, dst, k);

    if (result == -1) cout << "No valid route found within " << k << " stops\n";
    else cout << "Cheapest price: " << result << endl;

    return 0;
}
