LCA(least common ancestors) 最近公共祖先
//各种求法详见HDU 2586 题解

//LCA求法总结
1.树链剖分 时间复杂度 O(n) + q*O(logn) 空间复杂度O(n)  适用于查询小空间紧 优先使用
2.ST在线 时间复杂度 预处理O(n*logn)/O(n)[+-1RMQ]     查询O(1) 适用于海量查询 空间O(n^2)
3.tarjan离线算法 时间复杂度 O(n + Q) 查询O(1) 空间巨大 要保存完整的查找树 明确离线查询且空间足够最好必用
4.doubly 算法查询时间复杂度为O(logn) 空间复杂度为O(n*logn) 复杂度垃圾很稳定不建议日常使用
5.笛卡尔树+LCA 建树O(n) +-1RMQ预处理O(n) 查询 O(1) 空间O(5n) 前提是会不依赖LCA的RMQ 然而并不会
