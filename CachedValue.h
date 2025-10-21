#include <atomic>
#include <mutex>

class CachedValue {
public:
    int getValue() const {
        // 双重检查锁定，保证线程安全和可见性
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
    int compute() const { return 42; } // 假设的计算

    mutable std::atomic<bool> cacheValid{false};
    mutable int cache = 0;
    mutable std::mutex mtx;
};