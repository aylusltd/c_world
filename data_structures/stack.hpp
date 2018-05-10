#include <iostream>
#include <string>

namespace stack{
    const bool DEBUG_MODE=false;
    template <class T>
    class Stack{
        private:
            void logger(std::string args){
                if(DEBUG_MODE == true){
                    std::cout<<args<<std::endl;    
                }
            }
            T l[4];
            T* list = l;
            int size=0;
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
                if( size<(capacity/2) && (capacity - size) > 10){
                    capacity *= .75;
                    T * temp = new T [capacity];
                    for(int i=0; i<size; i++){
                        temp[i]=list[i];
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
                    retVal = list[size-1];
                    size--;
                    compact();
                }
                return retVal;
            };
            T peek(){
                T retVal;
                if(size >0){
                    retVal = list[size-1];
                }
                return retVal;
            }
            void clear(){
                size=0;
                capacity=4;
                T* temp = new T [4];
                list=temp;
            }
    };
}
