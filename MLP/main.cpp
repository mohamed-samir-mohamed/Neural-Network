#include <iostream>
#include <fstream>
#include "NeuralNetwork.h"
#include "NeuralNetworkFileReader.h"
using namespace std;

int main()
{
	NeuralNetworkCalssifier f ("C://Users//Muhammad Samir//Desktop//test.txt");
	vector<float> testPattern;
	for(int i = 0; i < 400 ; i++)
	{
		testPattern.push_back(1);
	}

	int g =  f.classify(testPattern);
	return 0;
}