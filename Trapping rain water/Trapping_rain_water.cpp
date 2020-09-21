#include <stdio.h>
#include <iostream>
#include <vector> 


void calc_water(std::vector<int>  vector){
    std::vector<int> ML;
    std::vector<int> MR;
    ML.reserve(vector.size());
    MR.reserve(vector.size());
    int max = vector[0];
    int pos_max=0;
    int maxr=0;
    int maxl=0;
    //CALCOLO IL MASSIMO
    for(int i=1;i<vector.size();++i)
        if(max<vector[i]){
            max=vector[i];
            pos_max=i;
            }
            
    for(int j=0;j<pos_max;++j){
        ML[j]=maxl;
        MR[j]=max;
        if(vector[j]>maxl)
                maxl=vector[j];
            
    }
    for(int j=vector.size()-1;j>pos_max;--j){
        MR[j]=maxr;
        ML[j]=max;
        if(vector[j]>maxr)
                maxr=vector[j];
    }
    ML[0]=0;
    MR[vector.size()-1]=0;
    ML[pos_max]=maxl;
    MR[pos_max]=maxr;
    /*
     for(int i=0;i<vector.size();i++){
        std::cout<<MR[i] << " ";
    }
    std::cout << std::endl;
    for(int i=0;i<vector.size();i++){
        std::cout<<ML[i] << " ";
    }*/
    
    //CALCOLO DELL'ACQUA
    int min;
    int total_water=0;
    for(int i=0;i<vector.size();++i){
        if(vector[i]<ML[i] && vector[i]<MR[i]){
            if(ML[i]<MR[i])
                min=ML[i];
            else min=MR[i];
            total_water+=(min-vector[i]);
        }
    }
    std::cout << total_water  << std::endl;

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
		calc_water(vec);
		vec.clear();
	    test--;	 
	}
	return 0;
}
