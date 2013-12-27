#ifndef NEURALNETWORKCALSSIFIER_H
#define NEURALNETWORKCALSSIFIER_H
#include "Layer.h"
#include <vector>
#include <string>
#include "FileReader.h"
using namespace std;


class NeuralNetworkCalssifier
{
public:	
	NeuralNetworkCalssifier(string filePath);	
	~NeuralNetworkCalssifier();
	void initNeuralNetwork(vector<int> NeuronsPerLayer);
	int classify(vector<float> pattern);
	void loadWieghts(vector<vector<float>> weightVectors);

private:
	vector<std::shared_ptr<Layer>> m_Layers;
	static int indexOfMax(vector<float>);
	NeuralNetworkFileReader m_FileReader;
};
#endif