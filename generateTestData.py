import os
import random

class GenerateTestData:
    def GasStation(self,testCase = 1, n = 5, m = 5, path = "./GasStation/gasStation.txt"):
        if os.path.exists(path):
            os.remove(path)
        with open(path, "w+") as f:
            f.write(str(testCase) + "\n")
            for i in range(testCase):
                f.write(str(n) + "\n")
                for j in range(n):
                    f.write(str(random.randint(1,int(m*1.1))) + " " + str(random.randint(1,m)) + "\n")
            f.close()
GenerateTestData().GasStation(100,10,10)


