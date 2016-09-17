#include <inttypes.h>

#define  LF_UNIT     1000000000
#define  LF_MAXINDEX 10

class LongFrac {
public:
	LongFrac(){init();}
	LongFrac(unsigned int x){init(); data[0]=x;}
	~LongFrac(){}

	void operator+=(const LongFrac& x);
	
	void print();
	
private:
	void init();
	uint64_t  data[LF_MAXINDEX];
};
