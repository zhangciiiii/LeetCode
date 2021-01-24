* 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

首先想到了一层层去遍历，检测到两端高的边后计算中间空白的格子，结果是对的，但是时间复杂度是O(N^2)。直接超时了。

看答案的方法，首先也是暴力法，但是是对每一个元素，依次向其左边和右边搜索最高对左边和右边，然后向答案加上较短边减去元素的高度。这样做时间复杂度也是O(N^2)

优化方法是：动态编程：
我们注意到，解法二中。对于每一列，我们求它左边最高的墙和右边最高的墙，都是重新遍历一遍所有高度，这里我们可以优化一下。
首先用两个数组，max_left [i] 代表第 i 列左边最高的墙的高度，max_right[i] 代表第 i 列右边最高的墙的高度。这样在求每个元素的左右最高墙时就不用每次都遍历一次了。

第二种思路是栈，遍历元素，并将元素的坐标依次入栈，栈满足从栈顶向下是依次增大的，不满足则出栈。出栈时，根据元素对应的坐标可以确定围成矩形的宽(在每次弹出栈的时候操作计算)，根据元素的值可以确定矩形的高