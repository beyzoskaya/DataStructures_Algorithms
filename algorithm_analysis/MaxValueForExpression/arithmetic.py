

def isOperator(op):
    return (op == '+' or op == '*' or op == '-')

#string s and memoization dictionary
#recursive --> store the previous calculations

def MaximizeExpression(s, memo={}):
    if s in memo:
        # if the subproblem is already calculated, no need to calculate again
        return memo[s]
    number = []
    operand = []
    #for getting the next number
    tmp = ""

    # separating operators and digits from the string input
    for i in range(len(s)):
        if (isOperator(s[i])):
            #if the character is operand then addded to the opr
            operand.append(s[i])
            #other than that added to the num
            number.append(int(tmp))
            tmp = ""
        else:
            tmp += s[i]

    # keeping last number
    number.append(int(tmp))

    #diagonal elements take the digit values 
    #other than that takes the -inf because they are not calculated
    n = len(number)
    minVal = [[0 for i in range(n)] for i in range(n)]
    maxVal = [[0 for i in range(n)] for i in range(n)]

    # iterate over subexpressions
    for i in range(n):
        for j in range(n):
            if i == j:
                minVal[i][j] = number[i]
                maxVal[i][j] = number[i]
            else:
                minVal[i][j] = float('inf')
                maxVal[i][j] = float('-inf')

    # looping similar to matrix chain multiplication
    # and updating both 2D arrays
    for L in range(2, n+1):
        for i in range(n-L+1):
            j = i+L-1
            for k in range(i, j):
                if operand[k] == '+':
                    minTmp = minVal[i][k] + minVal[k+1][j]
                    maxTmp = maxVal[i][k] + maxVal[k+1][j]
                elif operand[k] == '-':
                    minTmp = minVal[i][k] - maxVal[k+1][j]
                    maxTmp = maxVal[i][k] - minVal[k+1][j]
                else:
                    minTmp = minVal[i][k] * minVal[k+1][j]
                    maxTmp = maxVal[i][k] * maxVal[k+1][j]

                if minTmp < minVal[i][j]:
                    minVal[i][j] = minTmp
                if maxTmp > maxVal[i][j]:
                    maxVal[i][j] = maxTmp

    memo[s] = maxVal[0][n-1]
    return maxVal[0][n-1]

if __name__ == "__main__":
    test_cases = ['test1.txt', 'test2.txt']
    for i, test in enumerate(test_cases):
        with open(f'testCases/{test}') as f:
            s = f.readline().strip()
        try:
            result = MaximizeExpression(s)
            print(f"Test Case {i+1}: {result}")
        except Exception as e:
            print(f"Test Case {i+1} failed: {e}")




