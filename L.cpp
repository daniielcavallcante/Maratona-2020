#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, c, n, i, j, k;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> l >> c;

    string word;
    char palavras[l][c];
    string mask[l][c];
    for(i = 0; i < l; i++){
        cin >> word;    
        for(int j = 0; j < c; j++){
            mask[i][j] = "";
            palavras[i][j] = word[j];
        }
    }   


    cin >> n;

    vector<string> colecao(n);

    char current = 'a';
    for(i = 0; i < n; i++){
        cin >> colecao[i];    

        sort(colecao[i].begin(), colecao[i].end());

        for(j = 0; j < l; j++){
            for(k = 0; k < c; k++){
                //Verificar na Horizontal
                string anagrama = "";
                for(int w = 0; w < colecao[i].size() && w + k < c; w++)
                    anagrama += palavras[j][k + w];

                sort(anagrama.begin(), anagrama.end());

                if(anagrama == colecao[i])
                    for(int w = 0; w < colecao[i].size() && w + k < c; w++)
                        mask[j][k + w] += current;


                //Verificar na Vertical
                anagrama = "";
                for(int w = 0; w < colecao[i].size() && w + j < l; w++)
                    anagrama += palavras[j + w][k];


                sort(anagrama.begin(), anagrama.end());
                if(anagrama == colecao[i])
                    for(int w = 0; w < colecao[i].size() && w + j < l; w++)
                        mask[j + w][k] += current;

                //Verificar na DP
                anagrama = "";
                int linha, coluna;
                for(linha = 0, coluna = 0; linha < colecao[i].size() && linha + j < l && coluna + k < c; linha++, coluna++)
                    anagrama += palavras[j + linha][k + coluna];


                sort(anagrama.begin(), anagrama.end());
                if(anagrama == colecao[i])
                    for(linha = 0, coluna = 0; linha < colecao[i].size() && linha + j < l && coluna + k < c; linha++, coluna++)
                        mask[j+linha][k+coluna] += current;


                //Verificar na DS
                anagrama = "";
                for(linha = 0, coluna = 0; linha < colecao[i].size() && linha + j < l && k + coluna >= 0; linha++, coluna--)
                    anagrama += palavras[j + linha][k + coluna];

                sort(anagrama.begin(), anagrama.end());
                if(anagrama == colecao[i])
                    for(linha = 0, coluna = 0; linha < colecao[i].size() && linha + j < l && k + coluna >= 0; linha++, coluna--)
                        mask[j+linha][k+coluna] += current;
                
            }
        }

        current++;
    }

    int ans = 0;
    for(i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            if(mask[i][j].size() > 0){
                string verify = mask[i][j];
                char first = verify[0];

                for(int w = 1; w < verify.size(); w++)
                    if(first != verify[w]){
                        ans++;
                        break;
                    }
            }

    cout << ans << endl;
    return 0;
}
