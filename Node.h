template<class T>
class Node{
	private:
		Node* pNext;
		T value;
	public:
		Node(){ pNext = NULL; memset(&value, 0, sizeof(T)); }
		virtual ~Node(){ pNext = NULL; memset(&value, 0, sizeof(T)); }
		Node* GetNext(){ return pNext; }
		bool SetNext(Node* node){
			if(node == NULL)
				return false;
			else
				pNext = node;
			return true;
		}
		T GetValue(){ return value; }
		bool SetValue(T &input){
			if(input == NULL)
				return false;
			else
				value = input;
			return true;
		}
};
