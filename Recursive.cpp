#include <bits/stdc++.h>
using namespace std;

//(Recursive)

//gcd
int gcdRec(int a, int b){
    if(b==0) return a;
    return gcdRec(b, a%b);
}

//reverse num

int rev(int sum,int n){
    if(n==0) {
        sum/=10;
        return sum;
    }
    sum += (n%10); 
    return rev(sum*10,n/10);
}

// check palindrome

bool isPalindrome(string s, int i, int j){
    
    if(i<j){
        if(s[i]==s[j]) return isPalindrome(s,i+1,j-1);
        else return false;
    }
    return true;
}

//check prime
bool isPrime(int a){
    if(a < 2) return false;
    for(int i=2; i<=sqrt(a); i++){
        if(a%i==0) return false;
    }
    return true;
}

// sum of palindromic nums within range a-b

int sum_pal(int a, int b){
    if(a>b) return 0;
    else {
        if(isPalindrome(to_string(a),0,to_string(a).size()-1)){
            cout<<a<<" ";
            return a + sum_pal(a+1,b);
        }
        else {
            return sum_pal(a+1,b); 
        }
    }
}



// (Divede and Conquere)

// sum of good numbers-> divisible by 11

int goodNum(int ara[],int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        int leftSm = goodNum(ara,l,mid);
        int rightSm = goodNum(ara,mid+1,r);
        return leftSm+rightSm;
    }
    else {
        if(ara[l]%11==0){
            cout<<ara[l]<<" ";
            return ara[l];
        }
        else return 0;
    }
}

/*
 ******************Merge Sort***************
*/


int main()
{

    // cout<<gcdRec(1234,282)<<endl;
    // cout<<__gcd(1234,282);

    int ara[] = {11,0,1,5,22};

    // cout<<"good values : ";
    // int sum = goodNum(ara,0,sizeof(ara)/sizeof(ara[0]));
    // cout<<"sum : "<<sum<<endl;

    // string s="ashik";
    // cout<<isPalindrome(s,0,s.size()-1)<<endl;

    //assignment-1
    int sum = sum_pal(100, 200);
    cout<<"\nsum = "<<sum<<endl;
    
    return 0;
}
