// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// The Graph structure is as folows

// Function to print graph
// adj: array of vectors to represent graph
// V: number of vertices
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i;

        for (int j = 0; j < adj[i].size(); j++)
            cout << "-> " << adj[i][j];

        cout << endl;
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        int a, b;
        vector<int> adj[v];
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printGraph(adj, v);
    }
    return 0;
}

// } Driver Code Ends