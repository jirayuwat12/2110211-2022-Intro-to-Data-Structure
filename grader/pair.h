#ifndef _CP_PAIR_H // protect duplicated code
#define _CP_PAIR_H

namespace CP{ // namespace
    template <typename T1,typename T2> // template
    class pair{
        public:
            //fields
            T1 first;
            T2 second;

            // custom initializer list constructor
            pair(const T1 &a,const T2 &b) : first(a),second(b){}
            //defualt initializer list constructor
            pair() :first(),second() {}
            //copy constructor
            pair(const pair<T1,T2>& other){
                this->first = other.first;
                this->second =  other.second;
            }

            // operator overloading
            bool operator==(const pair<T1,T2> & other){
                return other.first == this->first && other.second == this->second;
            }
            bool operator<(const pair<T1,T2> & other) const{
                //                                      ^ this const mean we promise that we will not change any feilds if this class (first and second)
                return this->first < other.first || (this->first == other.first && this->second < other.second);
            }

    };
}

#endif