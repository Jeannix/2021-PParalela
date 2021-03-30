#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

int** A;
int** B;
int** C;

int n=2000;
int m=3000;
int k=4000;

void Mat_r_MEM(){		// Memory Reservation for all Matrix
	A=new int*[n];
	for(int i=0; i<n;++i)
		A[i]=new int[m];
	B=new int*[m];
	for(int i=0; i<m;++i)
		B[i]=new int[k];
	C=new int*[n];
	for(int i=0; i<n;++i)
		C[i]=new int[k];
}
void Mat_f_MEM(){
	for (int i=0; i<n; ++i){		// Initialization of A
		for (int j=0; j<m; ++j){
			int temp=rand() % 300;
			A[i][j]=temp;
		}
	}
	for (int i=0; i<m; ++i){		// Initialization of B
		for (int j=0; j<k; ++j){
			int temp=rand() % 300;
			B[i][j]=temp;
		}
	}
	for (int i=0; i<n; ++i){		// Initialization with 0's
		for (int j=0; j<k; ++j){
			C[i][j]=0;
		}
	}
}
void Mat_p(int** p, int tam1, int tam2){ // Matrix Print
	for (int i=0; i<tam1; ++i){
		for (int j=0; j<tam2; ++j){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Mat_Mult(){  // Matrix Multiplication
	for(int ti=0; ti<n; ti++){
		for(int tj=0; tj<k; tj++){
			for(int tk=0; tk<m; tk++){
				C[ti][tj] = C[ti][tj] + A[ti][tk] * B[tk][tj];
			}
		}
	}
}
void Mat_c_MEM(){  // Matrix Clean Memory
	for (int i=0; i<n; ++i){
		delete [] A[i];
		delete [] A;
	}
	for (int i=0; i<m; ++i){
		delete [] B[i];
		delete [] B;
	}
	for (int i=0; i<n; ++i){
		delete [] C[i];
		delete [] C;
	}
}
int main() {
	Mat_r_MEM();
	Mat_f_MEM();
	//Mat_p(A,n,m);
	//cout<<endl;
	//Mat_p(B,m,k);
	//cout<<endl;
	//Mat_p(C,n,k);
	//cout<<endl;
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	Mat_Mult();
	end = std::chrono::high_resolution_clock::now();
	int64_t duration =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
		.count();
	std::cout << duration;
	cout<<endl;
	//Mat_p(C,n,k);
	//Mat_c_MEM();
	return 0;
}
