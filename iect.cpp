#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include "cr1.h"
#include "cr2.h"
#include "intersection.h"
using namespace std;

//inputs: Prefix P, Stack SOI, minimum support minsup, minimum ratio minR
void IECT(string P, stack<pair<string, vector<set<int> > > > soi, double minsup, double minR, vector<string> CP){
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
		pair<string, vector<set<int> > > i2;

		int N=current.size(); //N+1

		while(!soi.empty()){ 

			i2=soi.top();
			soi.pop();  // ??? do i need to pop or just traverse the stack
			vector<set<int> > t2=i2.second;
			set<int> vip;

			auto it= set_intersection(current[0].begin(), current[0].end(), t2[0].begin(), t2[0].end(), back_inserter(vip));

			if(vip.size() >= minsup) {

				std::vector<set<int> > v;

				v.push_back(vip);

				for(int i=1; i<N; i++){
					set<int> temp;
					auto it=set_intersection(current[i].begin(), current[i].end(), t2[i].begin(), t2[i].end(), back_inserter(temp));
					v.push_back(temp);
				}

				suffix.push(make_pair(i2.first, v));

			}


		}

		P+=tos.first; //????
		
		IECT(P, suffix, minsup, minR, CP);


	}
}

