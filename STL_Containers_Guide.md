# STL 容器完整学习指南

## 目录
1. [序列容器](#序列容器)
2. [关联容器](#关联容器)
3. [容器适配器](#容器适配器)
4. [容器选择指南](#容器选择指南)

---

## 序列容器

### 1. Vector（动态数组）

**特点：**
- 动态数组，内存连续
- 支持快速随机访问 O(1)
- 尾部插入删除快 O(1)，中间插入删除慢 O(n)
- 自动扩容（容量不足时重新分配内存）

**常用操作：**
```cpp
vector<int> vec;
vec.push_back(10);      // 尾部添加
vec.pop_back();         // 尾部删除
vec[0];                 // 下标访问
vec.at(0);             // 带边界检查的访问
vec.size();            // 元素个数
vec.capacity();        // 容量
vec.empty();           // 是否为空
vec.clear();           // 清空
vec.insert(it, val);   // 插入
vec.erase(it);         // 删除
vec.front();           // 第一个元素
vec.back();            // 最后元素
```

**适用场景：**
- 需要频繁随机访问
- 主要在尾部插入删除
- 需要动态数组

---

### 2. List（双向链表）

**特点：**
- 双向链表，内存不连续
- 不支持随机访问
- 任意位置插入删除快 O(1)
- 不需要连续内存空间

**常用操作：**
```cpp
list<int> lst;
lst.push_back(10);     // 尾部添加
lst.push_front(5);     // 头部添加
lst.pop_back();        // 尾部删除
lst.pop_front();       // 头部删除
lst.insert(it, val);   // 插入
lst.erase(it);         // 删除
lst.remove(val);       // 删除所有值为val的元素
lst.sort();            // 排序
lst.reverse();         // 反转
lst.unique();          // 去重（需先排序）
lst.front();           // 第一个元素
lst.back();            // 最后元素
```

**适用场景：**
- 频繁在中间位置插入删除
- 不需要随机访问
- 数据量不确定

---

### 3. Deque（双端队列）

**特点：**
- 双端队列
- 支持快速随机访问 O(1)
- 头尾插入删除都快 O(1)
- 内存分段连续（多个固定大小的数组）

**常用操作：**
```cpp
deque<int> dq;
dq.push_back(10);      // 尾部添加
dq.push_front(5);      // 头部添加
dq.pop_back();         // 尾部删除
dq.pop_front();        // 头部删除
dq[0];                 // 随机访问
dq.at(0);              // 带检查的访问
dq.front();            // 第一个元素
dq.back();             // 最后元素
```

**适用场景：**
- 需要在两端频繁插入删除
- 需要随机访问
- 作为queue和stack的底层容器

---

## 关联容器

### 4. Set（集合）

**特点：**
- 元素自动排序（默认升序）
- 元素唯一，不允许重复
- 底层是红黑树
- 查找效率 O(log n)

**常用操作：**
```cpp
set<int> s;
s.insert(10);          // 插入
s.erase(10);           // 删除
s.find(10);            // 查找，返回迭代器
s.count(10);           // 统计个数（0或1）
s.size();              // 元素个数
s.empty();             // 是否为空
s.clear();             // 清空
```

**适用场景：**
- 需要自动排序
- 需要去重
- 频繁查找元素

---

### 5. Multiset（多重集合）

**特点：**
- 与set类似
- 允许元素重复
- 自动排序

**常用操作：**
```cpp
multiset<int> ms;
ms.insert(10);         // 可插入重复元素
ms.count(10);          // 统计元素个数
ms.erase(10);          // 删除所有值为10的元素
```

**适用场景：**
- 需要排序且允许重复
- 统计元素出现次数

---

### 6. Map（映射/字典）

**特点：**
- 键值对存储（key-value）
- key唯一，自动按key排序
- 底层是红黑树
- 查找效率 O(log n)

**常用操作：**
```cpp
map<string, int> m;
m["key"] = 100;        // 插入/修改
m.insert(make_pair("k", 10));  // 插入
m.erase("key");        // 删除
m.find("key");         // 查找
m.count("key");        // 是否存在（0或1）
m.size();              // 元素个数
```

**适用场景：**
- 需要键值对存储
- 需要按key排序
- 快速查找value

---

### 7. Multimap（多重映射）

**特点：**
- 与map类似
- 允许key重复
- 不支持[]操作符

**常用操作：**
```cpp
multimap<string, int> mm;
mm.insert(make_pair("k", 10));
mm.count("k");         // 统计key的个数
```

**适用场景：**
- 一个key对应多个value
- 需要按key排序

---

## 容器适配器

### 8. Stack（栈）

**特点：**
- 后进先出（LIFO）
- 基于deque实现（也可用vector或list）
- 只能访问栈顶元素

**常用操作：**
```cpp
stack<int> stk;
stk.push(10);          // 压栈
stk.pop();             // 出栈
stk.top();             // 访问栈顶
stk.size();            // 元素个数
stk.empty();           // 是否为空
```

**适用场景：**
- 函数调用栈
- 表达式求值
- 括号匹配

---

### 9. Queue（队列）

**特点：**
- 先进先出（FIFO）
- 基于deque实现
- 只能访问队首和队尾

**常用操作：**
```cpp
queue<int> q;
q.push(10);            // 入队
q.pop();               // 出队
q.front();             // 队首元素
q.back();              // 队尾元素
q.size();              // 元素个数
q.empty();             // 是否为空
```

**适用场景：**
- BFS广度优先搜索
- 任务调度
- 消息队列

---

### 10. Priority_queue（优先队列）

**特点：**
- 优先级队列
- 默认是大顶堆（最大值在堆顶）
- 基于vector实现
- 自动排序

**常用操作：**
```cpp
// 大顶堆（默认）
priority_queue<int> pq;

// 小顶堆
priority_queue<int, vector<int>, greater<int>> minHeap;

pq.push(10);           // 插入
pq.pop();              // 删除堆顶
pq.top();              // 访问堆顶
pq.size();             // 元素个数
pq.empty();            // 是否为空
```

**适用场景：**
- 需要动态获取最大/最小值
- 堆排序
- Dijkstra算法
- 哈夫曼编码

---

## 容器选择指南

### 按访问方式选择

| 需求 | 推荐容器 |
|------|---------|
| 随机访问 | vector, deque |
| 顺序访问 | list, forward_list |
| 键值访问 | map, unordered_map |

### 按插入删除位置选择

| 位置 | 推荐容器 |
|------|---------|
| 尾部 | vector |
| 头部和尾部 | deque, list |
| 中间 | list |

### 按排序需求选择

| 需求 | 推荐容器 |
|------|---------|
| 自动排序 | set, map, multiset, multimap |
| 手动排序 | vector, deque |
| 不需排序 | unordered_set, unordered_map |

### 按查找效率选择

| 效率要求 | 推荐容器 |
|----------|---------|
| O(1) 哈希查找 | unordered_set, unordered_map |
| O(log n) 二叉树查找 | set, map |
| O(n) 线性查找 | vector, list |

### 性能对比表

| 容器 | 随机访问 | 头部插入 | 尾部插入 | 中间插入 | 查找 |
|------|---------|---------|---------|---------|------|
| vector | O(1) | O(n) | O(1)* | O(n) | O(n) |
| list | - | O(1) | O(1) | O(1) | O(n) |
| deque | O(1) | O(1) | O(1) | O(n) | O(n) |
| set | - | - | - | O(log n) | O(log n) |
| map | - | - | - | O(log n) | O(log n) |

*摊销时间复杂度

---

## 常用STL算法

```cpp
#include <algorithm>

// 排序
sort(vec.begin(), vec.end());                    // 升序
sort(vec.begin(), vec.end(), greater<int>());    // 降序

// 查找
find(vec.begin(), vec.end(), value);             // 查找元素
binary_search(vec.begin(), vec.end(), value);    // 二分查找（需已排序）

// 反转
reverse(vec.begin(), vec.end());

// 最大最小值
max_element(vec.begin(), vec.end());
min_element(vec.begin(), vec.end());

// 统计
count(vec.begin(), vec.end(), value);

// 去重（需先排序）
sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());
```

---

## 迭代器类型

1. **输入迭代器**：只读，只能前进
2. **输出迭代器**：只写，只能前进
3. **前向迭代器**：可读写，只能前进（forward_list）
4. **双向迭代器**：可读写，可前进后退（list, set, map）
5. **随机访问迭代器**：可读写，可随机跳转（vector, deque）

---

## 总结

- **需要频繁随机访问** → vector
- **需要频繁头尾操作** → deque
- **需要频繁中间插入删除** → list
- **需要自动排序且元素唯一** → set
- **需要键值对且自动排序** → map
- **需要后进先出** → stack
- **需要先进先出** → queue
- **需要动态获取最值** → priority_queue
