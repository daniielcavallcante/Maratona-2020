#include <bits/stdc++.h>
 
using namespace std;

#define MOD 1000000007 

typedef long long int ll;
 
ll sum(ll a, ll b){
    return (((a % MOD) + (b % MOD)) % MOD);
}

ll product(ll a, ll b){
    return (((a % MOD) * (b % MOD)) % MOD);
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
 
    ll n, i, x, cont = 1, idx;;
    cin >> n;   
    vector<vector<ll>> tree(n+1);
 
    queue<ll> fila;
    stack<ll> pilha;
 
    ll pd[n+1][2];
    for(i = 1; i <= n; i++){
        tree[i].emplace_back(-1LL);
        pd[i][0] = 1LL;
        pd[i][1] = 1LL;
    }
 
    for(i = 1; i <= n-1; ++i){
        cin >> x;
        tree[x].emplace_back(i+1);
    }
 
 
    fila.push(1);
 
    while(!fila.empty()){
        idx = fila.front();

        if(tree[idx].size() > 1)
            for(i = 1; i < tree[idx].size(); ++i){
                fila.push(tree[idx][i]);
                cont++;
            }
 
        pilha.push(idx);
        fila.pop();
 
        if(cont == n)
            while(!fila.empty()){
                pilha.push(fila.front());
                fila.pop();
            }
    }
    
    while(!pilha.empty()){
        idx = pilha.top();

        if(tree[idx].size() <= 1){
            pd[idx][0] = (ll)1;
            pd[idx][1] = (ll)1;
        }else{
            vector<ll> pref(tree[idx].size());
            vector<ll> suf(tree[idx].size());

            pref[0] = 1LL;
            suf.emplace_back(1LL);

            for(i = 1; i < tree[idx].size(); ++i)
                pref[i] = product(pref[i-1], pd[tree[idx][i]][0]);
 
            for(i = tree[idx].size() - 1; i >= 1; --i)
                suf[i] = product(suf[i+1], pd[tree[idx][i]][0]);
 
            ll s2 = 0LL;
            for(i = 1; i < tree[idx].size(); ++i)
                s2 = sum(s2, product(product(pref[i-1], pd[tree[idx][i]][1]), suf[i+1]));
 
 
            pd[idx][0] = sum(suf[1], s2);
            pd[idx][1] = s2;

            suf.clear();
            pref.clear();
        }
 
        pilha.pop();
    }

    cout << pd[1][0] % 1000000007 << '\n';
 
    return 0;
}
