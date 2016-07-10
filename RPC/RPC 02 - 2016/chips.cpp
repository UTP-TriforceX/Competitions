#include <bits/stdc++.h>
#define D(x) cout << #x "=" << x << endl
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, b, t;
  while (cin >> n >> b >> t) {
    int bill = 0, ted = 0,  t_ted = 0 , t_bill = 0;
    while (n > 0) {
      if (bill == 0 and ted == 0) {
        if (n > 0) {
          bill += min(b, n);
          n -= min(b, n);
        }

        if (n > 0) {
          ted += min(t, n);
          n -= min(t, n);
        }
      } else if(bill == 0 and n > 0) {
        bill += min(b, n);
        n -= min(b, n);
        t_ted++;
        ted--;
      } else if (ted == 0 and n > 0) {
        ted += min(t, n);
        n -= min(t,n);
        t_bill++;
        bill--;
      }

      if (ted < bill) {
        t_ted += ted;
        t_bill += ted;
        bill -= ted;
        ted = 0;
      } else {
        t_ted += bill;
        t_bill += bill;
        ted -= bill;
        bill = 0;
      }
    }
    cout << t_bill+bill << " " << t_ted+ted << endl;
  }
  return 0;
}
