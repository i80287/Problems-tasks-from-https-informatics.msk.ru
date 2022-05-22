#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cn01 = 0, cn10 = 0, cn00 = 0, cn11 = 0;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 1 && b == 0){
            cn10++;
        }else if(a == 0 && b == 1){
            cn01++;
        }else if(a == 1 && b == 1){
            cn11++;
        }else{
            cn00++;
        }
    }
    if(cn10 == cn01){
        if(cn10 > 0){
            if((cn01 + cn00) % 2 == 0){
                cout<<"YES";
            }else{
                cout<<"NO";
            }
        }else{
            if(cn00 == 0){
                cout<<"YES";
            }else if(cn11 == 0){
                cout<<"YES";
            }else{
                cout<<"NO";
            }
        }
    }else{
        cout<<"NO";
    }
}