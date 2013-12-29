#ifndef NEURALNETWORKCALSSIFIER_H
#define NEURALNETWORKCALSSIFIER_H
#include <vector>
#include <string>
using namespace std;

//forward declarations.
class Layer;
class NeuralNetworkFileReader;

class NeuralNetworkCalssifier
{
public:	
	NeuralNetworkCalssifier(string filePath);	
	~NeuralNetworkCalssifier();
	void initNeuralNetwork(vector<int> NeuronsPerLayer);
	int  classify(vector<float> pattern);
	void loadWieghts(vector<vector<float>> weightVectors);

private:
	vector<std::shared_ptr<Layer>> m_Layers;
	static int indexOfMax(vector<float>);
	std::unique_ptr<NeuralNetworkFileReader> m_FileReader;
};
#endif