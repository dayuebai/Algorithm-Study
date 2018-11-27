
def recursive_find_lake(map_area,explored,x,y,height, width):
    if x >= width or x < 0 or y >= height or y <0:
        return
    elif map_area[y][x] == 1:
        return 
    elif (y,x) in explored:
        return
    else:
        explored.add((y,x))
        recursive_find_lake(map_area,explored,x - 1,y,height, width)
        recursive_find_lake(map_area,explored,x + 1,y,height, width)
        recursive_find_lake(map_area,explored,x,y - 1,height, width)
        recursive_find_lake(map_area,explored,x,y + 1,height, width)

def find_zero(map_area, height, width, lake):
    for i in range(height):
        for j in range(width):
            if map_area[i][j] == 0 and (i,j) not in lake:
                return (i,j)
            
def find_mini(lake1, lake2):
    smallest = 10000000
    for i in lake1:
        for j in lake2:
            distance = abs(i[0] - j[0]) + abs(i[1] - j[1]) - (1 if i[0] == j[0] or \
                       i[1] == j[1] else 0)
            if distance < smallest:
                smallest = distance
    print(smallest)
def solve(map_area,height, width):
    lake1 = set()
    lake2 = set()
    
    first_y, first_x = find_zero(map_area,height, width, lake1)
    
    recursive_find_lake(map_area,lake1, first_x, first_y, height, width)
    print(lake1)
    
    first_x = 0
    first_y = 0
    first_y, first_x = find_zero(map_area,height, width, lake1)
                
    recursive_find_lake(map_area,lake2, first_x, first_y, height, width)
    print(lake1, lake2)
    find_mini(lake1, lake2)

if __name__ == "__main__":
    #test_num = int(input())  #number of testcases
    height = int(input())
    width = int(input())
    map_area = []

    
    for i in range(height):
        line = [int(i) for i in input().strip().split()]
        map_area.append(line)
        
    solve(map_area,height,width)
    print(map_area)
