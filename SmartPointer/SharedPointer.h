#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include <atomic>

template <typename T>
class SharedPointer
{
private:
    T *m_ptr;
    std::atomic<int*> m_ref_counter;

public:
    SharedPointer()
        : m_ptr(nullptr)
    {
        m_ref_counter.store(new int(0));
    }

    SharedPointer(T *ptr)
        : m_ptr(ptr)
    {
        m_ref_counter.store(new int(1));
    }

    SharedPointer(const SharedPointer<T> &that)
    {
        this->m_ptr = that.m_ptr;
        int * that_ref_counter = that.m_ref_counter.load(std::memory_order::memory_order_acquire);
        this->m_ref_counter.store(that_ref_counter, std::memory_order::memory_order_release);
        if (that.m_ptr)
        {
            int * this_ref_counter = this->m_ref_counter.load(std::memory_order::memory_order_relaxed);
            (*this_ref_counter)++;
        }
    }

    SharedPointer& operator = (const SharedPointer<T> &that)
    {
        clean_up();
        
        this->m_ptr = that.m_ptr;
        int * that_ref_counter = that.m_ref_counter.load(std::memory_order::memory_order_acquire);
        this->m_ref_counter.store(that_ref_counter, std::memory_order::memory_order_release);
        if (that.m_ptr)
        {
            int * this_ref_counter = this->m_ref_counter.load(std::memory_order::memory_order_relaxed);
            (*this_ref_counter)++;
        }
    }

    ~SharedPointer()
    {
        clean_up();
    }

    int ref_count()
    {
        int * this_ref_counter = m_ref_counter.load(std::memory_order::memory_order_relaxed);
        return this_ref_counter ? *this_ref_counter : 0;
    }

    T* get()
    {
        return m_ptr;
    }

    T* operator -> () const
    {
        return m_ptr;
    }

    T& operator * () const
    {
        return *m_ptr;
    }

private:
    void clean_up()
    {
        int * this_ref_counter = m_ref_counter.load(std::memory_order::memory_order_acquire);
        (*this_ref_counter)--;
        if (*this_ref_counter == 0)
        {
            if (m_ptr)
            {
                delete m_ptr;
                m_ptr = nullptr;
            }
            delete this_ref_counter;
            this_ref_counter = nullptr;
            this->m_ref_counter.store(this_ref_counter, std::memory_order::memory_order_release);
        }
    }
};

#endif // __SHARED_POINTER_H__