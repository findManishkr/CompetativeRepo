#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long 

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


ll f( vector <string> &stringData){

    
    unordered_map< int,int>maskCount;  // stores the freq of each unique parity mask, 
    // {key: parityMask, value: freq}

    // step1

    // calculate parity mask for all strings 

       for( auto str : stringData ){
           
           int currMask = 0;

           for( char ch : str ){
              
                 // determine the bit position ( 0->`a`, 1 ->`b`....and so on)
               int bitIdx = ch - 'a';


               // flip the corresponding bit using xor, 
               // if char appears odd number of times , the bit will be one 

               currMask ^= ( 1 << bitIdx) ;
           }

            maskCount[currMask]++;

       }

       ll totalPairs = 0;

       // step - 2
       // find complementary pairs using xor logic

       // iterate over all unique masks in  found in stringData

          for( auto pairr : maskCount ){
               
              int mask1 = pairr.first;
              ll count1 = pairr.second;

              // case 1, target xor is 0 ie ( M1 ^ M2 == 0) => M2 must be M1
               // this case covers pair of identical masks

               if( count1 >= 2){
                totalPairs += count1 * ( count1 -1 )/2;
               }

               // case 2: target xor is 2^k ( M1 ^ M2 = 2^k) > ie M2 differs M1 by one bit
              
                 for( int k = 0; k < 26; k++){
                  
                    int mask2 = mask1 ^ ( 1 << k);

                    // we check two conditions to prevent double counting

                    // 1. mask2 must exist in our map
                    // 2. mask1 must be strictly less that mask2 ( M1 < M2)

                    // this ensures that the pair (M1, M2) is counted only once, when process the smaller mask

                    if( mask2 > mask1 && maskCount.count( mask2) ){
                       ll count2 = maskCount[ mask2];

                       totalPairs += count1 * count2;

                    }

                 }

          }


          return totalPairs;

}


int main(int argc, char const *argv[]) { setupIO();

       vector< string >stringData =   {"ball", "all", "call", "bal"};

             cout << f( stringData ) <<'\n';

    return 0;
}