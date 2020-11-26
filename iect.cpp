#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include "cr1.h"
#include "cr2.h"
#include "intersection.h"
using namespace std;

//inputs: Prefix P, Stack SOI, minimum support minsup, minimum ratio minR
void IECT(string P, stack<pair<string, vector<set<int> > > >& soi, double minsup, double minR, vector<string>& CP){
	while(!soi.empty()) {

		pair<string, vector<set<int> > > tos;
		tos=soi.top();
		soi.pop();

		stack<pair<string, vector<set<int> > > > suffix;

		if((criteriaRatioOne(tos.first, tos.second) <= minR) && criteriaRatioTwo(tos.first, tos.second)){
			P+=tos.first; //????
			CP.push_back(P);

		}

		vector<set<int> > current=tos.second; //tos transaction
		 //i2;

		int N=current.size(); //N+1

		while(!soi.empty()){ 


			set<int> vip;
			pair<string, vector<set<int> > > i2=soi.top();
			soi.pop();  // ??? do i need to pop or just traverse the stack
			vector<set<int> > t2=i2.second;

			auto it= set_intersection(current[0].begin(), current[0].end(), t2[0].begin(), t2[0].end(), inserter(vip, vip.begin()));

			if(vip.size() >= minsup) {

				std::vector<set<int> > v;

				v.push_back(vip);

				for(int i=1; i<N; i++){
					set<int> temp;
					auto it=set_intersection(current[i].begin(), current[i].end(), t2[i].begin(), t2[i].end(), inserter(temp, temp.begin()));
					v.push_back(temp);
				}

				suffix.push(make_pair(i2.first, v));

			}


		}

		P+=tos.first; //????
		
		IECT(P, suffix, minsup, minR, CP);


	}
}

int main() {

	string P="";
	stack<pair<string, vector<set<int> > > > soi;
	soi.push({"a", { {1, 2, 3, 4, 5, 6}, {7}, {9} } });
	//soi.push({"f", { {1, 2, 4, 5, 6}, {8}, {9} } });
	//soi.push({"g", { {1, 2, 3, 4, 5}, {7, 8}, {} } });
	soi.push({"b", { {2, 3, 4, 6}, {7, 8}, {} } }); 
	double minsup=4.0;
	double minR=0.4;
	vector<string> CP;

	IECT(P, soi, minsup, minR, CP);

	for(int i=0; i<CP.size(); i++){
		cout<<CP[i];
	}
	return 0;
}

