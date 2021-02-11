//
// Created by milerol on 09.02.2021.
//

#ifndef TEMPLATE_STACK_HPP
#define TEMPLATE_STACK_HPP
#include <iostream>
template <typename T>
class stack
{
 public:
  stack() : element_top(nullptr) {};
  void push(T&& value){
    node* new_node = new node;
    new_node->data = value;
    new_node->element_next = element_top;
    element_top = new_node;
  }
  void push(const T& value) {
      node* new_node = new node;
      new_node->data = value;
      new_node->element_next = element_top;
      element_top = new_node;
  }
  void pop() {
    if (empty()) throw std::string("Stack is empty!");
    node *delete_node = element_top;
    element_top = delete_node->element_next;
    delete delete_node;
  }
  const T& head() const {
    if (empty()) throw std::string("Stack is empty!");
    return element_top->data;
  }

  ~stack(){
    while (element_top){
    node *delete_node = element_top;
    element_top = delete_node->element_next;
    delete delete_node;
    }
  }

  bool empty() const
  {
    return element_top == nullptr;
  }
 private:
  struct node {
    T data;
    node* element_next;
  };
  node* element_top;
};

#endif  // TEMPLATE_STACK_HPP
