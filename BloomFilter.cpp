#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class BloomFilter{
    
    bool bitarray[100];
    int arrSize;
    
    public:
    
BloomFilter(){
    
    bitarray[100] = { false };
	arrSize = 100;
}
    
    
int hashfunction1(string s)
    {
        
	int hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		hash = hash*i + 32 + s[i];
		hash = hash % arrSize;
	}
	return hash;
    }

int hashfunction2(string s)
    {
        
	int hash = 30;
	for (int i = 0; i < s.size(); i++) {
	    
		hash = hash*20+hash*pow(10,i) + s[i];
		hash = hash % arrSize;
	}
	return hash;
    }

int hashfunction3(string s)
    {
        
	int hash = 1;
	for (int i = 0; i < s.size(); i++)
	{
		hash = hash + pow(19, i) * s[i];
		hash = hash % arrSize;
	}
	return hash % arrSize;
    }


int hashfunction4(string s)
    {
        
	int hash = 7;
	for (int i = 0; i < s.size(); i++)
	{
		hash = (hash * 31 + s[i]) % arrSize;
	}
	return hash;
    }



    
bool lookup( string s)
{
	int a = hashfunction1(s);
	int b = hashfunction2(s);
	int c = hashfunction3(s);
	int d = hashfunction4(s);

	if (bitarray[a] && bitarray[b] && bitarray
		&& bitarray[d])
		return true;
	else
		return false;
}


void insert( string s)
{

	if (lookup(s))
		cout << s << " is Probably already present" << endl;
	else
	{
	int a = hashfunction1(s);
	int b = hashfunction2(s);
	int c = hashfunction3(s);
	int d = hashfunction4(s);

		bitarray[a] = true;
		bitarray[b] = true;
		bitarray[c] = true;
		bitarray[d] = true;

		cout << s << " inserted" << endl;
	}
}


    
};

int main()
{
	
	string testarray[33]
		= {  "abound",   "abounds",       "abundance",
            "abundant", "accessible",    "bloom",
            "blossom",  "bolster",       "bonny",
            "bonus",    "bonuses",       "coherent",
            "cohesive", "colorful",      "comely",
            "comfort",  "gems",          "generosity",
            "generous", "generously",    "genial",
            "bluff",    "cheater",       "hate",
            "war",      "humanity",      "racism",
            "hurt",     "nuke",          "gloomy",
            "facebook", "c++", "twitter" };
			
	BloomFilter b;
    
	for (int i = 0; i < 33; i++) {
		b.insert(testarray[i]);
	}
	return 0;
}
