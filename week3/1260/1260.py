from queue import Queue

class Node:
    def __init__(self, num):
        self.num = num
        self.connect = []
        self.visit = False

    def connect_node(self, node_num):
        self.connect.append(node_num)

class P_1260:
    def __init__(self):
        self.N, self.M, self.V = map(int, input().split())
        self.nodes = {}
        for _ in range(self.M):
            node1, node2 = map(int, input().split())
            if node1 not in self.nodes:
                self.nodes[node1] = Node(node1)
            if node2 not in self.nodes:
                self.nodes[node2] = Node(node2)
            self.nodes[node1].connect_node(node2)
            self.nodes[node2].connect_node(node1)
        for _, node in self.nodes.items():
            node.connect.sort()
        # no connected nodes
        if self.V not in self.nodes:
            self.nodes[self.V] = Node(self.V)

    def run(self):
        start_node = self.nodes[self.V]
        self.dfs_recursive(start_node)
        print()
        self.reset_visit()
        # self.dfs_stack(start_node)
        # print()
        # self.reset_visit()
        self.bfs(start_node)

    def dfs_recursive(self, node):
        print(node.num, end=' ')
        node.visit = True
        
        for next_node_num in node.connect:
            next_node = self.nodes[next_node_num]
            if next_node.visit:
                continue
            self.dfs_recursive(self.nodes[next_node_num])

    def dfs_stack(self, node):
        stack = [node]

        while len(stack) > 0:
            top = stack.pop()
            if top.visit:
                continue

            print(top.num, end=' ')
            top.visit = True # visit check when printing
            
            for next_node_num in reversed(top.connect):
                next_node = self.nodes[next_node_num]
                if next_node.visit:
                    continue
                stack.append(next_node)

    def bfs(self, node):
        queue = Queue()
        queue.put(node)
        node.visit = True
        
        while not queue.empty():
            front = queue.get()
            print(front.num, end= ' ')

            for next_node_num in front.connect:
                next_node = self.nodes[next_node_num]
                if next_node.visit:
                    continue
                next_node.visit = True
                queue.put(next_node)

    def reset_visit(self):
        for _, node in self.nodes.items():
            node.visit = False


if __name__ == "__main__":
    P = P_1260()
    P.run()