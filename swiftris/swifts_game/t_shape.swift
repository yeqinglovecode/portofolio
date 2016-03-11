//
//  TShape.swift
//  Swifts game
//
//  Created by Qing Ye on 3/5/16.
//  Copyright © 2016 Bloc. All rights reserved.
//

class TShape:Shape{
    /*
    Orientation 0
       |0|
     |1|2|3|
    Orientation 90
       |1|
       |2|0|
       |3|
    Orientation 180
      |1|2|3|
        |0|
    Orientation 270
        |1|
      |0|2|
        |3|
 */
    override var bottomBlocksForOrientations: [Orientation: Array<Block>] {
        return [
            Orientation.Zero:  [blocks[SecondBlockIdx], blocks[ThirdBlockIdx], blocks[FourthBlockIdx]],
            Orientation.Ninety: [blocks[FirstBlockIdx], blocks[FourthBlockIdx]],
            Orientation.OneEighty: [blocks[FirstBlockIdx], blocks[SecondBlockIdx], blocks[FourthBlockIdx]],
            Orientation.TwoSeventy: [blocks[FirstBlockIdx], blocks[FourthBlockIdx]]
        
        ]
    }
}
