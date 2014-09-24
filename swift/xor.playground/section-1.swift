// Playground - noun: a place where people can play
// DeckOfXor Algorithm
// http://www.topcoder.com/challenge-details/30045380/?type=develop&nocache=true
//
// Author: Kejia.Wu
// Email: edward9145@gmail.com

import Foundation

class DeckOfXor {
    func differentWays(number: [Int], limit: Int) -> Int {
        var ways = 0
        var counts = Int(pow(2, Float(number.count)))
        for i in 0..<counts {
            var subSet = [Int]()
            for j in 0..<number.count {
                if (getBit(i, pos: j)) {
                    subSet.append(number[j])
                }
            }
            if(xor(subSet) <= limit) {
                ways += 1
            }
//            print(xor(subSet))
//            println(subSet)
        }
        return ways
    }
    
    func xor(number: [Int]) -> Int {
        if (number.count == 0) {
            return 0
        }
        var result = number[0]
        for i in 1..<number.count {
            result ^= number[i]
        }
        return result
    }
    
    // optimize this func
    func getBit(val: Int, pos: Int) -> Bool {
        var bit = val & Int(pow(2, Float(pos)));
        return (bit > 0 ? true : false);
    }
}

var xor = DeckOfXor()

xor.differentWays([1,2], limit: 2)
xor.differentWays([5,5], limit: 3)
xor.differentWays([1,2,3,4,5,6,7], limit: 5)
xor.differentWays([123, 456, 789, 147, 258, 369, 159, 357], limit: 500)
xor.differentWays([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0], limit: 1000000000000000)
xor.differentWays([1000000000000000, 999999999999999], limit: 65535)
