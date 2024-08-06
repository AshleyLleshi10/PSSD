#include <string>

class StrangeComputer {
    public:
        int setMemory (std::string mem){
            int counter = 0;
            return recurseMem(counter, mem, '0');
    }
    int recurseMem (int count, std::string original, char bit)
    {
        if (original.empty() == true)
        {
            return count;
        }
        if (original[0] != bit){
            count++;
            bit = original[0];
            original.erase(0,1);
            return recurseMem(count, original, bit);
        }
        else {
            original.erase(0,1);
            return recurseMem(count, original, bit);
        }

    }
};
