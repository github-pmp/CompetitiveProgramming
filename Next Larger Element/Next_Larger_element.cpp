/*TIME COMPLEXITY*/
/*For study time complexity of this algorithm we can observe that the approch is similar to the "Sliding Window maximum" problem but in this case we don't have 
the ranges for compute the maximum element. The conclusion are the same and the cost of an iteration is at most O(N), the iteration process is repeted N times therefore
the total cost is O(N^2) time.*/

#include <stdio.h>
#include <iostream>
#include <vector> 
#include<bits/stdc++.h>


void find_max(std::vector<long long int> const& vec){
    std::deque<long long int> qi;
    std::vector<long long int> res;
    res.reserve(vec.size());
    
    for(int i=vec.size()-1;i >=0 ;--i){
        
        while(!qi.empty() and vec[i]>=qi.back())
            qi.pop_back();
           
    if(!qi.empty())res.push_back(qi.back());
    else res.push_back(-1);
    
    qi.push_back(vec[i]);
    
    }
    
    for(int i=vec.size()-1;i>=0;--i){
        std::cout <<res[i] << " ";
    }
    
}


int main() {
    int test,len,k;
	std::cin>>test;
	std::vector<long long int> vec;
	while(test>0){
	    std::cin>>len;
	    vec.reserve(len);
	    long long int number;
	    for(int i=0;i<len;i++){
			std::cin >> number;
			vec.push_back(number);
		}
		find_max(vec);
		std::cout << std::endl;
		vec.clear();
	    test--;	 
	}
	return 0;
}
