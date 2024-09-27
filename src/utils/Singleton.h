#ifndef SINGLETON_H
#define SINGLETON_H

// Simple singleton template for utility purposes
template <typename T>
class Singleton {
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

#endif // SINGLETON_H
