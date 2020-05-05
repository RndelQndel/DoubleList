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
	public:
		List(){}
		~List(){}
}
