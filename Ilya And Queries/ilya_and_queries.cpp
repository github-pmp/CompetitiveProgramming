/*COMPLEXITY
To compute the complexity of the algorithm we consider two aspects: the time for the costruction of the data structure(static data prefix sum) and the query time.
Cosider a string s and the data structure v: for all the elements v[i] with 0<i<s.lenght, v[i] = #{j|s(j)==s(j+1)} with i < j <= s.lenght(). To costruct it we scan 
the entire string s, therefore the time complexity is ϴ(n).
The query time is O(1) because there is only one operation for answer the query: v[start] - v[end].*/



#include <stdio.h>
#include <iostream>
#include <vector>

void construct(std::vector<int> &v,std::string s){
	int sum = 0;
	v[s.length()-1];
	for(int i=s.length()-2; i>=0 ;i--){
			if(s[i]==s[i+1])
				sum++;
			v[i]=sum;			
	}
	/*for(int i=0;i<s.length();i++)
		std::cout << v[i] << " ";*/
}


int main(){
	int len,start,end;
	std::string s;
	int sum=0;
	std::cin >> s;
	std::cin >> len;
	std::vector<int> v(s.length());
	int result[len+1];
	construct(v,s);
	for(int i=0;i<len;i++){
		std::cin >> start;
		std::cin >> end;
		start--;
		end--;		
		result[i] = v[start] - v[end];
	}	
	for(int i=0;i<len;i++)
		std::cout << result[i] << std::endl;
			
 return 0;
}
