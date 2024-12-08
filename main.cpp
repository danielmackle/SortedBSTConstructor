#include <vector>
#include "TreeNode.h"

int main();
void construct(const std::vector<int>& array);
void construct(const std::vector<int>& array, int first, int last);

template <typename T>
void construct(TreeNode<T>*& root, T value);

TreeNode<int>* root = nullptr;

int main() {
    const std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    construct(array);
    root->toString();
    return 0;
}
void construct(const std::vector<int>& array) {
    construct(array, 0, array.size()-1);
}
void construct(const std::vector<int>& array, const int first, const int last) {
    if (first > last) {
        return;
    }
    const int mid = first + (last - first) / 2;
    const int selected = array[mid];

    construct(root, selected);

    construct(array, first, mid-1);
    construct(array, mid+1, last);
}

template <typename T>
void construct(TreeNode<T>*& root, T value) {
    if (!root) {
        root = new TreeNode<T>(value);
        return;
    }
    if (root->getValue() == value) {
        return;
    }
    if (value < root->getValue()) {
        TreeNode<T>*& left = root->getLeft();
        construct(left, value);
        return;
    }
    TreeNode<T>*& right = root->getRight();
    construct(right, value);
}