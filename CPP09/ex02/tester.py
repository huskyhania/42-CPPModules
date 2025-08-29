import random
import subprocess
import sys
import re


def generate_numbers(n, low=0, high=100):
    """Generate a list of n random integers between low and high."""
    return [random.randint(low, high) for _ in range(n)]

def is_sorted(nums):
    """Check if a list is sorted in non-decreasing order."""
    return all(nums[i] <= nums[i+1] for i in range(len(nums)-1))

def run_test(n, program="./PmergeMe", runs=5):
    total_comparisons = 0

    for i in range(runs):
        numbers = generate_numbers(n)
        input_str = " ".join(map(str, numbers))

        print(f"\nRun {i+1}:")
        print("Input:", input_str)

        try:
            result = subprocess.run(
                [program, *map(str, numbers)],  # pass numbers as argv
                text=True,
                capture_output=True,
                check=True
            )
            output = result.stdout.strip()

            # --- Extract "Sorting done" line ---
            match_sorted = re.search(r"Sorting done:\s*(.*)", output)
            if not match_sorted:
                print("❌ 'Sorting done' not found in output")
                continue
            sorted_nums = list(map(int, match_sorted.group(1).split()))

            # --- Verify sorting ---
            if is_sorted(sorted_nums):
                print("✅ Output is sorted")
            else:
                print("❌ Output is NOT sorted:", sorted_nums)

            # --- Extract comparisons ---
            match_comparisons = re.search(r"Total comparisons:\s*(\d+)", output)
            if match_comparisons:
                comparisons = int(match_comparisons.group(1))
                total_comparisons += comparisons
                print(f"Comparisons in this run: {comparisons}")
            else:
                print("❌ 'Total comparisons' not found")

        except subprocess.CalledProcessError as e:
            print("Error running program:", e.stderr)

    print(f"\n=== Summary ===")
    print(f"Total comparisons across {runs} runs: {total_comparisons}")
    if runs > 0:
        print(f"Average comparisons: {total_comparisons / runs:.2f}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python tester.py <n> [program] [runs]")
        sys.exit(1)

    n = int(sys.argv[1])
    program = sys.argv[2] if len(sys.argv) > 2 else "./PmergeMe"
    runs = int(sys.argv[3]) if len(sys.argv) > 3 else 5

    run_test(n, program, runs)