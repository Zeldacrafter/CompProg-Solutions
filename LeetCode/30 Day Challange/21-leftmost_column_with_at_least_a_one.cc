/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        
        int bestC = -1;
        for(int c = dims[1] - 1, r = 0; ~c && r < dims[0]; ) {
            if(binaryMatrix.get(r, c))
                bestC = c--;
            else
                r++;
        }
        return bestC;
    }
};
