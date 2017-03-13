package longfrac

import "fmt"

const (
	Unit     = 1000000000
	MaxIndex = 10
)

type LongFrac struct {
	data [MaxIndex]int64
}

/************************************************************************/
func (x *LongFrac) Print() {
	fmt.Printf("%d.\n", x.data[0])
	for i := 1; i < MaxIndex; i++ {
		fmt.Printf("%09d ", x.data[i])
		if i%7 == 0 {
			fmt.Println("")
		}
	}
	fmt.Println("")
}

/************************************************************************/
func (x *LongFrac) AddInt(y int64) {
	x.data[0] += y
}

/************************************************************************/
func (x *LongFrac) Add(y LongFrac) {
	var kuriagari int64
	for i := MaxIndex - 1; i >= 0; i-- {
		x.data[i] += y.data[i] + kuriagari
		kuriagari = x.data[i] / Unit
		x.data[i] %= Unit

	}
}

/************************************************************************/
func (x *LongFrac) Sub(y LongFrac) {
	var kurisagari int64
	for i := MaxIndex - 1; i >= 0; i-- {
		x.data[i] -= y.data[i]
		x.data[i] -= kurisagari
		if x.data[i] < 0 {
			x.data[i] += Unit
			kurisagari = 1
		} else {
			kurisagari = 0
		}
	}
}

/************************************************************************/
func (x *LongFrac) Mul(y int64) {
	var kuriagari int64
	for i := MaxIndex - 1; i >= 0; i-- {
		x.data[i] *= y
		x.data[i] += kuriagari

		kuriagari = x.data[i] / Unit
		x.data[i] %= Unit
	}

}

/************************************************************************/
func (x *LongFrac) Div(y int64) {
	var amari int64
	for i := 0; i < MaxIndex; i++ {
		x.data[i] += amari * Unit
		amari = x.data[i] % y
		x.data[i] /= y
	}
}

/************************************************************************/
func Arccot(z int64) LongFrac {
	var (
		ret, x, y LongFrac
	)

	x.AddInt(1) //第１項
	x.Div(z)
	ret.Add(x)

	for i := int64(3); i < 100; i += 4 {
		x.Div(z)
		x.Div(z)
		y = x
		y.Div(i)
		ret.Sub(y)
		//ret.Print()

		x.Div(z)
		x.Div(z)
		y = x
		y.Div(i + 2)
		ret.Add(y)
		//ret.Print()
	}

	return ret
}
