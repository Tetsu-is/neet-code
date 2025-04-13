package main

import (
	"fmt"

	"github.com/Tetsu-is/neet-code.git/two_pointers"
)

func main() {
	in := []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
	sol := Solution{}
	out := sol.Trap(in)
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

func (s *Solution) Trap(height []int) int {
	return two_pointers.Trap(height)
}
