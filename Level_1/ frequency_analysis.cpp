#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	vector<string> text;
	int total = 0;
	vector <pair <int,char>> freq(26);
	for(int i = 0;i < 26;i++){
		freq[i].first = 0;
		freq[i].second = 'a' + i;
	}
	while(getline(cin,s))
	{
		for(int i = 0;i < s.size();i++){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] = s[i] - 'A' + 'a';
			}
		}
		for(int i = 0;i < s.size();i++){
			if(s[i] >= 'a' && s[i] <= 'z'){
				freq[s[i] - 'a'].first++;
				total++;
			}
		}
		text.push_back(s);

	}
	
	sort(freq.rbegin(),freq.rend());
	cout << "character		frequency" << endl;
	for(int i= 0;i < 26;i++){
		double per = freq[i].first;
		per /= total;
		per *= 100;
		cout << "   " << freq[i].second <<"		    	" << per << endl;
	}
	return 0;
}