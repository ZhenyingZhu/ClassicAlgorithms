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
        private T[] array;
        private StackInfo[] infos;
        private int totalVol = 0;

        // Solution 1: divide the array into 3 equal size pieces.
        // Solution 2: when one stack exceed its cap, shift elements and give it more spaces
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
            return array[(info.EndIdx + array.Length - 1) % array.Length];
        }

        public T Pop(int stackId)
        {
            T res = this.Peek(stackId);

            StackInfo info = infos[stackId];
            info.EndIdx = (info.EndIdx - 1 + array.Length) % array.Length;

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
            info.EndIdx = (info.EndIdx + 1) % array.Length;

            totalVol++;
        }

        private void AllocateSpace(int stackId)
        {
            StackInfo curInfo = infos[stackId];
            int nextIdx = (stackId + 1) % infos.Length;
            StackInfo nextInfo = infos[nextIdx];
            if (curInfo.EndIdx == nextInfo.StartIdx)
            {
                this.AllocateSpace(nextIdx);
                this.ShiftByOne(nextIdx);
            }
            else
            {
                return;
            }
        }

        private void ShiftByOne(int stackId)
        {
            StackInfo info = infos[stackId];
            int startIdx = info.StartIdx;
            int endIdx = info.EndIdx >= startIdx ? info.EndIdx : info.EndIdx + array.Length;

            for (int i = endIdx - 1; i >= info.StartIdx; i--)
            {
                int nextIdx = (i + 1) % array.Length;
                array[nextIdx] = array[i];
            }
            info.EndIdx = (info.EndIdx + 1) % array.Length;
            info.StartIdx = (info.StartIdx + 1) % array.Length;
        }

        private class StackInfo
        {
            public int StartIdx { get; set; }

            // The next cell of the val.
            public int EndIdx { get; set; }


        }
    }
}
