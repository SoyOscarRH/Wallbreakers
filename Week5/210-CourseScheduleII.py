class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(set)
        neighbors = collections.defaultdict(set)
        for course, pre in prerequisites:
            graph[course].add(pre)
            neighbors[pre].add(course)
        stack = [n for n in range(numCourses) if not graph[n]]
        result = []
        while stack:
            node = stack.pop()
            result.append(node)
            for n in neighbors[node]:
                graph[n].remove(node)
                if not graph[n]:
                    stack.append(n)
        return result if len(result) == numCourses else []
