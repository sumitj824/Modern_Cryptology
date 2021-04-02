
#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	vector<string> text;
	while(getline(cin,s))
	{
		for(int i = 0;i < s.size();i++){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] = s[i] - 'A' + 'a';
			}
		}
		text.push_back(s);

	}
	cout << "Cipher text : \n";

	for(auto s:text) cout << s << endl;
	map <char,char> m;
	for(int i = 0;i < 26;i++){
		m['a' + i] = '_';
	}
	cout << "\n";
	cout << "-------**********-------\n\n";
	
	m['m'] = 't';
	m['e'] = 'h';
	m['y'] = 'e';
	m['a'] = 's';
	m['w'] = 'i';
    m['p'] = 'a';
    m['i'] = 'c';
    m['b'] = 'v';
    m['h'] = 'n';
    m['s'] = 'r';
    m['t'] = 'f';
    m['j'] = 'm';
    m['o'] = 'b';
    m['g'] = 'o';
    m['k'] = 'l';
    m['v'] = 'w';
    m['r'] = 'g';
    m['f'] = 'p';
    m['n'] = 'u';
    m['u'] = 'd';
    m['x'] = 'y';
    m['d'] = 'q';
     
	

	
	cout << "Plain text : \n"; 
	for(auto s:text)
	{	string ne;
		for(int i = 0;i < s.size();i++){
			if(s[i] >= 'a' && s[i] <= 'z')
			ne += m[s[i]];
			else ne += s[i];
		}
		cout<<ne<<endl;
	}
	
	return 0;
}