import math

class FerrisWheel:

    _numberOfChildren = 0
    _totalWeight = 0
    _arrWeightOfChildren = []
    def __init__(self, numberOfChildren: 'int', totalWeight: 'int', arrWeightOfChildren: '[]'):
        self._numberOfChildren = numberOfChildren
        self._totalWeight = totalWeight
        self._arrWeightOfChildren = arrWeightOfChildren

    def checkParameters(self) -> bool:

        if self._numberOfChildren < 1 or self._numberOfChildren > 2*10e5:
            return False

        if self._totalWeight < 1 or self._totalWeight > 10e9:
            return False

        if len(self._arrWeightOfChildren) == 0:
            return False

        if self._numberOfChildren!= len(self._arrWeightOfChildren):
            return False

        if any(nWeightOfChild < 1 or nWeightOfChild > 10e9 for nWeightOfChild in self._arrWeightOfChildren):
            return False

        return True

    def Calculate(self):
        nCounter = 0
        self._arrWeightOfChildren.sort()
        while len(self._arrWeightOfChildren) > 0:
            nWeightOfActualChild = self._arrWeightOfChildren.pop()
            bestFitIndex = self.findBestFitRecursive(self._arrWeightOfChildren, 0, len(self._arrWeightOfChildren), self._totalWeight-nWeightOfActualChild )
            if bestFitIndex >= 0:
                self._arrWeightOfChildren.pop(bestFitIndex)
            nCounter += 1
        return nCounter

    def findBestFitRecursive(self, arrWeightOfChildren, fromIndex, toIndex, targetValue):
        index = int((fromIndex + toIndex) / 2)
        if len(arrWeightOfChildren) == 0:
            return -1
        elif arrWeightOfChildren[index] <= targetValue and toIndex - fromIndex == 1:
            return index
        elif arrWeightOfChildren[index] > targetValue and toIndex - fromIndex == 1:
            return -1
        elif arrWeightOfChildren[index] > targetValue:
            return self.findBestFitRecursive(arrWeightOfChildren, fromIndex, index, targetValue)
        else:
            return self.findBestFitRecursive(arrWeightOfChildren, index, toIndex, targetValue)
p1, p2 = map(int, input().split(" "))  
arrParameters = input()
strParams = list(map(int, arrParameters.strip().split(" ")))
wheel = FerrisWheel(p1, p2, strParams )
esult_by_calc = wheel.Calculate() if wheel.checkParameters() else None
print(esult_by_calc)