import os
import random

class GenerateTestData:
    def GasStation(self,testCase = 1, n = 5, m = 5, path = "./GasStation/gasStation.txt"):
        if os.path.exists(path):
            os.remove(path)
        with open(path, "w+") as f:
            #generate a file that contains:
            #first line is the number of test cases
            #second line is the number of gas stations
            #gas - dist
            #n lines follow, each line contains a pair of coordinates from 1 to m separated by a space
            f.write(str(testCase) + "\n")
            for i in range(testCase):
                f.write(str(n) + "\n")
                for j in range(n):
                    f.write(str(random.randint(1,int(m*1.1))) + " " + str(random.randint(1,m)) + "\n")
            f.close()
GenerateTestData().GasStation(10,1000,10)