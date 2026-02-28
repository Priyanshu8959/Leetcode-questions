class Solution {
public:

bool check(long long diff , vector<int>& position, int m){

    int last = position[0];
    int count = 1;

    for(int i = 1; i < position.size(); i++){
        if(position[i] - last >= diff){
            count++;
            last = position[i];
        }
    }

    return count >= m;
}

int maxDistance(vector<int>& position, int m) {

    sort(position.begin(), position.end());

    long long n = position.size();

    long long low = 1;

    long long high = position[n-1] - position[0];

    long long ans = 0;

    while(low <= high){

        long long guess = low + (high - low) / 2;

        if(check(guess, position, m)){
            ans = guess;
            low = guess + 1;  // move right for max distance
        }
        else{
            high = guess - 1;
        }
    }

    return ans;
}
};