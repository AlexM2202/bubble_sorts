import random

def make_file(fname: str, elements):
    file = open(f"{fname}.txt", '+w')
    file.write(f"{elements}\n\n")
    for x in range(0, int(elements)):
        file.write(f"{random.randint(0, int(elements))}\n")
    file.close()
    return

if __name__ == "__main__":
    make_file(input("Enter output file name: ") ,input("Enter num elements: "))