#pragma once

#include <array>
#include <stdexcept>

#define MAX_SIZE 1e5

template<class T>
class Allocator
{
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

    public:
        template<class U>
        struct rebind 
        {
            using other = Allocator<U>;
        };

        Allocator();
        Allocator(const Allocator<T> &other);
        Allocator(Allocator<T> &&other) noexcept;

        pointer allocate(size_type n);
        void deallocate(pointer ptr, size_type n);

        template<class T1, class ... ARGS>
        void construct(T1 *p, ARGS... args);
        void destroy(pointer p);

    private:
        static const size_type max_blocks = MAX_SIZE;
        size_type count_used_blocks;
        std::array<T, max_blocks> used_blocks;
        std::array<T*, max_blocks> free_blocks;
};

template<class T>
Allocator<T>::Allocator() 
{
    for(std::size_t i = 0; i < MAX_SIZE; ++i) {
        free_blocks[i] = &used_blocks[i];
    }
    count_used_blocks = 0;
}

template<class T>
Allocator<T>::Allocator(const Allocator<T> &other) : Allocator<T>()
{
    count_used_blocks = count_used_blocks;
    for(std::size_t i = 0; i < MAX_SIZE; ++i) {
        free_blocks[i] = &used_blocks[i];
        used_blocks[i] = other.used_blocks;
    }
}

template<class T>
Allocator<T>::Allocator(Allocator<T> &&other) noexcept 
{
    count_used_blocks = count_used_blocks;
    free_blocks = std::move(other.free_blocks);
    used_blocks = std::move(other.used_blocks);
}

template<class T>
T* Allocator<T>::allocate(std::size_t n) 
{
    if (count_used_blocks + n > MAX_SIZE)
    {
        throw std::bad_alloc();
    }
    count_used_blocks += n;
    return free_blocks[count_used_blocks - n];
}

template<class T>
void Allocator<T>::deallocate(T *ptr, std::size_t n) {
    if (ptr < free_blocks[0] || ptr + n > free_blocks[MAX_SIZE - 1]) {
        throw std::out_of_range("Bad_dealloc\n");
    }
    free_blocks[MAX_SIZE - count_used_blocks--] = ptr;
} 

template<class T>
template<class T1, class ... ARGS>
void Allocator<T>::construct(T1 *p, ARGS... args) 
{
    if (p < free_blocks[0] || p > free_blocks[MAX_SIZE - 1]) {
        throw std::out_of_range("ptr not in alloc\n");
    }
    new (p) T1(std::forward<ARGS>(args)...);
};

template<class T>
void Allocator<T>::destroy(T* p) 
{
    p->~T();
}
