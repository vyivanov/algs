package algs

/* Reference: "Introduction to algorithms", The MIT Press, p.18 */
func insertion_sort(hand []int) {
	for i := 1; i < len(hand); i++ {
		// Loop invariant: sub-hand [0..i-1] is already sorted before each iteration.
		key := hand[i]
		k := i - 1
		for k >= 0 && hand[k] > key {
			hand[k+1] = hand[k]
			k -= 1
		}
		hand[k+1] = key
	}
}
