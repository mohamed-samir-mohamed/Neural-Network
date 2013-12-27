#include "NeuralNetwork.h"
#include <string>

int NeuralNetworkCalssifier::indexOfMax(vector<float> arr)
{
	int tmp = 0;
	float max = std::numeric_limits<float>::min();
	int size = arr.size();
	for (int i = 0 ; i < size ; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			tmp = i;
		}
	}
	return tmp;
}

NeuralNetworkCalssifier::NeuralNetworkCalssifier( string filePath )
{
	m_FileReader.load(filePath);
	initNeuralNetwork(m_FileReader.getNeuronsPerLayer());
	loadWieghts(m_FileReader.getWeights());
}

int NeuralNetworkCalssifier::classify(vector<float> pattern)
{
	vector <float> output;
	int layersCount = m_Layers.size();

	//init inputs to the first layer..
	m_Layers[0]->setLayerNeuronsValues(pattern);
	m_Layers[1]->setPreviousLayerNeuronsValues(pattern);

	for(int i = 1 ; i < layersCount; i++ )
	{
		m_Layers[i]->forward();
		for (int j = 0 ; j < m_Layers[i]->getNeuronsCount(); j++)
		{
			if (i < layersCount - 1)//not output layer.
			m_Layers[i+1]->setPreviousLayerNeuronValueAt(j,m_Layers[i]->getNuronAt(j)->m_Value);
		}
	}
	int sizeOfOutputLayer = m_Layers[layersCount-1]->getNeuronsCount();
	for(int i = 0 ; i < sizeOfOutputLayer; i++)
	{
		output.push_back(m_Layers[layersCount-1]->getNuronAt(i)->m_Value);
	}

	return indexOfMax(output);//strategy for voting.
}

void NeuralNetworkCalssifier:: loadWieghts(vector<vector<float>> weightVectors)
{
	int count = weightVectors.size();
	int weightsCount , c = 1 ;

	//for each weight vector.
	for (int i = 0 ; i < count ; i++)
	{
		m_Layers[c]->setWeights(weightVectors[i]);
		c++;
	}
}

void NeuralNetworkCalssifier::initNeuralNetwork( vector<int> NeuronsPerLayer )
{
	int NumberOfLayers = NeuronsPerLayer.size();

	//init layers starting from the input layer.
	for (int i = 0 ; i < NumberOfLayers ; i++)
	{
		m_Layers.push_back(std::shared_ptr<Layer>(new Layer(NeuronsPerLayer[i])));
	}
}

NeuralNetworkCalssifier::~NeuralNetworkCalssifier()
{

}