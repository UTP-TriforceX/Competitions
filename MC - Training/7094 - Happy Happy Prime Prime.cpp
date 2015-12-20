#include <bits/stdc++.h>
#define N 1e5 + 5
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

vector <bool> primes(N, true);

int to_int(string s) {
  int ans;
  stringstream ss;
  ss << s;
  ss >> ans;
  return ans;
}

string to_string(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

void sieve(){
  primes[0] = primes [1] = false;
  for (int i = 4; i < primes.size(); i += 2) {
    primes[i] = false;
  }

  for (int i = 3; i <= sqrt(N); ++i) {
    if (primes[i]){
      for (int j = i; j*i <= N; ++j) {
        primes[i*j] = false;
      }
    }
  }
}

bool is_happy(string x) {
  set <int> conj;
  int aux = 0;
  string st = x;
  while (aux != 1){
    aux = 0;
    for (int i = 0; i < st.size(); ++i) {
      aux += ((st[i] - '0')*(st[i] - '0'));
    }
    if(conj.count(aux))
      return false;
      conj.insert(aux);
    st = to_string(aux);
  }
  return true;
}
int main() {
  fast;
  sieve();
  int n, k;
  string num;
  cin >> n;
  while(n--) {
    cin >> k >> num;
    cout << k << " " << num << " ";
    if(primes[to_int(num)]) {
      (is_happy(num)) ? cout << "YES" << endl : cout << "NO" << endl;
    }else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
