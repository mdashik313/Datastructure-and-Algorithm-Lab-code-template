#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    double valPerWeight1 = (double)a.second/a.first, valPerWeight2 = (double)b.second/b.first;
    return valPerWeight1 > valPerWeight2;
}

void printV(vector<pair<int,int>> &v, int n){
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<" v/w = "<<(double)v[i].second/v[i].first<<endl;
    }
}

void fractionalKnapsack(vector<pair<int,int>> &v, int n, int w){
    sort(v.begin(),v.end(),cmp);
    printV(v,n);


    int profit=0, knap_left=w;
    int itr = 0;
    while(itr < n && knap_left>0){
        profit += v[itr].second;
        knap_left -= v[itr].first;
        itr++;
    }

    cout<<"profit = "<<profit<<endl;
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,w;
    cin>>n;

    vector<pair<int,int>>v;

    for(int i=0; i<n; i++){
        int weitht,value;
        cin>>weitht>>value;
        v.push_back(make_pair(weitht,value));
    }
    cin>>w;

    fractionalKnapsack(v,n,w);



    return 0;
}
