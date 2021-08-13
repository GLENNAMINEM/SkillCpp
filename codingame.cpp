#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* This function takes two vectors and a start id and  return last id */
int searchend( vector<int> fromids, vector<int> endids, int startid){
    int idx=0; //To stock a id from value 
    int i = 1 ; 

    vector<int>::iterator it = find(fromids.begin(), fromids.end(), endids[startid]);
    if(it != fromids.end()){
            idx = distance(fromids.begin(), it);
        }

    while(i != fromids.size()){

        vector<int>::iterator it = find(fromids.begin(), fromids.end(), endids[idx]);
         if(it != fromids.end()){
            idx = distance(fromids.begin(), it);
        }else{ 
            // If we dn't find we go to next id
            idx++;
        }
            
        i++;
    }

    return endids[idx];
}




int main(){

vector<int> fromids { 4, 9, 6, 1 };
vector<int> endids { 9, 5, 1, 4 };
int startid = 4;
auto end = searchend(fromids, endids, startid);
cout<<" le dernier element:"<<end<<endl;

    return 0;
}