class TaskManager {
public:
    //priority_queue< pair< pair<int, int>, int> > pq;
    // priority_queue< pair<int, priority_queue<pair<int, int>> >> pq;
    priority_queue<int> pq;
    unordered_map<int,int> taskToUser;
    unordered_map<int, int> userToPriority; 
    unordered_map<int, priority_queue<int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i<tasks.size(); i++){
            int usedId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];

            //pq.push({{priority, taskId},userId});

            //pq.push({priority, {taskId, userId}});
            pq.push(priority);
            mp[priority].push(taskId);
            taskToUser[taskId] = userId;
            userToPriority[userId] = priority;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        //pq.push({{priority, taskId},userId});

        //pq.push({{priority},{taskId,userId}});

        pq.push(priority);
        mp[priority].push(taskId);
        taskToUser[taskId] = userId;
        userToPriority[userId] = priority;
        return;
    }
    
    void edit(int taskId, int newPriority) {
        int priority = mp[taskId];
        for(auto &it : pq){
            if(it.first.second == taskId){
                it.first.first = newPriority;
                break;
            }
        }
        return;
    }
    
    void rmv(int taskId) {
        priority_queue< pair< pair<int, int>, int> > temp;
        priority_queue< pair< pair<int, int>, int> >
        
        while(!pq.empty() && pq.top().first.second != taskId){
            temp.push(pq.top());
            pq.pop();
        } 
        pq.pop();
        for(int i = 0; i<v.size(); i++){
            pq.push(temp[i]);
        }
        return;
    }
    
    int execTop() {
        int userId = pq.top().second;



        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
