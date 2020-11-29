#include<bits/stdc++.h>
#include<iostream>
#include "iect.h"

using namespace std;

int main() {

	string P="";

	vector<pair<string, vector<set<int> > > > soi;
	soi.push_back({"a", { {1, 2, 3, 4, 5, 6}, {7}, {9} } });
	soi.push_back({"b", { {2, 3, 4, 6}, {7, 8}, {} } }); 
	soi.push_back({"e", { {3, 4}, {8}, {} } });
	soi.push_back({"f", { {1, 2, 4, 5, 6}, {8}, {9} } });
	soi.push_back({"g", { {1, 2, 3, 4, 5}, {7, 8}, {} } });

	double minsup=4.0;
	double minR=0.4;

	vector<string> CP;

	//sorting data for initial stack of items
	sort(soi.begin(), soi.end(), [](auto &left, auto &right) {
		return ((left.second)[0]).size() > ((right.second)[0]).size();
	});

	IECT(P, soi, minsup, minR, CP);

	for(int i=0; i<CP.size(); i++){
		cout<<CP[i]<<" ";
	}

	cout<<endl;
	return 0;

}
