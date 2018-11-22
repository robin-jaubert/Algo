#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>


template <typename T>
class CNode
{
   private:
    T m_data;

    CNode* m_Next;

    public:
     CNode(const T & i=T(), CNode* ptr = nullptr){
         setMData(i);
         setMNext(ptr);
     }

        ~CNode(){
         std::cout << getMNext() << std::endl;
         delete m_Next;
      }

     T getMData() const {return this->m_data;}

     void setMData(T data){this->m_data = data;}

     CNode* getMNext() const {return this->m_Next;}

     void setMNext(CNode* next){this->m_Next = next;}

};


#endif // NODE_HPP
