// #include <iostream>
// #include <Eigen/Dense>
// using Eigen::MatrixXd;
// using namespace std;
// int main()
// {
//   MatrixXd m(2,2);
//     m(0,0) = 3;
//       m(1,0) = 2.5;
//         m(0,1) = -1;
//           m(1,1) = m(1,0) + m(0,1);
//         cout << m << endl;}

// inserting into a vector
#include <iostream>
#include <vector>

void print(std::vector<int> myvector)
{
	for (std::vector<int>::iterator it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main ()
{
	std::vector<int> myvector (3,100);
	print(myvector);
	std::vector<int>::iterator it;
	
	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	print(myvector);

	myvector.insert (it,2,300);
	print(myvector);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	print(myvector);

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	print(myvector);

	return 0;
}
