#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define inf 1e9
void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

 vector<int> prime( int n ){

         vector<int>seive(n,1);      // 0-> means prime

          for( int i = 2; i *i < n; i++){

             if( seive[i] ){    // if it is prime

                  for( int k = 2 *i; k < n; k += i)
                      seive[k] = 0;     // mark other multiples of i as non -prime 
                  
             }

          }

          vector<int>res ;        // this will store primes with unit digit 3

          for( int i = 2; i < n; i++ ){

              if( (seive[i] == 1) && (i % 10 == 3) )
              res.push_back(i);
          }
      return res;

 }

int dp[10001];
 int f( int idx, vector<int>&cell, vector<int>&prime3,int n){
           if( idx >= n ) return -inf;
           if( idx == n -1) return cell[idx];

            
            if( dp[idx] != -1 ) return dp[idx];
           int res1 = 0;

           res1 += cell[idx] + f( idx + 1, cell, prime3, n);
             
             int res2 = -inf;
           for( int p : prime3){
              if( idx + p >= n ) continue;
              res2 = max( res2, f(idx + p, cell, prime3,n) );
           }

           res2 += cell[idx];

           return  dp[idx] = max(res1, res2);
     
 }



int main(int argc, char const *argv[]) { setupIO();

    vector<int> cell = {0,-10,-20,-30,50};
     int n = cell.size();

       vector<int>prime3 = prime(n);
        
       memset(dp, -1,sizeof(dp));

         cout << f(0,cell,prime3,n) <<'\n';
       

    return 0;
}