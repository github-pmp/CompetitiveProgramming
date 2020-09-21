#include <stdio.h>
#include <iostream>
#include <vector> 
#include<bits/stdc++.h>

int remove_indexes(std::deque<int> &qi,int k,int i){
    while (!qi.empty() and qi.front() <= i - k)
            qi.pop_front();
        
}
void calc_sub_max(std::vector<int> vec,int k){
    std::deque<int> qi;
    for(int i=0;i < vec.size();++i){
        remove_indexes(qi,k,i);
        while(!qi.empty() and vec[i]>=vec[qi.back()])
            qi.pop_back();
        qi.push_back(i);
        if(i >= k-1){
            std::cout << vec[qi.front()] << " ";
        }
    }
    
}


int main() {
    int test,len,k;
	std::cin>>test;
	std::vector<int> vec;
	while(test>0){
	    std::cin>>len;
	    std::cin>>k;
	    vec.reserve(len);
	    int number;
	    for(int i=0;i<len;i++){
			std::cin >> number;
			vec.push_back(number);
		}
		calc_sub_max(vec,k);
		std::cout << std::endl;
		vec.clear();
	    test--;	 
	}
	return 0;
}
