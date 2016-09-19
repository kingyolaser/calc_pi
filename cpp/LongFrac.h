
#ifndef LONG_FRAC_H
#define LONG_FRAC_H

#include <inttypes.h>

#define  LF_UNIT     1000000000LL
#define  LF_UNIT_KETA 9
#define  LF_MAXINDEX 10

class LongFrac {
public:
	LongFrac(){init();}
	LongFrac(unsigned int x){init(); data[0]=x;}
	LongFrac(const LongFrac &x);
	~LongFrac(){}

	void operator=(const LongFrac& x);
	void operator+=(const LongFrac& x);
	void operator-=(const LongFrac& x);
	void operator*=(const int x);
	void operator/=(const int x);
	
	
	friend LongFrac atan_inverse(int x);
	
	void print();
	
private:
	void init();
	int64_t  data[LF_MAXINDEX];
};

LongFrac atan_inverse(int x);

#endif //LONG_FRAC_H
