* 给出一个区间的集合，请合并所有重叠的区间。

先根据每个区间的左端元素排序，然后创建结果数组，监控结果数组的最后一组范围，遍历所有区间，根据其左端元素判断是否发生融合，若融合则根据右端元素与结果数组末尾的大小，判断哪个更大。