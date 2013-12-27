#include "FileReader.h"
#include <string>

NeuralNetworkFileReader::NeuralNetworkFileReader(std::string filePath)
{
	load(filePath);
}

NeuralNetworkFileReader::NeuralNetworkFileReader()
{

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
		mInputStream.open(filePath);
		bool b = mInputStream.is_open();
		//load number of layers.
		string buffer;
		bool a = getline(mInputStream,buffer);
		m_NumberOfLayers = atoi(buffer.c_str());
		//load neurons per layer.
		for (int i = 0; i < m_NumberOfLayers; i++)
		{
			getline(mInputStream,buffer);
			m_NeuronsPerLayer.push_back(atoi(buffer.c_str()));
		}
		//load weights.
		for (int i = 1; i < m_NumberOfLayers; i++)
		{
			int currentWeightsCount = m_NeuronsPerLayer[i-1] * m_NeuronsPerLayer[i]; //intermediate weights count equals to the multiplication of the layers neurons count.
			vector<float> currentWeights;
			for (int j = 0; j < currentWeightsCount; j++)
			{
				getline(mInputStream,buffer);
				currentWeights.push_back(atof(buffer.c_str()));
			}
			m_Wieghts.push_back(currentWeights);
		}
		return true;
	}
	catch(exception& e)
	{
		return false;
	}
}