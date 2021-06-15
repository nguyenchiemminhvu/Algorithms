#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

template <typename T>
class SharedPointer
{
private:
    T *m_ptr;
    int *m_ref_counter;

public:
    SharedPointer()
        : m_ptr(nullptr), m_ref_counter(new int(0))
    {

    }

    SharedPointer(T *ptr)
        : m_ptr(ptr), m_ref_counter(new int(1))
    {

    }

    SharedPointer(const SharedPointer<T> &that)
    {
        this->m_ptr = that.m_ptr;
        this->m_ref_counter = that.m_ref_counter;
        if (that.m_ptr)
        {
            (*this->m_ref_counter)++;
        }
    }

    SharedPointer& operator = (const SharedPointer<T> &that)
    {
        clean_up();
        
        this->m_ptr = that.m_ptr;
        this->m_ref_counter = that.m_ref_counter;
        if (that.m_ptr)
        {
            (*this->m_ref_counter)++;
        }
    }

    ~SharedPointer()
    {
        clean_up();
    }

    int ref_count()
    {
        return m_ref_counter ? *m_ref_counter : 0;
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
        (*m_ref_counter)--;
        if (*m_ref_counter == 0)
        {
            if (m_ptr)
            {
                delete m_ptr;
                m_ptr = nullptr;
            }
            delete m_ref_counter;
            m_ref_counter = nullptr;
        }
    }
};

#endif // __SHARED_POINTER_H__