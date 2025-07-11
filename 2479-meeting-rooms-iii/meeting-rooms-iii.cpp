class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> freq(n, 0);
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        sort(meetings.begin(), meetings.end());

        // Use min-heap of (end_time, room)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];
            long long duration = end - start;

            // Free up rooms
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            int room;
            long long actualStart;

            if (!availableRooms.empty()) {
                // Assign room immediately
                room = availableRooms.top();
                availableRooms.pop();
                actualStart = start;
            } else {
                // Delay meeting to earliest end time
                auto [earliestEnd, delayedRoom] = busyRooms.top();
                busyRooms.pop();
                room = delayedRoom;
                actualStart = earliestEnd;
            }

            freq[room]++;
            busyRooms.push({actualStart + duration, room});
        }

        // Find room with max frequency
        int maxCount = -1, resultRoom = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] > maxCount) {
                maxCount = freq[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
