#include <iostream>
#include <cstdlib>
#include <cmath>
#define MAX 10 // Aruebas con 10 / 100 / 1000 -> 100 elem / 10000 elem / 1M elem	
using namespace std;
double y[MAX]={0};
double x[MAX];
double** A;

void Mat_r_MEM(){
	A = new double*[MAX];
	for (int i = 0; i < MAX; ++i)
		A[i] = new double[MAX];
}
void Mat_f_MEM(){
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			int temp=rand() % 10000;
			A[i][j]=temp;
		}
	}
}
void Arr_f_MEM(){
	for (int i=0; i<MAX; ++i){
		int temp=rand() % 10000;
		x[i]=temp;
	}
}
void Mat_p(){
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Arr_p_y(){
	for(int i=0;i<MAX;i++){
		cout<<y[i];
	}
	cout<<endl;
}
void Arr_p_x(){
	for(int i=0;i<MAX;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void Mat_c_MEM(){
	for (int i=0; i<MAX; ++i){
		delete [] A[i];
		delete [] A;
	}
}
int main(int argc, char *argv[]){
	Mat_r_MEM();
	Mat_f_MEM();
	Arr_f_MEM();
	//Mat_p();
	//cout<<endl;
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			y[i] += A[i][j] * x[j];
		}
	}
	//Arr_p_y();
	//Arr_p_x();
	Mat_c_MEM();
	return 0;
}

