#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL p1 = 1, p2 = 1, p3 = 1, p4 = 0;
LL mod = 1000000007;

void fast_pow(int n){
    if(n == 1)
        return;
        
    if(n % 2 == 0){
        fast_pow(n / 2);
        LL c1 = p1;
        LL c2 = p2;
        LL c3 = p3;
        LL c4 = p4;
        
        p1 = ((c1 * c1) % mod + (c2 * c3) % mod) % mod;
        p2 = ((c1 * c2) % mod + (c2 * c4) % mod) % mod;
        p3 = ((c1 * c3) % mod + (c3 * c4) % mod) % mod;
        p4 = ((c2 * c3) % mod + (c4 * c4) % mod) % mod;
    }
    else{
        fast_pow(n - 1);
        LL c1 = p1;
        LL c2 = p2;
        LL c3 = p3;
        LL c4 = p4;
        
        p1 = (c1 + c2) % mod;
        p2 = c1;
        p3 = c1;
        p4 = c2;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    fast_pow(n + 2);

    cout << (p1 - 1 + mod) % mod << '\n';
}
