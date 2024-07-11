// Copyright Epic Games, Inc. All Rights Reserved.

#include <algorithm>
#include <numeric>
#include <random>
#include "NumericBPLibrary.h"
#include "Numeric.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(LogArrayUtils)

UNumericBPLibrary::UNumericBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

// See function docs in header file.

int32 UNumericBPLibrary::ArrayMax(const TArray<int32>& A)
{
	// Returns the maximum element in the array A.
	return A.Num() > 0 ? *std::max_element(A.GetData(), A.GetData() + A.Num()) : -1;
}

int32 UNumericBPLibrary::ArrayMin(const TArray<int32>& A)
{
	return A.Num() > 0 ? *std::min_element(A.GetData(), A.GetData() + A.Num()) : -1;
}

TArray<int32> UNumericBPLibrary::PartialSum(const TArray<int32>& A)
{
	TArray<int32> Result = A;
	std::partial_sum(Result.GetData(), Result.GetData() + Result.Num(), Result.GetData());
	return Result;
}

TArray<int32> UNumericBPLibrary::PartialSumN(const TArray<int32>& A, int32 N)
{
	N = FMath::Clamp(N, 0, A.Num());
	TArray<int32> Result = A;

	// Calculate the partial sum of the first N elements of the array.
	std::partial_sum(Result.GetData(), Result.GetData() + N, Result.GetData());
	return Result;
}

bool UNumericBPLibrary::IsPermutation(const TArray<int32>& A, const TArray<int32>& B)
{
	// Returns true if A is a permutation of B.
	return A.Num() == B.Num() && std::is_permutation(A.GetData(), A.GetData() + A.Num(), B.GetData());
}

TArray<int32> UNumericBPLibrary::EveryoneCubed(const TArray<int32>& A)
{
    TArray<int32> Result = A;

	// Cube each element in the array.
    std::transform(A.GetData(), A.GetData() + A.Num(), Result.GetData(), [](int32 n) {return n * n * n; });
    return Result;
}

TArray<int32> UNumericBPLibrary::EveryoneSquared(const TArray<int32>& A)
{
    TArray<int32> Result = A;

	// Square each element in the array.
    std::transform(A.GetData(), A.GetData() + A.Num(), Result.GetData(), [](int32 n) {return n * n; });
    return Result;
}

TArray<int32> UNumericBPLibrary::Sample(const TArray<int32>& A, int32 N)
{
	N = FMath::Clamp(N, 0, A.Num());
	TArray<int32> B;
	B.SetNumUninitialized(N);

	std::random_device rd;
	std::default_random_engine engine(rd());

	std::sample(A.GetData(), A.GetData() + A.Num(), B.GetData(), N, engine);

	return B;
}

bool UNumericBPLibrary::CopyArray(const TArray<int32>& A, UPARAM(ref)TArray<int32>& B)
{
	if (A.Num() == B.Num())
	{
		B = A;
		return true;
	}
	else
	{
		UE_LOGFMT(LogArrayUtils, Warning, "CopyArray: Arrays must be of equal length. A.Num() = {0}, B.Num() = {1}", A.Num(), B.Num());
		return false;
	}
}

bool UNumericBPLibrary::SwapArrays(UPARAM(ref) TArray<int32>& A, UPARAM(ref) TArray<int32>& B)
{
	TArray<int32> Temp = A;
	A = B;
	B = Temp;
	return true;
}

bool UNumericBPLibrary::MoveArray(UPARAM(ref) TArray<int32>& A, UPARAM(ref) TArray<int32>& B)
{
	B = A;
	A.Empty();
	return true;
}

bool UNumericBPLibrary::ArrayIsDecreasing(const TArray<int32>& A)
{
	for (int32 i = 1; i < A.Num(); ++i)
	{
		if (A[i - 1] < A[i])
		{
			return false;
		}
	}
	return true;
}

bool UNumericBPLibrary::ArrayIsIncreasing(const TArray<int32>& A)
{
	for (int32 i = 1; i < A.Num(); ++i)
	{
		if (A[i - 1] > A[i])
		{
			return false;
		}
	}
	return true;
}

bool UNumericBPLibrary::ArrayIsStrictlyDecreasing(const TArray<int32>& A)
{
	for (int32 i = 1; i < A.Num(); ++i)
	{
		if (A[i - 1] <= A[i])
		{
			return false;
		}
	}
	return true;
}

bool UNumericBPLibrary::ArrayIsStrictlyIncreasing(const TArray<int32>& A)
{
	for (int32 i = 1; i < A.Num(); ++i)
	{
		if (A[i - 1] >= A[i])
		{
			return false;
		}
	}
	return true;
}

TArray<int32> UNumericBPLibrary::NextPermutation(TArray<int32> A)
{
    if (A.Num() > 1)
    {
        std::next_permutation(A.GetData(), A.GetData() + A.Num());
    }

	UE_LOGFMT(LogArrayUtils, Warning, "NextPermutation: Array must have at least 1 elements. A.Num() = {0}", A.Num());
    return A;
}

TArray<int32> UNumericBPLibrary::PrevPermutation(TArray<int32> A)
{
    if (A.Num() > 1)
    {
        std::prev_permutation(A.GetData(), A.GetData() + A.Num());
    }

	UE_LOGFMT(LogArrayUtils, Warning, "PrevPermutation: Array must have at least 1 elements. A.Num() = {0}", A.Num());
	return A;
}

TArray<int32> UNumericBPLibrary::StableSortAscending(TArray<int32> A)
{
	Algo::StableSort(A);
	return A;
}

TArray<int32> UNumericBPLibrary::StableSortDescending(TArray<int32> A)
{
	Algo::Sort(A, [](const int32& A, const int32& B) { return A > B; });
	return A;
}

int32 UNumericBPLibrary::Search(const TArray<int32>& A, const TArray<int32>& B, bool& found)
{
	auto result = std::search(A.GetData(), A.GetData() + A.Num(), B.GetData(), B.GetData() + B.Num());

	if (result != A.GetData() + A.Num())
	{
		found = true;
		return result - A.GetData();
	}
	else
	{
		found = false;
		return -1;
	}
}

bool UNumericBPLibrary::IsSorted(const TArray<int32>& A)
{
	return A.Num() <= 1 || Algo::IsSorted(A);
}

int32 UNumericBPLibrary::InnerProduct(const TArray<int32>& A, const TArray<int32>& B, int32 StartIndex)
{
	return (A.Num() == B.Num() && A.Num() > 0 && B.Num() > 0)
		? std::inner_product(A.GetData(), A.GetData() + A.Num(), B.GetData(), StartIndex)
		: -1;
}

TArray<int32> UNumericBPLibrary::Clamp(const TArray<int32>& A, int32 Min, int32 Max)
{
	TArray<int32> B = A;

	std::for_each(B.GetData(), B.GetData() + B.Num(), [Min, Max](int32& Element)
	{
		Element = FMath::Clamp(Element, Min, Max);
	});

	return B;
}

TArray<int32> UNumericBPLibrary::ClampN(const TArray<int32>& A, int32 Min, int32 Max, int32 N)
{
	TArray<int32> B = A;

	N = FMath::Min(N, B.Num());

	// Clamp the first N elements of the array.
	std::for_each(B.GetData(), B.GetData() + N, [Min, Max](int32& Element)
	{
		Element = FMath::Clamp(Element, Min, Max);
	});

	return B;
}

int32 UNumericBPLibrary::Count(const TArray<int32>& A, int32 Value)
{
	return A.Num() > 0 ? std::count(A.GetData(), A.GetData() + A.Num(), Value) : -1;
}

int32 UNumericBPLibrary::Accumulate(const TArray<int32>& A)
{
	return A.Num() > 0 ? std::accumulate(A.GetData(), A.GetData() + A.Num(), 0) : -1;
}

TArray<int32> UNumericBPLibrary::Fill(const TArray<int32>& A, int32 Value)
{
	TArray<int32> B = A;

	std::fill(B.GetData(), B.GetData() + B.Num(), Value);

	return B;
}

TArray<int32> UNumericBPLibrary::FillN(const TArray<int32>& A, int32 Value, int32 N)
{
	TArray<int32> B = A;

	N = FMath::Min(N, B.Num());

	std::fill_n(B.GetData(), N, Value);

	return B;
}

TArray<int32> UNumericBPLibrary::Iota(const TArray<int32>& A, int32 Value)
{
	TArray<int32> B = A;

	std::iota(B.GetData(), B.GetData() + B.Num(), Value);

	return B;
}

TArray<int32> UNumericBPLibrary::Replace(const TArray<int32>& A, int32 OldValue, int32 NewValue)
{
	TArray<int32> B = A;

	std::replace(B.GetData(), B.GetData() + B.Num(), OldValue, NewValue);

	return B;
}

TArray<int32> UNumericBPLibrary::Rotate(const TArray<int32>& A, int32 Amount)
{
	TArray<int32> B = A;

	if (B.Num() > 0)
	{
		// Rotate the array by Amount positions. If Amount is negative, the rotation is performed in the opposite direction.
		Amount = Amount % B.Num();
		Amount = (Amount < 0) ? B.Num() + Amount : Amount;

		std::rotate(B.GetData(), B.GetData() + Amount, B.GetData() + B.Num());
	}

	UE_LOGFMT(LogArrayUtils, Warning, "Rotate: Array must have at least 1 elements. A.Num() = {0}", A.Num());
	return B;
}

void UNumericBPLibrary::ArrayMinMax(const TArray<int32>& A, int32& Min, int32& Max)
{
	if (A.Num() > 0)
	{
		Min = *std::min_element(A.GetData(), A.GetData() + A.Num());
		Max = *std::max_element(A.GetData(), A.GetData() + A.Num());
	}
	else
	{
		UE_LOGFMT(LogArrayUtils, Warning, "ArrayMinMax: Array must have at least 1 elements. A.Num() = {0}", A.Num());
		Min = 0;
		Max = 0;
	}
}

bool UNumericBPLibrary::ArrayIsEqual(const TArray<int32>& A, const TArray<int32>& B)
{
	return A.Num() == B.Num() && std::equal(A.GetData(), A.GetData() + A.Num(), B.GetData());
}

bool UNumericBPLibrary::ArrayIsNotEqual(const TArray<int32>& A, const TArray<int32>& B)
{
	return A.Num() != B.Num() || !std::equal(A.GetData(), A.GetData() + A.Num(), B.GetData());
}

TArray<int32> UNumericBPLibrary::NthElement(const TArray<int32>& A, int32 N)
{
	TArray<int32> Result = A;

	if (N >= 0 && N < A.Num())
	{
		std::nth_element(Result.GetData(), Result.GetData() + N, Result.GetData() + Result.Num());
	}

	return Result;
}

int32 UNumericBPLibrary::Mismatch(const TArray<int32>& A, const TArray<int32>& B, bool& IsMismatch)
{
	auto result = std::mismatch(A.GetData(), A.GetData() + A.Num(), B.GetData());

	if (result.first != A.GetData() + A.Num())
	{
		IsMismatch = true;
		return result.first - A.GetData();
	}
	else
	{
		IsMismatch = false;
		return -1;
	}
}

TArray<int32> UNumericBPLibrary::SortAscending(const TArray<int32>& A)
{
	TArray<int32> Result = A;
	Algo::Sort(Result);
	return Result;
}

TArray<int32> UNumericBPLibrary::SortDescending(const TArray<int32>& A)
{
	TArray<int32> Result = A;
	Algo::Sort(Result, [](const int32& A, const int32& B) { return A > B; });
	return Result;
}

TArray<int32> UNumericBPLibrary::PartialSortAscending(const TArray<int32>& A, int32 N)
{
	TArray<int32> Result = A;

	if (N >= 0 && N < A.Num())
	{
		std::partial_sort(Result.GetData(), Result.GetData() + N, Result.GetData() + Result.Num());
	}

	return Result;
}

TArray<int32> UNumericBPLibrary::PartialSortDescending(const TArray<int32>& A, int32 N)
{
	TArray<int32> Result = A;

	if (N >= 0 && N < A.Num())
	{
		std::partial_sort(Result.GetData(), Result.GetData() + N, Result.GetData() + Result.Num(), std::greater<int32>());
	}

	return Result;
}

int32 UNumericBPLibrary::IsSortedUntil(const TArray<int32>& A, bool& IsSorted)
{
	IsSorted = A.Num() <= 1 || UNumericBPLibrary::IsSorted(A);
	return std::is_sorted_until(A.GetData(), A.GetData() + A.Num()) - A.GetData();
}

TArray<int32> UNumericBPLibrary::BiggestArray(const TArray<int32>& A, const TArray<int32>& B)
{
	int32 SumA = std::accumulate(A.GetData(), A.GetData() + A.Num(), 0);
	int32 SumB = std::accumulate(B.GetData(), B.GetData() + B.Num(), 0);

	return (SumA > SumB) ? A : B;
}

TArray<int32> UNumericBPLibrary::SmallestArray(const TArray<int32>& A, const TArray<int32>& B)
{
	int32 SumA = std::accumulate(A.GetData(), A.GetData() + A.Num(), 0);
	int32 SumB = std::accumulate(B.GetData(), B.GetData() + B.Num(), 0);

	return (SumA > SumB) ? B : A;
}

int32 UNumericBPLibrary::Deaccumulate(const TArray<int32>& A)
{
	return std::accumulate(A.GetData(), A.GetData() + A.Num(), 0, std::minus<int32>());
}

int32 UNumericBPLibrary::MultiplyAllElements(const TArray<int32>& A)
{
	return std::accumulate(A.GetData(), A.GetData() + A.Num(), 1, std::multiplies<int32>());
}

bool UNumericBPLibrary::LexicographicalCompare(const TArray<int32>& A, const TArray<int32>& B)
{
	return std::lexicographical_compare(A.GetData(), A.GetData() + A.Num(), B.GetData(), B.GetData() + B.Num());
}

TArray<int32> UNumericBPLibrary::EraseAllOcurrencesOfValue(UPARAM(ref) TArray<int32>& A, int32 ElementToRemove)
{
	A.RemoveAll([ElementToRemove](int32 Element) { return Element == ElementToRemove; });
	A.Shrink();
	return A;
}

TArray<int32> UNumericBPLibrary::ShrinkToFit(UPARAM(ref) TArray<int32>& A)
{
	A.Shrink();
	return A;
}

TArray<int32> UNumericBPLibrary::ArrayTake(const TArray<int32>& A, int32 N)
{
	N = FMath::Clamp(N, 0, A.Num());
	return TArray<int32>(A.GetData(), N);
}

TArray<int32> UNumericBPLibrary::ArrayDrop(const TArray<int32>& A, int32 N)
{
	N = FMath::Clamp(N, 0, A.Num());
	return TArray<int32>(A.GetData() + N, A.Num() - N);
}