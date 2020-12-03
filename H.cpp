#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;


//https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
ull binomialCoeff(ull n, ull k){ 
    ull res = 1; 
  
    if(k > n - k) 
        k = n - k; 

    for(ull i = 0; i < k; ++i){ 
        res *= (n - i); 
        res /= (i + 1); 
    } 

    return res; 
} 

ull solve(vector<ull> pesos, ull max, int n, int k){
    ull prob = 0, sum = 0;
    int i, cont = 0, x, w, qt1 = 0;
    bool mask[n], flag;

    for(i = 0; i < n; i++){
        if(sum + pesos[i] <= max){
            mask[i] = true;
            sum += pesos[i];
            qt1++;
        }else
            mask[i] = false;
    }

    cont = 0;
    int cont1 = 0;
    for(i = 0; i < n; i++){
        if(mask[i]){
            x = n - (i+1);
            w = k - cont;
            cont++;
            prob += binomialCoeff(x, w);
            cont1++;
        }
        if(cont1 == k){
            prob++;
            break;
        }
    }
    
    return prob;
}

int main(){
    ull a, b, probA, probB;
    int n, k, i;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n >> k;

    vector<ull> pesos(n);
    for(i = 0; i < n; i++)
        cin >> pesos[i];
    
    cin >> a >> b;
    

    sort(pesos.begin(), pesos.end(),  greater<ull>());

    probB = solve(pesos, b, n, k);
    probA = solve(pesos, a-1, n, k);

    cout << probB - probA << endl;


    return 0;
}