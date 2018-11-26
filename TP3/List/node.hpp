#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode<T>> m_Next;
public:
    //constructor
    CNode (const T &  val = T(), const std::shared_ptr<CNode<T>> &ptr = nullptr);
    //destructor
    ~CNode (){}

    //getter / setter
    const T &GetData () const;
    std::shared_ptr<CNode<T>> GetNextNode () const;
    void SetData (const T & val);
    void SetNextNode (const std::shared_ptr<CNode<T>> &ANode);
};


template <typename T>
CNode<T>::CNode (const T & val, const std::shared_ptr<CNode<T>> &ptr ) : m_Data (val), m_Next (ptr){}


template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetNextNode () const
{
    return m_Next;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetNextNode (const std::shared_ptr<CNode<T>> &ANode)
{
    m_Next = ANode;
}

#endif // NODE_HPP
