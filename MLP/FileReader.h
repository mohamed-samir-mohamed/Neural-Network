#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <fstream>
#include <iosfwd>

using namespace std;

class NeuralNetworkFileReader
{
public:
	NeuralNetworkFileReader();
	NeuralNetworkFileReader(std::string filePath);
	~NeuralNetworkFileReader();
	bool load(std::string filePath);
	int getNumberOfLayers();
	vector<int>& getNeuronsPerLayer();
	vector<vector<float>>& getWeights();

private:
	fstream mInputStream;
	int m_NumberOfLayers;
	vector<int> m_NeuronsPerLayer;
	vector<vector<float>> m_Wieghts;
};
#endif