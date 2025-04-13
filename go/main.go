package main

import (
	"fmt"

	"github.com/Tetsu-is/neet-code.git/two_pointers"
)

func main() {
	in := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	sol := Solution{}
	out := sol.MaxArea(in)

	fmt.Println("out: ", out)
}

type Solution struct {
}

func (s *Solution) ThreeSum(nums []int) [][]int {
	return two_pointers.ThreeSum(nums)
}

func (s *Solution) MaxArea(heights []int) int {
	return two_pointers.MaxArea(heights)
}
