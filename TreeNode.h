//
// Created by Daniel Mackle on 08/12/2024.
//

#pragma once
#include <iostream>

template <typename T>
class TreeNode {
    public:
    explicit TreeNode(int value = 0, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr) : value(value), left(left), right(right) {}
    ~TreeNode() = default;
    T getValue() {
        return value;
    }
    void setValue(T value) {
        this->value = value;
    }
    TreeNode<T>*& getLeft() {
        return left;
    }
    TreeNode<T>*& getRight() {
        return right;
    }
    void setLeft(TreeNode<T>* left) {
        this->left = left;
    }
    void setRight(TreeNode<T>* right) {
        this->right = right;
    }
    void toString() {
        if (this->left) {
            left->toString();
        }
        std::cout << this->getValue() << std::endl;
        if (this->right) {
            right->toString();
        }
    }
    private:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
};
