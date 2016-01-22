#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool is_vowel(char c){
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool has_vowel(string &s){
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(is_vowel(s[i])) return true;
	}
	return false;
}

bool has_2_consecutive_letter(string &s){
	int n = s.length();
	for(int i = 1; i < n; i++){
		if(s[i]==s[i-1] && s[i]!='e' && s[i]!='o') return false;
	}
	return true;
}

bool check_3(string &s){
	int state = 0;
	int n = s.length();
	for(int i = 0; i < n; i++){
		bool vowel = is_vowel(s[i]);
		switch(state){
		case 0:
			if(vowel) state = 1;
			else state = 3;
			break;
		case 1:
			if(vowel) state = 2;
			else state = 3;
			break;
		case 2:
			if(vowel) return false;
			else state = 3;
			break;
		case 3:
			if(vowel) state = 1;
			else state = 4;
			break;
		case 4:
			if(vowel) state = 1;
			else return false;
			break;
		default:
			break;
		}
	}
	return true;
}

bool anylise(string &s){
	if(!has_vowel(s)) return false;
	if(!has_2_consecutive_letter(s)) return false;
	if(!check_3(s)) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	string s;
	while(cin >> s){
		if(s=="end") break;
		if(anylise(s)){
			printf("<%s> is acceptable.\n", s.c_str());
		}
		else{
			printf("<%s> is not acceptable.\n", s.c_str());
		}
	}
	return 0;
}
