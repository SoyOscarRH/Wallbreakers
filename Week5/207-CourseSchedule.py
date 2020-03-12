class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = collections.defaultdict(set)
        neighbors = collections.defaultdict(set)
        for course, pre in prerequisites:
            graph[course].add(pre)
            neighbors[pre].add(course)
        stack = [n for n in range(numCourses) if not graph[n]]
        count = 0
        while stack:
            node = stack.pop()
            count += 1
            for n in neighbors[node]:
                graph[n].remove(node)
                if not graph[n]:
                    stack.append(n)
        return count == numCourses
