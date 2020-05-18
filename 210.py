class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        degree=[0]*numCourses
        mp=[[-1]for i in range(numCourses)]
        for i in prerequisites:
            degree[i[0]]+=1
            mp[i[1]].append(i[0])
        
        que=[]
        result=[]
        for i,j in enumerate(degree):
            if j==0:
                que.append(i)
        

        while que!=[]:
            t=que.pop(0)
            result.append(t)
            for i in mp[t]:
                if i>=0:
                    degree[i]-=1
                    if degree[i]==0:
                        que.append(i)
        if len(result)==numCourses:
            return result
        else:
            return []