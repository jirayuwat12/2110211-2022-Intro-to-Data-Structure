#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        queue<T> temp;
        while(!this->empty()) {temp.push(this->top());this->pop();}
        *this = s;
        while(!temp.empty()) {this->push(temp.front());temp.pop();}
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> temp;
        while(!q.empty()) {temp.push(q.front());q.pop();}
        auto temp2 = *this;
        while(!(this->empty())) this->pop();
        while(!temp.empty()) {this->push(temp.top());temp.pop();}
        while(!temp2.empty()) {this->push(temp2.top());temp2.pop();}
        
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
    }
}
