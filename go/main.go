package main

import (
	"fmt"

	"github.com/Tetsu-is/neet-code.git/two_pointers"
)

func main() {
	in := []int{1, 2, -2, -1}
	exp := [][]int{}
	sol := two_pointers.Solution{}
	out := sol.ThreeSum(in)

	fmt.Println("out: ", out)
	fmt.Println("exp: ", exp)
}
