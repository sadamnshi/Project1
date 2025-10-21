#include <atomic>
#include <mutex>

class CachedValue {
public:
    int getValue() const {
        // ˫�ؼ����������֤�̰߳�ȫ�Ϳɼ���
        if (!cacheValid.load(std::memory_order_acquire)) {
            std::lock_guard<std::mutex> lock(mtx);
            if (!cacheValid.load(std::memory_order_relaxed)) {
                cache = compute();
                cacheValid.store(true, std::memory_order_release);
            }
        }
        return cache;
    }

private:
    int compute() const { return 42; } // ����ļ���

    mutable std::atomic<bool> cacheValid{false};
    mutable int cache = 0;
    mutable std::mutex mtx;
};