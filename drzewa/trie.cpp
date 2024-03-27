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
