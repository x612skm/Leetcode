//using sieve_of_eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n+1];
        if(n == 0) return 0;
        for(int i=0; i<=n; i++)
            isPrime[i] = true;
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2; i*i<n; i++){
            if(isPrime[i] == true){
                //loop through it multiples and mark them as false;
                for(int j= i*i; j<=n; j+= i){
                    //make all the multiples mark as the false
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(isPrime[i] == true)
                count++;
        }
        return count;
    }
};