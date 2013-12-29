#ifndef LAYER_H
#define LAYER_H
#include <vector>
using namespace std;

class Neuron;

class Layer
{
public:

	Layer (int fNumOfNeurons);
	void forward();
	void setLayerNeuronsValues(vector<float>& fValues);
	vector<float> getNeuronsValues();
	void setLayerweightsValues( vector<float>& fValues);
	void setLayerWieghtAt(int index,float value);
	int  getNeuronsCount();
	void setWeights(vector<float>& fWeights);
	int  getWeightsCount();
	void setPreviousLayerNeuronsValues(vector<float>& vlaues);
	void setPreviousLayerNeuronValueAt(int index,float value);
	std::shared_ptr<Neuron> getNuronAt(int index);

private:
	 vector<std::shared_ptr<Neuron>>  m_Neurons;
	 vector<float> m_PreviousLayerValues;
	 vector<float> m_Weights;
};
#endif