#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}

void dfs(int S,vector<int> adj[],bool* visited,int* arr,int& li)
{
    vector<int> ::iterator i;
    for(i=adj[S].begin();i!=adj[S].end();i++)
    {
        if(!visited[*i])
        {
            dfs(*i,adj,visited,arr,li);
        }
    }
    if(!visited[S])
    {
        visited[S]=true;
        arr[li--]=S;
    }
    
}

int* topoSort(int V, vector<int> adj[]) {
    // Your code here4
    int* arr=new int[V];
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    int li=V-1;
   // vector<int>::iterator i;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,arr,li);
        }
    }
    return arr;
    
    
    
}