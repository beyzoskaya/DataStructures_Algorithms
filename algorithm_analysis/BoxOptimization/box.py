
# import sys

# class Box:
#     def __init__(self, length, width, height):
#         self.length = length
#         self.width = width
#         self.height = height

#     def __lt__(self, other):
#         return (self.length * self.width) > (other.length * other.width)

# def get_max_height(boxes):
#     
#     boxes.sort(reverse = True)

#     
#     heigth = [box.height for box in boxes]

#     
#     for i in range(1, len(boxes)):
#         for j in range(i):
#             
#             if boxes[i].length < boxes[j].length and boxes[i].width < boxes[j].width:
#                 heigth[i] = max(heigth[i], heigth[j] + boxes[i].height)

#     
#     return max(heigth)

# if __name__ == '__main__':
#     # Read the input file and parse the box dimensions
#     filename = sys.argv[1]
#     with open(filename) as f:
#         n = int(f.readline().strip())
#         boxes = []
#         for i in range(n):
#             length, width, height = map(float, f.readline().split())
#             boxes.append(Box(length, width, height))

#     # Compute and print the maximum nesting depth
#     print(get_max_height(boxes))



def parse_input(file_path):
    with open(file_path, "r") as f:
        n = int(f.readline())
        boxes = []
        for i in range(n):
            dimensions = tuple(map(float, f.readline().split()))
            boxes.append(dimensions)
        return boxes


def max_nesting_depth(boxes):
    # need to sort for length attribute in non decreasing way   
    boxes.sort(reverse=True, key=lambda box: box[0])
    #iterate ıver boxes largest to smallest becasue smallest box can be put inside the largest box

    # array to keep depths
    #initialize with 1 because each box can put inside itself
    max_depths = [1] * len(boxes)

    # starting from second element to the last element becasue we already sort the boxes about length 
    for b in range(1,len(boxes)):
        for j in range(b): #iterate before boxes starting from b--> can we put before boxes to the box b 
            if boxes[j][0] > boxes[b][0] and boxes[j][1] > boxes[b][1] and boxes[j][2] > boxes[b][2]:
                max_depths[b] = max(max_depths[b], max_depths[j] + 1)

    
    return max(max_depths)

if __name__ == "__main__":
    test_cases = ['test1.txt', 'test2.txt', 'test3.txt', 'test4.txt', 'test5.txt']
    for i, test in enumerate(test_cases):
        with open(f'testCases/{test}') as f:
            n = int(f.readline())
            boxes = [tuple(map(float, f.readline().split())) for _ in range(n)]
        print(f"Test Case {i+1}: {max_nesting_depth(boxes)}")