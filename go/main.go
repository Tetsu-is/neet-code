package main

import (
	"fmt"

	"github.com/Tetsu-is/neet-code.git/stack"
	"github.com/Tetsu-is/neet-code.git/two_pointers"
)

func main() {
	in := "([])"
	sol := Solution{}
	out := sol.isValid(in)
	fmt.Println("out: ", out)
}

type Solution struct {
}

func (s *Solution) threeSum(nums []int) [][]int {
	return two_pointers.ThreeSum(nums)
}

func (s *Solution) maxArea(heights []int) int {
	return two_pointers.MaxArea(heights)
}

func (s *Solution) trap(height []int) int {
	return two_pointers.Trap(height)
}

func (sol *Solution) isValid(s string) bool {
	return stack.IsValid(s)
}
