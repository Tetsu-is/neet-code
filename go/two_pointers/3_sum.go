package two_pointers

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	const target int = 0
	complementMap := make(map[int][]int)
	avoidDuplicateMap := make(map[string]bool)
	result := [][]int{}

	complementMap[target-nums[0]] = []int{nums[0]}

	// create map
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			n := nums[j]
			value, ok := complementMap[n]
			if ok {
				tmp := []int{n, value[0], value[1]}
				sort.Ints(tmp)
				key := fmt.Sprintf("%d%d%d", tmp[0], tmp[1], tmp[2])
				if avoidDuplicateMap[key] {
					fmt.Printf("duplicate blocked: %d%d%d\n", tmp[0], tmp[1], tmp[2])
					continue
				}
				if tmp[0] == tmp[1] && tmp[1] == tmp[2] {
					fmt.Printf("3 values are same: %d%d%d\n", tmp[0], tmp[1], tmp[2])
					continue
				}

				result = append(result, tmp)
				avoidDuplicateMap[key] = true
			}
			complementMap[target-(nums[i]+nums[j])] = []int{nums[i], nums[j]}
		}
	}

	return result
}

type Solution struct {
}

func (s *Solution) ThreeSum(nums []int) [][]int {
	return threeSum(nums)
}
