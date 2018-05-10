#include <iostream>
#include <string>

namespace queue{
    const bool DEBUG_MODE=false;
    template <class T>
    class Queue{
        private:
            void logger(std::string args){
                if(DEBUG_MODE == true){
                    std::cout<<args<<std::endl;    
                }
            }
            T l[4];
            T* list = l;
            int size=0;
            int readPosition=0;
            int capacity=4;
            void ensureCapacity(){
                if(size == capacity){
                    capacity *= 2;
                    T * temp = new T [capacity];
                    for(int i=0; i<size; i++){
                        temp[i]=list[i];
                    }
                    list=temp;
                }
            }
            void compact(){
                if( readPosition > size/2){
                    capacity *= .75;
                    T * temp = new T [capacity];
                    for(int i=0; i<size; i++){
                        temp[i]=list[readPosition + i];
                    }
                    list=temp;
                }
            }
        public:
            void push(T item){
                ensureCapacity();
                list[size] = item;
                size++;
            };
            T pop(){
                T retVal;
                if(size >0){
                    retVal = list[readPosition];
                    readPosition++;
                    compact();
                }
                return retVal;
            };
            T peek(){
                T retVal;
                if(size > readPosition){
                    retVal = list[readPosition];
                }
                return retVal;
            }
            void clear(){
                size=0;
                readPosition=0;
                capacity=4;
                T* temp = new T [4];
                list=temp;
            }
    };
}
