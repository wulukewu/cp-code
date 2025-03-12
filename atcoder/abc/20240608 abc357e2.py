import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    a = [int(data[i]) - 1 for i in range(1, N + 1)]  # Convert to 0-based indexing
    
    visited = [False] * N
    in_cycle = [False] * N
    component = [-1] * N
    cycle_length = 0
    
    def find_cycle(start):
        slow, fast = start, start
        while True:
            slow = a[slow]
            fast = a[a[fast]]
            if slow == fast:
                break
        
        cycle_start = slow
        cycle_nodes = []
        while True:
            cycle_nodes.append(slow)
            slow = a[slow]
            if slow == cycle_start:
                break
        return cycle_nodes
    
    def assign_component(node, comp_id):
        stack = [node]
        while stack:
            curr = stack.pop()
            if visited[curr]:
                continue
            visited[curr] = True
            component[curr] = comp_id
            next_node = a[curr]
            if not visited[next_node]:
                stack.append(next_node)
    
    component_id = 0
    for i in range(N):
        if not visited[i]:
            cycle_nodes = find_cycle(i)
            cycle_length += len(cycle_nodes)
            for node in cycle_nodes:
                in_cycle[node] = True
                assign_component(node, component_id)
            component_id += 1
    
    # Calculate sizes of each component
    component_sizes = [0] * component_id
    cycle_sizes = [0] * component_id
    for i in range(N):
        component_sizes[component[i]] += 1
        if in_cycle[i]:
            cycle_sizes[component[i]] += 1
    
    # Calculate the number of reachable pairs
    reachable_pairs = 0
    for comp_id in range(component_id):
        cycle_size = cycle_sizes[comp_id]
        total_size = component_sizes[comp_id]
        tree_size = total_size - cycle_size
        
        # All pairs within the cycle
        reachable_pairs += cycle_size * cycle_size
        
        # All pairs from trees to any node in their cycle
        reachable_pairs += tree_size * total_size
    
    print(reachable_pairs)