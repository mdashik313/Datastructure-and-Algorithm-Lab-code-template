#include <bits/stdc++.h>
using namespace std;

void merge(int ara[], int l, int mid, int r){
    
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1],M[n2];

    for(int i=0; i<n1; i++){
        L[i] = ara[l+i];
    }
    for(int j=0; j<n2; j++){
        M[j] = ara[mid+j+1];
    }

    int i,j,k;
    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= M[j]){
            ara[k] = L[i];
            i++;
        }
        else {
            ara[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        ara[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ara[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int ara[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(ara,l,mid);
        mergeSort(ara,mid+1,r);

    }
}

int main()
{
    
    return 0;
}

