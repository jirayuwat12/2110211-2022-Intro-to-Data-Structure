#ifndef _CP_STACK_H
#define _CP_STACK_H

#include "vector.h"

namespace CP
{
    template <typename T>
    class stack{
      protected:
        vector<T> v;

      public:  
        stack() : v() {}
        bool empty() return v.empty();
        size_t size() return v.size();

        const T& top() return v.back();

        void push(const T& element) v.push_back(element);
        void pop() v.pop_back();
    };
} // namespace CP


#endif