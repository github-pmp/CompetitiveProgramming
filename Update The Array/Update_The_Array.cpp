/*TIME COMPLEXITY*/
/*To resolve this problem i use an auxiliary data structure called "binary indexed tree"(BIT) to store the dynamic prefix-sums.
The idea is to support the update operation and have a better time for the query.
For one update operation we have to sum all the element in the range and we pay at most O(N) time.
The update operation considering that we use a BIT cost at most O(LogN) where N is the index of the query.
In conclusion this algorithm cost O(N) + O(LogN) time.
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>


void add(std::vector<long long> &b,long long index,long long val){
    index = index + 1; 
    while (index <= b.capacity()) { 
    	b[index] += val; 
    	index += index & (-index); 
	}
}

long long sum(std::vector<long long> &b,long long index){
    long long sum = 0; 
    index = index + 1; 
    while (index>0) 
    { 
        sum += b[index]; 
        index -= index & (-index); 
    } 
    return sum;
}

int main() {
	int test,dim,l,r,numq;
	long long nupdate,num;
	std::vector<long long> result;	
	std::cin>> test;
	while(test > 0){
	std::cin >> dim;
	std::cin >> nupdate;
	std::vector<long long> v;
	v.reserve(dim);
	result.reserve(dim);
	std::vector<long long> BITtree(dim+1);
	for(long long i=0; i<nupdate ;i++){
		std::cin >> l;
		std::cin >> r;
		std::cin >> num;
		add(BITtree,l,num);
		if(r!=dim-1)add(BITtree,r+1,-num);
	}
	std::cin>>numq;
	int query;
	for(int i=0;i<numq;i++){
		std::cin >> query;
		result.push_back(sum(BITtree,query));
	}
	test--;	
	}
	for(int i=0; i<result.size() ;i++)	
		std::cout << result[i] << std::endl;
	
	return 0;
}
