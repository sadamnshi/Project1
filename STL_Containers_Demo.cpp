/*
 * STL容器学习代码示例
 * 涵盖常用的STL容器：vector, list, deque, set, map, stack, queue等
 */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// ============================================================
// 1. VECTOR - 动态数组容器
// ============================================================
void vectorDemo() {
    cout << "\n========== VECTOR 容器演示 ==========" << endl;
    
    // 创建vector
    vector<int> vec;
    
    // 添加元素 - push_back在末尾添加
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    cout << "Vector元素: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";  // 支持下标访问
    }
    cout << endl;
    
    // 使用迭代器遍历
    cout << "使用迭代器遍历: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 常用操作
    cout << "大小: " << vec.size() << endl;
    cout << "容量: " << vec.capacity() << endl;
    cout << "第一个元素: " << vec.front() << endl;
    cout << "最后元素: " << vec.back() << endl;
    
    // 插入元素
    vec.insert(vec.begin() + 1, 15);  // 在第2个位置插入15
    cout << "插入15后: ";
    for (int val : vec) {  // C++11范围for循环
        cout << val << " ";
    }
    cout << endl;
    
    // 删除元素
    vec.erase(vec.begin());  // 删除第一个元素
    vec.pop_back();  // 删除最后一个元素
    
    // 清空和判空
    cout << "是否为空: " << (vec.empty() ? "是" : "否") << endl;
    vec.clear();
    cout << "清空后是否为空: " << (vec.empty() ? "是" : "否") << endl;
}

// ============================================================
// 2. LIST - 双向链表容器
// ============================================================
void listDemo() {
    cout << "\n========== LIST 容器演示 ==========" << endl;
    
    list<int> lst;
    
    // 添加元素
    lst.push_back(10);    // 尾部添加
    lst.push_back(30);
    lst.push_front(5);    // 头部添加
    lst.push_front(1);
    
    cout << "List元素: ";
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // List不支持随机访问，不能用[]
    // 但支持双向迭代
    lst.push_back(40);
    lst.push_back(20);
    
    // 排序
    lst.sort();  // list有自己的sort成员函数
    cout << "排序后: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // 反转
    lst.reverse();
    cout << "反转后: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // 删除特定值
    lst.remove(10);  // 删除所有值为20的元素
    cout << "删除20后: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // 去重（需要先排序）
    lst.sort();
    lst.unique();
    cout << "去重后: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================================
// 3. DEQUE - 双端队列
// ============================================================
void dequeDemo() {
    cout << "\n========== DEQUE 容器演示 ==========" << endl;
    
    deque<int> dq;
    
    // 双端操作
    dq.push_back(10);     // 尾部添加
    dq.push_back(20);
    dq.push_front(5);     // 头部添加
    dq.push_front(1);
    
    cout << "Deque元素: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";  // 支持随机访问
    }
    cout << endl;
    
    // 访问元素
    cout << "第一个元素: " << dq.front() << endl;
    cout << "最后元素: " << dq.back() << endl;
    cout << "第3个元素: " << dq[2] << endl;
    cout << "at(1): " << dq.at(1) << endl;
    
    // 双端删除
    dq.pop_front();  // 删除头部
    dq.pop_back();   // 删除尾部
    
    cout << "删除首尾后: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================================
// 4. SET - 集合容器（自动排序，元素唯一）
// ============================================================
void setDemo() {
    cout << "\n========== SET 容器演示 ==========" << endl;
    
    set<int> s;
    
    // 插入元素（自动排序，自动去重）
    s.insert(30);
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(30);  // 重复元素不会被插入
    s.insert(40);
    
    cout << "Set元素（自动排序）: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 查找元素
    set<int>::iterator findIt = s.find(30);
    if (findIt != s.end()) {
        cout << "找到元素: " << *findIt << endl;
    }
    
    // 统计元素个数（只能是0或1）
    cout << "30出现次数: " << s.count(30) << endl;
    cout << "100出现次数: " << s.count(100) << endl;
    
    // 删除元素
    s.erase(30);
    cout << "删除30后: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Set大小: " << s.size() << endl;
}

// ============================================================
// 5. MULTISET - 允许重复的集合
// ============================================================
void multisetDemo() {
    cout << "\n========== MULTISET 容器演示 ==========" << endl;
    
    multiset<int> ms;
    
    // 允许插入重复元素
    ms.insert(30);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);
    ms.insert(30);
    
    cout << "Multiset元素: ";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "30出现次数: " << ms.count(30) << endl;
    
    // 删除所有值为30的元素
    ms.erase(30);
    cout << "删除所有30后: ";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================================
// 6. MAP - 键值对容器（key-value）
// ============================================================
void mapDemo() {
    cout << "\n========== MAP 容器演示 ==========" << endl;
    
    map<string, int> m;
    
    // 插入元素的三种方式
    m.insert(pair<string, int>("张三", 85));
    m.insert(make_pair("李四", 92));
    m["王五"] = 78;  // 最简单的方式
    m["赵六"] = 88;
    
    cout << "Map元素（按key排序）:" << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    // 访问元素
    cout << "\n张三的分数: " << m["张三"] << endl;
    
    // 查找
    map<string, int>::iterator findIt = m.find("李四");
    if (findIt != m.end()) {
        cout << "找到李四，分数: " << findIt->second << endl;
    }
    
    // 修改值
    m["王五"] = 95;
    cout << "修改后王五的分数: " << m["王五"] << endl;
    
    // 判断key是否存在
    if (m.count("赵六") > 0) {
        cout << "赵六存在于map中" << endl;
    }
    
    // 删除
    m.erase("赵六");
    cout << "\nMap大小: " << m.size() << endl;
}

// ============================================================
// 7. MULTIMAP - 允许重复key的map
// ============================================================
void multimapDemo() {
    cout << "\n========== MULTIMAP 容器演示 ==========" << endl;
    
    multimap<string, int> mm;
    
    // 允许相同的key
    mm.insert(make_pair("数学", 85));
    mm.insert(make_pair("数学", 92));
    mm.insert(make_pair("英语", 78));
    mm.insert(make_pair("数学", 88));
    
    cout << "Multimap元素:" << endl;
    for (multimap<string, int>::iterator it = mm.begin(); it != mm.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << "\n数学成绩数量: " << mm.count("数学") << endl;
}

// ============================================================
// 8. STACK - 栈容器（后进先出 LIFO）
// ============================================================
void stackDemo() {
    cout << "\n========== STACK 容器演示 ==========" << endl;
    
    stack<int> stk;
    
    // 压栈
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    
    cout << "栈的大小: " << stk.size() << endl;
    cout << "栈顶元素: " << stk.top() << endl;
    
    // 出栈
    cout << "出栈顺序: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
    
    cout << "栈是否为空: " << (stk.empty() ? "是" : "否") << endl;
}

// ============================================================
// 9. QUEUE - 队列容器（先进先出 FIFO）
// ============================================================
void queueDemo() {
    cout << "\n========== QUEUE 容器演示 ==========" << endl;
    
    queue<string> q;
    
    // 入队
    q.push("第1个人");
    q.push("第2个人");
    q.push("第3个人");
    q.push("第4个人");
    
    cout << "队列大小: " << q.size() << endl;
    cout << "队首元素: " << q.front() << endl;
    cout << "队尾元素: " << q.back() << endl;
    
    // 出队
    cout << "\n出队顺序: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// ============================================================
// 10. PRIORITY_QUEUE - 优先队列（默认大顶堆）
// ============================================================
void priorityQueueDemo() {
    cout << "\n========== PRIORITY_QUEUE 容器演示 ==========" << endl;
    
    // 默认是大顶堆（最大值在堆顶）
    priority_queue<int> pq;
    
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    
    cout << "优先队列大小: " << pq.size() << endl;
    cout << "堆顶元素（最大值）: " << pq.top() << endl;
    
    cout << "\n出队顺序（从大到小）: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // 小顶堆（最小值在堆顶）
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    
    cout << "\n小顶堆出队顺序（从小到大）: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

// ============================================================
// 11. STL算法示例
// ============================================================
void algorithmDemo() {
    cout << "\n========== STL 算法演示 ==========" << endl;
    
    vector<int> vec = {30, 10, 50, 20, 40};
    
    cout << "原始数据: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 排序
    sort(vec.begin(), vec.end());
    cout << "升序排序: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 降序排序
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "降序排序: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 查找
    vector<int>::iterator it = find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        cout << "找到30，位置: " << distance(vec.begin(), it) << endl;
    }
    
    // 反转
    reverse(vec.begin(), vec.end());
    cout << "反转后: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 最大最小值
    cout << "最大值: " << *max_element(vec.begin(), vec.end()) << endl;
    cout << "最小值: " << *min_element(vec.begin(), vec.end()) << endl;
}

// ============================================================
// 主函数 - 运行所有演示
// ============================================================
int main() {
    cout << "======================================" << endl;
    cout << "    STL 容器完整学习示例" << endl;
    cout << "======================================" << endl;
    
    vectorDemo();           // 1. Vector演示
    listDemo();             // 2. List演示
    dequeDemo();            // 3. Deque演示
    setDemo();              // 4. Set演示
    multisetDemo();         // 5. Multiset演示
    mapDemo();              // 6. Map演示
    multimapDemo();         // 7. Multimap演示
    stackDemo();            // 8. Stack演示
    queueDemo();            // 9. Queue演示
    priorityQueueDemo();    // 10. Priority Queue演示
    algorithmDemo();        // 11. 算法演示
    
    cout << "\n======================================" << endl;
    cout << "         演示完成！" << endl;
    cout << "======================================" << endl;
    
    return 0;
}
