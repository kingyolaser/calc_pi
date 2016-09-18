
#include <stdio.h>
#include <string.h>
#include "LongFrac.h"

/****************************************************************************/
void LongFrac::init()
{
	memset(data, 0, sizeof(data));
}

/****************************************************************************/
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
/****************************************************************************/
void LongFrac::operator-=(const LongFrac& x)
{
    for( int i=LF_MAXINDEX-1; i>0; i-- ){
        data[i] -= x.data[i];
        if( data[i] < 0 ){
            data[i] += LF_UNIT;
            data[i-1] --;
        }
    }
    
    data[0] -= x.data[0];
    //繰り下がり処理はしない
}
/****************************************************************************/
void LongFrac::operator/=(const int x)
{
	uint32_t amari =0;
	for( int i=0; i<LF_MAXINDEX; i++ ){
		data[i] += amari*LF_UNIT;
		amari = data[i] % x;
		data[i] /= x;
	}
}

/****************************************************************************/
void LongFrac::print()
{
	printf("%d.\n",(uint32_t)data[0]);
	
	for( int i=1; i<LF_MAXINDEX; i++ ){
		printf("%09d ", (uint32_t)data[i]);
		if( i%5 == 0 ){
			printf("\n");
		}
	}
	printf("\n");
}
