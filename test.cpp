#include "Children.cpp"
#include "Adult.cpp"
using namespace std;

int main()
{
	string hong;
	hong = "affine";
	for(int i = 0; i< hong.size(); i++){
		hong[i] =((hong[i]-97)*5 +(7%26) +97);
	}
	cout<<hong;
	return 0;
}