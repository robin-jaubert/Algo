#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode<T>> m_RC;
    std::shared_ptr<CNode<T>> m_LC;
public:
    //constructor
    CNode (const T &  val = T(), const std::shared_ptr<CNode<T>> &next = nullptr, const std::shared_ptr<CNode<T>> &prev = nullptr);
    //destructor
    ~CNode (){}

    //getter / setter
    const T &GetData () const;
    std::shared_ptr<CNode<T>> GetLC () const;
    void SetData (const T & val);
    void SetLC (const std::shared_ptr<CNode<T>> &ANode);
    std::shared_ptr<CNode<T> > GetRC() const;
    void setRC(const std::shared_ptr<CNode<T> > &Prev);
};

template <typename T>
CNode<T>::CNode (const T & val, const std::shared_ptr<CNode<T>> &next, const std::shared_ptr<CNode<T>> &prev ) : m_Data (val), m_RC (next), m_LC(prev){}


template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetRC () const
{
    return m_RC;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::setRC(const std::shared_ptr<CNode<T> > &Prev)
{
    m_RC = ANode;
}

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetLC() const
{
    return m_LC;
}

template <typename T>
void CNode<T>::setLC(const std::shared_ptr<CNode<T> > &leftChild){
    m_LC = leftChild;
}

#endif // NODE_HPP
