<h2><a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii">123. Best Time to Buy and Sell Stock III</a></h2><h3>Hard</h3><hr><p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the maximum profit you can achieve. You may complete <strong>at most two transactions</strong>.</p>

<p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [3,3,5,0,0,3,1,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,3,4,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> prices = [7,6,4,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this case, no transaction is done, i.e. max profit = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>

# 📌 Stock Trading Max 2 Trades: Mental Models

## 1. Split-Point Method (The Suffix Array)
* **The Core Idea:** Split the timeline into two separate halves using a wall.
* **The Math:** `Total Profit = Max Profit(Left Side) + Max Profit(Right Side)`
* **Mental Model:** 
  * Walk **backwards** from the end to calculate the best single trade you could *ever* make in the future on the right side of the wall (`secMaxProfit`).
  * Walk **forwards** from the start to find the best single trade on the left side of the wall.
  * Test every single day as the "wall" and combine the left profit with the pre-calculated right profit.

---

## 2. Reinvestment Chain (The Continuous Box) 📦
* **The Core Idea:** One single pool of money where your first win funds your next bet.
* **The Math:** 
  $$\text{Total Profit} = (B - A) + (D - C)$$
  Rearranged:
  $$\text{Total Profit} = D - (C - (B - A))$$
  Where:
  * $A$ = Buy 1
  * $B$ = Sell 1 (Profit 1 = $B - A$)
  * $C$ = Buy 2
  * $D$ = Sell 2
* **Mental Model:**
  * Treat `Buy 2` as your **Effective Out-of-Pocket Cost**: $(C - \text{Profit 1})$.
  * If Stock 2 costs \$10 ($C$), but you have \$4 in your pocket from trade 1 ($B-A$), it only feels like you spent \$6 of your original money to buy it. 
  * You return **only `Profit 2`** because the math already injected your first profit directly into your final wallet balance.
 of how many days of data there are.
*   **Cons**: Requires a shift in mindset to view "cost" as a relative value influenced by past success.

