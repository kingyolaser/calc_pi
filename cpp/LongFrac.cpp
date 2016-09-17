
#include <string.h>
#include "LongFrac.h"

void LongFrac::init()
{
	memset(data, 0, sizeof(data));
}

void LongFrac::operator+=(const LongFrac& x)
{
    for( int i=LF_MAXINDEX-1; i>0; i-- ){
        data[i] += x.data[i];
        if( data[i] >= LF_UNIT ){
            data[i] -= LF_UNIT;
            data[i-1] ++;
        }
    }
    
    data[0] += x.data[0];
    //繰り上がり処理はしない
}
