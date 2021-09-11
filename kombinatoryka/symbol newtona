const ll mod = 998244353;
const ll INF = mod;
const int N = 200005;
ll sil[N];
ll odw[N];
 
ll npok(ll a, ll b){
    if(b > a or b < 0)
        return 0;
    return sil[a] * odw[b] % INF * odw[a - b] % INF;
}

ll fast(ll a, ll b){
    ll ret = 1;
 
    while(b){
        if(b & 1)
            ret = ret * a % INF;
        a = a * a  % INF;
        b /= 2;
    }
    return ret;
}
 
void prep(){
    sil[0] = 1;
    for(int i = 1; i < N; i++)
        sil[i] = sil[i - 1] * i % INF;
 
    odw[N - 1] = fast(sil[N - 1], INF - 2);
 
    for(int i = N - 2; i >= 0; i--)
        odw[i] = odw[i + 1] * (i + 1) % INF;
}
 
