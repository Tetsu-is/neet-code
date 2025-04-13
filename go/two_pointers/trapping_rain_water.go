package two_pointers

func trap(height []int) int {
	// declare variables
	n := len(height)
	sum := 0
	prefix := make([]int, n)
	suffix := make([]int, n)

	// initialize
	prefix[0] = height[0]
	suffix[n-1] = height[n-1]

	// set prefix and suffix
	for i := 1; i < n; i++ {
		if prefix[i-1] <= height[i-1] {
			prefix[i] = height[i-1]
		} else {
			prefix[i] = prefix[i-1]
		}

		j := n - i - 1
		if suffix[j+1] <= height[j+1] {
			suffix[j] = height[j+1]
		} else {
			suffix[j] = suffix[j+1]
		}
	}

	// calculate
	for i := 0; i < n; i++ {
		if prefix[i] <= suffix[i] {
			val := prefix[i] - height[i]
			if val > 0 {
				sum += val
			}
		} else {
			val := suffix[i] - height[i]
			if val > 0 {
				sum += val
			}
		}
	}

	return sum
}

func Trap(height []int) int {
	return trap(height)
}
