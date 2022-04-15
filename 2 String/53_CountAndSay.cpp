#include <bits/stdc++.h>

using namespace std;

/*

"3322251"
two 3's, three 2's, one 5, and one 1
23 + 32 + 15 +1 1
"23321511"

*/
string countAndSay(int n){
	if(n==1) return "1";
	if(n==2) return "11";
	
	string s="11";
	
	for(int i=3; i<=n; i++){
		string t="";
		s=s+'&';
		int c=1;
		for(int j=1; j<s.length(); j++){
			if(s[j] != s[j-1] ){
				t=t+to_string(c);
				t=t+s[j-1];
				c=1;
			}
			else c++;
		}
		s=t; 
	}
	return s;

}


int main(){
    int n;
    cin>>n;
    
    cout<<countAndSay(3322251);

    return 0;
}