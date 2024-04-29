#include<iostream>
#include<vector>
using namespace std;
int f(string s, string t, vector<vector<int>>& dp, int i, int j) {
    if(i<0 || j<0)
{
    return  0 ;
}   
if(dp[i][j]!=-1){
    return dp[i][j];
}

  if(s[i]==t[j]){
        return dp[i][j]= 1+f(s,t,dp,i-1,j-1);
     }
     else{
        return dp[i][j]=0+max(f(s,t,dp,i,j-1),f(s,t,dp,i-1,j));
     }
}



int main() {
    string s = "abcd";
    string t = "bc";
    int n = s.size();
    int m = t.size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    int ans = f(s, t, dp, n-1, m-1);
cout<<ans;
   int len  =ans ;
    vector<char> a(len);

     
     for(int i=0;i<len;i++){
        a[i]='&';

     }
    int index= len -1;

    int i = n -1; 
    int j = m -1;

     while(i>=0 && j>=0){
        if(s[i]==t[j]){
           a[index]=s[i-1];
           index --;
           
           i--;
           j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
           i --; 
        }
        else{
          j-- ;
        }
     }
     for(int i=0;i<len;i++){
        cout<<a[i]<<" ";

     }

    return 0;
}
