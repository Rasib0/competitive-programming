import sys
import math

while True:

    line = input()
    line = line.split(" ")

    if line[0] == "0":
        break

    N = 0
    inputs = []
    for i in range(len(line)):
        if i == 0:
            N = int(line[i])
        else:
            inputs.append(int(line[i]))

    LIS = []
    P = []

    for i in range(N):
        LIS.append(1)

    for j in range(N):
        P.append(j)

    maxi = 1

    prev_index = 0
    prev_value = 0

    for i in range(N):
        maxi = 1
        count = 1
        for j in range(i):

            if inputs[j] < inputs[i]:
                count = LIS[j] + 1

                if count == LIS[i]:
                    if inputs[P[i]] > inputs[j]:
                        P[i] = j
                elif count > LIS[i]:
                    maxi = max(maxi, count)
                    P[i] = j

        LIS[i] = maxi

    maxi = 1
    for i in range(N):
        maxi = max(maxi, LIS[i])

    counter = 1
    curr = math.inf
    # output = str(maxi)
    # output += " "

    # print(maxi)
    startprint = 0
    startvalue = math.inf

    last_index = 0

    for i in range(N):
        if LIS[i] == maxi:
            last_index = i

    # print(last_index)

    curr_index = -1
    output = ""
    curr_index = last_index
    while True:
        # print("lastindex"+ str(curr_index))
        # print("value"+ str(inputs[curr_index]))
        output = str(inputs[curr_index]) + " " + output

        if curr_index == P[curr_index]:
            break
        curr_index = P[curr_index]

    output = output.strip()
    output = str(maxi)+" "+output

    # for i in range(maxi):
    #     curr = math.inf
    #     for j in range(last_index+1):
    #         curr = min ( inputs[i], curr)
    #     output+=str(curr)
    #     output+= " "

    # print(P)
    # print(LIS)
    output = output.strip()
    print(output)
    # print("end")
