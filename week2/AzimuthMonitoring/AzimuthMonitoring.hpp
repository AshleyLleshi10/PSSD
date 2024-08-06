#include<string>
#include<vector>
#include<iostream>
using namespace std;

class AzimuthMonitoring {
    public:
        int getAzimuth (vector<string> instructions){
            int azimuth = 360;
            for (int i = 0; i <= instructions.size(); i++)
            {
                string c = instructions[i];
                //std::cout << azimuth << std::endl;
                if (instructions[i].size() == 5)
                {
                    //std::cout << "ping right" << std::endl;
                    azimuth = azimuth + 90;
                }
                else if (c.length() == 4 && c[0] == 'L')
                {
                    //std::cout << "ping left" << std::endl;   
                    azimuth = azimuth - 90; 
                }
                else if (c.length() == 11)
                {
                    //std::cout << "ping 180" << std::endl;   
                    azimuth = azimuth + 180;
                }
                else if (c == 4 && c[0] == 'H')
                {
                    //std::cout << "ping stop" << std::endl;   
                    break;
                }
                else if (c.length() >= 6 && c[0] == 'L')
                {
                    //std::cout << "ping left x" << std::endl;   
                    azimuth = azimuth - stoi(c.erase(0,5));
                }
                else if (c.length() >= 7 && c[0] == 'R')
                {
                    //std::cout << "ping right x" << std::endl;   
                    azimuth = azimuth + stoi(c.erase(0,6));
                }
            }

            if (azimuth < 0)
            {
                azimuth = azimuth + 360;
            }
            else if (azimuth > 360)
            {
                azimuth = azimuth - 360;
            }
            return azimuth;
        }
};
