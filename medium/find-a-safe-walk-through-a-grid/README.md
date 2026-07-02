# Find A Safe Walk Through A Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-07-02T18:36:39.465Z  

```cpp
                int ncost = cost + grid[nx][ny];
                if (ncost < dist[nx][ny]) {
                    dist[nx][ny] = ncost;
                    pq.push({ncost, nx, ny});
                }
            }
        }

        return false;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/)