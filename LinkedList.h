//
// Created by Omkar Desai on 4/3/2018.
//
#pragma once
#include <iostream>

class linkedlist{
public:
    class node{
    public:
        int data;
        node* next;
        node(int data, node* next):data(data),next(next){}
    };
    node* head;
    int size=0;

    linkedlist():head(nullptr){}
    //**************************
    void addfront(int v){
        node* temp=new node(v,head);
        head=temp;
        size++;
    }
    //***********************

    void addback(int v){
        if(head== nullptr)
            addfront(v);
        else {
            size++;
            node *temp = new node(v, nullptr);
            node *i;
            for (i = head; i->next != nullptr; i = i->next);
            i->next = temp;
        }
    }
    int removefront(){
        if(head== nullptr)
            return 0;
        node* rem=head;
        int data=rem->data;
        head=rem->next;
        delete rem;
        size--;
        return data;
    }
    void removeback(){
        if(head== nullptr)
            return;
        node* i;
        for(i=head;i->next->next!= nullptr;i=i->next);
        node* rem=i->next;
        i->next= nullptr;
        size--;
        delete rem;
    }
    int listSize(){
        return size;
    }
    friend std::ostream& operator <<(std::ostream& s, const linkedlist& l){
        for (node* p = l.head; p != nullptr; p = p->next)
            s << p->data << ' ';
        return s;
    }
    class iterator {
    private:
        node* current;
    public:
        iterator(const linkedlist &myList) {
            current = myList.head;
        }

        bool operator!() const {
            return current != nullptr;
        }

        iterator &operator++() {
            current = current->next;
            return *this;
        }

        int operator*() const {
            return current->data;
        }
    };
};