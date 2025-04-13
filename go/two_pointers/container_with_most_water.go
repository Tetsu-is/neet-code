package two_pointers

func maxArea(heights []int) int {
	n := len(heights)
	left := 0
	right := n - 1
	max := 0

	for left < right {
		if heights[left] < heights[right] {
			min := heights[left]
			value := (right - left) * min
			if value > max {
				max = value
			}
			left++
		} else {
			min := heights[right]
			value := (right - left) * min
			if value > max {
				max = value
			}
			right--
		}
	}

	return max
}

func MaxArea(heights []int) int {
	return maxArea(heights)
}
