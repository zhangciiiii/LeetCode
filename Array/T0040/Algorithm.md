* 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。

也是搜索回溯的算法，但是注意每个元素只能使用一次，所以每次DFS迭代时候，begin的元素是当前位置的下一个。
为了避免出现重复解法，需要按一定顺序进行搜索。首先得对candidates元素进行排序，然后在每次进入DFS迭代时，判断当前元素是否和前面重合，以避免多次查找