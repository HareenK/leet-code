// Find the minimum number of meeting rooms necessary for conducting all the meetings. 


int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(intervals[0].end);
        int room = 1;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < pq.top()) room++;
            else pq.pop();
            pq.push(intervals[i].end);
        }
        return room;
    }
