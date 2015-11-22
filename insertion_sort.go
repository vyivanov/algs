package algs

/* Reference: "Introduction to algorithms", The MIT Press, p.18 */
func insertion_sort(hand []int) {
	for i := 1; i < len(hand); i++ {
		// Loop invariant: sub-hand [0..i-1] is already sorted before each iteration.
		key := hand[i]
		j := i - 1
		for j >= 0 && hand[j] > key {
			hand[j+1] = hand[j]
			j -= 1
		}
		hand[j+1] = key
	}
}
