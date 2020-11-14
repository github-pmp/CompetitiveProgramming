/*TIME COMPLEXITY*/
/* To solve this problem is helpuful use the paradigm "Divide and Conquer" and in particular the "merge-sort" algorithm because the number of inversion that we need are equal
to the number of exchange of two consequent element to be able to order an array.
So the time complexity is O(N*logN).*/



#include <stdio.h>
#include <iostream>
#include <vector> 
#include<bits/stdc++.h>

long long int merge(std::vector<long long int>& A, long long int l, long long int m, long long int r ) {
  long long int i = l;
  long long int j = m + 1;
  std::vector<long long int> copy((r-l)+1);
  long long int k = 0;
  long long int count = 0;
  
  while((i <= m) and (j <= r)) {
    if(A[i] < A[j]) {
      copy[k] = A[i];
      i++;
    } else {
      copy[k] = A[j];
      count += m-i+1;
      j++;
    }
    k++;
    
  }
  
  while(i <= m){
  	copy[k] = A[i];
  	k++;
  	i++;
  }
    
  while(j <= r){
  	copy[k] = A[j];
  	k++;
  	j++;
  }
    
  
  std::copy(copy.begin(), copy.end(), A.begin()+l);
  
  return count;
}

long long int calc_inversion(std::vector<long long int> &vec,long long int l,long long int r){
    if(l>=r)return 0;
    long long int middle=(l+r)/2;
    long long int cl=calc_inversion(vec,l,middle);
    long long int cr=calc_inversion(vec,middle+1,r);
    return cr+cl+merge(vec,l,middle,r);  
}


int main() {
    int test;
    long long int len;
	std::cin>>test;
	std::vector<long long int> vec;
	std::string blank;
	std::getline(std::cin,blank);
	while(test>0){
		std::cin>>len;
	    vec.reserve(len);
	    long long int number;
	    for(int i=0;i<len;i++){
			std::cin >> number;
			vec.push_back(number);
		}
		std::getline(std::cin,blank);
		std::cout << calc_inversion(vec,0,len-1);
		std::cout << std::endl;
		vec.clear();
	    test--;	 
	}
	return 0;
}
