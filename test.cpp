#define USE_BLAS_LIB
#include "spams.h"
#include <string>

using namespace std;
using namespace FISTA;

void display(Matrix<double>& mat)
{
	int m=mat.m();
	int n=mat.n();
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
			cout<<mat(i,j)<<" ";
		cout<<endl;
	}
}
int main(int argc,char** argv)
{
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	Matrix<double> u(m,n);
	u.setAleat();
	display(u);
	Matrix<double> v(m,n);
	ParamFISTA<double> param;
	Vector < int > *  groups=new Vector < int > ();
	char* regul=argv[3];
        _proximalFlat(&u,&v,groups,1,1.0,0.0,0.0,false,false,regul,true,false,true,true,1,false);
	cout<<endl<<"after procesing "<<endl;
	display(v);
	return 1;
}
