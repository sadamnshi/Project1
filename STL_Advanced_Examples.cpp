/*
 * STL �����߼�Ӧ��ʾ��
 * չʾʵ�ʿ����еĳ���Ӧ�ó���
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
// ʵ��1: ʹ��Mapͳ�Ƶ��ʳ���Ƶ��
// ============================================================
void wordFrequencyCounter() {
    cout << "\n========== ����Ƶ��ͳ�� ==========" << endl;
    
    vector<string> words = {"apple", "banana", "apple", "orange", 
                            "banana", "apple", "grape", "banana"};
    
    map<string, int> frequency;
    
    // ͳ��ÿ�����ʳ��ֵĴ���
    for (const string& word : words) {
        frequency[word]++;  // ���key�����ڣ����Զ���������ʼ��Ϊ0
    }
    
    cout << "����Ƶ��ͳ�ƽ����" << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << " ��" << endl;
    }
}

// ============================================================
// ʵ��2: ʹ��Set���м�������
// ============================================================
void setOperations() {
    cout << "\n========== �������� ==========" << endl;
    
    set<int> setA = {1, 2, 3, 4, 5};
    set<int> setB = {4, 5, 6, 7, 8};
    
    cout << "����A: ";
    for (int val : setA) cout << val << " ";
    cout << "\n����B: ";
    for (int val : setB) cout << val << " ";
    cout << endl;
    
    // ����
    set<int> unionSet;
    set_union(setA.begin(), setA.end(), 
              setB.begin(), setB.end(), 
              inserter(unionSet, unionSet.begin()));
    
    cout << "\n����: ";
    for (int val : unionSet) cout << val << " ";
    cout << endl;
    
    // ����
    set<int> intersectionSet;
    set_intersection(setA.begin(), setA.end(), 
                     setB.begin(), setB.end(), 
                     inserter(intersectionSet, intersectionSet.begin()));
    
    cout << "����: ";
    for (int val : intersectionSet) cout << val << " ";
    cout << endl;
    
    // ���A-B��
    set<int> differenceSet;
    set_difference(setA.begin(), setA.end(), 
                   setB.begin(), setB.end(), 
                   inserter(differenceSet, differenceSet.begin()));
    
    cout << "�(A-B): ";
    for (int val : differenceSet) cout << val << " ";
    cout << endl;
}

// ============================================================
// ʵ��3: ʹ��Priority_Queueʵ��Top K����
// ============================================================
void topKElements() {
    cout << "\n========== Top K ���Ԫ�� ==========" << endl;
    
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 3;
    
    // ʹ��С����ά��k�����Ԫ��
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // �Ƴ���С��Ԫ��
        }
    }
    
    cout << "ԭ����: ";
    for (int num : nums) cout << num << " ";
    cout << "\n\nTop " << k << " ���Ԫ��: ";
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // �������
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// ============================================================
// ʵ��4: ʹ��Stackʵ������ƥ��
// ============================================================
void bracketMatching() {
    cout << "\n========== ����ƥ���� ==========" << endl;
    
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
        
        cout << str << " : " << (isValid ? "��Ч" : "��Ч") << endl;
    }
}

// ============================================================
// ʵ��5: ʹ��Queueʵ�ּ򵥵��������
// ============================================================
void taskScheduler() {
    cout << "\n========== �������ϵͳ ==========" << endl;
    
    queue<string> taskQueue;
    
    // �������
    cout << "�������..." << endl;
    taskQueue.push("����1: �������");
    taskQueue.push("����2: ���в���");
    taskQueue.push("����3: ����Ӧ��");
    taskQueue.push("����4: ����֪ͨ");
    
    cout << "�������� " << taskQueue.size() << " ������\n" << endl;
    
    // ִ������
    int taskNum = 1;
    while (!taskQueue.empty()) {
        cout << "ִ����: " << taskQueue.front() << endl;
        taskQueue.pop();
        taskNum++;
    }
    
    cout << "\n��������ִ����ɣ�" << endl;
}

// ============================================================
// ʵ��6: ѧ���ɼ�����ϵͳ
// ============================================================
struct Student {
    string name;
    int score;
    
    Student(string n, int s) : name(n), score(s) {}
    
    // ��������ıȽϺ���
    bool operator<(const Student& other) const {
        return score > other.score;  // ����������
    }
};

void studentManagementSystem() {
    cout << "\n========== ѧ���ɼ�����ϵͳ ==========" << endl;
    
    vector<Student> students;
    students.push_back(Student("����", 85));
    students.push_back(Student("����", 92));
    students.push_back(Student("����", 78));
    students.push_back(Student("����", 95));
    students.push_back(Student("����", 88));
    
    // ����������
    sort(students.begin(), students.end());
    
    cout << "�ɼ��������Ӹߵ��ͣ���" << endl;
    cout << "����\t����\t����" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << (i + 1) << "\t" << students[i].name 
             << "\t" << students[i].score << endl;
    }
    
    // ͳ�Ʒ�����
    map<string, int> scoreRange;
    for (const Student& s : students) {
        if (s.score >= 90) scoreRange["����(90-100)"]++;
        else if (s.score >= 80) scoreRange["����(80-89)"]++;
        else if (s.score >= 60) scoreRange["����(60-79)"]++;
        else scoreRange["������(0-59)"]++;
    }
    
    cout << "\n������ͳ�ƣ�" << endl;
    for (const auto& pair : scoreRange) {
        cout << pair.first << ": " << pair.second << " ��" << endl;
    }
}

// ============================================================
// ʵ��7: ʹ��Vectorʵ�ֶ�̬�������
// ============================================================
void vectorAdvancedOperations() {
    cout << "\n========== Vector�߼����� ==========" << endl;
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "ԭʼ����: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    
    // ��������ż��
    cout << "\nż��: ";
    for (int val : vec) {
        if (val % 2 == 0) cout << val << " ";
    }
    cout << endl;
    
    // ɾ����������
    vec.erase(remove_if(vec.begin(), vec.end(), 
                        [](int x) { return x % 2 != 0; }), 
              vec.end());
    
    cout << "ɾ��������: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    
    // ÿ��Ԫ�س���2
    for_each(vec.begin(), vec.end(), [](int& x) { x *= 2; });
    
    cout << "ÿ��Ԫ�س�2: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    
    // �ۼ����
    int sum = 0;
    for (int val : vec) sum += val;
    cout << "�ܺ�: " << sum << endl;
}

// ============================================================
// ʵ��8: ʹ��Mapʵ�ּ򵥵Ļ���ϵͳ
// ============================================================
void simpleCacheSystem() {
    cout << "\n========== �򵥻���ϵͳ ==========" << endl;
    
    map<string, string> cache;
    
    // ģ�⻺�����
    auto getFromCache = [&](const string& key) -> string {
        if (cache.find(key) != cache.end()) {
            cout << "��������: " << key << " -> " << cache[key] << endl;
            return cache[key];
        } else {
            cout << "����δ����: " << key << "�������ݿ��ȡ..." << endl;
            // ģ������ݿ��ȡ
            string value = "����_" + key;
            cache[key] = value;  // ���뻺��
            return value;
        }
    };
    
    // ����
    getFromCache("user_001");
    getFromCache("user_002");
    getFromCache("user_001");  // �ڶ��η��ʣ����л���
    getFromCache("user_003");
    
    cout << "\n��ǰ�������ݣ�" << endl;
    for (const auto& pair : cache) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}

// ============================================================
// ʵ��9: ʹ��Dequeʵ�ֻ�������
// ============================================================
void slidingWindowMax() {
    cout << "\n========== �����������ֵ ==========" << endl;
    
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;  // ���ڴ�С
    
    cout << "����: ";
    for (int num : nums) cout << num << " ";
    cout << "\n���ڴ�С: " << k << endl;
    
    cout << "\nÿ�����ڵ����ֵ: ";
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxVal = *max_element(nums.begin() + i, nums.begin() + i + k);
        cout << maxVal << " ";
    }
    cout << endl;
}

// ============================================================
// ʵ��10: ��άVector�����󣩲���
// ============================================================
void matrixOperations() {
    cout << "\n========== ��άVector������� ==========" << endl;
    
    // ����3x4����
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << "ԭʼ����:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    // ת�þ���
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "\nת�ú����:" << endl;
    for (const auto& row : transposed) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// ============================================================
// ������
// ============================================================
//int main() {
//    cout << "======================================" << endl;
//    cout << "    STL ����ʵ��Ӧ��ʾ��" << endl;
//    cout << "======================================" << endl;
//    
//    wordFrequencyCounter();        // 1. ����Ƶ��ͳ��
//    setOperations();               // 2. ��������
//    topKElements();                // 3. Top K����
//    bracketMatching();             // 4. ����ƥ��
//    taskScheduler();               // 5. �������
//    studentManagementSystem();     // 6. ѧ���ɼ�����
//    vectorAdvancedOperations();    // 7. Vector�߼�����
//    simpleCacheSystem();           // 8. ����ϵͳ
//    slidingWindowMax();            // 9. ��������
//    matrixOperations();            // 10. �������
//    
//    cout << "\n======================================" << endl;
//    cout << "         ����ʾ��������ɣ�" << endl;
//    cout << "======================================" << endl;
//    
//    return 0;
//}
