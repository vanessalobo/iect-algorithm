#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void create_stack_of_items(vector<pair<string, vector<set<int> > > >& soi)
{
	//vector<pair<string, vector<set<int> > > > soi;

	string STOCKGRP="data/stock-group-edit.csv";
	string STOCKTXN="data/stock-txn-unix.csv";

	// ifstream sgrp(STOCKGRP, ios::in);
	// ifstream stxn(STOCKTXN, ios::in);

	ifstream sgrp(STOCKGRP);
	ifstream stxn(STOCKTXN);

	if(!sgrp.is_open() || !stxn.is_open()){
		cout<<"ERROR! Failed to open"<<endl;
		exit(0);
	}

	string linetxn, linegrp;

	
	while(getline(stxn, linetxn) && getline(sgrp, linegrp)){

		vector<int> clustgroup;

		stringstream sstxn(linetxn);
		stringstream ssgrp(linegrp);

		string groupno;
		char delim=',';

		//filling all the number of each group into vector groups
		while(!ssgrp.eof()){
			getline(ssgrp, groupno, delim);
			clustgroup.push_back(stoi(groupno));
			groupno.clear();
		}

		
		string stockno, txno;
		pair<string, vector<set<int> > > item;
		int index=0;

		//filling in stock code number
		getline(sstxn, stockno, delim);
		item.first=stockno;
		stockno.clear();

		//filling in the vip and non-vip groups
		vector<set<int> > dbs;

		for(int i=0; i<clustgroup.size(); i++){

			set<int> group;
			int c=0;
			if(clustgroup[i]==0)
			{
				dbs.push_back(group);
				continue;
			}
			// for(int j=0; j<clustgroup[i]; j++){

			// 	getline(sstxn, txno, delim);
			// 	//cout<<txno<<" ";
			// 	if(!sstxn.eof()) group.insert(stoi(txno));
			// 	txno.clear();
			// 	//c++;

			// }
			

			do{
				int check=0;
				getline(sstxn, txno, delim);
				//cout<<txno<<" ";
				if(sstxn.eof()) check=-1;
				//if(!sstxn.eof()) 
				group.insert(stoi(txno));
				txno.clear();
				c++;				

			}while(c<clustgroup[i]);
			dbs.push_back(group);
			group.clear();
		}

		item.second=dbs;
		soi.push_back(item);
		dbs.clear();
		item.first.clear();
		item.second.clear();
		clustgroup.clear();




	}


	//cout<<"done"<<endl;

	return;
}
