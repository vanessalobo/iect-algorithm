#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

double criteriaRatioOne(string p, vector<set<int> > v){
	double cr1=0;
	double sumV=0, S_P=0;
	int N= v.size()-1; //number of non vip sets
	sumV=v[0].size();
	for(int i=1; i<=N; i++){
		S_P += v[i].size();
	}

	cr1=(double) S_P/sumV;

	return cr1;
}

int main(){


	unordered_map<string, vector<set<int> > > m;
	m["a"]={
		{2, 3, 4, 6},
		{7, 8},
		{}
	};



	for(auto itr=m.begin(); itr != m.end(); itr++){
		int x=(itr->second).size();
		cout<<" ";
		cout<<criteriaRatioOne(itr->first, itr->second);
	}
	

	cout<<endl;
	
	return 0;
}
