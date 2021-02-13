const int MAX=1<<19;
int LAZY[MAX*4],SUM[MAX*4];
 
void push(int u,int lo,int hi){
  LAZY[2*u]+=LAZY[u];
  LAZY[2*u+1]+=LAZY[u];
  SUM[u]+=LAZY[u]*(hi-lo+1);
  LAZY[u]=0;
}
 
void update(int a,int b,int u,int lo,int hi,int c){
  if (b<lo || a>hi)return;
  if (a<=lo && b>=hi){
    LAZY[u]+=c;
    return;
  }
  SUM[u]+=(min(b,hi)-max(a,lo)+1)*c;
  int mid=(lo+hi)>>1;
  update(a,b,2*u,lo,mid,c);
  update(a,b,2*u+1,mid+1,hi,c);
}
 
int getsum(int a,int b,int u,int lo,int hi){
  if (b<lo || a>hi)return 0;
  push(u,lo,hi);
  if (a<=lo && b>=hi)
    return SUM[u];
  int mid=(lo+hi)>>1;
  int L=getsum(a,b,2*u,lo,mid);
  int R=getsum(a,b,2*u+1,mid+1,hi);
  return L+R;
}
int32_t main(){
  BOOST;
  int n,q;
  cin>>n>>q;
  for (int z=0;z<q;z++){
    int type;
    cin>>type;
    if (type==1){
      int a,b,c;
      cin>>a>>b>>c;
      update(a,b,1,1,MAX,c);
    }
    else{
      int a,b;
      cin>>a>>b;
      cout<<getsum(a,b,1,1,MAX)<<"\n";
    }
  }  
  return 0; 
}
