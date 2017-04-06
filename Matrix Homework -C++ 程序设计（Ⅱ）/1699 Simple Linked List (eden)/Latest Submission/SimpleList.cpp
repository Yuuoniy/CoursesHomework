#include "SimpleList.hpp"
#include <sstream>
  list::list(){
    head = NULL;
    _size = 0;
  }
  list::list(const list& other){
      head = NULL;
      _size = 0;
      *this = other;
  }
  list& list::operator=(const list& other){
      if(this==&other)
        return *this;
      clear();
      if(other.head==NULL)
         return *this;     
      node* temp = other.head;
      node* tail = NULL;
      while(temp!=NULL){
          if(head==NULL){
            head = new node(temp->data);
            tail = head;
          }
          else{
            tail->next = new node (temp->data);
            tail = tail->next;
          }
          temp = temp->next;
      }
      _size = other._size;     
    return *this;
  }
  
  list::~list(){
    clear();
  }
 
  // Capacity
  bool list::empty(void) const{
    return _size==0?true:false;
  }
  int list::size(void) const{
    return _size;
  }
  std::string list::toString(void) const{
      std::string str = "";
      std::string shorts;
      if(_size==0)
        str = "NULL";
      else{
        node *temp = head;
        while(temp!=NULL){
          std::stringstream ss;
          ss << temp->data;
          ss >> shorts;
          str +=  shorts +"->";
          temp = temp->next;
        }
        str += "NULL";   
      }
      return str;
  }
 
  void list::insert(int position, const int& data){
    if(position>_size||position<0)
      return ;
      if(head==NULL||position==0){
         node*temp = new node(data);
         temp->next = head;
         head = temp;
         _size++;
       }
      else {
        node* find = head;
        for(int i = 0;i<position-1;i++){
          find = find->next;
        }
        _size++;
        node* temp = new node(data);
        temp->next = find->next;
        find->next = temp;
      }
  }

  void list::erase(int position){
    if(position<0||position>=_size)
      return ;
    else if(position==0){
      node* temp = head;
      head = head->next;
      _size--;
      delete temp;
    }
    else{
      node* find = head;
      for(int i = 0;i<position-1;i++){
          if(find==NULL||find->next==NULL)
            return;
          find = find->next;
      }
      _size--;
      node*del = find->next;
      find->next = del->next;
      delete del;
    } 
  }


  list& list::sort(void){
    if(head==NULL||head->next==NULL)
      return *this;
    node* i = head;
    node* j = head;
    int temp = 0;
    for(;i->next;i=i->next){
      for(j=head;j->next;j=j->next){
        if(j->next==NULL)
          break;
        if(j->data>j->next->data){
            temp = j->next->data;
            j->next->data = j->data;
            j->data = temp;
        }
      }
    }
    return *this;
      
}
      
  

 
