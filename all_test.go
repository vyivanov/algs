package algs

import (
	"sort"
	"testing"
)

func Test_InsertionSort(t *testing.T) {
	// TODO: automate problem instance generation
	problem_instance := []int{6, 3, 82, 34, 56, -4}
	insertion_sort(problem_instance)
	if false == sort.IntsAreSorted(problem_instance) {
		t.Error("Slice is not sorted:", problem_instance)
	}
}
