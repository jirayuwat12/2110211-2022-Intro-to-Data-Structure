#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int>s;
  for(pair<int,int> i : v){
    if(i.first == 0){
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      if(i.second == 0){
        s.push(a+b);
      }else if(i.second == 1){
        s.push(a-b);
      }else if(i.second == 2){
        s.push(a*b);
      }else{
        s.push(a/b);
      }
    }else{
      s.push(i.second);
    }
  }
  return s.top();
}

#endif
