#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include "cr1.h"
#include "cr2.h"
using namespace std;

//inputs: Prefix P, Stack SOI, minimum support minsup, minimum ratio minR
void IECT(string P, vector<pair<string, vector<set<int> > > >& soi, double minsup, double minR, vector<string>& CP){

	while(soi.size() > 0) {

		pair<string, vector<set<int> > > tos;
		tos=soi.back();
		soi.pop_back();

		vector<pair<string, vector<set<int> > > > suffix;

		string X= P+tos.first;

		if((criteriaRatioOne(tos.first, tos.second) <= minR) && criteriaRatioTwo(tos.first, tos.second)){
			//P=X; //????
			CP.push_back(X);

		}

		vector<set<int> > current=tos.second; //tos transaction
		 //i2;

		int N=current.size(); //N+1

		for(auto it=soi.rbegin(); it!=soi.rend(); it++){ 

			set<int> vip;
			pair<string, vector<set<int> > > i2=*it;
			//soi.pop();  // ??? do i need to pop or just traverse the stack
			vector<set<int> > t2=i2.second;

			auto itr= set_intersection(current[0].begin(), current[0].end(), t2[0].begin(), t2[0].end(), inserter(vip, vip.begin()));

			// auto itr= set_intersection(current[0].begin(), current[0].end(), t2[0].begin(), t2[0].end(), front_inserter(vip));

			if(vip.size() >= minsup) {

				std::vector<set<int> > v;

				v.push_back(vip);

				for(int i=1; i<N; i++){
					set<int> temp;
					auto itr=set_intersection(current[i].begin(), current[i].end(), t2[i].begin(), t2[i].end(), inserter(temp, temp.begin()));

					// auto itr=set_intersection(current[i].begin(), current[i].end(), t2[i].begin(), t2[i].end(), front_inserter(temp));
					v.push_back(temp);
				}

				suffix.push_back(make_pair(i2.first, v));

			}


		}

		 //????
		
		IECT(X, suffix, minsup, minR, CP);


	}
}



