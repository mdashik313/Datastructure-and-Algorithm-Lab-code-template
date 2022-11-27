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

    int profit=0, k_left=w;
    int itr = 0;
    while(itr < n && k_left>0){
        if(k_left >= v[itr].first){
            profit += v[itr].second;
            k_left -= v[itr].first;
        }
        else {
            profit += k_left * ((double)v[itr].second/v[itr].first);
            k_left = 0;
        }
        
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