#include <iostream>
using namespace std;
void f(int ost, int step, int &res){
    if(step <= 4){
        if(ost > 0){
            for(int i = 1; i <= 10; ++i){
                f(ost - i*i, step + 1, res);
            }
        }else if(ost == 0){
            res = min(res, step);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int res = n;
    f(n, 0, res);
    cout << res;
}