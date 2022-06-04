// Leet2019.cpp : Defines the entry point for the console application.
//

// Leet2015.cpp : Defines the entry point for the console application.
//reverse
#include "stdafx.h"
#include "Solution2022.h"

using namespace std;
typedef std::numeric_limits< double > dbl;

int _tmain(int argc, _TCHAR* argv[])
{

	// Runtime begin marker start
	clock_t begin = clock();
	//Solution2022::Test::Main(); // Medium

	// 6/1/2022
	//Solution2022::BinarySearch::Main();
	//Solution2022::FirstBadVersion::Main();
	//Solution2022::SearchInsertPosition::Main();


	// 6/2/2022
	//Solution2022::SquaresofaSortedArray::Main();
	//Solution2022::RotateArray::Main();
	//Solution2022::MoveZeroes::Main();
	
	// 6/3/2022
	//Solution2022::TwoSumIIInputArrayIsSorted::Main();
	//Solution2022::ReverseString::Main();
	//Solution2022::ReverseWordsinaStringIII::Main();

	//6/4/2022
	//Solution2022::MiddleoftheLinkedList::Main();
	//Solution2022::RemoveNthNodeFromEndofList::Main();
	//Solution2022::LongestSubstringWithoutRepeatingCharacters::Main();
	//Solution2022::PermutationinString::Main();
	//Solution2022::FloodFill::Main();
	
	//Solution2022::MaxAreaofIsland::Main();
	//Solution2022::MergeTwoBinaryTrees::Main();
	//Solution2022::PopulatingNextRightPointersinEachNode::Main();
	//Solution2022::ZeroOneMatrix::Main();
	//Solution2022::RottingOranges::Main();
	//Solution2022::MergeTwoSortedLists::Main();
	//Solution2022::ReverseLinkedList::Main();
	//Solution2022::Combinations::Main();
	//Solution2022::Permutations::Main();
	//Solution2022::LetterCasePermutation::Main();
	//Solution2022::ClimbingStairs::Main();
	//Solution2022::HouseRobber::Main();
	//Solution2022::Triangle::Main();
	//Solution2022::PowerofTwo::Main();
	//Solution2022::NumberofOneBits::Main();
	//Solution2022::ReverseBits::Main();
	//Solution2022::SingleNumber::Main();


	//====Problem Ends====

	// Runtime end marker
	clock_t end = clock();
	double elapsed_time_in_millisecond = double(end - begin) / double(CLOCKS_PER_SEC / 1000.0);

	// End program routine
	cout.precision(dbl::digits10);
	cout << "\n\nYour program total runtime is: " << elapsed_time_in_millisecond << "ms";
	cout << "\n\nPress enter key to exit ...\n\n";
	cin.get();
	return 0;
}

