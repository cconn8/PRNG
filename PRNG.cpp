//============================================================================
// Name        : PRNG.cpp
// Author      : Colm Conneely
// Date		   : 24 Mar 2021
// Version     :
// Copyright   : Your copyright notice
// Description : Implementation of Pseudorandom Number Generator
/*				The required inputs to implement a Linear Congruential Generator (LCG) are as follows:
 * 				m 	the modulus		0 < m
 * 				a	multiplier		0 < a < m
 * 				c	increment		0 <= c < m
 * 				x0	seed			0 <= x0 < m
 *
 *	Test using a=7^5 (16807), c=0, m =(2^31 - 1)
 */

//============================================================================

#include <iostream>
#include <cmath>
#include <math.h>

#include "PRNG.h"

using namespace std;

PRNG::PRNG(long long int m, long long int a, int c, int seed, long long int testRange){


	cout<<"Starting Linear Congruential Generator..\n"<<endl;

	this->testRange = testRange;
	this->m = m;							//modulus
	this->a = a;							//multiplier
	this->c = c;							//increment
	this->seed = seed;						//x0 seed

	cout<<"Input Values: \nm = " << m << "\na = "<< a << "\nc = " << c << " \nx[0] = " << seed << "\nTest Range = " << testRange <<"\n"<< endl;

	lcg();

}



void PRNG::lcg(){

	cout<<"Starting lcg!"<<endl;
	sequence[0] = seed;		//set first value to seed

	cout<<"Number Value: ";

	for(long long int i=0; i < testRange; i++){
		sequence[i+1] = (a * sequence[i] + c) % m;
		binary[i] = (int)sequence[i] % 2;
//		cout<< x[i] << " ";
	}

	cout<<"\nBinary Value: ";

//	for(int i=0; i< testRange; i++){
//		cout<<binary[i] << " ";
//	}

	repeatTest(sequence);

}

long long int PRNG::loop(long long int seqVal, long long int sequence[], int inc){

	for(long long int i=0; i<inc; i++){
		if(seqVal == sequence[i]){
			return seqVal;
		}
	}
	return -1;
}

void PRNG::repeatTest(long long int sequence[]){
	int counter = 0;
	int periodCounter = 0;
	int period = 0;

	cout<<"\n\nTesting for Period and Repeat values"<<endl;

	for(int i=0; i<50; i++){
		if(sequence[i] == loop(sequence[i], sequence, i)){  //sequence[i] is value, sequence is full array, i is the current index
			counter++;

			if(periodCounter == 0){
				period = i;
				periodCounter++;
			}
//			cout<<"Value [" << sequence[i] <<"] repeats at index i = " << i <<endl;
		}
	}

	cout<<"\nNumber of repeats: "<< counter << "\nPeriod: "<< period <<endl;
}

PRNG::~PRNG(){
	cout<<"Programme ended - memory released!"<<endl;
}

int main() {

	long long int m = 58;							//modulus
	long long int a = 53;							//multiplier
	int c = 0;								//increment
	int seed = 1;							//x0 seed
	long long int testRange = m;

	PRNG test(m,a,c,seed, testRange);


	return 0;
}
