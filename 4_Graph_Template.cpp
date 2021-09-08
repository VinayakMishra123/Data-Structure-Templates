#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fastio() ios::sync_with_stdio(0); cin.tie(0);
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* *oset.find_by_order(index_in_set) :: ret element*/

#define ll long long int
#define ld long double
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll mod = 1000000007;

template<typename ty>
bool isrt(vector<ty> v){ 
    if(is_sorted(v.begin(),v.end()) == true)
        return true;
    else return false;}

#define pb push_back
#define inp(type,vec) type x;cin>>x;vec.pb(x); 
#define inc(i,x,n) for(ll i=x;i<n;i++)
#define dec(i,x,n) for(ll i=x;i>=n;i--)
#define step(TC) ll TC;cin>>TC;while(TC--)

struct Node{int data;Node *left;Node *right;};
struct node{ll data; node *next; node *prev;};
mt19937 rng;
int getRandomNumber(int l, int r)
{uniform_int_distribution<int> dist(l, r); return dist(rng);}
template<typename T>
void printa(T arr[],ll n){inc(i,0,n){cout<<arr[i]<<" ";}cout<<"\n";}
int __lcm(int a, int b){return (a * b) / __gcd(a, b);}

#define v(x,name) vector<x> name
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define reverse(v) reverse(v.begin(),v.end())
#define sort(v) sort(v.begin(),v.end())
#define digits(n) floor(log10(n)) + 1
#define printv(ar) for(auto x:ar){cout<<x<<" ";}cout<<endl;

/*void init_code(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}*/
#define one_built_ll(n) __builtin_popcountll(n)
#define one_built_int(n) __builtin_popcount(n)


/*-----start-----*/

/*
	//"KAHN'S ALGORITHM"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> adj[n];
    int in_deg[n];
    for(int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        in_deg[v]++;    //u->v : so v has incoming edge, hence indeg[v] inc by one 
        adj[u].push_back(v);
    } 

    queue<int> q;

    //push elements with in_deg ==0 in queue
    for(int i = 0; i < n; i++)
    {
        if(in_deg[i] == 0)
        {
            q.push(in_deg[i]);
        }
    }

    int count = 0;//if its cyclic directed ,then at some point ertices will 

    while(!q.empty())
    {
        //print first position in queue
        int val = q.top();
        q.pop();
        cout<<val<<" ";

        //decrease indegree of nodes adj to the node just popped
        for(auto x: adj[val])
        {
            in_deg[val]--;
            
            //push nodes with in_deg == 0 again after decreasing
        
            if(in_deg[i] == 0)
            {
                q.push(in_deg[i]);
            }

        }

        count++;
    }    
    if(count !=  n)
        cout<< "not a DAG" << "\n";
}*/

/*

	//" BFS AND DFS "
    
class graph
{

public:
    int V;
    list<int> *adj;
    graph(int v)
    {
        V = v;
        adj = new list<int>[V];
    }
    void connect(int source, int dest, bool bidirect = true)
    {
        adj[source].push_back(dest);
        if (bidirect)
        {
            adj[dest].push_back(source);
        }
    }
    void printList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    void bfs(int src)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (auto neighbour : adj[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void dfs_helper(int src,map<int,bool> &visited)
    {
    	cout<<src<<" ";
    	visited[src]=true;
    	for(auto y:adj[src])
    	{
    		if(!visited[src])
    		{
    			dfs_helper(y,visited);
    		}
    	}

    }

    void dfs(int src)
    {
    	map<int,bool> vis;
    	for(auto x:adj)
    	{
    		vis[x.first]=false;
    	}
    	dfs_helper(src,vis);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    graph g(6);

    g.connect(0, 1);
    g.connect(1, 2);
    g.connect(0, 4);
    g.connect(2, 4);
    g.connect(3, 2);
    g.connect(2, 3);
    g.connect(3, 5);
    g.bfs(0); 
}
*/

/*

	//" TOPOLOGICAL SORT "

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> adj[n];
    int in_deg[n];
    for(int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        in_deg[v]++;    //u->v : so v has incoming edge, hence indeg[v] inc by one 
        adj[u].push_back(v);
    } 

    queue<int> q;

    //push elements with in_deg ==0 in queue
    for(int i = 0; i < n; i++)
    {
        if(in_deg[i] == 0)
        {
            q.push(in_deg[i]);
        }
    }

    while(!q.empty())
    {
        //print first position in queue
        int val = q.top();
        q.pop();
        cout<<val<<" ";

        //decrease indegree of nodes adj to the node just popped
        for(auto x: adj[val])
        {
            in_deg[val]--;
        }

        //push nodes with in_deg == 0 again after decreasing
        for(int i = 0; i < n; i++)
        {
            if(in_deg[i] == 0)
            {
                q.push(in_deg[i]);
            }
        }


    }

    return 0;
}
*/

/*

    // "BIPARTITE BFS"

bool bipartiteBfs(int src, vector<int> aList[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto x : aList[node])
        {
            if (color[x] == -1)
            {
                color[x] = 1 - color[node];
                q.push(x);
            }
            else if (color[x] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool checkbiPartite(vector<int> vec[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, vec, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    if (checkbiPartite(adj, n))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}

*/
/*

    // " TOPO-SORT USINF DFS"
void topoSort_helper(int src, stack<int> &st, vector<int> graph[], vector<bool> &vis)
{
    vis[src] = true;
    for (auto x : graph[src])
    {
        if (vis[x] == false)
        {
            topoSort_helper(x, st, graph, vis);
        }
    }
    st.push(src);
}
vector<int> topoSort(int n, vector<int> graph[])
{
    vector<bool> vis(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            topoSort_helper(i, st, graph, vis);
        }
    }
    vector<int> answer;
    while (st.empty() != false)
    {
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
}

int main()
{
}

*/
