#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte() {
    if(head==nullptr)
    return;

    Node* atual=head;
    Node* posterior=head->next;
    Node* anterior=nullptr;
    tail=atual;
   
    
    while(posterior!=nullptr)
    {
      atual->next=anterior;
      anterior=atual;
      atual=posterior;
      posterior=posterior->next;
    }
    atual->next=anterior;
    head=atual;

}