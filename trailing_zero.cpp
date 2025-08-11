#include<iostream>
using namespace std;

int helper(int x){
    int count = 0;
    while(x>0){
    count+=x/5;
    x=x/5;
    }
    return count;
}


int trailing(int n){
    int low=1,high=n*5,mid;
    int ans=-1,zero;
    while(low<=high){
        mid=(low+high)/2;
        zero = helper(mid);
        if(zero>=n){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}


int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int result = trailing(n);
    cout<<"Smallest no is :"<<result<<endl;
    return 0;
}