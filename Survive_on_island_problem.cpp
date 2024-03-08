#include <bits/stdc++.h>
using namespace std;

int main (){
    int s, n, m;
    cin>> s>> n>> m;
    int x = s/7;
    int y = s - x;
    int sm = s * m;
    int node = sm / n;

    if(sm % n != 0 ) node++;
    if(node <= y){
        cout <<  node;
    }
    else{
        cout << "-1";
    }

    return 0;
}
