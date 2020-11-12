/*COMPLEXITY*/
/* The time complexity of this algorithm is ϴ(N). We can use the Gauss formula for the sum of first n natural numbers and to compute missing number we
can scan the entire array for compute the sum and we can take the difference between them, that is:  Gauss_sum - sum_number_in_array.*/


#include <stdio.h>
#include <iostream>
#include <vector> 


void find_number(std::vector<int>  vector,int n){
    int sum=0;
    int g_sum=(n*(n+1))/2;
    for(int i=0;i<vector.size();++i)
        sum+=vector[i];
    std::cout << g_sum-sum  << std::endl;
}


int main() {
    int test,len;
	std::cin>>test;
	std::vector<int> vec;
	while(test>0){
	    std::cin>>len;
	    vec.reserve(len);
	    int number;
	    for(int i=0;i<len-1;i++){
			std::cin >> number;
			vec.push_back(number);
		}
		find_number(vec,len);
		vec.clear();
	    test--;	 
	}
	return 0;
}
