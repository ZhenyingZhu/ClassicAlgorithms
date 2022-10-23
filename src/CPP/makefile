CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c -pthread $(DEBUG)
LFLAGS = -Wall -std=c++11 -pthread $(DEBUG)

SOURCES =			\
	src/SolutionCollection.cpp			\
	src/SmartPtr.cpp			\
	src/MyUtils.cpp			\
	src/cppprimer/StringOperations.cpp			\
	src/cppprimer/CollectionErase.cpp			\
	src/cppprimer/TestQuery.cpp			\
	src/cppprimer/BulkItem.cpp			\
	src/cppprimer/HelloWorld.cpp			\
	src/cppprimer/MapOperations.cpp			\
	src/cppprimer/TestWordQuery.cpp			\
	src/cppprimer/QueueOperations.cpp			\
	src/cppprimer/AndQuery.cpp			\
	src/cppprimer/TextQuery.cpp			\
	src/cppprimer/NotQuery.cpp			\
	src/cppprimer/Query.cpp			\
	src/cppprimer/OrQuery.cpp			\
	src/cppprimer/WordsTransform.cpp			\
	src/epi/chapter5/Reverse.cpp			\
	src/epi/chapter5/SwapBits.cpp			\
	src/epi/chapter5/Divide.cpp			\
	src/epi/chapter5/Multiply.cpp			\
	src/epi/chapter5/IsPalindrome.cpp			\
	src/epi/chapter5/IntersectRectangle.cpp			\
	src/epi/chapter5/Power.cpp			\
	src/epi/chapter5/Parity.cpp			\
	src/epi/chapter5/ClosestIntSameBitCount.cpp			\
	src/epi/chapter5/ReverseBits.cpp			\
	src/epi/chapter5/UniformRandom.cpp			\
	src/epi/chapter6/DutchFlagPartition.cpp			\
	src/epi/chapter6/PlusOne.cpp			\
	src/epi/chapter6/Multiply.cpp			\
	src/epi/chapter6/CanReachEnd.cpp			\
	src/epi/chapter6/DeleteDuplicates.cpp			\
	src/epi/chapter6/BuyAndSellStockOnce.cpp			\
	src/epi/chapter6/BuyAndSellStockTwice.cpp			\
	src/epi/chapter6/GeneratePrimes.cpp			\
	src/epi/chapter6/ApplyPermutation.cpp			\
	src/epi/chapter6/NextPermutation.cpp			\
	src/epi/chapter6/RandomSampling.cpp			\
	src/epi/chapter6/OnlineRandomSample.cpp			\
	src/epi/chapter6/ComputeRandomPermutation.cpp			\
	src/epi/chapter6/RandomSubset.cpp			\
	src/epi/chapter6/NonuniformRandomNumberGeneration.cpp			\
	src/epi/chapter6/IsValidSudoku.cpp			\
	src/epi/chapter6/MatrixInSprialOrder.cpp			\
	src/epi/chapter6/RotateMatrix.cpp			\
	src/epi/chapter6/GeneratePascalTriangle.cpp			\
	src/epi/chapter7/InterconvertIntStr.cpp			\
	src/epi/chapter7/ConvertBase.cpp			\
	src/epi/chapter7/SSDecodeColID.cpp			\
	src/epi/chapter7/ReplaceAndRemove.cpp			\
	src/epi/chapter7/IsPalindrome.cpp			\
	src/epi/chapter7/ReverseWords.cpp			\
	src/epi/chapter7/PhoneMnemonic.cpp			\
	src/epi/chapter7/LookAndSay.cpp			\
	src/epi/chapter7/RomanToInteger.cpp			\
	src/epi/chapter7/GetValidIPAddress.cpp			\
	src/epi/chapter7/SnakeString.cpp			\
	src/epi/chapter7/RLE.cpp			\
	src/epi/chapter7/RabinKarp.cpp			\
	src/epi/chapter8/MergeTwoSortedLists.cpp			\
	src/epi/chapter8/ReverseSublist.cpp			\
	src/epi/chapter8/HasCycle.cpp			\
	src/epi/chapter8/OverlappingNoCycleLists.cpp			\
	src/epi/chapter8/OverlappingLists.cpp			\
	src/epi/chapter8/DeletionFromList.cpp			\
	src/epi/chapter8/RemoveKthLast.cpp			\
	src/epi/chapter8/RemoveDuplicates.cpp			\
	src/epi/chapter8/CyclicallyRightShiftList.cpp			\
	src/epi/chapter8/EvenOddMerge.cpp			\
	src/epi/chapter8/IsLinkedListAPalindrome.cpp			\
	src/epi/chapter8/ListPivoting.cpp			\
	src/epi/chapter8/AddTwoNumbers.cpp			\
	src/epi/chapter9/MaxStack.cpp			\
	src/epi/chapter9/Eval.cpp			\
	src/epi/chapter9/IsWellFormed.cpp			\
	src/epi/chapter9/ShortestEquivalentPath.cpp			\
	src/epi/chapter9/SetJumpOrder.cpp			\
	src/epi/chapter9/ExamineBuildingsWithSunset.cpp			\
	src/epi/chapter9/BinaryTreeDepthOrder.cpp			\
	src/epi/chapter9/CircularQueue.cpp			\
	src/epi/chapter9/StackQueue.cpp			\
	src/epi/chapter9/QueueWithMax.cpp			\
	src/epi/chapter10/IsBalanced.cpp			\
	src/epi/chapter10/IsSymmetric.cpp			\
	src/epi/chapter10/LCA.cpp			\
	src/epi/chapter10/LCAWithParent.cpp			\
	src/epi/chapter10/SumRootToLeaf.cpp			\
	src/epi/chapter10/HasPathSum.cpp			\
	src/epi/chapter10/BSTInSortedOrder.cpp			\
	src/epi/chapter10/PreorderTraversal.cpp			\
	src/epi/chapter10/FindKthNodeBinaryTree.cpp			\
	src/epi/chapter10/FindSuccessor.cpp			\
	src/epi/chapter10/InorderTraversal.cpp			\
	src/epi/chapter10/BinaryTreeFromPreorderInorder.cpp			\
	src/epi/chapter10/ReconstructPreorder.cpp			\
	src/epi/chapter10/CreateListOfLeaves.cpp			\
	src/epi/chapter10/ExteriorBinaryTree.cpp			\
	src/epi/chapter10/ConstructRightSibling.cpp			\
	src/epi/chapter10/BinaryTreeLocking.cpp			\
	src/epi/chapter11/TopK.cpp			\
	src/epi/chapter11/MergeSortedArrays.cpp			\
	src/epi/chapter11/SortKIncreasingDecreasingArray.cpp			\
	src/epi/chapter11/SortApproximatelySortedData.cpp			\
	src/epi/chapter11/FindClosestKStars.cpp			\
	src/epi/chapter11/OnlineMedian.cpp			\
	src/epi/chapter11/KLargestInBinaryHeap.cpp			\
	src/epi/chapter11/StackByHeap.cpp			\
	src/epi/chapter12/SearchFirstOfK.cpp			\
	src/epi/chapter12/SearchEntryEqualToItsIndex.cpp			\
	src/epi/chapter12/SearchSmallest.cpp			\
	src/epi/chapter12/SquareRoot.cpp			\
	src/epi/chapter12/DoubleSquareRoot.cpp			\
	src/epi/chapter12/MatrixSearch.cpp			\
	src/epi/chapter12/FindMinMax.cpp			\
	src/epi/chapter12/FindKthLargest.cpp			\
	src/epi/chapter12/FindMissingElement.cpp			\
	src/epi/chapter12/FindBuplicateMissing.cpp			\
	src/epi/chapter13/MergeContactLists.cpp			\
	src/epi/chapter13/CanFormPalindrome.cpp			\
	src/epi/chapter13/IsLetterConstructibleFromMagazine.cpp			\
	src/epi/chapter13/ISBNCache.cpp			\
	src/epi/chapter13/LCA.cpp			\
	src/epi/chapter13/MostFrequentQueries.cpp			\
	src/epi/chapter13/FindNearestRepetition.cpp			\
	src/epi/chapter13/FindSmallestSubarrayCoveringSet.cpp			\
	src/epi/chapter13/FindSmallestSequentiallyCoveringSubset.cpp			\
	src/epi/chapter13/LongestSubarrayWithDistinctEntries.cpp			\
	src/epi/chapter13/LongestContainedRange.cpp			\
	src/epi/chapter13/FindStudentWithHighestBestOfThreeScores.cpp			\
	src/epi/chapter13/FindAllSubstrings.cpp			\
	src/epi/chapter13/TestCollatzConjecture.cpp			\
	src/epi/chapter14/IntersectTwoSortedArrays.cpp			\
	src/epi/chapter14/MergeTwoSortedArrays.cpp			\
	src/epi/chapter14/EliminateDuplicate.cpp			\
	src/epi/chapter14/FindMaxSimultaneousEvents.cpp			\
	src/epi/chapter14/AddInterval.cpp			\
	src/epi/chapter14/UnionOfIntervals.cpp			\
	src/epi/chapter14/GroupByAge.cpp			\
	src/epi/chapter14/TeamPhotoDay1.cpp			\
	src/epi/chapter14/StableSortList.cpp			\
	src/epi/chapter14/FindSalaryCap.cpp			\
	src/epi/chapter15/IsBinaryTreeBST.cpp			\
	src/epi/chapter15/FindFirstGreaterThanK.cpp			\
	src/epi/chapter15/FindKLargestInBST.cpp			\
	src/epi/chapter15/FindLCA.cpp			\
	src/epi/chapter15/RebuildBSTFromPreorder.cpp			\
	src/epi/chapter15/FindClosestElementsInSortedArrays.cpp			\
	src/epi/chapter15/GenerateFirstKABSqrt2.cpp			\
	src/epi/chapter15/BuildMinHeightBSTFromSortedArray.cpp			\
	src/epi/chapter15/BinarySearchTree.cpp			\
	src/epi/chapter15/NodesOnPath.cpp			\
	src/epi/chapter15/RangeLookupInBST.cpp			\
	src/epi/chapter15/AddCredits.cpp			\
	src/epi/chapter16/ComputeTowerHanoi.cpp			\
	src/epi/chapter16/NQueens.cpp			\
	src/epi/chapter16/Permutations.cpp			\
	src/epi/chapter16/GeneratePowerSet.cpp			\
	src/epi/chapter16/Combinations.cpp			\
	src/epi/chapter16/GenerateBalancedParentheses.cpp			\
	src/epi/chapter16/PalindromePartitioning.cpp			\
	src/epi/chapter16/GenerateAllBinaryTrees.cpp			\
	src/epi/chapter16/SolveSudoku.cpp			\
	src/epi/chapter16/GrayCode.cpp			\
	src/epi/chapter16/ComputeDiameter.cpp			\
	src/epi/chapter17/NumCombinationsForFinalScore.cpp			\
	src/epi/chapter17/LevenshteinDistance.cpp			\
	src/epi/chapter17/NumberOfWays.cpp			\
	src/epi/chapter17/ComputeBinomialCoefficient.cpp			\
	src/epi/chapter17/IsPatternContainedInGrid.cpp			\
	src/epi/chapter17/OptimumSubjecToCapacity.cpp			\
	src/epi/chapter17/DecomposeIntoDictionaryWords.cpp			\
	src/epi/chapter17/MinimumPathWeight.cpp			\
	src/epi/chapter17/MaximumRevenue.cpp			\
	src/epi/chapter17/NumberOfWaysToTop.cpp			\
	src/epi/chapter17/MinimumMessiness.cpp			\
	src/epi/chapter17/LongestNondecreasingSubsequenceLength.cpp			\
	src/epi/chapter18/OptimumTaskAssignment.cpp			\
	src/epi/chapter18/MinimumTotalWaitingTime.cpp			\
	src/epi/chapter18/FindMinimumVisits.cpp			\
	src/epi/chapter18/HasThreeSum.cpp			\
	src/epi/chapter18/MajoritySearch.cpp			\
	src/epi/chapter18/FindAmpleCity.cpp			\
	src/epi/chapter18/GetMaxTrappedWater.cpp			\
	src/epi/chapter18/CalculateLargestRectangle.cpp			\
	src/epi/chapter19/SearchMaze.cpp			\
	src/epi/chapter19/FlipColor.cpp			\
	src/epi/chapter19/FillSurroundedRegions.cpp			\
	src/epi/chapter19/IsDeadlocked.cpp			\
	src/epi/chapter19/CloneGraph.cpp			\
	src/epi/chapter19/IsAnyPlacementFeasible.cpp			\
	src/epi/chapter19/TransformString.cpp			\
	src/epi/chapter19/FindLargestNumberTeams.cpp			\
	src/epi/chapter19/DijkstraShortestPath.cpp			\
	src/epi/chapter22/PassByValue.cpp			\
	src/epi/chapter22/WeakPtrUsage.cpp			\
	src/epi/chapter22/MacroUsage.cpp			\
	src/main.cpp

SOURCES_MAIN = src/main.cpp

OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS_MAIN = $(SOURCES_MAIN:.cpp=.o)

EXECUTABLES = cppalgorithms

.PHONY: all
all: $(EXECUTABLES)

cppalgorithms: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXECUTABLES)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(OBJECTS_MAIN) $(EXECUTABLES)
