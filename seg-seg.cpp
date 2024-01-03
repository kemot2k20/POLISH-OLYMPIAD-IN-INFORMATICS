int base;
int tree[2*N], lazy[2*N];

void push(int v){
    if(v >= base) return;
    tree[2*v] += lazy[v];
    tree[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
 
void add(int v,int be,int en,int x,int b,int val){
    if(b < be || en < x) return;
    if(be >= x && en <= b){
        tree[v] += val;
        lazy[v] += val;
    }else{
        push(v);
        int mid = (be+en)/2;
        add(v*2,be,mid,x,min(b,mid),val);
        add(v*2+1,mid+1,en,max(x,mid+1),b,val);
        tree[v] = max(tree[2*v],tree[2*v+1]);
    }
}
 
int mx(int v,int be,int en,int x,int b){
    if(b < be || en < x) return 0;
    if(be >= x && en <= b) return tree[v];
    push(v);
    int mid = (be+en)/2;
    int wynik = 0;
    wynik = max(wynik,mx(v*2,be,mid,x,min(b,mid)));
    wynik = max(wynik,mx(v*2+1,mid+1,en,max(x,mid+1),b));
    return wynik;
}
