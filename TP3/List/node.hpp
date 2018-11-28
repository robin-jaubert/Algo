#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode<T>> m_Next;
    std::shared_ptr<CNode<T>> m_Prev;
public:
    //constructor
    CNode (const T &  val = T(), const std::shared_ptr<CNode<T>> &next = nullptr, const std::shared_ptr<CNode<T>> &prev = nullptr);
    //destructor
    ~CNode (){}

    //getter / setter
    const T &GetData () const;
    std::shared_ptr<CNode<T>> GetNextNode () const;
    void SetData (const T & val);
    void SetNextNode (const std::shared_ptr<CNode<T>> &ANode);
    std::shared_ptr<CNode<T> > GetPrev() const;
    void setPrev(const std::shared_ptr<CNode<T> > &Prev);
};

template <typename T>
CNode<T>::CNode (const T & val, const std::shared_ptr<CNode<T>> &next, const std::shared_ptr<CNode<T>> &prev ) : m_Data (val), m_Next (next), m_Prev(prev){}


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

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetPrev() const
{
    return m_Prev;
}

template <typename T>
void CNode<T>::setPrev(const std::shared_ptr<CNode<T> > &Prev){
    m_Prev = Prev;
}

#endif // NODE_HPP
