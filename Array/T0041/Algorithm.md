* 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

难点在于时间复杂度和空间复杂度的限制。排序的话时间复杂度至少是O(N logN)，想到创建哈希表，这样查找时间只要O(1)，但是额外创建哈希表所需空间是O(N)，因此考虑直接在原数组上操作：
先遍历一遍数组，将所有范围在(1,N)以外对数全部标记为 N+1，这样索引时不会越界。然后第二遍遍历时，将每个元素所对应于数组位置上的元素标记负号（若已经就是负号就不用加了），最后再遍历一次，找到还是正数的位置，其对应的元素就是最小正整数。