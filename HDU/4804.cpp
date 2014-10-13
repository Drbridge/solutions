#include<cstdio>
#include<cstring>

const int MOD = 1000000007;
int h, w, upp, low;
short a[101];
long long b[2][1<<10][22];

int main() {
  while(~scanf("%d%d%d%d", &h, &w, &low, &upp)) {
    bool s = 0, t = 1;
    int res = 0;
    memset(a, 0, sizeof(a));
    a[0] = (1 << w)-1;
    for(int i = 1; i <= h; i++) {
      scanf("%*c");
      for(int j = 0; j < w; j++) {
        char t0;
        scanf("%c", &t0);
        a[i] |= (t0=='1')<<j;
      }
    }
    memset(b[s], 0, sizeof(b[0]));
    b[s][(1 << w) - 1][0] = 1;
    for(int i = 1; i <= h; i++)
      for(int j = 0; j < w; j++, s^=1, t^=1) {
        memset(b[t], 0, sizeof(b[t]));
        int t0 = a[i-1]>>j | (a[i] & ((1 << j) - 1))<<(w - j);
        for(int x = t0; ; x = x-1&t0) {
          for(int y = 0; y <= upp; y++)
            if(b[s][x][y]) {
              b[s][x][y] %= MOD;
              if((x&1) == (a[i-1]>>j & 1)) {
                b[t][x>>1][y] += b[s][x][y];
                b[t][x>>1 | 1<<(w-1)][y+1] += b[s][x][y];
                if(j && !(x & 1<<(w-1)))
                  b[t][x>>1 | 3<<(w-2)][y] += b[s][x][y];
              }
              if(!(x&1) && (a[i-1]>>j & 1))
                b[t][x>>1 | 1<<(w-1)][y] += b[s][x][y];
            }
          if(!x)
            break;
        }
      }
    for(int y = low; y <= upp; y++) {
      b[s][a[h]][y] %= MOD;
      res += b[s][a[h]][y];
      res %= MOD;
    }
    printf("%d\n", res);
  }
  return 0;
}
