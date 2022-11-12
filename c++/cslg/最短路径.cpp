#include <iostream>

#define int long long
const int N=2e5+5,M=N<<2;
int n,m,s,h[N],en,dis[N];
struct point{int i,x,y;}a[N]; //存点坐标
struct node{ //松弛操作中的节点
    int x,v;
    inline bool operator < (const node &nt) const {
        return v>nt.v;
    }
};
struct edge{int n,v,w;}e[M]; //前向星边表
void add(int x,int y,int z){e[++en]=(edge){h[x],y,z};h[x]=en;} //加边
void dij(int s){ //dij模板
    priority_queue<node> q;
    memset(dis,66,sizeof dis);
    q.push((node){s,0});
    dis[s]=0;
    while(!q.empty()){
        node x=q.top();
        q.pop();
        if(x.v!=dis[x.x]) continue; //一个dij懒惰操作，省去了visit[]数组
        for(int i=h[x.x];i;i=e[i].n){
            int y=e[i].v;
            if(dis[x.x]+e[i].w<dis[y]){
                dis[y]=dis[x.x]+e[i].w;
                q.push((node){y,dis[y]});
            }
        }
    }
}
inline bool cmpx(const point &x,const point &y){return x.x==y.x?x.y<y.y:x.x<y.x;}
inline bool cmpy(const point &x,const point &y){return x.y==y.y?x.x<y.x:x.y<y.y;}
signed main(){
    read(n);
    for(int i=1;i<=n;i++)
        a[i].i=i,read(a[i].x),read(a[i].y);
    sort(a+1,a+1+n,cmpx); //按横坐标排
    for(int i=2;i<=n;i++)
        add(a[i-1].i,a[i].i,a[i].x-a[i-1].x), //前后节点建双向边
        add(a[i].i,a[i-1].i,a[i].x-a[i-1].x);
    sort(a+1,a+1+n,cmpy); //按纵坐标排
    for(int i=2;i<=n;i++)
        add(a[i-1].i,a[i].i,a[i].y-a[i-1].y),
        add(a[i].i,a[i-1].i,a[i].y-a[i-1].y);
    dij(1);
    printf("%lld",dis[n]);
}