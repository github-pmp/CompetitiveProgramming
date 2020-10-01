#include<stdio.h>
#include <iostream>
#include <vector> 
#include<bits/stdc++.h>


int main(){
    int len,number;
    std::cin>>len;
    std::vector<int> vec;
    vec.reserve(len);
    for(int i=0;i<len;i++){
			std::cin >> number;
			vec.push_back(number);
		}
	std::sort(vec.begin(), vec.end());
	int max=1;
	int diff=1;
	int elem=vec[0];
	int elem_counts=1;
	for(int i=1;i<len;++i)  
	    {
	       if(elem==vec[i])
	        ++elem_counts;
	       else{
	           ++diff;
	           elem_counts=1;
	           elem=vec[i];
	       }
	       if(max<elem_counts)
	            max=elem_counts;
	    }
	
	 std::cout << max << " " << diff;
	
    
    return 0;
}
