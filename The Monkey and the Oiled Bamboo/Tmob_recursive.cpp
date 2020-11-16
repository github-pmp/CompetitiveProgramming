/*TIME COMPLEXITY*/
/*To resolve this kind of problem one approch is to use "exponential search" and "binary search":
In the first step we generate solutions in according to exponential values and we stop when a solution is accepted for the problem.
In the second step we take this solution and we use "binary search" in the range [0 - solution] to search the best solution.
For "exponential search" we pay in time at most O(log i) where i is the first solution accepted, instead for "binary search" we pay O(K*logK) where K = [0-solution].
The total cost of this algorithm is O(log i) + O(K*logK) time.
*/



#include <stdio.h>
#include <iostream>
#include <vector> 
#include<bits/stdc++.h>

int check_solution(long long sol,std::vector<long long >& vec,int start){
	for(int i=start;i<vec.size();i++){
		int input=vec[i];
		if(sol==input)sol--;
		else if(sol<input) return i;
	}
	return -1;
}

long long binarysearch(std::vector<long long >& vec,long long l,long long r,long long min){
	if(l==r)return min;
	long long middle = (r+l)/2;
	long long sol = check_solution(middle,vec,0);
	if(sol == -1){
		if(middle < min)min=middle;
			return binarysearch(vec,l,middle,min);
	}else return binarysearch(vec,middle+1,r,min);
	
}



int calc(std::vector<long long >& vec){	
	std::vector<long long> result;
	result.reserve(result.size());
	result.push_back(vec[0]);
	for(int i=1;i<vec.size();++i)
		result.push_back(vec[i] - vec[i-1] );
	long long exp=0;
	long long sol=1;
	if(check_solution(sol,result,0)==-1)return 1;
	bool exit=false;
	int start=0;
	
	while(!exit){
		sol=sol*2;
		start=check_solution(sol,result,start);
		if(start == -1)exit=true;
		else exp++;			
	}
	long long rangel = sol/2;
	long long ranger = sol;
	
	sol = binarysearch(result,rangel,ranger,sol);
	return sol;
	
	}
	
	

int main() {
    int test=0;
    int len=0;
	std::cin>>test;
	std::vector< long long> vec;
	std::vector<long long> result;
	while(test>0){
		std::cin>>len;
	    vec.reserve(len);
	    int number;
	    for(int i=0;i<len;i++){
			std::cin >> number;
			vec.push_back(number);
		}
		long long r=calc(vec);
		result.push_back(r);
		vec.clear();
	    test--;	 
	}
	for(int i=0;i<result.size();i++)
		std::cout<<"Case "<< i+1 << ": "<<result[i]<< std::endl;
		
	return 0;
}
