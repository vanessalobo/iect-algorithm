#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

vector<int> intersection(vector<vector<int> > arrays, int* length){
	int n= arrays.size();
	int sizes[n+1];
	for(int i=0; i<n; i++){
		sizes[i]=arrays[i].size();
	}
	int max=*max_element(sizes, sizes+n);
	vector<int> res(max);
	auto it=set_intersection(arrays[0].begin(), arrays[0].end(), arrays[1].begin(), arrays[1].end(), res.begin());
	std::vector<int> temp(max);	

	for(int i=2; i<n; i++){
		
		it=set_intersection(res.begin(), res.end(), arrays[i].begin(), arrays[i].end(), temp.begin());
		res=temp;
		//cout<<it-temp.begin()<<endl;
	} 
	*length=it-temp.begin();
	//cout<<*length<<endl;
	return res;
}

