/*
 * STL����ѧϰ����ʾ��
 * ���ǳ��õ�STL������vector, list, deque, set, map, stack, queue��
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
// 1. VECTOR - ��̬��������
// ============================================================
void vectorDemo() {
    cout << "\n========== VECTOR ������ʾ ==========" << endl;
    
    // ����vector
    vector<int> vec;
    
    // ���Ԫ�� - push_back��ĩβ���
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    cout << "VectorԪ��: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";  // ֧���±����
    }
    cout << endl;
    
    // ʹ�õ���������
    cout << "ʹ�õ���������: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ���ò���
    cout << "��С: " << vec.size() << endl;
    cout << "����: " << vec.capacity() << endl;
    cout << "��һ��Ԫ��: " << vec.front() << endl;
    cout << "���Ԫ��: " << vec.back() << endl;
    
    // ����Ԫ��
    vec.insert(vec.begin() + 1, 15);  // �ڵ�2��λ�ò���15
    cout << "����15��: ";
    for (int val : vec) {  // C++11��Χforѭ��
        cout << val << " ";
    }
    cout << endl;
    
    // ɾ��Ԫ��
    vec.erase(vec.begin());  // ɾ����һ��Ԫ��
    vec.pop_back();  // ɾ�����һ��Ԫ��
    
    // ��պ��п�
    cout << "�Ƿ�Ϊ��: " << (vec.empty() ? "��" : "��") << endl;
    vec.clear();
    cout << "��պ��Ƿ�Ϊ��: " << (vec.empty() ? "��" : "��") << endl;
}

// ============================================================
// 2. LIST - ˫����������
// ============================================================
void listDemo() {
    cout << "\n========== LIST ������ʾ ==========" << endl;
    
    list<int> lst;
    
    // ���Ԫ��
    lst.push_back(10);    // β�����
    lst.push_back(30);
    lst.push_front(5);    // ͷ�����
    lst.push_front(1);
    
    cout << "ListԪ��: ";
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // List��֧��������ʣ�������[]
    // ��֧��˫�����
    lst.push_back(40);
    lst.push_back(20);
    
    // ����
    lst.sort();  // list���Լ���sort��Ա����
    cout << "�����: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // ��ת
    lst.reverse();
    cout << "��ת��: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // ɾ���ض�ֵ
    lst.remove(20);  // ɾ������ֵΪ20��Ԫ��
    cout << "ɾ��20��: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // ȥ�أ���Ҫ������
    lst.sort();
    lst.unique();
    cout << "ȥ�غ�: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================================
// 3. DEQUE - ˫�˶���
// ============================================================
void dequeDemo() {
    cout << "\n========== DEQUE ������ʾ ==========" << endl;
    
    deque<int> dq;
    
    // ˫�˲���
    dq.push_back(10);     // β�����
    dq.push_back(20);
    dq.push_front(5);     // ͷ�����
    dq.push_front(1);
    
    cout << "DequeԪ��: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";  // ֧���������
    }
    cout << endl;
    
    // ����Ԫ��
    cout << "��һ��Ԫ��: " << dq.front() << endl;
    cout << "���Ԫ��: " << dq.back() << endl;
    cout << "��3��Ԫ��: " << dq[2] << endl;
    cout << "at(1): " << dq.at(1) << endl;
    
    // ˫��ɾ��
    dq.pop_front();  // ɾ��ͷ��
    dq.pop_back();   // ɾ��β��
    
    cout << "ɾ����β��: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================================
// 4. SET - �����������Զ�����Ԫ��Ψһ��
// ============================================================
void setDemo() {
    cout << "\n========== SET ������ʾ ==========" << endl;
    
    set<int> s;
    
    // ����Ԫ�أ��Զ������Զ�ȥ�أ�
    s.insert(30);
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(30);  // �ظ�Ԫ�ز��ᱻ����
    s.insert(40);
    
    cout << "SetԪ�أ��Զ�����: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ����Ԫ��
    set<int>::iterator findIt = s.find(30);
    if (findIt != s.end()) {
        cout << "�ҵ�Ԫ��: " << *findIt << endl;
    }
    
    // ͳ��Ԫ�ظ�����ֻ����0��1��
    cout << "30���ִ���: " << s.count(30) << endl;
    cout << "100���ִ���: " << s.count(100) << endl;
    
    // ɾ��Ԫ��
    s.erase(30);
    cout << "ɾ��30��: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Set��С: " << s.size() << endl;
}

// ============================================================
// 5. MULTISET - �����ظ��ļ���
// ============================================================
void multisetDemo() {
    cout << "\n========== MULTISET ������ʾ ==========" << endl;
    
    multiset<int> ms;
    
    // ��������ظ�Ԫ��
    ms.insert(30);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);
    ms.insert(30);
    
    cout << "MultisetԪ��: ";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "30���ִ���: " << ms.count(30) << endl;
    
    // ɾ������ֵΪ30��Ԫ��
    ms.erase(30);
    cout << "ɾ������30��: ";
    for (int val : ms) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================================
// 6. MAP - ��ֵ��������key-value��
// ============================================================
void mapDemo() {
    cout << "\n========== MAP ������ʾ ==========" << endl;
    
    map<string, int> m;
    
    // ����Ԫ�ص����ַ�ʽ
    m.insert(pair<string, int>("����", 85));
    m.insert(make_pair("����", 92));
    m["����"] = 78;  // ��򵥵ķ�ʽ
    m["����"] = 88;
    
    cout << "MapԪ�أ���key����:" << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    // ����Ԫ��
    cout << "\n�����ķ���: " << m["����"] << endl;
    
    // ����
    map<string, int>::iterator findIt = m.find("����");
    if (findIt != m.end()) {
        cout << "�ҵ����ģ�����: " << findIt->second << endl;
    }
    
    // �޸�ֵ
    m["����"] = 95;
    cout << "�޸ĺ�����ķ���: " << m["����"] << endl;
    
    // �ж�key�Ƿ����
    if (m.count("����") > 0) {
        cout << "����������map��" << endl;
    }
    
    // ɾ��
    m.erase("����");
    cout << "\nMap��С: " << m.size() << endl;
}

// ============================================================
// 7. MULTIMAP - �����ظ�key��map
// ============================================================
void multimapDemo() {
    cout << "\n========== MULTIMAP ������ʾ ==========" << endl;
    
    multimap<string, int> mm;
    
    // ������ͬ��key
    mm.insert(make_pair("��ѧ", 85));
    mm.insert(make_pair("��ѧ", 92));
    mm.insert(make_pair("Ӣ��", 78));
    mm.insert(make_pair("��ѧ", 88));
    
    cout << "MultimapԪ��:" << endl;
    for (multimap<string, int>::iterator it = mm.begin(); it != mm.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << "\n��ѧ�ɼ�����: " << mm.count("��ѧ") << endl;
}

// ============================================================
// 8. STACK - ջ����������ȳ� LIFO��
// ============================================================
void stackDemo() {
    cout << "\n========== STACK ������ʾ ==========" << endl;
    
    stack<int> stk;
    
    // ѹջ
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    
    cout << "ջ�Ĵ�С: " << stk.size() << endl;
    cout << "ջ��Ԫ��: " << stk.top() << endl;
    
    // ��ջ
    cout << "��ջ˳��: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
    
    cout << "ջ�Ƿ�Ϊ��: " << (stk.empty() ? "��" : "��") << endl;
}

// ============================================================
// 9. QUEUE - �����������Ƚ��ȳ� FIFO��
// ============================================================
void queueDemo() {
    cout << "\n========== QUEUE ������ʾ ==========" << endl;
    
    queue<string> q;
    
    // ���
    q.push("��1����");
    q.push("��2����");
    q.push("��3����");
    q.push("��4����");
    
    cout << "���д�С: " << q.size() << endl;
    cout << "����Ԫ��: " << q.front() << endl;
    cout << "��βԪ��: " << q.back() << endl;
    
    // ����
    cout << "\n����˳��: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// ============================================================
// 10. PRIORITY_QUEUE - ���ȶ��У�Ĭ�ϴ󶥶ѣ�
// ============================================================
void priorityQueueDemo() {
    cout << "\n========== PRIORITY_QUEUE ������ʾ ==========" << endl;
    
    // Ĭ���Ǵ󶥶ѣ����ֵ�ڶѶ���
    priority_queue<int> pq;
    
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    
    cout << "���ȶ��д�С: " << pq.size() << endl;
    cout << "�Ѷ�Ԫ�أ����ֵ��: " << pq.top() << endl;
    
    cout << "\n����˳�򣨴Ӵ�С��: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // С���ѣ���Сֵ�ڶѶ���
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    
    cout << "\nС���ѳ���˳�򣨴�С����: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

// ============================================================
// 11. STL�㷨ʾ��
// ============================================================
void algorithmDemo() {
    cout << "\n========== STL �㷨��ʾ ==========" << endl;
    
    vector<int> vec = {30, 10, 50, 20, 40};
    
    cout << "ԭʼ����: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // ����
    sort(vec.begin(), vec.end());
    cout << "��������: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // ��������
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "��������: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // ����
    vector<int>::iterator it = find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        cout << "�ҵ�30��λ��: " << distance(vec.begin(), it) << endl;
    }
    
    // ��ת
    reverse(vec.begin(), vec.end());
    cout << "��ת��: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // �����Сֵ
    cout << "���ֵ: " << *max_element(vec.begin(), vec.end()) << endl;
    cout << "��Сֵ: " << *min_element(vec.begin(), vec.end()) << endl;
}

// ============================================================
// ������ - ����������ʾ
// ============================================================
int main() {
    cout << "======================================" << endl;
    cout << "    STL ��������ѧϰʾ��" << endl;
    cout << "======================================" << endl;
    
    vectorDemo();           // 1. Vector��ʾ
    listDemo();             // 2. List��ʾ
    dequeDemo();            // 3. Deque��ʾ
    setDemo();              // 4. Set��ʾ
    multisetDemo();         // 5. Multiset��ʾ
    mapDemo();              // 6. Map��ʾ
    multimapDemo();         // 7. Multimap��ʾ
    stackDemo();            // 8. Stack��ʾ
    queueDemo();            // 9. Queue��ʾ
    priorityQueueDemo();    // 10. Priority Queue��ʾ
    algorithmDemo();        // 11. �㷨��ʾ
    
    cout << "\n======================================" << endl;
    cout << "         ��ʾ��ɣ�" << endl;
    cout << "======================================" << endl;
    
    return 0;
}
