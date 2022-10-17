#include <vector>

template <class T>
class VectorStack : public IStack<T>{
private:
    std::vector<T> data;

public:
    void push(const T& element) {
        data.push_back(element);
    }
    T& pop() {
        T temp = data.back();
        data.pop_back();
        return temp;
    }
    T& peek() const {
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

