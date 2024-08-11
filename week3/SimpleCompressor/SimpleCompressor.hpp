#include <string>
//#include <iostream>
class SimpleCompressor {
    public:
        std::string uncompress (std::string data) {
            int repeats = 1;
            std::string returnString;
            return recur(data, repeats, returnString);
        }
        std::string recur (std::string comData, int nRepeats, std::string uncData){
            //std::cout << "compresed" << comData << std::endl;
            //std::cout << "uncompresssed" << uncData << std::endl;
            char head;
            if (comData.empty() == true){
                return uncData;
            }
            if (nRepeats == 0)
            {
                nRepeats = 1;
            }
            if (comData[0]=='1'||comData[0]=='2'||comData[0]=='3'||comData[0]=='4'||comData[0]=='5'||comData[0]=='6'||comData[0]=='7'||comData[0]=='8'||comData[0]=='9'){
                nRepeats = nRepeats * (comData[0] - '0');
                comData.erase(0,1);
            }
                head = comData[0];
                if (head == ']'){
                    //s std::cout<< "pointing to " << comData[0] << std::endl; 
                    comData.erase(0,1);
                    return recur(comData, nRepeats, uncData);
                }
                if (head == '[')
                {
                    comData.erase(0,1);
                    return recur(comData, nRepeats, uncData);
                }
                if (nRepeats == 1){
                    uncData.push_back(comData[0]);
                    comData.erase(0,1);
                }
                if (nRepeats != 1){
                    int pointTo = 0;
                    while (head != ']')
                    {
                        head = comData[pointTo];
                        if (head == ']'){
                            break;
                        }
                        uncData.push_back(comData[pointTo]);
                        pointTo++;
                    }
                }
            return recur(comData, nRepeats - 1, uncData);
        }
};
