#include "Sigmoid.h"
#include "math.h"

float Sigmoid::sigmoid(float value)
{
	float temp = 0 ; 
	temp = 1/(1 + exp(value * -1 * Sigmoid::alpha));
	return temp;
}

float Sigmoid::Derevative(float value)
{
	float t = Sigmoid::sigmoid(value);
	float t1 = (alpha * t *(1 - t));
	return t1 ;
}