#ifndef TMEMORY_H
#define TMEMORY_H
#include <utility>
#include "enums.h"

    template <class T>class TMemory {
        public:
        T FNumber;
        public:
        NumStates FState;

        public:
        TMemory() {
            FNumber = T();
            FState = OFF;
        }

        public: TMemory(T number) {
            FNumber = number;
            FState = OFF;
        }

        public: T Add(T number) {
            FState = ON;
            auto a = FNumber;
            auto b = number;
            FNumber = (T)(a + b);
            return FNumber;
        }

        public:
        void Clear() {
            FNumber = T();
            FState = OFF;
        }

        public:
        std::pair<T, NumStates> Edit(Commands command, T newNumber) {
            switch (command) {
                case Commands::Store:
                    FState = ON;
                    FNumber = newNumber;
                    break;
                case Commands::Add:{
                    FState = ON;
                    auto a = FNumber;
                    auto b = newNumber;
                    FNumber = (T)(a + b);
                    break;}
                case Commands::Clear:
                    Clear();
                    break;
            }
            return std::pair<T, NumStates>(FNumber, FState);
        }
    };

#endif // TMEMORY_H
