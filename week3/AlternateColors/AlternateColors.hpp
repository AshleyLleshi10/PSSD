#include<string>
#include<vector>
class AlternateColors{
    public:
        std::string getColor(long r, long g, long b, long k){
            std::vector<long> ballVector({r, g, b});
            std::vector<std::string> colourVector ({"RED", "GREEN", "BLUE"});
            int counter = 0;
            std::string head;
            for (int i = 1; i <= k; i++)
            {
                if (counter > ballVector.size() - 1)
                {
                    counter = 0;
                }

                if (ballVector[counter] > 1000000000)
                {
                    ballVector[counter] = ballVector[counter] - 100000000;
                }
                ballVector[counter]--;
                head = colourVector[counter];

                if (ballVector[counter] == 0)
                {
                    ballVector.erase(ballVector.begin() + counter);
                    colourVector.erase(colourVector.begin() + counter);
                    counter--;
                    if (ballVector.empty() == true)
                    {
                        break;
                    }
                }

                counter++;
            }
            return head;
        }
};
