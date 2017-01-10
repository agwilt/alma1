#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
 
using namespace std;

vector<int> merge(vector<int> v1,vector<int> v2){
    vector<int> v(v1.size()+v2.size());
	unsigned int i=0;    
    unsigned int j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<=v2[j]){
            v[i+j]=v1[i];   
            ++i;       
        }
        else{
            v[i+j]=v2[j];
            ++j;     
        }
    }
    if(i<v1.size()){
        for(unsigned int k=i; k<v1.size(); ++k){
            v[k+j]=v1[k];        
		}
	}
    else{
        for(unsigned int k=j; k<v2.size(); ++k){
            v[k+i]=v2[k];       
		}
    }
	return v;
}



 
vector<int> merge_sort(const vector<int>& input)
{
    if(input.size()<=1){
		return input;
	}
	vector<int> output(input.size());
 
    //Split Vector//
    int midpoint=0.5*input.size();
	vector<int> input_left(input.begin(),input.begin()+midpoint);
    vector<int> input_right(input.begin()+midpoint,input.end());

    input_left=merge_sort(input_left);
    input_right=merge_sort(input_right);
	output=merge(input_left,input_right);

    return output;
}
 
int main(){
	
    //Create unsorted vector of ints
	srand(clock());
	int n=0;
	cout<< "Enter a number: ";
	cin>> n;
    vector<int> unsorted(n);
	vector<int> unsorted_copy(n);
    for(int i=0; i<n; ++i){
		unsorted[i]=rand()%1000;
		unsorted_copy[i]=unsorted[i];
		
	}
 
    //Perform merge_sort//
	clock_t    start;
	start = clock();
    vector<int> sortedmerge=merge_sort(unsorted);
    std::cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	
	//Perform sort//	
	start = clock();
    sort(unsorted_copy.begin(),unsorted_copy.end());
    std::cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	
    //Display results//
	if (n<=100){
    cout << "Unsorted: " <<  endl;
    for(auto value:unsorted)  cout << value << " ";
    cout <<  "\n"<< endl;
    cout << "Merge Sorted: " <<  endl;
    for(auto value:sortedmerge)  cout << value << " ";
    cout <<  "\n"<<endl;
	cout << "Sort Sorted: " <<  endl;
	for(auto value:unsorted_copy)  cout << value << " ";
    cout <<  "\n"<<endl;
	}
 
}