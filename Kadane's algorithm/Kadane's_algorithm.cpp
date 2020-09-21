#include <stdio.h>
#include <vector>
#include <iostream>

void sumsubarray(std::vector<int>  vector){
    int sum=vector[0];
    int maxsum=vector[0];
	for(int i=1;i<vector.size();++i){
	   sum+=vector[i];
       if(sum<vector[i])
    	 sum=vector[i];
	   
	if(sum>maxsum)  
	    maxsum=sum;
	}
	std::cout << maxsum << " " << std::endl;
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
		sumsubarray(vec);
		vec.clear();
	    test--;	 
	}
	return 0;
}
