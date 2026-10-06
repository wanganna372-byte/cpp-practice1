# C++ 算法与矩阵运算练习

本项目包含binary-search、merge-sort、maximum-return和matrix的 C++ 实现。
每个程序都包含测试，运行后会输出 PASS 或 FAIL。

## GitHub 小项目

仓库链接：https://github.com/wanganna372-byte/cpp-practice1

## 文件说明

- `binary-search.cpp`：在升序数组中查找目标值，返回下标；找不到时返回 -1。
- `merge-sort.cpp`：使用归并排序将数组按升序排列。
- `maximum-return.cpp`：使用分治法计算一次买卖的最大收益，必须先买后卖；收益可以为负数。
- `matrix/matrix.hpp`：声明 Matrix 类。
- `matrix/matrix.cpp`：实现矩阵加法、乘法和格式化输出。
- `matrix/main.cpp`：测试矩阵运算及维度检查。

## 编译环境

需要支持 C++11 的 g++ 编译器。

以下命令在 Bash 终端中执行，起始目录为仓库根目录。

## 编译与运行

### binary-search

```bash
g++ -std=c++11 binary-search.cpp -o binary-search
./binary-search
```

### merge-sort

```bash
g++ -std=c++11 merge-sort.cpp -o merge-sort
./merge-sort
```

### maximum-return

```bash
g++ -std=c++11 maximum-return.cpp -o maximum-return
./maximum-return
```

### matrix（在LINUX/WSL的bash中）

```bash
cd matrix
g++ -std=c++11 main.cpp matrix.cpp
./matrix-demo
```

## 实现思路

### binary-search

比较目标值与搜索区间的中间元素，每次缩小一半搜索范围。
时间复杂度为 O(log n)。

###  merge-sort

递归排序左右两个子区间，再通过临时数组合并有序结果。
时间复杂度为 O(n log n)。

### maximum-return

先计算相邻价格的变化量，再寻找最大非空子数组和。
分治时分别计算左侧、右侧和跨越中点的最优结果。
时间复杂度为 O(n log n)。

###  matrix

加法对相同位置的元素求和，要求两个矩阵维度相同。
乘法使用“行乘列”的方式计算，要求左矩阵列数等于右矩阵行数。
维度不符合要求时抛出 std::invalid_argument 异常。

## 测试结果

## 测试结果

- binary-search：正常查找、目标不存在及边界测试均通过。
-  merge-sort：空数组、单元素、重复元素、正序和逆序测试均通过。
- maximum-return：一般价格序列、递增、递减及两个价格的测试均通过。
-  matrix：加法、乘法、加零矩阵及非方阵乘法测试均通过；维度不匹配时正确抛出异常。

## AI 使用说明

使用工具：Chatgpt。

AI 辅助写readme。
