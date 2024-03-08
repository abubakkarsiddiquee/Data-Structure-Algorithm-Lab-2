#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];

long long merge(int l, int r, int mid){
    int l_s = mid - l + 1;
    int l_arr[l_s + 1];

    int r_s = r - mid;
    int r_arr[r_s + 1];

    for(int i = 0; i < l_s; i++){
        l_arr[i] = a[i + l];
    }

    for(int i = 0; i < r_s; i++){
        r_arr[i] = a[mid + 1 + i];
    }

    l_arr[l_s] = r_arr[r_s] = INT_MAX;

    int l_count = 0, r_count = 0;
    long long inversions = 0; 

    for(int i = l; i <= r; i++){
        if(l_arr[l_count] <= r_arr[r_count]){
            a[i] = l_arr[l_count];
            l_count++;
        }
        else{
            a[i] = r_arr[r_count];
            r_count++;

         
            inversions += l_s - l_count;
        }
    }

    return inversions;
}

long long mergeSort(int l, int r){
    long long inversions = 0;

    if(l < r){
        int mid = (l + r) / 2;

  
        inversions += mergeSort(l, mid);
        inversions += mergeSort(mid + 1, r);

   
        inversions += merge(l, r, mid);
    }

    return inversions;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

   
    long long inversions = mergeSort(0, n - 1);

  
    cout << inversions << endl;

    return 0;

}
