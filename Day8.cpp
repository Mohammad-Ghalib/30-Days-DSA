//1 N meetings in one room

    int maxMeetings(int start[], int end[], int n){
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++) v.push_back({end[i], start[i]});
        
        sort(v.begin(), v.end());
        
        int ans=1, endTime = v[0].first;
        
        for(int i=1; i<n; i++){
            if(v[i].second > endTime){
                ans++;
                endTime = v[i].first;
            }
        }
        
        return ans;
    }

//2 Minimum no. of platforms

    int findPlatform(int arr[], int dep[], int n){
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int platReq=1, ans=1, i=1, j=0;
        
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                platReq++;
                i++;
            }
            else{
                platReq--;
                j++;
            }
            
            ans = max(ans, platReq);
        }
        
        return ans;
    }

//3 Job sequencing problem

    static bool comparison(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n){
        
        sort(arr, arr+n, comparison);
        int maxi = arr[0].dead, jobs=0, ans=0;
        
        for(int i=1; i<n; i++) maxi = max(maxi, arr[i].dead);
        
        int slot[maxi+1];
        memset(slot, -1, sizeof(slot));
        
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    ans += arr[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        
        return {jobs, ans};
    } 

//4 Fractional Knapsack

    static bool compare(Item i1, Item i2){
        return (double)i1.value/(double)i1.weight > (double)i2.value/(double)i2.weight;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr+n, compare);
        
        double ans=0;
        
        for(int i=0; i<n && W>0; i++){
            if(W >= arr[i].weight){
                ans += arr[i].value; 
                W -= arr[i].weight;
            }
            else{
                ans += ((double)arr[i].value/(double)arr[i].weight)*(double)W;
                W=0;
            }
        }
        
        return ans;
    }

//5 Greedy Algo to find min. no. of coins 
//(will work only if c[i] > c[i-1]+c[i-2])

	int minCoins(int coins[], int M, int V){ 
	    sort(coins, coins+M, greater<int>());
	    int ans=0, i=0;
	    while(V && i<M){
	        ans += V/coins[i];
	        V -= (V/coins[i])*coins[i];
	        i++;
	    }
	    
	    return ans;
	} 

//6 -> Same as N meetings in 1 room