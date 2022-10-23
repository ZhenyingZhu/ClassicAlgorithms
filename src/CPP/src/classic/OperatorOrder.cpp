#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  map<int, int> m;
  m[1] = 2;

  int tmp = max(m.rbegin()->second, 1);
  printf("tmp %d\n", tmp); // print 2

  m[2] = max(m.rbegin()->second, 1);
  // interesting thing happen here is that
  // 1. m[2] = 0
  // 2. tmp = m.rbegin()->second is 0
  // 3. max(tmp, 1) return 1
  printf("m[2] = %d\n", m[2]); // print 1
  
  return 0;
}

