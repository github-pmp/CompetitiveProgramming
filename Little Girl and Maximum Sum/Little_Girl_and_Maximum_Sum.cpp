#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

long long calc(std::vector<long long> const &v,std::vector<long long> const &c){
	long long sum = 0;
	for(int i=0; i < v.size() ;i++)	
		sum+=(c[i] * v[i]);
	
	
	return sum;
}



int main() {
    int test=0;
    int dim;
	std::cin>>dim;
	std::cin>>test; 
	std::vector<long long> vet;
	std::vector<long long> contatori(dim);
	vet.reserve(dim);
	long long num;
	for(int i=0;i<dim;i++){
		std::cin >> num;
		vet.push_back(num);
	}
	std::vector<long long> result;
	result.reserve(test);
	while(test>0){
	    long long queryl;
	    long long queryr;
		std::cin >> queryl;	
		std::cin >> queryr;
		contatori[queryl-1]++; 
		if(queryr != dim)contatori[queryr]--;   		
	    test--;	 
	}
	for(int i=1;i<dim;i++)
		contatori[i]+=contatori[i-1];
	std::sort(vet.begin(),vet.end());
	std::sort(contatori.begin(),contatori.end());	
	std::cout << calc(vet,contatori);	
	return 0;
}
