#include <inttypes.h>

#define  LF_UNIT     1000000000
#define  LF_MAXINDEX 10

class LongFrac {
	LongFrac(){}
	~LongFrac(){}

	void operator+=(const LongFrac& x);
private:
	uint64_t  data[LF_MAXINDEX];
};
