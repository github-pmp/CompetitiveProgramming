/*COMPLESSITA'*/
/*Per poter calcolare la complessità dell'algoritmo dobbiamo tener conto di due fattori,la costruzione della struttura dati(static prefix sum) e del costo di una query.
Preso una stringa s la mia struttura dati v contiene per ogni elemento v[i] con 0<i<s.lenght(), v[i] = #{j|s(j)==s(j+1) con i < j <= s.lenght() e la costruisco scorrendo 
la stringa una sola volta di conseguenza il costo è ϴ(n).Per le query mi basterà O(1) poichè eseguo una sola operazione ovvero v[start]-v[end].*/


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
