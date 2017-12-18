#ifndef PeopleList_h
#define PeopleList_h

#include<string>

typedef int InfoType;

class PeopleList
{
  private:
  	struct Node{
  		std::string first_name;
		std::string last_name;
		InfoType value; 
		Node *next;
		Node *prev;
	};

	Node* head;
	Node* tail;
  	bool priority(const std::string firstName, const std::string lastName,const std::string pfirst_name,const std::string plast_name);	
  public:
  	
  	PeopleList(const PeopleList& rhs){
  				int n=rhs.size();
				Node *last = NULL;
				Node *now  = new Node;	
				Node *next = new Node;
				Node *r=rhs.head;

				for(int i=0;i<n;i++){	
			//	cout<<r<<" "<<r->first_name<<" "<<r->last_name<<" "<<r->value<<endl; 
					if(i==0) head=now;		
					if(i==n-1) { now->value=r->value; 
								 now->first_name=r->first_name; 
								 now->last_name=r->last_name; 
								 now->next=NULL; 
								 now->prev=last;
								 tail=now; 
					}
					else{ 
							now->value=r->value; 
							now->first_name=r->first_name; 
							now->last_name=r->last_name; 
							now->next=next; 
							now->prev=last;
							 
						}
					last=now;
					now=next;
					next = new Node;
					r=r->next; 
				}
	  }
	  
    ~PeopleList(){
		Node *i=head;
		while(1){ 	
				if(i==NULL) break; 
				Node *p=i;
				i=i->next;	
				delete p;
	  }
	}
	const PeopleList& operator=(const PeopleList& rhs){
		
		if (this == &rhs) return *this;
		
		Node *i=head;
		while(1){ 	
				if(i==NULL) break; 
				Node *p=i;
				i=i->next;	
				delete p;
	  }
	
		
		int n=rhs.size();
		Node *last = NULL;
		Node *now  = new Node;	
		Node *next = new Node;
		Node *r=rhs.head;

		for(int i=0;i<n;i++){	
			if(i==0) head=now;		
			if(i==n-1) { 
				now->value=r->value; 
				now->first_name=r->first_name; 
				now->last_name=r->last_name; 
				now->next=NULL; 
				now->prev=last;
				tail=now; 
			}
			else{ 
				now->value=r->value; 
				now->first_name=r->first_name; 
				now->last_name=r->last_name; 
				now->next=next; 
				now->prev=last;
				tail=now;  
			}
				last=now;
				now=next;
				next = new Node;
				r=r->next; 
		}
	}
  	
    PeopleList(): head(NULL), tail(NULL)  {  }	;   
    bool empty() const;   
    int size() const;	
    bool add(const std::string& firstName, const std::string& lastName, const InfoType& value);
    bool change(const std::string& firstName, const std::string& lastName, const InfoType& value);
    bool addOrChange(const std::string& firstName, const std::string& lastName, const InfoType& value);
    bool remove(const std::string& firstName, const std::string& lastName);
    bool contains(const std::string& firstName, const std::string& lastName) const;
    bool lookup(const std::string& firstName, const std::string& lastName, InfoType& value) const;
    bool get(int i, std::string& firstName, std::string& lastName, InfoType& value) const;   
    void swap(PeopleList& other);

};
bool combine(const PeopleList& m1, const PeopleList& m2, PeopleList& result);
void psearch (const std::string& fsearch, const std::string& lsearch,const PeopleList& p1, PeopleList& result);

#endif
