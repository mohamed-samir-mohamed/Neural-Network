#include "Layer.h"
#include "Neuron.h"

Layer::Layer(int numOfNeurons)
{
	for (int i = 0 ; i < numOfNeurons ; i++)
	{
		m_Neurons.push_back(std::shared_ptr<Neuron>(new Neuron()));
	}	
}

void Layer::forward()
{	
	try
	{
		int weightPerNeuron = m_Weights.size() / m_Neurons.size(), inc = 0;
		int size = m_Neurons.size();
		for (int i = 0 ; i < size ; i++)
		{
			for (int j = 0 ; j < weightPerNeuron ; j++)
			{
				m_Neurons[i]->m_Netk += m_Weights[inc] * m_PreviousLayerValues[j];
				inc ++;
			}
			m_Neurons[i]->m_Value = (  1 / (1 + exp(  (-1 * m_Neurons[i]->m_Netk)  )));
		}	
	}
	catch(exception & e)
	{
		//log.
	}
}

void Layer ::setLayerNeuronsValues(vector<float>& fValues)
{
	int size = fValues.size();
	for (int i = 0 ; i < size ; i++)
	{
		m_Neurons[i]->m_Value = fValues[i];
	}
}

void Layer::setLayerweightsValues (vector<float>& fValues)
{
	int size = fValues.size();
	for (int i = 0 ; i < size ; i++)
	{
		m_Weights[i] = fValues[i];
	}
}

int Layer::getNeuronsCount()
{
	return m_Neurons.size();
}

int Layer::getWeightsCount()
{
	return m_Weights.size();
}

void Layer::setPreviousLayerNeuronsValues( vector<float>& values )
{
	int size = values.size();
	for (int i = 0; i < size; i++)
		m_PreviousLayerValues.push_back(values[i]);
}

std::shared_ptr<Neuron> Layer::getNuronAt( int index )
{
	try
	{
		return m_Neurons[index];
	}
	catch(exception& e)
	{
		//log.
	}
}

void Layer::setPreviousLayerNeuronValueAt( int index,float value )
{
	try
	{
		m_PreviousLayerValues[index] = value;
	}
	catch(exception& e)
	{
		//log...
	}
}

void Layer::setLayerWieghtAt( int index,float value)
{
	try
	{
		m_Weights[index] = value;
	}
	catch(exception& e)
	{
	}
}

void Layer::setWeights( vector<float>& fWeights )
{
	int size = fWeights.size();
	for(int i = 0; i < size; i++)
	{
		m_Weights.push_back(fWeights.at(i));
	}
}
