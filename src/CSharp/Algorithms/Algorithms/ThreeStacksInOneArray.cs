using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Implement 3 stacks in one array.
    /// Uncertenties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 3.1
    /// </remarks>
    public class ThreeStacksInOneArray<T>
    {
        T[] array;
        StackInfo[] infos;
        int totalVol = 0;

        // Solution 1: divide the array into 3 equal size pieces.
        // Solution 2: one stack exceed its cap, shift elements and give it more spaces
        public ThreeStacksInOneArray(int stackCap = 2, int stackNum = 3)
        {
            if (stackCap <= 1 || stackNum <= 2)
            {
                throw new ApplicationException("space too less");
            }

            array = new T[stackCap * stackNum];
            infos = new StackInfo[stackNum];
            for (int i = 0; i < stackNum; i++)
            {
                infos[i] = new StackInfo() { StartIdx = stackCap * i, EndIdx = stackCap * i };
            }
        }

        public bool IsEmpty(int stackId)
        {
            if (stackId >= infos.Length)
            {
                throw new ArgumentOutOfRangeException();
            }

            StackInfo info = infos[stackId];
            return info.EndIdx == info.StartIdx;
        }

        public T Peek(int stackId)
        {
            if (this.IsEmpty(stackId))
            {
                throw new ApplicationException("Stack is empty");
            }

            StackInfo info = infos[stackId];
            return array[info.EndIdx];
        }

        public T Pop(int stackId)
        {
            T res = this.Peek(stackId);

            StackInfo info = infos[stackId];
            int endIdx = info.EndIdx - 1;
            if (endIdx < 0)
            {
                info.EndIdx = array.Length + endIdx;
            }

            totalVol--;

            return res;
        }

        public void Push(T val, int stackId)
        {
            if (stackId >= infos.Length)
            {
                throw new ArgumentOutOfRangeException();
            }

            if (totalVol == array.Length)
            {
                throw new ApplicationException("Stack full");
            }

            this.AllocateSpace(stackId);
            StackInfo info = this.infos[stackId];
            array[info.EndIdx] = val;
            info.EndIdx = info.EndIdx + 1 % array.Length;
            totalVol++;
        }

        private void AllocateSpace(int stackId)
        {
            StackInfo curInfo = infos[stackId];
            int nextIdx = (stackId + 1) % infos.Length;
            StackInfo nextInfo = infos[nextIdx];
            if (curInfo.EndIdx < nextInfo.StartIdx)
            {
                return;
            }
            else if (curInfo.EndIdx == nextInfo.StartIdx)
            {
                this.AllocateSpace(nextIdx);
                this.ShiftByOne(nextIdx);
            }
        }

        private void ShiftByOne(int stackId)
        {
            StackInfo info = infos[stackId];

            // TODO
        }

        private class StackInfo
        {
            public int StartIdx { get; set; }

            // The next cell of the val.
            public int EndIdx { get; set; }


        }
    }
}
