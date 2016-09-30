//
//  quick_sort.hpp
//  Quick Sort
//
//  Created by 郑振宇 on 16/9/30.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <vector>
#include <cstddef>
#include "utils.hpp"

// 数组划分
template <typename T>
size_t Partition(std::vector<T> &a, const size_t p, const size_t r) {
    T x = a[r];
    size_t i = p;
    
    for (auto j = p; j != r; ++j) {
        if (a[j] <= x) {
            std::swap(a[i], a[j]);
            i = i + 1;
        }
    }
    
    std::swap(a[i], a[r]);
    
    return i;
}

// 使用Hoare方法进行数组划分
template <typename T>
size_t HoarePartition(std::vector<T> &a, const size_t p, const size_t r) {
    T x = a[p];
    size_t i = p;
    size_t j = r;
    
    while(i != j) {
        while (a[j] >= x && i < j) {
            --j;
        }
        
        while (a[i] <= x && i < j) {
            ++i;
        }
        
        if (i < j) {
            std::swap(a[i], a[j]);
        }
    }
    
    a[p] = a[i];
    a[i] = x;
    
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 快速排序
template <typename T>
void QuickSort(std::vector<T> &a, const size_t p, const size_t r) {
    if (p < r) {
        size_t q = Partition(a, p, r);
        
        if (q > 0) QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用Hoare方法进行快速排序
template <typename T>
void HoareQuickSort(std::vector<T> &a, const size_t p, const size_t r) {
    if (p < r) {
        size_t q = HoarePartition(a, p, r);
        
        if (q > 0) HoareQuickSort(a, p, q - 1);
        HoareQuickSort(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用随机的方式划分
template <typename T>
size_t RandomizedPartition(std::vector<T> &a, const size_t p, const size_t r) {
    int i = static_cast<int>(random(p, r));
    
    std::swap(a[i], a[r]);
    
    return Partition(a, p, r);
}

// 随机化版本的快速排序
template <typename T>
void RandomizedQuickSort(std::vector<T> &a, const size_t p, const size_t r) {
    if (p < r) {
        size_t q = RandomizedPartition(a, p, r);
        
        if (q > 0) RandomizedQuickSort(a, p, q - 1);
        RandomizedQuickSort(a, q + 1, r);
    }
}

#endif /* quick_sort_hpp */
