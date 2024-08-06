#include<string>
// #include<iostream>
class AzimuthMonitoring {
    public:
        int getAzimuth (std::string instructions[]){
            int azimuth = 360;
            for (int i = 0; i <= instructions->length(); i++)
            {
                //std::cout << azimuth << std::endl;
                if (instructions[i].length() == 5)
                {
                    //std::cout << "ping right" << std::endl;
                    azimuth = azimuth + 90;
                }
                else if (instructions[i].length() == 4 && instructions[i][0] == 'L')
                {
                    //std::cout << "ping left" << std::endl;   
                    azimuth = azimuth - 90; 
                }
                else if (instructions[i].length() == 11)
                {
                    //std::cout << "ping 180" << std::endl;   
                    azimuth = azimuth + 180;
                }
                else if (instructions[i].length() == 4 && instructions[i][0] == 'H')
                {
                    //std::cout << "ping stop" << std::endl;   
                    break;
                }
                else if (instructions[i].length() >= 6 && instructions[i][0] == 'L')
                {
                    //std::cout << "ping left x" << std::endl;   
                    azimuth = azimuth - stoi(instructions[i].erase(0,5));
                }
                else if (instructions[i].length() >= 7 && instructions[i][0] == 'R')
                {
                    //std::cout << "ping right x" << std::endl;   
                    azimuth = azimuth + stoi(instructions[i].erase(0,6));
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