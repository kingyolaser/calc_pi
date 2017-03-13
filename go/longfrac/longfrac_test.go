package longfrac

import "testing"

func TestDiv(t *testing.T) {
	//var x LongFrac
	x := LongFrac{data: [MaxIndex]int64{0}}

	x.AddInt(2)
	if x.data[0] != 2 {
		t.Errorf("%d != %d", 2, x.data[0])
	}

	x.Div(3)
	if x.data[0] != 0 {
		t.Errorf("%d != %d", 0, x.data[0])
	}
	if x.data[1] != 666666666 {
		t.Errorf("%d != %d", 666666666, x.data[1])
	}

	var y LongFrac
	y.AddInt(5)
}
