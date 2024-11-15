#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
#define LF '\n'
#define fi first
#define se second
#define pb push_back

int n,m;
vector<int> Available;
vector<vector<int>> Max,Allocation;
vector<bool> Finish;
void init_one_dimension(int n,vector<int> & a){
  for(int i = 0;i < n;i++)
    cin >> a[i];
}
void init_two_dimension(int n,int m,vector<vector<int>> & a){
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
      cin >> a[i][j];
}

bool is_enough(int i){
  for(int j = 0;j < n;j++)
    if(Available[j] < Max[i][j]-Allocation[i][j])
      return false;
  return true;
}
bool dfs(string& res_str){
  for(int i = 0;i < m;i++){
    if(!Finish[i] && is_enough(i)){
        vector<int> backup = Available;
        Finish[i] = true;
        res_str += to_string(i);
        for(int j = 0;j < n;j++){
          Available[j] += Allocation[i][j];
        }

        if(dfs(res_str))return true;

        Available = backup;
        res_str.erase(res_str.size() - 1,res_str.size() - 1);
        Finish[i] = false;
    }
  }
  for(bool it : Finish)
    if(!it)
      return false;
  return true;
}
void solve() {
  cin >> n >> m;
  Available.resize(n);
  Finish.resize(m,false);
  Max.resize(m,vector<int>(n));
  Allocation.resize(m,vector<int>(n));
  init_one_dimension(n,Available);
  init_two_dimension(m,n,Max);
  init_two_dimension(m,n,Allocation);

  string res_str = "";
  
  if(dfs(res_str)){
    for(int i = 0;i < res_str.size();i++)
      if(i != res_str.size() - 1)
        cout << res_str[i] << ",";
      else
        cout << res_str[i];
  }
  else{
    cout << "处于不安全状态" << LF;
  }
}


int main(){

  ios::sync_with_stdio(0), cin.tie(0);

  int tt = 1;
  //cin >> tt;

  while (tt--) {
    solve();
  }

  return 0;
}