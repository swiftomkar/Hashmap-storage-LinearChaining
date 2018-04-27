//
// Created by Omkar Desai on 4/3/2018.
//
#pragma once
#include <iostream>
#include <string>
class linkedlist{
public:
    class node{
    public:
        std::string data;
        node* next;
        node(std::string data, node* next):data(data),next(next){}
    };
    node* head;
    int size=0;

    linkedlist():head(nullptr){}
    //**************************
    void addfront( std::string v){
        node* temp=new node(v,head);
        head=temp;
        size++;
    }
    //***********************

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

        std::string operator*() const {
            return current->data;
        }
    };
};