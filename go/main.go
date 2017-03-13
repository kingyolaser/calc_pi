package main

import (
	"./longfrac"
	//"fmt"
)

func main() {
	var x1, x2 longfrac.LongFrac
	x1 = longfrac.Arccot(5)
	x1.Mul(16)

	x2 = longfrac.Arccot(239)
	x2.Mul(4)
	x1.Sub(x2)
	x1.Print()
}
