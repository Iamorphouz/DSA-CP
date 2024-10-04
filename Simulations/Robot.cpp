// L left in place
// G one step
// R right in place

// intuition:
// If after one set of commands
// robot is at (0, 0) or
// change in diretion
// then it will have a loop
#include <string>
using namespace std;
class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int dirX = 0, dirY = 1;
        int x = 0, y = 0;
        for (char &i : instructions)
        {
            if (i == 'G')
                x = x + dirX, y = y + dirY;
            else if (i == 'L')
            {
                swap(dirX, dirY);
                dirX = -1 * dirX;
            }
            else
            {
                swap(dirX, dirY);
                dirY = -1 * dirY;
            }
            // cout<<x<<" "<<y<<endl;
            // cout<<dirX<<" "<<dirY<<endl;
        }
        return (x == 0 && y == 0) || !(dirX == 0 && dirY == 1);
        // return (x == 0 && y == 0) or (dirX != 0 && dirY != 1);  // fails at "LLGRL"

        // return                       fails at "LGR"
        // ((x, y) == (0, 0))
        //  ||
        // ((dirX, dirY) != (0, 1));
    }
};