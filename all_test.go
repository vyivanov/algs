package algs

import (
	"math/rand"
	"sort"
	"testing"
)

func Test_InsertionSort(t *testing.T) {
	const max_iterations = 32
	const max_hand_size = 64
	rand.Seed(27)
	for i := 0; i < max_iterations; i++ {
		hand_size := rand.Intn(max_hand_size)
		hand := make([]int, hand_size)
		for k := 0; k < hand_size; k++ {
			hand[k] = rand.Int()
		}
		insertion_sort(hand)
		if false == sort.IntsAreSorted(hand) {
			t.Error("Slice is not sorted on iteration", i)
		}
	}
}
