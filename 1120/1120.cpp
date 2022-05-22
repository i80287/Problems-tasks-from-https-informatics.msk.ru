#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,x,sum=0;
	vector <int> otw(0);
	cin>>n>>x;
	int il = x;
	vector <int> a(n);
	vector <int> prov(x+1,0);
	vector <int> prev(x+1,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<x){
	    cout<<"NO";
    }else{
    	prov[0]=1;
        for(int i=0;i<n;i++){
    	    for(int j=x;j>=a[i];j--){
			    if(prov[j-a[i]]==1){
        			prov[j]=1;
    				prev[j]=a[i];
    			}
    		}
    	}
    	
	    while(prev[il]==0){
	    	il--;
	    }
	    while(il>0){
	    	otw.push_back(prev[il]);
	    	il-=prev[il];
	    }
	    sum=0;
	    for(int i=0;i<otw.size();i++){
	       sum+=otw[i];
	    }
	    if(sum==x) cout<<"YES";
	    if(sum!=x) cout<<"NO";
	}
}