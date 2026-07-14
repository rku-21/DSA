<h2><a href="https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd">3608. Find the Number of Subsequences With Equal GCD</a></h2><h3>Hard</h3><hr><p>You are given an integer array <code>nums</code>.</p>

<p>Your task is to find the number of pairs of <strong>non-empty</strong> <span data-keyword="subsequence-array">subsequences</span> <code>(seq1, seq2)</code> of <code>nums</code> that satisfy the following conditions:</p>

<ul>
	<li>The subsequences <code>seq1</code> and <code>seq2</code> are <strong>disjoint</strong>, meaning <strong>no index</strong> of <code>nums</code> is common between them.</li>
	<li>The <span data-keyword="gcd-function">GCD</span> of the elements of <code>seq1</code> is equal to the GCD of the elements of <code>seq2</code>.</li>
</ul>

<p>Return the total number of such pairs.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>The subsequence pairs which have the GCD of their elements equal to 1 are:</p>

<ul>
	<li><code>([<strong><u>1</u></strong>, 2, 3, 4], [1, <strong><u>2</u></strong>, <strong><u>3</u></strong>, 4])</code></li>
	<li><code>([<strong><u>1</u></strong>, 2, 3, 4], [1, <strong><u>2</u></strong>, <strong><u>3</u></strong>, <strong><u>4</u></strong>])</code></li>
	<li><code>([<strong><u>1</u></strong>, 2, 3, 4], [1, 2, <strong><u>3</u></strong>, <strong><u>4</u></strong>])</code></li>
	<li><code>([<strong><u>1</u></strong>, <strong><u>2</u></strong>, 3, 4], [1, 2, <strong><u>3</u></strong>, <strong><u>4</u></strong>])</code></li>
	<li><code>([<strong><u>1</u></strong>, 2, 3, <strong><u>4</u></strong>], [1, <strong><u>2</u></strong>, <strong><u>3</u></strong>, 4])</code></li>
	<li><code>([1, <strong><u>2</u></strong>, <strong><u>3</u></strong>, 4], [<strong><u>1</u></strong>, 2, 3, 4])</code></li>
	<li><code>([1, <strong><u>2</u></strong>, <strong><u>3</u></strong>, 4], [<strong><u>1</u></strong>, 2, 3, <strong><u>4</u></strong>])</code></li>
	<li><code>([1, <strong><u>2</u></strong>, <strong><u>3</u></strong>, <strong><u>4</u></strong>], [<strong><u>1</u></strong>, 2, 3, 4])</code></li>
	<li><code>([1, 2, <strong><u>3</u></strong>, <strong><u>4</u></strong>], [<strong><u>1</u></strong>, 2, 3, 4])</code></li>
	<li><code>([1, 2, <strong><u>3</u></strong>, <strong><u>4</u></strong>], [<strong><u>1</u></strong>, <strong><u>2</u></strong>, 3, 4])</code></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [10,20,30]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The subsequence pairs which have the GCD of their elements equal to 10 are:</p>

<ul>
	<li><code>([<strong><u>10</u></strong>, 20, 30], [10, <strong><u>20</u></strong>, <strong><u>30</u></strong>])</code></li>
	<li><code>([10, <strong><u>20</u></strong>, <strong><u>30</u></strong>], [<strong><u>10</u></strong>, 20, 30])</code></li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">50</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 200</code></li>
</ul>
# Problem Breakdown: Subsequence Pair Count

## 1. Core Intuition & State Definition
We need to form two disjoint subsequences from an array such that their final GCDs are equal. For every element in the array, we have exactly three mutually exclusive choices:
1. **Skip** the element entirely.
2. Put the element into **Subsequence 1**.
3. Put the element into **Subsequence 2**.

### State Formulation
`solve(idx, gcd1, gcd2)` returns the total number of valid ways to finish distributing elements from index `idx` to `n-1` given the current GCD track:
*   `idx`: Current element index being evaluated.
*   `gcd1`: Running GCD of Subsequence 1 (`0` if Subsequence 1 is empty).
*   `gcd2`: Running GCD of Subsequence 2 (`0` if Subsequence 2 is empty).

---

## 2. Step 1: Pure Recursive Logic
The mathematical definition of GCD allows `__gcd(0, x) = x`. This property simplifies initializing empty subsequences.

### Rules of Transition
*   **Include in Seq 1**: New GCD becomes `__gcd(gcd1, nums[idx])`.
*   **Include in Seq 2**: New GCD becomes `__gcd(gcd2, nums[idx])`.
*   **Skip**: GCDs remain unchanged.

### Base Case (The End of Array)
When `idx == n`, check if both subsequences have been created (`gcd1 > 0` and `gcd2 > 0`) and if their final GCDs match (`gcd1 == gcd2`).

```cpp
int MOD = 1e9 + 7;

int solveRecursive(int idx, int gcd1, int gcd2, vector<int>& nums) {
    // Base Case: All elements processed
    if (idx == nums.size()) {
        if (gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2) {
            return 1; 
        }
        return 0;
    }

    // Choice 1: Skip current element
    long long skip = solveRecursive(idx + 1, gcd1, gcd2, nums);

    // Choice 2: Add to Subsequence 1
    int nextGcd1 = (gcd1 == 0) ? nums[idx] : std::gcd(gcd1, nums[idx]);
    long long ans1 = solveRecursive(idx + 1, nextGcd1, gcd2, nums);

    // Choice 3: Add to Subsequence 2
    int nextGcd2 = (gcd2 == 0) ? nums[idx] : std::gcd(gcd2, nums[idx]);
    long long ans2 = solveRecursive(idx + 1, gcd1, nextGcd2, nums);

    // Return sum of all choices modulo 10^9 + 7
    return (skip + ans1 + ans2) % MOD;
}
```

---

## 3. Step 2: Top-Down Memoization (DP)
To avoid computing identical states repeatedly, add a 3D cache lookup (`dp[201][201][201]`). The structure and decisions map directly from the recursive code.

```cpp
class Solution {
public:
    int dp[201][201][201];
    int MOD = 1e9 + 7;

    int solveMemo(int idx, int gcd1, int gcd2, vector<int>& nums) {
        // 1. Base case (Exact same as recursion)
        if (idx == nums.size()) {
            return (gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2) ? 1 : 0;
        }

        // 2. Cache Lookup
        if (dp[idx][gcd1][gcd2] != -1) {
            return dp[idx][gcd1][gcd2];
        }

        // 3. Transitions (Exact same as recursion)
        long long skip = solveMemo(idx + 1, gcd1, gcd2, nums);
        
        int nextGcd1 = (gcd1 == 0) ? nums[idx] : std::gcd(gcd1, nums[idx]);
        long long ans1 = solveMemo(idx + 1, nextGcd1, gcd2, nums);
        
        int nextGcd2 = (gcd2 == 0) ? nums[idx] : std::gcd(gcd2, nextGcd2, nums); // Correct handling of 0 state
        long long ans2 = solveMemo(idx + 1, gcd1, nextGcd2, nums);

        // 4. Store result and return
        return dp[idx][gcd1][gcd2] = (skip + ans1 + ans2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        // Initialize entire memoization array with -1
        memset(dp, -1, sizeof(dp));
        
        // Start process at index 0, with both subsequences empty (GCD = 0)
        return solveMemo(0, 0, 0, nums);
    }
};
```



