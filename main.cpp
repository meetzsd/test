#include <iostream>
#include <vector>
using namespace std;
int r[50][50];
int f=1;
int row,col;
int countWays(vector<vector<int> > map, int x, int y) {
  int i,j;
  int min;
  int res;
  int res1;
  if(map[0][0]==0)
    return 0;
  if(f==1) {
    row=x;
    col=y;
    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++) {
        r[i][j] = -1;
      }
    r[0][0] = 1;
    for(i=1;i<x;i++) {
        r[i][0] = 1;
    }
    for(i=1;i<y;i++) {
        r[0][i] = 1;
        r[0][i] = 1;
    }
    min=-1;
    for(i=0;i<x;i++) {
      if(map[i][y-1] != 1){
        min = i;
      }
    }
    for(i=x-min-1;i<x;i++){
      r[i][0] = 0;
    }
    //cout<<r[0][1]<<" "<<r[1][0]<<endl;
    min=-1;
    for(i=0;i<y;i++) {
      if(map[x-1][i] != 1){
        min = i;
      }
    }
    for(i=y-min-1;i<y;i++){
      r[0][i] = 0;
    }
   // cout<<r[0][1]<<" "<<r[1][0]<<endl;
    f=0;
  }
  if(r[x-1][y-1]>=0) {
    return r[x - 1][y - 1];
  }
    res= ((map[row-(x-1)][col-y]==1)?(countWays(map,x-1,y)):0)%1000000007;
    res1 =(res+((map[row-x][col-(y-1)]==1)?(countWays(map,x,y-1)):0))%1000000007;

    r[x-1][y-1] = res1;
  return res1;

}
int main() {
  int x,y;
  int i,j,m;
  int res;
  cin>>x>>y;
  vector<vector<int>> map;
  vector<int> map1;
  for(i=0;i<x;i++){
    map1.clear();
    for(j=0;j<y;j++){
      cin>>m;
      map1.push_back(m);
    }
    map.push_back(map1);
  }
  res= countWays(map, x, y);
  cout<<res;
  return 0;
}