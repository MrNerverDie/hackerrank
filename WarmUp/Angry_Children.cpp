#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{

	int N, K;
	cin>>N>>K;
	std::vector<int> packets;
	for (int i = 0; i < N; ++i)
	{
		int temp; cin>>temp;
	    packets.push_back(temp);
	}
	sort(packets.begin(), packets.end());
	int distance = K;
	int min = packets[K - 1] - packets[0];
	while(K++ < N) {
		int value = packets[K - 1] - packets[K - distance];
		if(value < min) 
			min = value;
	}
	cout<<min<<endl;

	return 0;
}