#include <iostream>
#include <set>
using namespace std;

template<typename T>
class Set {
private:
    set<T> data;

public:
    Set() {}
    Set(initializer_list<T> elements) : data(elements) {}
    ~Set() {}

    Set<T>& operator=(const Set<T>& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    void add(const T& element) {
        data.insert(element);
    }

    void add(const initializer_list<T>& elements) {
        for (const auto& element : elements) {
            data.insert(element);
        }
    }

    void remove(const T& element) {
        data.erase(element);
    }

    void clear() {
        data.clear();
    }

    bool contains(const T& element) const {
        return data.count(element) > 0;
    }

    size_t size() const {
        return data.size();
    }

    Set<T> union_with(const Set<T>& other) const {
        Set<T> result(*this);
        for (const auto& element : other.data) {
            result.add(element);
        }
        return result;
    }

    Set<T> intersection_with(const Set<T>& other) const {
        Set<T> result;
        for (const auto& element : data) {
            if (other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    Set<T> difference_with(const Set<T>& other) const {
        Set<T> result;
        for (const auto& element : data) {
            if (!other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
    os << "{ ";
    for (const auto& element : set.data) {
        os << element << " ";
    }
    os << "}";
    return os;
}
