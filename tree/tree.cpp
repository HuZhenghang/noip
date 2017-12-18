#include <iostream>
#include <string>
using namespace std;

typedef string ItemType;

struct WordNode {
	ItemType m_data;
	WordNode *m_left;
	WordNode *m_right;
	int occurence;
};

class WordTree {

private:
	WordNode* root;
	void aux_add(WordNode*& nodeptr, ItemType item,int time) {
		if (nodeptr == nullptr) {
			nodeptr = new WordNode;
			nodeptr->m_data = item;
			nodeptr->m_right = nullptr;
			nodeptr->m_left = nullptr;
			nodeptr->occurence = time;
			return;
		}
		if (item < nodeptr->m_data)
			aux_add(nodeptr->m_left, item,time);
		else if (item > nodeptr->m_data)
			aux_add(nodeptr->m_right, item,time);
		else nodeptr->occurence++;
	}
	void aux_destroy(WordNode*& nodeptr) {
		if (nodeptr != nullptr) {
			aux_destroy(nodeptr->m_right);
			aux_destroy(nodeptr->m_left);
			delete nodeptr;
		}
	}
	void aux_print(WordNode* nodeptr) const  {
		if (nodeptr == nullptr) return;
		aux_print(nodeptr->m_left);
		cout << nodeptr->m_data << " " << nodeptr->occurence << endl;
		aux_print(nodeptr->m_right);
	}
	int aux_count_total(WordNode* nodeptr) const {
		if (nodeptr == nullptr) return 0;
		return nodeptr->occurence +aux_count_total(nodeptr->m_left)+ aux_count_total(nodeptr->m_right);
	}
	int aux_count_distinct(WordNode* nodeptr) const {
		if (nodeptr == nullptr) return 0;
		return 1 + aux_count_distinct(nodeptr->m_left) + aux_count_distinct(nodeptr->m_right);
	}
	 WordNode* getroot() const{ return root; }
	 void aux_copy(WordNode* nodeptr) {
		 if (nodeptr == nullptr)  return;
		 aux_add(root, nodeptr->m_data,nodeptr->occurence);
		 aux_copy(nodeptr->m_left);
		 aux_copy(nodeptr->m_right);
	 }
public:
	WordTree() : root(nullptr) { };
	WordTree(const WordTree& rhs) { *this = rhs; }
	const WordTree& operator=(const WordTree& rhs) {
		if (this == &rhs) return *this;
		aux_destroy(root);
		aux_copy(rhs.getroot());
	}
	void add(ItemType v) { aux_add(root, v,1); }
	int distinctWords() const { return aux_count_distinct(root);  }
	int totalWords() const { return aux_count_total(root); }
	friend ostream& operator<<(ostream &out, const WordTree& rhs) { rhs.aux_print(rhs.getroot()); return out; }
	~WordTree() { aux_destroy(root); }
};
int main() {

		return 0;
		
		
}
