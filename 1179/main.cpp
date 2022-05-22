#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int d, x, y;
    cin >> d >> x >> y;
    if((y + x == d && x >=0 && x <= d && y >=0 && y <= d) || (y == 0 && x >=0 && x <= d) || (x == 0 && y >=0 && y <= d)){
        cout << 0;
    }else if( x >= 1 && x <= d - 1 && y >= 1 && y <= d - 1 && x + y < d){
      cout << 0;
    }else{
      int a, b, c;
      c = x * x + (y - d) * (y - d);
      a = x * x + y * y;
      b = y * y + (x - d) * (x - d);
      if(a <= b){
        if(a <= c){
          cout << 1;
        }else{
          cout << 3;
        }
      }else{
        if(b <= c){
          cout << 2;
        }else{
          cout << 3;
        }
      }
    }
}