#include <iostream>
#include <fstream>
#include "NeuralNetwork.h"
#include <time.h>
#include <omp.h>
#include "FileReader.h"
using namespace std;


float* loadArrayFromFile(char* fileName, int numberOfLines)
{
	ifstream myReadFile;
	myReadFile.open(fileName);
	char output[100];
	float* out= new float [numberOfLines];
	if (myReadFile.is_open()) 
	{
		for(int i = 0 ; i < numberOfLines ; i++) 
		{
			myReadFile >> output;
			out[i] = atof(output);		
		}
	}
	myReadFile.close();

	return out;
}

int main()
{
// 	char buffer[256];
// 	vector<float> line;
// 	vector<vector<float>> data;
// 	vector<vector<float>> desireds;
// 	ifstream myfile ("WriteLines.txt");
// 
// 	for(int k = 0 ; k < 200 ; k ++)
// 	{
// 		for(int j = 0 ; j < 20 ; j++)
// 		{
// 			myfile.getline (buffer,100);
// 			for (int i = 0 ; i < 256 ; i++)
// 			{
// 				if (buffer[i] == '1')
// 					line.push_back(1);
// 				if (buffer[i] == '0')
// 					line.push_back(0);
// 			}
// 		}
// 		data.push_back(line);
// 		line.clear();
// 	}
// 
// 	//
// 	ifstream myfile1 ("desired.txt");
// 	int count = 0;
// 	for(int k = 0 ; k < 200 ; k ++)
// 	{	
// 		myfile1.getline (buffer,100);
// 		for (int i = 0 ; i < 256 ; i++)
// 		{
// 			if (buffer[i] == '1')
// 			{
// 				line.push_back(1);
// 				count ++;
// 			}
// 			if (buffer[i] == '0')
// 			{
// 				line.push_back(0);
// 				count++;
// 			}
// 			if (count == 4)
// 			{
// 				count = 0; 
// 				break;
// 			}
// 		}
// 		desireds.push_back(line);
// 		line.clear();
// 	}	
// 
// 
// 	//------------------------------------------------------------------------------------------
// 	float* input = new float [400];
// 	int o = 0; 
// 	for (int i = 0 ; i < 400 ; i++)
// 	{
// 		input [i] = data [4][i];		
// 	}
// 	//load weights
// 	float* output = loadArrayFromFile("output.txt",40);
// 	float* hidden = loadArrayFromFile("hidden.txt",4000);
// 	vector<float*> temp;
// 	temp.push_back(hidden);
// 	temp.push_back(output);
// 
// 
// 	NeuralNetworkCalssifier obj;
// 	int* n = new int[3];
// 	//layers set......
// 	n[0] = 400;
// 	n[1]= 10; 
// 	n[2]= 4;
// 	//init.....
// 	obj.NeuralNetworkinit(input,3,n);
// 	obj.loadWieghts(temp);
// 
// 	float* ff = new float [400];
// 	for (int i = 0 ; i < 400 ; i++)
// 	{
// 		ff [i] = data [6][i];	
// 	}
// 	int gg = obj.classify(ff);


	NeuralNetworkCalssifier f ("C://Users//Muhammad Samir//Desktop//test.txt");
	return 0;
}