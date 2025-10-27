class Solution {
public:
    void backtracking(int to, int index, int hour, int minutes, vector<string>& result)
    {
        if(to == 0)
        {
            if( hour < 12 && minutes < 60)
            {
                result.push_back( to_string(hour)+ ":" +
                             (minutes < 10 ? "0" : "") + to_string(minutes));
            }
            return;
        }

        if( index >= 10)
            return;
        
        if( index < 4)
        {
            backtracking(to - 1, index + 1, hour + (1 << index), minutes, result);
        }
        else
        {
            backtracking(to - 1, index + 1, hour, minutes+ (1 << (index - 4)), result);
        }
        backtracking(to, index + 1, hour, minutes, result);
    }

    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> result;

        backtracking(turnedOn,0,0,0,result);
        return result;    
    }
};