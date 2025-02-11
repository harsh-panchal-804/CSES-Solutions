#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> bookings;
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        bookings.push_back({start, end, i});
    }
    
  
    sort(bookings.begin(), bookings.end());
    
  
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> roomsPQ;
    
   
    vector<int> ans(n);
    
    int roomCount = 0;
    
   
    for (auto [start, end, idx] : bookings) {
       
        if (!roomsPQ.empty() && roomsPQ.top().first < start) {
            auto [freeTime, room] = roomsPQ.top();
            roomsPQ.pop();
            ans[idx] = room;
            roomsPQ.push({end, room});
        } else {
           
            roomCount++;
            ans[idx] = roomCount;
            roomsPQ.push({end, roomCount});
        }
    }
    
  
    cout << roomCount << "\n";
    
   
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
