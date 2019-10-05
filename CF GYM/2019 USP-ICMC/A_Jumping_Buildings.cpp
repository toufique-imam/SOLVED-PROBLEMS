#include<bits/stdc++.h>
using namespace std;
#define SEGTREE int mid=(st+en)/2,lt=node*2,rg=lt+1
const int N=1e5+9;
struct nd{
    int idmin,idmax,mini,maxi;
    nd(){
        idmax=idmin=mini=maxi=0;
    }
};
nd seg[4*N];
int ara[N];
void merge_(nd &par,nd &lt_c,nd &rg_c){
    if(lt_c.mini<=rg_c.mini){
        par.mini=lt_c.mini;
        par.idmin=lt_c.idmin;
    }
    else {
        par.mini=rg_c.mini;
        par.idmin=rg_c.idmin;
    }
    if(lt_c.maxi>=rg_c.maxi){
        par.maxi=lt_c.maxi;
        par.idmax=lt_c.idmax;
    }
    else {
        par.maxi=rg_c.maxi;
        par.idmax=rg_c.idmax;
    }
}
void build(int node,int st,int en){
    if(st==en){
        seg[node].idmax=seg[node].idmin=st;
        seg[node].maxi=seg[node].mini=ara[st];
        return;
    }
    SEGTREE;
    build(lt,st,mid);
    build(rg,mid+1,en);
    merge_(seg[node],seg[lt],seg[rg]);
}

int query(int node,int st,int en,int l,int r,int val){
    if(st>r || en<l)return 1e9;
    if(seg[node].maxi<val)return 1e9;
    if(st>=l && en<=r){
        if(seg[node].mini>val)return st;
    }
    SEGTREE;
    if(seg[lt].maxi>val)return query(lt,st,mid,l,r,val);
    else if(seg[rg].maxi>val) return query(rg,mid+1,en,l,r,val);
    return 1e9;
}
void delete_(int node,int st,int en,int l){
    if(st>l || en<l)return;
    if(st==en && st==l){
        seg[node].idmax=seg[node].idmin=l;
        seg[node].maxi=0;
        seg[node].mini=1e9;
        return;
    }
    SEGTREE;
    delete_(lt,st,mid,l);
    delete_(rg,mid+1,en,l);
    merge_(seg[node],seg[lt],seg[rg]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int ans=query(1,1,n,i+1,min(n,ara[i]+i),ara[i]);
        if(ans>=1e9){
            printf("%d ",min(ara[i]+i,n)-i);
        }
        else
            printf("%d ",ans-i-1);
        delete_(1,1,n,i);
    }
    printf("\n");
}
