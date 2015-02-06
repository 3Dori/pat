#include <cstdio>
#include <iostream>
#include <vector>

#define P(x) (cout << #x " is " << x;)

using namespace std;

struct Player{
  int atime;
  int ptime;
  bool isvip;
};

struct Table{
  bool isvip;
  int etime;
  int count;
};

vector<Table&> tables;
vector<Player&> players;

long time2sec(int hr, int min, int sec){
  return hr * 3600 + min * 60 + sec;
}

int main(){
  int N;
  int hr, min, sec, ptime, isvip;
  long atime;
  cin >> N;
  for (int i = 0; i < N; i++){
    scanf("%02d:%02d:%02d %d %d", &hr, &min, &sec, &ptime, &isvip);
    atime = time2sec(hr, min, sec);
    ptime *= 60;
    players.push_back(new Player{atime, ptime, bool(isvip)});
  }
  return 0;
}
