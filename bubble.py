def sort(input_file: str):
    sort_arr = []
    ifile = open(input_file)
    num = ifile.readline()
    ifile.readline()
    for x in range(int(num)):
        sort_arr.append(int(ifile.readline()))
    ifile.close()
    print(f"Sort Started on {sort_arr.__len__()} items")
    flag = True
    while flag:
        flag = False
        x = 0
        for x in range(sort_arr.__len__()-1):
            if(sort_arr[x] > sort_arr[x+1]):
                temp = sort_arr[x]
                sort_arr[x] = sort_arr[x+1]
                sort_arr[x+1] = temp
                flag = True
            x += 1 
    return sort_arr

if __name__ == "__main__":
    ans = sort(input("Input file: "))
    print("Done, writing now")
    outf = open("output_py.txt", '+w')
    for x in ans:
        outf.write(f"{x}\n")