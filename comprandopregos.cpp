#include <bits/stdc++.h>

using namespace std;

int bs(int target, vector<int> v){
    //1. definir o intervalo
    int l = 0, r = (int) v.size() - 1;

    //2. executar a busca

    while(l < r){
        int mid = (l + r) / 2;
        
        //3. condição que eu quero que seja uma possivel resposta
        if(v[mid] <= target) l = mid; // mid é possivel, mas [l .. mid - 1]
        //4. else, condicao que eu nao quero que seja uma resposta possivel
        if(v[mid] > target) r = mid - 1; //[l ... mid - 1]
    }
    //l == ... , r == ...
    //se eu quero que seja reposta: l == mid ou r == mid
    //se eu NAO quero que seja reposta: l == mid + 1 ou r == mid - 1
    
    //teto a/b => (a - 1) / b + 1 
    //=> (a - 1)/2 + 1 => (a - 1 + 2) / 2 

    //l == mid => int mid = (l + r + 1) / 2;
    //r == mid => int mid = (l + r) / 2;

    //[3, 5] => target == 4
    //          mid == (0 + 1) / 2 == 0
    // if(v[0]: 3 <= 4) => l = 0
    // l == 0, r == 1

    //(l + r + 1) / 2
    //[3, 5] => target == 4
    //          mid == (0 + 1 + 1) / 2 == 1
    // if(v[1]: 5 <= 4)
    // if(v[1]: 5 > 4) r = 0
    // l == 0, r == 0

    //l == r: v[l] >= target

    if(v[l] > target) return -1;

    return l;
}

int k;
long long q, n;

bool mid_caixas_satisfazem(long long num_caixas, long long num_pregos){
    // [n, n -1, n -2 ... n - num_caixas + 1]
    // (a0 + an) * num_termos / 2
    long long soma = (n + n - num_caixas + 1) * num_caixas / 2;
    return (soma >= num_pregos);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    while(k--){
        cin >> n >> q;

        //logica
        // 1 2 3 4 5 6 7 8 9 10 
        // 25 pregos => preciso das x maiores
        //k caixas funcionam => k + 1 caixas funcionam
        //l caixas nao funcionam => l - 1 caixas nao funcionam
        //funcao: numero_x_de_caixas_funciona(x)
        // 1 1 1 1 1 0 0 0

        //1.intervalo
        int l = 1, r = (int) n;
        //checa se usando todas as caixas funcionam

        while(l < r){

            //l = mid => int mid = (l + r + 1) / 2;
            //r = mid => int mid = (l + r) / 2;
        
            int mid = (l + r) / 2;
            // cout << mid << " " << mid_caixas_satisfazem(mid, q) << "\n";
            if(mid_caixas_satisfazem(mid, q)) r = mid; // [l .. mid]
            else l = mid + 1;
        }
        //l == r: r == n
        if(mid_caixas_satisfazem(l, q)) cout << l << "\n";
        else cout << "IMPOSSIVEL\n";
    }


    return 0;
}
