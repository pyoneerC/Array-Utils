// © 2024 Maximo Comperatore. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Script.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "UObject/UnrealType.h"
#include "UObject/ScriptMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/UnrealTypePrivate.h"
#include "NumericBPLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogArrayUtils, Log, All);

UCLASS()
class UNumericBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	 * Returns the maximum value of an array.
	 *
	 * @param A The input array.
	 * @return The maximum value in the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "MAX", Category = "Array Utils", ToolTip = "Returns the maximum value of an array"))
	static int32 ArrayMax(const TArray<int32>& A);

	/**
	 *
	 * @param A Input array.
	 * @param B Sub range to search for.
	 * @return Index in which the sub range starts if found, -1 otherwise.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "SEARCH RANGE", Category = "Array Utils", ToolTip = "Searches for the first occurrence of the sequence of elements in the first array. Will give true and the first index where the whole range matches, false and -1 otherwise. Example: Search({1,2,3}, {3} will give 2 as the subrange starts at [2] in the main array."))
	static int32 Search(const TArray<int32>& A, const TArray<int32>& B, bool& found);

	/**
	 * Returns the partial summed array.
	 *
	 * @param A The input array.
	 * @return The partial summed array
	 * @note partial sum({1,2,3}) -> {1,3,6}
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "PARTIAL SUM", Category = "Array Utils", ToolTip = "Returns the partial summed array. Example: partialsum({1,2,3,4}) -> {1,3,6,10}"))
	static TArray<int32> PartialSum(const TArray<int32>& A);

	/**
	 *
	 * @param A Array.
	 * @param Min Low.
	 * @param Max High.
	 * @return Array with all elements clamped.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "CLAMP", Category = "Array Utils", ToolTip = "Returns the array with all elements clamped to the range"))
	static TArray<int32> Clamp(const TArray<int32>& A, int32 Min, int32 Max);

	/**
	*
	* @param A Array.
	* @param Min Low.
	* @param Max High.
	* @return Array with N elements clamped.
	*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "CLAMP N", Category = "Array Utils", ToolTip = "Returns the array with N first elements elements clamped to the range"))
	static TArray<int32> ClampN(const TArray<int32>& A, int32 Min, int32 Max, int32 N);

	/**
	 *
	 * @param A Array.
	 * @param N Number of Random Samples.
	 * @return Array with the samples.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "SAMPLE", Category = "Array Utils", ToolTip = "Returns n random numbers from the array in the form of an array. Example: sample({1,2,3,4,5}, 2) -> {3,2}"))
	static TArray<int32> Sample(const TArray<int32>& A, int32 N);

	/**
	 *
	 * @param A Array.
	 * @return Array with each element squared.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "i²", Category = "Array Utils", ToolTip = "Transform each number to be the square of itself"))
	static TArray<int32> EveryoneSquared(const TArray<int32>& A);

	/**
	 *
	 * @param A Array.
	 * @return Array with each element cubed.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "i³", Category = "Array Utils", ToolTip = "Transform each number to be the cube of itself"))
	static TArray<int32> EveryoneCubed(const TArray<int32>& A);

	/**
	 *
	 * @param A Array.
	 * @return Array sorted in ascending order, preserving the relative order of elements with equivalent values.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "STABLE SORT ASCENDING", Category = "Array Utils", ToolTip = "Sorts the array in ascending order, preserving the relative order of elements with equivalent values."))
	static TArray<int32> StableSortAscending(TArray<int32> A);

	/**
	 *
	 * @param A Array.
	 * @return Array sorted in descending order, preserving the relative order of elements with equivalent values.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "STABLE SORT DESCENDING", Category = "Array Utils", ToolTip = "Sorts the array in descending order, preserving the relative order of elements with equivalent values."))
	static TArray<int32> StableSortDescending(TArray<int32> A);

	/**
	 * Returns the partial summed array up until the index given.
	 *
	 * @param A The input array.
	 * @param N The index up until which to sum the array.
	 * @return The partial summed array up until the index given.
	 * @note partial sum n({1,2,3}, 2) -> {1,3,3}
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "PARTIAL SUM N", Category = "Array Utils", ToolTip = "Returns the partial summed array up until the index provided. Example: partialsumn({1,2,3}, 2) -> {1,3,3}"))
	static TArray<int32> PartialSumN(const TArray<int32>& A, int32 N = 1);

	/**
	 * Returns the minimum value of an array.
	 *
	 * @param A The input array.
	 * @return The minimum value in the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "MIN", Category = "Array Utils", ToolTip = "Returns the minimum value of an array"))
	static int32 ArrayMin(const TArray<int32>& A);

	/**
	 * Returns the minimum and maximum value of an array.
	 *
	 * @param A The input array.
	 * @param Min (Out) The minimum value in the array.
	 * @param Max (Out) The maximum value in the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "MIN MAX", Category = "Array Utils", ToolTip = "Returns the minimum and maximum value of an array"))
	static void ArrayMinMax(const TArray<int32>& A, int32& Min, int32& Max);

	/**
	 * Returns true if the two arrays are permutations of each other.
	 *
	 * @param A The first array.
	 * @param B The second array.
	 * @return true if the arrays are permutations, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS PERMUTATION?", Category = "Array Utils", ToolTip = "Returns true if the two arrays are permutations of each other"))
	static bool IsPermutation(const TArray<int32>& A, const TArray<int32>& B);

	/**
	 * Returns the next permutation of an array.
	 *
	 * @param A The input array.
	 * @return The next permutation of the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "NEXT PERMUTATION", Category = "Array Utils", ToolTip = "Returns the next permutation of an array"))
	static TArray<int32> NextPermutation(TArray<int32> A);

	/**
	 * Returns the previous permutation of an array.
	 *
	 * @param A The input array.
	 * @return The previous permutation of the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "PREV PERMUTATION", Category = "Array Utils", ToolTip = "Returns the previous permutation of an array"))
	static TArray<int32> PrevPermutation(TArray<int32> A);

	/**
	 * Returns true if the array is sorted in ascending order. For example, {1, 2, 3, 4} is sorted, but {1, 3, 2, 4} is not.
	 *
	 * @param A The input array.
	 * @return true if the array is sorted, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS SORTED?", Category = "Array Utils", ToolTip = "Returns true if the array is sorted in ascending order."))
	static bool IsSorted(const TArray<int32>& A);

	/**
	* Returns the inner product of two arrays. Arrays must have the same length, otherwise 0 will be returned.
	*
	* @param A The first array.
	* @param B The second array.
	* @param StartIndex The initial value for the inner product calculation.
	* @return The inner product of the two arrays.
	*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "INNER PRODUCT",Category = "Array Utils", ToolTip = "Returns the inner product of two arrays. Arrays must have the same length, otherwise -1 will be returned."))
	static int32 InnerProduct(const TArray<int32>& A, const TArray<int32>& B, int32 StartIndex = 0);

	/**
	 * Returns the number of elements in the array that are equal to the specified value. For example, {1, 1, 2, 3, 3, 3, 4} has 2 elements equal to 1.
	 *
	 * @param A The input array.
	 * @param Value The value to count in the array.
	 * @return The count of elements equal to the specified value in the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "COUNT", Category = "Array Utils", ToolTip = "Returns the number of elements in the array that are equal to the specified value"))
	static int32 Count(const TArray<int32>& A, int32 Value);

	/**
	 * Returns the sum of all elements of an array.
	 *
	 * @param A The input array.
	 * @return The sum of all elements in the array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "SUM", Category = "Array Utils", ToolTip = "Returns the sum of all elements of an array"))
	static int32 Accumulate(const TArray<int32>& A);

	/**
	 * Fills the array with a specified value.
	 *
	 * @param A The input array.
	 * @param Value The value to fill the array with.
	 * @return The array filled with the specified value.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "FILL", Category = "Array Utils", ToolTip = "Fills all the array with a number of choice"))
	static TArray<int32> Fill(const TArray<int32>& A, int32 Value);

	/**
	 * Fills the array with a number of choice up to the provided number.
	 *
	 * @param A The input array.
	 * @param Value The value to fill the array with.
	 * @param N The number of elements to fill with the specified value.
	 * @return The array filled with the specified value.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "FILL N", Category = "Array Utils", ToolTip = "Fills the array with a number of choice up to the provided number. Example: {1,2,3,4,5} filln(5, 3) = {5, 5, 5, 4, 5}"))
	static TArray<int32> FillN(const TArray<int32>& A, int32 Value, int32 N);

	/**
	 * Sorts the array in ascending order.
	 *
	 * @param A The input array.
	 * @return The array sorted in ascending order.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "SORT ASCENDING", Category = "Array Utils", ToolTip = "Sorts the array in ascending order"))
	static TArray<int32> SortAscending(const TArray<int32>& A);

	/**
	 * Sorts the array in descending order.
	 *
	 * @param A The input array.
	 * @return The array sorted in descending order.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "SORT DESCENDING", Category = "Array Utils", ToolTip = "Sorts the array in descending order"))
	static TArray<int32> SortDescending(const TArray<int32>& A);

	/**
	 * Sorts the array in ascending order up to the specified index.
	 *
	 * @param A The input array.
	 * @param N The index up to which to sort the array.
	 * @return The array sorted in ascending order up to the specified index.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "PARTIAL SORT ASCENDING", Category = "Array Utils", ToolTip = "Sorts the array in ascending order up to the specified index, leaving the rest in unspecified order"))
	static TArray<int32> PartialSortAscending(const TArray<int32>& A, int32 N);

	/**
	 * Sorts the array in descending order up to the specified index.
	 *
	 * @param A The input array.
	 * @param N The index up to which to sort the array.
	 * @return The array sorted in descending order up to the specified index.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "PARTIAL SORT DESCENDING", Category = "Array Utils", ToolTip = "Sorts the array in descending order up to the specified index, leaving the rest in unspecified order"))
	static TArray<int32> PartialSortDescending(const TArray<int32>& A, int32 N);

	/**
	 * Returns the index of the first element in the array that is not sorted.
	 *
	 * @param A The input array.
	 * @return True if the array is sorted, false otherwise.
	 * @return The index of the first element in the array that is not sorted.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS SORTED UNTIL?", Category = "Array Utils", ToolTip = "Returns the index of the first element in the array that is not sorted"))
	static int32 IsSortedUntil(const TArray<int32>& A, bool& IsSorted);

	/**
	 * Returns the subtraction of all elements of an array.
	 *
	 * @param A The input array.
	 * @return The subtraction of all elements of an array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "DEACUMULATE", Category = "Array Utils", ToolTip = "Returns the subtraction of all elements of an array, starting from 0. {1,2,3} -> -6. Flips the sign and + or - respectively."))
	static int32 Deaccumulate(const TArray<int32>& A);

	/**
	 * Returns the multiplication of all elements of an array.
	 *
	 * @param A The input array.
	 * @return The multiplication of all elements of an array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "MULTIPLY ALL ELEMENTS", Category = "Array Utils", ToolTip = "Returns the multiplication of all elements of an array"))
	static int32 MultiplyAllElements(const TArray<int32>& A);

	/**
	 * Returns true if the first array is lexicographically less than the second array. For example, {1, 2, 3} is less than {1, 2, 4} as 3 < 4.
	 *
	 * @param A The first array.
	 * @param B The second array.
	 * @return true if the first array is lexicographically less than the second array, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "LEXICOGRAPHICAL COMPARE", Category = "Array Utils", ToolTip = "Returns true if the first array is lexicographically less than the second array. For example, {1, 2, 3} is less than {1, 2, 4} as 3 < 4."))
	static bool LexicographicalCompare(const TArray<int32>& A, const TArray<int32>& B);

	/**
	 * Returns the greater array.
	 *
	 * @param A The first array.
	 * @param B The second array.
	 * @return The greater array of two summed.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "BIGGEST ARRAY", Category = "Array Utils", ToolTip = "Returns the greater array"))
	static TArray<int32> BiggestArray(const TArray<int32>& A, const TArray<int32>& B);

	/**
	 * Returns the smallest array of two summed.
	 *
	 * @param A The first array.
	 * @param B The second array.
	 * @return The smallest array of two summed.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "SMALLEST ARRAY", Category = "Array Utils", ToolTip = "Returns the smallest array"))
	static TArray<int32> SmallestArray(const TArray<int32>& A, const TArray<int32>& B);

	/**
	 * Fills the array with a number that increments by 1 each index.
	 *
	 * @param A The input array.
	 * @param Value The starting value for filling the array.
	 * @return The array filled with values starting from the specified value and incrementing by 1.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "IOTA", Category = "Array Utils", ToolTip = "Fills the array with a number that increments by 1 each index, ex. iota({1,2,3}, 5) = {5,6,7}"))
	static TArray<int32> Iota(const TArray<int32>& A, int32 Value);

	/**
	 * Replaces all instances of a value in an array with another value.
	 *
	 * @param A The input array.
	 * @param OldValue The value to be replaced.
	 * @param NewValue The new value to replace the old value with.
	 * @return The array with replaced values.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "REPLACE", Category = "Array Utils", ToolTip = "Replaces all instances of a value in an array with another value"))
	static TArray<int32> Replace(const TArray<int32>& A, int32 OldValue, int32 NewValue);

	/**
	 * Rotates the array by a specified amount. Positive values rotate to the right, negative values rotate to the left.
	 *
	 * @param A The input array.
	 * @param Amount The amount by which to rotate the array.
	 * @return The rotated array.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "ROTATE", Category = "Array Utils", ToolTip = "Rotates the array by a specified amount"))
	static TArray<int32> Rotate(const TArray<int32>& A, int32 Amount);

	/**
	 * Returns true if the two arrays are equal.
	 *
	 * @param A The first array.
	 * @param B The second array.
	 * @return true if the two arrays are equal, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS EQUAL?", Category = "Array Utils", ToolTip = "Returns true if the two arrays are equal"))
	static bool ArrayIsEqual(const TArray<int32>& A, const TArray<int32>& B);

	/**
	 * Returns true if the two arrays are not equal.
	 *
	 * @param A The first array.
	 * @param B The second array.
	 * @return true if the two arrays are not equal, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS NOT EQUAL?", Category = "Array Utils", ToolTip = "Returns true if the two arrays are not equal"))
	static bool ArrayIsNotEqual(const TArray<int32>& A, const TArray<int32>& B);

	/**
	 * Returns the array with the nth element sorted.
	 *
	 * @param A The input array.
	 * @param N The index of the element to sort.
	 * @return The array with the nth element sorted.
	 */
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "NTH ELEMENT", Category = "Array Utils", ToolTip = "Returns the array with the nth element sorted"))
	static TArray<int32> NthElement(const TArray<int32>& A, int32 N);

	/**
	* Returns the index of the first mismatching element between two arrays. False if no mismatch (arrays are equal).
	*
	* @param A The first array.
	* @param B The second array.
	* @param bIsMismatch (Out) Whether the arrays are mismatched.
	* @return The index of the first mismatching element between two arrays.
	*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "MISMATCH?", Category = "Array Utils", ToolTip = "Returns the index of the first mismatching element between two arrays"))
	static int32 Mismatch(const TArray<int32>& A, const TArray<int32>& B, bool& IsMismatch);

	/**
	 * Returns true if the array is decreasing; i.e, each item is less than or equal to the previous one.
	 *
	 * @param A The input array.
	 * @return true if the array is decreasing, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS DECREASING?", Category = "Array Utils", ToolTip = "Whether an entire sequence is decreasing; i.e, each item is less than or equal to the previous one"))
	static bool ArrayIsDecreasing(const TArray<int32>& A);

	/**
	 * Returns true if the array is increasing; i.e, each item is greater than or equal to the previous one.
	 *
	 * @param A The input array.
	 * @return true if the array is increasing, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS INCREASING?", Category = "Array Utils", ToolTip = "Whether an entire sequence is increasing; i.e, each item is greater than or equal to the previous one"))
	static bool ArrayIsIncreasing(const TArray<int32>& A);

	/**
	 * Returns true if the array is strictly decreasing; i.e, each item is less than the previous one.
	 *
	 * @param A The input array.
	 * @return true if the array is strictly decreasing, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS STRICTLY DECREASING?", Category = "Array Utils", ToolTip = "Whether an entire sequence is strictly decreasing; i.e, each item is less than the previous one"))
	static bool ArrayIsStrictlyDecreasing(const TArray<int32>& A);

	/**
	 * Returns true if the array is strictly increasing; i.e, each item is greater than the previous one.
	 *
	 * @param A The input array.
	 * @return true if the array is strictly increasing, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "IS STRICTLY INCREASING?", Category = "Array Utils", ToolTip = "Whether an entire sequence is strictly increasing; i.e, each item is greater than the previous one"))
	static bool ArrayIsStrictlyIncreasing(const TArray<int32>& A);

	/**
	 * Erases all occurrences of a value in the array.
	 *
	 * @param A The input array.
	 * @param Value The element to remove.
	 * @return The array with the elements(s) removed.
	 */
	UFUNCTION(Blueprintable, meta = (CompactNodeTitle = "ERASE FROM ARRAY", Category = "Array Utils", ToolTip = "Erases all ocurrences of the value in the array. Ex Erase({1,2,3,4,5,5},5) -> {1,2,3,4}"))
	static TArray<int32> EraseAllOcurrencesOfValue(UPARAM(ref) TArray<int32>& A, int32 Value);

	/**
	 * Shrinks the array to fit the number of elements in the array.
	 *
	 * @param A Array.
	 * @return Shrink Array.
	 */
	 UFUNCTION(Blueprintable, meta = (CompactNodeTitle = "SHRINK TO FIT", Category = "Array Utils", ToolTip = "Shrinks the array to fit the number of elements in the array."))
	 static TArray<int32> ShrinkToFit(UPARAM(ref) TArray<int32>& A);

	/**
	 * Copies the array A into B. Returns true if the copy was successful, false otherwise.
	 *
	 * @param A Array to copy.
	 * @param B Array to copy into.
	 * @return Whether the copy was successful.
	 */
	UFUNCTION(Blueprintable, BlueprintCallable, meta = (CompactNodeTitle = "COPY ARRAY", Category = "Array Utils", ToolTip = "Copies the array A into B. Returns true if the copy was successful, false otherwise."))
	static bool CopyArray(const TArray<int32>& A, UPARAM(ref)TArray<int32>& B);

	/**
	 * Swaps the contents of two arrays. Returns true if the swap was successful, false otherwise.
	 *
	 * @param A Array to swap.
	 * @param B Array to swap.
	 * @return Whether the swap was successful.
	 */
	UFUNCTION(Blueprintable, BlueprintCallable, meta = (CompactNodeTitle = "SWAP ARRAYS", Category = "Array Utils", ToolTip = "Swaps the contents of two arrays. Returns true if the swap was successful, false otherwise."))
	static bool SwapArrays(UPARAM(ref) TArray<int32>& A, UPARAM(ref) TArray<int32>& B);

	/**
	 * Moves the contents of array A into B. Returns true if the move was successful, false otherwise.
	 *
	 * @param A Array to move.
	 * @param B Array to move into.
	 * @return Whether the move was successful.
	 */
	UFUNCTION(Blueprintable, BlueprintCallable, meta = (CompactNodeTitle = "MOVE ARRAY", Category = "Array Utils", ToolTip = "Moves the contents of array A into B. Returns true if the move was successful, false otherwise."))
	static bool MoveArray(UPARAM(ref) TArray<int32>& A, UPARAM(ref) TArray<int32>& B);

	/**
	 * Takes the first N elements of the array and copies them to a new array. If N is larger than size of the input array, all items from the input array are selected.
	 *
	 * @param A Array.
	 * @param N Number of elements to take.
	 * @return The first N elements of the array in other array.
	 */
	UFUNCTION(BlueprintCallable, Blueprintable, meta = (CompactNodeTitle = "TAKE", Category = "Array Utils", ToolTip = "Take N items from the beginning of the input array and copy them to a new array. If N is larger than size of the input array, all items from the input array are selected."))
	static TArray<int32> ArrayTake(const TArray<int32>& A, int32 N);

};
