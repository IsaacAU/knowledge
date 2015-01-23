#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
#include<set>

#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void printPath(vi &prev){
    for(int i=0; i<prev.size(); ++i){
        vi path;
        path.pb(i);
        int x=i;
        while(prev[x]>=0){
            path.insert(begin(path), prev[x]);
            x=prev[x];
        }
        for(auto x:path)
            cout<<x<<"->";
        cout<<endl;
    }
}

// implement with priority queue
vi dijkstra1(vvii &G, int s){
    int v=G.size();
    vi D(v,INT_MAX), prev(v, -1);
    bool visit[v];
    fill_n(visit, v, false);
    D[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(ii(0,s));
    while(!pq.empty()){
        ii t=pq.top();
        pq.pop();
        int u=t.second;
        visit[u]=true;
        for(auto p:G[u]){
            int u2=p.second, d2=p.first;
            if(visit[u2])   continue;
            if(D[u2]>D[u]+d2){
                prev[u2]=u;
                D[u2]=D[u]+d2;
                pq.push(ii(D[u2],u2));
            }
        }
    }
    printPath(prev);
    return D;
}

// implement with set
vi dijkstra2(vvii &G, int s){
    int v=G.size();
    vi D(v, INT_MAX), prev(v, -1);
    set<ii> Q;
    Q.insert(ii(0,s));
    D[s]=0;
    while(!Q.empty()){
        ii t=*begin(Q);
        Q.erase(begin(Q));
        int u=t.second;
        for(auto p:G[u]){
            int u2=p.second, d2=p.first;
            if(D[u2]>D[u]+d2){
                auto it=Q.find(ii(D[u2], u2));
                if(it!=Q.end())
                    Q.erase(it);
                prev[u2]=u;
                D[u2]=D[u]+d2;
                Q.insert(ii(D[u2], u2));
            }
        }
    }
    printPath(prev);
    return D;
}


int main()
{
    freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);
    int v,e,x,y,w,s;
    cin>>v>>e;
    vvii G(v,vii());
    for(int i=0; i<e; ++i){
        cin>>x>>y>>w;
        G[x].pb(ii(w,y));
    }
    cin>>s;
    vi D=dijkstra1(G, s);
    for(auto d:D)
        cout<<d<<"\t";
    cout<<endl;
}
