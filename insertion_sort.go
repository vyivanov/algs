package algs

func insertion_sort(hand []int) {
	for i := 1; i < len(hand); i++ {
		key := hand[i]
		j := i - 1
		for j >= 0 && hand[j] > key {
			hand[j+1] = hand[j]
			j -= 1
		}
		hand[j+1] = key
	}
}
