package stack

type MinStack struct {
	s   []int
	min []int
}

func Constructor() MinStack {
	return MinStack{
		s:   []int{},
		min: []int{},
	}
}

func (this *MinStack) Push(val int) {
	this.s = append(this.s, val)

	var v int
	if len(this.min) == 0 || val < this.min[len(this.min)-1] {
		v = val
	} else {
		v = this.min[len(this.min)-1]
	}
	this.min = append(this.min, v)
}

func (this *MinStack) Pop() {
	this.s = this.s[:len(this.s)-1]
	this.min = this.min[:len(this.min)-1]
}

func (this *MinStack) Top() int {
	return this.s[len(this.s)-1]
}

func (this *MinStack) GetMin() int {
	return this.min[len(this.min)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
