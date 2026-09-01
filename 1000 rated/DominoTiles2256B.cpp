#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int ans =0;
	    vector<string> pat = {"0011","0110","1100","1001"};
	    for(auto it:pat){
	        bool flag = true;
	        for(int i=0;i<n;i++){
	            if(s[i]!='?' && s[i]!=it[i%4]){
	                flag =false;
	                break;
	            }
	        }
	        if(flag) ans++;
	    }
	    cout<<ans<<endl;
	}

}
