#ifndef __UNIQUE_POINTER_H__
#define __UNIQUE_POINTER_H__

template <typename T>
class UniquePointer
{
private:
    T *m_ptr;

public:
    UniquePointer()
        : m_ptr(nullptr)
    {

    }

    UniquePointer(T *ptr)
        : m_ptr(ptr)
    {

    }

    UniquePointer(const UniquePointer<T> &that)
    {
        this->m_ptr = that.m_ptr;
    }

    UniquePointer& operator = (const UniquePointer<T> &that)
    {
        clean_up();
        
        this->m_ptr = that.m_ptr;
    }

    ~UniquePointer()
    {
        clean_up();
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
        if (m_ptr)
        {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }
};

#endif // __UNIQUE_POINTER_H__