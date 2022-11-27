#include <bits/stdc++.h>
using namespace std;

struct job{
    int start,duration,lim,serial;
};

bool cmp(struct job a, struct job b){
    return a.start+a.duration < b.start+b.duration;
}

void knapSack(vector<job> &v, int st, int end, int salary){
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++){
        cout<<"j-"<<v[i].serial<<" "<<v[i].start<<" "<<v[i].duration<<"-->"<<v[i].start+v[i].duration<<endl;
    } 
    for(int i=0; i<v.size(); i++){
        
    } 
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector<job>v;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        struct job j;
        cin>>j.start>>j.duration>>j.lim;
        j.serial = i+1;
        v.push_back(j);
    }  

    int salary,x,y;
    cin>>salary>>x>>y;

    knapSack(v,x,y,salary);

    
    return 0;
}