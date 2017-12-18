#include <iostream>
#include <string>
using namespace std;
        
typedef string ItemType;
        
struct Node {
    ItemType value;
    Node *next;
};
        
class LinkedList {    
	private:
        Node *head;
            
    public:
        LinkedList() : head(NULL) {  }	
        
		LinkedList(const LinkedList& rhs){
				int n=rhs.size();
				Node *p1 = new Node;
				Node *p2 = new Node;	
				Node *cur=rhs.head;
				head=p1;
				for(int i=0;i<n;i++){				
					if(i==n-1) { p1->value=cur->value; p1->next=NULL; }
					else{ p1->next = p2;  p1->value = cur->value; cur=cur->next; }
					p1=p2;
					p2=new Node;
				}	
		} 
         ~LinkedList(){
		 		Node *i=head; 
				while(1){
					if(i==NULL) break; 		
					Node *p=i;
					i=i->next;	
					delete p;
				}
		 }
        
		const LinkedList& operator=(const LinkedList& rhs){
			if (this == &rhs) return *this;
			Node *i=head; 
				while(1){
					if(i==NULL) break; 		
					Node *p=i;
					i=i->next;	
					delete p;
				}

			int n=rhs.size();
			Node *p1 = new Node;
			Node *p2 = new Node;	
			Node *cur=rhs.head;
			head=p1;
			for(int i=0;i<n;i++){				
				if(i==n-1) { p1->value=cur->value; p1->next=NULL; }
				else{ p1->next = p2;  p1->value = cur->value; cur=cur->next; }
				p1=p2;
				p2=new Node;
			}		
				return *this;
		}
        
		void insertToFront(const ItemType &val){
			Node *cur = new Node;
			cur->next=head;
			cur->value=val;
			head = cur;	
		}
        
		void printList() const{
				Node *i=head; 
				while(1){
					if(i==NULL) break; 	
					cout<<i->value<<" ";
					i=i->next;	
				}
				cout<<endl;	
		}
        
		bool get(int i, ItemType& item) const{
    		Node *p=head;
			while(i>0){
				if(p==NULL) return false;
    			p=p->next;
    			i--;
			}
			item = p->value;
			return true;
	}
		void reverseList(){
			
			Node *pre=NULL;
			Node *cur=head;
			Node *n=head->next;
			while(1){
				cur->next=pre;
				pre=cur;	
				cur=n;	
				if(n==NULL) {
					head=pre; 
					break;
				}
				n=n->next;			
			}
		} 
        
        void printReverse() const{
        	Node *p=head; 
			int n=this->size();	   	
        	ItemType op[n];
        	for(int i=n-1;i>=0;i--){
        		op[i]=p->value;
        		p=p->next;
			}
			for(int i=0;i<n;i++) cout<<op[i]<<" "; cout<<endl;
		}
        
        void append(const LinkedList &other){

        	if(this->size()==0) {
        		Node *i = new Node;
				Node *p = new Node;	
				Node *h=other.head; 
        		for(int k=0;k<other.size();k++){
					if(k==0){ head = p;}
        			p->value = h->value;
        			p->next = i;
        			i = new Node;
        			p=p->next;
        			h=h->next;
				}
					p->next=NULL;
			}
        	else{
        			Node *i=head;	
					Node *h=other.head; 
					while(1){  if(i->next==NULL) break; i=i->next; }
				
					for(int k=0;k<other.size();k++){
						Node *p = new Node;
						i->next=p;
						p->value=h->value;
						h=h->next;
						i=i->next;
					}
					i->next=NULL;
			}
		} 
        
        void swap(LinkedList &other){
        	Node *temp = head;
			head = other.head;
			other.head = temp;
		} 
        
        int size() const{
        	int num=0;
			Node *p=head;
			while(1){ if(p==NULL) return num; p=p->next; num++; }
    }
};
int main(){	
    LinkedList e1;
    e1.insertToFront("A");
    e1.insertToFront("B");
    e1.insertToFront("C");
    e1.insertToFront("D");
    LinkedList e2;
    e2.insertToFront("X");
    e2.insertToFront("Y");
    e2.insertToFront("Z");
    e2=e2;
	 
	 e1.printList();
e2.printList();

    return 0;
}
