import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def sierpinski_carpet(N):
    def is_black(i, j, n):
        # If N = 0, the only cell is black
        if n == 0:
            return True
        
        # Check the central part in the current level
        block_size = 3 ** (n - 1)
        if (i // block_size) % 3 == 1 and (j // block_size) % 3 == 1:
            return False
        
        # Recur into the sub-block
        return is_black(i, j, n - 1)
    
    size = 3 ** N
    carpet = []
    
    for i in range(size):
        row = []
        for j in range(size):
            if is_black(i, j, N):
                row.append('#')
            else:
                row.append('.')
        carpet.append(''.join(row))
    
    return carpet

# Read input
N = int(input().strip())

# Generate the carpet
carpet = sierpinski_carpet(N)

# Print the carpet
for line in carpet:
    print(line)
