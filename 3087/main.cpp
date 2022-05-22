#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n,x,prov=1;
    cin>>n;	
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    vector <int> dp(x+1,1000003);
    dp[0]=0;
    
    for(int i=1;i<x+1;i++){
        for(int j=0;j<n;j++){
            int Elam = a[j];
            if(i-Elam>=0 && dp[i]>dp[i-Elam]){
				dp[i]=dp[i-Elam];
        	}
		}
		if(dp[i]!=1000003) dp[i]++;
    }
    if(dp[x]==1000003){
		cout<<"No solution";
	}else{
		vector <int> din(0);
		int i=x;
		while(i!=0){
			for(int j=0;j<n;j++){
				int Elam=a[j];
				if(i-Elam>=0 && dp[i]==dp[i-a[j]]+1){
					din.push_back(a[j]);
					i-=a[j];
				}
			}
		}
		for(int i=0;i<din.size();i++){
			cout<<din[i]<<" ";
		}
	}
}