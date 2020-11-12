#include <stdio.h>
#include <iostream>
#include <vector> 
/*COMPLEXITY*/
/*The time complexity for this algorithm is ϴ(n) because we scan the entire array from the last element to the first and compute the leaders step by step*/

void printleaders(std::vector<int>  vector){
    std::vector<int> leaders;
    leaders.reserve(vector.size());
    int max = vector.back();
    leaders.push_back(max);
    for(int i=vector.size()-2; i>=0 ;i--){	
    	if(vector[i]>=max){
    		max = vector[i];
    		leaders.push_back(max);
    	} 
	}   		
    /*std::cout << "stampa dei leader" << std::endl;*/	
	for(int i=leaders.size()-1;i>=0;i--)	
		std::cout << leaders[i] << " ";
	std::cout << std::endl;
}


int main() {
    int test,len;
	std::cin>>test;
	std::vector<int> vec;
	while(test>0){
	    std::cin>>len;
	    vec.reserve(len);
	    int number;
	    for(int i=0;i<len;i++){
			std::cin >> number;
			vec.push_back(number);
		}
		printleaders(vec);
		vec.clear();
	    test--;	 
	}
	return 0;
}
