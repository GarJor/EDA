#include <iostream>
#include <vector>
using namespace std;


typedef vector< vector<int> > Graf;
typedef vector<bool> Tiza;

bool es_aciclic(const Graf& g, Tiza& t, int u, int oldu){

    if(not t[u]){
        int control = 0;
        t[u]= true;
        for(const auto& i: g[u]){
            if(i > 0) c.pop_back();
            if(old!=i) ++control;
            if(oldu!=i and not es_aciclic(g,t,i,u))return false;
        }
        return true;
    }
    else return false;
}

bool es_bosc(const Graf& g, int& nArbres){

    Tiza t(g.size(),false);
    for(int i=0; i<g.size(); i++){

        if(not t[i]){

            if(es_aciclic(g,t,i,-1))nArbres++;
            else return false;
        }
    }
    return true;
}

int main(){

    int n,m; //n vertices y m aristas
    while(cin>>n>>m){

        Graf g(n);
        while(m--){

            pair<int,int> a;
            cin>>a.first>>a.second;
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        int nArbres=0;
        if(es_bosc(g,nArbres))cout<<nArbres<<endl;
        else cout<<"no"<<endl;
      }
  }
