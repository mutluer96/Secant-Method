#include <iostream>
#include <cmath>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<Windows.h>

using namespace std;

//this program computes the root of a 4th deg polynomial numerically 
//with secant method

ofstream outfile;


double secant_method(double A, double B, double C, double D, double E, double x_n, double x_n_minus_1, ofstream & out)
{

	int i;
	double xnpl1, xn, xnmin1, a, b, c, d, e;
	a = A;
	b = B;
	c = C;
	d = D;
	e = E;
	xn = x_n;
	xnmin1 = x_n_minus_1;


	for (i = 0;; i++)
	{
		xnpl1 = xn - ((a*pow(xn, 4) + b * pow(xn, 3) + c * pow(xn, 2) + d * xn + e)*(xn - xnmin1) / ((a*pow(xn, 4) + b * pow(xn, 3) + c * pow(xn, 2) + d * xn + e) - (a*pow(xnmin1, 4) + b * pow(xnmin1, 3) + c * pow(xnmin1, 2) + d * xnmin1 + e)));
		xnmin1 = xn;
		xn = xnpl1;
		if (abs((a*pow(xnpl1, 4) + b * pow(xnpl1, 3) + c * pow(xnpl1, 2) + d * xnpl1 + e)) <= 0.0001)
		{
			break;
		}
		if (i > 1500)
		{
			cout << "Ooops no convergence to any root, num of iterations is: " << i << endl;
			out << "\n\nOoops no convergence to any root, details are below, num of iterations is: " << i << endl;
			out << fixed << showpoint;
			out << left << setprecision(0) << A << "x^4 +" << B << "x^3 +" << C << "x^2 +" << D << "x +" << E<<endl;
			out << showpoint << setprecision(2) << "x_n root candidate: " << setw(6) << x_n << "x_n_minus_1 root candidate: " << setw(12) << x_n_minus_1 << endl;

			return false;
		}
	}
	
	out << fixed << showpoint ;
	out << left << setprecision(0) << A << "x^4 +" << B << "x^3 +" << C << "x^2 +" << D << "x +" << E<<endl;
	out << showpoint<<setprecision(2) <<"x_n root candidate: "<< setw(6) << x_n << "x_n_minus_1 root candidate: "<<setw(12) << x_n_minus_1 << endl;
	cout << "The number of iteration is equal to : " << i << endl;
	out << setw(18) << left << "Num of Iterations: " << i << " "<<setw(5) << "Root " <<setprecision(6)<< xnpl1 << endl << endl;
	return xnpl1;
}
int main()
{ 
	outfile.open("Secant_Method_Data.txt");

	char program_status;
	int number_of_iteration;
	double x_n_plus_1, x_n, x_n_minus_1, A, B, C, D, E;
	//A(X^4)+B(X^3)+C(X^2)+D(X)+E==0;

	cout << "This program helps you to find the real roots of 4th degree polynomials" << endl;


	while (true)
	{
		cin.clear();//to clear input buffer
		cout << "Please insert the initial test root" << endl;
		cin >> x_n;
		cout << "Please insert the second test root" << endl;
		cin >> x_n_minus_1;
		
		cout << "Insert coefficient of x^4" << endl;
		cin >> A;
		cout << "Insert coefficient of x^3" << endl;
		cin >> B;
		cout << "Insert coefficient of x^2" << endl;
		cin >> C;
		cout << "Insert coefficient of x" << endl;
		cin >> D;
		cout << "Insert constant of polynomial" << endl;
		cin >> E;


		cout << "The resultant root of polynomial is " << secant_method(A, B, C, D, E, x_n, x_n_minus_1, outfile) << endl;//calling function


		cout << "Another root finding or exit the program? (for exit press E , to contiue just press a key)" << endl;
		cin >> program_status;
		
		if ((program_status == 'e') || (program_status == 'E'))
		{
			break;
		}
		else
		{
		//	Sleep(50);
			system("cls");
		}
		
	}
	
	//system("Pause");
	return 0;
}