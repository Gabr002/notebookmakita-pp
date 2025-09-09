#include <iostream>
#include <vector>
#include <numeric> 


using namespace std;


typedef long long ll;

/**
 * @brief Performs a Depth First Search (DFS) traversal on a graph.
 * * @param v The current vertex to visit.
 * @param g The adjacency list representation of the graph. Passed by reference to avoid copying.
 * @param vis The visited array, marking which nodes have been visited. Passed by reference to modify the original.
 */
void dfs(int v, const vector<vector<int>>& g, vector<bool>& vis)
{
    vis[v] = true;

    for (int w : g[v])
    {
        if (!vis[w])
        {
            dfs(w, g, vis);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;

    cin >> n >> m;


    vector<vector<int>> g(n);
    vector<bool> vis(n, false); 


    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
    
        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }


    int times = 0;


    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
         
            dfs(i, g, vis);

            times++;
        }
    }

    cout << times << endl;

    return 0;
}
