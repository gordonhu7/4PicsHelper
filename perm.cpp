#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "DictionaryTrie.h"
#include "DictionaryTrie.cpp"
#include "DictionaryHashtable.h"
#include "DictionaryHashtable.cpp"
#include "util.h"
#include "util.cpp"
#include <map>

using namespace std;

void allNLength(char arr[], string prefix, int length, int n,vector<string> &vec,DictionaryHashtable t){
	if(n == 0){
		cout << prefix << endl;
		if(t.find(prefix)){
			cout << prefix << endl;
			vec.push_back(prefix);
		}
		return;
	}

	for(int i =0; i < length; i++){
		string nPrefix = prefix + arr[i];
		allNLength(arr,nPrefix,length,n-1,vec,t);
	}

}

int main(int argc,char** argv){

	//this puts the dictioanry in a trie tree
	DictionaryTrie dict;
	ifstream ifs(argv[1]);
	Utils::load_dict(dict,ifs);
	ifs.close();
	
	//smh at the find in the trie
	DictionaryHashtable hashT;
	ifstream if2(argv[1]);
	Utils::load_dict(hashT,if2);
	if2.close();

	if(argc != 2){
		cout << "Ha nice try!" << endl;
		return -1;
	} 

	//user inserts some sort of string and now convert to char array	
	string str;
	cout << "Enter a list of characters: " << endl;
	cin >> str;
	int numSlots;
	cout << "Enter the number of slots: " << endl; 
   	cin >> numSlots;
 
	//is there a library function to convert a string to char array?
	int len = str.length();
	char arr[len] = {0};
	for(int i =0;i< len;i++){
		arr[i] = str.at(i);
	}	

	//vector to store all combos
	vector<string> vec;
	cout << "Might take a bit..."<<endl;	
	allNLength(arr,"", len, numSlots,vec,hashT);	
	
	//map that stores strings to ints in increasing order
	map<int,string,std::greater<int>> m1;

	for(int j =0;j<vec.size();j++){
		m1.insert(std::pair<int,string>(dict.FIND(vec.at(j)),vec.at(j)));
	}

	char userI = 'n';
	//test by printing out the elements	
	std::map<int,string>::iterator it = m1.begin();
	while(it != m1.end() && userI == 'n'){
		cout << "Press n for the next possible word" << endl;
		cout << it->first << "  " << it->second << endl;
		cin >> userI;
		it++;
	}

	cout<<"Mjork!"<<endl;
}
