/*

# 🏙️ Longest Ambulance Response Time

**Difficulty:** Medium  
**Tags:** Graph, BFS, Shortest Path, Multi-source BFS  

---

### 📘 Problem Description

In a city, there are **N districts**, numbered from `0` to `N - 1`, connected by **M two-way streets**.  
Some districts have **hospitals**.  

When an ambulance is needed in a district, it is dispatched from the **nearest hospital** — the one that can reach the district in the **shortest time**.  
Each street takes **exactly 1 minute** to travel.

You need to determine the **longest time** it would take for an ambulance to reach any district in the city, assuming it always takes the shortest possible route.

If any district cannot be reached from any hospital (i.e., it lies in a disconnected component), return **-1**.

---

### 🧩 Function Signature

```cpp
int solution(int N, vector<int>& A, vector<int>& B, vector<int>& H);

*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const int inf = 1e9 + 7;
int solution(int N, vector<int>& A, vector<int>& B, vector<int>& H){

                int  n = A.size();
       vector< vector<int>>graph(N, vector<int>());

        for( int i = 0; i < n; i++){

           int u = A[i], v = B[i];
           graph[u].push_back(v);
           graph[v].push_back(u);

        }

        vector< bool> vis(N,false);
        vector< int> dist(N,inf);

        queue< int > q;
        for( int i = 0;i < H.size(); i++){
               q.push( H[i]);
               dist[H[i]] = 0;
               vis[H[i]] = true;
        }

          while( !q.empty()){

               int node = q.front(); q.pop();


               // process node 


                 for( int nbd : graph[node] ){
                    if( vis[nbd] ) continue;

                    dist[nbd] = 1 + dist[node];
                    q.push(nbd);
                    vis[nbd] = 1;

                 }


          }


          int maxi = *max_element( dist.begin(),dist.end());


return maxi == inf ? -1 : maxi;

}

int main(int argc, char const *argv[]) { setupIO();

         int n = 6;
         vector<int>A = {0, 1, 1, 2, 4, 4};
         vector<int>B = {1, 2, 3, 4, 5, 0};
         vector < int >  H = {0, 5};

         int ans = solution(n, A, B,H);

           cout << ans <<'\n';

    return 0;
}