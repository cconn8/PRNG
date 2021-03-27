/*
 * PRNG.h
 *
 *  Created on: 27 Mar 2021
 *      Author: colm
 */

#ifndef PRNG_H_
#define PRNG_H_

class PRNG {
private:

	long long int testRange;
	long long int m;							//modulus
	long long int a;								//multiplier
	int c;								//increment
	int seed;							//x0 seed
	long long int sequence[10000];
	long long int binary[10000];

public:
	PRNG(long long int m, long long int a, int c, int seed, long long int testRange);
	virtual void lcg();
	virtual long long int loop(long long int seqVal, long long int sequence[], int inc);
	virtual void repeatTest(long long int sequence[]);
	virtual ~PRNG();

};



#endif /* PRNG_H_ */
