package two_pointers

import (
	"sort"
)

func threeSumPrev(nums []int) [][]int {
	sort.Ints(nums)
	result := [][]int{}
	n := len(nums)
	const target int = 0

	for i := 0; i < n-2; i++ {
		// iの重複をスキップ
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		left := i + 1
		right := n - 1
		for left < right {
			sum := nums[i] + nums[left] + nums[right]
			if sum < 0 {
				left++
			} else if sum > 0 {
				right--
			} else {
				result = append(result, []int{nums[i], nums[left], nums[right]})
				// leftとrightの重複をスキップ
				for left < right && nums[left] == nums[left+1] {
					left++
				}
				for left < right && nums[right] == nums[right-1] {
					right--
				}
				left++
				right--
			}
		}
	}

	return result
}

func threeSum(nums []int) [][]int {
	// prep
	target := 0
	complement_idx := make(map[int]int)
	result := [][]int{}

	// process
	for i := 0; i < len(nums)-1; i++ {
		var new_target = target - nums[i]
		// skip

		for j := i + 1; j < len(nums); j++ {
			_, exists := complement_idx[nums[i]]
			if exists {
				tmp := []int{nums[i], nums[j], nums[complement_idx[nums[i]]]}
				sort.Ints(tmp)
				result = append(result, tmp)
				continue
			}
			complement_idx[new_target-nums[j]] = j
		}

	}

	return result
}

func ThreeSum(nums []int) [][]int {
	return threeSum(nums)
}
