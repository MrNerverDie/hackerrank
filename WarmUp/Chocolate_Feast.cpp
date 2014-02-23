#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{

 	string s;

 	int times, N, C, M;
 	cin>>times;
 	while(times--) {
 		cin>>N>>C>>M;
 	    int num = N / C;
 	    int leftWarpers = num;
 	    while(leftWarpers - M >= 0) {
 	        leftWarpers -= M;
 	        leftWarpers++;
 	        num++;
 	    }
 	    cout<<num<<endl;
 	}

	return 0;
}