from python import Python
from collections.vector import InlinedFixedVector

fn sort(inout vect: InlinedFixedVector[Int]) -> InlinedFixedVector[Int]:
    var flag: Bool = True
    while flag:
        flag = False
        for x in range(vect.__len__()-1):
            if vect[x] > vect[x+1]:
                var temp: Int = vect[x]
                vect[x] = vect[x+1]
                vect[x+1] = temp
                flag = True
    return vect

fn main() raises:
    var py = Python.import_module("builtins") #import python builtins
    #get file
    var arg: String = py.input("Enter file - ")
    try: #open
        var file = py.open(arg, 'r')
        var count: Int = atol(file.readline().replace("\n",''))
        file.readline()
        var vect: InlinedFixedVector[Int] = InlinedFixedVector[Int](count)
        for x in range(count):
            vect.append(atol(file.readline().replace("\n",'')))
        file.close()
        print("Sort Started on",count,"items")
        vect = sort(vect)
        print("Done, writing now")
        file = py.open("output_mojo.txt", '+w')
        for x in range(vect.__len__()):
            file.write(str(vect[x])+"\n")
        file.close()
    except:
        print("Error:", arg,"does not exist!")
    