package main

import (
	"github.com/Tetsu-is/neet-code.git/stack"
	"github.com/Tetsu-is/neet-code.git/two_pointers"
)

func main() {
	ms := stack.Constructor()
	ms.Push(-2)
	ms.Push(0)
	ms.Push(-3)
	println(ms.GetMin()) // return -3
	ms.Pop()
	println(ms.Top())    // return 0
	println(ms.GetMin()) // return -2
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
