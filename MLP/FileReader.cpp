#include "FileReader.h"
#include <string>

NeuralNetworkFileReader::NeuralNetworkFileReader(std::string filePath)
{
	NeuralNetworkFileReader::mInputStream.open(filePath.c_str());
}

NeuralNetworkFileReader::~NeuralNetworkFileReader()
{
	mInputStream.close();
}

vector<int>& NeuralNetworkFileReader::getNeuronsPerLayer()
{
	return m_NeuronsPerLayer;
}

vector<vector<float>>& NeuralNetworkFileReader::getWeights()
{
	return m_Wieghts;
}

int NeuralNetworkFileReader::getNumberOfLayers()
{
	return m_NumberOfLayers;
}

bool NeuralNetworkFileReader::load(std::string filePath)
{
	try
	{
		NeuralNetworkFileReader::mInputStream.open(filePath.c_str());
		//load number of layers.
		string buffer;
		getline(mInputStream,buffer);
		m_NumberOfLayers = atoi(buffer.c_str());
		//load neurons per layer.
		for (int i = 0; i < m_NumberOfLayers; i++)
		{
			getline(mInputStream,buffer);
			m_NeuronsPerLayer.push_back(atoi(buffer.c_str()));
		}
		//load weights.

		

		return true;
	}
	catch(exception& e)
	{
		return false;
	}

}