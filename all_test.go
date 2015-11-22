package algs

import (
	"sort"
	"testing"
)

func Test_InsertionSort(t *testing.T) {
	hand := []int{6, 3, 82, 34, 56, -4}
	insertion_sort(hand)
	if false == sort.IntsAreSorted(hand) {
		t.Error("Slice is not sorted:", hand)
	}
}
