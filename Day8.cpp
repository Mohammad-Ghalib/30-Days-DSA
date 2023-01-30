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

