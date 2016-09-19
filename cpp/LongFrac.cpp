
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "LongFrac.h"

/****************************************************************************/
LongFrac::LongFrac(const LongFrac &x)
{
	memcpy(data, x.data, sizeof(data));
}
/****************************************************************************/
void LongFrac::init()
{
	memset(data, 0, sizeof(data));
}

/****************************************************************************/
void LongFrac::operator=(const LongFrac& x)
{
	memcpy(data, x.data, sizeof(data));
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
void LongFrac::operator*=(const int x)
{
	uint32_t kuriagari = 0;
    for( int i=LF_MAXINDEX-1; i>0; i-- ){
		data[i] *= x;
		data[i] += kuriagari;
		if( data[i] >= LF_UNIT ){
			kuriagari = data[i]/LF_UNIT;
			data[i] -= kuriagari*LF_UNIT;
		}else{
			kuriagari = 0;
		}
	}
	
	data[0] *= x;
	data[0] += kuriagari;
    //繰り上がり処理はしない
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
LongFrac atan_inverse(int div)
{
	LongFrac sum=0;
	LongFrac x=1;
	
	//必要なループ回数を計算
	int max_i = LF_UNIT_KETA*LF_MAXINDEX/log10(div);
	printf("div=%d, max_i=%d\n", div, max_i);
	
	x/=div;
	
	for( int i=1; i<max_i; i+=2 ){
		LongFrac tmp = x;
		tmp /= i;
		if( (i-1)%4 == 0 ){
			sum += tmp;
		}else{
			sum -= tmp;
		}
		x /= div;
		x /= div;
	}
	
	return sum;
}

/****************************************************************************/
void LongFrac::print()
{
	printf("%d.\n",(uint32_t)data[0]);
	
	char buf[80]="";
	int col = 0;
		
	for( int i=1; i<LF_MAXINDEX; i++ ){
		sprintf(buf+strlen(buf), "%09ld", data[i] );
		if( strlen(buf) > 10 ){
			char buf2[11];
			memcpy(buf2, buf, 10);
			buf2[10] = '\0';
			strcpy(buf, buf+10);
			printf("%s ", buf2);
			col ++;
			if( col%7 == 0 ){
				printf("\n");
				col=0;
			}
			
		}
	}
	printf("\n");
}

