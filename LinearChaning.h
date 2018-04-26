//
// Created by Omkar Desai on 4/3/2018.
//
#pragma once

#include <fstream>
#include "LinkedList.h"
#include "jenkins.h"
template <typename T>
class linearChaining{
private:
    int initSize;
    linkedlist<T>* arr;
    int size;
    int capacity;
    void grow(){
        linkedlist<T>* bkp=arr;
        arr=new linkedlist<T>[capacity*2];
        capacity=2*capacity;
        for(int i=0;i<capacity;i++)
            arr[i].head= nullptr;
        for(int i=0;i<size;i++)
            if(bkp[i].head!= nullptr) {
                uint64_t pos = SpookyHash::Hash64(&(bkp[i].head), capacity,97);
                linkedlist<T> temp = arr[pos];
                temp=bkp[i];
            }
    }
    int hash(T key,int n){
        int ret;
        ret=key%n;
        return ret;
    }
public:
    linearChaining(int initSize):size(0),capacity(initSize),arr(new T[initSize]){}

    void add(T key){
        if(2*capacity<size){
            grow();
        }
        //int pos=hash(key,capacity);
        uint64 spookyPos=SpookyHash::Hash64(&key, sizeof(key),97);
        uint32_t pos=spookyPos&(initSize-1);
        linkedlist<int>::iterator i(arr[pos]);

        while(!i){
            if(*i==key)
                return;
            ++i;
        }
        arr[pos].addfront(key);
        size++;
    }

    T find(T key){
        //int pos=hash(key,capacity);
        uint64 spookyPos=SpookyHash::Hash64(&key, sizeof(key),97);
        uint64_t pos=spookyPos&(initSize-1);
        linkedlist<int> find=arr[pos];
        if(find.head== nullptr)
            return -1;
        linkedlist::iterator i(arr[pos]);
        while(!i){
            if(*i==key)
                return key;
            ++i;
        }
        return -1;
    }
    void histogram(){
        std::ofstream hist;
        hist.open("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\HashHistogram.txt");
        int histArr[11]={0};
        for(int i=0;i<capacity;i++){
            if(arr[i].head!= nullptr){
                if(arr[i].size>=10)
                    histArr[10]++;
                else
                    histArr[arr[i].size]++;
            }
        }
        for(int i=1;i<=10;i++){
            hist<<histArr[i];
            hist<<"\n";
        }
        for(int i=1;i<=10;i++)
            std::cout<<histArr[i]<<" ";
        hist.close();
    }
};