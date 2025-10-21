/*
 * STL 容器高级应用示例
 * 展示实际开发中的常见应用场景
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

// ============================================================
// 实例1: 使用Map统计单词出现频率
// ============================================================
void wordFrequencyCounter() {
    cout << "\n========== 单词频率统计 ==========" << endl;
    
    vector<string> words = {"apple", "banana", "apple", "orange", 
                            "banana", "apple", "grape", "banana"};
    
    map<string, int> frequency;
    
    // 统计每个单词出现的次数
    for (const string& word : words) {
        frequency[word]++;  // 如果key不存在，会自动创建并初始化为0
    }
    
    cout << "单词频率统计结果：" << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << " 次" << endl;
    }
}

// ============================================================
// 实例2: 使用Set进行集合运算
// ============================================================
void setOperations() {
    cout << "\n========== 集合运算 ==========" << endl;
    
    set<int> setA = {1, 2, 3, 4, 5};
    set<int> setB = {4, 5, 6, 7, 8};
    
    cout << "集合A: ";
    for (int val : setA) cout << val << " ";
    cout << "\n集合B: ";
    for (int val : setB) cout << val << " ";
    cout << endl;
    
    // 并集
    set<int> unionSet;
    set_union(setA.begin(), setA.end(), 
              setB.begin(), setB.end(), 
              inserter(unionSet, unionSet.begin()));
    
    cout << "\n并集: ";
    for (int val : unionSet) cout << val << " ";
    cout << endl;
    
    // 交集
    set<int> intersectionSet;
    set_intersection(setA.begin(), setA.end(), 
                     setB.begin(), setB.end(), 
                     inserter(intersectionSet, intersectionSet.begin()));
    
    cout << "交集: ";
    for (int val : intersectionSet) cout << val << " ";
    cout << endl;
    
    // 差集（A-B）
    set<int> differenceSet;
    set_difference(setA.begin(), setA.end(), 
                   setB.begin(), setB.end(), 
                   inserter(differenceSet, differenceSet.begin()));
    
    cout << "差集(A-B): ";
    for (int val : differenceSet) cout << val << " ";
    cout << endl;
}

// ============================================================
// 实例3: 使用Priority_Queue实现Top K问题
// ============================================================
void topKElements() {
    cout << "\n========== Top K 最大元素 ==========" << endl;
    
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 3;
    
    // 使用小顶堆维护k个最大元素
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // 移除最小的元素
        }
    }
    
    cout << "原数组: ";
    for (int num : nums) cout << num << " ";
    cout << "\n\nTop " << k << " 最大元素: ";
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // 反向输出
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// ============================================================
// 实例4: 使用Stack实现括号匹配
// ============================================================
void bracketMatching() {
    cout << "\n========== 括号匹配检查 ==========" << endl;
    
    vector<string> testCases = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[()]}",
        "((()))"
    };
    
    for (const string& str : testCases) {
        stack<char> stk;
        bool isValid = true;
        
        for (char c : str) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    isValid = false;
                    break;
                }
                
                char top = stk.top();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    stk.pop();
                } else {
                    isValid = false;
                    break;
                }
            }
        }
        
        if (!stk.empty()) isValid = false;
        
        cout << str << " : " << (isValid ? "有效" : "无效") << endl;
    }
}

// ============================================================
// 实例5: 使用Queue实现简单的任务调度
// ============================================================
void taskScheduler() {
    cout << "\n========== 任务调度系统 ==========" << endl;
    
    queue<string> taskQueue;
    
    // 添加任务
    cout << "添加任务..." << endl;
    taskQueue.push("任务1: 编译代码");
    taskQueue.push("任务2: 运行测试");
    taskQueue.push("任务3: 部署应用");
    taskQueue.push("任务4: 发送通知");
    
    cout << "队列中有 " << taskQueue.size() << " 个任务\n" << endl;
    
    // 执行任务
    int taskNum = 1;
    while (!taskQueue.empty()) {
        cout << "执行中: " << taskQueue.front() << endl;
        taskQueue.pop();
        taskNum++;
    }
    
    cout << "\n所有任务执行完成！" << endl;
}

// ============================================================
// 实例6: 学生成绩管理系统
// ============================================================
struct Student {
    string name;
    int score;
    
    Student(string n, int s) : name(n), score(s) {}
    
    // 用于排序的比较函数
    bool operator<(const Student& other) const {
        return score > other.score;  // 按分数降序
    }
};

void studentManagementSystem() {
    cout << "\n========== 学生成绩管理系统 ==========" << endl;
    
    vector<Student> students;
    students.push_back(Student("张三", 85));
    students.push_back(Student("李四", 92));
    students.push_back(Student("王五", 78));
    students.push_back(Student("赵六", 95));
    students.push_back(Student("孙七", 88));
    
    // 按分数排序
    sort(students.begin(), students.end());
    
    cout << "成绩排名（从高到低）：" << endl;
    cout << "排名\t姓名\t分数" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << (i + 1) << "\t" << students[i].name 
             << "\t" << students[i].score << endl;
    }
    
    // 统计分数段
    map<string, int> scoreRange;
    for (const Student& s : students) {
        if (s.score >= 90) scoreRange["优秀(90-100)"]++;
        else if (s.score >= 80) scoreRange["良好(80-89)"]++;
        else if (s.score >= 60) scoreRange["及格(60-79)"]++;
        else scoreRange["不及格(0-59)"]++;
    }
    
    cout << "\n分数段统计：" << endl;
    for (const auto& pair : scoreRange) {
        cout << pair.first << ": " << pair.second << " 人" << endl;
    }
}

// ============================================================
// 实例7: 使用Vector实现动态数组操作
// ============================================================
void vectorAdvancedOperations() {
    cout << "\n========== Vector高级操作 ==========" << endl;
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "原始数组: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    
    // 查找所有偶数
    cout << "\n偶数: ";
    for (int val : vec) {
        if (val % 2 == 0) cout << val << " ";
    }
    cout << endl;
    
    // 删除所有奇数
    vec.erase(remove_if(vec.begin(), vec.end(), 
                        [](int x) { return x % 2 != 0; }), 
              vec.end());
    
    cout << "删除奇数后: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    
    // 每个元素乘以2
    for_each(vec.begin(), vec.end(), [](int& x) { x *= 2; });
    
    cout << "每个元素乘2: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    
    // 累加求和
    int sum = 0;
    for (int val : vec) sum += val;
    cout << "总和: " << sum << endl;
}

// ============================================================
// 实例8: 使用Map实现简单的缓存系统
// ============================================================
void simpleCacheSystem() {
    cout << "\n========== 简单缓存系统 ==========" << endl;
    
    map<string, string> cache;
    
    // 模拟缓存操作
    auto getFromCache = [&](const string& key) -> string {
        if (cache.find(key) != cache.end()) {
            cout << "缓存命中: " << key << " -> " << cache[key] << endl;
            return cache[key];
        } else {
            cout << "缓存未命中: " << key << "，从数据库获取..." << endl;
            // 模拟从数据库获取
            string value = "数据_" + key;
            cache[key] = value;  // 存入缓存
            return value;
        }
    };
    
    // 测试
    getFromCache("user_001");
    getFromCache("user_002");
    getFromCache("user_001");  // 第二次访问，命中缓存
    getFromCache("user_003");
    
    cout << "\n当前缓存内容：" << endl;
    for (const auto& pair : cache) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}

// ============================================================
// 实例9: 使用Deque实现滑动窗口
// ============================================================
void slidingWindowMax() {
    cout << "\n========== 滑动窗口最大值 ==========" << endl;
    
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;  // 窗口大小
    
    cout << "数组: ";
    for (int num : nums) cout << num << " ";
    cout << "\n窗口大小: " << k << endl;
    
    cout << "\n每个窗口的最大值: ";
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxVal = *max_element(nums.begin() + i, nums.begin() + i + k);
        cout << maxVal << " ";
    }
    cout << endl;
}

// ============================================================
// 实例10: 二维Vector（矩阵）操作
// ============================================================
void matrixOperations() {
    cout << "\n========== 二维Vector矩阵操作 ==========" << endl;
    
    // 创建3x4矩阵
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << "原始矩阵:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    // 转置矩阵
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "\n转置后矩阵:" << endl;
    for (const auto& row : transposed) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// ============================================================
// 主函数
// ============================================================
//int main() {
//    cout << "======================================" << endl;
//    cout << "    STL 容器实际应用示例" << endl;
//    cout << "======================================" << endl;
//    
//    wordFrequencyCounter();        // 1. 单词频率统计
//    setOperations();               // 2. 集合运算
//    topKElements();                // 3. Top K问题
//    bracketMatching();             // 4. 括号匹配
//    taskScheduler();               // 5. 任务调度
//    studentManagementSystem();     // 6. 学生成绩管理
//    vectorAdvancedOperations();    // 7. Vector高级操作
//    simpleCacheSystem();           // 8. 缓存系统
//    slidingWindowMax();            // 9. 滑动窗口
//    matrixOperations();            // 10. 矩阵操作
//    
//    cout << "\n======================================" << endl;
//    cout << "         所有示例运行完成！" << endl;
//    cout << "======================================" << endl;
//    
//    return 0;
//}
