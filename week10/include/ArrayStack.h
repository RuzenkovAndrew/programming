#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "Stack.h"
#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack : public Stack<T> {
private:
    std::vector<T> items;

public:
    void push(const T& item) override {
        items.push_back(item);
    }
    T pop() override {
        if (isEmpty()) {
            throw std::out_of_range("Стек пуст!");
        }
        T topItem = items.back();
        items.pop_back();
        return topItem;
    }
    T peek() const override {
        if (isEmpty()) {
            throw std::out_of_range("Стек пуст!");
        }
        return items.back();
    }
    bool isEmpty() const override {
        return items.empty();
    }
    int size() const override {
        return items.size();
    }
};

#endif
