/*TIME COMPLEXITY*/
/*To resolve this problem i use an array v that contains for any elements v[i]={value,i,j}, i sorted this array respect the value field and i take elements starting
from the maximum values until i've covered all the searching couples of the problem.
The time complexity is the time that i spend to order that is O(N*logN) plus the time that i spend to fill all couples that is at most N*#rows, therefore O(N*#rows).
IN conclusion this algorithm runs in O(N*logN)+O(N*#rows)*/


#include<stdio.h>
#include <iostream>
#include <vector> 
#include <bits/stdc++.h> 
#include<tuple>



int main(){
    int len;
    long long int number;
    std::cin>>len;
    int righe=(2*len)-1;
    int number_elements = (righe*(righe+1))/2;
    std::vector<int> vec;
    std::vector<std::tuple<int, int, long long int> > v; 
    vec.reserve(number_elements);
    v.reserve(len);
    for(int i=0;i<number_elements;i++){
			std::cin >> number;
			vec.push_back(number);
		}

     int riga=2;
     int i=0;
     while(i<number_elements){
	    int colonna=1;
	    while(colonna<riga){
	        v.push_back(std::make_tuple(vec[i],riga,colonna));
	        ++i;
	        ++colonna;
	    }
	    ++riga;
     }
     sort(v.begin(), v.end()); 
	/*for(int i=0;i<v.size();i++){
	    std::cout << std::get<0>(v[i]) << " " 
             << std::get<1>(v[i]) << " " 
             << std::get<2>(v[i]) << "\n";
	}*/
     std::vector<long long int> res;
     int size=len*2;
     res.reserve(size+1);
     for(int i=0;i<size+1;i++)
     	res[i]=-1;
	    
     i=vec.size()-1; 
     int j=0;
     while(j<size){
	    int first=std::get<1>(v[i]);
	    int second=std::get<2>(v[i]);
	    if(res[first]==-1 && res[second]==-1 )
	    {
	        res[first]=second;
	        res[second]=first;
	        j+=2;
	    }
	    --i;
      }
      for(int i=1;i<size+1;i++)
	 std::cout << res[i] << " ";
	
	

    return 0;
}
