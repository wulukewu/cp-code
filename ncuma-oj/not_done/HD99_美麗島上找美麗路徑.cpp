// #include <iostream>
// #include <vector>

// using namespace std;

// vector < vector < int > > arr;
// vector < int > c;

// signed dfs(int x, int ori, vector < int >& visited){
//     int y = 0;

//     if(c[x]==c[ori] and x!=ori){
//         return 1;
//     }

//     for(int i=0; i<arr[x].size(); i++){
//         if(visited[arr[x][i]]==0){
//             visited[arr[x][i]] = 1;
//             y += dfs(arr[x][i], ori, visited);
//             visited[arr[x][i]] = 0;
//         }
//     }

//     return y;
// }

// signed main(){
//     int t;
//     cin >> t;

//     while(t--){
//         int n;
//         cin >> n;
        
//         c = vector < int > (n);
//         for(int i=0; i<n; i++){
//             cin >> c[i];
//         }

//         int v, u;
//         arr = vector < vector < int > > (n);
//         for(int i=0; i<n-1; i++){
//             cin >> v >> u;
//             arr[v-1].push_back(u-1);
//             arr[u-1].push_back(v-1);
//         }

//         int ans = 0;
//         for(int i=0; i<n; i++){
//             vector < int > visited(n, 0);
//             visited[i] = 1;
//             ans += dfs(i, i, visited);
//         }

//         ans /= 2;

//         cout << ans << endl;
//     }
// }

#include <iostream>
#include <vector>
#include <numeric>
#include <map>           // Using map instead of unordered_map for potentially wider compatibility
#include <vector>
#include <set>           // Using set instead of unordered_set for potentially wider compatibility
#include <utility>       // For std::pair and std::make_pair

// --- Disjoint Set Union (DSU) Implementation ---
struct DSU {
    std::vector<int> parent;
    // Constructor initializes DSU for n elements (1 to n)
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the set containing i, with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent[i]);
    }

    // Unite the sets containing i and j
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

// --- Function to solve a single test case ---
void solve() {
    int n;
    std::cin >> n;

    std::vector<int> colors(n + 1);
    // Using std::map for broader compatibility than unordered_map (C++11)
    std::map<int, std::vector<int> > nodes_by_color; // Space between > >
    for (int i = 1; i <= n; ++i) {
        std::cin >> colors[i];
        nodes_by_color[colors[i]].push_back(i);
    }

    // Adjacency list
    std::vector<std::vector<int> > adj(n + 1); // Space between > >
    // Store edges
    std::vector<std::pair<int, int> > edges;   // Space between > >
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // Use make_pair instead of initializer list {}
        edges.push_back(std::make_pair(u, v));
    }

    long long total_beautiful_paths = 0;

    // Iterate through each distinct color present in the tree
    // Using iterators for C++98/03/11 compatibility instead of C++17 structured binding
    for (std::map<int, std::vector<int> >::const_iterator it = nodes_by_color.begin(); it != nodes_by_color.end(); ++it) {
        int color_c = it->first;
        const std::vector<int>& nodes_with_color_c = it->second; // Get reference to the vector

        if (nodes_with_color_c.size() < 2) {
            continue;
        }

        DSU dsu(n);
        // Build DSU based on non-color_c nodes
        // Using C++11 range-based for loop here. If this still causes warnings/errors,
        // replace with: for (std::vector<std::pair<int, int> >::const_iterator edge_it = edges.begin(); edge_it != edges.end(); ++edge_it)
        for (size_t i = 0; i < edges.size(); ++i) { // C++98 compatible loop
             int u = edges[i].first;
             int v = edges[i].second;
             if (colors[u] != color_c && colors[v] != color_c) {
                 dsu.unite(u, v);
             }
        }


        long long color_c_paths = 0;
        // Using std::map for broader compatibility
        std::map<int, int> component_counts;

        // Iterate through each node 'u' that has the current color 'color_c'
        // Using C++11 range-based for loop. If needed, replace with iterator loop.
        for (size_t i = 0; i < nodes_with_color_c.size(); ++i) { // C++98 compatible loop
            int u = nodes_with_color_c[i];
            // Using std::set for broader compatibility
            std::set<int> processed_components_for_u;

            // Check all neighbors of 'u'
            // Using C++11 range-based for loop. If needed, replace with iterator loop.
             for (size_t j = 0; j < adj[u].size(); ++j) { // C++98 compatible loop
                int neighbor = adj[u][j];
                if (colors[neighbor] == color_c) {
                    if (u < neighbor) {
                        color_c_paths++;
                    }
                } else {
                    int component_root = dsu.find(neighbor);
                    // Use find() method for std::set
                    if (processed_components_for_u.find(component_root) == processed_components_for_u.end()) {
                        color_c_paths += component_counts[component_root];
                        component_counts[component_root]++;
                        processed_components_for_u.insert(component_root);
                    }
                }
            }
        }
        total_beautiful_paths += color_c_paths;
    }

    std::cout << total_beautiful_paths << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}