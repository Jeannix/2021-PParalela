#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
#define MAX 10000 // Pruebas con 10 / 100 / 1000 -> 100 elem / 10000 elem / 1M elem	
using namespace std::chrono;
using namespace std;

double y[MAX]={0};	// Y initialization
double x[MAX];	// X Declaration
double** A;		// Matrix A Declaration

void Mat_r_MEM(){	// Matrix Reserve Memory
	A = new double*[MAX];
	for (int i = 0; i < MAX; ++i)
		A[i] = new double[MAX];
}
void Mat_f_MEM(){	//Matrix Fill Memory
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			int temp=rand() % 10000;
			A[i][j]=temp;
		}
	}
}
void Arr_f_MEM(){ // Array Fill Memory
	for (int i=0; i<MAX; ++i){
		int temp=rand() % 10000;
		x[i]=temp;
	}
}
void Mat_p(){ // Matrix Print
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Arr_p_y(){ // Array Y Print 
	for(int i=0;i<MAX;i++){
		cout<<y[i];
	}
	cout<<endl;
}
void Arr_p_x(){	// Array X Print 
	for(int i=0;i<MAX;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void Mat_c_MEM(){  // Matrix Clean Memory
	for (int i=0; i<MAX; ++i){
		delete [] A[i];
		delete [] A;
	}
}
int main(){
	Mat_r_MEM();
	Mat_f_MEM();
	Arr_f_MEM();
	//Mat_p();
	//cout<<endl;
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			y[i] += A[i][j] * x[j];
		}
	}
	end = std::chrono::high_resolution_clock::now();
	int64_t duration =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
		.count();
	std::cout << std::setw(10) << duration << std::setw(30);
	//Arr_p_y();
	//Arr_p_x();
	Mat_c_MEM();
	return 0;
}
