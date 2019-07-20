#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
#define ll long long
#define N 200000
#define A 1000000
#define BLOCK 448 // ~sqrt(N)

ll cnt[A], a[N], ans[N];

struct node {
    int L, R, i;
}q[N];

bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

ll calculate(ll position){
    return (a[position] * ((cnt[a[position]] * cnt[a[position]]) - ((cnt[a[position]]-1) * (cnt[a[position]]-1)) ));
}


int main() {
    std::ios_base::sync_with_stdio(false);
    ll n;
    ll m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<m; i++) {
        ll left = 0, right = 0;
        cin>> left>>right;
   
        q[i].L = left;
        q[i].R = right;
        q[i].i = i;
    }
    

    sort(q, q + m, cmp);
    
    ll currentL = 0;
    ll currentR = 0;
    ll answer  = 0;

    for(ll i=0; i<m; i++) {
        
        ll L = q[i].L - 1;
        ll R = q[i].R - 1;
       
        while(currentL < L) {
            answer = (answer - calculate(currentL));
            cnt[a[currentL]]--;
            currentL++;
        }
    
        
        while(currentL > L) {
            currentL--;
            cnt[a[currentL]]++;
            answer = (answer + calculate(currentL));
          
        }

        while(currentR <= R) {
            cnt[a[currentR]]++;
            answer = (answer + calculate(currentR));
            currentR++;
        }

        while(currentR > R+1) {
            currentR--;
            answer = (answer - calculate(currentR));
            cnt[a[currentR]]--;
        }
        
        ans[q[i].i] = answer;
    }

    
    for(ll i=0; i<m; i++){
        cout<<ans[i]<<endl;
    }
}
