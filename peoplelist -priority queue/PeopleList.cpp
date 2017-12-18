#include "PeopleList.h"

bool PeopleList::priority(const std::string firstName, const std::string lastName,const std::string pfirst_name,const std::string plast_name){
	if(firstName<pfirst_name) return true;
	else if(pfirst_name<firstName) return false;
	else if(lastName<plast_name) return true;
	return false;
}


int PeopleList::size() const{
			int num=0;
			Node *p=head;

			while(1){ 
			
					if(p==NULL) return num; 
					p=p->next; 
					num++; 
					
					}

}

bool PeopleList::empty() const{
	if(head==NULL) return true;
	return false;

}

bool PeopleList::remove(const std::string& firstName, const std::string& lastName){
		Node *p=head;
		while(1){ 	
				if(p==NULL) return false; 
				if(p->first_name==firstName && p->last_name==lastName) {
					if(p==head){
						if(head!=tail){
							head=p->next;
							head->prev=NULL;
							delete p;
						}
						else{
							head=NULL; tail=NULL;
							delete p;
						}
						return true;
					}
					else if(p==tail){
	
						tail=p->prev;
						tail->next=NULL;
						delete p;
						return true; 
					}
					else{
						
						p->prev->next=p->next;
						p->next->prev=p->prev;
						delete p;
						return true;
					}
					
				}
				p=p->next; 		
	 }
	
}

bool PeopleList::contains(const std::string& firstName, const std::string& lastName) const{
		Node *p=head;
		while(1){ 	
				if(p==NULL) return false; 
				if(p->first_name==firstName && p->last_name==lastName) return true;
				p=p->next; 		
	 }
}

bool PeopleList::lookup(const std::string& firstName, const std::string& lastName, InfoType& value) const{
		Node *p=head;
		while(1){ 	
				if(p==NULL) return false; 
				if(p->first_name==firstName && p->last_name==lastName) {
					value=p->value;
					return true;
				}
				p=p->next; 		
	 }
}



bool PeopleList::get(int i, std::string& firstName, std::string& lastName, InfoType& value) const{
	if( i<0 || i>size() ) return false;
		Node *p=head;
		while(1){ 	
				if(i==0) {
					firstName=p->first_name;
					lastName=p->last_name;
					value=p->value;
					return true;
				}
				p=p->next; 	
				i--;	
	 }
}

void  PeopleList::swap(PeopleList& other){
	Node *h=head;
	Node *t=tail;
	head=other.head;
	tail=other.tail;
	other.head=h;
	other.tail=t;
}


bool PeopleList::change(const std::string& firstName, const std::string& lastName, const InfoType& value) {
		Node *p=head;
		while(1){ 	
				if(p==NULL) return false; 
				if(p->first_name==firstName && p->last_name==lastName) {
					p->value=value;
					return true;
				}
				p=p->next; 		
	 }
}

bool PeopleList::add(const std::string& firstName, const std::string& lastName, const InfoType& value){
	Node *a=new Node;
	a->first_name=firstName; a->last_name=lastName; a->value=value; 
	Node *p=head;
	if( empty() ){
		head=a;
		tail=a;
		a->prev=NULL;
		a->next=NULL;
		return true;
	}
	while(1){ 
			if( p->first_name==firstName && p->last_name==lastName ) return false; 
			else if( priority(firstName,lastName,p->first_name,p->last_name) ){
				if(p==head) {
					head=a;
					a->prev=NULL;
					a->next=p;
					p->prev=a;
				}
				else{
					a->prev=p->prev;
					a->next=p;
					p->prev->next=a;
					p->prev=a;	
				}
				return true;
			}
			else if(p->next==NULL){
				a->next=NULL;
				a->prev=tail;
				tail->next=a;
				tail=a;
				return true;
			}
			p=p->next; 
	}
}

bool PeopleList::addOrChange(const std::string& firstName, const std::string& lastName, const InfoType& value){
	if( contains(firstName,lastName) ) change(firstName,lastName,value);
	else add(firstName,lastName,value);
	return true;
	
}

 bool combine(const PeopleList& m1, const PeopleList& m2, PeopleList& result){
 	
 	PeopleList a=m1;
	bool flag=0;

	for (int n = 0; n < m2.size(); n++)
    {
        std::string f;
         std::string l;
        InfoType v;
        m2.get(n, f, l, v);
        if( a.contains(f,l) )
        	for (int m = 0; m < a.size(); m++){
       		 std::	string f1;
       		 std::	string l1;
        		InfoType v1;
        		a.get(m, f1, l1, v1);
        		if(f1==f && l1==l && v!=v1) flag=1;
}
		
		else a.add(f,l,v);

    }
	result=a;
	
	if(flag) return false;
	return true;
	
}

void psearch (const std::string& fsearch, const std::string& lsearch, const PeopleList& p1, PeopleList& result){
   PeopleList a;
			 	
        for (int n = 0; n < p1.size(); n++){
         std::string f;
         std::string l;
        InfoType v;
        p1.get(n, f, l, v);
        if( (f==fsearch || fsearch=="*") && (l==lsearch || lsearch=="*")  ) a.add(f,l,v);  
    }
	result=a;
}


