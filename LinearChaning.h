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
    linkedlist* arr;
    int size;
    int capacity;
    void grow(){
        linkedlist* bkp=arr;
        int bkpCapacity=capacity;
        arr=new linkedlist[capacity*2];
        capacity=2*capacity;
        for(int i=0;i<capacity;i++)
            arr[i].head= nullptr;
        for(int i=0;i<bkpCapacity;i++)
            if(bkp[i].head!= nullptr) {
                linkedlist::iterator iter(bkp[i]);
                while(!iter){
                    add(*iter);
                }
                //uint64_t pos = SpookyHash::Hash64(&(bkp[i].head), capacity,97);
                int pos=hash(bkp[i].head->data,capacity);
                linkedlist temp = arr[pos];
                temp=bkp[i];
            }
    }

    int hash(std::string key,int n){
        int ret;
        std::string myKey=std::string(key);
        int strsum=0;
        for(int i=0;i<myKey.length();i++){
            strsum+=key[i];
        }
        ret=strsum%n;
        return ret;
    }
public:
    linearChaining(int initSize=10):size(0),capacity(initSize),arr(new linkedlist[initSize]){}

    void add(std::string key){
        if(2*size>=capacity){
            grow();
        }
        int pos=hash(key,capacity);
        //uint64 spookyPos=SpookyHash::Hash64(&key, sizeof(key),97);
        //uint64_t pos=spookyPos&(initSize-1);
        linkedlist::iterator i(arr[pos]);
        if(!i==0){
            size++;
        }
        while(!i){
            if(*i==key)
                return;
            ++i;
        }
        arr[pos].addfront(key);
    }

    std::string find(std::string key){
        int pos=hash(key,capacity);
        //uint64 spookyPos=SpookyHash::Hash64(&key, sizeof(key),97);
        //uint64_t pos=spookyPos&(initSize-1);
        //linkedlist<int> find=arr[pos];
        if(arr[pos].head== nullptr)
            return "-1";
        linkedlist::iterator i(arr[pos]);
        while(!i){
            if(*i==key)
                return key;
            ++i;
        }
        return "-1";
    }
    void readList(std::string filename){
        std::ifstream file;
        file.open(filename);
        while(!file.eof()){
            std::string wordHolder;
            file>>wordHolder;
            add(wordHolder);
        }
    }
    void checkList(std::string filename){
        std::ifstream file;
        file.open(filename);
        while(!file.eof()){
            std::string wordHolder;
            file>>wordHolder;
            std::cout<<find(wordHolder)<<'\n';
        }
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
        for(int i=1;i<=10;i++) {
            if (i == 10)
                std::cout << "Number of bins with " << i << " and more elements: " << histArr[i] << "\n";
            else
                std::cout << "Number of bins with " << i << " elements: " << histArr[i] << "\n";
        }
        hist.close();
    }
};