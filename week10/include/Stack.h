#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
    virtual ~Stack() = default;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
};

#endif
