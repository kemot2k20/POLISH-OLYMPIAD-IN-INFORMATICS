const int K = 19;
const int N = 2e5 + 5;
const int MX = N * K;

int t[MX][2];
int sz = 1;

void init() {
    sz = 1;
    for (int i = 0; i < MX; i ++)
        for (int j = 0; j < 2; j ++) 
            t[i][j] = -1;
}

void add(int x) {
    int v = 0;
    for (int bit = K - 1; bit >= 0; bit --) {
        int b = (x >> bit) & 1;
        if (t[v][b] == -1) {
            t[v][b] = sz ++;
        }
        v = t[v][b];
    }
}

int maxi(int x) {
    int v = 0, res = 0;
    for (int bit = K - 1; bit >= 0; bit --) {
        int b = (x >> bit) & 1;
        if (t[v][b^1] != -1) {
            res += (1 << bit);
            b ^= 1;
        }
        v = t[v][b];
    }
    return res;
}




vector<array<int, 2>> t({{-1, -1}});
  auto add = [&](int x) {
    int v = 0;
    for (int i = LOG - 1; i >= 0; --i) {
      int j = (x >> i) & 1;
      if (t[v][j] == -1) {
        t[v][j] = t.size();
        t.push_back({-1, -1});
      }
      v = t[v][j];
    }
  };  
  for (int x : a) add(x);
  auto get = [&](int x) {
    int v = 0;
    for (int i = LOG - 1; i >= 0; --i) {
      int j = (x >> i) & 1;
      if (t[v][j ^ 1] != -1) j ^= 1;
      x ^= j << i;
      v = t[v][j];
    }
    return x;
  };
