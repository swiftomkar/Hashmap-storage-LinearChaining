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
    int static const initSize=1024;
    linkedlist arr[initSize];
    int size;
    int capacity;
#if 0
    void grow(){
        linkedlist* bkp=arr;
        T* arr=new int[capacity*2];
        capacity=2*capacity;
        for(int i=0;i<capacity;i++)
            arr[i]=-1;
        for(int i=0;i<size;i++)
            if(bkp[i]!=-1)
                rehash(bkp[i]);
    }
#endif
    int hash(T key,int n){
        int ret;
        ret=key%n;
        return ret;
    }
#if 0
    void rehash(T key){
        int pos=hash(key,capacity);
        linkedlist temp=arr[pos];
        linkedlist::iterator i(arr[pos]);
        while(!i){
            if(*i==key)
                return;
            ++i;
        }
        arr[pos]=new linkedlist ;
        arr[pos]->addfront(key);
    }
#endif
public:
    linearChaining():size(1),capacity(initSize){}

    void add(T key){
        //int pos=hash(key,capacity);
        uint64 spookyPos=SpookyHash::Hash64(&key, sizeof(key),97);
        uint32_t pos=spookyPos&(initSize-1);
        linkedlist::iterator i(arr[pos]);

        while(!i){
            if(*i==key)
                return;
            ++i;
        }
        arr[pos].addfront(key);
        size++;
    }

    int find(T key){
        //int pos=hash(key,capacity);
        uint64 spookyPos=SpookyHash::Hash64(&key, sizeof(key),97);
        uint64_t pos=spookyPos&(initSize-1);
        linkedlist find=arr[pos];
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