package main

import (
	"fmt"

	"github.com/Tetsu-is/neet-code.git/two_pointers"
)

func main() {
	in := []int{-2, 0, 1, 1, 2}
	exp := [][]int{{-2, 0, 2}, {-2, 1, 1}}
	sol := two_pointers.Solution{}
	out := sol.ThreeSum(in)

	fmt.Println("out: ", out)
	fmt.Println("exp: ", exp)
}
