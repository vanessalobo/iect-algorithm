#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool criteriaRatioTwo(string p, vector<set<int> > v, int N) {
	double S_P=0;
	for(int i=1; i<=N; i++){
		S_P += v[i].size();
	}
	double mean=(double)S_P/N;

	double SD_square = 0.0;
	double SD_cube = 0.0;
	for(int i=1; i<=N; i++){
		SD_square += (v[i].size() - mean) * (v[i].size()-mean);
		if(i==N) continue;
		SD_cube += (v[i].size() - mean) * (v[i].size()-mean) *(v[i].size() - mean);

	}

	double SD= (double)sqrt(SD_square)/N;
	double cr2 = (double) SD_cube/(SD*SD*SD*(N-1));
	int flag=1; //to check if P is not in any of the vip groups
	for(int i=1; i<=N; i++){
		if(v[i].size()!=0){
			flag=0;
			break;
		}
	}

	if(flag || (cr2<0)) return true;
	else return false;

}

int main(){


	unordered_map<string, vector<set<int> > > m;
	m["a"]={
		{1, 2, 3, 4, 5},
		{7, 8},
		{}
	};

	int N=2;
	for(auto itr=m.begin(); itr != m.end(); itr++){
		cout<<criteriaRatioTwo(itr->first, itr->second, N);
	}
	

	cout<<endl;
	
	return 0;
}