#include "Node.h"

template<class T>
class List{
	private:
		class ListNode : public Node<T>{
			private:
				Node* pPrev;
			public:
				ListNode(){ pPrev = NULL; }
				virtual ~ListNode() { pPrev = NULL; }
				Node* GetPrev() { return pPrev; }
				bool SetPrev(Node* node){
					if(node == NULL)
						return false;
					else
						pPrev = node;
					return true;
				}
		};

		Node* m_pHead;
		Node* m_pTail;

		size_t m_size;
	public:
		List() {
			m_pHead = NULL;
			m_pTail = NULL;
			size = 0;
		}
		virtual ~List(){
			clear();
		}
		T front();
		T back();
		size_t size();
		bool push_front(T value);
		bool push_back(T value);
		bool pop_front();
		bool pop_back();
		bool empty();
		bool clear();
		bool insert(int num);
		bool erase(int num);
		// iterator begin
		// iterator end
		// iterator insert
		// iterator erase
};

template<class T>
T List<T>::front(){
	return m_pHead->value;
}

template<class T>
T List<T>::back(){
	return m_pTail->value;
}

template<class T>
size_t List<T>::size(){
	return m_size;
}

template<class T>
bool List<T>::push_front(T value){
	Node* node = new ListNode;
	if( NULL == node )
		return false;
	node->SetValue(value);
	
	if( NULL == m_pHead && m_pHead == m_pTail ){
		m_pHead = node;
		m_pTail = node;
	}
	else{
		node->SetNext(m_pHead);
		m_pHead = node;
	}
	m_size++;
	return true;
}

template<class T>
bool List<T>::push_back(T value){
	Node* node = new ListNode;
	if( NULL == node )
		return false;
	node->SetValue(value);

	if( NULL == m_pTail && m_pTail == m_pHead ){
		m_pHead = node;
		m_pTail = node;
	}
	else{
		m_pTail->SetNext(node);
		m_pTail = node;
	}
	m_size++;
	return true;
}

template<class T>
bool List<T>::pop_front(){
	Node* temp = m_pHead;
	if( NULL == temp )
		return false;
	m_pHead = m_pHead->GetNext();
	delete temp;
	m_size--;
	return true;
}

template<class T>
bool List<T>::pop_back(){
	Node* temp = m_pTail;
	if( NULL == temp )
		return false;
	m_pTail = m_pTail->GetPrev();
	delete temp;
	m_size--;
	return true;
}

template<class T>
bool List<T>::empty(){
	if( 0 == m_size ){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
bool List<T>::clear(){
	return true;
}

template<class T>
bool List<T>::insert(int num){
}

template<class T>
bool List<T>::erase(int num){
}
